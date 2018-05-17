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

void	check_sig(int status)
{
	int	signal;

	if (WIFSIGNALED(status)) {
		signal = WTERMSIG(status);
		if (signal == SIGSEGV)
			write(2, "Segmentation fault\n", 19);
		else if (signal == SIGFPE)
			write(2, "Floating exception\n", 19);
	}
}

void	my_exec_error(char **argv, char *s)
{
	if (errno == ENOEXEC) {
		write(2, argv[0], my_strlen(s));
		write(2, ": Exec format error. Wrong Architecture.\n", 41);
	}
}

void	my_access_error(char **argv, char *s)
{
	if (access(argv[0], F_OK) != 0) {
		write(2, argv[0], my_strlen(s));
		write(2, ": Command not found.\n", 21);
	}
}
