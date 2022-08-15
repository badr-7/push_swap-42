/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-hous <mel-hous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 08:46:43 by mel-hous          #+#    #+#             */
/*   Updated: 2022/06/30 10:30:57 by mel-hous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

char	*get_line(int fd)
{
	char	line[4];
	int		i;

	i = 0;
	ft_bzero(line, 4);
	while (read(fd, line + (i), 1) > 0)
	{
		if (line[i] == '\n')
			break ;
		i++;
	}
	if (!line[0])
		return (NULL);
	return (ft_strdup(line));
}

void	check_op(t_list **a, t_list **b, char *s)
{
	if (ft_strcmp(s, "sa\n") == 0)
		sa(a, 0);
	else if (ft_strcmp(s, "ra\n") == 0)
		ra(a, 0);
	else if (ft_strcmp(s, "rb\n") == 0)
		rb(b, 0);
	else if (ft_strcmp(s, "pa\n") == 0)
		pa(a, b, 0);
	else if (ft_strcmp(s, "pb\n") == 0)
		pb(a, b, 0);
	else if (ft_strcmp(s, "rr\n") == 0)
		rr(a, b, 0);
	else if (ft_strcmp(s, "rrr\n") == 0)
		rrr(a, b, 0);
	else if (ft_strcmp(s, "rra\n") == 0)
		rra(a, 0);
	else if (ft_strcmp(s, "rrb\n") == 0)
		rrb(b, 0);
	else
		exit (write(2, "ERROR\n", 6));
}

void	ft_rdout(t_list **a, t_list **b)
{
	char	*line;

	line = get_line(0);
	while (line)
	{
		check_op(a, b, line);
		free(line);
		line = get_line(0);
	}
}

void	sort_a(t_list *a)
{
	while (a->next)
	{
		if (a->content >= a->next->content)
		{
			write(1, "KO\n", 3);
			exit(1);
		}
		a = a->next;
	}
	write(1, "OK\n", 3);
}

int	main(int ac, char **av)
{
	t_list	*stack_a;
	t_list	*stack_b;
	int		i;
	int		j;
	char	**s;

	if (ac < 2)
		return (0);
	stack_a = NULL;
	stack_b = NULL;
	i = 1;
	j = 0;
	s = malloc(sizeof(char *) * ac);
	while (av[i] != NULL)
	{
		check_alpha(av[i]);
		s[j++] = ft_strdup(av[i++]);
	}
	s[j] = NULL;
	creat_stack(s, &stack_a);
	ft_rdout(&stack_a, &stack_b);
	sort_a(stack_a);
	ft_lstclear(&stack_a);
	ft_free(s);
	return (0);
}
