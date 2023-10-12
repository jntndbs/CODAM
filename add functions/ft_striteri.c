/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdobos <jdobos@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 17:49:43 by jdobos            #+#    #+#             */
/*   Updated: 2023/10/12 12:35:46 by jdobos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

// void	ft_touppermod(unsigned int i, char *c)
// {
// 	if (*c >= 97 && *c <= 122)
// 		*c = *c - 32;
// }

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	size_t	i;

	i = 0;
	while (s[i])
	{
		f(i, &s[i]);
		i++;
	}
	return ;
}

// int	main(void)
// {
// 	char s[] = "Heeee6eellloIo";
// 	ft_striteri(s, ft_touppermod);
// 	printf("%s\n", s);
// 	return (0);
// }