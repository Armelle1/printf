#include <unistd.h>
#include "main.h"

/**
 *write_nbr - write number
 *@n : the number that write
 * Return: The written character
 */
int write_nbr(int n)
{
	char c;

	if (n < 0)
	{
		c = '-';
		n = -n;
		write(1, &c, 1);
		return (1 + write_nbr(n));
	}
	if (n > 9)
	{
		write_nbr(n / 10);
		return (1 + write_nbr(n % 10));
	}
	c = n + '0';
	write(1, &c, 1);
	return (1);
}
/**
 *write_unsign_nbr - write number
 *@n : the number that written
 * Return: The written character
 */
int write_unsign_nbr(unsigned int n)
{
	char c;

	if (n > 9)
	{
		write_nbr(n / 10);
		return (1 + write_nbr(n % 10));
	}
	c = n + '0';
	write(1, &c, 1);
	return (1);
}
