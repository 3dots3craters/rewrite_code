/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hayelee <hayelee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/03 16:53:44 by hayelee           #+#    #+#             */
/*   Updated: 2021/07/05 08:47:21 by hayelee          ###   ########.fr       */
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

int	open_origin_file(char *filename)
{
	int	fd;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		print_error("Error: OPEN ORIGINAL FILE ERROR");
	return (fd);
}

int	open_new_file(char *filename)
{
	int	fd;

	fd = open(filename, O_RDWR | O_CREAT | O_TRUNC, 0644);
	if (fd < 0)
		print_error("Error: OPEN NEW FILE ERROR");
	return (fd);
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
