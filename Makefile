# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hayelee <hayelee@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/14 14:13:25 by hayelee           #+#    #+#              #
#    Updated: 2021/07/05 09:18:08 by hayelee          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= rewrite

SRCS			= 	main.c\
					open_file.c\
					rewrite_file.c\
					check_line_info.c\
					utils/ft_strchr_idx.c\
					utils/ft_strrchr_idx.c\
					make/make_new_file.c\
					make/make_second_argument.c\
					get_next_line/get_next_line.c\
					get_next_line/get_next_line_utils.c\

OBJS			= $(SRCS:.c=.o)

CC				= gcc 
RM				= rm -f
CFLAGS			= -Wall -Wextra -Werror -I.

all:			$(NAME)

$(NAME):		$(OBJS)
				$(CC) ${CFLAGS} -o ${NAME} ${OBJS}

clean:
				$(RM) $(OBJS) 

fclean:			clean
				$(RM) $(NAME) 

re:				fclean $(NAME)

.PHONY:			all clean fclean re
