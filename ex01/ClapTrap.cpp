/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmachado <gmachado@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 22:26:40 by gmachado          #+#    #+#             */
/*   Updated: 2024/02/21 22:05:18 by gmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(void) : m_name("Unnamed"), m_hp(ClapTrap::default_hp),
	m_ep(ClapTrap::default_ep), m_damage(ClapTrap::default_damage),
	m_max_hp(ClapTrap::default_hp)
{
	std::cout << "ClapTrap default constructor called." << std::endl;
}

ClapTrap::ClapTrap(std::string name) : m_name(name),
	m_hp(ClapTrap::default_hp), m_ep(ClapTrap::default_ep),
	m_damage(ClapTrap::default_damage), m_max_hp(ClapTrap::default_hp)
{
	std::cout << "ClapTrap constructor with name parameter called."
		<< std::endl;
}

ClapTrap::ClapTrap(std::string name, int hp, int ep, int damage) :
	m_name(name), m_hp(hp), m_ep(ep), m_damage(damage), m_max_hp(hp)
{
	std::cout << "ClapTrap protected constructor called." << std::endl;
}

ClapTrap::ClapTrap(ClapTrap &src)
{
	std::cout << "ClapTrap copy constructor called." << std::endl;
	*this = src;
}

ClapTrap::~ClapTrap(void)
{
	std::cout << "ClapTrap destructor called." << std::endl;
}

ClapTrap &ClapTrap::operator=(ClapTrap &src)
{
	std::cout << "ClapTrap assignment operator called." << std::endl;

	if (this == &src)
		return *this;

	m_name = src.get_name();
	m_hp = src.get_hp();
	m_ep = src.get_ep();
	m_damage = src.get_damage();
	m_max_hp = src.get_max_hp();

	return *this;
}

void ClapTrap::attack(const std::string& target)
{
	if (m_hp == 0)
	{
		std::cout << "ClapTrap " << m_name << " can't attack. "
			"No hit points left!" << std::endl;
		return;
	}

	if (m_ep == 0)
	{
		std::cout << "ClapTrap " << m_name << " can't attack. "
			"No energy points left!" << std::endl;
		return;
	}

	std::cout << "ClapTrap " << m_name << " attacks " << target
		<< ", causing " << m_damage << " points of damage!" << std::endl;

	--m_ep;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (m_hp == 0)
	{
		std::cout << "ClapTrap " << m_name << " can't take any more damage. "
			"No hit points left!" << std::endl;
		return;
	}

	if (amount > m_hp)
		amount = m_hp;

	std::cout << "ClapTrap " << m_name << " takes " << amount
		<< " points of damage!" << std::endl;

	m_hp -= amount;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (m_hp == m_max_hp)
	{
		std::cout << "ClapTrap " << m_name << " can't be repaired. "
			"Already at full hit points!" << std::endl;
		return;
	}

	if (m_hp == 0)
	{
		std::cout << "ClapTrap " << m_name << " can't be repaired. "
			"No hit points left!" << std::endl;
		return;
	}

	if (m_ep == 0)
	{
		std::cout << "ClapTrap " << m_name << " can't be repaired. "
			"No energy points left!" << std::endl;
		return;
	}

	if (m_hp + amount > m_max_hp)
		amount = m_max_hp - m_hp;

	std::cout << "ClapTrap " << m_name << " is repaired, recovering "
		<< amount << " points of damage!" << std::endl;

	m_hp += amount;
	--m_ep;
}

std::string ClapTrap::get_name(void) { return m_name; }

unsigned int ClapTrap::get_hp(void) { return m_hp; }

unsigned int ClapTrap::get_ep(void) { return m_ep; }

unsigned int ClapTrap::get_damage(void) { return m_damage; }

unsigned int ClapTrap::get_max_hp(void) { return m_max_hp; }

std::ostream &operator<<(std::ostream &out, ClapTrap &ct)
{
	out << "ClapTrap(Name: " << ct.get_name() << ", "
			<< "Hit Points: " << ct.get_hp() << ", "
			<< "Energy Points: " << ct.get_ep() << ", "
			<< "Damage: " << ct.get_damage() << ")";
	return out;
}
