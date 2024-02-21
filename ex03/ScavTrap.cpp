/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmachado <gmachado@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 04:17:37 by gmachado          #+#    #+#             */
/*   Updated: 2024/02/20 22:44:30 by gmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ScavTrap.hpp"


ScavTrap::ScavTrap(void): ClapTrap("Unnamed", ScavTrap::default_hp,
	ScavTrap::default_ep, ScavTrap::default_damage)
{
	std::cout << "ScavTrap default constructor called." << std::endl;
}

ScavTrap::ScavTrap(std::string name): ClapTrap(name, ScavTrap::default_hp,
	ScavTrap::default_ep, ScavTrap::default_damage)
{
	std::cout << "ScavTrap constructor with name parameter called."
		<< std::endl;
}

ScavTrap::ScavTrap(ScavTrap &src): ClapTrap(src.get_name(), src.get_hp(),
	src.get_ep(), src.get_damage())
{
	std::cout << "ScavTrap copy constructor called." << std::endl;
}

ScavTrap::~ScavTrap(void)
{
	std::cout << "ScavTrap destructor called." << std::endl;
}

ScavTrap &ScavTrap::operator=(ScavTrap &src)
{
	std::cout << "ScavTrap assignment operator called." << std::endl;

	if (this == &src)
		return *this;

	set_name(src.get_name());
	set_hp(src.get_hp());
	set_ep(src.get_hp());
	set_damage(src.get_damage());

	return *this;
}

void ScavTrap::attack(const std::string& target)
{
	if (get_hp() == 0)
	{
		std::cout << "ScavTrap " << get_name() << " can't attack. "
			"No hit points left!" << std::endl;
		return;
	}

	if (get_ep() == 0)
	{
		std::cout << "ScavTrap " << get_name() << " can't attack. "
			"No energy points left!" << std::endl;
		return;
	}

	std::cout << "ScavTrap " << get_name() << " attacks " << target
		<< ", causing " << get_damage() << " points of damage!" << std::endl;

	set_ep(get_ep() - 1);
}

void ScavTrap::guardGate()
{
	if (get_hp() == 0)
	{
		std::cout << "ScavTrap " << get_name() << " can't guard the gate. "
			"No hit points left!" << std::endl;
		return;
	}

	if (get_ep() == 0)
	{
		std::cout << "ScavTrap " << get_name() << " can't guard the gate. "
			"No energy points left!" << std::endl;
		return;
	}

	std::cout << "ScavTrap " << get_name() << " is now in Gate keeper mode."
		<< std::endl;
	set_ep(get_ep() - 1);
}

std::ostream &operator<<(std::ostream &out, ScavTrap &st)
{
	out << "ScavTrap(Name: " << st.get_name() << ", "
			<< "Hit Points: " << st.get_hp() << ", "
			<< "Energy Points: " << st.get_ep() << ", "
			<< "Damage: " << st.get_damage() << ")";
	return out;
}
