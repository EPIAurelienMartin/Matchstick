/*
** EPITECH PROJECT, 2018
** nl
** File description:
** ...
*/

#include "my.h"
#define SIZE 1

char    *next(char *str)
{
	char  *tmp = NULL;
	int   i = 0;

	tmp = malloc((my_strlen(str) + 1) * sizeof(char));
	if (!(tmp))
		return (NULL);
	while (str[i] != 0) {
		tmp[i] = str[i];
		i++;
	}
	tmp[i] = '\0';
	free(str);
	return (tmp);
}

char    *get_next_line(const int fd)
{
	static char	buffer[SIZE];
	char  *str = NULL;
	int   i = 0;
	int   j = 0;

	str = malloc(sizeof(char));
	if (!(str))
		return (NULL);
	str[0] = 0;
	while ((j = read(fd, buffer, SIZE)) > 0 && buffer[0] != '\n') {
		str = next(str);
		str[i] = buffer[0];
		i++;
	}
	if (j == 0 && i == 0)
		return (0);
	else
		return (str);
}
