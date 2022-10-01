/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mclerico <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 13:46:57 by mclerico          #+#    #+#             */
/*   Updated: 2021/10/29 17:45:22 by mclerico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
#include <stdlib.h>
#include "libft/libft.h"
int		ft_args(char *s, char c);
int 	ft_reps(int	*nums);
int		ft_atoicheck(const char *str);
int		ft_atoinum(const char *str);
int		ft_nparams(char **argv);
int		ft_swap(t_list **stack, char *str);
int		ft_push(t_list **dest, t_list **source, char *str);
int		ft_rotate(t_list **list, char *str);
int		ft_rrotate(t_list **list, char *str);
int		ft_get_max(t_list *list);
int		ft_min(int *num);
int		*ft_mapping(int *nums, int len);
int		ft_issorted(t_list *list);
int		ft_binsort(int num, int index);
void	ft_add(t_list **nums, int *new, int len);
void	ft_radix_sort(t_list **stacka, t_list **stackb);
void	ft_printstack(t_list *stack);
int		ft_tryrrotate(t_list **stack, int max, int flag, char *str);
int		ft_tryrotate(t_list **stack, int max, int flag, char *str);
void	ft_pushmaxb(t_list **stacka, t_list **stackb);
void    ft_sort2(t_list **stacka);
void	ft_sort3a(t_list **stacka);
void	ft_sort5(t_list **stacka, t_list **stackb);
int		ft_pushrank(t_list **stacka, t_list **stackb, int max);
void	ft_return_max(t_list **stackb);
void	ft_inchunk(t_list **stacka, t_list **stackb);
void	ft_insertion100(t_list **stacka, t_list **stacb);
int		ft_fstack(t_list **nums, char **argv, int argc, int n);
void    fill_stacka(t_list **stacka, t_list **stackb);
void    ft_inchunk(t_list **stacka, t_list **stackb);
#endif
