/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwahbi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 19:19:54 by mwahbi            #+#    #+#             */
/*   Updated: 2021/11/05 13:47:43 by mwahbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*newelm;
	t_list	*newlst;

	newlst = 0;
	while (lst)
	{
		newelm = ft_lstnew(f(lst->content));
		if (newelm == 0)
		{
			ft_lstclear(&newlst, del);
			break ;
		}
		else
			ft_lstadd_back(&newlst, newelm);
		lst = lst->next;
	}
	return (newlst);
}
