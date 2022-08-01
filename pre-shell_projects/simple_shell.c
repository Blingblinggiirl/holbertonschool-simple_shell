#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
	size_t buffer_size = 32;
	char *buffer;
	int status;
	char **argv;
	pid_t pid;
	
	buffer = malloc(sizeof(char) * buffer_size);
	while (1)
	{
		printf("#cisfun$");
		getline(buffer, buffer_size, stdin);
		argv = malloc(sizeof(char) * 2);
		argv[0] = malloc(sizeof(char) * strlen(buffer));
		argv[0] = strtok(buffer, "\n");
		argv[0] = NULL;
		pid = fork();

		if(pid == 0)
		{
			if(execve(argv[0], argv, NULL) == 1)
				perror("Error");
			wait(&status);
		}
		return(0);
	}
}
