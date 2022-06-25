/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_a.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-hous <mel-hous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 13:37:07 by mel-hous          #+#    #+#             */
/*   Updated: 2022/06/25 10:59:25 by mel-hous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list *ft_find(t_list *s, int index)
{
    while (s)
    {
        if (s->index == index)
            return (s);
        s = s->next;
    }
    return (NULL);
}

t_list *ft_find_min_gt(t_list **s, int index)
{
    t_list  *stack;
    t_list  *result;

    stack = *s;
    result = NULL;
    while (!result && stack)
    {
        if (stack->index > index)
            result = stack;
        stack = stack->next;
    }
    while (stack)
    {
        if (stack->index > index && stack->index < result->index)
            result = stack;
        stack = stack->next;
    }
    return(result);
}

int ft_diff(int a, int b)
{
    if(a > b)
        return(a);
    return(b);
}

void ft_atleast1(t_list **a, t_list **b, t_list *elma, t_list *elmb)
{
    // printf("%d  %d", elma->content, elmb->content);
    while (*a != elma && *b != elmb)
        rr(a, b);
    
}
void ft_atleast2(t_list **a, t_list **b, t_list *elma, t_list *elmb)
{
    while (*a != elma && *b != elmb)
        rrr(a, b);
    
}

void ft_rotation(t_list **stack, t_list *elem, int i)
{
    if(i == 1)
        while (*stack != elem)
            ra(stack, 1);
    else
        while (*stack != elem)
            rb(stack, 1);
}

void ft_rrotation(t_list **stack, t_list *elem, int i)
{
    if(i == 1)
        while (*stack != elem)
            rra(stack, 1);
    else
        while (*stack != elem)
            rrb(stack, 1);
}

void ft_movment(t_list **stack_a, t_list **stack_b, t_list *elem_b)
{
    int rotation_a;
    int rotation_b;
    int rev_rotation_a;
    int rev_rotation_b;
    t_list *elem_a;

    elem_a = ft_find_min_gt(stack_a, elem_b->index);
    rotation_b = ft_pos(*stack_b, elem_b->content);
    rotation_a = ft_pos(*stack_a, elem_a->content);
    rev_rotation_a =  ft_lstsize(*stack_a) - rotation_a;
    rev_rotation_b = ft_lstsize(*stack_b) - rotation_b;
    
    if(rotation_a <= rev_rotation_a && rotation_b <= rev_rotation_b)
        ft_atleast1(stack_a, stack_b, elem_a, elem_b);
    if(rotation_a > rev_rotation_a && rotation_b > rev_rotation_b)
        ft_atleast2(stack_a, stack_b, elem_a, elem_b);
    if(rotation_a <= rev_rotation_a)
        ft_rotation(stack_a, elem_a, 1);
    else
        ft_rrotation(stack_a, elem_a, 1);
    if(rotation_b <= rev_rotation_b)
        ft_rotation(stack_b, elem_b, 0);
    else
        ft_rrotation(stack_b, elem_b, 0); 
}

int ft_move(t_list **a, t_list **b, t_list *elem_b)
{
    int rotation_a;
    int rotation_b;
    int rev_rotation_a;
    int rev_rotation_b;
    t_list *elem_a;

    elem_a = ft_find_min_gt(a, elem_b->index);
    rotation_b = ft_pos(*b, elem_b->content);
    rotation_a = ft_pos(*a, elem_a->content);
    rev_rotation_a =  ft_lstsize(*a) - rotation_a;
    rev_rotation_b = ft_lstsize(*b) - rotation_b;
    if(rotation_a <= rev_rotation_a && rotation_b <= rev_rotation_b)
        return(ft_diff(rotation_a, rotation_b));
    if(rotation_a > rev_rotation_a && rotation_b > rev_rotation_b)
        return(ft_diff(rev_rotation_a, rev_rotation_b));
    if(rotation_a <= rev_rotation_a && rotation_b > rev_rotation_b)
        return(rotation_a + rev_rotation_b);
    return(rev_rotation_a + rotation_b);
}

void    align_a(t_list **stack_a)
{
    t_list  *elem;

    elem = ft_find(*stack_a, 0);
    if (ft_pos(*stack_a, elem->content) <= ft_lstsize(*stack_a) / 2)
        ft_rotation(stack_a, elem, 1);
    else
        ft_rrotation(stack_a, elem, 1);
}

void ft_pusha(t_list **stack_a, t_list **stack_b)
{
    t_list *tmp;
    t_list *best_elem;
    int mvt;
    int best_mvt;
    
    while(*stack_b)
    {
        tmp = *stack_b;
        best_mvt = 0;
        best_elem = NULL;
        while(tmp)
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
        pa(stack_a, stack_b);
    }
    align_a(stack_a);
}