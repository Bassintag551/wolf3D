/*
** weapon_utils.c for wolf3d in /home/bassintag/delivery/MUL_2016/wolf3d
** 
** Made by Antoine Stempfer
** Login   <antoine.stempfer@epitech.net>
** 
** Started on  Fri Dec 16 14:49:48 2016 Antoine Stempfer
** Last update Sun Dec 18 20:20:46 2016 Antoine Stempfer
*/

#include <stdlib.h>
#include "wolf.h"

t_weapon	*weapon_create(t_weapon_def *def)
{
  t_weapon	*res;

  res = malloc(sizeof(t_weapon));
  res->type = def;
  res->cooldown = 0;
  return (res);
}
