/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_op.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfaria-m <lfaria-m@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 11:00:01 by lfaria-m          #+#    #+#             */
/*   Updated: 2024/11/27 11:10:07 by lfaria-m         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "push_swap.h"

void	sa(t_list **stack_a)
{
	t_list	*temp;

	if (*stack_a && (*stack_a)->next)
	{
		temp = (*stack_a)->next;
		(*stack_a)->next = temp->next;
		temp->next = *stack_a;
		*stack_a = temp;
		write(1, "sa\n", 3);
	}
}

void	sb(t_list **stack_b)
{
	t_list	*temp;

	if (*stack_b && (*stack_b)->next)
	{
		temp = (*stack_b)->next;
		(*stack_b)->next = temp->next;
		temp->next = *stack_b;
		*stack_b = temp;
		write(1, "sb\n", 3);
	}
}

void	ss(t_list **stack_a, t_list **stack_b)
{
	t_list	*temp;

	if (*stack_a && (*stack_a)->next)
	{
		temp = (*stack_a)->next;
		(*stack_a)->next = temp->next;
		temp->next = *stack_a;
		*stack_a = temp;
	}
	if (*stack_b && (*stack_b)->next)
	{
		temp = (*stack_b)->next;
		(*stack_b)->next = temp->next;
		temp->next = *stack_b;
		*stack_b = temp;
	}
	write(1, "ss\n", 3);
}

void	rra(t_list **stack_a)
{
	t_list	*temp;
	t_list	*before_last;

	if (ft_lstsize(*stack_a) < 2)
		return ;
	before_last = *stack_a;
	while (before_last->next && before_last->next->next)
		before_last = before_last->next;
	temp = ft_lstlast(*stack_a);
	before_last->next = 0;
	temp->next = *stack_a;
	*stack_a = temp;
	write(1, "rra\n", 4);
}
