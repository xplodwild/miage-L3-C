/**
 * @author Guillaume Lesniak
 * https://github.com/xplodwild/miage-L3-C
 * Pour information uniquement - réutilisation du code interdite
 */

#include <stdio.h>
#include <stdlib.h>

// Macro pour vider le buffer de scanf
#define CLRBUF { scanf("%*[^\n]"); getchar(); }

// Renvoie le max parmi num1/num2/num3
int max(int num1, int num2, int num3);

int main(int argc, char* argv[])
{
	int num[3];
	int i = 0, ret = 0;
	
	// Lis les 3 nombres
	for (; i < 3; i++) {
		ret = 0;
		
		while (ret != 1) {
			printf("Nombre %d: ", i+1);
			ret = scanf("%d", &num[i]);
			CLRBUF;
		}
	}
	
	// Calcule le max
	printf("Max: %d\n", max(num[0], num[1], num[2]));
	
	return 0;
}

int max(int num1, int num2, int num3)
{
	int result = num1; 

	if(result < num2) 
		result = num2;

	if(result < num3) 
		result = num3; 

	return result;
}