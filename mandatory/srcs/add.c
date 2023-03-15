/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sperez-p <sperez-p@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 17:01:56 by sperez-p          #+#    #+#             */
/*   Updated: 2023/03/14 17:01:57 by sperez-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/minishell.h"

char	*ft_join_chr(char *str, int c)
{
	char	*new_str;
	int		i;

	i = 0;
	new_str = (char *)malloc(sizeof(char) * ft_strlen(str) + 2);
	if (!new_str)
		return (NULL);
	if (str)
	{
		while (str[i])
		{
			new_str[i] = str[i];
			i++;
		}
		free(str);
	}
	new_str[i] = c;
	new_str[++i] = '\0';
	return (new_str);
}