#include "main.h"

/**
 * get_precision - calculates the precision
 * @format: formatted string to print the
 * arguments
 * @i: list of arguments to be printed
 * @list: list of arguments
 *
 * Return: precision
 */
int get_precision(const char *format, int *i, va_list list)
{
	int curr_i = *i + 1;
	int precicion = -1;

	if (format[curr_i] != '.')
		return (precicion);
	precicion = 0;
	for (curr_i += 1; format[curr_i] != '\0'; curr_i++)
	{
		if (is_digit(format[curr_i]))
		{
			precicion *= 10;
			precicion += format[curr_i] - '0';
		}
		else if (format[curr_i] == '*')
		{
			curr_i++;
			precicion = va_arg(list, int);
			break;
		}
		else
			break;
	}
	*i = curr_i - 1;
	return (precicion);
}
