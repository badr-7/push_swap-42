/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-hous <mel-hous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 13:11:00 by mel-hous          #+#    #+#             */
/*   Updated: 2022/06/18 10:03:13 by mel-hous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include<unistd.h>
#include<stdlib.h>
// #include"libft/libft.h"

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
    int index;
}					t_list;

char	*ft_strdup(const char *src);
char	**ft_split(const char *str, char c);
int	ft_atoi(const char	*str);
// linked liste functions
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstadd_front(t_list **lst, t_list *new);
void	ft_lstclear(t_list **lst, void (*del)(void *));
void	ft_lstiter(t_list *lst, void (*f)(void *));
t_list	*ft_lstlast(t_list *lst);
void	ft_lstdelone(t_list *lst);
t_list	*ft_lstnew(void *content);
int	ft_lstsize(t_list *lst);
// stack manupulation functions
t_list *sa(t_list *s);
t_list *sb(t_list *s);
void ss(t_list *a,t_list *b);
t_list *rra(t_list *s);
t_list *ra(t_list *s);
t_list *rb(t_list *s);
void rr(t_list *a, t_list *b);
t_list *rrb(t_list *s);
void rrr(t_list *a, t_list *b);
t_list *pa(t_list **a, t_list **b);
t_list *pb(t_list **a, t_list **b);




#endif