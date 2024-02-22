/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmachado <gmachado@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 18:56:13 by gmachado          #+#    #+#             */
/*   Updated: 2024/02/21 22:43:46 by gmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(void) : ClapTrap("Unnamed_clap_name",
	FragTrap::default_hp, ScavTrap::default_ep, FragTrap::default_damage),
	m_name("Unnamed")
{
	std::cout << "DiamondTrap default constructor called." << std::endl;
}

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name + "_clap_name",
	FragTrap::default_hp, ScavTrap::default_ep, FragTrap::default_damage),
	m_name(name)
{
	std::cout << "DiamondTrap constructor with name parameter called."
		<< std::endl;
}

DiamondTrap::DiamondTrap(DiamondTrap &src) : ClapTrap(src)
{
	std::cout << "DiamondTrap copy constructor called." << std::endl;
	set_name(src.get_name());
}

DiamondTrap::~DiamondTrap(void)
{
	std::cout << "DiamondTrap destructor called." << std::endl;
}

DiamondTrap &DiamondTrap::operator=(DiamondTrap &src)
{
	std::cout << "DiamondTrap assignment operator called." << std::endl;

	if (this == &src)
		return *this;

	set_name(src.get_name());
	m_hp = src.get_hp();
	m_ep = src.get_hp();
	m_damage = src.get_damage();
	m_max_hp = src.get_max_hp();

	return *this;
}

void DiamondTrap::whoAmI()
{
	std::cout << "My name is " << m_name << " and my ClapTrap name is "
		<< ClapTrap::m_name << '.' << std::endl;
}

void DiamondTrap::attack(const std::string& target)
{
	ScavTrap::attack(target);
}

void DiamondTrap::set_name(std::string name)
{
	m_name = name;
	ClapTrap::m_name = name + "_clap_name";
}

std::string DiamondTrap::get_name(void) { return m_name; }

std::string DiamondTrap::get_claptrap_name(void)
{
	return ClapTrap::get_name();
}

std::ostream &operator<<(std::ostream &out, DiamondTrap &dt)
{
	out << "DiamondTrap(Name: " << dt.get_name() << ", "
			<< "Claptrap Name: " << dt.get_claptrap_name() << ", "
			<< "Hit Points: " << dt.get_hp() << ", "
			<< "Energy Points: " << dt.get_ep() << ", "
			<< "Damage: " << dt.get_damage() << ")";
	return out;
}