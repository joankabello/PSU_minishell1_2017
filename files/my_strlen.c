/*
** EPITECH PROJECT, 2018
** joan
** File description:
** kabello
*/

#include <criterion/criterion.h>

int	my_strlen(char const *str)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i] != '\0') {
		i++;
		count++;
	}
	return (count);
}
