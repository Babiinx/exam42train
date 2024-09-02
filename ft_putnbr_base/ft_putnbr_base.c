/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaboidin <gaboidin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 16:15:12 by gaboidin          #+#    #+#             */
/*   Updated: 2024/09/02 17:04:19 by gaboidin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_is_valid(char *base, int size)
{
	int	i;
	int	k;

	i = 0;
	if (size < 2)
		return (0);
	while (base[i])
	{
		if (base[i] == '-' || base[i] == '+')
			return (0);
		k = i + 1;
		while (base[k])
		{
			if (base[i] == base[k])
				return (0);
			k++;
		}
		i++;
	}
	return (1);
}

void	ft_putnbr_base(int nbr, char *base)
{
	if (ft_is_valid(base, ft_strlen(base)) != 1)
		return ;
	if (nbr == -2147483648)
	{
		ft_putchar('-');
		ft_putnbr_base((nbr / ft_strlen(base)) * -1, base);
		ft_putnbr_base((nbr % ft_strlen(base)) * -1, base);
	}
	else
	{
		if (nbr < 0)
		{
			ft_putchar('-');
			nbr = -nbr;
		}
		if (nbr < ft_strlen(base))
			ft_putchar(base[nbr]);
		else
		{
			ft_putnbr_base((nbr / ft_strlen(base)), base);
			ft_putnbr_base((nbr % ft_strlen(base)), base);
		}
	}
}
int	main(void)
{
	ft_putnbr_base(25685, "poneyvif");
	return (0);
}