/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_manipulation2.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-hous <mel-hous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 15:57:26 by mel-hous          #+#    #+#             */
/*   Updated: 2022/06/26 18:21:57 by mel-hous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

void	ss(t_list **a, t_list **b)
{
	sa(a, 1);
	sb(b);
}

t_list	*ft_find(t_list *s, int index)
{
	while (s)
	{
		if (s->index == index)
			return (s);
		s = s->next;
	}
	return (NULL);
}

t_list	*ft_find_min_gt(t_list **s, int index)
{
	t_list	*stack;
	t_list	*result;

	stack = *s;
	result = NULL;
	while (!result && stack)
	{
		if (stack->index > index)
			result = stack;
		stack = stack->next;
	}
	while (stack)
	{
		if (stack->index > index && stack->index < result->index)
			result = stack;
		stack = stack->next;
	}
	return (result);
}

void	ft_atleast1(t_list **a, t_list **b, t_list *elma, t_list *elmb)
{
	while (*a != elma && *b != elmb)
		rr(a, b, 1);
}

void	ft_atleast2(t_list **a, t_list **b, t_list *elma, t_list *elmb)
{
	while (*a != elma && *b != elmb)
		rrr(a, b, 1);
}
