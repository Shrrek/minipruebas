#include "../incs/minishell.h"

static void	ft_write_args(char **next_line)
{
	int	i;
	int	len;

	i = 0;
	//ft_print2dstr(next_line);
	len = (int)ft_2dstrlen((const char **)next_line) - 1;
	while (next_line[++i])
	{
		if (i == len)
		{
			printf("%s", next_line[i]);
			break;
		}
		printf("%s ", next_line[i]);
	}
}

static int	ft_checkn(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	if (str[i] != '-')
		return (0);
	i++;
	while (str[i] && str[i] == 'n')
		i++;
	if (str[i] == '\0')
		return(1);
	return(0);
}

void	ft_echo(char **next_line)
{
	//printf("\nECHO\n");
	int	i;

	i = 0;
	if (ft_checkn(next_line[1]))
		ft_write_args(&next_line[1]);
	else if (next_line[1] != NULL)
	{
		ft_write_args(next_line);
		printf("\n");
	}
	else
		printf("\n");
}