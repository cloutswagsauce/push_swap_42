/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_helper.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfaria-m <lfaria-m@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 12:10:16 by lfaria-m          #+#    #+#             */
/*   Updated: 2024/11/27 12:11:58 by lfaria-m         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "push_swap.h"

void	move_a_to_b(t_list **stack_a, t_list **stack_b)
{
	t_list	*cheapest_node;

	cheapest_node = get_cheapest(*stack_a);
	if (!cheapest_node)
		return ;
	if (cheapest_node->above_median && cheapest_node->target->above_median)
		rotate_both(stack_a, stack_b, cheapest_node);
	else if (!(cheapest_node->above_median)
		&& !(cheapest_node->target->above_median))
		reverse_rotate_both(stack_a, stack_b, cheapest_node);
	push_prep(stack_a, cheapest_node, 'a');
	push_prep(stack_b, cheapest_node->target, 'b');
	pb(stack_a, stack_b);
}

void	move_b_to_a(t_list **stack_a, t_list **stack_b)
{
	t_list	*target;

	if (!*stack_b)
		return ;
	if ((*stack_b)->target)
		target = (*stack_b)->target;
	else
		target = find_min(*stack_a);
	if (target)
	{
		push_prep(stack_a, target, 'a');
		pa(stack_a, stack_b);
	}
}

void	init_nodes_b(t_list **stack_a, t_list **stack_b)
{
	set_indexes(*stack_a);
	set_indexes(*stack_b);
	set_target_b(stack_a, stack_b);
}

t_list	*get_cheapest(t_list *stack)
{
	if (!stack)
		return (0);
	while (stack)
	{
		if (stack->cheapest)
			return (stack);
		stack = stack->next;
	}
	return (0);
}