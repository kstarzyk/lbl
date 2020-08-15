%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <unistd.h>
#include <ctype.h>
#include <getopt.h>

#include "src/generator.h"

extern int yylex();
extern int yyparse();
extern FILE* yyin;

void yyerror(const char* s);

Structure *program = NULL;

%}
%debug

%union {
	int fval;
    char* str;
    bool boolean;
    expression *expr;
    statement *stmt;
    enum Operator binop;
};

%token<fval> T_NUMBER;
%token<str> T_STRING;
%token<str> T_REGEXP;
%token<str> T_IDENT;
%token<str> T_VREF;
%token<str> T_IREF;

%token<boolean> T_TRUE;
%token<boolean> T_FALSE;

%token T_ASSIGN T_COLON T_COMMA;
%token T_PLUS_PLUS T_MINUS_MINUS T_PLUS_ASSIGN T_EQ T_NEQ;
%token T_PLUS T_MINUS T_MULTIPLY T_DIVIDE;
%token T_LEFT T_RIGHT T_CLEFT T_CRIGHT T_TLEFT T_TRIGHT T_BLEFT T_BRIGHT;
%token T_ARGUMENTS;
%token T_BEGIN T_END T_STATE;
%token T_SEMICOLON T_NL;
%token T_PROCENT;

%token T_IF T_OSTREAM T_ISTREAM T_LOOP;
%right T_ASSIGN T_PLUS_ASSIGN T_MINUS_ASSIGN T_EQ T_NEQ;

%left T_PLUS T_MINUS;
%left T_MULTIPLY T_DIVIDE;
%left T_TLEFT T_TRIGHT

%start top;

%type<binop> binary_op;

%type<expr> expression_list term expression var_ref;
%type<stmt> statement_list statement statement_if declaration block;

%%

separator: T_NL | T_SEMICOLON;

top: top_statements {};

top_statements: top_statement {
} | top_statements top_statement
;


top_statement: directive | arguments | state | block | pattern_block | begin | end
;

directive: T_PROCENT T_IDENT expression separator 
  | T_PROCENT T_IDENT separator {
    if (strcmp($2, "cbc") == 0) {
      program->mode = CBC;
    } else if (strcmp($2, "wbw") == 0) {
      program->mode = WBW;
    } else program->mode = LBL;
  }

pattern_block: T_REGEXP T_CLEFT statement_list T_CRIGHT {
  statement* stmt = block_statement($1, $3->list);
  append_statement(&program->blocks, stmt);
}
;

block: T_CLEFT statement_list T_CRIGHT {
    program->main = copy_stmt_list($2->list);
} | T_CLEFT T_CRIGHT {
    $$ = statement_list(NULL);
}
;

begin: T_BEGIN block  { program->begin = copy_stmt_list($2->list); };
end: T_END block      { program->end = copy_stmt_list($2->list); };

statement_list 
    :   { $$ = statement_list(NULL); }
    | statement  { 
        // printf("STATEMENT\n");
        statement* list = statement_list(NULL); 
        append_statement(&list->list, $1); 
        $$ = list; 
    } | statement_list separator statement {
        append_statement(&$1->list, $3);
        // printf("TUTAJ APPEND NORMALNIE\n");
        $$ = $1;
    }  
;

statement: statement_if { $$ = $1; }
  | T_IF expression T_COLON expression {
        statement* list = statement_list(NULL); 
        statement* sexpr = expr_statement($4);
        append_statement(&list->list, sexpr); 
        $$ = if_statement($2, list, NULL);
        free_expression($4);
} | T_LOOP T_CLEFT statement_list T_CRIGHT {
    $$ = loop_statement(NULL, $3);
} | T_LOOP expression T_CLEFT statement_list T_CRIGHT {
    $$ = loop_statement($2, $4);
} | term T_ASSIGN expression {
        $$ = assign_statement($1, $3);
        free_expression($1);
        free_expression($3);
} | term T_PLUS_PLUS {
        expression expr = {
            .type = BinaryOp,
            .bop = {
                .op = PLUS,
                .lhs = copy_expression($1),
                .rhs = &(expression){
                  .type = Number,
                  .value = 1,
                },
            }
        };
        $$ = assign_statement($1, &expr);
        free_expression($1);
} | term T_MINUS_MINUS {
        expression expr = {
            .type = BinaryOp,
            .bop = {
                .op = MINUS,
                .lhs = copy_expression($1),
                .rhs = &(expression){
                  .type = Number,
                  .value = 1,
                },
            }
        };
        $$ = assign_statement($1, &expr);
        free_expression($1);
} | term T_PLUS_ASSIGN expression {                
        expression expr = {
            .type = BinaryOp,
            .bop = {
                .op = PLUS,
                .lhs = copy_expression($1),
                .rhs = copy_expression($3),
            }
        };
        $$ = assign_statement($1, &expr);
        free_expression($1);
}  | term T_MINUS_ASSIGN expression {
        expression expr = {
            .type = BinaryOp,
            .bop = {
                .op =  MINUS,
                .lhs = copy_expression($1),
                .rhs = copy_expression($3),
            }
        };
        $$ = assign_statement($1, &expr);
        free_expression($1);
}   | expression {
    $$ = expr_statement($1);
    free_expression($1);
} 
;

