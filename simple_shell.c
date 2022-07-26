#include "main.h"
/**
 * simple_shell - holbie-made command line interpreter
 */

int main(int ac, char **av, char **env)
{
	char *buffer = NULL, *token;
	char *args[1024];
	size_t str = 0, len = 0;
	int child, x, status = 0, interactive = 1;
	(void) ac, (void) av;

	while (interactive)
	{
		prompt();
		if (getline(&buffer, &len, stdin) == -1)
			break;
		token = strtok(buffer, " \t\n");
		if (token == NULL)
			break;
		if (strcmp(token, "exit") == 0)
		{
			free(buffer);
			return (str);
		}
		if (!strcmp(token, "env"))
		{
			for (x = 0; env[x] != NULL; x++)
				printf("%s\n", env[x]);
			continue;
		}
		for (str = 0; str < 1024 && token != NULL; str++)
		{
			args[str] = token;
			token = strtok(NULL, " \t\n");
		}
		args[str] = NULL;
		if (!args[0])
		{
			free(args[0]);
			free(buffer);
			return (0);
		}
		child = fork();
		if (child == 0)
		{
			if (execve(args[0], args, env) == -1)
			{
				perror("Error");
				return (0);
			}
		}
		else
			wait(&status);
	}
	free(buffer);
	return (0);
}
/**
 * prompt - verify is in interactive mode for print #cisfun$
 */

int prompt(void)
{
	if (isatty(STDIN_FILENO) == 1)
		write(1, "#cisfun$ ", 9);
	return (0);
}
