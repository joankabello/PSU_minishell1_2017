/*
** EPITECH PROJECT, 2018
** joan
** File description:
** kabello
*/

#include	<stdlib.h>
#include	<stdio.h>
#include	<unistd.h>
#include	<string.h>
#include	<my.h>

int	count_word(char *str, char delim)
{
	int	count = 0;

	for (int i = 0; str[i]; i++)
		if (str[i] == delim)
			count++;
	return (count + 1);
}

int	count_letters(char const *str, int i, char delim)
{
	int	count = 0;

	while (str[i] != '\0' && str[i] != delim && str[i] != '\t') {
		i++;
		count++;
	}
	return (count);
}

char	**str_to_tab(char *str, char delim)
{
	char	**tab = NULL;
	int	line = 0;
	int	col = 0;
	int	i = 0;
//	int	count_let = count_letters(str, i, delim) + 1;

	epurstr(str);
	tab = malloc(sizeof(*tab) * (count_word(str, delim) + 1));
	tab[line] = malloc(sizeof(**tab) * (count_letters(str, i, delim) + 1));
	for (; str[i] != '\0'; i++) {
		if (str[i] == delim) {
			i++;
			tab[line][col] = '\0';
			col = 0;
			line++;
			tab[line] = malloc(sizeof(**tab) * (count_letters(str, i, delim) + 1));
		}
		tab[line][col] = str[i];
		col++;
	}
	tab[line][col] = '\0';
	tab[line + 1] = NULL;
	return (tab);
}
