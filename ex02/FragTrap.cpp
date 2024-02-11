/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmachado <gmachado@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 04:17:37 by gmachado          #+#    #+#             */
/*   Updated: 2024/02/10 21:58:40 by gmachado         ###   ########.fr       */
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

FragTrap::FragTrap(FragTrap &src): ClapTrap(src.get_name(), src.get_hp(),
	src.get_ep(), src.get_damage())
{
	std::cout << "FragTrap copy constructor called." << std::endl;
}

FragTrap::~FragTrap(void)
{
	std::cout << "FragTrap destructor called." << std::endl;
}

FragTrap &FragTrap::operator=(FragTrap &src)
{
	set_name(src.get_name());
	set_hp(src.get_hp());
	set_ep(src.get_hp());
	set_damage(src.get_damage());

	std::cout << "FragTrap assignment operator called." << std::endl;

	return *this;
}

void FragTrap::attack(const std::string& target)
{
	if (get_hp() == 0)
	{
		std::cout << "FragTrap " << get_name() << " can't attack. "
			"No hit points left!" << std::endl;
		return;
	}

	if (get_ep() == 0)
	{
		std::cout << "FragTrap " << get_name() << " can't attack. "
			"No energy points left!" << std::endl;
		return;
	}

	std::cout << "FragTrap " << get_name() << " attacks " << target
		<< ", causing " << get_damage() << " points of damage!" << std::endl;

	set_ep(get_ep() - 1);
}

void FragTrap::highFivesGuys(void)
{
	if (get_hp() == 0)
	{
		std::cout << "FragTrap " << get_name() << " can't request high fives. "
			"No hit points left!" << std::endl;
		return;
	}

	if (get_ep() == 0)
	{
		std::cout << "FragTrap " << get_name() << " can't request high fives. "
			"No energy points left!" << std::endl;
		return;
	}

	std::cout << "FragTrap " << get_name() << " says: \"Gimme a High Five, guys!!!\"."
		<< std::endl;
	set_ep(get_ep() - 1);
}

std::ostream &operator<<(std::ostream &out, FragTrap &st)
{
	out << "FragTrap(Name: " << st.get_name() << ", "
			<< "Hit Points: " << st.get_hp() << ", "
			<< "Energy Points: " << st.get_ep() << ", "
			<< "Damage: " << st.get_damage() << ")";
	return out;
}
