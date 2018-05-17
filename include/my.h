/*
** EPITECH PROJECT, 2018
** joan
** File description:
** kabello
*/

#ifndef	_MY_H_
#define	_MY_H_
#include	<library.h>

char	**copy(char **env, char *add);
char	**my_unsetenv(char **env, char *key_rm);
void	connect(char *new, char *key, char *value);
void	do_something(char **env, char *key, char *new, int i);
char	**my_setenv(char *key, char *value, char **env);
void	my_exec(char **env, char *s, char **argv);
void	init_exec(char **env, char *s, char **argv);
void	remove_tab(char *str);
void	remove_spaces(char *str);
char	*check_words(char *str, int nb_words, int ps);
char	*epurstr(char *str);
void	my_exec_error(char **argv, char *s);
void	check_sig(int status);
char	**my_env(char **env);
void	my_bzero(char *str, int size);
int	my_strncmp(char *s1, char *s2, int nb);
char	*concat_lines(char *line1, char *line2);
char	*store_oldpwd(char **env);
int	count_words(char *str);
char	*open_oldpwd(char **env, char *cmd);
int	command_setenv(char **argv, char **env);
char	*check_oldpwd(char **env, char *s);
int	my_getenv(char *name, char **env);
char	*get_home_dir(char **env);
int	my_cd(char *s, char **env);
char	*my_cat(char *l1, char *l2);
char	*concatenate_lines(char *line1, char *line2);
char	*save_path(char **env);
char	*try_path(char **env, char *s);
char	*check_path(char **env, char *s);
void	my_access_error(char **argv, char *s);
char	*my_strdup(char *str);
char	*my_strcpy(char *dest, char *src);
int	my_strcmp(char *s1, char *s2);
void	my_putchar(char c);
int	is_command(char *str);
int	my_putstr(char *str);
char	*my_strcat(char *dest, char *src);
int	strcount(char *str, char delim);
int	my_strlen(char const *str);
char	*count_let(char *str, int *n, char delim);
char	**str_to_tab(char *str, char delim);
void	display(char **tab);
int	my_env_count(char **env);
char	**get_env(char **env);
int	my_env_disp(char **env);
int	my_strncmp(char *str1, char *str2, int n);

#endif
