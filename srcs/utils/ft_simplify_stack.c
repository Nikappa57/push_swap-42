/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_simplify_stack.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorenzogaudino <lorenzogaudino@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 18:24:33 by lorenzogaud       #+#    #+#             */
/*   Updated: 2023/03/23 23:35:49 by lorenzogaud      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_qs_swap(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

static int	ft_qs_partition(int *arr, int low, int high)
{
	int	pivot;
	int	i;
	int	j;

	pivot = arr[high];
	i = (low - 1);
	j = low;
	while (j <= high - 1)
	{
		if (arr[j] <= pivot)
			ft_qs_swap(&arr[++i], &arr[j]);
		j++;
	}
	ft_qs_swap(&arr[i + 1], &arr[high]);
	return (i + 1);
}

static void	ft_quicksort(int *arr, int low, int high)
{
	int	pi;

	if (low < high)
	{
		pi = ft_qs_partition(arr, low, high);
		ft_quicksort(arr, low, pi - 1);
		ft_quicksort(arr, pi + 1, high);
	}
}

static int	ft_arr_val_pos(int *arr, int len, int val)
{
	int	i;

	i = 0;
	while (i < len)
	{
		if (arr[i] == val)
			return (i);
		i++;
	}
	return (-1);
}

void	ft_simplify_stack(t_list **stack_a, int stack_a_len)
{
	int		*sorted_arr;
	t_list	*elm;

	elm = *stack_a;
	sorted_arr = ft_copy_stack(*stack_a, stack_a_len);
	ft_quicksort(sorted_arr, 0, stack_a_len - 1);
	while (elm)
	{
		elm->content = ft_arr_val_pos(
				sorted_arr, stack_a_len, elm->content);
		if (elm->content == -1)
		{
			free(sorted_arr);
			ft_print_error(stack_a, NULL);
		}
		elm = elm->next;
	}
	free(sorted_arr);
}
