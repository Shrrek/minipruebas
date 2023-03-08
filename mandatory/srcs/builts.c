#include "../incs/minishell.h"

void    ft_builts(t_mini *minishell)
{
    char    *dst;
    int     i;
//    char    *path;
//    char    *temp_path;

    if (ft_strstr(minishell->next_line, "echo"))
		{
			i = 4;
			if (minishell->next_line[i] != '\0')
			{
//				ft_no_quotes(minishell->next_line);
				dst =  &minishell->next_line[ft_strchr(minishell->next_line, ' ') + 1];
				write (1, dst, ft_strlen(dst));
			}
			write (1, "\n", 1);
		}
/*		else if (ft_strstr(minishell->next_line, "env"))
		{
			i = 3;
			while (minishell->next_line[i] != '\0')
			{
				if (minishell->next_line[i] != ' ')
//					ft_process_error(ENV_ERROR, minishell);
                    printf("No such file or directory\n");
				i++;
			}
			ft_print2dstr(minishell->mini_env);
		}
		else if (ft_strstr(minishell->next_line, "export"))
		{
			i = 6;
			minishell->mini_env = ft_export_variable(minishell->mini_env, &minishell->next_line[i + 1], minishell);
			ft_print2dstr_export(minishell->mini_env);
		}
		else if (ft_strstr(minishell->next_line, "cd"))
		{
			minishell->mini_path = NULL;
			temp_path = NULL;
//			minishell->mini_path = getcwd(minishell->minipath, ft_strlen(minishell->minipath));
			minishell->mini_path = getcwd(minishell->mini_path, 1000);
			printf("la ruta antes de cambiar era: %s\n", minishell->mini_path);
			temp_path = ft_strdup(minishell->mini_path, minishell);
			path =  &minishell->next_line[ft_strchr(minishell->next_line, ' ') + 1];
			if (ft_strstr(path, "cd"))
			{
				printf("Vamos al HOME\n");
				chdir(minishell->mini_home);
				printf("la ruta es %s\n", minishell->mini_home);
				minishell->mini_env = ft_change_env(minishell->mini_env, "PWD", minishell->mini_home ,minishell);
			}
			else
			{
				if (!opendir(path))
//					ft_process_error(DIR_ERROR, minishell);
                    printf("No such file or directory\n");
//				closedir(path);				
				chdir(path);
				minishell->mini_path = getcwd(minishell->mini_path, 1000);
				printf("la pwd es: %s\n", minishell->mini_path);
				minishell->mini_env = ft_change_env(minishell->mini_env, "PWD", minishell->mini_path ,minishell);
			}
			printf("la oldpwd es : %s\n", temp_path);
			minishell->mini_env = ft_change_env(minishell->mini_env, "OLDPWD", temp_path ,minishell);
		}
*/		else if (ft_strstr(minishell->next_line, "pwd"))
			printf("%s\n", getcwd(minishell->mini_path, 1000));

}