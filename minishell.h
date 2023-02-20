/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperales <jperales@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 17:16:27 by jperales          #+#    #+#             */
/*   Updated: 2023/02/20 19:30:43 by jperales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include <stdlib.h>

typedef struct s_general
{
	char	**env;
	char    *user;
	char    *path;
	char    *home;
	char    *pwd;

}t_general;

#endif