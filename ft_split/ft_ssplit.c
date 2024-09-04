/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ssplit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaboidin <gaboidin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 18:33:05 by gaboidin          #+#    #+#             */
/*   Updated: 2024/09/04 19:32:40 by gaboidin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

int is_charset(char find)
{
    if (find <= 32)
        return (1);
    return (0);
}

char    **ft_split(char *str)
{
    char **tab = malloc(sizeof(char *) * 10000);
    int i = 0;
    int j = 0;
    int k = 0;
    while(str[i])
    {
        if (!is_charset(str[i]))
        {
            tab[j] = malloc(sizeof(char) * 10000);
            while (!is_charset(str[i]) && str[i])
                tab[j][k++] = str[i++];
            tab[j++][k] = '\0';
            k = 0;
        }
        else
            i++;
    }
    tab[j] = 0;
    return (tab);
}
#include <stdio.h>

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