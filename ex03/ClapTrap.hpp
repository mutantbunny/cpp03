/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmachado <gmachado@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 22:26:37 by gmachado          #+#    #+#             */
/*   Updated: 2023/11/23 03:23:30 by gmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <iostream>

class ClapTrap
{
	protected:
		static const unsigned int default_hp = 10;
		static const unsigned int default_ep = 10;
		static const unsigned int default_damage = 0;

		std::string m_name;
		unsigned int m_hp;
		unsigned int m_ep;
		unsigned int m_damage;

		const unsigned int m_default_hp;

		ClapTrap(std::string name, int hp, int ep, int damage);

	public:
		ClapTrap(void);
		ClapTrap(std::string name);
		ClapTrap(ClapTrap &src);

		~ClapTrap(void);

		ClapTrap &operator=(ClapTrap &src);

		void attack(const std::string& target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);

		void set_name(std::string name);
		std::string get_name(void);

		void set_hp(unsigned int hp);
		unsigned int get_hp(void);

		void set_ep(unsigned int ep);
		unsigned int get_ep(void);

		void set_damage(unsigned int damage);
		unsigned int get_damage(void);
};

std::ostream &operator<<(std::ostream &out, ClapTrap &ct);

#endif

