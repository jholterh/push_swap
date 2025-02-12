/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jholterh <jholterh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 12:44:14 by jholterh          #+#    #+#             */
/*   Updated: 2025/02/04 16:18:57 by jholterh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *head)
{
	int		counter;
	t_list	*tmp;

	tmp = head;
	counter = 0;
	while (tmp)
	{
		counter++;
		tmp = tmp->next;
	}
	return (counter);
}

int	ft_lstsize2(t_list2 *head)
{
	int	counter;
	t_list2	*tmp;

	tmp = head;
	counter = 0;
	while (tmp)
	{
		counter++;
		tmp = tmp->next;
	}
	return (counter);
}
