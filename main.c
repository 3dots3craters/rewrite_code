/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hayelee <hayelee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/03 16:53:44 by hayelee           #+#    #+#             */
/*   Updated: 2021/07/05 09:07:51 by hayelee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rewrite_code.h"

int	main(int argc, char *argv[])
{
	t_info info;
	
	int	i;

	i = 1;
	check_argv(argc, argv);
	rewrite_file(i, argc, argv, &info);
	return (0);
}

void check_argv(int argc, char *argv[])
{
    int i;
    int len;

    i = 0;
    len = 0;
    while (++i < argc)
    {
        len = ft_strlen(argv[i]);
        if (argv[i][len - 1] != 'c' && argv[i][len - 2] != '.')
        {
            print_error("Error: WRONG FILE\t\t: Check only c files");
        }
    }
}

void init_info(t_info *info)
{
	info->func_tab_start_idx = 0;
    info->func_tab_end_idx = 0;
    info->var_tab_idx = 0;
}

void	print_error(char *error)
{
	printf("%s\n", error);
	exit(1);
}
