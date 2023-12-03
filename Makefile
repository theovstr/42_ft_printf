
# Variables

NAME		= libftprintf.a
INCLUDE		= include
SRC_DIR		= src/
OBJ_DIR		= obj/
CC			= cc
CFLAGS		= -Wall -Werror -Wextra -I$(INCLUDE) # Added $(INCLUDE) to include directory
RM			= rm -f
AR			= ar rcs

GREEN=\033[0;32m
YELLOW=\033[0;33m
BLUE=\033[0;34m
MAGENTA=\033[0;35m
NC=\033[0m # No Color

# Sources

SRC_FILES	= ft_printf ft_printchars ft_printptr minilibft ft_checktype ft_flags ft_itoa ft_printhexa ft_printnb ft_printunsigned


SRC 		= $(addprefix $(SRC_DIR), $(addsuffix .c, $(SRC_FILES)))
OBJ 		= $(addprefix $(OBJ_DIR), $(addsuffix .o, $(SRC_FILES)))

# Rules

all: $(NAME)

$(NAME): $(OBJ)
	@$(AR) $(NAME) $(OBJ)
	@echo "$(GREEN)Compiled ✓ $(NAME)$(NC)"

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@echo "$(YELLOW)Compiling $<...$(NC)"
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CFLAGS) -c -fPIE $< -o $@

clean:
	@$(RM) -rf $(OBJ_DIR)
	@echo "$(MAGENTA)Cleaned object files ✓ $(NC)"

fclean: clean
	@$(RM) -f $(NAME)
	@echo "$(MAGENTA)Cleaned $(NAME) ✓ $(NC)"

re: fclean all
	@echo "$(BLUE)Cleaned and recompiled $(NAME) ✓ $(NC)"
