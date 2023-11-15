/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmachado <gmachado@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 22:26:37 by gmachado          #+#    #+#             */
/*   Updated: 2023/11/15 02:39:54 by gmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <iostream>

class ClapTrap
{
	private:
		std::string _name;
		unsigned int _hp;
		unsigned int _ep;
		unsigned int _damage;
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

