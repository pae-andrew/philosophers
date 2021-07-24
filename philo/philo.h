/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcredibl <gcredibl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/24 14:18:30 by gcredibl          #+#    #+#             */
/*   Updated: 2021/07/24 15:27:24 by gcredibl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
# include <unistd.h>
# include <stdio.h>
# include <sys/time.h>
# include <pthread.h>
# include <stdlib.h>
/*
 *
 * t2d - time to die with out food
 * t2e - time to eat
 * t2s - time to sleep
 * nte - optional - number of times to eat
 * fa - forks available
 */

/*
 * Philosopher number 1 is next to
 * philosopher number ’number_of_philosophers’.
 * tlm - time from last meal
 * tls - time from last sleep
 * tlt - time from last thinking
 */

typedef struct s_philo {
	int				uni_num;
	int				num_phil;
	uint64_t		tlm;
	uint64_t		t2d;
	uint64_t		t2e;
	uint64_t		t2s;
	int				nte;
	pthread_mutex_t	**lock;
	int				*die;
	int				*forks;
	int				*rf;

}	t_phil;

typedef struct s_params {
	int				num_phil;
	unsigned int	t2d;
	unsigned int	t2e;
	unsigned int	t2s;
	int				nte;
	int				r2d;
	int				die;
	int				*forks;
	pthread_mutex_t	**lock;
	pthread_t		*tid;
	t_phil			*phil;
}	t_params;

int			ft_atoi(const char *str);
void		ft_usleep(uint64_t t);
void		ft_sleep(t_phil *phil, uint64_t c_time);
void		*return_death(uint64_t c_time, t_phil *phil);
void		clean_params(t_params *params);
t_phil		create_phil(t_params *params, int num);
int			init_params(t_params *params, int argc, char **argv);
int			allocate_mutex(t_params *params);
uint64_t	get_time(void);
int			eat(t_phil *phil, uint64_t time);
int			return_fork(t_phil *phil);
int			get_fork(t_phil *phil);
void		set_death(t_phil *phil, uint64_t c_time);
void		check2print(char *str, t_phil *ph, uint64_t time);
int			check2die(t_phil *phil);
#endif
