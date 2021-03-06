/*
** render_walls.c for wolf3d in /home/bassintag/delivery/MUL_2016/wolf3d
** 
** Made by Antoine Stempfer
** Login   <antoine.stempfer@epitech.net>
** 
** Started on  Sun Dec 18 15:23:56 2016 Antoine Stempfer
** Last update Fri Jan  6 15:12:11 2017 Antoine Stempfer
*/

#include <math.h>
#include "wolf.h"

static void	calc_draw_pos(int height, int line_height,
			      sfVector2i *draw_pos)
{
  draw_pos->x = -line_height / 2 + height / 2;
  draw_pos->y = line_height / 2 + height / 2;
}

static sfVector2f	calc_cam_pos(float cam_x, t_map *map)
{
  sfVector2f		cam_pos;

  cam_pos = my_vector2f_create(map->player.cam_plane.x * cam_x
			       + map->player.dir.x,
			       map->player.cam_plane.y * cam_x
			       + map->player.dir.y);
  return (cam_pos);
}

static void	draw_strip(t_my_framebuffer *buffer, t_map *map,
			   t_raycast_hit hit, int x)
{
  sfVector2i	draw_pos;

  calc_draw_pos(HUD_START, HUD_START / hit.dist, &draw_pos);
  if ((map->app->flags & FLAG_NO_TEXTURES) == 0)
    my_draw_vertical_strip_cam(buffer, my_vector2i_create(x, hit.texture_x),
			       draw_pos, (hit.side == 1 || hit.side == 3) ?
			       &map->textures_walls[(hit.id - 1) * 2] :
			       &map->textures_walls[(hit.id - 1) * 2 + 1]);
  else
    my_draw_vertical_line(buffer, x, draw_pos, hit.side == 1 ?
			  sfRed : hit.side == 2 ?
			  sfBlue : hit.side == 3 ?
			  sfGreen : sfYellow);
}

void		render_walls(t_my_framebuffer *buffer, t_map *map)
{
  float		angle;
  float		rel_angle;
  t_raycast_hit	hit;
  int		x;
  float		cam_x;
  sfVector2f	cam_pos;

  x = 0;
  while (x < WINDOW_W)
    {
      cam_x = 2 * (WINDOW_W - x) / (float)WINDOW_W - 1;
      cam_pos = calc_cam_pos(cam_x, map);
      rel_angle = atan2(cam_x, 1);
      angle = atan2(cam_pos.x, cam_pos.y);
      hit = raycast(map->player.position, angle, map->tiles, map->size);
      hit.dist *= cosf(rel_angle);
      map->z_buffer[x++] = hit.dist;
      draw_strip(buffer, map, hit, x);
    }
}
