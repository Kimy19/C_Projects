/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaekim <yaekim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 10:30:34 by yaekim            #+#    #+#             */
/*   Updated: 2024/04/03 16:59:12 by yaekim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include "./libft/libft.h"

void	print_x(va_list ptr, int *len, int flag);
void	print_u(va_list ptr, int *len);
void	print_di(va_list ptr, int *len);
void	print_c(va_list ptr, int *len);
void	print_s(va_list ptr, int *len);
void	print_p(va_list ptr, int *len);
int		ft_printf(const char *format, ...);

#endif