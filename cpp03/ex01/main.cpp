/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotrujil <jotrujil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 18:26:54 by jotrujil          #+#    #+#             */
/*   Updated: 2025/08/01 11:39:40 by jotrujil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main(void) {
    std::cout << "=== ClapTrap Testing ===" << std::endl;
    
    // Test constructors
    std::cout << "\n--- Constructor Tests ---" << std::endl;
    ClapTrap defaultBot;
    ClapTrap namedBot("Ford Prefect");
    
    // Test copy constructor and assignment
    std::cout << "\n--- Copy Tests ---" << std::endl;
    ClapTrap copyBot(namedBot);
    ClapTrap assignBot;
    assignBot = namedBot;
    
    // Basic functionality tests
    std::cout << "\n--- Basic Actions ---" << std::endl;
    namedBot.attack("Marvin");
    namedBot.takeDamage(3);
    namedBot.beRepaired(2);
    
    // Energy depletion test
    std::cout << "\n--- Energy Depletion Test ---" << std::endl;
    ClapTrap energyBot("EnergyTester");
    for (int i = 1; i <= 11; i++) {
        std::cout << "Attack " << i << ": ";
        energyBot.attack("target");
    }
    
    // No energy left, try to repair
    energyBot.beRepaired(5);
    
    // Death test
    std::cout << "\n--- Death Test ---" << std::endl;
    ClapTrap deadBot("DeadBot");
    deadBot.takeDamage(15);
    deadBot.attack("ghost");
    deadBot.beRepaired(5);
    
    std::cout << "\n--- Destructors ---" << std::endl;
    return 0;
}