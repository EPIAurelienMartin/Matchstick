/*
** EPITECH PROJECT, 2018
** init
** File description:
** ...
*/

#include "my.h"
#include "match.h"

void    display_stars(int stars)
{
	while (stars > 0) {
		my_putchar('*');
		stars--;
	}
	my_putchar('\n');
}

char    **my_pyramide(char **tab, int line, int stars)
{
	int   i = 0;
	int   j = 0;
	int   x = 0;

	display_stars(stars);
	while (i < line) {
		j = 0;
		my_putchar('*');
		while (j < stars - 2) {
			my_putchar(tab[x][j]);
			j++;
		}
		x++;
		my_putstr("*\n");
		i++;
	}
	display_stars(stars);
	return (tab);
}

char	**put_match(char **tab, int line)
{
	int	y = 0;
	int	x = 0;

	while (y <= line) {
		x = 0;
		while (x <= y) {
			tab[y][line - x] = '|';
			tab[y][line + x] = '|';
			x++;
		}
		y++;
	}
	return (tab);
}

char    **make_board(int line, int stars)
{

	char	**tab = NULL;
	int	x = 0;
	int	y = 0;

	tab = malloc(sizeof(char *) * (line + 1));
	while (y < line) {
		x = 0;
		tab[y] = malloc(sizeof(char) * stars + 1);
		while (x < stars) {
			tab[y][x] = ' ';
			x++;
		}
		tab[y][stars] = '\0';
		y++;
	}
	tab[line] = NULL;
	tab = put_match(tab, line - 1);
	return (tab);
}

void    init_struct(struct s_match *ma, char **av)
{
	ma->line = my_getnb(av[1]);
	ma->max = my_getnb(av[2]);
	ma->stars = ma->line * 2 + 1;
	ma->tab = make_board(ma->line, ma->stars - 2);
	ma->done = 0;
}
