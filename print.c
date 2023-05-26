#include "main.h"
/**
 * _puts - Writes string to std output
 * @str: string to be written
 *
 * Return: On success, the number of chars written.
 * On error, -1 is returned, and errno is set.
 */
int _puts(const char *str)
{
	int len = 0;

	while (str[len] != '\0')
	{
		len++;
	}
	if (write(STDOUT_FILENO, str, len) == -1)
	{
		return (-1);
	}
	if (write(STDOUT_FILENO, "\n", 1) == -1)
	{
		return (-1);
	}
	return (len + 1);
}



/**
 * _snprintf - Custom implementation of snprintf.
 *
 * @str: Dest buffer to store the formatted string.
 * @size: Max no of characters to write (including null-terminator).
 * @format: Format str
 * @...: Additional args.
 *
 * Return: Total number of chars that would have been written if the
 *           buffer was large enough (excluding the null-terminator).
 */
int _snprintf(char *str, size_t size, const char *format, ...)
{
	int result;
	va_list args;

	va_start(args, format);

	result = vsnprintf(str, size, format, args);

	va_end(args);

	return (result);
}


/**
 * _fputs - Writes a string to the specified file descriptor.
 *
 * @str: The string to write.
 * @fd: The file descriptor to write to.
 * Return: On success, the number of characters written is returned.
 *          On failure, -1 is returned.
 */
ssize_t _fputs(const char *str, int fd)
{
	size_t len = 0;
	const char *p = str;

	while (*p != '\0') 
	{
		len++;
		p++;
	}

	return (write(fd, str, len));
}
