/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jholterh <jholterh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 12:43:22 by jholterh          #+#    #+#             */
/*   Updated: 2025/02/04 15:51:14 by jholterh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **head, t_list *new)
{
	new->next = *head;
	*head = new;
}

void	ft_lstadd_front2(t_list2 **head, t_list2 **tail, t_list2 *new)
{
	new->next = *head;
	if (*head != NULL)
		(*head)->prev = new;
	else
		*tail = new;
	*head = new;
}
