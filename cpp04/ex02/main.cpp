/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotrujil <jotrujil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 19:23:34 by jotrujil          #+#    #+#             */
/*   Updated: 2025/10/14 19:58:22 by jotrujil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main() {
    std::cout << "=== Abstract Animal Test ===\n" << std::endl;
    
    // This should NOT compile (Animal is abstract):
    // AAnimal animal;
    
    // But polymorphism still works:
    const AAnimal* dog = new Dog();
    const AAnimal* cat = new Cat();
    
    dog->makeSound();
    cat->makeSound();
    
    delete dog;
    delete cat;
    
    std::cout << "\n✅ Animal is abstract but polymorphism works!" << std::endl;
    
    return 0;
}