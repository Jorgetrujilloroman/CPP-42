/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotrujil <jotrujil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 18:26:54 by jotrujil          #+#    #+#             */
/*   Updated: 2025/08/04 17:49:07 by jotrujil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

int main(void) {
    std::cout << "--- DiamondTrap Basic Tests ---" << std::endl;
    DiamondTrap diamond("Robot");
    diamond.whoAmI();
    diamond.attack("enemy");
    diamond.takeDamage(30);
    diamond.beRepaired(15);
    diamond.guardGate();
    diamond.highFivesGuys();
    
    std::cout << "\n--- Default Constructor ---" << std::endl;
    DiamondTrap def;
    def.whoAmI();
    def.attack("target");
    
    std::cout << "\n--- Copy Tests ---" << std::endl;
    DiamondTrap copy1(diamond);
    copy1.whoAmI();
    DiamondTrap copy2;
    copy2 = diamond;
    copy2.whoAmI();
    
    std::cout << "\n--- Attribute Tests ---" << std::endl;
    DiamondTrap attr("Tester");
    std::cout << "Testing hit points (should be 100):" << std::endl;
    attr.takeDamage(50);
    std::cout << "Testing energy points (should be 50):" << std::endl;
    for (int i = 0; i < 52; i++) {
        attr.attack("dummy");
    }
    std::cout << "Testing attack damage (should be 30):" << std::endl;
    DiamondTrap dmg("Damage");
    dmg.attack("test");
    
    std::cout << "\n--- Death Test ---" << std::endl;
    DiamondTrap dead("Dead");
    dead.takeDamage(150);
    dead.attack("ghost");
    dead.whoAmI();
    
    std::cout << "\n--- End ---" << std::endl;
    return 0;
}