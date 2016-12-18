##
## Makefile for wolf3d in /home/antoine.stempfer/delivery/MUL_2016/wolf3d
##
## Made by Bassintag
## Login   <bassintag@epitech.eu>
##
## Started on  Mon Dec 12 13:36:51 2016 Bassintag
## Last update Sun Dec 18 20:56:18 2016 Antoine Stempfer
##

CC	=	gcc

RM	=	rm -f

CFLAGS	=	-Wextra -Wall -I $(INC) -O3

LDFLAGS	=	-L$(LIBDIR) -lc_graph_prog -lmy -lmyio -lmylists -lm

INC	=	include

LIBDIR	=	lib

NAME	=	wolf3d

OBJS	=	$(SRCS:.c=.o)

SRCS	=	src/setup_globals.c \
		src/init_app.c \
		src/init_map.c \
		src/init_walls_textures.c \
		src/init_objects_textures.c \
		src/init_weapons_textures.c \
		src/init_hud_textures.c \
		src/init_player.c \
		src/init_entities.c \
		src/start_game.c \
		src/main_loop.c \
		src/update_pickup_score.c \
		src/update_pickup_food.c \
		src/update_pickup_dog_food.c \
		src/update_pickup_medikit.c \
		src/update_pickup_ammo.c \
		src/update_pickup_machine_gun.c \
		src/update_pickup_chain_gun.c \
		src/update_objects.c \
		src/render_map.c \
		src/render_walls.c \
		src/render_objects.c \
		src/render_hud.c \
		src/handle_events.c \
		src/raycast.c \
		src/main.c \
		src/object_utils.c \
		src/player_utils.c \
		src/my_framebuffer.c \
		src/my_put_pixel.c \
		src/my_load_texture.c \
		src/my_slice_texture.c \
		src/my_destroy_texture.c \
		src/my_texture_get_at.c \
		src/my_clean.c \
		src/my_draw_vertical_line.c \
		src/my_draw_vertical_strip.c \
		src/my_draw_rect.c \
		src/my_draw_texture.c \
		src/my_draw_num.c \
		src/can_move.c \
		src/can_see.c \
		src/my_vectors2.c \
		src/move_forward.c \
		src/map_utils.c \
		src/weapon_utils.c \
		src/keybinds/key_close.c \
		src/keybinds/key_left.c \
		src/keybinds/key_right.c \
		src/keybinds/key_strafe_left.c \
		src/keybinds/key_strafe_right.c \
		src/keybinds/key_forward.c \
		src/keybinds/key_back.c \
		src/keybinds/key_weapon_next.c \
		src/keybinds/key_weapon_shoot.c

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(OBJS) -o $(NAME) $(LDFLAGS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: clean all

.PHONY: all clean fclean re
