#ifndef _LANGLIB_H_
#define _LANGLIB_H_ 1

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../vendors/tiny-regex-c/re.h"

/* MACROS */
#define ARGUMENTS_PARSE \
  __arguments __parse_arguments(Program *p, int argc, char *argv[])
#define PROGRAM_ARGS Program *p, __arguments args, __state *state

#define STATE_NEW()      \
  __state *__state_new() \
  {                      \
    __state *s = malloc(sizeof(__state));

#define PROGRAM_INIT()                                 \
  Program *p = program_new();                          \
  __arguments args = __parse_arguments(p, argc, argv); \
  __state *s = __state_new();

#define PROGRAM_BEGIN void begin(PROGRAM_ARGS)
#define PROGRAM_END void end(PROGRAM_ARGS)

#define PROGRAM_PROC void process(PROGRAM_ARGS)

#define PROGRAM_RUN()                                                     \
  begin(p, args, s);                                                      \
  while (fgets(p->line, sizeof(p->line), p->use_stdin ? stdin : p->file)) \
  {                                                                       \
    process(p, args, s);                                                  \
    p->line_number++;                                                     \
  }                                                                       \
  end(p, args, s);                                                        \
  program_free(p);

#define PROGRAM_RUN_CHAR()                                                 \
  begin(p, args, s);                                                       \
  while (fscanf(p->use_stdin ? stdin : p->file, "%c", &p->current) != EOF) \
  {                                                                        \
    process(p, args, s);                                                   \
    p->line_number++;                                                      \
  }                                                                        \
  end(p, args, s);                                                         \
  program_free(p);

#define PROGRAM_RUN_CHAR_WHOLE()                                        \
  begin(p, args, s);                                                    \
  FILE *f = p->use_stdin ? stdin : p->file;                             \
  fseek(f, 0, SEEK_END);                                                \
  p->_input_size = ftell(f);                                            \
  fseek(f, 0, SEEK_SET);                                                \
  p->_input = malloc((p->_input_size) + 1);                             \
  fread(p->_input, 1, p->_input_size, f);                               \
  fclose(f);                                                            \
  p->_input[p->_input_size] = 0;                                        \
  while ((p->current = p->_input[p->line_number]) && p->current != EOF) \
  {                                                                     \
    process(p, args, s);                                                \
    p->line_number++;                                                   \
    p->current = p->_input[p->_input_size];                             \
  }                                                                     \
  end(p, args, s);                                                      \
  program_free(p);

#define MAIN                       \
  int main(int argc, char *argv[]) \
  {                                \
    PROGRAM_INIT();                \
    PROGRAM_RUN();                 \
    return 0;                      \
  }

#define MAIN_CHAR                  \
  int main(int argc, char *argv[]) \
  {                                \
    PROGRAM_INIT();                \
    PROGRAM_RUN_CHAR_WHOLE();      \
    return 0;                      \
  }

/* REGEX */

bool regex_r(const char *src, re_t pattern)
{
    const char *string_to_search = src;
    int match_length;
    /* Check if the regex matches the text: */
    int match_idx = re_matchp(pattern, string_to_search, &match_length);
    // if (match_idx != -1)
    // printf("match at idx %i, %i chars long.\n", match_idx, match_length);
    return match_idx != -1;
}

bool regex(const char *src, const char *reg)
{
    /* Standard null-terminated C-string to search: */

    /* Compile a simple regular expression using character classes, meta-char and
     * greedy + non-greedy quantifiers: */
     // re_t pattern = re_compile("[Hh]ello [Ww]orld\\s*[!]?");
    re_t pattern = re_compile(reg);

    return regex_r(src, pattern);
}

/* PROGRAM */
typedef struct
{
    bool use_stdin;

    FILE *file;
    char *filename;

    char line[255];
    char current;

    int line_number;
    int line_tokens_length;
    char **line_tokens;

    char *_input;
    long _input_size;

    char delimiter;

} Program;

Program *program_new()
{
    Program *p = (Program *)malloc(sizeof(Program));
    p->use_stdin = false;
    p->file = NULL;
    p->filename = NULL;
    p->line_tokens = NULL;
    p->line_number = 0;
    p->line_tokens_length = 0;
    p->delimiter = ' ';

    p->_input = NULL;
    p->_input_size = 0;

    return p;
}

const char *get_token_by_index(Program *p, int index)
{
    if (index < p->line_tokens_length)
    {
        return p->line_tokens[index];
    }
    return "";
}

void program_free(Program *p)
{
    if (p->file != NULL)
    {
        fclose(p->file);
        free(p->filename);
    }
    free(p);
}

int split_string(const char *txt, char delim, char ***tokens)
{
    int *tklen, *t, count = 1;
    char **arr, *p = (char *)txt;

    while (*p != '\0')
        if (*p++ == delim)
            count += 1;
    t = tklen = calloc(count, sizeof(int));
    for (p = (char *)txt; *p != '\0'; p++)
        *p == delim ? *t++ : (*t)++;
    *tokens = arr = malloc(count * sizeof(char *));
    t = tklen;
    p = *arr++ = calloc(*(t++) + 1, sizeof(char *));
    while (*txt != '\0')
    {
        if (*txt == delim)
        {
            p = *arr++ = calloc(*(t++) + 1, sizeof(char *));
            txt++;
        }
        else
            *p++ = *txt++;
    }
    free(tklen);
    return count;
}

#endif