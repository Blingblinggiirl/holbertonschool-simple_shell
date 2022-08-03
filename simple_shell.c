#include "main.h"


int main(__attribute__((unused)) int ac,  __attribute__((unused)) char **av, char **env)
{
	char *buffer = NULL, *token;
	int status = 0;
	char *args[1024];
	size_t str, len = 0;
	int interactive = 1;
	int child;
	int x;
	

	while (interactive)
	{

		if (getline(&buffer, &len, stdin) == -1)
			break;
		token = strtok(buffer, " \t\n"); /* aca tokenizas hasta un tab o enter*/
		if (token == NULL)
			break;
		if (!strcmp(token, "exit")) /* usas strcmp pa comparar lo que te pasaron, creando asi el exit */
		{
			if (token)
				free(token);
			free(buffer);
			return (str);
		}
		if (!strcmp(token, "env")) /* esta es la parte para la task 6 sobre env,comparo si token es env */
		{
			for (x = 0; env[x] != NULL; x++) 
				printf("%s\n", env[x]);
			continue;
		}
		for (str = 0; str < 1024 && token != NULL; str++) /* aqui seria la parte de los argumentos, recorres los args siempre y cuando sea distinto de nulo */
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
