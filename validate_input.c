/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_input.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfaria-m <lfaria-m@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 10:00:38 by lfaria-m          #+#    #+#             */
/*   Updated: 2024/11/27 12:01:58 by lfaria-m         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "push_swap.h"

int	ft_atoi_safe(const char *str, int *error)
{
	int			sign;
	long long	result;

	sign = 1;
	result = 0;
	*error = 0;
	str = skip_whitespace(str);
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		result = result * 10 + (*str - '0');
		if (check_overflow(result, sign, error))
			return (0);
		str++;
	}
	if (*str != '\0')
		*error = 1;
	return ((int)(sign * result));
}


int	is_int(char *str)
{
	int	error;

	error = 0;
	if (ft_atoi_safe(str, &error) == 0 && error)
		return (0);
	return (1);
}

int	no_duplicates(char *str, t_list *stack_a)
{
	int	error;
	int	value;

	error = 0;
	value = ft_atoi_safe(str, &error);
	if (error)
		return (0);
	while (stack_a)
	{
		if (stack_a->nbr == value)
			return (0);
		stack_a = stack_a->next;
	}
	return (1);
}

int	all_digits(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	if (str[i])
	{
		while (str[i])
		{
			if (!ft_isdigit(str[i]))
				return (0);
			i++;
		}
		return (1);
	}
	else
		return (0);
}

int	validate_input(char *str, t_list *stack_a)
{
	if (str)
	{
		if (all_digits(str) && is_int(str) && no_duplicates(str, stack_a))
			return (1);
		else
			return (0);
	}
	return (0);
}
