/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_precision.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaquig <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 16:58:42 by mamaquig          #+#    #+#             */
/*   Updated: 2020/02/19 17:03:27 by mamaquig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	check_prec(t_liste *data, const char **str, va_list ap)
{
	int			i;
	int			tmp;
	const char	*str2;

	i = 0;
	str2 = *str;
	if (str2[i] == '.')
	{
		data->pre_on_off = 1;
		str2++;
		*str = str2;
		if ((data->prec = ft_atoi(str2)))
		{
			tmp = ft_strlen(ft_itoa(data->prec));
			if (str2[i] == '0')
				tmp += 1;
			*str = ((str2) + tmp);
		}
		else if (str2[i] == '*')
		{
			data->prec = (va_arg(ap, int));
			*str = ++str2;
		}
	}
}
