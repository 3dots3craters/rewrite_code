/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hayelee <hayelee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/05 09:06:12 by hayelee           #+#    #+#             */
/*   Updated: 2022/02/26 15:35:22 by hayelee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rewrite_code.h"

int open_origin_file(char *filename)
{
	int fd;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		print_error("Error: CAN'T OPEN ORIGINAL FILE");
	return (fd);
}

int open_new_file(char *filename)
{
	int fd;

	fd = open(filename, O_RDWR | O_CREAT | O_TRUNC, 0644);
	if (fd < 0)
		print_error("Error: CAN'T OPEN NEW FILE");
	return (fd);
}