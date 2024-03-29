/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-hous <mel-hous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 14:20:42 by mel-hous          #+#    #+#             */
/*   Updated: 2022/06/28 09:39:12 by mel-hous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	char	**s;
	int		i;
	int		j;
	t_list	*stack_a;
	t_list	*stack_b;

	stack_b = NULL;
	stack_a = NULL;
	if (ac < 2)
		return (0);
	i = 1;
	j = 0;
	s = malloc(sizeof(char *) * ac);
	while (av[i] != NULL)
	{
		check_alpha(av[i]);
		s[j++] = ft_strdup(av[i++]);
	}
	s[j] = NULL;
	starting(&stack_a, s);
	ft_pushb(&stack_a, &stack_b);
	ft_pusha(&stack_a, &stack_b);
	ft_lstclear(&stack_a);
	ft_free(s);
	return (0);
}
