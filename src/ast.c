#include "ast.h"
#include <stdio.h>

bool equal(const char *a, const char *b)
{
    return strcmp(a, b) == 0;
}

expression *_expression(enum ExpressionType type)
{
    expression *expr = malloc(sizeof(*expr));
    expr->type = type;
    return expr;
}

expression *number_expression(int value)
{
    expression *expr = _expression(Number);
    expr->value = value;
    return expr;
}

expression *string_expression(char *str)
{
    expression *expr = _expression(String);
    expr->str = strdup(str);
    return expr;
}

expression *binary_expression(enum Operator op, expression const *lhs,
    expression const *rhs)
{
    expression *expr = _expression(BinaryOp);
    expr->bop.op = op;
    expr->bop.lhs = copy_expression(lhs);
    expr->bop.rhs = copy_expression(rhs);
    return expr;
}

expression *call_expression(const char *name, expression const *arguments)
{
    expression *expr = _expression(Call);
    expr->call.name = strdup(name);
    expr->call.args = copy_expr_list(arguments->list);
    return expr;
}

expression *index_expression(expression const *target, expression const *ind)
{
    expression *expr = _expression(Index);
    expr->index.ref = copy_expression(target);
    expr->index.index = copy_expression(ind);
    return expr;
}

expression *var_ref(enum VarScope scope, char *name)
{
    expression *expr = _expression(VarRef);
    expr->ref.def = NORMAL;
    expr->ref.scope = scope;
    expr->ref.name = strdup(name);
    return expr;
}

expression *var_ref_index(enum VarScope scope, int index)
{
    expression *expr = _expression(VarRef);
    expr->ref.def = INDEX;
    expr->ref.scope = scope;
    expr->ref.index = index;
    return expr;
}

expression *expression_list(expr_list const *list)
{
    expression *expr = _expression(List);
    expr->list = copy_expr_list(list);
    return expr;
}

statement *statement_list(stmt_list const *list)
{
    statement *stmt = _statement(Block);
    stmt->list = copy_stmt_list(list);
    return stmt;
}

void free_expression(expression *expr)
{
    if (expr == NULL)
        return;
    switch (expr->type)
    {
    case BinaryOp:
        free_expression(expr->bop.lhs);
        free_expression(expr->bop.rhs);
        free(expr);
        break;
    case Call:
        free(expr->call.name);
        free(expr);
        break;
    case List:
        break;
    case Number:
        break;
    case Boolean:
        break;
        break;
    case VarRef:
        if (expr->ref.def == NORMAL)
            free(expr->ref.name);
        free(expr);
    default:
        break;
    }
}

// STATEMENTS

statement *_statement(enum StatementType type)
{
    statement *stmt = malloc(sizeof(*stmt));
    stmt->type = type;
    return stmt;
}

statement *expr_statement(expression const *e)
{
    statement *stmt = _statement(Expr);
    stmt->expr = copy_expression(e);
    return stmt;
}

statement *if_statement(expression const *e, statement const *s, statement *elseif)
{
    statement *stmt = _statement(If);
    stmt->ifCond.expr = copy_expression(e);
    stmt->ifCond.statements = copy_stmt_list(s->list);
    return stmt;
}

statement *loop_statement(expression const *e, statement const *s)
{
    statement *stmt = _statement(Loop);
    if (e != NULL) {
        stmt->loop.condition = copy_expression(e);
    }
    stmt->loop.statements = copy_stmt_list(s->list);
    return stmt;
}

statement *assign_statement(expression const *lhs, expression const *rhs)
{
    statement *stmt = _statement(Assign);
    stmt->assign.lhs = copy_expression(lhs);
    stmt->assign.rhs = copy_expression(rhs);
    return stmt;
}

statement *block_statement(const char *pattern, stmt_list const *list)
{
    statement *stmt = _statement(Block);
    stmt->block.ch = pattern != NULL ? pattern[1] : ' ';
    stmt->block.pattern = strdup(pattern);
    stmt->block.list = copy_stmt_list(list);
    return stmt;
}

void append_statement(stmt_list **list, statement const *to_add)
{
    while (*list)
    {
        list = &(*list)->next;
    }

    *list = malloc(sizeof(**list));
    (*list)->stmt = copy_statement(to_add);
    (*list)->next = NULL;
}

void append_expression(expr_list **list, expression const *to_add)
{
    while (*list)
    {
        list = &(*list)->next;
    }

    *list = malloc(sizeof(**list));
    (*list)->expr = copy_expression(to_add);
    (*list)->next = NULL;
}

