/*
** aspirateur2.c for qsd in /home/ovsepi_l/rendu/Robby
** 
** Made by Ludovic Ovsepian
** Login   <ovsepi_l@epitech.net>
** 
** Started on  Mon Jun 30 13:43:44 2014 Ludovic Ovsepian
** Last update Mon Jun 30 21:32:56 2014 Ludovic Ovsepian
*/

#include "struct.h"
#include "math.h"
#include <stdio.h>

int	finished(t_rob *rob)
{
  int	x;
  int	y;
  int	count;

  x = 0;
  y = 0;
  count = 0;
  while (y < 21)
    {
      while (x < 21)
	{
	  if (rob->tab[y][x] == 'o' || rob->tab[y][x] == 'D' && rob->meat == 1)
	    count++;
	  x++;
	}
      y++;
      x = 0;
    }
  if (count != 0 || rob->xdab != 0 || rob->ydab != 0 || rob->nb_meat != 0)
    return (0);
  return (1);
}

int	return_dab(t_rob *rob)
{
  if (rob->meat == 1)
    rob->tab[rob->ydab][rob->xdab] = 'o';
  else
    rob->tab[rob->ydab][rob->xdab] = ' ';
  rob->meat = 0;
  if (rob->xdab > 0)
    rob->xdab--;
  else if (rob->ydab > 0)
    rob->ydab--;
  if (rob->tab[rob->ydab][rob->xdab] == 'o')
    rob->meat = 1;
  rob->tab[rob->ydab][rob->xdab] = 'D';
}

int	acquire_target(t_rob *rob)
{
  int	x;
  int	y;
  int	lenght;

  x = 0;
  y = 0;
  lenght = 5000;
  while (y < 21)
    {
      while (x < 21)
        {
	  if ((rob->tab[y][x] == 'o' || rob->tab[y][x] == 'D' && rob->meat == 1)
	      && sqrt(pow(x - rob->xrob, 2) + pow(y - rob->yrob, 2)) < lenght)
	    {
	      lenght = sqrt(pow(x - rob->xrob, 2) + pow(y - rob->yrob, 2));
	      rob->ytarget = y;
	      rob->xtarget = x;
	    }
	  x++;
	}
      y++;
      x = 0;
    }
  return (lenght);
}

void	next_rob(t_rob *rob)
{
  rob->tab[rob->yrob][rob->xrob] = ' ';
  if (rob->xrob < rob->xtarget)
    rob->xrob++;
  if (rob->xrob > rob->xtarget)
    rob->xrob--;
  if (rob->yrob < rob->ytarget)
    rob->yrob++;
  if (rob->yrob > rob->ytarget)
    rob->yrob--;
  rob->tab[rob->yrob][rob->xrob] = 'R';
}

int	mouv_rob(t_rob *rob)
{
  if (rob->acquired_target == 0)
    {
      if (acquire_target(rob) == 5000)
	return (0);
      rob->acquired_target = 1;
    }
  if (rob->xrob != rob->xtarget && rob->yrob != rob->ytarget && rob->cooldown == -1)
    rob->cooldown = 2;
  else if (rob->cooldown == -1)
    rob->cooldown = 1;
  if (rob->cooldown == 0)
    {
      next_rob(rob);
      rob->acquired_target = 0;
    }
  rob->cooldown--;
}
