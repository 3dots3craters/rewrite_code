/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_new_file.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hayelee <hayelee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/03 16:55:07 by hayelee           #+#    #+#             */
/*   Updated: 2021/07/05 09:15:16 by hayelee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../rewrite_code.h"

void	make_new_file(char *line, int err_num, int new_fd, int ret_gnl, t_info *info)
{
	int	i;

	i = -1;
	if (err_num == FUNC_LINE)
	{
		while (line[++i])
		{
			if (i == info->func_tab_start_idx)
			{
				write(new_fd, "\t", 1);
				while (i <= info->func_tab_end_idx)
					++i;
			}
			write(new_fd, &line[i], 1);
		}
		write(new_fd, "\n", 1);
	}
	else if (err_num == VAR_LINE)
	{
		while (line[++i])
		{
			if(i == info->var_tab_idx)
			{
				write(new_fd, "\t", 1);
				++i;
			}
			write(new_fd, &line[i], 1);
		}
		write(new_fd, "\n", 1);
	}
	else
	{
		if (ret_gnl == 0)
			return ;
		while (line[++i])
			write(new_fd, &line[i], 1);
		write(new_fd, "\n", 1);
	}
	return ;
}