void init_structure(Structure *s)
{
    s->begin = NULL;
    s->end = NULL;
    s->main = NULL;
    s->blocks = NULL;

    s->state = NULL;
    s->args = NULL;

    s->mode = LBL;
    // default input arg
    s->_requiredArgs = 1;
}

void free_structure(Structure *s)
{
    struct Var *temp;
    while (s->state != NULL)
    {
        temp = s->state;
        s->state = s->state->next;
        free(temp);
    }

    free(s->begin);
    free(s->end);
    free(s->main);
}

expression *copy_expression(expression const *expr)
{
    expression *copy = malloc(sizeof(*copy));
    switch (copy->type = expr->type)
    {
    case Number:
        copy->value = expr->value;
        break;
    case String:
        copy->str = strdup(expr->str);
        break;
    case Boolean:
        copy->boolean = expr->boolean;
        break;
    case List:
        copy->list = copy_expr_list(expr->list);
        break;
    case BinaryOp:
        copy->bop.op = expr->bop.op;
        copy->bop.lhs = copy_expression(expr->bop.lhs);
        copy->bop.rhs = copy_expression(expr->bop.rhs);
        break;
    case VarRef:
        if (expr->ref.def == INDEX)
        {
            copy->ref.index = expr->ref.index;
        }
        else
        {
            copy->ref.name = strdup(expr->ref.name);
        }
        copy->ref.scope = expr->ref.scope;
        copy->ref.def = expr->ref.def;
        break;
    case Call:
        copy->call.name = strdup(expr->call.name);
        copy->call.args = copy_expr_list(expr->call.args);
        break;
    case Index:
        copy->index.ref = expr->index.ref;
        copy->index.index = expr->index.index;
        break;
    default:
        printf("UNHANDLED: %d\n", expr->type);
    }

    return copy;
}

statement *copy_statement(statement const *stmt)
{
    statement *copy = malloc(sizeof(*copy));

    switch (copy->type = stmt->type)
    {
    case Assign:
        copy->assign.lhs = copy_expression(stmt->assign.lhs);
        copy->assign.rhs = copy_expression(stmt->assign.rhs);
        break;
    case Expr:
        copy->expr = copy_expression(stmt->expr);
        break;
    case If:
        copy->ifCond.expr = copy_expression(stmt->ifCond.expr);
        copy->ifCond.statements = copy_stmt_list(stmt->ifCond.statements);
        break;
    case Loop:
        if (stmt->loop.condition != NULL) {
            copy->loop.condition = copy_expression(stmt->loop.condition);
        }
        copy->loop.statements = copy_stmt_list(stmt->loop.statements);
        break;
    case Block:
        copy->block.ch = stmt->block.ch;
        copy->block.pattern = strdup(stmt->block.pattern);
        copy->block.list = copy_stmt_list(stmt->block.list);
        break;
    }

    return copy;
}

expr_list *copy_expr_list(expr_list const *list)
{
    expr_list *ret = NULL;
    expr_list **write = &ret;
    while (list)
    {
        append_expression(write, list->expr);
        write = &(*write)->next;
        list = list->next;
    }

    return ret;
}

stmt_list *copy_stmt_list(stmt_list const *list)
{
    stmt_list *ret = NULL;
    stmt_list **write = &ret;

    while (list)
    {
        append_statement(write, list->stmt);
        write = &(*write)->next;
        list = list->next;
    }

    return ret;
}

void add_argument(Structure *s, char const *name, char const *type,
    bool required)
{
    for (struct Arg *arg = s->args; arg != NULL; arg = arg->next)
    {
        if (equal(arg->name, name))
        {
            return;
        }
    }

    struct Arg *node = malloc(sizeof(struct Arg));
    node->name = strdup(name);
    if (equal(type, "pattern"))
        node->type = REGEX;
    else if (equal(type, "number"))
        node->type = NUMBER;
    else if (equal(type, "string"))
        node->type = STRING;

    node->required = true;
    node->next = s->args;
    s->args = node;
    s->_requiredArgs++;
}

void add_state_var(Structure *s, char const *name, char const *type,
    expression *expr)
{
    for (struct Var *val = s->state; val != NULL; val = val->next)
    {
        if (equal(val->name, name))
        {
            return;
        }
    }

    struct Var *node = malloc(sizeof(struct Var));
    node->name = strdup(name);
    if (equal(type, "pattern"))
        node->type = REGEX;
    else if (equal(type, "number"))
    {
        node->type = NUMBER;
        node->expr = expr;
    }
    else if (equal(type, "string"))
        node->type = STRING;
    else if (equal(type, "array"))
    {
        node->type = ARRAY;
    }
    node->next = s->state;
    s->state = node;
}
