/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   libft_split.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: jdobos <jdobos@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/05/22 14:15:39 by jdobos        #+#    #+#                 */
/*   Updated: 2024/06/13 18:29:26 by jdobos        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

static size_t	count(char const *s, char c)
{
	int		t;
	size_t	words;

	t = 0;
	words = 0;
	while (*s)
	{
		if (*s != c && t == 0)
		{
			words++;
			t = 1;
		}
		else if (*s == c)
			t = 0;
		s++;
	}
	return (words);
}

static void	*free_er(char **arr, size_t word)
{
	while (word--)
		free(arr[word]);
	free(arr);
	arr = NULL;
	return (NULL);
}

static char	*wordalloc(char const *s, char const c)
{
	size_t	i;
	char	*word;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	word = (char *)malloc((i + 1) * sizeof(char));
	if (!word)
		return (NULL);
	i = 0;
	while (s[i] && s[i] != c)
	{
		word[i] = s[i];
		i++;
	}
	word[i] = '\0';
	return (word);
}

char	**ft_split(const char *s, const char c)
{
	char	**arr;
	size_t	word;
	size_t	i;

	arr = (char **)malloc((count(s, c) + 1) * sizeof(char *));
	if (!arr)
		return (NULL);
	word = 0;
	i = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i])
		{
			arr[word] = wordalloc((char *)(s + i), c);
			if (!arr[word])
				return (free_er(arr, word));
			i += ft_strlen(arr[word]);
			word++;
		}
	}
	arr[word] = NULL;
	return (arr);
}
