/**
 * @author Guillaume Lesniak
 * https://github.com/xplodwild/miage-L3-C
 * Pour information uniquement - réutilisation du code interdite
 */
#include <stdio.h>
#include <stdlib.h>
#include <libgen.h>

int main(int argc, char** argv)
{
	if (argc != 2)
	{
		printf("Usage: %s filename\n", argv[0]);
		exit(-1);
	}
	
	printf("Basename: %s\n", basename(argv[1]));
	
	return EXIT_SUCCESS;
}