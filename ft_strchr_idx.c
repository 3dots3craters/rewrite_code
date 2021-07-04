/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr_idx.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hayelee <hayelee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/13 09:32:53 by hayelee           #+#    #+#             */
/*   Updated: 2021/07/04 20:47:34 by hayelee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rewrite_code.h"

int	ft_strchr_idx(const char *s, int c)
{
	int	i;

	i = 0;
	while (42)
	{
		if (s[i] == (unsigned char)c && s[i])
			return (i);
		if (s[i] == '\0')
			return (-1);
		i++;
	}
}
