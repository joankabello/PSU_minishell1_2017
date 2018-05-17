/*
** EPITECH PROJECT, 2018
** joan
** File description:
** kabello
*/

int	my_strncmp(char *s1, char *s2, int nb)
{
	int	a;

	a = 0;
	while (s1[a] == s2[a] && s1[a] && s2[a] && a < nb) {
		a++;
	}
	if ((s1[a] == '\0' && s2[a] == '\0') || a == nb) {
		return (0);
	}
	else if (s1[a] > s2[a]) {
		return (1);
	}
	else {
		return (-1);
	}
}
