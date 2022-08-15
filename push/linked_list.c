/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-hous <mel-hous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 09:37:04 by mel-hous          #+#    #+#             */
/*   Updated: 2022/06/28 10:21:02 by mel-hous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*p;

	if (!*lst)
	{
		*lst = new;
		return ;
	}
	p = ft_lstlast(*lst);
	p->next = new;
}

void	ft_lstdelone(t_list *lst)
{
	if (!lst)
		return ;
	free(lst);
}

t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return (0);
	while (!(lst->next == NULL))
		lst = lst->next;
	return (lst);
}

t_list	*ft_lstnew(int content)
{
	t_list	*s;

	s = (t_list *)malloc(sizeof(t_list));
	if (s == NULL)
		return (NULL);
	s->content = content;
	s->next = NULL;
	return (s);
}

int	ft_lstsize(t_list *lst)
{
	int	i;

	i = 0;
	while (lst)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}
