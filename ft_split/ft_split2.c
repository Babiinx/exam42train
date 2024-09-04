/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaboidin <gaboidin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 15:40:58 by gaboidin          #+#    #+#             */
/*   Updated: 2024/09/04 15:43:35 by gaboidin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int is_charset(char find)
{
	int		i;
	char	*charset = {"\n \t"};
    
	i = 0;
	while (charset[i])
	{
		if (charset[i] == find)
			return (1);
		i++;
	}
	return (0);
}

int	count_word(char *str)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		if (!is_charset(str[i]))
		{
			count++;
			while (!is_charset(str[i]) && str[i])
				i++;
		}
		else
			i++;
	}
	return (count);
}

void	malloc_len_word(char *str, char **tab)
{
	int	i;
	int	j;
	int	word;

	i = 0;
	j = 0;
	while (str[i])
	{
		if (!is_charset(str[i]))
		{
			word = 0;
			while (!is_charset(str[i]) && str[i])
			{
				i++;
				word++;
			}
			tab[j] = malloc(sizeof(char) * (word + 1));
			if (!tab[j])
				return ;
			j++;
		}
		else
			i++;
	}
	tab[j] = 0;
}

void	ft_strcpy(char **tab, char *str)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	k = 0;
	while (str[i])
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

	tab = malloc(sizeof(char *) * count_word(str) + 1);
	if (!tab)
		return (0);
	malloc_len_word(str, tab);
	ft_strcpy(tab, str);
	return (tab);
}

int	main(int ac, char **av)
{
	if (ac != 2)
		return (2);
	int i = 0;
	char **str = ft_split(av[1]);
	if (!str)
		return (2);
	while (str[i])
	{
		printf("%s\n", str[i]);
		i++;
	}
	return (0);
}