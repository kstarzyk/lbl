CC = clang
FLAGS =  -std=c11 -D_SVID_SOURCE -pedantic -Wall \
	 -Wformat-zero-length 

LIB = -lfl -L/usr/local/opt/flex/lib -L/usr/local/opt/bison/lib
NAME = lbl
BIN = $(NAME)c
o ?= src/$(NAME)

DEPS_EXEC = gcc flex bison
K := $(foreach exec,$(DEPS_EXEC),\
        $(if $(shell which $(exec)),some string,$(error "dependency '$(exec)' not in PATH")))


DEBUG?=0
ifeq ($(DEBUG),1)
	DEBUG_FLAGS = -DYYDEBUG=1
	DEBUG_MODE = --debug 
	FLAGS += -g -fsanitize=address
else
	DEBUG_FLAGS = 
	DEBUG_MODE = 
endif

all: prepare compiler

prepare: lex.yy.c y.tab.c y.tab.h

docker:
	docker build -t $(NAME) .

lex: lex.yy.c

bison: y.tab.c

yacc: bison

release:
	@echo "TODO"

examples: prepare compiler
	./$(BIN) examples/bf.lbl

lex.yy.c: src/scanner.l
	flex $(DEBUG_MODE) src/scanner.l 
	
y.tab.c: src/parser.y
	bison -Wcounterexamples --token-table --verbose $(DEBUG_MODE) --report=all -t -dy src/parser.y

y.tab.h: src/parser.y

compiler:
	$(CC) $(DEBUG_FLAGS) $(FLAGS) lex.yy.c y.tab.c src/ast.c -o $(BIN) 
#$(LIB)

clean:
	rm -rf $(BIN)

distclean: clean
	rm -rf lex.yy.c
	rm -rf y.tab.c
	rm -rf y.tab.h