/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaquig <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 15:21:05 by mamaquig          #+#    #+#             */
/*   Updated: 2020/02/26 10:13:22 by mamaquig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	nb_char(t_liste *data, int len)
{
	if (data->width >= len)
		data->str_len += data->width;
	else
		data->str_len += len;
}

void	data_init(t_liste *data)
{
	data->pre_on_off = 0;
	data->prec = 0;
	data->f_zero = 0;
	data->f_less = 0;
	data->width = 0;
}

int		is_flag(char flag)
{
	if (flag != '%' && flag != 'c' && flag != 's' &&
			flag != 'p' && flag != 'd' && flag != 'i' && flag != 'u' &&
			flag != 'x' && flag != 'X')
		return (1);
	else
		return (0);
}

void	struct_filling(t_liste *data, const char *str, va_list ap)
{
	check_flags(data, &str);
	check_width(data, &str, ap);
	check_prec(data, &str, ap);
	check_type(data, &str, ap);
}

int		ft_printf(const char *str, ...)
{
	int		i;
	t_liste	data;
	va_list	ap;

	i = 0;
	data.str_len = 0;
	va_start(ap, str);
	while (str[i])
	{
		data_init(&data);
		if (str[i] == '%')
		{
			struct_filling(&data, &str[++i], ap);
			while (is_flag(str[i]))
				i++;
		}
		else
		{
			write(1, &str[i], 1);
			data.str_len++;
		}
		i++;
	}
	va_end(ap);
	return (data.str_len);
}
