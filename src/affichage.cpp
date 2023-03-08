/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   affichage.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aptive <aptive@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 19:23:07 by aptive            #+#    #+#             */
/*   Updated: 2023/03/08 15:48:55 by aptive           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/web_serv.hpp"

void affichage_list(std::list <std::pair<std::string, std::string> > list)
{
	int i = 0;
	for (std::list<std::pair<std::string, std::string> >::iterator it = list.begin(); it != list.end(); it++)
	{
		i++;
		std::cout << "list " << i << " < " << it->first << ", " << it->second << " >"<< std::endl;
	}
}
