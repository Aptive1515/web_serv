/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif_arg.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aptive <aptive@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 19:19:35 by aptive            #+#    #+#             */
/*   Updated: 2023/03/07 19:19:37 by aptive           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/web_serv.hpp"

void check_arg(int argc, char ** argv)
{
	if (argc != 2)
		throw std::string("Error : Wrong number of arguments !\n");
	(void)argv;
}
