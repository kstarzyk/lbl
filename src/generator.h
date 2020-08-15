#ifndef _GEN_H_
#define _GEN_H_ 1

// #include <assert.h>
#include <stdio.h>

#include "ast.h"

#define p(...) printf(__VA_ARGS__);

#define pr(...)        \
  printf(__VA_ARGS__); \
  printf("\n");

#define prg()          \
  printf("/* GEN */"); \
  printf("\n");
#define prg_end()          \
  printf("/* END_GEN */"); \
  printf("\n");

void generate_expr_list(expr_list const *list);

void generate_expr(expression const *e)
{
    // printf("TYPE: %d\n", e->type);
    switch (e->type)
    {
    case Number:
        p("%d", e->value);
        break;
    case Boolean:
        p("%s", e->boolean ? "true" : "false");
        break;
    case String:
        if (strlen(e->str) == 3)
        {
            p("'%c'", e->str[1]);
        }
        else
            p("%s", e->str);
        break;
    case BinaryOp:
        generate_expr(e->bop.lhs);
        p(" ");
        switch (e->bop.op)
        {
        case PLUS:
            p("+");
            break;
        case MINUS:
            p("-");
            break;
        case LT:
            p("<");
            break;
        case GT:
            p(">");
            break;
        case EQ:
            p("==");
            break;
        case NEQ:
            p("!=");
            break;
        case DIVIDE:
            p("/");
            break;
        case MULTIPLY:
            p("*");
            break;
        default:
            break;
        }
        p(" ");
        generate_expr(e->bop.rhs);
        break;
    case Call:
        if (equal(e->call.name, "skip"))
        {
            p("break;");
            break;
        }
        else if (equal(e->call.name, "next"))
        {
            p("p->line_number += 1;");
            pr("p->current = p->_input[p->line_number];");
            break;
        }
        else if (equal(e->call.name, "prev"))
        {
            p("p->line_number -= 1;");
            pr("p->current = p->_input[p->line_number];");
            break;
        }
        else if (equal(e->call.name, "position"))
        {
            p("p->line_number;");
            break;
        }
        else if (equal(e->call.name, "return"))
        {
            p("return;");
            break;
        }
        else if (equal(e->call.name, "current"))
        {
            p("p->current");
            break;
        }
        else if (equal(e->call.name, "move"))
        {
            p("p->line_number = ");
            generate_expr_list(e->call.args);
            p(";");
            pr("p->current = p->_input[p->line_number];");
            break;
        }
        p("%s(", e->call.name);
        if (equal(e->call.name, "printf"))
        {
            p("\"");
            expr_list const *ptr = e->call.args;
            while (ptr != NULL)
            {
                if (ptr->expr->type == String)
                    p("%%s");
                if (ptr->expr->type == Number)
                    p("%%d");
                if (ptr->expr->type == String)
                    p("%%s");

                p("%%c");
                if (ptr->next != NULL)
                {
                    p(",");
                }
                ptr = ptr->next;
            }

            p("\",");
        }
        else if (equal(e->call.name, "scanf"))
        {
            // expr_list const *ptr = e->call.args;
            p("\"%%c\", %s);", "&state->mem[state->p]");
            break;
        }

        generate_expr_list(e->call.args);
        pr(")");
        break;
    case VarRef:
        switch (e->ref.scope)
        {
        case LOCAL:
            break;
        case STATE:
        {
            if (e->ref.def == INDEX)
            {
                p("get_token_by_index(p, %d)", e->ref.index - 1);
            }
            else if (equal(e->ref.name, "line") || equal(e->ref.name, "current") || equal(e->ref.name, "line_number"))
            {
                p("p->%s", e->ref.name);
            }
            else
            {
                p("state->%s", e->ref.name);
            }
            break;
        }
        case ARGUMENTS:
            p("args.%s", e->ref.name);
            break;
        }
        break;
    case List:
    {
        expr_list const *ptr = e->list;
        if (ptr == NULL)
        {
            p("new_array()");
            break;
        }
        for (; ptr; ptr = ptr->next)
        {
            generate_expr(ptr->expr);
        }
        break;
    }
    case Index:
        generate_expr(e->index.ref);
        p("[");
        generate_expr(e->index.index);
        p("]");
        break;
    default:
        printf("expr: unknown\n");
        break;
    }
}

void generate_expr_list(expr_list const *list)
{
    if (list == NULL)
        return;
    expr_list const *ptr = list;

    for (; ptr; ptr = ptr->next)
    {
        generate_expr(ptr->expr);
        if (ptr->next != NULL)
        {
            p(",");
        }
    }
}

void generate_stmt_list(stmt_list const *list, bool is_switch);
void generate_stmt(statement const *s, bool is_switch)
{
    if (s == NULL)
        return;
    // printf("type: %d\n", s->type);
    switch (s->type)
    {
    case Expr:
        generate_expr(s->expr);
        p(";");
        break;
    case If:
        p("if (");

        generate_expr(s->ifCond.expr);
        pr(") {");
        generate_stmt_list(s->ifCond.statements, false);
        pr("}");
        break;
    case Block:
    {
        if (is_switch)
        {
            pr("case '%c': ", s->block.ch);
            generate_stmt_list(s->block.list, false);
            pr("break;\n");
            break;
        }
        else if (!is_switch && s->block.pattern != NULL)
        {
            pr("if (regex(p->line, \"%s\")) {", s->block.pattern);
            generate_stmt_list(s->block.list, false);
            if (true) // todo
                pr("return;");
            pr("}");
            break;
        }
        else
            generate_stmt_list(s->block.list, false);
        break;
    }
    case Loop:
        if (s->loop.condition != NULL) {
            p("while(");
            generate_expr(s->loop.condition);
            pr(") {");
        }
        else pr("while(true) {");
        generate_stmt_list(s->loop.statements, false);
        pr("}");
        break;
    case Assign:
        generate_expr(s->assign.lhs);
        p(" = ");
        generate_expr(s->assign.rhs);
        p(";");
        break;
    default:
        printf("stmt: unknown (%d)\n", s->type);
        break;
    }
}

