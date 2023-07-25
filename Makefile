# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jmiranda <jmiranda@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/13 19:59:56 by jmiranda          #+#    #+#              #
#    Updated: 2023/02/16 16:05:02 by jmiranda         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME    = so_long

SRCS    = check_parsing.c clear.c errors.c errors2.c get.c main.c \
 		 moves.c render_image.c \

LIBFT   = libft/libft.a

OBJS    = ${SRCS:.c=.o}

CC      = gcc

CFLAGS  = -Wall -Wextra -Werror

all     : ${NAME}

${NAME} : ${LIBFT} ${OBJS}
				@$(CC) -lmlx -framework OpenGL -framework AppKit ${LIBFT} ${OBJS} -o ${NAME}
				@echo so_long Is Complete!
${LIBFT}:
				@$(MAKE) -C libft

%.o     : %.c
				@echo -n .
				@$(CC) $(CFLAGS) -c $< -o $@

clean   :
				@rm -f ${OBJS} libft/*.o

fclean  : clean
				@rm -f ${NAME} libft/libft.a

re      : fclean all

.PHONY  : all bonus clean fclean re
