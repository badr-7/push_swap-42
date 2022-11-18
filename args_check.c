/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-hous <mel-hous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 15:33:52 by mel-hous          #+#    #+#             */
/*   Updated: 2022/06/30 08:29:45 by mel-hous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_alpha(char *str)
{
	int	i;

	i = 0;
	if ((str[i] == '+' || str[i] == '-') && str[i + 1] == '\0')
	{
		write(2, "Error\n", 6);
		exit (1);
	}
	else if ((str[i] == '+' || str[i] == '-') && str[i + 1] != '\0')
		i++;
	while (str[i] != '\0')
	{
		if (str[i] == '+' || str[i] == '-')
		{
			if (str[i - 1] == ' ' && str[i + 1] != ' ')
				i++;
		}
		if ((str[i] >= 58 && str[i] <= 127) || (str[i] >= 33 && str[i] <= 47))
		{
			write(2, "Error\n", 6);
			exit (1);
		}
		i++;
	}
}

void	ft_free(char **s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		free(s[i]);
		i++;
	}
	free(s);
}

void	ft_find_double(t_list *s, int a)
{
	t_list	*tmp;

	tmp = s;
	while (tmp != NULL)
	{
		if (tmp->content == a)
		{
			write(1, "ERROR\n", 6);
			exit(1);
		}
		tmp = tmp->next;
	}
}

void	creat_stack(char **s, t_list **stack_a)
{
	char	**tmp;
	int		i;
	int		j;

	i = 0;
	while (s[i])
	{
		j = 0;
		tmp = ft_split(s[i], ' ');
		if (tmp[0] == NULL)
			exit (write(1, "ERROR\n", 6));
		while (tmp[j] != NULL)
		{
			if (!*stack_a)
				*stack_a = ft_lstnew(ft_atoi(tmp[j]));
			else
			{
				ft_find_double(*stack_a, ft_atoi(tmp[j]));
				ft_lstadd_back(stack_a, ft_lstnew(ft_atoi(tmp[j])));
			}
			j++;
		}
		ft_free(tmp);
		i++;
	}
}
