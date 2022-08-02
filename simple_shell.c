#include "main.h"
/**
 *
 *
 *
 */
int main(void)
{
	char *buffer = NULL; /** first argument of getline */
	int savegetline, status; /* status: for wait */
	char **buffer_token; /** para guardar la tokeniz en la variable (strtok)*/
	size_t bufsize = 0; /** arguments de getline */
	pid_t pid;

	while (1)
	{
		write(1, "#cisfun$", 8);

		savegetline = getline(&buffer, &bufsize, stdin);

		if (savegetline == -1)
			break;

		buffer_token = _strtok(buffer, " \t\n");

		if (buffer_token[0] == "env")
			*_getenv();
		pid = fork();
		if (pid == -1)
			perror("Error");
		else if (pid == 0)
			execve(buffer_token[0], buffer_token, NULL);
		else
			wait(&status);
			free(buffer_token);
	}
	return (0);
}
