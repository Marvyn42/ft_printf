/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_width.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaquig <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 15:05:10 by mamaquig          #+#    #+#             */
/*   Updated: 2020/02/26 02:49:17 by mamaquig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	w_is_null(const char **str)
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

void	w_is_num(const char **str, t_liste *data)
{
	int			tmp;
	const char	*str2;
	int			i;

	i = 0;
	tmp = 0;
	str2 = *str;
	while (str2[i++] == '0')
		tmp++;
	tmp += ft_strlen(ft_itoa(data->width));
	*str = ((str2) + tmp);
}

void	check_width(t_liste *data, const char **str, va_list ap)
{
	int			i;
	int			tmp;
	const char	*str2;

	str2 = *str;
	i = 0;
	tmp = 0;
	if ((data->width = ft_atoi(str2)))
		w_is_num(str, data);
	else if (str2[i] == '0')
		w_is_null(str);
	else if (str2[i] == '*')
	{
		data->width = (va_arg(ap, int));
		if (data->width < 0)
		{
			data->f_less = 1;
			data->width *= -1;
		}
		*str = ++str2;
	}
}
