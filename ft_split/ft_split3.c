/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaboidin <gaboidin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 15:51:45 by gaboidin          #+#    #+#             */
/*   Updated: 2024/09/04 16:07:12 by gaboidin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int is_charset(char find)
{
    int i = 0;
    char *charset = {"\n\t "};
    
    while(charset[i])
    {
        if (charset[i] == find)
            return (1);
        i++;
    }
    return (0);
}

int count_word(char *str)
{
    int i = 0;
    int word = 0;
    
    while(str[i])
    {
        if(!is_charset(str[i]))
        {
            word++;
            while(!is_charset(str[i]) && str[i])
                i++;
        }
        else
            i++;
    }
    return (word);
}

void malloc_len_word(char *str, char **tab)
{
    int i = 0;
    int j = 0;
    int word;
    while(str[i])
    {
        word = 0;
        if (!is_charset(str[i]))
        {
            while(!is_charset(str[i]) && str[i])
            {
                i++;
                word++;
            }
            tab[j] = malloc(sizeof(char) * (word + 1));
            if(!tab[j])
                return ;
            j++;
        }
        else
            i++;
    }
    tab[j] = 0;
}

void    print(char *str, char **tab)
{
    int i = 0;
    int k = 0;
    int j;
    while (str[i])
    {
        j = 0;
        if (!is_charset(str[i]))
        {
            while(!is_charset(str[i]) && str[i])
            {
                tab[k][j] = str[i];
                j++;
                i++;
            }
            tab[k][j] = '\0';
            k++;
        }
        else
            i++;
    }
    
}

char **ft_split(char *str)
{
    char **tab;

    tab = malloc(sizeof(char *) * count_word(str) + 1);
    if (!tab)
        return (0);
    malloc_len_word(str, tab);
    print(str, tab);
    return (tab);
}

int main(int ac, char **av)
{
    if (ac != 2)
        return (0);
    int i = 0;
    char **str = ft_split(av[1]);

    while(str[i])
    {
        printf("%s\n", str[i]);
        i++;
    }
    return (0);
}