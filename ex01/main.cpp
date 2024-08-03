/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshahary <sshahary@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 00:29:24 by sshahary          #+#    #+#             */
/*   Updated: 2024/08/03 18:22:59 by sshahary         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Serializer.hpp"

int main()
{
	Data originalData;
	originalData.id = 42;
	originalData.name = "Test Data";
	originalData.value = 3.14f;

	std::cout << "Original Data Address: " << &originalData << std::endl;
	std::cout << "Original Data: id=" << originalData.id << ", name=" << originalData.name << ", value=" << originalData.value << std::endl;

	uintptr_t raw = Serializer::serialize(&originalData);
	Data* deserializedData = Serializer::deserialize(raw);

	std::cout << "Deserialized Data Address: " << deserializedData << std::endl;
	std::cout << "Deserialized Data: id=" << deserializedData->id << ", name=" << deserializedData->name << ", value=" << deserializedData->value << std::endl;

	if (&originalData == deserializedData)
	{
		std::cout << "Success: Deserialized data matches original data." << std::endl;
	}
	else
	{
		std::cout << "Error: Deserialized data does not match original data." << std::endl;
	}

	return 0;
}
