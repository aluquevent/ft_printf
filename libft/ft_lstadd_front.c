/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aluque-v <aluque-v@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 16:16:16 by aluque-v          #+#    #+#             */
/*   Updated: 2025/01/18 16:16:18 by aluque-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

/*
*
*		Adds the element 'newlst' at the beginning of the list
*
*/

void	ft_lstadd_front(t_list **lst, t_list *newlst)
{
	if (!lst || !newlst)
		return ;
	newlst->next = *lst;
	*lst = newlst;
}
