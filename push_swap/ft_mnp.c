/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mnp.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-hous <mel-hous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 13:09:13 by mel-hous          #+#    #+#             */
/*   Updated: 2022/06/20 16:38:36 by mel-hous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

t_list *sa(t_list *s)
{
    if(ft_lstsize(s) > 1)
    {
        int temp;
        int index;
        
        temp = s->content;
        index = s->index;
    
        s->content = s->next->content;
        s->index = s->next->index;
        s->next->content = temp;
        s->next->index = index;
    }
    return(s);
}

t_list *sb(t_list *s)
{
    if(ft_lstsize(s) > 1)
    {
        int temp;
        int index;
        
        temp = s->content;
        index = s->index;
    
        s->content = s->next->content;
        s->index = s->next->index;
        s->next->content = temp;
        s->next->index = index;
    }
    return(s);
}

void ss(t_list *a,t_list *b)
{
    a = sa(a);
    b = sb(b);
}

t_list *rra(t_list *s)
{
    t_list *temp2;
    
    temp2 = ft_lstlast(s);
    temp2->next = s;
    s = temp2;
    return(temp2);
}
t_list *ra(t_list *s)
{
    t_list *temp2;
    t_list *temp;
    
    temp = s->next;
    temp2 = ft_lstlast(s);
    s->next = NULL;
    temp2->next = s;
    return(temp);
}

t_list *rb(t_list *s)
{
    t_list *temp2;
    t_list *temp;
    
    temp = s->next;
    temp2 = ft_lstlast(s);
    s->next = NULL;
    temp2->next = s;
    return(temp);
}

void rr(t_list *a, t_list *b)
{
    a = ra(a);
    b = rb(b);
}

t_list *rrb(t_list *s)
{
    t_list *temp2;
    
    temp2 = ft_lstlast(s);
    temp2->next = s;
    s = temp2;
    return(temp2);
}

void rrr(t_list *a, t_list *b)
{
    a = rra(a);
    b = rrb(b);
}

t_list *pa(t_list **a, t_list **b)
{
    t_list *temp;
    t_list *temp2;

    temp = ft_lstnew((*b)->content);
    temp->next = *a;
    temp2 = *b;
    *b = (*b)->next;
    ft_lstdelone(temp2);
    *a = temp;
    return(*a);
}

t_list *pb(t_list **a, t_list **b)
{
    t_list *temp;
    t_list *temp2;

    temp = ft_lstnew((*a)->content);
    temp->next = *b;
    temp2 = *a;
    *a = (*a)->next;
    ft_lstdelone(temp2);
    *b = temp;
    return(*b);
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