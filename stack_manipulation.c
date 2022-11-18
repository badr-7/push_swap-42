/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_manipulation.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-hous <mel-hous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 13:09:13 by mel-hous          #+#    #+#             */
/*   Updated: 2022/06/26 15:50:35 by mel-hous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

void	sa(t_list **s, int i)
{
	int	temp;
	int	index;

	if (ft_lstsize(*s) > 1)
	{
		temp = (*s)->content;
		index = (*s)->index;
		(*s)->content = (*s)->next->content;
		(*s)->index = (*s)->next->index;
		(*s)->next->content = temp;
		(*s)->next->index = index;
		if (i == 1)
			write(1, "sa\n", 3);
	}
}

void	sb(t_list **s)
{
	int	temp;
	int	index;

	if (ft_lstsize(*s) > 1)
	{
		temp = (*s)->content;
		index = (*s)->index;
		(*s)->content = (*s)->next->content;
		(*s)->index = (*s)->next->index;
		(*s)->next->content = temp;
		(*s)->next->index = index;
		write(1, "sb\n", 1);
	}
}

void	rra(t_list **s, int i)
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
		write(1, "rra\n", 4);
}

void	ra(t_list **s, int i)
{
	t_list	*tmp;

	tmp = *s;
	if (tmp && tmp->next)
	{
		*s = tmp->next;
		ft_lstlast(*s)->next = tmp;
		tmp->next = NULL;
	}
	if (i == 1)
		write(1, "ra\n", 3);
}

void	rb(t_list **s, int i)
{
	t_list	*tmp;

	tmp = *s;
	if (tmp && tmp->next)
	{
		*s = tmp->next;
		ft_lstlast(*s)->next = tmp;
		tmp->next = NULL;
	}
	if (i == 1)
		write(1, "rb\n", 3);
}
