/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmachado <gmachado@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 22:26:37 by gmachado          #+#    #+#             */
/*   Updated: 2024/02/21 19:25:33 by gmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <iostream>

class ClapTrap
{
	private:
		static const unsigned int default_hp = 10;
		static const unsigned int default_ep = 10;
		static const unsigned int default_damage = 0;

		std::string m_name;
		unsigned int m_hp;
		unsigned int m_ep;
		unsigned int m_damage;

	public:
		ClapTrap(void);
		ClapTrap(std::string name);
		ClapTrap(ClapTrap &src);

		~ClapTrap(void);

		ClapTrap &operator=(ClapTrap &src);

		void attack(const std::string& target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);

		std::string get_name(void);
		unsigned int get_hp(void);
		unsigned int get_ep(void);
		unsigned int get_damage(void);
};

std::ostream &operator<<(std::ostream &out, ClapTrap &ct);

#endif

