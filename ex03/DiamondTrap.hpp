/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmachado <gmachado@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 18:56:10 by gmachado          #+#    #+#             */
/*   Updated: 2023/11/22 04:20:54 by gmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

# include "ScavTrap.hpp"
# include "FragTrap.hpp"

class DiamondTrap: public FragTrap, public ScavTrap
{
	private:
		std::string m_name;

	public:
		DiamondTrap(void);
		DiamondTrap(std::string name);
		DiamondTrap(DiamondTrap &src);

		~DiamondTrap(void);

		DiamondTrap &operator=(DiamondTrap &src);

		void whoAmI();
		void attack(const std::string& target);

		void set_name(std::string name);
		std::string get_name(void);
		std::string get_claptrap_name(void);
};

std::ostream &operator<<(std::ostream &out, DiamondTrap &dt);

#endif