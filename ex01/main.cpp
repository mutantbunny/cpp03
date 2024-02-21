/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmachado <gmachado@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 22:26:43 by gmachado          #+#    #+#             */
/*   Updated: 2024/02/20 22:46:17 by gmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

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
			"clone ClapTrap John:\n";
		ClapTrap john_clone(john);
		std::cout << "--> Created " << john_clone << ".\n" << std::endl;

		std::cout << "\n-> Test fuctionality:\n";

		std::cout << "\n--> Make John attack target Ted, take damage and "
			"be repaired until energy points are exhausted:\n";

		for (int i = 1; john.get_ep() > 0 && john.get_hp() > 0; ++i)
		{
			std::cout << "\n---> Round " << i << ":\n";
			john.attack("Ted");
			john.takeDamage(1);
			john.beRepaired(1);
			std::cout << "Status at the end of the round: " << john << "\n";
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
	}

	{
		std::cout << "\n\nTest ScavTrap class:\n\n";

		std::cout << "-> Test constructors:\n\n";

		std::cout << "--> Create ScavTrap object using default constructor:\n";
		ScavTrap no_name;
		std::cout << "--> Created " << no_name << ".\n" << std::endl;

		std::cout << "--> Create ScavTrap object using constructor"
			" with name parameter:\n";
		ScavTrap bill("Bill");
		std::cout << "--> Created " << bill << ".\n" << std::endl;

		std::cout << "--> Create ScavTrap object using copy constructor "
			"to clone ScavTrap Bill:\n";
		ScavTrap bill_clone(bill);
		std::cout << "--> Created " << bill_clone << ".\n" << std::endl;

		std::cout << "\n-> Test fuctionality:\n";

		std::cout << "\n--> Make Bill attack target Phil, take damage, "
			"be repaired and guard gate 5 times "
			"until energy points are exhausted:\n";

		for (int i = 1; bill.get_ep() > 0 && bill.get_hp() > 0; ++i)
		{
			std::cout << "\n---> Round " << i << ":\n";
			bill.attack("Phil");
			bill.takeDamage(2);
			bill.beRepaired(1);
			bill.guardGate();
			bill.guardGate();
			bill.guardGate();
			bill.guardGate();
			bill.guardGate();
			std::cout << "Status at the end of the round: " << bill << "\n";
		}

		std::cout << "\n---> Make Bill attack target Phil, take damage, "
			"be repaired and guard gate again (no energy points left):\n";
		bill.attack("Phil");
		bill.takeDamage(5);
		bill.beRepaired(1);
		bill.guardGate();
		std::cout << "Final status: " << bill << "\n";

		std::cout << "\n--> Make Bill's clone attack target Bob, take damage, "
			"be repaired and guard gate until hit points are exhausted:\n";

		for (int i = 1; bill_clone.get_ep() > 0 && bill_clone.get_hp() > 0;
			++i)
		{
			std::cout << "\n---> Round " << i << ":\n";
			bill_clone.attack("Bob");
			bill_clone.takeDamage(20);
			bill_clone.beRepaired(1);
			bill_clone.guardGate();

			std::cout << "Status at the end of the round: " << bill_clone
				<< "\n";
		}

		std::cout << "\n--> Make Bill's clone attack target Bob, take damage, "
			"be repaired and guard gate again (no hit points left):\n";
		bill_clone.attack("Bob");
		bill_clone.takeDamage(20);
		bill_clone.beRepaired(1);
		bill_clone.guardGate();
		std::cout << "Final status: " << bill_clone << "\n";

		std::cout << "\n-> End of ScavTrap tests, ScavTrap object destructors "
			"should be called:\n";
	}

	return 0;
}