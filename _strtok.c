int _strtok()
{
	char *buffer, *buff_cpy, *buff_token;
	size_t bufsize = 32;

	buffer = malloc(bufsize * sizeof(char));
	if (buffer == NULL)
	{
		perror("Error");
		return (-1);
	}
	_getline(&buffer, &bufsize, stdin);;
	
	buff_cpy = malloc(bufsize * sizeof(char));
	if (buff_cpy == NULL)
	{
		perror("Error");
		free(buffer);
		return (-1);
	}
	_strcyp(buff_cpy, buffer);
	buff_token = strtok(buff_cpy, " ");
	while (buff_token != NULL)
	{
		buff_token = strtok(NULL, " ");
	}
	free(buff_cpy);
	free(buffer);
	return (0);
}

