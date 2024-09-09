.PHONY: all run gdb batch_run clean latest run_gen $(ALL)

RESULT = .result
$(shell > $(RESULT))

COLOR_RED   = \033[1;31m
COLOR_GREEN = \033[1;32m
COLOR_NONE  = \033[0m

ALL = $(basename $(notdir $(shell find tests/. -name "*.c")))

GEN_SRC_DIR = test-gen
GEN_OBJ_DIR = build-gen
GEN_OUTPUT_DIR = gen-output
GEN_ALL = $(shell find $(GEN_SRC_DIR)/ -name "*.c")
GEN_OBJ_FILE = $(patsubst $(GEN_SRC_DIR)/%.c,$(GEN_OBJ_DIR)/%.o,$(GEN_ALL))
GEN_EXE_FILE = $(notdir $(GEN_OBJ_FILE))

all: $(addprefix Makefile., $(ALL))
	@echo "" $(ALL)

$(ALL): %: Makefile.%

Makefile.%: tests/%.c latest
	@/bin/echo -e "NAME = $*\nSRCS = $<\ninclude $${AM_HOME}/Makefile" > $@
	@if make -s -f $@ ARCH=$(ARCH) $(MAKECMDGOALS); then \
		printf "[%14s] $(COLOR_GREEN)PASS!$(COLOR_NONE)\n" $* >> $(RESULT); \
	else \
		printf "[%14s] $(COLOR_RED)FAIL!$(COLOR_NONE)\n" $* >> $(RESULT); \
	fi
	-@rm -f Makefile.$*

run: all
	@cat $(RESULT)
	@rm $(RESULT)

batch_run: all
	@cat $(RESULT)
	@rm $(RESULT)

gdb: all

$(GEN_OBJ_DIR):
	mkdir -p $(GEN_OBJ_DIR)

$(GEN_OUTPUT_DIR):
	mkdir -p $(GEN_OUTPUT_DIR)

$(GEN_OBJ_DIR)/%.o: $(GEN_SRC_DIR)/%.c | $(GEN_OBJ_DIR) $(GEN_OUTPUT_DIR)
	gcc $< -o $@

run_gen: $(GEN_OBJ_FILE)
	@for file in $(GEN_EXE_FILE);do\
		./$(GEN_OBJ_DIR)/$$file > $(GEN_OUTPUT_DIR)/$$file.txt;\
	done\

clean:
	rm -rf Makefile.* build/ build-gen/ gen-output/

latest:
