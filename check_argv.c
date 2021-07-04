/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_argv.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hayelee <hayelee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/05 08:40:09 by hayelee           #+#    #+#             */
/*   Updated: 2021/07/05 08:48:34 by hayelee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rewrite_code.h"

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