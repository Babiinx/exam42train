/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaboidin <gaboidin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 11:58:27 by gaboidin          #+#    #+#             */
/*   Updated: 2024/08/31 18:08:10 by gaboidin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(const char *str)
{
	int	i;
	int	ng;
	int	res;

	i = 0;
	ng = 1;
	res = 0;
	while (str[i])
	{
		while (str[i] == ' ' || str[i] == '\n' || str[i] == '\t'
			|| str[i] == '\v' || str[i] == '\f' || str[i] == '\r')
			i++;
		if (str[i] == '-' || str[i] == '+')
		{
			if (str[i] == '-')
				ng = -ng;
			i++;
		}
		if (str[i] == '-' || str[i] == '+')
			return (0);
		if (str[i] >= '0' && str[i] <= '9')
		{
			res = res * 10 + (str[i] - 48);
			i++;
		}
	}
	return (res * ng);
}

//#include <stdio.h>
//
//int	main(void)
//{
//	char str[] = "    --223afe1";
//	printf("%d", ft_atoi(str));
//	return (0);
//}