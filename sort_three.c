/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfaria-m <lfaria-m@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 15:23:54 by lfaria-m          #+#    #+#             */
/*   Updated: 2024/11/27 12:05:29 by lfaria-m         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "push_swap.h"

void	sort_three(t_list **list)
{
	int	a;
	int	b;
	int	c;

	a = (*list)->nbr;
	b = (*list)->next->nbr;
	c = (*list)->next->next->nbr;
	if (a < b && b < c)
		return ;
	else if (a < c && c < b)
	{
		sa(list);
		ra(list);
	}
	else if (b < a && a < c)
		sa(list);
	else if (b < c && c < a)
		ra(list);
	else if (c < a && a < b)
		rra(list);
	else if (c < b && b < a)
	{
		sa(list);
		rra(list);
	}
}