statement_if: T_IF expression T_CLEFT statement_list T_CRIGHT {
    $$ = if_statement($2, $4, NULL);
}

state: T_STATE T_CLEFT state_block T_CRIGHT;
state_block: declaration | state_block declaration;

declaration: T_IDENT T_COLON expression T_COMMA {
  if ($3->type == List) {
  add_state_var(program, $1, "array", $3); 
  } else {
  add_state_var(program, $1, "number", $3); 
  }
};

arguments: T_ARGUMENTS T_CLEFT arguments_block T_CRIGHT;


expression: expression binary_op term { 
      $$ = binary_expression($2, $1, $3); 
      free_expression($1); 
      free_expression($3);
    }
    | T_BLEFT expression_list T_BRIGHT { 
      expression* expr = expression_list(NULL);
      expr = copy_expression($2);
      $$ = expr;
    }
    | T_IDENT T_LEFT expression_list T_RIGHT { $$ = call_expression($1, $3); }
    | T_LEFT expression T_RIGHT { $$ = $2;}
    | T_OSTREAM expression_list { $$ = call_expression("printf", $2); }
    | T_ISTREAM expression_list { $$ = call_expression("scanf", $2);
    }

;

expression: term;

term: T_NUMBER  { $$ = number_expression($1); }
    | T_MINUS T_NUMBER { $$ = number_expression(-$2); }
    | T_STRING { $$ = string_expression($1); }
    | var_ref { $$ = $1; }
    | var_ref T_BLEFT expression T_BRIGHT {
      $$ = index_expression($1, $3);
      free_expression($1); 
      free_expression($3);
    }
;

var_ref
    : T_VREF { 
        enum VarScope scope;
        if ($1[0] == '@') scope = ARGUMENTS;
        if ($1[0] == '$') scope = STATE;
        memmove($1, $1+1, strlen($1));
        $$ = var_ref(scope, $1); 
    } | T_IREF {
      enum VarScope scope;
      if ($1[0] == '@') scope = ARGUMENTS;
      if ($1[0] == '$') scope = STATE;
      memmove($1, $1+1, strlen($1));
      $$ = var_ref_index(scope, atoi($1));
    }
;

expression_list: { $$ = expression_list(NULL); }
    | expression { 
        expression* expr = expression_list(NULL); 
        expression* temp = copy_expression($1);
        append_expression(&expr->list, temp); 
        $$ = expr;
        free_expression(temp);
    }
    | expression_list T_COMMA expression {
        append_expression(&$1->list, $3);
        $$ = $1;
        free_expression($3);
    }
;

binary_op:  T_PLUS { $$ = PLUS; }
    | T_MINUS { $$ = MINUS; }
    | T_MULTIPLY { $$ = MULTIPLY; }
    | T_DIVIDE { $$ = DIVIDE; }
    | T_TLEFT { $$ = LT; }
    | T_TRIGHT { $$ = GT; }
    | T_EQ { $$ = EQ; }
    | T_NEQ { $$ = NEQ; }

;

arguments_block: arg  | arguments_block arg;

arg: T_IDENT T_TLEFT T_IDENT T_TRIGHT
{
    add_argument(program, $1, $3, true);
} | T_STRING T_COLON arg {
  exit(1);
}
;


%%

void yyerror(const char* s) {
	fprintf(stderr, "Parse error: %s\n", s);
	exit(1);
  // gen_structure(program);
  printf("ERR: %s\n", s);
	exit(1);
}

