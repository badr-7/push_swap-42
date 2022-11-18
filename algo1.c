/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-hous <mel-hous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 15:44:10 by mel-hous          #+#    #+#             */
/*   Updated: 2022/06/30 10:10:23 by mel-hous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

int	markup(t_list *lst)
{
	t_list	*mh;
	t_list	*best_mh;
	int		count;
	int		best_count;

	mh = lst;
	best_count = 0;
	best_mh = mh;
	while (mh)
	{
		markup_reset(lst);
		count = markup_at(lst, mh);
		if (count > best_count
			|| (count == best_count && mh->index < best_mh->index))
		{
			best_count = count;
			best_mh = mh;
		}
		mh = mh->next;
	}
	markup_reset(lst);
	markup_at(lst, best_mh);
	return (best_count);
}

void	sa_stat(t_list **a)
{
	int	count1;
	int	count2;

	count1 = markup(*a);
	sa(a, 0);
	count2 = markup(*a);
	if (count1 >= count2)
	{
		sa(a, 0);
		markup(*a);
	}
	else
		write(1, "sa\n", 3);
}

void	starting(t_list **s, char **a)
{
	creat_stack(a, s);
	ft_indexing(s);
	markup(*s);
	sa_stat(s);
}
