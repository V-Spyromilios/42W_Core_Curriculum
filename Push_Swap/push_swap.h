/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: espyromi <espyromi@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/24 20:48:19 by espyromi          #+#    #+#             */
/*   Updated: 2021/11/05 19:48:03 by espyromi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdlib.h>
# include <unistd.h> 
# include <stdio.h>

int		*take_arg(int argc, char *arg[]);
void	swap(int *a, int *b);
int		*copy(int *arr, int len);
int		*bbsort(int *arr, int len);
void	sort_them(int *before, int *after, int *len);
int		ft_atoi(const char *str);
void	error_exit(int *poi);
void	move_all_up(int *arr, int len);
void	move_all_down(int *stack, int len);
int		check_duplicate(int *arr);
void	check_input(int *arr, int len);
void	sa(int *stack);
void	sb(int *stack);
void	ss(int *stack_a, int *stack_b);
void	ra(int *stack, int len);
void	rb(int *stack, int len);
int		pa(int *stack_a, int *stack_b, int *len);
int		pb(int *stack_a, int *stack_b, int *len);
void	rrb(int *stack, int len);
void	rra(int *stack, int len);
void	rrr(int *stack_a, int *stack_b, int len);
void	rr(int *stack_a, int *stack_b, int len);
int		check_if_sorted(int *arr, int length);
void	hardcode_3(int *arr, int len);
int		hardcode_4(int *stack_a, int *stack_b, int *length);
void	hardcode_5(int *stack_a, int *stack_b, int *length);
void	bring_min_up(int *arr, int len);
void	bring_sec_min_up(int *stack, int len);
void	send_sec_min_up(int pos, int *arr, int len);
void	sort(int *indexes, int *len, int *stack_b);
void	call_rra(int *indexes, int times, int len);
void	call_ra(int *indexes, int times, int len);
void	bring_them_back(int *indexes, int *stack_b, int *length);
int		find_min_pos(int *stack, int length);
void	check_two(int *arr);

#endif
