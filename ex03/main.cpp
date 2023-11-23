/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmachado <gmachado@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 22:26:43 by gmachado          #+#    #+#             */
/*   Updated: 2023/11/22 18:46:15 by gmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

// static void fight_one_round(ClapTrap &fighter, std::string target,
// 	int round, int damage)
// {
// 	std::cout << "\n---------\n";
// 	std::cout << "Round " << round << ": Fight!\n";
// 	fighter.attack(target);
// 	fighter.takeDamage(damage);
// 	fighter.beRepaired(1);
// 	std::cout << "Status: " << fighter << "\n---------\n" << std::endl;
// }

// static void fight_one_round(FragTrap &fighter, std::string target,
// 	int round, int damage)
// {
// 	std::cout << "\n---------\n";
// 	std::cout << "Round " << round << ": Fight!\n";
// 	fighter.attack(target);
// 	fighter.takeDamage(damage);
// 	fighter.beRepaired(1);
// 	std::cout << "Status: " << fighter << "\n---------\n" << std::endl;
// }

// static void fight_ten_rounds(FragTrap &fighter, std::string target,
// 	int round, int damage)
// {
// 	std::cout << "\n---------\n";
// 	std::cout << "Round " << round << ": Fight!\n";
// 	for (int i = 10; i > 0; --i)
// 	{
// 		fighter.attack(target);
// 		fighter.takeDamage(damage);
// 		fighter.beRepaired(1);
// 	}

// 	std::cout << "Status: " << fighter << "\n---------\n" << std::endl;
// }

int main()
{
	std::cout << "### TESTING CLAPTRAP ###\n" << std::endl;
	{
		std::cout << "\033[34mConstructing\033[0m" << std::endl;
		ClapTrap a;
		ClapTrap b("Cody");

		std::cout << "\033[34mTesting\033[0m" << std::endl;
		a.attack("some other robot");
		a.takeDamage(10);
		a.takeDamage(10);
		a.beRepaired(5);
		a.attack("some other other robot");
		b.beRepaired(3);
		for (int i = 0; i < 12; i++)
			b.attack("Cody-clone");
		b.beRepaired(3);
		std::cout << "\033[34mDeconstructing\033[0m" << std::endl;
	}
	std::cout << "\n\n### TESTING SCAVTRAP ###\n" << std::endl;
	{
		std::cout << "\033[34mConstructing\033[0m" << std::endl;
		ScavTrap a;
		ScavTrap b("Savage");

		std::cout << "\033[34mTesting\033[0m" << std::endl;
		a.attack("CloneTrap");
		// for (int i = 0; i < 50; i++)
		// 	a.attack("CloneTrap");
		a.beRepaired(22);
		a.takeDamage(21);
		a.beRepaired(22);
		a.guardGate();
		a.guardGate();
		b.attack("Savage-clone");
		b.takeDamage(101);
		b.takeDamage(15);
		b.attack("ScavTrap-clone");
		std::cout << "\033[34mDeconstructing\033[0m" << std::endl;
	}
	std::cout << "\n\n### TESTING FRAGTRAP ###\n" << std::endl;
	{
		std::cout << "\033[34mConstructing\033[0m" << std::endl;
		FragTrap a;
		FragTrap b("Chadd");

		std::cout << "\033[34mTesting\033[0m" << std::endl;
		a.highFivesGuys();
		a.attack("some random dude");
		a.takeDamage(101);
		a.takeDamage(1);
		a.attack("some random dude");
		b.highFivesGuys();
		// for(int i = 0; i < 101; i++)
		// 	b.attack("FragTrap-clone");
		std::cout << "\033[34mDeconstructing\033[0m" << std::endl;
	}
	std::cout << "\n\n### TESTING DIAMONDTRAP ###\n" << std::endl;
	{
		std::cout << "\033[34mConstructing\033[0m" << std::endl;
		DiamondTrap a;
		DiamondTrap b("Giga Chadd");
		DiamondTrap c(a);

		std::cout << "\033[34mTesting\033[0m" << std::endl;
		a.whoAmI();
		a.attack("some super random dude");
		b.whoAmI();
		b.attack("Chadd-clone");
		c.whoAmI();
		std::cout << "\033[34mDeconstructing\033[0m" << std::endl;
	}
	return (0);
}