EXE     := ../parser
SRCS    := $(wildcard *.p)
OBJS    := $(patsubst %.p,assembly/%,$(SRCS))
SHELL   := /bin/bash

all: class assembly $(OBJS) class/io.class

class:
	mkdir -p class

class/io.class: class
ifeq (,$(wildcard ../jasmin.jar))
	jasmin -d class external_io/io.j
else
	java -jar ../jasmin.jar -d class external_io/io.j
endif

assembly/%: %.p
	@echo "Generate $@.j file"
	@-./$(EXE) -o $@.j $^ > /dev/null 2> /dev/null

ifeq (,$(wildcard $@.j))
	touch $@.j
endif

	@echo "Generate class"
ifeq (,$(wildcard ../jasmin.jar))
	jasmin -d class $@.j
else
	java -jar ../jasmin.jar -d class $@.j
endif

test: all
	@bash test.sh

check: all
	@bash check.sh

assembly:
	mkdir -p $@

clean:
	$(RM) -rf assembly output class
