#include <stdio.h>

/*
 * Printea un array 2d
 */
void ft_print2dstr(char **str)
{
	//printf("\nPRINT\n");
	int i;

	i = 0;
	if (str[i])
	{
		while (str[i])
		{
			printf("%s\n", str[i]);
			i++;
		}
	}
}