/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmachado <gmachado@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 22:26:43 by gmachado          #+#    #+#             */
/*   Updated: 2023/11/21 02:14:55 by gmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

static void fight_one_round(ClapTrap &fighter, std::string target,
	int round, int damage)
{
	std::cout << "\n---------\n";
	std::cout << "Round " << round << ": Fight!\n";
	fighter.attack(target);
	fighter.takeDamage(damage);
	fighter.beRepaired(1);
	std::cout << "Status: " << fighter << "\n---------\n" << std::endl;
}

static void fight_ten_rounds(ClapTrap &fighter, std::string target,
	int round, int damage)
{
	std::cout << "\n---------\n";
	std::cout << "Round " << round << ": Fight!\n";
	for (int i = 10; i > 0; --i)
	{
		fighter.attack(target);
		fighter.takeDamage(damage);
		fighter.beRepaired(1);
	}

	std::cout << "Status: " << fighter << "\n---------\n" << std::endl;
}

int main(void)
{
	std::cout << "Create ClapTrap John:\n";
	ClapTrap john("John");
	std::cout << john << '\n' << std::endl;

	std::cout << "Fight Ted (deals 1 HP damage per round):\n";

	int round = 1;

	while (john.get_ep() > 0 && john.get_hp() > 0)
		fight_one_round(john, "Ted", round++, 1);

	fight_one_round(john, "Ted", round, 1);

	std::cout << "Create ClapTrap Rick:\n";
	ClapTrap rick("Rick");
	std::cout << rick << '\n' << std::endl;

	std::cout << "Fight Jack (deals 4 HP damage per round):\n";

	round = 1;
	while (rick.get_ep() > 0 && rick.get_hp() > 0)
		fight_one_round(rick, "Jack", round++, 4);

	fight_one_round(rick, "Jack", round, 4);

	std::cout << "Create ScavTrap Bob:\n";
	ScavTrap bob("Bob");
	std::cout << bob << '\n' << std::endl;

	std::cout << "Fight Chuck (deals 1 HP damage per round):\n";

	round = 1;

	while (bob.get_ep() > 0 && bob.get_hp() > 0)
	{
		fight_ten_rounds(bob, "Chuck", round, 1);
		round += 10;
	}

	std::cout << "Create ScavTrap Robin:\n";
	ScavTrap robin("Robin");
	std::cout << robin << '\n' << std::endl;

	std::cout << "Fight Conan (deals 10 HP damage per round):\n";

	round = 1;
	while (robin.get_ep() > 0 && robin.get_hp() > 0)
	{
		fight_ten_rounds(robin, "Conan", round, 10);
		round += 10;
	}
}