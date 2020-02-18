/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaquig <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/06 13:15:28 by mamaquig          #+#    #+#             */
/*   Updated: 2020/02/18 15:32:52 by mamaquig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	nb_char(t_liste *data, int len)
{
	if (data->width >= len)
		data->str_len += data->width;
	else
		data->str_len += len;
}

void	print_str(va_list ap, char type, t_liste *data)
{
	char	*str;
	int		tmp;

	(void)type;
	str = va_arg(ap, char *);
	if (data->pre_on_off && (unsigned)data->prec < ft_strlen(str))
		tmp = data->prec;
	else
		tmp = ft_strlen(str);
	nb_char(data, tmp);
	if (data->f_less)
	{
		write(1, str, tmp);
		if (data->width && data->width > tmp)
			while ((data->width-- - tmp) != 0)
				write(1, " ", 1);
	}
	else
	{
		if (data->width && data->width > tmp)
			while ((data->width-- - tmp) != 0)
				write(1, " ", 1);
		write(1, str, tmp);
	}
}
