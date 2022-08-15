/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-hous <mel-hous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 13:11:00 by mel-hous          #+#    #+#             */
/*   Updated: 2022/06/28 09:28:50 by mel-hous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include<unistd.h>
# include<stdlib.h>
# include<stdbool.h>
# include<stdio.h>

typedef struct s_list
{
	int				content;
	struct s_list	*next;
	int				index;
	bool			keep;
}					t_list;

char	*ft_strdup(const char *src);
char	**ft_split(const char *str, char c);
int		ft_atoi(const char	*str);
// linked liste functions
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstadd_front(t_list **lst, t_list *new);
void	ft_lstiter(t_list *lst, void (*f)(void *));
t_list	*ft_lstlast(t_list *lst);
void	ft_lstdelone(t_list *lst);
t_list	*ft_lstnew(int content);
int		ft_lstsize(t_list *lst);
// stack manupulation functions
void	sa(t_list **s, int i);
void	sb(t_list **s);
void	ss(t_list **a, t_list **b);
void	rra(t_list **s, int i);
void	ra(t_list **s, int i);
void	rb(t_list **s, int i);
void	rr(t_list **a, t_list **b, int i);
void	rrb(t_list **s, int i);
void	rrr(t_list **a, t_list **b, int i);
void	pa(t_list **a, t_list **b, int i);
void	pb(t_list **a, t_list **b, int i);
void	ft_indexing(t_list **stack);
void	greater_than(t_list **stack_a);
int		markup(t_list *lst);
void	sa_stat(t_list **a);
void	starting(t_list **s, char **a);
void	creat_stack(char **s, t_list **stack_a);
void	ft_find_double(t_list *s, int a);
void	ft_free(char **s);
void	check_alpha(char *str);
void	ft_pushb(t_list **stack_a, t_list **stack_b);
int		ft_pos(t_list *stack, int n);
int		check_mvt(t_list **stack_a, t_list **stack_b);
void	ft_pusha(t_list **stack_a, t_list **stack_b);
int		ft_strcmp(const char *s1, const char *s2);
void	markup_reset(t_list *lst);
int		markup_at(t_list *lst, t_list *mh);
void	ft_bzero(void *s, size_t n);
t_list	*ft_find_min_gt(t_list **s, int index);
void	ft_atleast1(t_list **a, t_list **b, t_list *elma, t_list *elmb);
void	ft_atleast2(t_list **a, t_list **b, t_list *elma, t_list *elmb);
void	ft_rotation(t_list **stack, t_list *elem, int i);
void	ft_rrotation(t_list **stack, t_list *elem, int i);
void	align_a(t_list **stack_a);
t_list	*ft_find(t_list *s, int index);
void	ft_lstclear(t_list **lst);

#endif