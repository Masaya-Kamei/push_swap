SRCSDIR	:= srcs
OBJSDIR	:= objs

GAME_SRCSNAME	:= init_stacks.c game_ope.c stack_ope.c utils.c
GAME_SRCSDIR	:= $(SRCSDIR)/game
GAME_SRCS		:= $(addprefix $(GAME_SRCSDIR)/, $(GAME_SRCSNAME))
GAME_OBJSDIR	:= $(OBJSDIR)/game
GAME_OBJS		:= $(addprefix $(GAME_OBJSDIR)/, $(GAME_SRCSNAME:.c=.o))

SORT_SRCSNAME	:= sort_main.c sort_5or_less.c sort_6or_more.c
SORT_SRCSDIR	:= $(SRCSDIR)/sort
SORT_SRCS		:= $(addprefix $(SORT_SRCSDIR)/, $(SORT_SRCSNAME))
SORT_OBJSDIR	:= $(OBJSDIR)/sort
SORT_OBJS		:= $(addprefix $(SORT_OBJSDIR)/, $(SORT_SRCSNAME:.c=.o))

CHECKER_SRCSNAME:= checker_main.c
CHECKER_SRCSDIR	:= $(SRCSDIR)/checker
CHECKER_SRCS	:= $(addprefix $(CHECKER_SRCSDIR)/, $(CHECKER_SRCSNAME))
CHECKER_OBJSDIR	:= $(OBJSDIR)/checker
CHECKER_OBJS	:= $(addprefix $(CHECKER_OBJSDIR)/, $(CHECKER_SRCSNAME:.c=.o))

INCLUDE := -I./include/
NAME	:= push_swap
CHECKER := checker

CC		:= gcc
CFLAGS	:= -Wall -Wextra -Werror
RM		:= rm -rf

LIBFTDIR	:= ./libft
LIBFT		:= $(LIBFTDIR)/libft.a
LIBFTTARGET	:= all

LIBINCLUDE	:= -I${LIBFTDIR}
LIBDIR		:= -L${LIBFTDIR}
LIBLINK		:= -lft
LIB			:= $(LIBINCLUDE) $(LIBDIR) $(LIBLINK)

all		:	$(NAME)

$(NAME)	:	$(LIBFT) $(SORT_OBJS) $(GAME_OBJS)
			$(CC) $(CFLAGS) $(INCLUDE) $(SORT_OBJS) $(GAME_OBJS) $(LIB) -o $(NAME)

$(CHECKER):	$(LIBFT) $(CHECKER_OBJS) $(GAME_OBJS)
			$(CC) $(CFLAGS) $(INCLUDE) $(CHECKER_OBJS) $(GAME_OBJS) $(LIB) -o $(CHECKER)

$(OBJSDIR)/%.o  :   $(SRCSDIR)/%.c
			@mkdir -p $(dir $@)
			$(CC) $(CFLAGS) $(INCLUDE) $(LIBINCLUDE) -o $@ -c $<

$(LIBFT):
			make $(LIBFTTARGET) -C $(LIBFTDIR)

clean	:
			$(RM) $(SORT_OBJS) $(CHECKER_OBJS) $(GAME_OBJS)
			make clean -C $(LIBFTDIR)

fclean	: 	clean
			$(RM) $(NAME) $(CHECKER)
			make fclean -C $(LIBFTDIR)

re		:	fclean all

address	:	CFLAGS		+=	-g -fsanitize=address
address	:	LIBFTTARGET	:=	address
address	:	re checker

leak	:	CC			:=	/usr/local/opt/llvm/bin/clang
leak	:	CFLAGS		+=	-g -fsanitize=leak
leak	:	LIBFTTARGET	:=	leak
leak	:	re checker

.PHONY:	all clean fclean re address leak
