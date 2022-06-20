/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fts1.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-hous <mel-hous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 15:49:30 by mel-hous          #+#    #+#             */
/*   Updated: 2022/06/20 16:58:17 by mel-hous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

void ft_pushb(t_list **stack_a, t_list **stack_b)
{
    int i;

    i = ft_lstsize(*stack_a);
    while(i)
    {
        if((*stack_a)->a == false)
            pb(stack_a, stack_b);
         if((*stack_a)->a == true)
            *stack_a = ra(*stack_a);
        i--;
    }
}