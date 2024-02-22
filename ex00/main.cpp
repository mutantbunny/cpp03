/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmachado <gmachado@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 22:26:43 by gmachado          #+#    #+#             */
/*   Updated: 2024/02/21 22:36:45 by gmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main(void)
{
	std::cout << "Test ClapTrap class:\n\n";

	std::cout << "-> Test constructors:\n\n";

	std::cout << "--> Create ClapTrap object using default constructor:\n";
	ClapTrap no_name;
	std::cout << "--> Created " << no_name << ".\n" << std::endl;

	std::cout << "--> Create ClapTrap object using constructor with "
		"name parameter:\n";
	ClapTrap john("John");
	std::cout << "--> Created " << john << ".\n" << std::endl;

	std::cout << "--> Create ClapTrap object using copy constructor to "
		"clone ClapTrap Unnamed:\n";
	ClapTrap john_clone(no_name);
	std::cout << "--> Created " << john_clone << "." << std::endl;

	std::cout << "\n--> Use assignment operator to copy attributes from "
		"ClapTrap John:\n";
	john_clone = john;
	std::cout << "--> Status of (now) John's clone: " << john_clone << "."
		<< std::endl;

	std::cout << "\n-> Test functionality:\n";

	std::cout << "\n--> Make John attack target Ted, take damage and "
		"be repaired until energy points are exhausted:\n";

	for (int i = 1; john.get_ep() > 0 && john.get_hp() > 0; ++i)
	{
		std::cout << "\n---> Round " << i << ":\n";
		john.attack("Ted");
		john.takeDamage(1);
		john.beRepaired(1);
		std::cout << "Status at the end of the round: " << john << ".\n";
	}

	std::cout << "\n---> Make John attack target Ted, take damage and "
		"be repaired again (no energy points left):\n";
	john.attack("Ted");
	john.takeDamage(1);
	john.beRepaired(1);
	std::cout << "Final status: " << john << "\n";

	std::cout << "\n--> Make John's clone attack target Jack, take damage "
		"and be repaired until hit points are exhausted:\n";

	for (int i = 1; john_clone.get_ep() > 0 && john_clone.get_hp() > 0;
		++i)
	{
		std::cout << "\n---> Round " << i << ":\n";
		john_clone.attack("Jack");
		john_clone.takeDamage(4);
		john_clone.beRepaired(1);
		std::cout << "Status at the end of the round: " << john_clone
			<< "\n";
	}

	std::cout << "\n--> Make John's clone attack target Jack, take damage "
		"and be repaired again (no hit points left):\n";
	john_clone.attack("Jack");
	john_clone.takeDamage(1);
	john_clone.beRepaired(1);
	std::cout << "Final status: " << john_clone << "\n";

	std::cout << "\n-> End of ClapTrap tests, ClapTrap object destructors "
		"should be called:\n";

	return 0;
}