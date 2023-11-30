# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jmiranda <jmiranda@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/13 19:59:56 by jmiranda          #+#    #+#              #
#    Updated: 2023/02/16 13:41:51 by jmiranda         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME   = libft.a

SRCS   = ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c \
         ft_isascii.c ft_isdigit.c ft_isprint.c ft_memchr.c ft_memcmp.c \
         ft_memcpy.c ft_memmove.c ft_memset.c ft_strchr.c ft_strdup.c \
         ft_strlcat.c ft_strlcpy.c ft_strlen.c ft_strncmp.c ft_strnstr.c \
         ft_strrchr.c ft_tolower.c ft_toupper.c ft_substr.c ft_strjoin.c \
         ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c ft_striteri.c \
         ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c \
		 get_next_line.c get_next_line_utils.c \

SRCS_B = ft_lstadd_back.c ft_lstadd_front.c ft_lstclear.c ft_lstdelone.c \
		 ft_lstiter.c ft_lstlast.c ft_lstmap.c ft_lstnew.c ft_lstsize.c \

OBJS   = ${SRCS:.c=.o}

OBJS_B = ${SRCS_B:.c=.o}

CC     = gcc

CFLAGS = -Wall -Wextra -Werror

all    : ${NAME}

${NAME}: ${OBJS}
				@ar -rcs ${NAME} ${OBJS}
				@echo Libft Is Complete!

bonus : ${OBJS_B}
				@ar -rcs ${NAME} ${OBJS_B}
				@echo Libft_Bonus Is Complete!

%.o    : %.c
				@echo -n .
				@$(CC) $(CFLAGS) -c $< -o $@

clean  :
				@rm -f ${OBJS} ${OBJS_B}

fclean : clean
				@rm -f ${NAME}

re     : fclean all

.PHONY : all bonus clean fclean re