void generate_stmt_list(stmt_list const *list, bool is_switch)
{
    if (list == NULL)
        return;
    struct stmt_list const *ptr = list;
    for (; ptr; ptr = ptr->next)
    {
        generate_stmt(ptr->stmt, is_switch);
    }
}

void gen_arguments(Arg *arg)
{
    pr("typedef struct {");
    prg();
    Arg *ptr = arg;
    while (ptr != NULL)
    {
        if (ptr->type == REGEX)
            pr("\tre_t %s;", ptr->name);
        if (ptr->type == NUMBER)
            pr("\tint %s;", ptr->name);
        ptr = ptr->next;
    }
    prg_end();
    pr("} __arguments;");
    pr("");
}

void gen_arguments_default(Arg *arg)
{
    pr("__arguments __arguments_default() {");
    pr("\t__arguments args;");
    prg();
    // pr("\targs.show_line_number = false;");
    prg_end();
    pr("\treturn args;");
    pr("}");
}

void gen_arguments_parse(Arg *arg, int requiredArgs)
{
    pr("ARGUMENTS_PARSE {");
    pr("\targv++; argc--;");
    pr("\tif (argc < %d) {", requiredArgs - 1);
    pr("\t\tprintf(\"required %d arguments (%%d given)\\n\", argc);",
        requiredArgs - 1);

    pr("\t\texit(1);");
    pr("\t}else if (argc == %d) p->use_stdin = true;", requiredArgs - 1);
    pr("\telse {");
    pr("\t\tchar const* const fileName = argv[argc-1];");
    pr("\t\tp->file = fopen(fileName, \"r\");");
    pr("\t}");

    pr("\t__arguments args = __arguments_default();");
    prg();
    Arg *ptr = arg;
    int i = 0;
    while (ptr != NULL)
    {
        if (ptr->type == REGEX)
        {
            pr("\targs.%s = re_compile(argv[%d]);", ptr->name, i);
        }
        else if (ptr->type == NUMBER)
            pr("\targs.%s = atoi(argv[%d]);", ptr->name, i);
        ptr = ptr->next;
        i++;
    }
    // pr("args.pattern = re_compile(argv[0]);");
    prg_end();
    pr("\treturn args;");
    pr("}");
}

void gen_head()
{
    pr("#include \"src/langlib.h\"");
    pr("");
}

void gen_state_methods(Var *state)
{
    pr("typedef struct {");
    prg();
    Var *ptr = state;
    while (ptr != NULL)
    {
        switch (ptr->type)
        {
        case ARRAY:
            pr("\tint %s[200000];", ptr->name);
            break;
        case Number:
            pr("\tint %s;", ptr->name);
            break;
        case STRING:
            break;
        case REGEX:
            break;
        default:
            break;
        }
        ptr = ptr->next;
    }
    prg_end();
    pr("} __state;");

    pr("STATE_NEW()");
    prg();
    Var *ptr2 = state;
    while (ptr2 != NULL)
    {
        if (ptr2->type != ARRAY)
        {
            printf("\ts->%s = ", ptr2->name);
            generate_expr(ptr2->expr);
            pr(";");
        }
        ptr2 = ptr2->next;
    }
    prg_end();
    pr("\treturn s;");
    pr("}");

    pr("void __state_free(__state *s) {");
    pr("\tfree(s);");
    pr("}");
}

void gen_structure(Structure const *program)
{
    gen_head();
    gen_arguments(program->args);
    gen_arguments_default(program->args);
    gen_arguments_parse(program->args, program->_requiredArgs);

    gen_state_methods(program->state);

    pr("PROGRAM_BEGIN {");
    generate_stmt_list(program->begin, false);
    pr("}");

    pr("PROGRAM_PROC {");
    switch (program->mode) {
    case CBC:
        pr("\tif (p->current == -1) {");
        pr("return;");
        pr("}");

        pr("\tswitch(p->current) {");
        generate_stmt_list(program->blocks, true);
        // generate_stmt_list(program->main, true);
        pr("\t\tcase '\\n': { break; }");
        // pr("\t\tdefault: { printf(\"\\n'%%c': unknown\", p->current); break; }");
        pr("\t\tdefault: break; ");
        pr("\t}");
        break;
    case WBW:
        break;
    case LBL:
    default:
        pr("\tp->line_tokens_length = split_string(p->line, p->delimiter, "
            "&p->line_tokens);");
        generate_stmt_list(program->blocks, false);
        // generate_stmt_list(program->main);
        pr("\tfree(p->line_tokens);");
        break;
    }
    pr("}");

    pr("PROGRAM_END {");
    generate_stmt_list(program->end, false);
    pr("}");

    pr("");
    if (program->mode != CBC) {
        pr("MAIN")
    }
    else
    {
        pr("MAIN_CHAR")
    }
}

#endif
