/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotrujil <jotrujil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 18:26:54 by jotrujil          #+#    #+#             */
/*   Updated: 2025/08/01 18:13:31 by jotrujil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int main(void) {
    std::cout << "--- ClapTrap Tests ---" << std::endl;
    ClapTrap clap("Basic");
    clap.attack("dummy");
    clap.takeDamage(5);
    clap.beRepaired(3);
    
    std::cout << "\n--- ScavTrap Tests ---" << std::endl;
    ScavTrap scav("Destroyer");
    scav.attack("enemy");
    scav.takeDamage(30);
    scav.beRepaired(10);
    scav.guardGate();
    
    std::cout << "\n--- Copy Tests ---" << std::endl;
    ScavTrap copy1(scav);
    ScavTrap copy2;
    copy2 = scav;
    
    std::cout << "\n--- Energy Test ---" << std::endl;
    ScavTrap tired("Exhausted");
    for (int i = 0; i < 52; i++) {
        tired.attack("target");
    }
    
    std::cout << "\n--- Death Test ---" << std::endl;
    ScavTrap dead("RIP");
    dead.takeDamage(150);
    dead.attack("ghost");
    dead.guardGate();
    
    std::cout << "\n--- Destruction Chain ---" << std::endl;
    return 0;
}