/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_nb.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaquig <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 13:53:02 by mamaquig          #+#    #+#             */
/*   Updated: 2020/02/19 14:56:58 by mamaquig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

char	*str_precision(t_liste *data, char *s1)
{
	char *str;

	str = ft_calloc((data->prec - ft_strlen(s1)), 1);
	str = ft_memset(str, 48, (data->prec - ft_strlen(s1)));
	str = ft_strjoin(str, s1);
	return (str);
}

void	width_nb(t_liste *data, char *s1)
{
	if (data->f_less == 1)
	{
		write(1, s1, ft_strlen(s1));
		while ((data->width-- - ft_strlen(s1)) != 0)
			write(1, " ", 1);
	}
	else if (data->f_zero == 1 && data->pre_on_off == 0)
	{
		while ((data->width-- - ft_strlen(s1)) != 0)
			write(1, "0", 1);
		write(1, s1, ft_strlen(s1));
	}
	else
	{
		while ((data->width-- - ft_strlen(s1)) != 0)
			write(1, " ", 1);
		write(1, s1, ft_strlen(s1));
	}
}

void	print_nb(va_list ap, char type, t_liste *data)
{
	long int		nb;
	char			*s1;

	if (type == 'u')
		nb = va_arg(ap, unsigned int);
	else
		nb = va_arg(ap, int);
	if (!(s1 = ft_itoa(nb)))
		return ;
	if (data->pre_on_off && (unsigned)data->prec > ft_strlen(s1))
		s1 = str_precision(data, s1);
	else if (data->pre_on_off && data->prec == 0 && nb == 0)
		return ;
	nb_char(data, ft_strlen(s1));
	if (data->width && (unsigned)data->width > ft_strlen(s1))
		width_nb(data, s1);
	else
		write(1, s1, ft_strlen(s1));
}
