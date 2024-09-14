/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_linked_list_manager.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabrifer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 12:40:57 by sabrifer          #+#    #+#             */
/*   Updated: 2024/09/14 12:46:24 by sabrifer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

t_coins	*create_node(void *data)
{
	t_coins	*coin;

	coin = (t_coins *)malloc(sizeof(t_coins));
	if (!coin)
		return (NULL);
	coin -> data = data;
	coin -> next = NULL;
	return (coin);
}

void	add_node_back(t_coins **coin, t_coins *new_node)
{
	t_coins	*ptr;

	ptr = NULL;
	if (!*coin)
		*coin = new_node;
	else
	{
		ptr = *coin;
		while (ptr -> next != NULL)
			ptr = ptr -> next;
		ptr -> next = new_node;
	}
}

void	free_lst(t_coins *node)
{
	if (!node)
		return ;
	free_lst(node -> next);
	free(node);
}

void	ft_lstclear(t_coins **coin)
{
	if (!coin || !*coin)
		return ;
	free_lst(*coin);
	*coin = NULL;
}
