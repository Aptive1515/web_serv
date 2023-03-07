/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aptive <aptive@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 19:19:55 by aptive            #+#    #+#             */
/*   Updated: 2023/03/07 19:25:19 by aptive           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/web_serv.hpp"

std::list<std::string> open_and_check_conf_file(std::string file)
{
	std::ifstream	flux(file.c_str());
	std::list <std::string> list_conf;
	std::string line;

	if (!flux.is_open())
		throw std::string("Error : Unable to open the file !\n");
	while (!flux.eof() && getline(flux, line))
		list_conf.push_back(line);
	return list_conf;
}
