NAME= push_swap

CC= gcc

CFLAGS= -Wall -Wextra -Wall -g3 -fsanitize=address 

SRCS= params.c fill_stack.c commands.c sort5_3.c logic.c main.c insertion2.c chunks.c

LIBFT= libft

INCLUDE= -L ${LIBFT} -lft

OBJS= ${SRCS:.c=.o}

RM = rm -r

all: ${NAME}

%.o:%.c
	${CC} ${CFLAGS} -o $@ -c $^

$(NAME): ${OBJS}
	make -C ${LIBFT}
	make bonus -C ${LIBFT}
	${CC} ${CFLAGS} ${INCLUDE} ${OBJS} -o ${NAME}
clean :
	${RM} ${OBJS}
	make clean -C ${LIBFT}
fclean: 
	make fclean -C ${LIBFT}
	${RM} ${NAME}
re: fclean all
.PHONY: clean re fclean all
