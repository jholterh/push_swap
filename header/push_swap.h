/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jholterh <jholterh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 15:21:34 by jholterh          #+#    #+#             */
/*   Updated: 2025/02/11 16:59:16 by jholterh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"

typedef struct s_link
{
	t_list2 *head_a;
	t_list2 *tail_a;
	t_list2 *head_b;
	t_list2 *tail_b;
}	t_link;

// helper functions
void	del(int content);
void	print_int(int content);
void	free_str(char **str);

// checking the input
int     check_before(t_list2 *head, int number);
int	get_nums(char *str, t_list2 **head, t_list2 **tail);
int     check_str(char *str);
int     handle_numbers(int argc, char **argv, t_link *link);

// instructions
void    swap_a(t_link *link, int version);
void	swap_b(t_link *link, int version);
void    swap_s(t_link *link);
void    push_b(t_link *link);
void    push_a(t_link *link);
void    rotate_a(t_link *link, int version);
void 	rotate_b(t_link *link, int version);
void    rotate_r(t_link *link);
void    reverse_rotate_a(t_link *link, int version);
void	reverse_rotate_b(t_link *link, int version);
void    reverse_rotate_r(t_link *link);

// algo
void	sort_numbers(t_link *link);
# endif