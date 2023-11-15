/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmachado <gmachado@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 22:26:40 by gmachado          #+#    #+#             */
/*   Updated: 2023/11/15 02:49:18 by gmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(void) : _name("Unnamed"), _hp(10),
	_ep(10), _damage(0)
{
	std::cout << "ClapTrap default constructor called." << std::endl;
}

ClapTrap::ClapTrap(std::string name) : _name(name), _hp(10),
	_ep(10), _damage(0)
{
	std::cout << "ClapTrap constructor with name parameter called."
		<< std::endl;
}

ClapTrap::ClapTrap(ClapTrap &src): _name(src._name), _hp(src._hp),
	_ep(src._ep), _damage(src._damage)
{
	std::cout << "ClapTrap copy constructor called." << std::endl;
}

ClapTrap::~ClapTrap(void)
{
	std::cout << "ClapTrap destructor called." << std::endl;
}

ClapTrap &ClapTrap::operator=(ClapTrap &src)
{
	_damage = src._damage;
	_hp = src._hp;
	_ep = src._ep;
	_damage = src._damage;
	std::cout << "ClapTrap assignment operator called." << std::endl;
	return *this;
}

void ClapTrap::attack(const std::string& target)
{
	if (_hp == 0)
	{
		std::cout << "ClapTrap " << _name << " can't attack. "
			"No hit points left!" << std::endl;
		return;
	}

	if (_ep == 0)
	{
		std::cout << "ClapTrap " << _name << " can't attack. "
			"No energy points left!" << std::endl;
		return;
	}

	std::cout << "ClapTrap " << _name << " attacks " << target
		<< ", causing " << _damage << " points of damage!" << std::endl;
	--_ep;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (_hp == 0)
	{
		std::cout << "ClapTrap " << _name << " can't take any more damage. "
			"No hit points left!" << std::endl;
		return;
	}

	std::cout << "ClapTrap " << _name << " takes " << amount
		<< " points of damage!" << std::endl;
	_hp >= amount? _hp -= amount : _hp = 0;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (_hp == 0)
	{
		std::cout << "ClapTrap " << _name << " can't be repaired. "
			"No hit points left!" << std::endl;
		return;
	}

	if (_ep == 0)
	{
		std::cout << "ClapTrap " << _name << " can't be repaired. "
			"No energy points left!" << std::endl;
		return;
	}

	std::cout << "ClapTrap " << _name << " is repaired, recovering "
		<< amount << " points of damage!" << std::endl;
	_hp += amount;
	--_ep;
}

void ClapTrap::set_name(std::string name) { _name = name; }
std::string ClapTrap::get_name(void) { return _name; }

void ClapTrap::set_hp(unsigned int hp) { _hp = hp; }
unsigned int ClapTrap::get_hp(void) { return _hp; }

void ClapTrap::set_ep(unsigned int ep) { _ep = ep; }
unsigned int ClapTrap::get_ep(void) { return _ep; }

void ClapTrap::set_damage(unsigned int damage) { _damage = damage; }
unsigned int ClapTrap::get_damage(void) { return _damage; }

std::ostream &operator<<(std::ostream &out, ClapTrap &ct)
{
	out << "ClapTrap(Name: " << ct.get_name() << ", "
			<< "Hit Points: " << ct.get_hp() << ", "
			<< "Energy Points: " << ct.get_ep() << ", "
			<< "Damage: " << ct.get_damage() << ")";
	return out;
}