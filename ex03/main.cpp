/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmachado <gmachado@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 22:26:43 by gmachado          #+#    #+#             */
/*   Updated: 2024/02/20 22:46:39 by gmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

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
		ScavTrap chris("Chris");
		std::cout << "--> Created " << chris << ".\n" << std::endl;

		std::cout << "--> Create ScavTrap object using copy constructor "
			"to clone ScavTrap Chris:\n";
		ScavTrap chris_clone(chris);
		std::cout << "--> Created " << chris_clone << ".\n" << std::endl;

		std::cout << "\n-> Test fuctionality:\n";

		std::cout << "\n--> Make Chris attack target Logan, take damage, "
			"be repaired and guard gate 5 times "
			"until energy points are exhausted:\n";

		for (int i = 1; chris.get_ep() > 0 && chris.get_hp() > 0; ++i)
		{
			std::cout << "\n---> Round " << i << ":\n";
			chris.attack("Logan");
			chris.takeDamage(2);
			chris.beRepaired(1);
			chris.guardGate();
			chris.guardGate();
			chris.guardGate();
			chris.guardGate();
			chris.guardGate();
			std::cout << "Status at the end of the round: " << chris << "\n";
		}

		std::cout << "\n---> Make Chris attack target Logan, take damage, "
			"be repaired and guard gate again (no energy points left):\n";
		chris.attack("Logan");
		chris.takeDamage(5);
		chris.beRepaired(1);
		chris.guardGate();
		std::cout << "Final status: " << chris << "\n";

		std::cout << "\n--> Make Chris's clone attack target Tony, take damage, "
			"be repaired and guard gate until hit points are exhausted:\n";

		for (int i = 1; chris_clone.get_ep() > 0 && chris_clone.get_hp() > 0;
			++i)
		{
			std::cout << "\n---> Round " << i << ":\n";
			chris_clone.attack("Tony");
			chris_clone.takeDamage(20);
			chris_clone.beRepaired(1);
			chris_clone.guardGate();

			std::cout << "Status at the end of the round: " << chris_clone
				<< "\n";
		}

		std::cout << "\n--> Make Chris's clone attack target Tony, take damage, "
			"be repaired and guard gate again (no hit points left):\n";
		chris_clone.attack("Tony");
		chris_clone.takeDamage(20);
		chris_clone.beRepaired(1);
		chris_clone.guardGate();
		std::cout << "Final status: " << chris_clone << "\n";

		std::cout << "\n-> End of ScavTrap tests, ScavTrap object destructors "
			"should be called:\n\n";
	}

	{
		std::cout << "Test FragTrap class:\n\n";

		std::cout << "-> Test constructors:\n\n";

		std::cout << "--> Create FragTrap object using default constructor:\n";
		FragTrap no_name;
		std::cout << "--> Created " << no_name << ".\n" << std::endl;

		std::cout << "--> Create FragTrap object using constructor"
			" with name parameter:\n";
		FragTrap luke("Luke");
		std::cout << "--> Created " << luke << ".\n" << std::endl;

		std::cout << "--> Create FragTrap object using copy constructor "
			"to clone FragTrap Luke:\n";
		FragTrap luke_clone(luke);
		std::cout << "--> Created " << luke_clone << ".\n" << std::endl;

		std::cout << "\n-> Test fuctionality:\n";

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
			"should be called:\n\n";
	}

	{
		std::cout << "\n\nTest DiamondTrap class:\n\n";

		std::cout << "-> Test constructors:\n\n";

		std::cout << "--> Create DiamondTrap object using default constructor:\n";
		DiamondTrap no_name;
		std::cout << "--> Created " << no_name << ".\n" << std::endl;

		std::cout << "--> Create DiamondTrap object using constructor"
			" with name parameter:\n";
		DiamondTrap freddy("Freddy");
		std::cout << "--> Created " << freddy << ".\n" << std::endl;

		std::cout << "--> Create DiamondTrap object using copy constructor "
			"to clone DiamondTrap Freddy:\n";
		DiamondTrap freddy_clone(freddy);
		std::cout << "--> Created " << freddy_clone << ".\n" << std::endl;

		std::cout << "\n-> Test fuctionality:\n";

		std::cout << "\n--> Let DiamondTrap objects tell us who they are:\n";

		std::cout << "\n--> Unnamed: ";
		no_name.whoAmI();
		std::cout << "\n--> Freddy: ";
		freddy.whoAmI();
		std::cout << "\n--> Freddy's clone: ";
		freddy_clone.whoAmI();

		std::cout << "\n--> Make Freddy attack target Logan, take damage, "
			"be repaired, request high fives 3 times and guard gate 3 times "
			"until energy points are exhausted:\n";

		for (int i = 1; freddy.get_ep() > 0 && freddy.get_hp() > 0; ++i)
		{
			std::cout << "\n---> Round " << i << ":\n";
			freddy.attack("Logan");
			freddy.takeDamage(2);
			freddy.beRepaired(1);
			freddy.highFivesGuys();
			freddy.highFivesGuys();
			freddy.highFivesGuys();
			freddy.guardGate();
			freddy.guardGate();
			freddy.guardGate();

			std::cout << "Status at the end of the round: " << freddy << "\n";
		}

		std::cout << "\n---> Make Freddy attack target Logan, take damage, "
			"be repaired, request high fives and guard gate again "
			"(no energy points left):\n";
		freddy.attack("Logan");
		freddy.takeDamage(5);
		freddy.beRepaired(1);
		freddy.highFivesGuys();
		freddy.guardGate();
		std::cout << "Final status: " << freddy << "\n";

		std::cout << "\n--> Make Freddy's clone attack target Tony, take damage, "
			"be repaired and guard gate until hit points are exhausted:\n";

		for (int i = 1; freddy_clone.get_ep() > 0 && freddy_clone.get_hp() > 0;
			++i)
		{
			std::cout << "\n---> Round " << i << ":\n";
			freddy_clone.attack("Tony");
			freddy_clone.takeDamage(20);
			freddy_clone.beRepaired(1);
			freddy_clone.highFivesGuys();
			freddy_clone.highFivesGuys();
			freddy_clone.highFivesGuys();
			freddy_clone.guardGate();
			freddy_clone.guardGate();
			freddy_clone.guardGate();

			std::cout << "Status at the end of the round: " << freddy_clone
				<< "\n";
		}

		std::cout << "\n--> Make Freddy's clone attack target Tony, take damage, "
			"be repaired and guard gate again (no hit points left):\n";
		freddy_clone.attack("Tony");
		freddy_clone.takeDamage(20);
		freddy_clone.beRepaired(1);
		freddy_clone.highFivesGuys();
		freddy_clone.guardGate();
		std::cout << "Final status: " << freddy_clone << "\n";

		std::cout << "\n-> End of DiamondTrap tests, DiamondTrap object destructors "
			"should be called:\n";
	}

	return 0;
}