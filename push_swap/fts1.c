/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fts1.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-hous <mel-hous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 15:49:30 by mel-hous          #+#    #+#             */
/*   Updated: 2022/06/21 13:59:32 by mel-hous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

int has_false(t_list *stack_a)
{
    while(stack_a)
    {
        if(stack_a->keep == false)
            return (true);
        stack_a = stack_a->next;
    }
    return (false);
}

int indexof(t_list *stack, int n)
{
    int i;

    i = 0;
    while(stack)
    {
        if(stack->content == n)
            return (i);
        stack = stack->next;
        i++;
    }
    return (-1);
}

void ft_pushb(t_list **stack_a, t_list **stack_b)
{
    int i;
    t_list  *tmp;
    
    while(!has_false(*stack_a))
    {
        tmp = *stack_a;
        while (tmp->keep)
            tmp = tmp->next;
        if (indexof(*stack_a, tmp->content) <= (ft_lstsize(*stack_a) / 2))
            while ((*stack_a)->keep)
                ra(stack_a);
        else
            while ((*stack_a)->keep)
               rra(stack_a);
        *stack_b = pb(stack_a, stack_b);
    }
}