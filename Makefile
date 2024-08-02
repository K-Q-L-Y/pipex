SRCDIR		= srcs
SRCS		:= $(shell find $(SRCDIR) -name '*.c')

OBJDIR		= objs
OBJDIRS		= $(sort $(dir $(OBJS)))
OBJS		= $(subst $(SRCDIR),$(OBJDIR),$(subst .c,.o,$(SRCS)))

CWD			:= $(shell pwd)
INCLUDE_DIR	= includes
HEADER_DIR	= headers
HEADERS		:= $(shell find $(HEADER_DIR) -name '*.h')
HEADERS_INC	= $(addprefix -I,$(sort $(dir $(HEADERS))))

LIBFT_DIR	= $(INCLUDE_DIR)/libft
LIBFT		= $(LIBFT_DIR)/libft.a

LIBS		= $(LIBFT)

IFLAGS		:= -I. $(HEADERS_INC)

CC			= cc
CFLAGS		= -Wall -Wextra -Werror -fsanitize=address -g3
AR			= ar -rcs
RM			= rm -rf
UP			= \033[1A
FLUSH		= \033[2K

NAME		= pipex
ARGS		= "input.txt" "ls -l" "output.txt"

$(NAME): $(OBJDIRS) $(OBJS) $(LIBS)
	$(CC) $(CFLAGS) $(IFLAGS) $(OBJS) $(LIBS) -o $(NAME)

all: $(NAME)

$(OBJDIRS):
	@mkdir -p $@

$(OBJDIR)/%.o: $(SRCDIR)/%.c $(HEADERS) $(LIBS)
	$(CC) $(CFLAGS) $(IFLAGS) -c $< -o $@
	@echo "$(UP)$(FLUSH)$(UP)"

clean:
	@$(RM) $(OBJS)

fclean:	clean
	make -C $(LIBFT_DIR) fclean
	@$(RM) $(NAME)
	@$(RM) $(OBJDIRS)
	@$(RM) *.txt

run:
	./$(NAME) $(ARGS)

re: fclean $(NAME)

push:
	@read -p "Commit name: " commit_name; make fclean;	\
	cd $(CWD); git add .; git commit -m "$$commit_name"; git push;	\

$(LIBFT): $(LIBFT_DIR) $(shell find $(LIBFT_DIR) -name "*.c")
	make -C $(LIBFT_DIR) all

.PHONY: all clean fclean re push