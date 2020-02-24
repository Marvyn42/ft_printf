/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaquig <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 13:15:18 by mamaquig          #+#    #+#             */
/*   Updated: 2020/02/24 18:03:57 by mamaquig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft/libft.h"

# include <stdarg.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

typedef struct		s_liste
{
	int				str_len;
	int				pre_on_off;
	int				prec;
	int				f_zero;
	int				f_less;
	int				width;
}					t_liste;

int					ft_printf(const char *str, ...);
void				nb_char(t_liste *data, int len);
char				*str_precision(t_liste *data, char *s1, char sign);
void				width_nb(t_liste *data, char *s1, int tmp);
void				check_flags(t_liste *data, const char **str);
void				check_width(t_liste *data, const char **str, va_list ap);
void				check_prec(t_liste *data, const char **str, va_list ap);
void				check_type(t_liste *data, const char **str, va_list ap);
void				print_str(va_list ap, char type, t_liste *data);
void				print_char(va_list ap, char type, t_liste *data);
void				print_nb(va_list ap, char type, t_liste *data);
void				print_uin(va_list ap, char type, t_liste *data);
void				print_add(va_list ap, char type, t_liste *data);
void				print_mod(va_list ap, char type, t_liste *data);

#endif
