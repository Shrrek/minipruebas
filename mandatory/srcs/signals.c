#include "../incs/minishell.h"

void	ft_signal_handler(int signal)
{
	if (signal == SIGINT) //ctrl c
	{
		printf("\n");
		rl_on_new_line();
		rl_replace_line("", 0);
		rl_redisplay();
	} 
	/*if (signal == SIGQUIT)
	{
		NULL;
	}*/
}