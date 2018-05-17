/*
** EPITECH PROJECT, 2018
** joan
** File description:
** kabello
*/

#include <unistd.h>
#include <my.h>
#include <stdlib.h>
#include <criterion/criterion.h>

int	my_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0') {
		my_putchar(str[i]);
		i++;
	}
	return (0);
}
