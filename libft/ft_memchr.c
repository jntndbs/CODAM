/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memchr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jdobos <jdobos@student.42.fr>                +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/03 18:04:05 by jdobos        #+#    #+#                 */
/*   Updated: 2023/10/13 11:33:11 by joni          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"

void	*ft_memchr(const void *str, int c, size_t n)
{
	if (c > 255)
		c -= 256;
	while (n > 0 && str)
	{
		if (*(unsigned char *)str == c)
			return ((void *)str);
		str++;
		n--;
	}
	return (NULL);
}

// int	main(void)
// {
// 	char	str[] = "yo i am john";
// 	char	c = 'i';
// 	int	n = 30;
// 	char	*out = ft_memchr(str, c, n);
// 	if (out != NULL)
// 		printf("out: %d\n", *out);
// 	else	printf("NULL\n");
// 	return (0);
// }