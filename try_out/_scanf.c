#include <stdio.h>

/**
 * main - Entry point
 *
 * RETURN: 0(Success)
 */
int main(void)
{
	/* Test return value of scanf*/
	int num, result;

	printf("Enter an integer\n");
	result = scanf("%d", &num);
	printf("Scanf return value for an integer: %d\n", result);

	char str[10];

	printf("Enter a string\n");
	result = scanf("%9s", str);
	printf("Scanf return value for a string: %d\n", result);


	return (0);
}
