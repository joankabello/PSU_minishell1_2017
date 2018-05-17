/*
** EPITECH PROJECT, 2018
** joan
** File description:
** kabello
*/

#include <stdio.h>
#include <library.h>
#include <sys/wait.h>
#include <signal.h>
#include <errno.h>

char	*link_lines(char *line1, char *line2)
{
	char	*new_line = NULL;
	int	len = my_strlen(line1) + my_strlen(line2);
	int	i = 0;
	int	j = 0;

	new_line = malloc(sizeof(*new_line) * (len + 1));
	if (new_line == NULL)
		return (NULL);
	my_bzero(new_line , len);
	for (i = 0 ; line1[i] ; i++)
		new_line[i] = line1[i];
	for (j = 0 ; line2[j] ; j++)
		new_line[i + j] = line2[j];
	new_line[i + j] = '\0';
	return (new_line);
}

char	*store_path(char **env)
{
	int	i;

	if ((i = my_getenv("PATH", env)) >= 0) {
		return (&env[i][5]);
	}
	return (NULL);
}

char	*open_path(char **env, char *cmd)
{
	char	*path = NULL;
	char	**get_path = NULL;
	char	*path_in = NULL;
	char	*add = NULL;
	int	i = 0;

	path = store_path(env);
	get_path = str_to_tab(path, ':');
	for (i = 0 ; get_path[i] ; i++) {
		add = link_lines(get_path[i], my_strdup("/"));
		path_in = link_lines(add, cmd);
		if (access(path_in, X_OK) == 0 && access(path_in, F_OK) == 0) {
			return (path_in);
		}
		free(add);
		free(path_in);
	}
	return (NULL);
}

char	*check_path(char **env, char *s)
{
	char	**argv = str_to_tab(s, ' ');

	if (access(argv[0], X_OK) != 0 && access(argv[0], F_OK) != 0)
		argv[0] = open_path(env, argv[0]);
	if (argv[0] == NULL && my_strcmp(s, "exit") != 0) {
		write(2, s, my_strlen(s));
		write(2, ": Command not found.\n", 21);
	}
	else {
		init_exec(env, s, argv);
	}
	return (NULL);
}
