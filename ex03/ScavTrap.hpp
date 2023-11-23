/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmachado <gmachado@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 04:17:31 by gmachado          #+#    #+#             */
/*   Updated: 2023/11/23 03:35:39 by gmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include "ClapTrap.hpp"

class ScavTrap : virtual public ClapTrap
{
	protected:
		static const unsigned int default_hp = 100;
		static const unsigned int default_ep = 50;
		static const unsigned int default_damage = 20;

	public:
		ScavTrap(void);
		ScavTrap(std::string name);
		ScavTrap(ScavTrap &src);

		~ScavTrap(void);

		ScavTrap &operator=(ScavTrap &src);

		void guardGate();
};

std::ostream &operator<<(std::ostream &out, ScavTrap &st);

#endif
