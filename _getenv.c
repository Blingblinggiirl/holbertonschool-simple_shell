#include "main.h"
/**
 *
 *
 *
 */
extern char **environ
char _printenv(void)
{
	int i;

	for(i = 0; environ[i]; i++)
	{
		write(1, environ[i], 10);
	}
	return (0);
}
