#include "main.h"

void print_buffer(char buffer[], int *buff_ind);

/**
 * _printf - Printf function
 * @format: format.
 * Return: Printed chars.
 */
int _printf(const char *format, ...)
{
	/* Variables declaration and Initialization */
	int char_idx, chars_printed = 0, total_chars = 0;
	int spec_flags, spec_width, spec_prec, spec_size, buf_idx = 0;
	va_list args_list;
	char output_buffer[BUFF_SIZE];

	/* Check if format string is NULL*/
	if (format == NULL)
		return (-1);

	va_start(args_list, format);

	/* Loop through the characters in the format string */
	for (char_idx = 0; format && format[char_idx] != '\0'; char_idx++)
	{
		if (format[char_idx] != '%')
		{
			output_buffer[buf_idx++] = format[char_idx];
			if (buf_idx == BUFF_SIZE)
			{
				print_buffer(output_buffer, &buf_idx);
				total_chars += buf_idx;
			}
			else
			{
				total_chars++;
			}
		}
		else
		{
			 /* Handle the '%' character followed by conversion specifier */
			print_buffer(output_buffer, &buf_idx);
			spec_flags = parse_flags(format, &char_idx);
			spec_width = parse_width(format, &char_idx, args_list);
			spec_prec = parse_precision(format, &char_idx, args_list);
			spec_size = parse_size(format, &char_idx);
			char_idx++;
			chars_printed = handle_print(format, &char_idx, args_list, output_buffer,
					 spec_flags, spec_width, spec_prec, spec_size);
			if (chars_printed == -1)
				return (-1);
			total_chars += chars_printed;
		}
	}

	 va_end(args_list);

	/* print the remaining characters */
	print_buffer(output_buffer, &buf_idx);

	return (total_chars);
}

/**
 * print_buffer - Prints the contents of the buffer if it exist
 * @buffer: Array of chars
 * @buff_idx: Index at which to add next char, represents the length.
 */
void print_buffer(char buffer[], int *buff_idx)
{
	if (*buff_idx > 0)
		write(1, &buffer[0], *buff_idx);

	*buff_idx = 0;
}
