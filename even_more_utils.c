/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   even_more_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfaria-m <lfaria-m@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 11:51:35 by lfaria-m          #+#    #+#             */
/*   Updated: 2024/11/27 12:03:20 by lfaria-m         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "push_swap.h"
#include <limits.h>

t_list	*find_best_match(t_list *stack_b, long nbr)
{
	t_list	*current_b;
	t_list	*target_node;
	long	best_match;

	current_b = stack_b;
	target_node = NULL;
	best_match = LONG_MIN;
	while (current_b)
	{
		if (current_b->nbr < nbr && current_b->nbr > best_match)
		{
			best_match = current_b->nbr;
			target_node = current_b;
		}
		current_b = current_b->next;
	}
	if (best_match == LONG_MIN)
		return (find_max(stack_b));
	return (target_node);
}
const char	*skip_whitespace(const char *str)
{
	while (*str == ' ' || *str == '\t' || *str == '\n' || *str == '\v'
		|| *str == '\f' || *str == '\r')
		str++;
	return (str);
}
int	check_overflow(long long result, int sign, int *error)
{
	if (sign * result > INT_MAX || sign * result < INT_MIN)
	{
		*error = 1;
		return (1);
	}
	return (0);
}

void	set_target_a(t_list **stack_a, t_list **stack_b)
{
	t_list	*current_a;

	current_a = *stack_a;
	while (current_a)
	{
		current_a->target = find_best_match(*stack_b, current_a->nbr);
		current_a = current_a->next;
	}
}
