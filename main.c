/*
** main.c for qs in /home/ovsepi_l/rendu/Robby
** 
** Made by Ludovic Ovsepian
** Login   <ovsepi_l@epitech.net>
** 
** Started on  Sat Jun 28 16:41:35 2014 Ludovic Ovsepian
** Last update Mon Jun 30 20:43:25 2014 Ludovic Ovsepian
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "struct.h"

int	telephone()
{
  char	buff[10];
  int	i;
  int	nb_ring;

  nb_ring = 0;
  i = 0;
  printf("Sonne, Allo, Repondeur\n");
  while (42)
    {
      read(0, buff, 10);
      if (strcmp(buff, "Sonne\n") == 0 && printf("attend\n"))
	nb_ring++;
      else if (strcmp(buff, "Allo\n") == 0)
	{
	  printf("Connextion étable\n");
	  return (0);
	}
      else if (strcmp(buff, "Repondeur\n") == 0 && printf("LaiC 1 message\n"))
	return (0);
      if (nb_ring == 5 && printf("Pas de réponse\n"))
	return (0);
      while (i <= 10)
	buff[i++] = 0;
      i = 0;
    }
}

int	show_tab(t_rob *rob)
{
  int	x;
  int	y;

  x = 0;
  y = 0;
  printf(" ");
  while (x++ < 20)
    printf("-");
  x = 0;
  printf("\n");
  while (rob->tab[y][0] != '\0')
    {
      printf("|%s|\n", rob->tab[y]);
      y++;
    }
  printf(" ");
  while (x++ < 20)
    printf("-");
  printf("\n");
  x = 0;
}

void	cuisine()
{
  printf("Je ne fais plus la cuisine depuis la maj 5.7\n");
}

int	main(int ac, char **av)
{
  char	buff[10];
  int	i;

  i = 0;
  while(42)
    {
  printf("Bienvenue, je suis Robby le robot Veuillez choisir linterface"
	 " voulue:\n1-Telephone\n2-Aspirateur\n3-Cuisine\n4-Quitter\n");
      read(0, buff, 10);
      if (buff[0] == '1')
	telephone();
      else if (buff[0] == '2' && (aspirateur(0, 0) == -1))
	printf("Erreur: une boulette est hors de la base\n");
      else if (buff[0] == '3')
	cuisine();
      else if (buff[0] == '4')
	exit(0);
      while (i <= 10)
	while (i <= 10)
	  buff[i++] = 0;
      i = 0;
    }
}
