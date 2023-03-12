#include "../incs/minishell.h"

char	*ft_substr(const char *str, unsigned int start, size_t len)
{
	//printf("\nsubstr\n");
	size_t	new_len;
	char	*dst;

	if (!str)
		return(NULL);
	if (start > ft_strlen(str))
		return (ft_strdup(""));
	str = str + start;
	new_len = ft_strlen (str);
	if (len > new_len)
		len = new_len;
	dst = ft_strndup(str, len);
	return (dst);	
}

 char	*ft_strtrim(const char *str, char const *set)
{
	//printf("\STRTRIM\n");
	size_t	end;

	if (!str || !set)
		return (NULL);
	while (*str != '\0' && ft_strchr(set, *str) != -1)
		str++;
	end = ft_strlen(str) - 1;
	while (end && ft_strchr(set, str[end]) != -1)
		end--;
	return (ft_substr(str, 0, end + 1));
}

static void	ft_process_quotes(t_mini *minishell)
{
	if (minishell->next_line_split && minishell->next_line_split[0])
	{
		if (minishell->next_line_split[0][0] == 34)
			minishell->next_line_split[0] = ft_strtrim(minishell->next_line_split[0], "\"");
		else if (minishell->next_line_split[0][0] == 39)
			minishell->next_line_split[0] = ft_strtrim(minishell->next_line_split[0], "\'");		
	}
}

/*  */
void    ft_builts(t_mini *minishell)
{
	//printf("\nBuilst\n");
	int     i;

	i = 0;
	ft_process_quotes(minishell);
	if (ft_str_equals(minishell->next_line_split[0], "env"))
		ft_print2dstr(minishell->mini_env);
    else if (ft_str_equals(minishell->next_line_split[0], "echo"))
		ft_echo(minishell->next_line_split);
	else if (ft_str_equals(minishell->next_line_split[0], "pwd"))
		printf("%s\n", getcwd(minishell->mini_path, 1000));
}

/*void    ft_builts(t_mini *minishell)
{
    int     i;
//    char    *path;
//    char    *temp_path;

	i = 0;
	if (ft_str_equals(minishell->next_line_split[0], "env"))
		ft_print2dstr(minishell->mini_env);
    if (ft_str_equals(minishell->next_line_split[0], "echo"))
		{
			if (minishell->next_line_split[1] != NULL)
			{
				while (minishell->next_line_split[++i])
					printf("%s ", minishell->next_line_split[i]);
				//dst =  &minishell->next_line[ft_strchr(minishell->next_line, ' ') + 1];
				//write (1, dst, ft_strlen(dst));
			}
			printf("\n");
			//write (1, "\n", 1);
		}*/
/*		else if (ft_strstr(minishell->next_line, "export"))
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
*/		/*else if (ft_strstr(minishell->next_line, "pwd"))
			printf("%s\n", getcwd(minishell->mini_path, 1000));

}*/