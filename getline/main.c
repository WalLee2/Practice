#include "line.h"
/**
 *
 *
 *
 *
 */
int main(int ac, char *av[])
{
	FILE *fd;
	char *buff, *buff2;
	size_t size;
	int status;

	if (ac != 2)
	{
		printf("USAGE: ./program file\n");
		exit(EXIT_FAILURE);
	}
	fd = fopen(av[1], "r");
	if (fd == NULL)
	{
		printf("Can't open file %s!\n", av[1]);
		exit(EXIT_FAILURE);
	}
	buff = NULL;
	size = 0;
	status = grabline(&buff, &size, fd);
	printf("errno: %d\n", errno);
	printf("status: %d\n", status);
	free(buff);
	buff2 = NULL;
	status = getline(&buff2, &size, fd);
	printf("getline status: %d\n", status);
	printf("%s\n", strerror(errno));
	printf("getline string: %s\n", buff2);
	free(buff2);
	fclose(fd);
	return (0);
}
