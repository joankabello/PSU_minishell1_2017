/*
** EPITECH PROJECT, 2018
** kj
** File description:
** j
*/

#include <stdio.h>
#include <my.h>
#include <criterion/criterion.h>

char	*my_strcpy(char *dest, char *src)
{
	int	i;

	i = 0;
	while (src[i] != '\0') {
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}