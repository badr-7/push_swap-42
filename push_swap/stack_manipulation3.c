/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_manipulation3.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-hous <mel-hous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 16:01:13 by mel-hous          #+#    #+#             */
/*   Updated: 2022/06/26 16:03:09 by mel-hous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

void	ft_rotation(t_list **stack, t_list *elem, int i)
{
	if (i == 1)
		while (*stack != elem)
			ra(stack, 1);
	else
		while (*stack != elem)
			rb(stack, 1);
}

void	ft_rrotation(t_list **stack, t_list *elem, int i)
{
	if (i == 1)
		while (*stack != elem)
			rra(stack, 1);
	else
		while (*stack != elem)
			rrb(stack, 1);
}

void	align_a(t_list **stack_a)
{
	t_list	*elem;

	elem = ft_find(*stack_a, 0);
	if (ft_pos(*stack_a, elem->content) <= ft_lstsize(*stack_a) / 2)
		ft_rotation(stack_a, elem, 1);
	else
		ft_rrotation(stack_a, elem, 1);
}
