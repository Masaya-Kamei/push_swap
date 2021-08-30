GAMESRCNAME	:= game_ope.c game_utils.c init_stack.c stack_ope.c
GAMESRCDIR	:= ./srcs/game/
GAMESRCS	:= $(addprefix $(GAMESRCDIR), $(GAMESRCNAME))
GAMEOBJS	:= $(GAMESRCS:.c=.o)

PUSHSWAPSRCNAME	:= push_swap.c sort.c
PUSHSWAPSRCDIR	:= ./srcs/push_swap/
PUSHSWAPSRCS	:= $(addprefix $(PUSHSWAPSRCDIR), $(PUSHSWAPSRCNAME))
PUSHSWAPOBJS	:= $(PUSHSWAPSRCS:.c=.o)

CHECKERSRCNAME	:= checker.c
CHECKERSRCDIR	:= ./srcs/checker/
CHECKERSRCS		:= $(addprefix $(CHECKERSRCDIR), $(CHECKERSRCNAME))
CHECKEROBJS		:= $(CHECKERSRCS:.c=.o)

INCLUDE := -I./include/
NAME	:= push_swap
CHECKER := checker

LIBFT		:= ./libft/libft.a
LIBFTTARGET	:= all

CC		:= gcc
CFLAGS	:= -Wall -Wextra -Werror
RM		:= rm -rf

LIBFTDIR	:= ./libft
LIBFTNAME 	:= ft
LIBFTINCLUDEDIR := ./libft

LIBINCLUDE	:= -I${LIBFTINCLUDEDIR}
LIBDIR		:= -L${LIBFTDIR}
LIBLINK		:= -l${LIBFTNAME}

all		:	$(NAME)

.c.o	:
			$(CC) $(CFLAGS) $(INCLUDE) $(LIBINCLUDE) -c $< -o $(<:.c=.o)

$(NAME)	:	$(LIBFT) $(PUSHSWAPOBJS) $(GAMEOBJS)
			$(CC) $(CFLAGS) $(INCLUDE) $(PUSHSWAPOBJS) $(GAMEOBJS) $(LIBINCLUDE) $(LIBDIR) $(LIBLINK) -o $(NAME)

$(CHECKER):	$(LIBFT) $(CHECKEROBJS) $(GAMEOBJS)
			$(CC) $(CFLAGS) $(INCLUDE) $(CHECKEROBJS) $(GAMEOBJS) $(LIBINCLUDE) $(LIBDIR) $(LIBLINK) -o $(CHECKER)

$(LIBFT):
			make $(LIBFTTARGET) -C $(LIBFTDIR)

clean	:
			$(RM) $(PUSHSWAPOBJS) $(CHECKEROBJS) $(GAMEOBJS)
			make clean -C $(LIBFTDIR)

fclean	: 	clean
			$(RM) $(NAME) $(CHECKER)
			make fclean -C $(LIBFTDIR)

re		:	fclean all

debug	: CFLAGS += -g
debug	: LIBFTTARGET := debug
debug	: re

address	: CFLAGS += -g -fsanitize=address
address	: LIBFTTARGET := address
address	: re

.PHONY:	all clean fclean re debug address
