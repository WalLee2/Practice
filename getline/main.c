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
	char *buff;
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
	return (0);
}
