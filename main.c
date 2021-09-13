/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pae-andrew <pae-andrew@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/28 20:53:39 by pae-andrew        #+#    #+#             */
/*   Updated: 2021/07/28 20:58:14 by pae-andrew       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_rules	rules;
	int		ret;

	if (argc != 5 && argc != 6)
		return (write_error("Wrong amount of arguments"));
	ret = init_all(&rules, argv);
	if (ret)
		return (error_manager(ret));
	if (launcher(&rules))
		return (write_error("There was an error creating the threads"));
	return (0);
}
