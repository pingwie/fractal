DEL_LINE =		\033[2K
ITALIC =		\033[3m
BOLD =			\033[1m
DEF_COLOR =		\033[0;39m
GRAY =			\033[0;90m
RED =			\033[0;91m
GREEN =			\033[0;92m
YELLOW =		\033[0;93m
BLUE =			\033[0;94m
MAGENTA =		\033[0;95m
CYAN =			\033[0;96m
WHITE =			\033[0;97m
BLACK =			\033[0;99m
ORANGE =		\033[38;5;209m
BROWN =			\033[38;2;184;143;29m
DARK_GRAY =		\033[38;5;234m
MID_GRAY =		\033[38;5;245m
DARK_GREEN =	\033[38;2;75;179;82m
DARK_YELLOW =	\033[38;5;143m

NAME	:= fractol
CFLAGS	:= -Wextra -Wall -Werror -Wunreachable-code -Ofast
LIBMLX	:= ./lib/
OBJ_DIR = obj
SRC_DIR = src
RM		= rm -f
RMD		= rm -r -f

HEADERS	:= -I $(LIBMLX)
LIBS	:= $(LIBMLX)/libmlx42.a -ldl -lglfw -pthread -lm
SRCS = $(wildcard $(SRC_DIR)/*.c)
OBJS	:= ${patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRCS)}

all: $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	@echo "$(BROWN)Compiling ${MAGENTA}→ $(CYAN) $(notdir $<) $(DEF_COLOR)"
	@$(CC) $(CFLAGS) -c $< -o $@ $(HEADERS) -g

$(NAME): $(OBJS)
	@$(CC) $(OBJS) $(LIBS) $(HEADERS) -o $(NAME)
	@echo "\n$(GREEN)   Created $(NAME) ✓ $(DEF_COLOR)\n"

clean:
	@$(RMD) $(OBJ_DIR)
	@echo "${BLUE} ◎ $(RED)All objects cleaned successfully ${BLUE}◎$(DEF_COLOR)\n"

fclean: clean
	@$(RM) $(NAME)
	@echo "${BLUE} ◎ $(GREEN)$(NAME) $(RED)deleted successfully ${BLUE}◎$(DEF_COLOR)"

re: fclean all

.PHONY: all, clean, fclean, re
