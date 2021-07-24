#include "philo.h"

int	eat(t_phil *phil, uint64_t time)
{
	if (get_fork(phil))
		check2print("has taken a fork", phil, time);
	else
		return (-1);
	if (get_time() - phil->tlm > phil->t2d && return_fork(phil))
		return (-1);
	phil->tlm = get_time();
	if (!phil->tlm)
		return (return_fork(phil));
	check2print("is eating", phil, time);
	ft_usleep(phil->t2e);
	return_fork(phil);
	if (phil->nte == 1)
	{
		pthread_mutex_lock(phil->lock[phil->num_phil]);
		*phil->rf += 1;
		pthread_mutex_unlock(phil->lock[phil->num_phil]);
	}
	if (phil->nte > 0)
		phil->nte--;
	return (0);
}

int	return_fork(t_phil *phil)
{
	int	l_fork;
	int	r_fork;

	if (phil->num_phil <= 1)
		return (1);
	if (phil->num_phil == phil->uni_num)
		r_fork = phil->num_phil - 1;
	else
		r_fork = phil->uni_num - 1;
	if (phil->uni_num == 1)
		l_fork = phil->num_phil - 1;
	else
		l_fork = phil->uni_num - 2;
	*phil->forks += 2;
	pthread_mutex_unlock(phil->lock[l_fork]);
	pthread_mutex_unlock(phil->lock[r_fork]);
	return (1);
}

int	get_fork(t_phil *phil)
{
	int	l_fork;
	int	r_fork;

	if (phil->num_phil <= 1)
		return (0);
	if (phil->num_phil == phil->uni_num)
		r_fork = phil->num_phil - 1;
	else
		r_fork = phil->uni_num - 1;
	if (phil->uni_num == 1)
		l_fork = phil->num_phil - 1;
	else
		l_fork = phil->uni_num - 2;
	pthread_mutex_lock(phil->lock[l_fork]);
	pthread_mutex_lock(phil->lock[r_fork]);
	*phil->forks -= 2;
	return (1);
}
