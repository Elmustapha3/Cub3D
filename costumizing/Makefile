CC = clang

all: compiling

compiling: compiling.c
	@$(CC) $(CFLAGS) $< -o $@
	@./compiling
	@rm -f compiling

mse7: deleting.c
	@$(CC) $(CFLAGS) $< -o $@
	@./mse7
	@rm -f mse7
