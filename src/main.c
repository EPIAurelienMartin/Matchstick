/*
** EPITECH PROJECT, 2017
** main
** File description:
** main
*/

#include "my.h"
#include "match.h"
#include "get_next_line.h"

void	ia_turn(struct s_match *ma)
{
	int     match = (rand() % ma->max);
	int     line = (rand() % ma->line + 1);

	if (match == 0)
		match += 1;
	while (count_match_line(ma->tab[line - 1]) == 0)
		line = (rand() % ma->line + 1);
	match = match % count_match_line(ma->tab[line - 1]) + 1;
	if (count_match_line(ma->tab[line - 1]) == 2 &&
		my_win_condition(ma->tab) == 2)
		match = 1;
	my_printf("\nAI's turn...\n");
	my_printf("AI removed %d match(es) from line %d\n", match, line);
	modif_tab(ma, line, match);
}

int	my_game(struct s_match *ma)
{
	while (my_win_condition(ma->tab) != 0) {
		my_pyramide(ma->tab, ma->line, ma->stars);
		my_printf("\nYour turn:\n");
		my_turn(ma);
		if (ma->done == 1)
			return (0);
		if (my_win_condition(ma->tab) == 0) {
			my_pyramide(ma->tab, ma->line, ma->stars);
			my_printf("You lost, too bad...\n");
			return (2);
		}
		my_pyramide(ma->tab, ma->line, ma->stars);
		ia_turn(ma);
		if (ma->done == 1)
			return (0);
	}
	my_pyramide(ma->tab, ma->line, ma->stars);
	my_printf("I lost... snif... but I'll get you next time!!\n");
	return (1);
}

int	check_arg(char **av)
{
	if (my_getnb(av[1]) < 1 || my_getnb(av[1]) > 100)
		return (84);
	if (my_getnb(av[2]) < 1)
		return (84);
	return (0);
}

int	main(int ac, char **av)
{
	struct s_match ma;
	int	winner = 0;

	if (ac == 3) {
		if (check_arg(av) == 84)
			return (84);
		init_struct(&ma, av);
		winner = my_game(&ma);
		my_free_tab(ma.tab);
	}
	else
		return (84);
	return (winner);
}
