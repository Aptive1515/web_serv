/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   affichage.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aptive <aptive@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 19:23:07 by aptive            #+#    #+#             */
/*   Updated: 2023/03/07 19:23:10 by aptive           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/web_serv.hpp"

void affichage_list(std::list<std::string> list)
{
	int i = 0;
	for (std::list<std::string>::iterator it = list.begin(); it != list.end(); it++)
	{
		i++;
		std::cout << "list " << i << " : " << *it << std::endl;
	}
}
