SRC		= 			\
		atoi		\
		bzero		\
		calloc		\
		isalnum		\
		isalpha		\
		isascii		\
		isdigit		\
		isprint		\
		itoa		\
		memchr		\
		memcmp		\
		memcpy		\
		memmove		\
		memset		\
		putchar_fd	\
		putendl_fd	\
		putnbr_fd 	\
		putstr_fd 	\
		split		\
		strchr		\
		strdup		\
		striteri 	\
		strjoin		\
		strlcat		\
		strlcpy		\
		strlen		\
		strmapi 	\
		strncmp		\
		strnstr		\
		strrchr		\
		strtok		\
		strtrim		\
		substr		\
		tolower		\
		toupper		\
		free_split	\
		ends_with	\
		count_occurence	\

EXTRA		=						\
				lstadd_front		\
				lstadd_back			\
				lstclear			\
				lstdelone			\
				lstiter				\
				lstlast				\
				lstmap				\
				lstnew				\
				lstsize				\

PREFIX		= ft_
SUFFIX		= .c

SRC_P		= $(addprefix $(PREFIX), $(SRC))
SRC_F		= $(addsuffix $(SUFFIX), $(SRC_P))
SRCDIR		= ./
SRCS		= $(addprefix $(SRCDIR), $(SRC_F))

EXTRA_P		= $(addprefix $(PREFIX), $(EXTRA))
EXTRA_F		= $(addsuffix $(SUFFIX), $(EXTRA_P))
EXTRA_DIR	= ./
EXTRAS		= $(addprefix $(EXTRA_DIR), $(EXTRA_F))

HEADER_DIR	= ./
HEADER		= libft.h
HEADERS		= $(addprefix $(HEADER_DIR), $(HEADER))

OBJDIR		= ./
OBJS		= $(addprefix $(OBJDIR),$(notdir $(SRCS:.c=.o)))
EXTRA_OBJS	= $(addprefix $(EXTRA_DIR),$(notdir $(EXTRAS:.c=.o)))

# MAIN		= main.c
NAME		= libft.a
CC			= cc
CFLAGS		= -Wall -Wextra -Werror
IFLAGS		= -I$(HEADERS)
AR			= ar rcs
RM 			= rm -rf

UP			= \033[1A
FLUSH		= \033[2K

all: $(NAME)

bonus: $(NAME) $(EXTRA_OBJS)
	@$(AR) $(NAME) $(OBJS) $(EXTRA_OBJS)

# run: $(NAME)
# 	@$(CC) $(MAIN) $(NAME)
# 	@./a.out

$(OBJDIR)%.o: $(SRCDIR)%.c
	$(CC) $(CFLAGS) -c $< -o $@
	@echo "$(UP)$(FLUSH)$(UP)"

$(NAME): $(OBJS)
	@$(AR) $(NAME) $(OBJS)

clean:
	@$(RM) $(OBJS) $(EXTRA_OBJS)

fclean: clean
	@$(RM) $(NAME)

re: fclean $(NAME)

.PHONY: all bonus clean fclean re
