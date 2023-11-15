/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmachado <gmachado@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 22:26:43 by gmachado          #+#    #+#             */
/*   Updated: 2023/11/15 02:53:09 by gmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

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

	std::cout << "Create ClapTrap Rick:\n";
	ClapTrap rick("Rick");
	std::cout << rick << '\n' << std::endl;

	std::cout << "Fight Jack (deals 4 HP damage per round):\n";

	round = 1;
	while (rick.get_ep() > 0 && rick.get_hp() > 0)
		fight_one_round(rick, "Jack", round++, 4);

	fight_one_round(rick, "Jack", round, 4);
}