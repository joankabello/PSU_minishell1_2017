/*
** EPITECH PROJECT, 2018
** jpan
** File description:
** kabello
*/

#include <unistd.h>
#include <stdlib.h>
#include <my.h>
#include <criterion/criterion.h>

void	my_putchar(char c)
{
	write(1, &c, 1);
}
