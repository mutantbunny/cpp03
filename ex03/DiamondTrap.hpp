/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmachado <gmachado@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 18:56:10 by gmachado          #+#    #+#             */
/*   Updated: 2024/02/21 21:34:49 by gmachado         ###   ########.fr       */
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
		void set_name(std::string name);

	public:
		DiamondTrap(void);
		DiamondTrap(std::string name);
		DiamondTrap(DiamondTrap &src);

		~DiamondTrap(void);

		DiamondTrap &operator=(DiamondTrap &src);

		void whoAmI();
		virtual void attack(const std::string& target);


		virtual std::string get_name(void);
		std::string get_claptrap_name(void);
};

std::ostream &operator<<(std::ostream &out, DiamondTrap &dt);

#endif