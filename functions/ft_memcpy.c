/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdobos <jdobos@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 18:04:10 by jdobos            #+#    #+#             */
/*   Updated: 2023/10/06 19:53:46 by jdobos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

void	*ft_memcpy(void *restrict dest, const void *src, size_t n)
{
	unsigned char	*d;
	unsigned char	*s;
	
	d = (unsigned char*)dest;
	s = (unsigned char*)src;
	while (n > 0)
	{
		*d = *s;
		d++;
		s++;
		n--;
	}
	return (dest);
}

int	main(void)
{
	char s1[5];
	char s2[] = "Hello";
	int i1[2];
	int i2[] = {1,2};
	memcpy(s1, s2, 3);
	memcpy(i1, i2, 0);
	printf("sys: %d\n", i1[1]);
	printf("sys: %s\n", s1);

	char s3[5];
	char s4[] = "Hello";
	int i3[2];
	int i4[] = {1,2};
	ft_memcpy(s3, s4, 3);
	ft_memcpy(i3, i4, 0);
	printf("mine: %d\n", i3[1]);
	printf("mine: %s\n", s3);
	return 0;
}

/* 
!!!!!!!!!!!!!!!!!
This main gives: 

f0r2s7% ./a.out       
sys: 0
sys: Hel@
mine: 2
mine: Hel

!!!!!!!!!!!!!!!!!
*/