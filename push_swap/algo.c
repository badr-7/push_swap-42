/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-hous <mel-hous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 14:20:48 by mel-hous          #+#    #+#             */
/*   Updated: 2022/06/20 16:59:39 by mel-hous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void ft_indexing(t_list **stack)
{
    t_list *tmp;
    t_list *tmp2;
    int a;
	
    tmp = *stack;
    while(tmp)
    {
        tmp2 = *stack;           
        a = 0;
        while (tmp2)
        {
             if(tmp->content > tmp2->content)
                a++;
            tmp2 = tmp2->next;
        } 
        tmp->index = a;
        tmp = tmp->next;
    }
}

void    markup_reset(t_list *lst)
{
	while (lst)
	{
		lst->a = false;
		lst = lst->next;
	}
}

int markup_at(t_list *lst, t_list *mh)
{
	int	count;
	int	max;
	int	size;

	count = 1;
	max = mh->content;
	mh->a = true;
	size = ft_lstsize(lst);
	while (size--)
	{
		if (mh->content >= max)
		{
			max = mh->content;
			mh->a = true;
			count++;
		}
		if (!mh->next)
			mh = lst;
		else
			mh = mh->next;
	}
	return (count);
}

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

void sa_stat(t_list *a)
{
	int count1;
	int count2;

	markup_reset(a);
	count1 = markup(a);
	sa(a);
	markup_reset(a);
	count2 = markup(a);
	if (count1 > count2)
	{
		sa(a);
		markup_reset(a);
		markup(a);
	}
}

 void starting(t_list **s , char **a)
 {
	ft_ft(a, s);
	ft_indexing(s);
	markup(*s);
	sa_stat(*s);
	 
 }