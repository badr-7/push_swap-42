/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-hous <mel-hous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 14:20:42 by mel-hous          #+#    #+#             */
/*   Updated: 2022/06/18 11:04:57 by mel-hous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "push_swap.h"

void check_alpha(char *str)
{
    int i;

    i = 0;
    if (str[i] == '+' || str[i] == '-')
        i++;
    while(str[i] != '\0')
    {
        if (str[i] == '+' || str[i] == '-')
        {
            if(str[i - 1] == ' ' && str[i + 1] != ' ')
                i++;
        }
        if (str[i] >= 58 && str[i] <= 127 || str[i] >= 33 && str[i] <= 47)
        {
            write(2, "forbiden character\n", 19);
            break;
        }
        i++;
    }
}

void ft_free(char **s)
{
    int i;

    i = 0;
    while(s[i])
    {
        free(s[i]);
        i++;
    }
    free(s);
}

void ft_find_double(t_list *s, int a)
{
    t_list *tmp = s;
    while(tmp != NULL)
    {
        if (tmp->content == a)
        {
            write(1, "ERROR\n", 6);
            exit(1);
        }
        tmp = tmp->next;
    }
}

void ft_ft(char **s , t_list **stack_a)
{
    char **tmp;
    int i;
    int j;
    t_list *temp;

    j = 0;
    i = 0;
    while(s[i])
    {
        tmp = ft_split(s[i], ' ');
        while(tmp[j] != NULL)
        {
            if (!*stack_a)
                *stack_a = ft_lstnew(ft_atoi(tmp[j]));
            else
            {
                ft_find_double(*stack_a, ft_atoi(tmp[j]));
                ft_lstadd_front(stack_a, ft_lstnew(ft_atoi(tmp[j])));
            }
            j++;
        }
        j = 0;
        ft_free(tmp);
        i++;
    }
    printf("%d\n",(*stack_a)->content);
    printf("%d\n",(*stack_a)->next->content);
    printf("%d\n",(*stack_a)->next->next->content);
    printf("%d\n",(*stack_a)->next->next->next->content);
    printf("%d\n",(*stack_a)->next->next->next->next->content);
    printf("%d\n",(*stack_a)->next->next->next->next->next->content);
}

int main(int ac, char **av)
{
    char **s;
    int i;
    int j;
    t_list *stack_a;

    i = 1;
    j = 0;
    s = malloc(sizeof(char *) * ac);
    while(av[i] != NULL)
    {
        check_alpha(av[i]);
        s[j++] = ft_strdup(av[i++]);
    }
    s[j] = NULL;
    // printf("%s" , temp);
    // s = ft_split(temp, ' ');
    i = 0;
    ft_ft(s, &stack_a);
    // printf("%s\n",stack_a->content);
    // printf("%s\n",stack_a->next->content);
    // printf("%s\n",stack_a->next->next->content);
    // printf("%s\n",stack_a->next->next->next->content);
    // printf("%s\n",stack_a->next->next->next->next->content);
    // printf("%s\n",stack_a->next->next->next->next->next->content);

}
