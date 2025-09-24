/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotrujil <jotrujil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 19:23:34 by jotrujil          #+#    #+#             */
/*   Updated: 2025/09/24 12:44:40 by jotrujil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

int main()
{
    std::cout << "--- Basic Polymorphism Test ---" << std::endl;
    const Animal* meta = new Animal();
    const Animal* j = new Dog();
    const Animal* i = new Cat();
    
    std::cout << j->getType() << " " << std::endl;
	j->makeSound();
    std::cout << i->getType() << " " << std::endl;
    i->makeSound();
    std::cout << meta->getType() << " " << std::endl;
    meta->makeSound();
    
    delete meta;
    delete j;
    delete i;
    
    std::cout << "\n--- Wrong Classes Test ---" << std::endl;
    const WrongAnimal* wrongMeta = new WrongAnimal();
    const WrongAnimal* wrongCat = new WrongCat();
    
    std::cout << wrongCat->getType() << " " << std::endl;
    wrongCat->makeSound(); // Should output WrongAnimal sound
	std::cout << wrongMeta->getType() << " " << std::endl;
    wrongMeta->makeSound();
    
    delete wrongMeta;
    delete wrongCat;
    
    std::cout << "\n--- Direct Object Test ---" << std::endl;
    Animal animal;
    Dog dog;
    Cat cat;
    
    animal.makeSound();
    dog.makeSound();
    cat.makeSound();
    
    std::cout << "\n--- Constructor/Destructor Test ---" << std::endl;
    {
        Animal* ptr = new Dog();
        ptr->makeSound();
        delete ptr;
    }
    
    std::cout << "\n--- Type Test ---" << std::endl;
    Animal* animals[3];
    animals[0] = new Animal();
    animals[1] = new Dog();
    animals[2] = new Cat();
    
    for (int i = 0; i < 3; i++) {
        std::cout << "Type: " << animals[i]->getType() << " - Sound: ";
        animals[i]->makeSound();
    }
    
    for (int i = 0; i < 3; i++) {
        delete animals[i];
    }
    
    return 0;
}