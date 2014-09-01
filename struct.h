/*
** struct.h for qsd in /home/ovsepi_l/rendu/Robby
** 
** Made by Ludovic Ovsepian
** Login   <ovsepi_l@epitech.net>
** 
** Started on  Sun Jun 29 10:37:01 2014 Ludovic Ovsepian
** Last update Mon Jun 30 19:29:42 2014 Ludovic Ovsepian
*/

#ifndef STRUCT_H_
# define STRUCT_H_

char    *get_fd(int fd, char *tab);

struct	s_rob
{
  char	tab[21][21];
  int	xdab;
  int	ydab;
  int	xrob;
  int	yrob;
  int	cooldown;
  int	meat;
  int	**mouvdab;
  int	y;
  int	nb_meat;
  int	xtarget;
  int	ytarget;
  int	acquired_target;
};

typedef struct s_rob t_rob;

#endif
