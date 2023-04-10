/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdelauna <tdelauna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 18:15:00 by aptive            #+#    #+#             */
/*   Updated: 2023/04/10 14:44:18 by tdelauna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/web_serv.hpp"

int main(int argc, char ** argv)
{
	// std::list <std::pair<std::string, std::string> > list_conf;
	std::map <std::string, std::string> list_conf;
	int server_fd(-1);

	try
	{
		check_arg(argc, argv);
		list_conf = open_and_check_conf_file(argv[1]);
		affichage_list(list_conf);


		// Créer un socket TCP/IP -----------------------------------------------
		// AF_INET = famille d'adresses IPv4
		// SOCK_STREAM = type de socket orienté connexion
		// 0 = protocole par défaut
		server_fd = socket(AF_INET, SOCK_STREAM, 0);
		if (server_fd == -1)
			throw std::string("Error : Error during creation of the socket !\n");

		std::cout << "socket : " << server_fd << std::endl;



		// Configurer l'adresse et le port du serveur -----------------------------

		// Nous configurons ensuite l'adresse et le port du serveur en utilisant une structure sockaddr_in,
		// et nous lions le socket à cette adresse en utilisant la fonction bind()
		// Nous mettons ensuite le socket en mode écoute en utilisant la fonction listen()
		// avec une queue de connexion maximale de 10.

		sockaddr_in server_addr;
		std::memset(&server_addr, 0, sizeof(server_addr));
		server_addr.sin_family = AF_INET;
		server_addr.sin_port = htons(8080); // Utiliser le port 8080
		server_addr.sin_addr.s_addr = INADDR_ANY;

		// Lier le socket à l'adresse et au port du serveur
		if (bind(server_fd, (sockaddr*)&server_addr, sizeof(server_addr)) < 0)
			throw std::string("Error : Error during connection of the socket !\n");

		// Mettre le socket en mode écoute
		// Utiliser une queue de connexion maximale de 10
		if (listen(server_fd, 10) < 0)
			throw std::string("Error : Error listen of the socket !\n");


		// Accepter les connexions entrantes
		while (true) {
			sockaddr_in client_addr;
			socklen_t client_addr_len = sizeof(client_addr);
			int client_fd = accept(server_fd, (sockaddr*)&client_addr, &client_addr_len);

			if (client_fd < 0)
				throw std::string("Error : Error during acception of the entrance connexion !\n");

			// Gérer la connexion entrante
			std::string message = "HELLO WORLD !";
			send(client_fd, message.c_str(), message.length(), 0);

			// Fermer la connexion
			close(client_fd);
		}
		// Fermer le socket
		close(server_fd);

		std::cout << "No problems" << std::endl;
	}
	catch(const std::string except)
	{
		if (server_fd != -1)
			close(server_fd);
		std::cout << except;
	}
	return 0;
}
