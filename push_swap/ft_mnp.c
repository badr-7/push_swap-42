/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mnp.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-hous <mel-hous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 13:09:13 by mel-hous          #+#    #+#             */
/*   Updated: 2022/06/25 10:47:56 by mel-hous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

void    sa(t_list **s, int i)
{
    if(ft_lstsize(*s) > 1)
    {
        int temp;
        int index;
        
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

void    sb(t_list **s)
{
    if(ft_lstsize(*s) > 1)
    {
        int temp;
        int index;
        
        temp = (*s)->content;
        index = (*s)->index;
    
        (*s)->content = (*s)->next->content;
        (*s)->index = (*s)->next->index;
        (*s)->next->content = temp;
        (*s)->next->index = index;
		write(1,"sb\n", 1);
    }
}

void ss(t_list **a,t_list **b)
{
    sa(a, 1);
    sb(b);
}

void rra(t_list **s, int i)
{
    t_list *temp2;
    t_list *temp1;

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
	if(i == 1)
		write(1, "rra\n", 4);
}
void ra(t_list **s, int i)
{
    t_list	*tmp;

	tmp = *s;
	if (tmp && tmp->next)
	{
		*s = tmp->next;
		ft_lstlast(*s)->next = tmp;
		tmp->next = NULL;
    }
	if(i == 1)
		write(1, "ra\n", 3);
}

void rb(t_list **s, int i)
{
    t_list	*tmp;

	tmp = *s;
	if (tmp && tmp->next)
	{
		*s = tmp->next;
		ft_lstlast(*s)->next = tmp;
		tmp->next = NULL;
    }
	if(i == 1)
		write(1, "rb\n", 3);
}

void rr(t_list **a, t_list **b)
{
    ra(a, 0);
    rb(b, 0);
	write(1, "rr\n", 3);
}

void    rrb(t_list **s, int i)
{
    t_list *temp2;
    t_list *temp1;

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
	if(i == 1)
		write(1, "rrb\n", 4);
}

void rrr(t_list **a, t_list **b)
{
    rra(a, 0);
    rrb(b, 0);
	write(1,"rrr\n", 4);
}

void    pa(t_list **a, t_list **b)
{
    t_list	*tmp;

	tmp = *b;
	if (tmp)
	{
		*b = tmp->next;
		tmp->next = *a;
		*a = tmp;
	}
	write(1,"pa\n", 3);
}

void pb(t_list **a, t_list **b)
{
    t_list	*tmp;

	tmp = *a;
	if (tmp)
	{
		*a = tmp->next;
		tmp->next = *b;
		*b = tmp;
	}
	write(1,"pb\n", 3);
}

// int main()
// {
//     t_list *lst;
//     t_list *klt;

//     lst = ft_lstnew("a1");
//     lst->next = ft_lstnew("a2");
//     lst->next->next = ft_lstnew("a3");
//     klt = ft_lstnew("k1");
//     klt->next = ft_lstnew("k2");
//     klt->next->next = ft_lstnew("k3");
//     klt = pb(&lst, &klt);
//     printf("%s\n",lst->content);
//     printf("%s\n",lst->next->content);
//     printf("%s\n",klt->content);
//     printf("%s\n",klt->next->content);
//     printf("%s\n",klt->next->next->content);
//     printf("%s\n",klt->next->next->next->content);
//     // printf("%s\n",klt->next->next->content);
// }