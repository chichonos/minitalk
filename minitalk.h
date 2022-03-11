/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mea <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 12:44:01 by mea               #+#    #+#             */
/*   Updated: 2022/03/11 11:14:53 by mea              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include "./printf/includes/ft_printf.h"

int	ft_printf(const char *input, ...);
int	ft_eval_input(va_list *list, char input);
int	ft_putchar_modif(char c);
int	ft_putnbr_modif(int nb);
int	ft_putstr_modif(char *str);
int	ft_putnbr_u_modif(unsigned int nb);
int	ft_hexa_modif(unsigned int nb);
int	ft_hexa_modif_v2(unsigned int nb);
int	ft_hexa_modif_v3(unsigned long nb);

#endif