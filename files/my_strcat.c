/*
** EPITECH PROJECT, 2018
** joan
** File description:
** kabello
*/

#include <my.h>
#include <criterion/criterion.h>

char	*my_strcat(char *dest, char *src)
{
	int	i;
	int	destlen;

	destlen = my_strlen(dest);
	i = 0;
	while (src[i] != '\0') {
		dest[destlen + i] = src[i];
		i++;
	}
	dest[destlen + i] = '\0';
	return (dest);
}
