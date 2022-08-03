#include "main.h"
/**
*
*
*
*
*/

int main(__attribute__((unused)) int ac,  __attribute__((unused)) char **av, char **env)
{
	char *buffer = NULL, *token;
	int status = 0;
	char *args[1024];
	size_t str, len = 0;
	int interactive = 1;
	int child;

	while (interactive)
	{
		interactive = isatty(0); /* checkea modo interactivo */
		/* write(1, " ", 1);  aqui deberia ir cisfun$ */

		if (getline(&buffer, &len, stdin) == -1) /* Esto es el control D */
			break;
		token = strtok(buffer, " \t\n"); /* aca tokenizas hasta un tab o enter*/
		if (!strcmp(token, "exit")) /* Funcion exit,  usas strcmp pa comparar lo que te pasaron */
		{
			free(buffer);
			return(0);	
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
