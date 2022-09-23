/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_ll.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcomic <kcomic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 23:08:44 by kcomic            #+#    #+#             */
/*   Updated: 2021/12/15 23:08:48 by kcomic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_pow(int nb, int power)
{
	if (power < 0)
		return (0);
	if (power == 0)
		return (1);
	if (power == 1)
		return (nb);
	return (nb * ft_pow(nb, power - 1));
}

int	ft_putnbr_ll(long long nb)
{
	int			len;
	int			ans;

	len = 1;
	ans = 0;
	if (nb == LLONG_MIN)
	{
		ft_putchar('-');
		ft_putchar('9');
		ans += 2;
		nb = 223372036854775808;
	}
	if (nb < 0)
	{
		ans += ft_putchar('-');
		nb = -nb;
	}
	len = ft_pow(10, ft_declen(nb) - 1);
	while (len > 0)
	{
		ans += ft_putchar(nb / len + '0');
		nb %= len;
		len /= 10;
	}
	return (ans);
}
