##
## Makefile for qsd in /home/ovsepi_l/rendu/Robby
## 
## Made by Ludovic Ovsepian
## Login   <ovsepi_l@epitech.net>
## 
## Started on  Sat Jun 28 16:50:08 2014 Ludovic Ovsepian
## Last update Mon Jun 30 18:46:08 2014 Ludovic Ovsepian
##

SRCS	=	main.c \
		aspirateur.c \
		read.c \
		aspirateur2.c \

OBJS	= $(SRCS:.c=.o)

NAME	= Robby

all: $(NAME)

$(NAME): $(OBJS)
	cc $(OBJS) -o $(NAME) -lm

clean:
	rm -rf $(OBJS)

fclean: clean
	rm $(NAME)

re: fclean all
