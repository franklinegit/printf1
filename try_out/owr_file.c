#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <stdio.h>

/**
 * main - Entry point
 * RETURN: 0 if success
 */
int main(void)
{
	/*Open a file or create it if not present*/
	/*Remember: Syntax for ope function is;*/
	/*open(*path, flags, mode)*/
	int fd = open("message.txt", O_WRONLY | O_CREAT | O_TRUNC, 0666);

	/*Handle error*/
	if (fd == -1)
	{
		perror("Error opening the file");
		return (1);
	}

	/*Create the message to write to the file*/
	const char *message = "This is the first entry into the file \n";

	/*Write the message to the file*/
	/*Syntax for write function;*/
	/*write(file descriptor, pointer to buffer of data to write,*/
	/* number of bytes to write)*/
	ssize_t bytes_written = write(fd, message, strlen(message));

	/*Handle error*/
	if (bytes_written == -1)
	{
		perror("Error: Message couldn't be written to file");
		close(fd);
		return (1);
	}
	printf("Message of %ld bytes succesfully written to the file \n", bytes_written);

	/*Close file*/
	close(fd);

	/*return 0 on succes*/
	return (0);
}
