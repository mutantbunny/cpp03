/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmachado <gmachado@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 22:26:40 by gmachado          #+#    #+#             */
/*   Updated: 2023/11/21 01:29:40 by gmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(void) : m_name("Unnamed"), m_hp(10),
	m_ep(10), m_damage(0)
{
	std::cout << "ClapTrap default constructor called." << std::endl;
}

ClapTrap::ClapTrap(std::string name) : m_name(name), m_hp(10),
	m_ep(10), m_damage(0)
{
	std::cout << "ClapTrap constructor with name parameter called."
		<< std::endl;
}

ClapTrap::ClapTrap(ClapTrap &src): m_name(src.m_name), m_hp(src.m_hp),
	m_ep(src.m_ep), m_damage(src.m_damage)
{
	std::cout << "ClapTrap copy constructor called." << std::endl;
}

ClapTrap::~ClapTrap(void)
{
	std::cout << "ClapTrap destructor called." << std::endl;
}

ClapTrap &ClapTrap::operator=(ClapTrap &src)
{
	m_damage = src.m_damage;
	m_hp = src.m_hp;
	m_ep = src.m_ep;
	m_damage = src.m_damage;
	std::cout << "ClapTrap assignment operator called." << std::endl;
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

	std::cout << "ClapTrap " << m_name << " takes " << amount
		<< " points of damage!" << std::endl;
	m_hp >= amount? m_hp -= amount : m_hp = 0;
}

void ClapTrap::beRepaired(unsigned int amount)
{
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

	std::cout << "ClapTrap " << m_name << " is repaired, recovering "
		<< amount << " points of damage!" << std::endl;
	m_hp += amount;
	--m_ep;
}

void ClapTrap::set_name(std::string name) { m_name = name; }
std::string ClapTrap::get_name(void) { return m_name; }

void ClapTrap::set_hp(unsigned int hp) { m_hp = hp; }
unsigned int ClapTrap::get_hp(void) { return m_hp; }

void ClapTrap::set_ep(unsigned int ep) { m_ep = ep; }
unsigned int ClapTrap::get_ep(void) { return m_ep; }

void ClapTrap::set_damage(unsigned int damage) { m_damage = damage; }
unsigned int ClapTrap::get_damage(void) { return m_damage; }

std::ostream &operator<<(std::ostream &out, ClapTrap &ct)
{
	out << "ClapTrap(Name: " << ct.get_name() << ", "
			<< "Hit Points: " << ct.get_hp() << ", "
			<< "Energy Points: " << ct.get_ep() << ", "
			<< "Damage: " << ct.get_damage() << ")";
	return out;
}