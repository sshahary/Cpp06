/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshahary <sshahary@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 15:53:42 by sshahary          #+#    #+#             */
/*   Updated: 2024/08/03 15:57:36 by sshahary         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Identification.hpp"

int main()
{
	Base* base = generate();
	if (base)
	{
		std::cout << "Identify by pointer: ";
		identify(base);

		std::cout << "Identify by reference: ";
		identify(*base);

		delete base;
	}
	else
		std::cout << "Failed to generate Base object." << std::endl;

	return 0;
}