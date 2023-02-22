/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_errors.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sperez-p <sperez-p@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 11:50:34 by sperez-p          #+#    #+#             */
/*   Updated: 2023/02/22 11:50:35 by sperez-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/minishell.h"

void	ft_process_error(int type, t_mini *minishell)
{
	if (type == MALLOC_ERROR)
		printf("Error.\nFailed to allocate memory.\n");
	if (type == NULL_ERROR)
		printf("Error.\nNULL pointer.\n");
	ft_general_free(minishell);
	exit(-1);
}