/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jholterh <jholterh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 11:51:29 by jholterh          #+#    #+#             */
/*   Updated: 2025/02/11 16:03:50 by jholterh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "push_swap.h"

int main(int argc, char *argv[]) {
    t_link *link = (t_link *)malloc(sizeof(t_link));
    if (!link)
        return 1;  // Exit with error if memory allocation fails

    link->head_a = NULL;
    link->tail_a = NULL;
    link->head_b = NULL;
    link->tail_b = NULL;

    if (argc < 2) {
        ft_printf("Usage: %s <numbers>\n", argv[0]);
        free(link);
        return 1;
    }

    if (handle_numbers(argc, argv, link) != 0) {
        ft_lstclear2(&(link->head_a), &(link->tail_a));
        free(link);
        return 1;
    }

    sort_numbers(link);

    //ft_lstiter2(link->head_a, print_int);
    ft_lstclear2(&(link->head_a), &(link->tail_a));
    //ft_printf("\n");
    //ft_lstiter2(link->head_b, print_int);
    ft_lstclear2(&(link->head_b), &(link->tail_b));
    free(link);
    return 0;
}