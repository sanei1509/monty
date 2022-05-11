#include "monty.h"

/**
 *extract_number - difference between the tokens
 *@token: receive token to search a number
 *Return: number or -1 if not found
 */

int extract_number(char *token)
{
	char *c = token;
	while (*c)
	{
		if (isdigit(*c) || ((*c == '-' || *c == '+') && isdigit(*(c+1))))
		{
			int val = strtol(c, &c, 10);

			if (val)
				return (val);
		}
		else
			c++;
	}
	return (-1);
}

/**
int main(void)
{
	char *str = "push      sad"; 
	printf("%i\n", extract_number(str));
	
	return (0);
}

*/

