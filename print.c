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
 * _snprintf - Formats strs & writes them to a buffer
 *             with a specified maximum size
 * @buffer: buffer where formatted string is written
 * @bufferSize: maximum no of chars to write.
 * @format: format str specifying how output should be formatted.
 * ...     Additional arguments to be formatted.
 * Return: no of chars written (excluding /0 ), or (-) val if error occurred
 */

int _snprintf(char *buffer, size_t bufferSize, const char *format, ...)
{
	va_list args;
	int result;

	va_start(args, format);
	result = vsnprintf(buffer, bufferSize, format, args);
	va_end(args);
	return (result);
}



/**
 * get_digit_count - computes the number of digits in an int.
 * @value: The int value.
 *
 * Return: The no of digits in the integer.
 */
int get_digit_count(int value)
{
	int count = 0;

	while (value != 0)
	{
		count++;
		value /= 10;
	}

	return (count);
}

/**
 * reverse_string - Reverses a given str in-place.
 * @str: str to be reversed.
 * @length: length of the str
 */
void reverse_string(char *str, int length)
{
	int i, j;

	for (i = 0, j = length - 1; i < j; i++, j--)
	{
		char temp = str[i];

		str[i] = str[j];
		str[j] = temp;
	}
}

/**
 * _itoa - converts an int to a str
 * @value: int value to convert.
 *
 * Return: dynamically allocated str representing the int.
 *
 */

char *_itoa(int value)
{
	int sign = (value < 0) ? -1 : 1;
	int length = get_digit_count(value);
	int index = 0;
	char *str = NULL;

	if (value == 0)
	{
		str = malloc(2 * sizeof(char));
		if (str == NULL)
			return (NULL);
		str[0] = '0';
		str[1] = '\0';
		return (str);
	}

	/* Allocate memory for the string */
	str = malloc((length + (sign < 0 ? 2 : 1)) * sizeof(char));
	if (str == NULL)
		return (NULL);

	/* Convert the value to string */
	if (sign < 0)
	{
		str[index++] = '-';
		value = -value;
	}

	while (value != 0)
	{
		int digit = value % 10;

		str[index++] = '0' + digit;
		value /= 10;
	}

	str[index] = '\0';

	reverse_string(str, index);

	return (str);
}

