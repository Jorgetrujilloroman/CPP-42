/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotrujil <jotrujil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 19:23:34 by jotrujil          #+#    #+#             */
/*   Updated: 2025/09/24 13:53:56 by jotrujil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "Brain.hpp"

int main() {
    std::cout << "=== CPP04 Exercise 01: Brain Tests ===\n" << std::endl;
    
    // Test 1: Basic requirements from subject
    std::cout << "--- Basic Test (from subject) ---" << std::endl;
    const Animal* j = new Dog();
    const Animal* i = new Cat();
    
    j->makeSound();
    i->makeSound();
    
    delete j; // should not create a leak
    delete i;
    
    // Test 2: Array of Animals (half dogs, half cats)
    std::cout << "\n--- Array Test (Half Dogs, Half Cats) ---" << std::endl;
    const int size = 4;
    Animal* animals[size];
    
    std::cout << "Creating animals array:" << std::endl;
    for (int i = 0; i < size / 2; i++) {
        animals[i] = new Dog();
    }
    for (int i = size / 2; i < size; i++) {
        animals[i] = new Cat();
    }
    
    std::cout << "\nTesting sounds:" << std::endl;
    for (int i = 0; i < size; i++) {
        std::cout << animals[i]->getType() << ": ";
        animals[i]->makeSound();
    }
    
    std::cout << "\nDeleting animals:" << std::endl;
    for (int i = 0; i < size; i++) {
        delete animals[i];
    }
    
    // Test 3: Deep Copy Test (most important)
    std::cout << "\n--- Deep Copy Test ---" << std::endl;
    
    // Test Dog deep copy
    std::cout << "Testing Dog deep copy:" << std::endl;
    Dog* original = new Dog();
    original->getBrain()->setIdea(0, "Original idea");
    original->getBrain()->setIdea(1, "Another idea");
    
    std::cout << "Original dog idea 0: " << original->getBrain()->getIdea(0) << std::endl;
    
    // Copy constructor test
    Dog copied(*original);
    std::cout << "Copied dog idea 0: " << copied.getBrain()->getIdea(0) << std::endl;
    
    // Modify original
    original->getBrain()->setIdea(0, "MODIFIED");
    
    std::cout << "After modifying original:" << std::endl;
    std::cout << "Original: " << original->getBrain()->getIdea(0) << std::endl;
    std::cout << "Copied: " << copied.getBrain()->getIdea(0) << std::endl;
    
    if (copied.getBrain()->getIdea(0) != original->getBrain()->getIdea(0)) {
        std::cout << "✅ Deep copy SUCCESS!" << std::endl;
    } else {
        std::cout << "❌ Shallow copy detected!" << std::endl;
    }
    
    // Assignment operator test
    Dog assigned;
    assigned = *original;
    original->getBrain()->setIdea(0, "MODIFIED AGAIN");
    
    if (assigned.getBrain()->getIdea(0) != original->getBrain()->getIdea(0)) {
        std::cout << "✅ Assignment operator deep copy SUCCESS!" << std::endl;
    } else {
        std::cout << "❌ Assignment operator shallow copy!" << std::endl;
    }
    
    delete original;
    
    // Test Cat deep copy
    std::cout << "\nTesting Cat deep copy:" << std::endl;
    Cat cat1;
    cat1.getBrain()->setIdea(0, "Cat idea");
    
    Cat cat2(cat1);
    cat1.getBrain()->setIdea(0, "Modified cat idea");
    
    if (cat2.getBrain()->getIdea(0) != cat1.getBrain()->getIdea(0)) {
        std::cout << "✅ Cat deep copy SUCCESS!" << std::endl;
    } else {
        std::cout << "❌ Cat shallow copy detected!" << std::endl;
    }
    
    // Test 4: Brain functionality
    std::cout << "\n--- Brain Functionality Test ---" << std::endl;
    Dog dog;
    Cat cat;
    
    dog.getBrain()->setIdea(0, "Chase ball");
    dog.getBrain()->setIdea(1, "Protect house");
    cat.getBrain()->setIdea(0, "Hunt mice");
    cat.getBrain()->setIdea(1, "Sleep");
    
    std::cout << "Dog ideas:" << std::endl;
    std::cout << "  0: " << dog.getBrain()->getIdea(0) << std::endl;
    std::cout << "  1: " << dog.getBrain()->getIdea(1) << std::endl;
    
    std::cout << "Cat ideas:" << std::endl;
    std::cout << "  0: " << cat.getBrain()->getIdea(0) << std::endl;
    std::cout << "  1: " << cat.getBrain()->getIdea(1) << std::endl;
    
    std::cout << "\n=== All tests completed! ===\n" << std::endl;
    std::cout << "Run with valgrind to check for memory leaks." << std::endl;
    
    return 0;
}