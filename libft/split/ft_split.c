/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agraille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 10:37:07 by agraille          #+#    #+#             */
/*   Updated: 2024/12/18 07:45:48 by agraille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

static	char	**ft_free_split(char **split)
{
	int	i;

	i = 0;
	while (split[i] != 0)
	{
		free(split[i]);
		split[i] = NULL;
		i++;
	}
	free(split);
	return (NULL);
}

static int	ft_count_word(const char *s, char c)
{
	int	count_word;
	int	seek;
	int	i;

	count_word = 0;
	seek = 1;
	i = 0;
	while (s[i])
	{
		if (s[i] == c && seek == 0)
		{
			seek = 1;
		}
		if (s[i] != c && seek == 1)
		{
			count_word += 1;
			seek = 0;
		}
		i++;
	}
	return (count_word);
}

static char	*ft_copy(int i, const char *s, char c)
{
	char	*copy;
	int		j;
	int		len;
	int		end;

	end = i;
	while (s[end] != c && s[end])
		end++;
	len = end - i;
	copy = malloc(sizeof(char) * (len + 1));
	if (copy == NULL)
		return (NULL);
	j = 0;
	while (i < end)
		copy[j++] = s[i++];
	copy[j] = '\0';
	return (copy);
}

static char	**ft_to_split(const char *s, char c, int word)
{
	int		i;
	int		j;
	char	**split;

	i = -1;
	j = 0;
	split = malloc(sizeof(char *) * (ft_count_word(s, c) + 1));
	if (!split)
		return (NULL);
	while (s[++i])
	{
		if (word == 1 && s[i] != c)
		{
			split[j++] = ft_copy(i, s, c);
			if (split[j - 1] == NULL)
				return (ft_free_split(split));
			word = 0;
		}
		else if (word == 0 && s[i] == c)
			word = 1;
	}
	split[j] = NULL;
	return (split);
}

char	**ft_split(char const *s, char c)
{
	int		word;
	char	**split;

	word = 1;
	if (!s)
		return (NULL);
	split = ft_to_split(s, c, word);
	if (!split)
		return (NULL);
	return (split);
}
