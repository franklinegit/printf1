#include <stdio.h>
#include <unistd.h>

/**
 * main - Entry point
 * RETURN: 0 (Success)
 */

int main(void)
{
	/* Open file, Handle error, Report success */
	FILE *file = fopen("file.txt", "r+");

	if (file == NULL)
	{
		perror("Error: Couldn't open the file \n");
		return (1);
	}

	printf("The file file.txt opened successfully \n");

	/* Read file content, Handle error, report success */
	char buffer[100];
	size_t bytes_read = fread(buffer, sizeof(char), sizeof(buffer), file);

	if (ferror(file))
	{
		perror("Error occured while reading file");
		fclose(file);
		return (1);
	}

	/* Print existing file content if any */
	if (bytes_read == 0)
	{
		printf("The file is empty \n");
	}
	else
	{
		printf("Here's the existing file contents \n");
		printf("%s \n", buffer);

		/* Truncate existing content */
		if (truncate("file.txt", 0) == -1)
		{
			perror("Error while truncating file \n");
			fclose(file);
			return (1);
		}

		else
		{
			printf("File truncated successfully \n");
		}
	}

	/* Write to file, Handle error, Report success */
	size_t bytes_written;

	while (bytes_read = fread(buffer, 1, sizeof(buffer), stdin) > 0)
	{
		bytes_written = fwrite(buffer, 1, bytes_read, file);

		if (ferror(file))
		{
			perror("Error writing to the file \n");
			fclose(file);
			return (1);
		}
	}

	if (ferror(stdin))
	{
		perror("Error reading from stdin \n");
		fclose(file);
		return (1);
	}

	printf("Successfully wrote %zu elements to file.txt \n", bytes_written);
	fclose(file);
	return (0);
}
