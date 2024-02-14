/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvasanc <alvasanc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 10:09:14 by alvasanc          #+#    #+#             */
/*   Updated: 2023/10/13 10:15:18 by alvasanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*aux_lst;

	aux_lst = *lst;
	while (*lst)
	{
		aux_lst = aux_lst->next;
		ft_lstdelone(*lst, del);
		*lst = aux_lst;
	}
}
