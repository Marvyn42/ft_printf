/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_precision.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaquig <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 16:58:42 by mamaquig          #+#    #+#             */
/*   Updated: 2020/02/26 02:43:08 by mamaquig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	p_is_null(const char **str)
{
	int			tmp;
	const char	*str2;
	int			i;

	i = 0;
	tmp = 0;
	str2 = *str;
	while (str2[i++] == '0')
		tmp++;
	*str = ((str2) + tmp);
}

void	p_is_num(const char **str, t_liste *data)
{
	int			tmp;
	const char	*str2;
	int			i;

	i = 0;
	tmp = 0;
	str2 = *str;
	while (str2[i++] == '0')
		tmp++;
	tmp += ft_strlen(ft_itoa(data->prec));
	*str = ((str2) + tmp);
}

void	check_prec(t_liste *data, const char **str, va_list ap)
{
	int			tmp;
	const char	*str2;

	str2 = *str;
	tmp = 0;
	if (str2[0] == '.')
	{
		data->pre_on_off = 1;
		str2++;
		*str = str2;
		if ((data->prec = ft_atoi(str2)))
			p_is_num(str, data);
		else if (str2[0] == '0')
			p_is_null(str);
		else if (str2[0] == '*')
		{
			if ((tmp = va_arg(ap, int)) >= 0)
				data->prec = tmp;
			else
				data->pre_on_off = 0;
			*str = ++str2;
		}
	}
}
