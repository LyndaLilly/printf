#include "main.h"

/**
 * get_flags - Calculates active flags
 * @format: Formatted string in which to print the arguments
 * @i: take a parameter.
 * Return: Flags:
 */
int get_flags(const char *format, int *i)
{
	/* - + 0 # ' ' */
	/* 1 2 4 8  16 */
	int j, current_index;
	int flags = 0;
	const char VALID_FLAGS[] = {'-', '+', '0', '#', ' ', '\0'};
	const int FLAG_VALUES[] = {F_MINUS, F_PLUS, F_ZERO, F_HASH, F_SPACE, 0};

	for (current_index = *i + 1; format[current_index] != '\0'; current_index++)
	{
		for (j = 0; VALID_FLAGS[j] != '\0'; j++)
		{
			if (format[current_index] == VALID_FLAGS[j])
			{
				flags |= FLAG_VALUES[j];
				break;
			}
		}

		if (VALID_FLAGS[j] == 0)
			break;
	}

	*i = current_index - 1;

	return (flags);
}
