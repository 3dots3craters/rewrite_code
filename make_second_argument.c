/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_second_argument.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hayelee <hayelee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/03 16:54:54 by hayelee           #+#    #+#             */
/*   Updated: 2021/07/04 18:51:30 by hayelee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rewrite_code.h"

char	**make_second_argument(char *origin, char *new)
{
	int	i;
	char	**ret;

	i = -1;
	ret = (char **)malloc(sizeof(char *) * 4);
	if (ret == NULL)
		return (NULL);
	ret[0] = ft_strdup("/bin/mv");
	if (ret[0] == NULL)
	{	
		free(ret);
		return (NULL);
	}
	ret[1] = ft_strdup(new);
	if (ret[1] == NULL)
	{
		free(ret[0]);
		free(ret);
		return (NULL);
	}
	ret[2] = ft_strdup(origin);
	if (ret[2] == NULL)
	{
		free(ret[0]);
		free(ret[1]);
		free(ret);
		return (NULL);
	}
	ret[3] = NULL;
	return (ret);
}
