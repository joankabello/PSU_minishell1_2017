/*
** EPITECH PROJECT, 2018
** joan
** File description:
** kabello
*/

#include <unistd.h>
#include <library.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <dirent.h>
#include <sys/stat.h>

int	my_getenv(char *s, char **env)
{
	int	i;
	char	*home;
	int	s_len;

	s_len = my_strlen(s) + 2;
	home = malloc(sizeof(char) * s_len);
	if (home != NULL) {
		my_strcpy(home, s);
		my_strcat(home, "=");
		i = 0;
		while (env[i] != NULL) {
			if (my_strncmp(env[i], home, my_strlen(home)) == 0) {
				free(home);
				return (i);
			}
			i++;
		}
		free(home);
	}
	return (-1);
}

char	*get_home_dir(char **env)
{
	int	i;

	if ((i = my_getenv("HOME", env)) >= 0) {
		return (env[i] + 5);
	}
	return (NULL);
}

int	my_cd_error(char **arg, struct stat buf, char *s)
{
	if (stat(arg[1], &buf) == -1) {
		write(2, arg[1], my_strlen(s));
		write(2, ": No such file or directory.\n", 29);
	}
	else if (!S_ISDIR(buf.st_mode)) {
		write(2, arg[1], my_strlen(s));
		write(2, ": Not a directory.\n", 20);
	}
	return (0);
}

int	my_cd(char *s, char **env)
{
	char	**arg;
	char	const	*home;
	struct	stat	buf;

	arg = str_to_tab(s, ' ');
	if (my_env_count(arg) == 1) {
		home = get_home_dir(env);
		chdir(home);
	}
	else if (my_env_count(arg) > 2) {
		write(2, "cd: Too many arguments.\n", 25);
		return (84);
	}
	if (my_env_count(arg) == 2) {
		my_cd_error(arg, buf, s);
		chdir(arg[1]);
	}
	return (0);
}
