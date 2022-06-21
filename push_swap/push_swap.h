/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-hous <mel-hous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 13:11:00 by mel-hous          #+#    #+#             */
/*   Updated: 2022/06/21 13:59:05 by mel-hous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include<unistd.h>
#include<stdlib.h>
#include<stdbool.h>
#include<stdio.h>
// #include"libft/libft.h"

typedef struct s_list
{
	int			content;
	struct s_list	*next;
    int index;
	bool keep;
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
t_list	*ft_lstnew(int content);
int	ft_lstsize(t_list *lst);
// stack manupulation functions
void sa(t_list **s);
void	sb(t_list **s);
void ss(t_list **a,t_list **b);
void rra(t_list **s);
void ra(t_list **s);
t_list *rb(t_list *s);
void rr(t_list *a, t_list *b);
void	rrb(t_list **s);
void rrr(t_list *a, t_list *b);
t_list *pa(t_list **a, t_list **b);
t_list *pb(t_list **a, t_list **b);
void ft_indexing(t_list **stack);
void greater_than(t_list **stack_a);
int	markup(t_list *lst);
void sa_stat(t_list *a);
void starting(t_list **s , char **a);
void ft_ft(char **s , t_list **stack_a);
void ft_find_double(t_list *s, int a);
void ft_free(char **s);
void check_alpha(char *str);
void ft_pushb(t_list **stack_a, t_list **stack_b);



#endif