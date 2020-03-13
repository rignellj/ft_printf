/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_brk.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrignell <jrignell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/02 19:11:25 by jrignell          #+#    #+#             */
/*   Updated: 2020/02/21 17:10:00 by jrignell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		printf_bonus(t_format *f, unsigned long long print)
{
	int		len;

	if (!f->len && f->format == 'b')
		f->nbr = ft_itoa_base((unsigned)print, 2, 0);
	else if (f->len && f->format == 'b')
		hh_h_ll_l_u(f, print, 2, 0);
	if (f->dot && f->format != 'b')
		ft_parse_precision(f);
	if (f->plus || f->space || f->hash)
		ft_parse_flags(f);
	if (f->width)
		ft_parse_width(f);
	ft_putstr(f->nbr);
	len = ft_strlen(f->nbr);
	ft_struct_del(f);
	return (len);
}
