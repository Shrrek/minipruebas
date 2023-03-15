#include "../incs/minishell.h"

static void	ft_process_next_line(t_mini *minishell)
{
	/* Checkea que las comillas esten chapadas */
	int	i;

	i = -1;
	if (ft_parse_quotes((const char *)minishell->next_line))
	{
//		printf("next_line sin split = %s\n", minishell->next_line);
		minishell->next_line_split = ft_split(minishell->next_line, ' ');
		//printf("Antes de expandir\n");
		//ft_print2dstr(minishell->next_line_split);
		ft_process_expand(minishell->next_line_split, minishell->mini_env);
		//printf("Despues de expandir\n");
		//ft_print2dstr(minishell->next_line_split);
		//ft_print2dstr(minishell->next_line_split);
		//*printf("%zu\n", ft_2dstrlen((const char **)minishell->next_line_split));
		while (minishell->next_line_split[++i])
		{
			ft_delete_spaces(minishell->next_line_split[i]);
			ft_delete_quotes(minishell->next_line_split[i]);
		}
		ft_builts(minishell);
	}
	else
		printf("Quotes error.\n");
}

static void ft_init(t_mini *minishell, const char **env)
{
	minishell->mini_env = ft_2dstrdup(env);
	minishell->next_line = NULL;
	minishell->mini_home = getenv("HOME");
	minishell->mini_path = NULL;
	rl_catch_signals = 0;
}

int main(int argc, char **argv, char **envp)
{
	t_mini	minishell;

	(void)argv;
	if (argc == 1)
	{
		ft_init(&minishell, (const char **)envp);
		/* Comprobar si van dentro o fuera del bucle */
		signal(SIGINT, ft_signal_handler);
		signal(SIGQUIT, ft_signal_handler);
		while (1)
		{
			minishell.next_line = readline(">MiniTabaqueros ");
			/* Equivalente a señal de ctrl+D o EOF */
			if (!minishell.next_line)
				exit(printf("exit\n"));
			add_history(minishell.next_line);
			if (ft_str_equals(minishell.next_line, "history -c"))
				rl_clear_history();
			ft_process_next_line(&minishell);
			free(minishell.next_line);
		}
		ft_general_free(&minishell);
	}
	printf("Error. Númmero de argumentos inválido.");
	return	(0);
}