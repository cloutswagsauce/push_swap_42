/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfaria-m <lfaria-m@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 15:20:52 by lfaria-m          #+#    #+#             */
/*   Updated: 2024/11/27 11:40:36 by lfaria-m         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "push_swap.h"
#include <stdio.h>

void	free_split(char **split)
{
	int	i;

	i = 0;
	if (!split)
		return ;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}

void	call_sort(t_list *stack_a, t_list *stack_b)
{
	if (!is_sorted(stack_a) && stack_a)
	{
		if (ft_lstsize(stack_a) == 2)
			sa(&stack_a);
		else if (ft_lstsize(stack_a) == 3)
			sort_three(&stack_a);
		else
			sort_stack(&stack_a, &stack_b);
	}
}

int	input_str(char *str, t_list **stack_a)
{
	char	**split_argv;

	split_argv = ft_split(str, ' ');
	if (!split_argv)
		return (1);
	if (!init_stack(stack_a, split_argv))
	{
		free_split(split_argv);
		free_stack(stack_a);
		return (1);
	}
	free_split(split_argv);
	return (0);
}

int	arg_count_init(int argc, char **argv, t_list **stack_a)
{
	if (argc == 2)
	{
		if (input_str(argv[1], stack_a))
			return (1);
	}
	else
	{
		if (!init_stack(stack_a, ++argv))
		{
			free_stack(stack_a);
			return (1);
		}
		return (0);
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_list	*stack_a;
	t_list	*stack_b;

	stack_a = 0;
	stack_b = 0;
	if (argc == 1)
		return (1);
	if ((argc == 2) && !(argv[1][0]))
	{
		write(2, "Error\n", 6);
		return (1);
	}
	if (arg_count_init(argc, argv, &stack_a))
		return (1);
	call_sort(stack_a, stack_b);
	free_stack(&stack_a);
	free_stack(&stack_b);
	return (0);
}
