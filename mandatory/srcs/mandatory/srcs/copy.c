/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copy.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperales <jperales@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 16:00:33 by jperales          #+#    #+#             */
/*   Updated: 2023/02/23 16:23:13 by jperales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/minishell.h"

char	*ft_strdup_free(const char *str, t_mini *minishell, char *src)
{
	int		i;
	char	*dst;

	i = -1;
	if (!str)
		ft_process_error(NULL_ERROR, minishell);
	dst = (char *)malloc(sizeof(char) * ft_strlen((const char *)str) + 1);
	if (!dst)
		ft_process_error(MALLOC_ERROR, minishell);
	while (str[++i])
		dst[i] = str[i];
	dst[i] = '\0';
	free(src);
	return (dst);
}

char	*ft_strdup(const char *str, t_mini *minishell)
{
	int		i;
	char	*dst;

	i = -1;
	if (!str)
		ft_process_error(NULL_ERROR, minishell);
	dst = (char *)malloc(sizeof(char) * ft_strlen((const char *)str) + 1);
	if (!dst)
		ft_process_error(MALLOC_ERROR, minishell);
	while (str[++i])
		dst[i] = str[i];
	dst[i] = '\0';
	return (dst);
}

char	**ft_2dstrdup(const char **str, t_mini *minishell)
{
	int		i;
	char	**dst;

	i = -1;
	if (!str)
		return (NULL);
	dst = (char **)malloc(sizeof(char *) * ((int)ft_2dstrlen + 1));
	if (!dst)
		ft_process_error(MALLOC_ERROR, minishell);
	while (str[++i])
		dst[i] = ft_strdup(str[i], minishell);
	dst[i] = NULL;
	return (dst);
} 
