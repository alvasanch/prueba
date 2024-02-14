/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvasanc <alvasanc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 11:13:15 by alvasanc          #+#    #+#             */
/*   Updated: 2023/10/11 11:31:11 by alvasanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int		size;
	t_list	*aux_node;

	if (!lst)
		return (0);
	size = 1;
	aux_node = lst;
	while (aux_node->next)
	{
		aux_node = aux_node->next;
		size++;
	}
	return (size);
}
