HEADER = push_swap.h

NAME = push_swap

B_NAME = checker

CC = gcc

CFLAGS = -Wall -Werror -Wextra

SRC	=	main.c\
		algo.c\
		algo1.c\
		args_check.c\
		linked_list.c\
		ft_split.c\
		libft_functions.c\
		push_a.c\
		push_b.c\
		stack_manipulation.c\
		stack_manipulation1.c\
		stack_manipulation2.c\
		stack_manipulation3.c\

BNS =	$(addprefix bonus/, checker.c)\
		algo.c\
		algo1.c\
		args_check.c\
		linked_list.c\
		ft_split.c\
		libft_functions.c\
		push_a.c\
		push_b.c\
		stack_manipulation.c\
		stack_manipulation1.c\
		stack_manipulation2.c\
		stack_manipulation3.c\
		

bonus_OBJ = ${BNS:.c=.o}

OBJ =	${SRC:.c=.o}

RM	=	rm -rf

all : ${NAME}

${NAME} : ${OBJ}
		@echo "\033[0;32m"
		@echo "██████╗░██╗░░░██╗░██████╗██╗░░██╗ ░██████╗░██╗░░░░░░░██╗░█████╗░██████╗░"
		@echo "██╔══██╗██║░░░██║██╔════╝██║░░██║ ██╔════╝░██║░░██╗░░██║██╔══██╗██╔══██╗"
		@echo "██████╔╝██║░░░██║╚█████╗░███████║ ╚█████╗░░╚██╗████╗██╔╝███████║██████╔╝"
		@echo "██╔═══╝░██║░░░██║░╚═══██╗██╔══██║ ░╚═══██╗░░████╔═████║░██╔══██║██╔═══╝░"
		@echo "██║░░░░░╚██████╔╝██████╔╝██║░░██║ ██████╔╝░░╚██╔╝░╚██╔╝░██║░░██║██║░░░░░"
		@echo "╚═╝░░░░░░╚═════╝░╚═════╝░╚═╝░░╚═╝ ╚═════╝░░░░╚═╝░░░╚═╝░░╚═╝░░╚═╝╚═╝░░░░░"
		@echo "\033[0m"
	 	@${CC} ${CFLAGS} ${SRC} -o ${NAME}

bonus : ${bonus_OBJ}
		@${CC} ${CFLAGS} ${bonus_OBJ} -o ${B_NAME}

clean :
	@${RM} ${OBJ} ${bonus_OBJ}

fclean : 
		@${RM} ${OBJ} ${bonus_OBJ} ${NAME} ${B_NAME}

re : fclean all

re_bonus : fclean bonus