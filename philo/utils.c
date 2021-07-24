#include "philo.h"

void	clean_params(t_params *params)
{
	int	i;

	i = 0;
	while (i <= params->num_phil)
	{
		free(params->lock[i]);
		pthread_mutex_destroy(params->lock[i]);
		i++;
	}
	free(params->lock);
	free(params->forks);
	free(params->tid);
	free(params->phil);
}

void 	*return_death(uint64_t c_time, t_phil *phil)
{
	set_death(phil, c_time);
	return (NULL);
}

void	ft_sleep(t_phil *phil, uint64_t c_time)
{
	check2print("is sleeping", phil, c_time);
	ft_usleep(phil->t2s);
	return ;
}

void	ft_usleep(uint64_t t)
{
	uint64_t	start;
	uint64_t	end;

	start = get_time();
	end = start + t;
	while (1)
	{
		if (get_time() >= end)
			return ;
		usleep(50);
	}
}

int	ft_atoi(const char *str)
{
	int					i;
	int					sign;
	unsigned long long	res;

	res = 0;
	sign = 1;
	i = 0;
	if (str == NULL)
		return (0);
	while (str[i] == '\t' || str[i] == '\n' || str[i] == '\v' || str[i] == '\f'
		   || str[i] == '\r' || str[i] == ' ')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i] > 47 && str[i] < 58)
	{
		res = (res * 10) + (str[i] - 48);
		i++;
	}
	return (res * sign);
}
