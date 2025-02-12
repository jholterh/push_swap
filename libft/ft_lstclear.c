/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jholterh <jholterh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 12:46:16 by jholterh          #+#    #+#             */
/*   Updated: 2025/02/10 15:46:13 by jholterh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **head, void (*del)(void *))
{
	t_list	*tmp;

	while (*head)
	{
		tmp = (*head)->next;
		ft_lstdelone(*head, del);
		*head = tmp;
	}
	*head = NULL;
}

void ft_lstclear2(t_list2 **head, t_list2 **tail) {
    if (!head)
        return;

    t_list2 *current = *head;
    t_list2 *next;

    while (current) {
        next = current->next;
        ft_lstdelone2(current);
        current = next;
    }

    *head = NULL;
    *tail = NULL;
}
