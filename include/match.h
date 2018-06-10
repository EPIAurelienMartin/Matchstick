/*
** EPITECH PROJECT, 2018
** match
** File description:
** stick
*/

#ifndef MATCH_H
# define MATCH_H_

struct s_match
{
	char	**tab;
	int	line;
	int	stars;
	int	max;
	int	done;
};

void    display_stars(int stars);
char    **my_pyramide(char **tab, int line, int stars);
char    **make_board(int line, int stars);
void    init_struct(struct s_match *ma, char **av);
void	ia_turn(struct s_match *ma);
int	my_game(struct s_match *ma);
int     check_line(char *gnl, int line, struct s_match *ma);
int     check_matches(char *gnl, int match, int line, struct s_match *ma);
void    my_turn_match(struct s_match *ma, char *gnl, int match, int line);
void    my_turn(struct s_match *ma);
void    my_free_tab(char **tab);
int     my_win_condition(char **tab);
int     count_match_line(char *str);
void    modif_tab(struct s_match *ma, int line, int nb);

#endif
