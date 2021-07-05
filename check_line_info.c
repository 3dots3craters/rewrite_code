/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_line_info.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hayelee <hayelee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/03 16:55:20 by hayelee           #+#    #+#             */
/*   Updated: 2021/07/05 08:58:33 by hayelee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rewrite_code.h"

int	check_line_info(char *line, t_info *info)
{
	int	i;
	int ret;
	int len;	

	ret = 0;
   	i = -1;
	len = ft_strlen(line);
	if (line[len - 1] == ';')
		ret = is_var_declaration_line(line, len, info);
	else if (line[len - 1] == ')')
		ret = is_func_definition_line(line, info);
	return (ret);
}

int is_var_declaration_line(char *line, int len, t_info *info)
{
	int tab_pos;
	int len2;
	int len3;

	len2 = len;
	len3 = len;
	tab_pos = 0;	
	if (line[len - 2] == ')')
	{
		return (0);
	}
	if (line[len - 2] == ' ' && line[len - 3] == 'n' && line[len - 4] == 'r'
		&& line[len - 5] == 'u' && line[len - 6] == 't' && line[len - 7] == 'e'
		&& line[len - 8] == 'r' && line[len - 9] == '\t')
		return (0);
	while (--len >= 0)
	{
		if (line[len] == '=' || line[len] == '+' || line[len] == '-')
		{
			return (0);
		}
	}
	while (--len2 >= 0)
	{
		if (line[len2] == '\t')
		{
			tab_pos = len2;
		   	break;	
		}
	}
	while (--len3 >= 0)
	{	
		if (line[len3] == ' ' && len3 > len2)
		{
			info->var_tab_idx = len3;
			return (VAR_LINE);
		}
	}
	return (0);
}

int is_func_definition_line(char *line, t_info *info)
{
	int pos;

	if (line[0] == '\t' || line[0] == ' ')
		return (0);
	pos = ft_strchr_idx(line, '(');
	while (--pos >= 0)
	{
		if (line[pos] == '\t')
		{
			info->func_tab_end_idx = pos;
			while (line[pos] == '\t')
			{
				if (line[pos - 1] != '\t')
				{	
					info->func_tab_start_idx = pos;
					return (FUNC_LINE);
				}
				--pos;
			}			
		}
	}
	return (0);
}
