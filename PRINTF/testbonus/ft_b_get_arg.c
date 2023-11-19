/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_b_get_arg.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: jdobos <jdobos@student.42.fr>                +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/11/16 14:44:16 by jdobos        #+#    #+#                 */
/*   Updated: 2023/11/19 16:24:57 by joni          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*get_arg_void(void *arg, t_va *v, t_fl *f)
{
	if (f->f_len == 0)
		v->print = arg_ptr(arg, v, f);
	else if (v->spec == 2 && arg && f->f_len > 0)
		v->print = flag_check_str(v, f, (char *)arg);
	else if (v->spec == 2 && !arg && f->f_len > 0)
		v->print = flag_check_str(v, f, "(null)");
	else if (v->spec == 3 && f->f_len > 0)
		v->print = flag_check_ptr(v, f, arg);
	if (!(v->print))
		return (NULL);
	return (v->print);
}

char	*get_arg_u(unsigned int arg, t_va *v, t_fl *f)
{
	if (v->spec == 6 && f->f_len == 0)
		v->print = arg_num(arg, v, f);
	else if (v->spec == 6 && f->f_len > 0)
		v->print = flag_check_num(v, f, arg);
	if (!(v->print))
		return (NULL);
	return (v->print);
}

char	*get_arg_int(int arg, t_va *v, t_fl *f)
{
	if (f->f_len == 0 && v->spec == 1)
		v->print = char_str(arg, v->print, 0);
	else if (f->f_len == 0)
		v->print = arg_num(arg, v, f);
	else if (v->spec == 1 && f->f_len > 0)
		v->print = flag_check_ch(v, f, arg);
	else if (v->spec == 4 && f->f_len > 0)
		v->print = flag_check_num(v, f, arg);
	else if (v->spec == 5 && f->f_len > 0)
		v->print = flag_check_num(v, f, arg);
	else if (v->spec == 7 && f->f_len > 0)
		v->print = flag_check_hex(v, f, arg);
	else if (v->spec == 8 && f->f_len > 0)
		v->print = flag_check_hex(v, f, arg);
	if (!(v->print))
		return (NULL);
	return (v->print);
}

char	*arg_num(long long arg, t_va *v, t_fl *f)
{
	if (v->spec == 6)
		v->print = add_p_f(v->print, mod_itoa(arg, 10, 0));
	else if (v->spec == 4)
		v->print = add_p_f(v->print, mod_itoa(arg, 10, 0));
	else if (v->spec == 5)
		v->print = add_p_f(v->print, mod_itoa(arg, 10, 0));
	else if (v->spec == 7)
		v->print = add_p_f(v->print, mod_itoa(arg, 16, 0));
	else if (v->spec == 8)
		v->print = add_p_f(v->print, mod_itoa(arg, 16, 1));
	return (v->print);
}

char	*arg_ptr(void *arg, t_va *v, t_fl *f)
{
	if (v->spec == 2 && arg)
		v->print = add_print(v->print, (char *)arg);
	else if (v->spec == 2 && !arg)
		v->print = add_print(v->print, "(null)");
	else if (v->spec == 3)
		v->print = add_p_f(v->print, ptr_str(arg));
	return (v->print);
}
