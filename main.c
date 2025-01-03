/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: istripol <istripol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 12:19:18 by istripol          #+#    #+#             */
/*   Updated: 2024/09/14 12:19:19 by istripol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char *av[])
{
	if (ac <= 1)
		return (0);
	else
	{
		if (ac == 2 && ft_check_arg(*av[1]))
			ft_init_stack(*av[1]);
		else if (ac > 2)
		{

		}
		else
		{
			write(2, "Error\n", 6);	
			return (0);
		}
	}
}