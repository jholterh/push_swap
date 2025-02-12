/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jholterh <jholterh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 17:12:10 by jholterh          #+#    #+#             */
/*   Updated: 2025/02/10 17:19:42 by jholterh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int check_before(t_list2 *head, int number) {
    t_list2 *tmp = head;
    while (tmp) {
        if (tmp->content == number)
            return 1;
        tmp = tmp->next;
    }
    return 0;
}

int get_nums(char *str, t_list2 **head, t_list2 **tail) {
    char **split = ft_split(str, ' ');
    if (!split)
        return 2;

    int i = 0;
    while (split[i]) {
        int num;
        if (ft_atoi(split[i], &num)) {
            free_str(split);
            return 3;
        }
        if (check_before(*head, num)) {
            free_str(split);
            return 1;
        }
        char *ptr = split[i];
        if (*ptr == '+' || *ptr == '-')
            ptr++;
        while (*ptr) {
            if (!ft_isdigit(*ptr)) {
                free_str(split);
                return 2;
            }
            ptr++;
        }
        t_list2 *new_node = ft_lstnew2(num);
        if (!new_node) {
            free_str(split);
            return 2;
        }
        ft_lstadd_back2(head, tail, new_node);
        i++;
    }
    free_str(split);
    return 0;
}

int check_str(char *str) {
    while (*str) {
        if (!ft_isdigit(*str) && !(*str == '+' || *str == '-' || *str == ' '))
            return 1;
        str++;
    }
    return 0;
}

int	handle_numbers(int argc, char **argv, t_link *link)
{
	int	i;
	int	back;

	i = 1;
	while (i < argc)
	{
		if (check_str(argv[i]))
		{
			ft_printf("Error: Invalid character in input '%s'\n", argv[i]);
			ft_lstclear2(&(link->head_a), &(link->tail_a));
			return (1);
		}
		back = get_nums(argv[i], &(link->head_a), &(link->tail_a));
		if (back != 0)
		{
			if (back == 3)
				ft_printf("Error: All numbers need to be integers\n");
			if (back == 2)
				ft_printf("Error: Failed to parse numbers from '%s'\n", argv[i]);
			if (back == 1)
				ft_printf("Error: Number occurs twice\n");
			ft_lstclear2(&(link->head_a), &(link->tail_a));
			return (1);
		}
		i++;
	}
	return (0);
}

