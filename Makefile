SRC			=	ft_printf.c \
				check_flags.c \
				check_precision.c \
				check_type.c \
				check_width.c \
				conversion/print_add.c \
				conversion/print_char.c \
				conversion/print_nb.c \
				conversion/print_str.c \
				conversion/print_uin.c \
				conversion/print_mod.c \
				conversion/str_precision.c \


HEADERS		= 	ft_print.h

LIB			=	libft.a

OBJS		= 	$(SRC:.c=.o)

NAME		= 	libftprintf.a

CC			=	gcc

CFLAGS		=	-Wall -Wextra -Werror

RM			=	rm -f

all:		$(NAME)

.c.o:		
			@$(CC) $(CFLAGS) -I $(HEADERS) -c $< -o $(<:.c=.o)

$(NAME):	$(LIB) $(OBJS)
			@echo	Making libftprintf.a ...
			@ar rcs $(NAME) $(OBJS) libft/*.o
			@echo	Done !

$(LIB):
			@echo	Making libft.a ...
			@make -C libft

clean:		
			@make -C libft $@
			@echo	.o files deleted.
			@$(RM) $(OBJS)

fclean:		clean
			@make -C libft $@
			@echo	.a file deleted.
			@$(RM) $(NAME)

re:			fclean all

.PHONY:		all clean fclean re
