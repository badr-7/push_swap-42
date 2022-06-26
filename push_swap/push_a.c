/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_a.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-hous <mel-hous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 13:37:07 by mel-hous          #+#    #+#             */
/*   Updated: 2022/06/26 16:02:16 by mel-hous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_diff(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}

void	ft_movment(t_list **stack_a, t_list **stack_b, t_list *elem_b)
{
	int		rotation_a;
	int		rotation_b;
	int		rev_rotation_a;
	int		rev_rotation_b;
	t_list	*elem_a;

	elem_a = ft_find_min_gt(stack_a, elem_b->index);
	rotation_b = ft_pos(*stack_b, elem_b->content);
	rotation_a = ft_pos(*stack_a, elem_a->content);
	rev_rotation_a = ft_lstsize(*stack_a) - rotation_a;
	rev_rotation_b = ft_lstsize(*stack_b) - rotation_b;
	if (rotation_a <= rev_rotation_a && rotation_b <= rev_rotation_b)
		ft_atleast1(stack_a, stack_b, elem_a, elem_b);
	if (rotation_a > rev_rotation_a && rotation_b > rev_rotation_b)
		ft_atleast2(stack_a, stack_b, elem_a, elem_b);
	if (rotation_a <= rev_rotation_a)
		ft_rotation(stack_a, elem_a, 1);
	else
		ft_rrotation(stack_a, elem_a, 1);
	if (rotation_b <= rev_rotation_b)
		ft_rotation(stack_b, elem_b, 0);
	else
		ft_rrotation(stack_b, elem_b, 0);
}

int	ft_move(t_list **a, t_list **b, t_list *elem_b)
{
	int		rotation_a;
	int		rotation_b;
	int		rev_rotation_a;
	int		rev_rotation_b;
	t_list	*elem_a;

	elem_a = ft_find_min_gt(a, elem_b->index);
	rotation_b = ft_pos(*b, elem_b->content);
	rotation_a = ft_pos(*a, elem_a->content);
	rev_rotation_a = ft_lstsize(*a) - rotation_a;
	rev_rotation_b = ft_lstsize(*b) - rotation_b;
	if (rotation_a <= rev_rotation_a && rotation_b <= rev_rotation_b)
		return (ft_diff(rotation_a, rotation_b));
	if (rotation_a > rev_rotation_a && rotation_b > rev_rotation_b)
		return (ft_diff(rev_rotation_a, rev_rotation_b));
	if (rotation_a <= rev_rotation_a && rotation_b > rev_rotation_b)
		return (rotation_a + rev_rotation_b);
	return (rev_rotation_a + rotation_b);
}

void	ft_pusha(t_list **stack_a, t_list **stack_b)
{
	t_list	*tmp;
	t_list	*best_elem;
	int		mvt;
	int		best_mvt;

	while (*stack_b)
	{
		tmp = *stack_b;
		best_mvt = 0;
		best_elem = NULL;
		while (tmp)
		{
			mvt = ft_move(stack_a, stack_b, tmp);
			if (!best_mvt || mvt < best_mvt)
			{
				best_mvt = mvt;
				best_elem = tmp;
			}
			tmp = tmp->next;
		}
		ft_movment(stack_a, stack_b, best_elem);
		pa(stack_a, stack_b, 1);
	}
	align_a(stack_a);
}
