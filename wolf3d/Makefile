NAME	= wolf3d

SRCDIR	= ./src
INCDIR	= ./includes
OBJDIR	= ./obj
MLXDIR	= ./miniLibX

SRC		= main.c \
		  window.c \
		  image.c \
		  keyboard.c \
		  player.c \
		  reader.c \
		  map.c \
		  render.c \
		  ray.c \
		  texture.c \

OBJ		= $(addprefix $(OBJDIR)/,$(SRC:.c=.o))

CC		= gcc
CFLAGS	= -Wall -Wextra -Werror
MLX_LNK	= -L $(MLXDIR) -l mlx -framework OpenGL -framework AppKit
MLX_INC	= -I $(MLXDIR)
MLX_LIB	= $(addprefix $(MLX)/,mlx.a)

FTDIR	= ./libft
FT_LIB	= $(addprefix $(FTDIR)/,libft.a)
FT_INC	= -I $(FTDIR)
FT_LNK	= -L $(FTDIR) -l ft

all: obj $(FT_LIB) $(MLX_LIB) $(NAME)

obj:
	@mkdir -p $(OBJDIR)

$(OBJDIR)/%.o:$(SRCDIR)/%.c
	@$(CC) $(CFLAGS) $(MLX_INC) $(FT_INC) -I $(INCDIR) -o $@ -c $<

$(FT_LIB):
	@make -C $(FTDIR)

$(MLX_LIB):
	@make -C $(MLXDIR)

$(NAME): $(OBJ)
	@$(CC) $(OBJ) $(MLX_LNK) $(FT_LNK) -lm -o $(NAME)

clean:
	@rm -rf $(OBJDIR)
	@make -C $(FTDIR) clean
	@make -C $(MLXDIR) clean

fclean: clean
	@rm -f $(NAME)
	@make -C $(FTDIR) fclean

re: fclean all
