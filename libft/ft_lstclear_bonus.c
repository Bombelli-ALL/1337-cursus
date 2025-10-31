/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerradi <alerradi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 16:31:47 by alerradi          #+#    #+#             */
/*   Updated: 2025/10/30 14:01:27 by alerradi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*hold;
	t_list	*tmp;

	if (!lst || !del)
		return ;
	hold = *lst;
	while (hold != NULL)
	{
		tmp = hold;
		hold = hold->next;
		del(tmp->content);
		free(tmp);
	}
	*lst = NULL;
}
