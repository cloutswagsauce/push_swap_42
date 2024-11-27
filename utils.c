/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfaria-m <lfaria-m@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 13:50:47 by lfaria-m          #+#    #+#             */
/*   Updated: 2024/11/27 11:56:17 by lfaria-m         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "push_swap.h"

void	find_cheapest(t_list *stack)
{
	t_list	*current;
	t_list	*cheapest_node;
	long	cheapest_value;

	current = stack;
	cheapest_node = NULL;
	cheapest_value = LONG_MAX;
	while (current)
	{
		current->cheapest = 0;
		current = current->next;
	}
	current = stack;
	while (current)
	{
		if (current->cost < cheapest_value)
		{
			cheapest_value = current->cost;
			cheapest_node = current;
		}
		current = current->next;
	}
	if (cheapest_node)
		cheapest_node->cheapest = 1;
}

void	cost_check(t_list *stack_a, t_list *stack_b)
{
	int	len_a;
	int	len_b;

	len_a = ft_lstsize(stack_a);
	len_b = ft_lstsize(stack_b);
	while (stack_a)
	{
		stack_a->cost = stack_a->index;
		if (!(stack_a->above_median))
			stack_a->cost = len_a - (stack_a->index);
		if (stack_a->target)
		{
			if (stack_a->target->above_median)
				stack_a->cost += stack_a->target->index;
			else
				stack_a->cost += len_b - (stack_a->target->index);
		}
		stack_a = stack_a->next;
	}
}

t_list	*find_max(t_list *stack)
{
	t_list	*max_node;
	long	max;

	if (!stack)
		return (0);
	max = LONG_MIN;
	while (stack)
	{
		if (stack->nbr > max)
		{
			max_node = stack;
			max = stack->nbr;
		}
		stack = stack->next;
	}
	return (max_node);
}

void	set_indexes(t_list *stack)
{
	int	i;
	int	median;

	i = 0;
	if (!stack)
		return ;
	median = ft_lstsize(stack) / 2;
	while (stack)
	{
		stack->index = i;
		stack->above_median = 0;
		if (i <= median)
			stack->above_median = 1;
		stack = stack->next;
		i++;
	}
}

int	is_sorted(t_list *stack)
{
	if (!stack)
		return (0);
	while (stack->next)
	{
		if (stack->nbr > stack->next->nbr)
			return (0);
		stack = stack->next;
	}
	return (1);
}
