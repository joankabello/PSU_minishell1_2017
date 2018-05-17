/*
** EPITECH PROJECT, 2017
** joan
** File description:
** kabello
*/

#include <stdlib.h>
#include <my.h>
#include <criterion/criterion.h>

char	*my_strdup(char *str)
{
	char	*dest;

	dest = NULL;
	if ((dest = malloc(sizeof(*str) * my_strlen(str) + 1)) == NULL) {
		return (NULL);
	}
	my_strcpy(dest, str);
	return (dest);
}
