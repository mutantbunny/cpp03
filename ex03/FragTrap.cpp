/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmachado <gmachado@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 04:17:37 by gmachado          #+#    #+#             */
/*   Updated: 2024/02/21 21:52:39 by gmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "FragTrap.hpp"


FragTrap::FragTrap(void): ClapTrap("Unnamed", FragTrap::default_hp,
	FragTrap::default_ep, FragTrap::default_damage)
{
	std::cout << "FragTrap default constructor called." << std::endl;
}

FragTrap::FragTrap(std::string name): ClapTrap(name, FragTrap::default_hp,
	FragTrap::default_ep, FragTrap::default_damage)
{
	std::cout << "FragTrap constructor with name parameter called."
		<< std::endl;
}

FragTrap::FragTrap(FragTrap &src)
{
	std::cout << "FragTrap copy constructor called." << std::endl;
	*this = src;
}

FragTrap::~FragTrap(void)
{
	std::cout << "FragTrap destructor called." << std::endl;
}

FragTrap &FragTrap::operator=(FragTrap &src)
{
	std::cout << "FragTrap assignment operator called." << std::endl;

	if (this == &src)
		return *this;

	ClapTrap::operator=(src);

	return *this;
}

void FragTrap::attack(const std::string& target)
{
	if (m_hp == 0)
	{
		std::cout << "FragTrap " << get_name() << " can't attack. "
			"No hit points left!" << std::endl;
		return;
	}

	if (m_ep == 0)
	{
		std::cout << "FragTrap " << get_name() << " can't attack. "
			"No energy points left!" << std::endl;
		return;
	}

	std::cout << "FragTrap " << get_name() << " attacks " << target
		<< ", causing " << m_damage << " points of damage!" << std::endl;
	--m_ep;
}

void FragTrap::highFivesGuys(void)
{
	if (m_hp == 0)
	{
		std::cout << "FragTrap " << get_name() << " can't request high fives. "
			"No hit points left!" << std::endl;
		return;
	}

	if (m_ep == 0)
	{
		std::cout << "FragTrap " << get_name() << " can't request high fives. "
			"No energy points left!" << std::endl;
		return;
	}

	std::cout << "FragTrap " << get_name()
		<< " says: \"Gimme a High Five, guys!!!\"." << std::endl;
	--m_ep;
}

std::ostream &operator<<(std::ostream &out, FragTrap &st)
{
	out << "FragTrap(Name: " << st.get_name() << ", "
			<< "Hit Points: " << st.get_hp() << ", "
			<< "Energy Points: " << st.get_ep() << ", "
			<< "Damage: " << st.get_damage() << ")";
	return out;
}
