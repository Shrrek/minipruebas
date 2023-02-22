/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperales <jperales@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 18:09:36 by sperez-p          #+#    #+#             */
/*   Updated: 2023/02/22 19:38:13 by jperales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H

# define MINISHELL_H

# include <stdio.h>
# include <stdlib.h>

# define MALLOC_ERROR 1
# define NULL_ERROR 2

typedef struct s_mini
{
	char	**minienv;

}t_mini;

/* COPY FUNCTIONS */
char	*ft_strdup(const char *str, t_mini *minishell);
char	**ft_2dstrdup(const char **str, t_mini *minishell);

/* ERROR FUNCTIONS */
void	ft_process_error(int type, t_mini *minishell);

/* FREE FUNCTIONS */
void    ft_free_2d_str(char **str);
void	ft_general_free(t_mini *minishell);

/* PRINT FUNCTIONS */
void    ft_print2dstr(char **str);

/* SEARCH FUNCIONS */
int		ft_strchr(const char *str, int c);
int		ft_strnstr(const char *str, const char *substr, size_t n);

/* SIZE FUNCTIONS */
size_t	ft_strlen(const char *str);
size_t  ft_2dstrlen(const char **str);

#endif
/*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*/

