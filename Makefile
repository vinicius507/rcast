NAME		=	rcast

CC			=	cc
CFLAGS 	= -O0 -g3
LIBS		=	-lmlx -lX11 -lXext -lm

RM			=	rm -rf

SRCS 		:= main.c image.c screen.c colors.c raycast.c render.c
SRCS		:= $(addprefix src/,$(SRCS))
OBJS		=	${SRCS:%.c=$(OBJS_DIR)%.o}
OBJS_DIR	=	build/

all:		$(NAME)

$(NAME):	$(OBJS)
			$(CC) $(CFLAGS) $(OBJS) -o $(NAME) $(LIBS)

$(OBJS_DIR)%.o:	%.c
			@mkdir -p $(dir $@)
			$(CC) $(CFLAGS) -c $< -o $@

clean:
			$(RM) $(OBJS_DIR)

fclean:
			$(RM) $(NAME)
			$(RM) $(OBJS_DIR)

re:			fclean all

.PHONY:		all clean fclean re run libft
