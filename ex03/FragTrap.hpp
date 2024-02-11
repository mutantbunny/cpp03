/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmachado <gmachado@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 04:17:31 by gmachado          #+#    #+#             */
/*   Updated: 2024/02/10 21:57:48 by gmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include "ClapTrap.hpp"

class FragTrap : virtual public ClapTrap
{
	protected:
		static const unsigned int default_hp = 100;
		static const unsigned int default_ep = 100;
		static const unsigned int default_damage = 30;

	public:
		FragTrap(void);
		FragTrap(std::string name);
		FragTrap(FragTrap &src);

		~FragTrap(void);

		FragTrap &operator=(FragTrap &src);

		virtual void attack(const std::string& target);
		void highFivesGuys(void);
};

std::ostream &operator<<(std::ostream &out, FragTrap &st);

#endif
