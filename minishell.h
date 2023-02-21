/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperales <jperales@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 17:16:27 by jperales          #+#    #+#             */
/*   Updated: 2023/02/21 20:25:27 by jperales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include <stdlib.h>

# define MALLOC_ERROR 1
# define NULL_ERROR 2

/*typedef struct s_general
{
	char	**minienv;
	char	*miniuser;
	char	*minipath;
	char	*minihome;
	char	*minipwd;

}t_general;*/

typedef struct s_mini
{
	char **minienv;
}t_mini;


/*SIZE FUNCTIONS*/
size_t	ft_strlen(const char *str);
size_t	ft_2dstrlen(char **str);

/* FREE FUNCTIONS */
void ft_general_free(t_mini *minishell);

/* PRINT FUNCTIONS */
void    ft_print2dstr(char **str);

/* ERROR FUNCTIONS */
void	ft_error_exit(int type, t_mini *minishell);

/* COPY FUNCTIONS */
char	*ft_strdup(const char *str, t_mini *minishell);
char	**ft_2dstrdup(const char **str, t_mini *minishell);
#endif
