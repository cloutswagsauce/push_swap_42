/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfaria-m <lfaria-m@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 15:18:23 by lfaria-m          #+#    #+#             */
/*   Updated: 2024/11/27 12:16:27 by lfaria-m         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "push_swap.h"

void	set_target_b(t_list **stack_a, t_list **stack_b)
{
	t_list	*current_b;
	t_list	*current_a;
	t_list	*target_node;
	long	best_match;

	current_b = *stack_b;
	while (current_b)
	{
		best_match = LONG_MAX;
		target_node = NULL;
		current_a = *stack_a;
		while (current_a)
		{
			if (current_a->nbr > current_b->nbr && current_a->nbr < best_match)
			{
				best_match = current_a->nbr;
				target_node = current_a;
			}
			current_a = current_a->next;
		}
		if (best_match == LONG_MAX)
			target_node = find_min(*stack_a);
		current_b->target = target_node;
		current_b = current_b->next;
	}
}

void	rotate_both(t_list **stack_a, t_list **stack_b, t_list *cheapest_node)
{
	while (*stack_a != cheapest_node && *stack_b != cheapest_node->target)
		rr(stack_a, stack_b);
	set_indexes(*stack_a);
	set_indexes(*stack_b);
}

void	reverse_rotate_both(t_list **stack_a, t_list **stack_b,
		t_list *cheapest_node)
{
	while (*stack_a != cheapest_node && *stack_b != cheapest_node->target)
		rrr(stack_a, stack_b);
	set_indexes(*stack_a);
	set_indexes(*stack_b);
}

static void	min_on_top(t_list **stack_a)
{
	while ((*stack_a)->nbr != find_min(*stack_a)->nbr)
	{
		if (find_min(*stack_a)->above_median)
			ra(stack_a);
		else
			rra(stack_a);
	}
}

void	sort_stack(t_list **stack_a, t_list **stack_b)
{
	int	len;

	len = ft_lstsize(*stack_a);
	if (len-- > 3 && !is_sorted(*stack_a))
		pb(stack_a, stack_b);
	if (len-- > 3 && !is_sorted(*stack_a))
		pb(stack_a, stack_b);
	while (len-- > 3 && !is_sorted(*stack_a))
	{
		init_nodes_a(stack_a, stack_b);
		move_a_to_b(stack_a, stack_b);
	}
	sort_three(stack_a);
	while (*stack_b)
	{
		init_nodes_b(stack_a, stack_b);
		move_b_to_a(stack_a, stack_b);
	}
	set_indexes(*stack_a);
	min_on_top(stack_a);
}
