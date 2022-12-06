SCANNER = scanner
PARSER  = parser
CC      = gcc #gcc
CFLAGS  = -Iinclude -Wall -std=gnu11 -g -MMD #gnu11
LEX     = flex
YACC    = bison
LIBS    = -lfl

EXEC    = $(PARSER)
SRCS    = $(PARSER) $(SCANNER) $(basename $(notdir $(wildcard lib/*.c)))
DEPS := $(SRCS:=.d)
OBJS := $(SRCS:%=obj/%.o)
OBJDIR  = obj
LIBDIR  = lib

all: $(OBJDIR) $(EXEC)

$(OBJDIR)/$(SCANNER).c: $(OBJDIR)/%.c: %.l
	$(LEX) -o $@ $<

$(OBJDIR)/$(PARSER).c: $(OBJDIR)/%.c: %.y
	$(YACC) -o $@ --defines=$(OBJDIR)/parser.h -v $<

$(OBJDIR):
	mkdir -p $(OBJDIR)

$(OBJS): $(OBJDIR)

$(OBJDIR)/%.o: $(LIBDIR)/%.c
	$(CC) $(CFLAGS) -c -o $@ $<


$(EXEC): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^ $(LIBS)

prepare:
	# we have installed the package meet the basic needs
	# you can prepare the extra package you need here, e.g.
	#apt install clang
	#apt install g++

test: all
	make test -C test/

pack:
	make clean
	zip -r icd22-hw3.zip . -x ".*" -x "*.zip" -x "test/*"

.PHONY: clean

clean:
	make clean -C test/
	rm -rf $(SCANNER) $(SCANNER:=.c) $(PARSER:=.c) $(PARSER:=.h) $(DEPS) $(PARSER:=.output) $(OBJS) $(EXEC) $(OBJDIR)

DOCKERHUB_ACCOUNT=plaslab
IMAGE_NAME = compiler-f20-hw3
DOCKER_IMG = ${DOCKERHUB_ACCOUNT}/${IMAGE_NAME}:latest

pull:
	docker pull ${DOCKER_IMG}
