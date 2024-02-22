/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmachado <gmachado@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 22:26:43 by gmachado          #+#    #+#             */
/*   Updated: 2024/02/21 22:52:06 by gmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

int main(void)
{
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
			john.takeDamage(5);
			john.beRepaired(1);
			std::cout << "Status at the end of the round: " << john << "\n";
		}

		std::cout << "\n---> Make John attack target Ted, take damage and "
			"be repaired again (no energy points left):\n";
		john.attack("Ted");
		john.takeDamage(5);
		john.beRepaired(1);
		std::cout << "Final status: " << john << "\n";

		std::cout << "\n--> Make John's clone attack target Jack, take damage "
			"and be repaired until hit points are exhausted:\n";

		for (int i = 1; john_clone.get_ep() > 0 && john_clone.get_hp() > 0;
			++i)
		{
			std::cout << "\n---> Round " << i << ":\n";
			john_clone.attack("Jack");
			john_clone.takeDamage(10);
			john_clone.beRepaired(1);
			std::cout << "Status at the end of the round: " << john_clone
				<< "\n";
		}

		std::cout << "\n--> Make John's clone attack target Jack, take damage "
			"and be repaired again (no hit points left):\n";
		john_clone.attack("Jack");
		john_clone.takeDamage(5);
		john_clone.beRepaired(1);
		std::cout << "Final status: " << john_clone << "\n";

		std::cout << "\n-> End of ClapTrap tests, ClapTrap object destructors "
			"should be called:\n";
	}

	{
		std::cout << "\nTest FragTrap class:\n\n";

		std::cout << "-> Test constructors:\n\n";

		std::cout << "--> Create FragTrap object using default constructor:\n";
		FragTrap no_name;
		std::cout << "--> Created " << no_name << ".\n" << std::endl;

		std::cout << "--> Create FragTrap object using constructor"
			" with name parameter:\n";
		FragTrap luke("Luke");
		std::cout << "--> Created " << luke << ".\n" << std::endl;

		std::cout << "--> Create FragTrap object using copy constructor to "
		"clone FragTrap Unnamed:\n";
		FragTrap luke_clone(no_name);
		std::cout << "--> Created " << luke_clone << "." << std::endl;

		std::cout << "\n--> Use assignment operator to copy attributes from "
			"FragTrap Luke:\n";
		luke_clone = luke;
		std::cout << "--> Status of (now) Luke's clone: " << luke_clone << "."
			<< std::endl;

		std::cout << "\n-> Test functionality:\n";

		std::cout << "\n--> Make Luke attack target Tim, take damage, "
			"be repaired and request high fives five times until "
			"energy points are exhausted:\n";

		for (int i = 1; luke.get_ep() > 0 && luke.get_hp() > 0; ++i)
		{
			std::cout << "\n---> Round " << i << ":\n";
			luke.attack("Tim");
			luke.takeDamage(8);
			luke.beRepaired(10);
			luke.highFivesGuys();
			luke.highFivesGuys();
			luke.highFivesGuys();
			luke.highFivesGuys();
			luke.highFivesGuys();
			std::cout << "Status at the end of the round: " << luke << "\n";
		}

		std::cout << "\n---> Make Luke attack target Tim, take damage, "
			"be repaired and request high fives again "
			"(no energy points left):\n";
		luke.attack("Tim");
		luke.takeDamage(8);
		luke.beRepaired(10);
		luke.highFivesGuys();
		std::cout << "Final status: " << luke << "\n";

		std::cout << "\n--> Make Luke's clone attack target Mark, take damage, "
			"be repaired and request high fives "
			"until hit points are exhausted:\n";

		for (int i = 1; luke_clone.get_ep() > 0 && luke_clone.get_hp() > 0;
			++i)
		{
			std::cout << "\n---> Round " << i << ":\n";
			luke_clone.attack("Mark");
			luke_clone.takeDamage(15);
			luke_clone.beRepaired(1);
			luke_clone.highFivesGuys();
			std::cout << "Status at the end of the round: " << luke_clone
				<< "\n";
		}

		std::cout << "\n--> Make Luke's clone attack target Mark, take damage, "
			"be repaired and request high fives "
			"again (no hit points left):\n";
		luke_clone.attack("Mark");
		luke_clone.takeDamage(15);
		luke_clone.beRepaired(1);
		luke_clone.highFivesGuys();
		std::cout << "Final status: " << luke_clone << "\n";

		std::cout << "\n-> End of FragTrap tests, FragTrap object destructors "
			"should be called:\n";
	}

	return 0;
}