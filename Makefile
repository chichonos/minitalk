# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mea <marvin@42.fr>                         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/11 11:09:03 by mea               #+#    #+#              #
#    Updated: 2022/03/11 11:49:03 by mea              ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CLIENT = client
SERVER = server

SRC_CLIENT = mainclient.c
SRC_SERVER = mainserver.c


OBJ_CLIENT = ${SRC_CLIENT:.c=.o}
OBJ_SERVER = ${SRC_SERVER:.c=.o}

CFLAGS = -Wextra -Werror -Wall
LFLAGS = -Lprintf -lftprintf
RM = rm -rf 
CC = gcc

%.o : %.c
	${CC} ${CFLAGS} -c $< -o $@		

${CLIENT} : ${OBJ_CLIENT}
	${MAKE} -C ./printf/
	${CC} ${LFLAGS} ${OBJ_CLIENT} -o ${CLIENT} 

${SERVER} : ${OBJ_SERVER}
	${MAKE} -C ./printf/
	${CC} ${LFLAGS} ${OBJ_SERVER} -o ${SERVER} 
	
all: client server

clean:
	${MAKE} -sC ./printf/ clean
	${RM} ${OBJ_CLIENT} ${OBJ_SERVER}

fclean: clean
	${MAKE} -sC ./printf/ fclean
	${RM} ${CLIENT} ${SERVER}

re: fclean all

.PHONY: all re fclean clean


