/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-hous <mel-hous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 14:20:48 by mel-hous          #+#    #+#             */
/*   Updated: 2022/06/26 15:45:04 by mel-hous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_indexing(t_list **stack)
{
	t_list	*tmp;
	t_list	*tmp2;
	int		a;

	tmp = *stack;
	while (tmp)
	{
		tmp2 = *stack;
		a = 0;
		while (tmp2)
		{
			if (tmp->content > tmp2->content)
				a++;
			tmp2 = tmp2->next;
		}
		tmp->index = a;
		tmp = tmp->next;
	}
}

void	markup_reset(t_list *lst)
{
	while (lst)
	{
		lst->keep = false;
		lst = lst->next;
	}
}

int	markup_at(t_list *lst, t_list *mh)
{
	int	count;
	int	max;
	int	size;

	count = 1;
	max = mh->content;
	mh->keep = true;
	size = ft_lstsize(lst);
	while (size--)
	{
		if (mh->content >= max)
		{
			max = mh->content;
			mh->keep = true;
			count++;
		}
		if (!mh->next)
			mh = lst;
		else
			mh = mh->next;
	}
	return (count);
}
