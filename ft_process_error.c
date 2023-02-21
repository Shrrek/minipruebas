#include "minishell.h"

void	ft_error_exit(int type, t_mini *minishell)
{
	ft_general_free(minishell);
	exit(-1);
}