/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmachado <gmachado@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 04:17:37 by gmachado          #+#    #+#             */
/*   Updated: 2023/11/23 03:31:09 by gmachado         ###   ########.fr       */
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

ScavTrap::ScavTrap(ScavTrap &src): ClapTrap(src.m_name, src.m_hp,
	src.m_ep, src.m_damage)
{
	std::cout << "ScavTrap copy constructor called." << std::endl;
}

ScavTrap::~ScavTrap(void)
{
	std::cout << "ScavTrap destructor called." << std::endl;
}

ScavTrap &ScavTrap::operator=(ScavTrap &src)
{
	m_name = src.m_name;
	m_hp = src.m_hp;
	m_ep = src.m_ep;
	m_damage = src.m_damage;
	std::cout << "ScavTrap assignment operator called." << std::endl;
	return *this;
}

void ScavTrap::guardGate()
{
	if (m_hp == 0)
	{
		std::cout << "ScavTrap " << m_name << " can't guard the gate. "
			"No hit points left!" << std::endl;
		return;
	}

	if (m_ep == 0)
	{
		std::cout << "ScavTrap " << m_name << " can't guard the gate. "
			"No energy points left!" << std::endl;
		return;
	}

	std::cout << "ScavTrap " << m_name << " is now in Gate keeper mode."
		<< std::endl;
	--m_ep;
}

std::ostream &operator<<(std::ostream &out, ScavTrap &st)
{
	out << "ScavTrap(Name: " << st.get_name() << ", "
			<< "Hit Points: " << st.get_hp() << ", "
			<< "Energy Points: " << st.get_ep() << ", "
			<< "Damage: " << st.get_damage() << ")";
	return out;
}
