/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aptive <aptive@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 18:15:00 by aptive            #+#    #+#             */
/*   Updated: 2023/03/07 19:15:09 by aptive           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/web_serv.hpp"

void check_arg(int argc, char ** argv)
{
	if (argc != 2)
		throw std::string("Error : Wrong number of arguments !\n");
	(void)argv;
}

void affichage_list(std::list<std::string> list)
{
	int i = 0;
	for (std::list<std::string>::iterator it = list.begin(); it != list.end(); it++)
	{
		i++;
		std::cout << "list " << i << " : " << *it << std::endl;
	}
}

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

int main(int argc, char ** argv)
{
	std::list <std::string> list_conf;

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
