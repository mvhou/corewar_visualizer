/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strsplit.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: eutrodri <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/03 22:10:54 by eutrodri      #+#    #+#                 */
/*   Updated: 2019/02/04 08:17:19 by eutrodri      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int		ft_count_words(const char *str, char c)
{
	int		word;
	int		i;

	i = 0;
	word = 0;
	if (!str)
		return (0);
	while (str[i] != '\0')
	{
		if (str[i] == c && str[i + 1] != c && str[i + 1] != '\0')
			word++;
		i++;
	}
	if (str[0] != '\0')
		word++;
	return (word);
}

static	char	*fresh_str(const char *str, char c, int *i)
{
	char	*s;
	int		k;
	int		j;

	k = *i;
	j = *i;
	while (str[j] != c && str[j] != '\0')
		j++;
	s = (char*)malloc(sizeof(*s) * ((j - k) + 1));
	if (s == NULL)
		return (NULL);
	k = 0;
	while (str[*i] != c && str[*i] != '\0')
	{
		s[k] = str[*i];
		k++;
		*i = *i + 1;
	}
	s[k] = '\0';
	while (str[*i] == c && str[*i] != '\0')
		*i = *i + 1;
	return (s);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**sf;
	int		i;
	int		w;
	int		j;

	if (!s)
		return (NULL);
	i = 0;
	j = 0;
	w = ft_count_words(s, c);
	sf = (char**)malloc(sizeof(char**) * (w + 1));
	if (sf == NULL)
		return (NULL);
	while (s[i] == c && s[i] != '\0')
		i++;
	while (j <= w && s[i] != '\0')
	{
		sf[j] = fresh_str(s, c, &i);
		j++;
	}
	sf[j] = NULL;
	return (sf);
}
