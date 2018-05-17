/*
** EPITECH PROJECT, 2018
** joan
** File description:
** joan
*/

#include <stdio.h>
#include <library.h>
#include <sys/wait.h>
#include <signal.h>
#include <errno.h>

void	my_exec(char **env, char *s, char **argv)
{
	if (execve(argv[0], argv, env) == -1) {
		my_exec_error(argv, s);
	}
}

void	init_exec(char **env, char *s, char **argv)
{
	int	status;
	pid_t	pid;

	status = 0;
	if (argv[0] != NULL) {
		pid = fork();
		if (pid == 0) {
			my_exec(env, s, argv);
			exit (1);
		}
		waitpid(pid, &status, 0);
		check_sig(status);
	}
}
