/*
** EPITECH PROJECT, 2018
** joan
** File description:
** kabello
*/

#include <library.h>
#include <signal.h>

void	my_prompt(void)
{
	write(1, "\033[94m{Ɛpitech.}>\033[0m", 22);
}

void	handle_sig(int signal)
{
	(void)signal;
	write(1, "\n", 1);
	my_prompt();
}

int	my_options(char *s, char **env)
{
	if (my_strncmp(s, "env", 3) == 0) {
		my_env_disp(env);
		return (3);
	}
	else if (my_strncmp(s, "cd", 2) == 0) {
		my_cd(s, env);
		return (1);
	}
	if (my_strncmp(s, "setenv", 6) == 0) {
		my_env_disp(env);
		return (2);
	}
	else if (my_strncmp(s, "unsetenv", 8) == 0) {
		my_putstr("Too few arguments.\n");
		return (4);
	}
	return (0);
}

int	main(int ac, char **av, char **env)
{
	char	*s;

	if (ac != 1) {
		exit (84);
	}
	(void)av;
	signal(SIGINT, handle_sig);
	s = my_strdup("HOME");
	while (my_strcmp(s, "exit")) {
		if (isatty(0))
			my_prompt();
		s = get_next_line(0);
		if (s == NULL)
			exit(0);
		else if (my_options(s, env) == 0)
			check_path(env, s);
	}
	return (0);
}
