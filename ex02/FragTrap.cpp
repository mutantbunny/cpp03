/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmachado <gmachado@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 04:17:37 by gmachado          #+#    #+#             */
/*   Updated: 2023/11/21 03:44:36 by gmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "FragTrap.hpp"


FragTrap::FragTrap(void): ClapTrap("Unnamed", default_hp,
	default_ep, default_damage)
{
	std::cout << "FragTrap default constructor called." << std::endl;
}

FragTrap::FragTrap(std::string name): ClapTrap(name, default_hp,
	default_ep, default_damage)
{
	std::cout << "FragTrap constructor with name parameter called."
		<< std::endl;
}

FragTrap::FragTrap(FragTrap &src): ClapTrap(src.m_name, src.m_hp,
	src.m_ep, src.m_damage)
{
	std::cout << "FragTrap copy constructor called." << std::endl;
}

FragTrap::~FragTrap(void)
{
	std::cout << "FragTrap destructor called." << std::endl;
}

FragTrap &FragTrap::operator=(FragTrap &src)
{
	m_damage = src.m_damage;
	m_hp = src.m_hp;
	m_ep = src.m_ep;
	m_damage = src.m_damage;
	std::cout << "FragTrap assignment operator called." << std::endl;
	return *this;
}

void FragTrap::highFivesGuys(void)
{
	std::cout << "FragTrap " << m_name << " says: \"Gimme a High Five, guys!!!\"."
		<< std::endl;
}

std::ostream &operator<<(std::ostream &out, FragTrap &st)
{
	out << "FragTrap(Name: " << st.get_name() << ", "
			<< "Hit Points: " << st.get_hp() << ", "
			<< "Energy Points: " << st.get_ep() << ", "
			<< "Damage: " << st.get_damage() << ")";
	return out;
}
