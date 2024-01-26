#include <stdlib.h>
#include <stdio.h>

/**
 * main - Entry point
 *
 * RETURN: RETURNS 0(success)
 */
int main(void)
{
	/* Determine size of memory block */
	size_t num_elem, size;
	int i;

	printf("Enter number of elements to store \n");
	scanf("%zu", &num_elem);

	/* Check validity of number of elements entered */
	if (num_elem <= 0)
	{
		fprintf(stderr, "Error: Number of elements must be positive and non-zero \n");
		return (1);
	}

	/* Allocate memory */
	size = num_elem * sizeof(int);
	int *ptr = (int *)malloc(size);

	if (ptr == NULL)
	{
		fprintf(stderr, "Error allocating memory space \n");
		return (1);
	}

	/* Input elements and store them in memory slots */
	printf("Enter the elements to store in memory \n");
	i = 0;
	while (i < num_elem)
	{
		scanf("%d", ptr + i);
		i++;
	}

	/* Print the elements */
	printf("The elements in memory are: \n");
	for (i = 0; i < (num_elem - 1); i++)
	{
		printf("%d ,", *(ptr + i));
	}
	printf("%d \n", *(ptr + (num_elem - 1)));

	/* Reallocate/Expand memory without losing old data */
	printf("Reallocating/Expanding memory \n");
	size_t new_size;

	printf("The current size of the memory allocated is: %zu bytes", size);
	printf("Enter size of new memory allocation\n");
	int val_check = scanf("%zu",&new_size);

	/* Check if new allocation is valid */
	if (val_check != 1)
	{
		fprintf(stderr, "Memory allocation must be a positive integer\n");
		return (1);
	}

	if (new_size <= size)
	{
		fprintf(stderr, "New memory allocation must be greater than initial allocation\n");
		return (1);
	}
	int *re_ptr = (int *)realloc(ptr, new_size);
	if (re_ptr == NULL)
	{
		fprintf(stderr, "New memory allocation unsuccessful\n");
		return (1);
	}

	size_t newnum_elem, add_elem;

	newnum_elem = new_size/sizeof(int);
	add_elem = newnum_elem - num_elem;
	printf("Now you can add %zu number of integers to the memory\n", add_elem);
	i = num_elem;
	while (i < newnum_elem)
	{		
		scanf("%d",re_ptr + i);
		i++;
	}
	/* Print the elements */
	printf("The elements in expanded memory are: \n");
	for (i = 0; i < (newnum_elem - 1); i++)
	{
		printf("%d ,", *(re_ptr + i));
	}
	printf("%d \n", *(ptr + (newnum_elem - 1)));

	/* Free up allocated reources */
	free(re_ptr);


	return (0);
}
