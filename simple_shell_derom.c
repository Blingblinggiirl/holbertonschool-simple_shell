#include "main.h"
#include <strings.h>

/**
 * main - check the code
 *
 *
 */
int main(void)
{
	char *buffer = NULL; /** first argument of getline */
	int savegetline, status; /* status: for wait */
	char **buffer_token[]; /** para guardar la tokeniz en la variable (strtok)*/
	size_t bufsize = 0; /** arguments de getline */
	pid_t pid;

	while (1)
	{
		write(1, "#cisfun$ ", 9);

		savegetline = getline(&buffer, &bufsize, stdin);

		if (savegetline == -1)
			break;

		buffer = strtok(buffer, " \t\n");
		buffer_token = calloc(strlen(buffer), sizeof(char *)); //guarda los tokens
		buffer_token[1] = NULL;

		if (buffer_token[0] == "env")
			getenv("PATH");
		pid = fork();
		if (pid == -1)
			perror("Error");
		else if (pid == 0)
		{
			if (execve(buffer_token[0], buffer_token, NULL) == -1)
			{
				perror("Error");
				return(0);
			}
		}
		else
			wait(&status);
	}
	return (0);
}
