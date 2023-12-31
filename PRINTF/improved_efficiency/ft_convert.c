/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdobos <jdobos@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 15:58:59 by jdobos            #+#    #+#             */
/*   Updated: 2023/11/27 14:31:23 by jdobos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*itoa_base(long long value, int base, const char *rep, char *print)
{
	char		buf[65];
	char		*ptr;
	long long	num;

	ptr = &buf[64];
	*ptr = '\0';
	num = value;
	if (value < 0 && base == 10)
		value *= -1;
	if (value == 0)
		*(--ptr) = rep[value % base];
	while (value != 0)
	{
		*(--ptr) = rep[value % base];
		value /= base;
	}
	if (num < 0 && base == 10)
		*(--ptr) = '-';
	return (add_print(print, ptr));
}

static char	*ptoa(unsigned long value, int base, const char *rep, char *print)
{
	char		buf[65];
	char		*ptr;
	long long	num;

	ptr = &buf[64];
	*ptr = '\0';
	num = value;
	if (value < 0 && base == 10)
		value *= -1;
	if (value == 0)
		*(--ptr) = rep[value % base];
	while (value != 0)
	{
		*(--ptr) = rep[value % base];
		value /= base;
	}
	if (num < 0 && base == 10)
		*(--ptr) = '-';
	return (add_print(print, ptr));
}

char	*mod_itoa(long long value, int base, char *print, int hex_type)
{
	const char	rep[] = "0123456789abcdef";
	const char	rep_up[] = "0123456789ABCDEF";

	if (hex_type == 2)
		return (ptoa(value, base, rep, print));
	else if (hex_type == 1)
		return (itoa_base(value, base, rep_up, print));
	else
		return (itoa_base(value, base, rep, print));
}

char	*ptr_str(void *arg, char *print)
{
	unsigned long	value;

	if (!arg)
		return (add_print(print, "(nil)"));
	print = add_print(print, "0x");
	value = (unsigned long)arg;
	return (mod_itoa(value, 16, print, 2));
}
