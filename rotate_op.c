/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_op.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfaria-m <lfaria-m@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 11:02:00 by lfaria-m          #+#    #+#             */
/*   Updated: 2024/11/27 11:10:42 by lfaria-m         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "push_swap.h"

void	rb(t_list **stack_b)
{
	t_list	*temp;
	t_list	*last;

	last = ft_lstlast(*stack_b);
	if (*stack_b)
	{
		temp = *stack_b;
		*stack_b = (*stack_b)->next;
		last->next = temp;
		temp->next = 0;
	}
	write(1, "rb\n", 3);
}

void	rrb(t_list **stack_b)
{
	t_list	*temp;
	t_list	*before_last;

	if (ft_lstsize(*stack_b) < 2)
		return ;
	before_last = *stack_b;
	while (before_last->next && before_last->next->next)
		before_last = before_last->next;
	temp = ft_lstlast(*stack_b);
	before_last->next = 0;
	temp->next = *stack_b;
	*stack_b = temp;
	write(1, "rrb\n", 4);
}

void	rr(t_list **stack_a, t_list **stack_b)
{
	t_list	*temp;
	t_list	*last;
	int		size;

	size = ft_lstsize(*stack_a);
	if (size < 2)
		return ;
	last = ft_lstlast(*stack_a);
	if (*stack_a)
	{
		temp = (*stack_a);
		*stack_a = (*stack_a)->next;
		last->next = temp;
		temp->next = 0;
	}
	last = ft_lstlast(*stack_b);
	if (*stack_b)
	{
		temp = *stack_b;
		*stack_b = (*stack_b)->next;
		last->next = temp;
		temp->next = 0;
	}
	write(1, "rr\n", 3);
}

void	rrr(t_list **stack_a, t_list **stack_b)
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
	if (ft_lstsize(*stack_b) < 2)
		return ;
	before_last = *stack_b;
	while (before_last->next && before_last->next->next)
		before_last = before_last->next;
	temp = ft_lstlast(*stack_b);
	before_last->next = 0;
	temp->next = *stack_b;
	*stack_b = temp;
	write(1, "rrr\n", 4);
}

void	ra(t_list **stack_a)
{
	t_list	*temp;
	t_list	*last;
	int		size;

	size = ft_lstsize(*stack_a);
	if (size < 2)
		return ;
	last = ft_lstlast(*stack_a);
	if (*stack_a)
	{
		temp = (*stack_a);
		*stack_a = (*stack_a)->next;
		last->next = temp;
		temp->next = 0;
	}
	write(1, "ra\n", 3);
}
