/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-hous <mel-hous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 14:20:48 by mel-hous          #+#    #+#             */
/*   Updated: 2022/06/18 13:24:15 by mel-hous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void ft_indexion(t_list **stack)
{
    t_list *tmp;
    t_list *tmp2;
    t_list *a;
    
    tmp = *stack;
    while(tmp != NULL)
    {
        if (tmp->content != NULL)
        {
            tmp2 = tmp;
            a->content = tmp2->content;
            a->index = 1;
            while (tmp2 != NULL)
            {
                if(a->content > tmp2->content)
                    a->index++;
                tmp2 = tmp2->next;
            }
            
        }
        
    }
}