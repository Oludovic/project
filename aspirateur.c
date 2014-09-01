/*
** aspirateur.c for qsd in /home/ovsepi_l/rendu/Robby
** 
** Made by Ludovic Ovsepian
** Login   <ovsepi_l@epitech.net>
** 
** Started on  Sat Jun 28 18:05:31 2014 Ludovic Ovsepian
** Last update Mon Jun 30 21:36:43 2014 Ludovic Ovsepian
*/

#include "struct.h"
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>

void	init_struc(t_rob *rob)
{
  int	x;
  int	y;

  x = 0;
  y = 0;
  rob->y = 0;
  rob->xdab = 0;
  rob->ydab = 0;
  rob->xrob = 10;
  rob->yrob = 10;
  rob->cooldown = 0;
  rob->meat = 0;
  while (y < 20)
    {
      while (x < 20)
	rob->tab[y][x++] = ' ';
      rob->tab[y][x] = '\0';
      y++;
      x = 0;
    }
  rob->tab[y][0] = '\0';
}

int	count_line(char *str)
{
  int	i;
  int	count;

  count = 0;
  i = 0;
  while (str[i] != 0)
    {
      if (str[i] == ';')
	count++;
      i++;
    }
  return (count);
}

void	mouv_dab(t_rob *rob)
{
  if (rob->meat == 1)
    rob->tab[rob->ydab][rob->xdab] = 'o';
  else
    rob->tab[rob->ydab][rob->xdab] = ' ';
  rob->meat = 0;
  if (rob->xdab < rob->mouvdab[rob->y][0])
      rob->xdab++;
  else if (rob->xdab > rob->mouvdab[rob->y][0])
      rob->xdab--;
  else if (rob->ydab < rob->mouvdab[rob->y][1])
      rob->ydab++;
  else if (rob->ydab > rob->mouvdab[rob->y][1])
      rob->ydab--;
  if (rob->xdab == rob->mouvdab[rob->y][0] && 
      rob->ydab == rob->mouvdab[rob->y][1])
    {
      rob->meat = 1;
      rob->nb_meat--;
      rob->y++;
    }
  if (rob->tab[rob->ydab][rob->xdab] == 'o')
    rob->meat == 1;
  rob->tab[rob->ydab][rob->xdab] = 'D';
}

void	cycles(t_rob *rob)
{
  rob->tab[rob->yrob][rob->xrob] = 'R';
  rob->acquired_target = 0;
  while (finished(rob) != 1)
    {
      if (rob->nb_meat != 0)
	mouv_dab(rob);
      else if (rob->xdab != 0 || rob->ydab != 0)
	return_dab(rob);
      mouv_rob(rob);
      show_tab(rob);
      usleep(250000);
    }
}

int	aspirateur(int i, int y)
{
  t_rob	rob;
  int	fd;
  char	*tab;

  init_struc(&rob);
  fd = open("mouv_dab", O_RDONLY);
  tab = get_fd(fd, tab);
  rob.nb_meat = count_line(tab);
  rob.mouvdab = malloc(sizeof(int*) * count_line(tab));
  while (i < count_line(tab))
    rob.mouvdab[i++] = malloc(sizeof(int) * 20);
  i = 0;
  while (tab[i] != '\0')
    {
      if (((rob.mouvdab[y][0] = atoi(&tab[i])) > 20 || atoi(&tab[i]) < 0))
	return (-1);
      while(tab[i++] != ';');
      if (((rob.mouvdab[y][1] = atoi(&tab[i])) > 20 || atoi(&tab[i]) < 0))
	return (-1);
      while (tab[i] != '\n' && tab[i] != '\0')
	i++;
      while (tab[i++ + 1] == '\n');
      y++;
    }
  cycles(&rob);
}
