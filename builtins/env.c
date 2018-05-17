/*
** EPITECH PROJECT, 2018
** joan
** File description:
** kabello
*/

#include <library.h>

int	my_env_count(char **env)
{
	int	i;

	i = 0;
	while (env[i] != NULL) {
		i++;
	}
	return (i);
}

char	**my_env(char **env)
{
	char	**my_env;
	int	i;

	my_env = malloc(sizeof(*my_env) * (my_env_count(env) + 1));
	for (i = 0; env[i]; i++) {
		my_env[i] = my_strdup(env[i]);
	}
	my_env[i] = NULL;
	return (my_env);
}

int	my_env_disp(char **env)
{
	int	i;
	char	**copy;

	i = 0;
	copy = my_env(env);
	while (env[i] != NULL) {
		my_putstr(copy[i]);
		my_putchar('\n');
		i++;
	}
	return (0);
}
