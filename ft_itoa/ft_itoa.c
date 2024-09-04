/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaboidin <gaboidin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 19:35:29 by gaboidin          #+#    #+#             */
/*   Updated: 2024/09/04 20:32:58 by gaboidin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h> 

char *ft_itoa(int nbr)
{
    int len = 0;
    int neg = 0;
    int tmp = nbr;
    char *str;

    if (nbr == -2147483648)
        return ("-2147483648");
    if (nbr < 0)
    {
        nbr = -nbr;
        neg = 1;
    }
    while (tmp != 0)
    {
        tmp = tmp / 10;
        len++;
    }
    
    len = len + neg;
    if (!(str = malloc(sizeof(char) * len)))
        return (NULL);
    str[--len] = '\0';
    while(len != 0)
    {
        str[len] = nbr % 10 + 48;
        nbr = nbr / 10;
        len--;
    }
    if (neg)
        str[0] = '-';
    return (str);
}

int main(void)
{
    int nbr = -2147483648;
    int i = 0;
    char *str;

    str = ft_itoa(nbr);
    while(str[i])
    {
        printf("%c", str[i]);
        i++;
    }
    return (0);
}