/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperales <jperales@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 18:09:36 by sperez-p          #+#    #+#             */
/*   Updated: 2023/02/23 20:07:07 by jperales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H

# define MINISHELL_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <signal.h>
# include <termios.h>

# define MALLOC_ERROR 1
# define NULL_ERROR 2
# define ERROR_34 3
# define ARGS_ERROR 4
# define ENV_ERROR 5

typedef struct s_mini
{
	char	**minienv;
	char	*next_line;
	char	*minipath;

}t_mini;

/* COPY FUNCTIONS */
char	*ft_strdup(const char *str, t_mini *minishell);
char	*ft_strdup_free(const char *str, t_mini *minishell, char *src);
char	**ft_2dstrdup(const char **str, t_mini *minishell);

/* ERROR FUNCTIONS */
void	ft_process_error(int type, t_mini *minishell);

/* FREE FUNCTIONS */
void    ft_free_2d_str(char **str);
void	ft_general_free(t_mini *minishell);

/* PRINT FUNCTIONS */
void    ft_print2dstr(char **str);
void    ft_print2dstr_export(char **str);
void	ft_print_line(char *str);

/* SEARCH FUNCIONS */
int		ft_strchr(const char *str, int c);
int		ft_strnstr(const char *str, const char *substr, size_t n);
char	*ft_strstr(const char *haystack, const char *needle);

/* SIZE FUNCTIONS */
size_t	ft_strlen(const char *str);
size_t  ft_2dstrlen(const char **str);

/* SIGNALS */
void	ft_signal_handler(int signal);

/* READLINE */
void	rl_replace_line(const char *text,int clear_undo);

#endif
/*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*/

