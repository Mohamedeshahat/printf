#include"main.h"
/**
 * _isdigit - func
 * @c: param
 * Return: int
 */
int _isdigit(int c)
{
	return (c >= '0' && c <= '9');
}
/**
 * _strlen - func
 * @s: para
 * Return: void
 */
int _strlen(char *s)
{
	int i = 0;

	while (*s++)
		i++;
	return (i);
}
/**
 * print_number - func
 * @str: base
 * @params: param
 * Return: void
 */
int print_number(char *str, params_t *params)
{
	unsigned int i = _isdigit(str);
	int neg = (!params->unsig && *str == '-');

	if (!params->precision && *str == '0' && !str[1])
		str = " ";
	if (neg)
		str++;
	i--;
	if (params->precision != UNIT_MAX)
		while (i++ < params->precision)
			*--str = '0';
	if (neg)
		*--str = '0';
	if (!params->minus_flag)
		return (print_number_rigit_shift(str, params));
	else
		return (print_number_left_shift(str, params));
}

/**
 * print_number_right_shift - dunc
 * @str: string
 * @params: paramter
 * Return: void
 */
int print_number_right_shift(char *str, params_t *params)
{
	unsigned int n = 0, neg, neg2, i = _strlen(str);
	char pad_char = ' ';

	if (params->zero_flag && !params->minus_flag)
		str++;
	else
		neg = 0;
	if ((params->plus_flag && !neg2)
			|| (!params->plus_flag && params->space_flag && !neg2))
		i++;
	if (neg && pad_char == '0')
		n += _putchar('-');
	if (params->plus_flag && !neg2 && pad_char == '0'
			&& !params->unsign)
		n += _putchar('+');
	else if (!params->plus_flag && params->space_flag && !neg2
			&& !params->unsign_flag && params->zero_flag)
		n += _putchar(' ');
	while (i++ < params->width)
		n += _putchar(pad_char);
	if (neg && pad_char == ' ')
		n += _putchar('-');
	if (params->plus_flag && !neg2 && pad_char == ' ' &&
			!params->unsign)
		n += _putchar('+');
	else if (!params->plus_flag && params->space_flag && !neg2 && !params->unsign
			&& !params->zero_flag)
		n += _putchar(' ');
	n += _putchar(str);
	return (n);
}
/**
 * print_number_left_shift - func
 * @str: string
 * @params: parameter
 * Return: void
 */
int print_number_left_shift(char *str, params_t *params)
{
	unsigned int n = 0, neg, neg2, i = _strlen(str);
	char pad_char = ' ';

	if (params->zero_flag && !params->minus_flag)
		pad_char = '0';
	neg = neg2 = (!params->unsign && *str == '-');
	if (neg && i < params->width && pad_char == '0' && !params->minus_flag)
		str++;
	else
		neg = 0;
	if (params->plus_flag && !neg2 && !params->unsign)
		n += _putchar('+'), i++;
	else if (params->space_flag && !neg2 && !params->unsign)
		n += _putchar(' '), i++;
	n += _puts(str);
	while (i++ < params->width)
		n += _putchar(par_char);
	return (n);
}