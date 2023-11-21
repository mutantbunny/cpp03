/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmachado <gmachado@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 22:26:43 by gmachado          #+#    #+#             */
/*   Updated: 2023/11/21 01:45:59 by gmachado         ###   ########.fr       */
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

	std::cout << "Create ScavTrap Rick:\n";
	ScavTrap rick("Rick");
	std::cout << rick << '\n' << std::endl;

	std::cout << "Fight Jack (deals 20 HP damage per round):\n";

	round = 1;
	while (rick.get_ep() > 0 && rick.get_hp() > 0)
		fight_one_round(rick, "Jack", round++, 20);

	fight_one_round(rick, "Jack", round, 20);
}