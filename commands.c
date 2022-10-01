/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mclerico <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/01 19:23:40 by mclerico          #+#    #+#             */
/*   Updated: 2021/10/14 19:24:13 by mclerico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_swap(t_list **stack, char *str)
{
	t_list	*first;
	t_list	*second;
	t_list	*third;

	first = *stack;
	second = (*stack)->next;
	third = second->next;
	if (!first || !second)
		return (-1);
	ft_lstadd_front(stack, second);
	first->next = third;
	write(1, str, 3);
	return (1);
}

int	ft_push(t_list **dest, t_list **source, char *str)
{
	t_list	*new;
	t_list	*first;

	new = *source;
	first = (*source)->next;
	ft_lstadd_front(dest, new);
	*source = first;
	write(1, str, 3);
	return (1);
}

int	ft_rotate(t_list **list, char *str)
{
	t_list	*first;

	first = *list;
	ft_lstadd_back(list, first);
	*list = first->next;
	first->next = NULL;
	if (str)
		write(1, str, 3);
	return (1);
}

int	ft_rrotate(t_list **list, char *str)
{
	t_list	*last;
	t_list	*first;
	int		size;
	int		e;

	last = ft_lstlast(*list);
	first = *list;
	e = 0;
	size = ft_lstsize(*list);
	ft_lstadd_front(list, last);
	while (e < size - 2)
	{
		first = first->next;
		e++;
	}
	first->next = NULL;
	if (str)
		write(1, str, 4);
	return (1);
}
