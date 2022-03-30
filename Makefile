# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: jvan-kra <jvan-kra@student.42.fr>            +#+                      #
#                                                    +#+                       #
#    Created: 2021/10/19 15:45:22 by jvan-kra      #+#    #+#                  #
#    Updated: 2021/12/17 21:55:19 by jvan-kra      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME 		=	pipex
HEADERS		=	pipex.h
HEADERS_DIR	=	includes
SRCS_DIR	=	srcs
BUILD_DIR	=	build
LIBFT		=	libft/libft.a
CFLAGS 		=	-Wall -Wextra -Werror

SRCS		=	main.c pipex.c error_exit.c path_parsing.c wait.c

DIR_CREATE	= @mkdir -p $(@D)
_HEADERS	= ${addprefix ${HEADERS_DIR}/, ${HEADERS}}
_OBJS		= ${addprefix ${BUILD_DIR}/, ${SRCS:.c=.o}}

all: ${NAME}

${BUILD_DIR}/%.o: ${SRCS_DIR}/%.c ${_HEADERS}
	${DIR_CREATE}
	${CC} ${CFLAGS} -Ilibft -I${HEADERS_DIR} -c -o $@ $<

${LIBFT}:
	@${MAKE} -C libft

${NAME}: ${LIBFT} ${_OBJS}
		${CC} ${CFLAGS} ${_OBJS} ${LIBFT} -o ${NAME}

clean:
	@${MAKE} -C libft clean
	${RM} -r ${BUILD_DIR}

fclean: clean
	@${MAKE} -C libft fclean
	${RM} ${NAME}

re: fclean all

bonus: all

.PHONY: all clean fclean re