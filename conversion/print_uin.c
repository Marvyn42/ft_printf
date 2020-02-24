/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_uin.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaquig <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 13:53:02 by mamaquig          #+#    #+#             */
/*   Updated: 2020/02/24 18:20:11 by mamaquig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

char	*min_to_maj(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] >= 'a' && str[i] <= 'z')
			str[i] -= 32;
		i++;
	}
	return (str);
}

void	width_uin(t_liste *data, char *s1)
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

void	print_uin(va_list ap, char type, t_liste *data)
{
	int				nb;
	char			*s1;

	nb = va_arg(ap, int);
	if (nb == 0)
		s1 = "0";
	else
		s1 = ft_itoa_base(nb, 16);
	if (type == 'X')
		s1 = min_to_maj(s1);
	if (data->pre_on_off && (unsigned)data->prec > ft_strlen(s1))
		s1 = str_precision(data, s1, type);
	else if (data->pre_on_off && data->prec == 0 && nb == 0 && data->width == 0)
		return ;
	nb_char(data, ft_strlen(s1));
	if (data->width && data->pre_on_off && data->prec == 0)
		width_nb(data, NULL, 0);
	else if (data->width && (unsigned)data->width > ft_strlen(s1))
		width_nb(data, s1, ft_strlen(s1));
	else
		write(1, s1, ft_strlen(s1));
}
