#include "monty.h"
/*
int main(void)
{
	extern int vari;
	vari = 23;
	err_arg = 1;
	stack_t *stack = NULL;
	void (*fn)(stack_t **, unsigned int);

	printf("test\n");
	fn = inst_sel("push");
	fn(&stack, 4);
}*/
/**
 * inst_sel - selects a function from inst_list based on input
 * @comm: command
 * Return: returns a pointer to a function
 */
void (*inst_sel(char *cmd))(stack_t **stack, unsigned int line_number)
{
	int iter = 0, ch_it = 0;
	char *op_c = NULL;

	instruction_t inst_list[] =
	{
		{"push", _push},
		{"pall", _pall},
		{NULL, NULL},
	};

	if (!cmd)
		return (NULL);
		
	/* compare */
	op_c = inst_list[iter].opcode;

	while (op_c != NULL)
	{
		if (strcmp(cmd, op_c) == 0)
			return (inst_list[iter].f);
		iter++;
		op_c = inst_list[iter].opcode;
	}
	return (NULL);
}

void _push(stack_t **stack, unsigned int line_number)
{
	extern int vari;
	extern int err_arg;

	if (err_arg == 0)
	{
		stack = NULL;
		printf("PUSH %d - line: %d\n", vari, line_number);
	}
	else
		printf("arg Error\n");
}

void _pall(stack_t **stack, unsigned int line_number)
{
	stack = NULL;
	printf("PALL - line: %d\n", line_number);
}
