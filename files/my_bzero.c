/*
** EPITECH PROJECT, 2018
** joan
** File description:
** dada
*/

#include	<library.h>

void	my_bzero(char *str, int size)
{
	int	i;

	i = 0;
	while (i < size) {
		str[i] = '\0';
		i++;
	}
}
