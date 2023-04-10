/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   web_serv.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdelauna <tdelauna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 18:14:43 by aptive            #+#    #+#             */
/*   Updated: 2023/04/10 14:20:46 by tdelauna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEB_SERV_HPP
# define WEB_SERV_HPP

# include <iostream>
# include <fstream>
# include <string>
# include <cstring>
# include <list>
# include <map>
# include <utility> // pour utiliser la paire (std::pair)
# include <sys/socket.h>
# include <netinet/in.h>
# include <arpa/inet.h>
# include <unistd.h>

// configurer la connexion. On l'appelle contexte d'adressage.
// struct sockaddr_in
// {
// 	short			sin_family;
// 	unsigned short	sin_port;
// 	struct in_addr	sin_addr;
// 	char			sin_zero[8];
// };


// +----------------------------------------------------------------------------+
//                                  AFFICHAGE                                   |
// +----------------------------------------------------------------------------+
void affichage_list(std::map<std::string, std::string> list);

// +----------------------------------------------------------------------------+
//                                  READ_FILE                                   |
// +----------------------------------------------------------------------------+
std::pair<std::string, std::string>	parse_to_pair (std::string str);
std::map<std::string, std::string>open_and_check_conf_file(std::string file);

// +----------------------------------------------------------------------------+
//                                  VERIF_ARG                                   |
// +----------------------------------------------------------------------------+
void						check_arg(int argc, char ** argv);

// +----------------------------------------------------------------------------+
//                                    END                                       |
// +----------------------------------------------------------------------------+

#endif
