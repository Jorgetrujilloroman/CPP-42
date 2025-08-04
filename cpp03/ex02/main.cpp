/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotrujil <jotrujil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 18:26:54 by jotrujil          #+#    #+#             */
/*   Updated: 2025/08/04 16:36:52 by jotrujil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include "FragTrap.hpp"

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
    
    std::cout << "\n--- FragTrap Tests ---" << std::endl;
    FragTrap frag("Boomer");
    frag.attack("target");
    frag.takeDamage(50);
    frag.beRepaired(20);
    frag.highFivesGuys();
    
    std::cout << "\n--- Copy Tests ---" << std::endl;
    FragTrap copy1(frag);
    FragTrap copy2;
    copy2 = frag;
    
    std::cout << "\n--- Energy Test ---" << std::endl;
    FragTrap tired("Exhausted");
    for (int i = 0; i < 102; i++) {
        tired.attack("target");
    }
    
    std::cout << "\n--- Death Test ---" << std::endl;
    FragTrap dead("RIP");
    dead.takeDamage(200);
    dead.attack("ghost");
    dead.highFivesGuys();
    
    std::cout << "\n--- End ---" << std::endl;
    return 0;
}