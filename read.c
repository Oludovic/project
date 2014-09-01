/*
** read.c for ef in /home/ovsepi_l/rendu/rush_my_tar
** 
** Made by Ludovic Ovsepian
** Login   <ovsepi_l@epitech.net>
** 
** Started on  Sat Nov 30 10:31:39 2013 Ludovic Ovsepian
** Last update Fri Dec  6 20:48:11 2013 Ludovic Ovsepian
*/

#include <stdlib.h>

int	my_strlen(char *str)
{
  int	i;

  i = 0;
  while (str[i] != 0)
    i++;
  return (i);
}

char	*my_strcat2(char *tab, char *buff)
{
  char	*t;
  int	i;
  int	j;

  i = 0;
  j = 0;
  if ((t = malloc(sizeof(char) * (my_strlen(tab) + my_strlen(buff)) + 1)) == 0)
    return (NULL);
  while (tab[i] != '\0')
    {
      t[i] = tab[i];
      i = i + 1;
    }
  while (buff[j] != '\0')
    {
      t[i] = buff[j];
      i = i + 1;
      j = j + 1;
    }
  t[i] = '\0';
  return (t);
}

char	*get_fd(int fd, char *tab)
{
  char	buff[4097];
  int	len;

  if ((tab = malloc(sizeof(*tab))) == 0)
    return (NULL);
  while ((len = read(fd, buff, 4096)) > 0)
    {
      if (len != 0)
        {
          buff[len] = 0;
          if ((tab = my_strcat2(tab, buff)) == NULL)
	    return (NULL);
        }
    }
  return (tab);
}
