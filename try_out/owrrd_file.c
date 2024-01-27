#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <errno.h>

/**
 * main - entry point
 * RETURN: 0 on success
 */
int main(void)
{
	/* Open file, and handle error if any */
	int fd1 = open("message.txt", O_RDWR | O_APPEND, 0666);

	if (fd1 == -1)
	{
		/* Handle No File Error */
		if (errno == ENOENT)
		{
			printf("File Not found");
			return (1);
		}

		/* Handle Permission Error*/
		else if (errno == EACCES)
		{
			printf("Permission denied");
			return (1);
		}

		/* Handle any other error*/
		else
		{
			printf("An error occured");
			return (1);
		}
	}

	/* Create message to write and write it */
	const char *message1 = "This is the second entry into the file \n";
	ssize_t bytes_written1 = write(fd1, message1, strlen(message1));

	/* Handle error when writing */
	if (bytes_written1 == -1)
	{
		perror("Error encountered when writing to file");
		close(fd1);
		return (1);
	}

	printf("%ld bytes successfully writen to the file \n", bytes_written1);
	close(fd1);
	return (0);
}
