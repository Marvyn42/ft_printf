/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_type.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaquig <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 17:40:50 by mamaquig          #+#    #+#             */
/*   Updated: 2020/02/18 12:29:04 by mamaquig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		wich_element(const char *tab, char flag)
{
	int i;

	i = 0;
	while (tab[i])
	{
		if (tab[i] == flag)
			return (i);
		i++;
	}
	return (-1);
}

void	check_type(t_liste *data, const char **str, va_list ap)
{
	int			i;
	int			tmp;
	char const	tab_t[10] = {'c', '%', 's', 'p', 'd', 'i', 'u', 'x', 'X', 0};
	void		(*const tab_f[9])(va_list, char, t_liste *) = {print_char,
				print_char, print_str, print_add, print_nb,
				print_nb, print_nb, print_uin, print_uin};

	i = 0;
	tmp = wich_element(tab_t, *str[i]);
	if (tmp != -1)
		tab_f[tmp](ap, tab_t[tmp], data);
}
