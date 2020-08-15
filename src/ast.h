#ifndef _AST_H
#define _AST_H_ 1

#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

bool equal(const char *a, const char *b);
enum VarType
{
    NUMBER,
    STRING,
    REGEX,
    ARRAY,
};

enum VarDef
{
    INDEX,
    NORMAL
};

enum VarScope
{
    LOCAL,
    STATE,
    ARGUMENTS,
};

enum StatementType
{
    Block,
    Expr,
    If,
    Assign,
    Loop,
    // Declaration,
};

enum ExpressionType
{
    Number,
    Boolean,
    BinaryOp,
    Call,
    VarRef,
    List,
    String,
    Index,
    // Declaration,
};

enum Operator
{
    PLUS,
    MINUS,
    MULTIPLY,
    DIVIDE,
    LT,
    GT,
    EQ,
    NEQ
};

// EXPRESSIONS
typedef struct expr_list expr_list;
typedef struct expression expression;
typedef struct stmt_list stmt_list;

struct expression
{
    enum ExpressionType type;
    union
    {
        int value;
        bool boolean;
        char *str;
        expression *expr;
        struct
        {
            char *name;
            expr_list *args;
        } call;
        struct
        {
            enum Operator op;
            expression *lhs;
            expression *rhs;
        } bop;
        struct
        {
            enum VarScope scope;
            enum VarDef def;
            union
            {
                char *name;
                int index;
            };
        } ref;
        struct
        {
            expression *ref;
            expression *index;
        } index;
        expr_list *list;
    };
};

// STATEMENTS

typedef struct statement statement;
struct statement
{
    enum StatementType type;
    union
    {
        expression *expr;
        stmt_list *list;
        struct
        {
            stmt_list *list;
            char *pattern;
            char ch;
        } block;
        struct
        {
            expression *expr;
            stmt_list *statements;
        } ifCond;
        struct
        {
            expression *condition;
            stmt_list *statements;
        } loop;
        struct
        {
            expression *lhs;
            expression *rhs;
        } assign;
    };
};

// expression list

struct expr_list
{
    expression *expr;
    expr_list *next;
};

// statements list
struct stmt_list
{
    statement *stmt;
    stmt_list *next;
};

typedef struct Arg
{
    char *name;
    enum VarType type;
    bool required;
    struct Arg *next;
} Arg;

typedef struct Var
{
    char *name;
    enum VarType type;
    union
    {
        expression *expr;
        int number;
        char *string;
    };
    struct Var *next;

} Var;

typedef enum
{
    LBL,
    WBW,
    CBC,
} ProgramMode;

typedef struct stmt_list *block_list;
typedef struct
{
    Var *state;
    Arg *args;

    stmt_list *begin;
    stmt_list *end;
    stmt_list *main;

    stmt_list *blocks;
    // Procedures* procs;


    ProgramMode mode;
    bool read_all;
    int _requiredArgs;
} Structure;

expression *copy_expression(expression const *);
statement *copy_statement(statement const *);

void free_expression(expression *);
void free_statement(statement *);

expression *number_expression(int value);
expression *string_expression(char *str);
expression *binary_expression(enum Operator, expression const *,
    expression const *);
expression *call_expression(const char *, expression const *);
expression *index_expression(expression const *, expression const *);
expression *expression_list(expr_list const *);
expression *var_ref(enum VarScope scope, char *name);
expression *var_ref_index(enum VarScope scope, int index);

statement *_statement(enum StatementType type);
statement *if_statement(expression const *e, statement const *s, statement *elseif);
statement *loop_statement(expression const *e, statement const *s);
statement *assign_statement(expression const *lhs, expression const *rhs);
statement *statement_list(stmt_list const *);
statement *expr_statement(expression const *e);
statement *block_statement(const char *pattern, stmt_list const *list);
// Block
void block_init(statement *s);

inline expr_list *empty_expr_list() {
    return NULL;
}
inline stmt_list *empty_stmt_list() {
    return NULL;
}

expr_list *copy_expr_list(expr_list const *);
stmt_list *copy_stmt_list(stmt_list const *);

void append_statement(stmt_list **, statement const *);
void append_expression(expr_list **, expression const *);

void free_expression(expression *);

void init_structure(Structure *s);
void free_structure(Structure *s);

void add_argument(Structure *s, char const *name, char const *type,
    bool required);
void add_state_var(Structure *s, char const *name, char const *type,
    expression *expr);

#endif
