#include "philo.h"

int	check2die(t_phil *phil)
{
	pthread_mutex_lock(phil->lock[phil->num_phil]);
	if (*phil->die == 1 || *phil->rf == phil->num_phil)
	{
		pthread_mutex_unlock(phil->lock[phil->num_phil]);
		return (1);
	}
	pthread_mutex_unlock(phil->lock[phil->num_phil]);
	return (0);
}

void	set_death(t_phil *phil, uint64_t c_time)
{
	pthread_mutex_lock(phil->lock[phil->num_phil]);
	*phil->die = 1;
	printf("\033[1;31m[%llu] %d died!\n",
		   (get_time() - c_time) / 1000, phil->uni_num);
	printf("\033[0m");
	pthread_mutex_unlock(phil->lock[phil->num_phil]);
	return ;
}

void	*run_sim(void *phil)
{
	t_phil		*ph;
	uint64_t	c_time;
	int			res;

	ph = (t_phil *) phil;
	c_time = get_time();
	ph->tlm = c_time;
	while (1)
	{
		if (check2die(ph))
			return (NULL);
		if (ph->t2e > ph->t2d || get_time() - ph->tlm > ph->t2d)
			return (return_death(c_time, ph));
		res = eat(ph, c_time);
		if (res == 1)
			return (return_death(c_time, ph));
		else if (res == 0)
		{
			if (get_time() - ph->tlm + ph->t2s > ph->t2d)
				return (return_death(c_time, ph));
			ft_sleep(ph, c_time);
		}
	}
}

int	start_loop(t_params *params)
{
	int			i;

	i = 0;
	while (i < params->num_phil)
	{
		ft_usleep(200);
		params->phil[i] = create_phil(params, i + 1);
		if (pthread_create(&(params->tid[i]), NULL, &run_sim, &params->phil[i]))
			return (1);
		i++;
	}
	i--;
	while (i >= 0)
	{
		pthread_join(params->tid[i], NULL);
		i--;
	}
	clean_params(params);
	return (0);
}

int	main(int argc, char **argv)
{
	t_params	params;

	if (argc < 5 || argc > 6)
	{
		printf("Wrong number of arguments\n");
		return (EXIT_FAILURE);
	}
	if (init_params(&params, argc, argv))
		return (EXIT_FAILURE);
	if (start_loop(&params))
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
