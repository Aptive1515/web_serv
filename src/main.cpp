/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aptive <aptive@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 18:15:00 by aptive            #+#    #+#             */
/*   Updated: 2023/03/08 15:49:13 by aptive           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/web_serv.hpp"

int main(int argc, char ** argv)
{
	std::list <std::pair<std::string, std::string> > list_conf;

	try
	{
		check_arg(argc, argv);
		list_conf = open_and_check_conf_file(argv[1]);
		affichage_list(list_conf);


		std::cout << "No problems" << std::endl;
	}
	catch(const std::string except)
	{
		std::cout << except;
	}
	return 0;
}
