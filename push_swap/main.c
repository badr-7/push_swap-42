/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-hous <mel-hous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 14:20:42 by mel-hous          #+#    #+#             */
/*   Updated: 2022/06/25 11:05:09 by mel-hous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "push_swap.h"


void printList(t_list *n)
{
    while (n) {
        printf(" %d \n", n->index);
        n = n->next;
    }
}

void    print_stack(t_list *stack)
{
    while (stack)
    {
        printf("%d\n", stack->content);
        stack = stack->next;
    }
}

int main(int ac, char **av)
{
    char **s;
    int i;
    int j;
    t_list *stack_a;
    t_list *stack_b;

    if(ac < 2)
    {
        write(1, "ERROR\n", 6);
        exit(1);
    }
    i = 1;
    j = 0;
    s = malloc(sizeof(char *) * ac);
    while(av[i] != NULL)
    {
        check_alpha(av[i]);
        s[j++] = ft_strdup(av[i++]);
    }
    s[j] = NULL;
    i = 0;
    starting(&stack_a, s);
    ft_pushb(&stack_a, &stack_b);
    ft_pusha(&stack_a, &stack_b);
}
