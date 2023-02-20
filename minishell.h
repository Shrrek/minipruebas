/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperales <jperales@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 17:16:27 by jperales          #+#    #+#             */
/*   Updated: 2023/02/20 19:59:28 by jperales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include <stdlib.h>

typedef struct s_general
{
	char	**minienv;
	char    *miniuser;
	char    *minipath;
	char    *minihome;
	char    *minipwd;

}t_general;

#endif