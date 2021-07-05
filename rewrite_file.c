/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rewrite_file.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hayelee <hayelee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/05 09:05:43 by hayelee           #+#    #+#             */
/*   Updated: 2021/07/05 09:08:54 by hayelee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rewrite_code.h"

int	rewrite_file(int num_pr, int argc, char *argv[], t_info *info)
{
	int	fd;
	int	new_fd;
	int	status;
	int	ret_gnl;
	int	err_num;
	pid_t	pid;
	char	*line;
	char	**second;

	if (argc - 1 == num_pr)
		rewrite_last_file(num_pr, argv, info);
	pid = fork();
	if (pid > 0)
	{
		waitpid(pid, &status, WUNTRACED);
		fd = open_origin_file(argv[num_pr]);
		new_fd = open_new_file("tmp");
		ret_gnl = 1;
		init_info(info);
		while (ret_gnl == 1)
		{
			ret_gnl = get_next_line(fd, &line);
			if (ret_gnl == -1)
			{
				free(line);
				printf("Error: wrong get_next_line\n");
				close(fd);
				close(new_fd);
				exit(1);
			}
			err_num = check_line_info(line, info);
			make_new_file(line, err_num, new_fd, ret_gnl, info);
			free(line);
		}
		close(fd);
		close(new_fd);
		second = make_second_argument(argv[num_pr], "tmp");
		if (second == NULL)
			return (0);
		execve(second[0], second, 0);
	}
	if (pid == 0)
		rewrite_file(num_pr + 1, argc, argv, info);
	return (0);
}

int	rewrite_last_file(int num_pr, char *argv[], t_info *info)
{
	int	fd;
	int	new_fd;
	int	ret_gnl;
	int	err_num;
	char	*line;
	char	**second;

	fd = open_origin_file(argv[num_pr]);
	new_fd = open_new_file("tmp");
	ret_gnl = 1;
	init_info(info);
	while (ret_gnl == 1)
	{
		ret_gnl = get_next_line(fd, &line);
		if (ret_gnl == -1)
		{
			free(line);
			printf("Error: WRONG GET_NEXT_LINE\n");
			close(fd);
			close(new_fd);
			exit(1);
		}
		err_num = check_line_info(line, info);
		make_new_file(line, err_num, new_fd, ret_gnl, info);
		free(line);
	}
	close(fd);
	close(new_fd);
	second = make_second_argument(argv[num_pr], "tmp");
	if (second == NULL)
		return (0);
	execve(second[0], second, 0);
	return (0);
}
