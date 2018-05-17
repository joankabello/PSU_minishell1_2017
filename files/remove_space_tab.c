/*
** EPITECH PROJECT, 2018
** joan
** File description:
** joan
*/

#include	<stdlib.h>
#include	<stdio.h>
#include	<unistd.h>
#include	<string.h>
#include	<my.h>

void	remove_tab(char *str)
{
	int	i = 0;

	while (str[i] != '\0') {
		if (str[i] == '\t')
			str[i] = ' ';
		i++;
	}
}

void	remove_spaces(char *str)
{
	int	i = 0;

	while (str[i] != '\0')
		i++;
	i--;
	while (i > 0 && str[i] == ' ') {
		str[i] = '\0';
		i--;
	}
}

char	*check_words(char *str, int nb_words, int ps)
{
	for (; str[ps + nb_words] != '\0'; ps++) {
		str[ps] = str[ps + nb_words];
	}
	str[ps] = '\0';
	return (str);
}

char	*epurstr(char *str)
{
	int	i;

	remove_tab(str);
	remove_spaces(str);
	for (i = 0; str[i] == ' ';)
		i++;
	check_words(str, i, 0);
	for (i = 0; str[i] != '\0';) {
		if (str[i] == ' ' ) {
			i++;
			for (; str[i] == ' ';)
				check_words(str, 1, i);
		}
		i++;
	}
	i -= 1;
	return (str);
}