char *remove_ext (char* myStr, char extSep, char pathSep) {
    char *retStr, *lastExt, *lastPath;

    // Error checks and allocate string.
    if (myStr == NULL) return NULL;
    if ((retStr = malloc (strlen (myStr) + 1)) == NULL) return NULL;
    // Make a copy and find the relevant characters.
    strcpy (retStr, myStr);
    lastExt = strrchr (retStr, extSep);
    lastPath = (pathSep == 0) ? NULL : strrchr (retStr, pathSep);
    // If it has an extension separator.
    if (lastExt != NULL) {
        // and it's to the right of the path separator.
        if (lastPath != NULL) {
            if (lastPath < lastExt) {
                // then remove it.
                *lastExt = '\0';
            }
        } else {
            // Has extension separator with no path separator.
            *lastExt = '\0';
        }
    }

    // Return the modified string.

    return retStr;
}

void preparse(int des_p[2]) {
  if (dup2(des_p[1], STDOUT_FILENO) == -1) {
      perror("dup2");
      exit(EXIT_FAILURE);
    }
    close(des_p[1]);
    close(des_p[0]);
}

void parse() {
    Structure s;
    program = &s;
    init_structure(program);

    do {
       yyparse();
      //  printf("%s\n", yytname[YYTRANSLATE(yytokentype)]);
       
    } while (!feof(yyin));

    gen_structure(program);
    free_structure(program);
}

void postparse() {
    fflush(stdout);
    close(STDOUT_FILENO);
    exit(EXIT_SUCCESS);
}

char* HELP_MESSAGE = "lang compiler (build 12412)\n\
  usage: langc [flags] file\n\
  flags:\n\
      -g    emits c code to stdout\n";

typedef struct {
  bool compile;
  bool generate;
  bool use_stdin;
  char *source_path;
  char *target_bin_name;
} CompilerOptions;

CompilerOptions get_default_options() {
  CompilerOptions opts = {
    .compile = true,
    .generate = false,
    .use_stdin = false,
    .source_path = NULL,
    .target_bin_name = NULL
  };
  return opts;
}

void parse_arguments(int argc, char **argv, CompilerOptions *options) {
  char *outname = NULL;
  int c;

  opterr = 0;

  while ((c = getopt(argc, argv, "go:")) != -1)
    switch (c) {
    case 'g':
      options->generate = true;
      options->compile = false;
      break;
    case 'c':
      outname = optarg;
      break;
    case '?':
      if (optopt == 'c')
        fprintf(stderr, "Option -%c requires an argument.\n", optopt);
      else if (isprint(optopt))
        fprintf(stderr, "Unknown option `-%c'.\n", optopt);
      else
        fprintf(stderr, "Unknown option character `\\x%x'.\n", optopt);
      exit(1);
    default:
      abort();
    }

  options->source_path = argv[optind];
  options->use_stdin = options->source_path == NULL;
  options->target_bin_name =
      !options->use_stdin ? outname != NULL ? outname : remove_ext(argv[optind], '.', '/') : "main";
  
  // for (index = optind; index < argc; index++)
  // printf ("Non-option argument %s\n", argv[index]);
}

int main(int argc, char **argv) {
  CompilerOptions options = get_default_options();
  parse_arguments(argc, argv, &options);

  int des_p[2];
  if (options.compile) {
    if (pipe(des_p) == -1) {
      perror("Pipe failed");
      exit(1);
    }
  }
  if (options.source_path != NULL) {
    yyin = fopen(options.source_path, "r");
  } else if (isatty(STDIN_FILENO)) {
    printf("%s", HELP_MESSAGE);
    exit(1);
  } else {
    yyin = stdin;
  }
  if (options.compile) {
    if (fork() == 0) {
      if (dup2(des_p[1], STDOUT_FILENO) == -1) {
        perror("dup2");
        exit(EXIT_FAILURE);
      }
      close(des_p[1]);
      close(des_p[0]);
      parse();
      postparse();
    }
  } else {
    parse();
    return EXIT_SUCCESS;
  }

  if (fork() == 0) {
    close(STDIN_FILENO); // closing stdin
    dup(des_p[0]);       // replacing stdin with pipe read
    close(des_p[1]);     // closing pipe write
    close(des_p[0]);

    char *prog2[] = {"gcc", "-o", options.target_bin_name,
                     "-x",  "c",  "vendors/tiny-regex-c/re.c",
                     "-",   NULL};
    execvp(prog2[0], prog2);
    perror("execvp failed");
    exit(1);
  }

  if (options.compile) {
    close(des_p[0]);
    close(des_p[1]);
    wait(0);
    wait(0);
  }

  return 0;
}

int yywrap(void) { return 0; }
