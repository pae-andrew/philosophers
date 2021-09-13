/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_manager.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pae-andrew <pae-andrew@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/28 20:50:56 by pae-andrew        #+#    #+#             */
/*   Updated: 2021/07/28 20:59:43 by pae-andrew       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	write_error(char *str)
{
	int	len;

	len = 0;
	while (str[len])
		len++;
	write(2, "Error: ", 7);
	write(2, str, len);
	write(2, "\n", 1);
	return (1);
}

int	error_manager(int error)
{
	if (error == 1)
		return (write_error("At least one wrong argument"));
	if (error == 2)
		return (write_error("Fatal error when intializing mutex"));
	if (error == 3)
		return (write_error("Error: He can't eat with one fork... He died"));
	return (1);
}
