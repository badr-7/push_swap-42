/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_manipulation1.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-hous <mel-hous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 15:47:34 by mel-hous          #+#    #+#             */
/*   Updated: 2022/06/26 15:57:20 by mel-hous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

void	rrb(t_list **s, int i)
{
	t_list	*temp2;
	t_list	*temp1;

	temp1 = *s;
	temp2 = NULL;
	while (temp1 && temp1->next)
	{
		temp2 = temp1;
		temp1 = temp1->next;
	}
	if (temp2)
	{
		temp1->next = *s;
		*s = temp1;
		temp2->next = NULL;
	}
	if (i == 1)
		write(1, "rrb\n", 4);
}

void	rrr(t_list **a, t_list **b, int i)
{
	rra(a, 0);
	rrb(b, 0);
	if (i == 1)
		write(1, "rrr\n", 4);
}

void	pa(t_list **a, t_list **b, int i)
{
	t_list	*tmp;

	tmp = *b;
	if (tmp)
	{
		*b = tmp->next;
		tmp->next = *a;
		*a = tmp;
	}
	if (i == 1)
		write(1, "pa\n", 3);
}

void	pb(t_list **a, t_list **b, int i)
{
	t_list	*tmp;

	tmp = *a;
	if (tmp)
	{
		*a = tmp->next;
		tmp->next = *b;
		*b = tmp;
	}
	if (i == 1)
		write(1, "pb\n", 3);
}

void	rr(t_list **a, t_list **b, int i)
{
	ra(a, 0);
	rb(b, 0);
	if (i == 1)
		write(1, "rr\n", 3);
}
