/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aptive <aptive@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 18:15:00 by aptive            #+#    #+#             */
/*   Updated: 2023/03/08 16:09:39 by aptive           ###   ########.fr       */
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


		// Créer un socket TCP/IP
		int sockfd = socket(AF_INET, SOCK_STREAM, 0);
		if (sockfd == -1)
			throw std::string("Error : Error during cration of the socket !\n");

		std::cout << "No problems" << std::endl;
	}
	catch(const std::string except)
	{
		std::cout << except;
	}
	return 0;
}
