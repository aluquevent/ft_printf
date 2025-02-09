/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aluque-v <aluque-v@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 16:15:54 by aluque-v          #+#    #+#             */
/*   Updated: 2025/01/18 16:15:57 by aluque-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

/*
*
*		Add the element 'newlst' at the end of the list.
*
*/

void	ft_lstadd_back(t_list **lst, t_list *newlst)
{
	if (!*lst)
		*lst = newlst;
	else
		ft_lstlast(*lst)->next = newlst;
}
