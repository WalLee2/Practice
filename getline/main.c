#include "line.h"
/**
 *
 *
 *
 *
 */
int main(int ac, char *av[])
{
	FILE *fp;
	char *buff;
	size_t size;
	int status;

	if (ac != 2)
	{
		printf("USAGE: ./program file\n");
		exit(EXIT_FAILURE);
	}
	fp = fopen(av[1], "r");
	if (fp == NULL)
	{
		printf("Can't open file %s!\n", av[1]);
		exit(EXIT_FAILURE);
	}
	buff = NULL;
	size = 0;
	status = grabline(&buff, &size, fp);
	printf("errno: %d\n", errno);
	printf("status: %d\n", status);
	printf("grabline string: %s\n", buff);
	free(buff);

	/*printf("grabline string: %s\n", buff);*/
/*	buff2 = NULL;
	status = getline(&buff2, &size, fp);
	printf("getline status: %d\n", status);
	printf("%s\n", strerror(errno));
	printf("getline string: %s\n", buff2);
	free(buff2);
*/
	fclose(fp);
	return (0);
}
