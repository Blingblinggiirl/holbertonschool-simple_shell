#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
/**
 * main - executes ls -l command in 5 different child processes
 * Return: 0
 */
int main(void)
{
	int status;
	char *argv[] = {"/bin/ls", "-l", "/tmp", NULL};
	int i;

	for (i = 0; i < 5; i++)
	{
		if (fork() == 0)
		{
			if (execve(argv[0], argv, NULL) == -1)
				perror("Error:");
		}
		wait(&status);
	}
	return (0);
}
