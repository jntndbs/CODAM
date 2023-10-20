/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdobos <jdobos@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 18:04:30 by jdobos            #+#    #+#             */
/*   Updated: 2023/10/16 16:27:48 by jdobos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	*a;
	unsigned char	*b;

	i = 0;
	a = (unsigned char *)s1;
	b = (unsigned char *)s2;
	if (n == 0)
		return (0);
	while (a[i] == b[i] && a[i] && b[i] && i <= n)
	{
		i++;
		n--;
	}
	return (a[i] - b[i]);
}

// int	main(void)
// {
// 	char s1[] = "1234";
// 	char s2[] = "\200";
// 	printf("mine: %d\n", ft_strncmp(s1, s2, 3));
// 	printf("sys: %d\n", strncmp(s1, s2, 3));
// 	return 0;
// }