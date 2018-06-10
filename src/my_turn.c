/*
** EPITECH PROJECT, 2018
** my_turn
** File description:
** ...
*/

#include "my.h"
#include "match.h"
#include "get_next_line.h"

int     check_line(char *gnl, int line, struct s_match *ma)
{
	if (line <= 0 || line > ma->line) {
		my_printf("Error: this line is out of range\n");
		return (-1);
	}
	if (my_str_isnum(gnl) == 0) {
		my_printf("Error: invalid input (positive number expected)\n");
		return (-1);
	}
	return (0);
}

int     check_matches(char *gnl, int match, int line, struct s_match *ma)
{
	if (my_str_isnum(gnl) == 0) {
		my_printf("Error: invalid input (positive number expected)\n");
		return (-1);
	}
	if (match > ma->max) {
		my_printf("Error: you cannot remove more than ");
		my_printf("%d matches per turn\n", ma->max);
		return (-1);
	}
	if (match == 0) {
		my_printf("Error: you have to remove at least one match\n");
		return (-1);
	}
	if (match > count_match_line(ma->tab[line - 1])) {
		my_printf("Error: not enough matches on this line\n");
		return (-1);
	}
	return (0);
}

void    my_turn_match(struct s_match *ma, char *gnl, int match, int line)
{
	my_printf("Matches: ");
	gnl = get_next_line(0);
	if (gnl == NULL) {
		ma->done = 1;
		return;
	}
	match = my_getnb(gnl);
	if (check_matches(gnl, match, line, ma) == -1)
		my_turn(ma);
	else {
		modif_tab(ma, line, match);
		my_printf("Player removed %d match(es) ", match);
		my_printf("from line %d\n", line);
	}
}

void    my_turn(struct s_match *ma)
{
	int     match = 0;
	int     line = 0;
	char    *gnl;

	my_printf("Line: ");
	gnl = get_next_line(0);
	if (gnl == NULL) {
		ma->done = 1;
		return;
	}
	line = my_getnb(gnl);
	if (check_line(gnl, line, ma) == -1)
		my_turn(ma);
	else
		my_turn_match(ma, gnl, match, line);
}
