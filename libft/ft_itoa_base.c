/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrignell <jrignell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/16 18:51:07 by jrignell          #+#    #+#             */
/*   Updated: 2020/02/21 12:46:55 by jrignell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa_base(long long value, int base, int upper)
{
	char				*s;
	char				*res;
	int					i;
	unsigned long long	temp;
	unsigned long long	n;

	s = (upper == 1) ? "0123456789ABCDEF" : "0123456789abcdef";
	i = (value < 0 && base == 10) ? 2 : 1;
	n = (value < 0) ? -value : value;
	temp = n;
	while ((temp /= base) > 0)
		i++;
	if (!(res = ft_strnew(i)))
		return (NULL);
	while (n)
	{
		res[--i] = s[n % base];
		n = n / base;
	}
	if (value == 0)
		res[0] = '0';
	else if (value < 0 && base == 10)
		res[0] = '-';
	return (res);
}
