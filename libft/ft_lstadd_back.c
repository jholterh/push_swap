/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jholterh <jholterh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 12:45:15 by jholterh          #+#    #+#             */
/*   Updated: 2025/02/04 15:58:34 by jholterh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **head, t_list *new)
{
	if (!*head)
		ft_lstadd_front(head, new);
	else
		ft_lstlast(*head)->next = new;
}

void	ft_lstadd_back2(t_list2 **head, t_list2 **tail, t_list2 *new)
{
	if (!*head)
		ft_lstadd_front2(head, tail, new);
	else
	{
		new->prev = *tail;
		(*tail)->next = new;
		*tail = new;
	}
}
