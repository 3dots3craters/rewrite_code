/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rewrite_code.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hayelee <hayelee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/03 16:51:30 by hayelee           #+#    #+#             */
/*   Updated: 2021/07/05 09:12:08 by hayelee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REWRITE_CODE_H
# define REWRITE_CODE_H

# include <stdio.h>
# include "get_next_line/get_next_line.h"

# define VAR_LINE 1
# define FUNC_LINE 2

typedef struct s_info
{
    int func_tab_start_idx;
    int func_tab_end_idx;
    int var_tab_idx;
}   t_info;

/*
** main.c
*/
void check_argv(int argc, char *argv[]);
void init_info(t_info *info);
void print_error(char *error);

/*
** open_file.c
*/
int open_origin_file(char *filename);
int open_new_file(char *filename);

/*
** rewrite_file.c
*/
int rewrite_file(int num_pr, int argc, char *argv[], t_info *info);
int rewrite_last_file(int num_pr, char *argv[], t_info *info);

/*
** check_line_info.c
*/
int check_line_info(char *line, t_info *info);
int is_var_declaration_line(char *line, int len, t_info *info);
int is_func_definition_line(char *line, t_info *info);

/*
** > make
*/
void make_new_file(char *line, int err_num, int new_fd, int ret_gnl, t_info *info);
char **make_second_argument(char *origin, char *new);

/*
** > utils
*/
int	ft_strchr_idx(const char *s, int c);
int	ft_strrchr_idx(const char *s, char c);


#endif