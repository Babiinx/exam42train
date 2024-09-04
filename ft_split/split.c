/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaboidin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 16:43:14 by gaboidin          #+#    #+#             */
/*   Updated: 2024/09/04 17:04:24 by gaboidin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int	is_charset(char find)
{
	int	i;
	char	*charset = {"\n\t "};

	i = 0;
	while(charset[i])
	{
		if(charset[i] == find)
			return (1);
		i++;
	}
	return (0);
}

int	count_word(char *str)
{
	int	i;
	int	word;

	i = 0;
	word = 0;
	while(str[i])
	{
		if (!is_charset(str[i]))
		{
			word++;
			while(!is_charset(str[i])  && str[i])
				i++;
		}
		else
			i++;
	}
	return (word);
}

void	malloc_len_word(char *str, char **tab)
{
	int	i;
	int	j;
	int	len;

	i = 0;
	j = 0;
	while(str[i])
	{
		if(!is_charset(str[i]))
		{
			len = 0;
			while(!is_charset(str[i]) && str[i])
			{
				i++;
				len++;
			}
			tab[j] = malloc(sizeof(char) * (len + 1));
			if (!tab[j])
				return ;
			j++;
		}
		else
			i++;
	}
}

void	print(char *str, char **tab)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	k = 0;
	while(str[i])
	{
		j = 0;
		if (!is_charset(str[i]))
		{
			while (!is_charset(str[i]) && str[i])
			{
				tab[k][j] = str[i];
				i++;
				j++;
			}
			tab[k][j] = '\0';
			k++;
		}
		else
			i++;
	}
}

char	**ft_split(char *str)
{
	char	**tab;

	tab = malloc(sizeof(char *) * (count_word(str) + 1));
	if (!tab)
		return (0);
	malloc_len_word(str, tab);
	print(str, tab);
	return (tab);
}

int	main(int ac, char **av)
{
	if (ac != 2)
		return (0);
	char	**tab = ft_split(av[1]);
	int	i = 0;
	while(tab[i])
	{
		printf("%s\n", tab[i]);
		i++;
	}
	return (0);
}
