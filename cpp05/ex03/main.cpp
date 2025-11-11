#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

void test_section(const std::string& title) {
    std::cout << "\n=============================================================\n";
    std::cout << "TEST: " << title << "\n";
    std::cout << "=============================================================\n";
}

int main() {
    // Critical: Initialize random seed for RobotomyRequestForm
    std::srand(std::time(NULL)); 

    Intern poor_intern;
    Bureaucrat boss("The Boss", 1);
    AForm* form_ptr = NULL;

    // --- 1. Test Successful Form Creation ---
    test_section("1. Test Successful Form Creation");

	// Case A: Presidential Pardon
	std::cout << "\nCase A: Presidential Pardon" << std::endl;

    try {
        form_ptr = poor_intern.makeForm("presidential pardon", "Ford Prefect");
        
        std::cout << *form_ptr << std::endl;
        boss.signForm(*form_ptr);
        boss.executeForm(*form_ptr); // Requires grade 5
        
        delete form_ptr;
        form_ptr = NULL;
    } catch (std::exception& e) {
        std::cerr << "Caught unexpected exception: " << e.what() << std::endl;
    }

	// Case B: Robotomy Request
    std::cout << "\nCase B: Robotomy Request" << std::endl;
    try {
        form_ptr = poor_intern.makeForm("robotomy request", "Zaphod Beeblebrox");

        std::cout << *form_ptr << std::endl;
        boss.signForm(*form_ptr);
        boss.executeForm(*form_ptr); // Requires grade 45
        
        delete form_ptr;
        form_ptr = NULL;
    } catch (std::exception& e) {
        std::cerr << "Caught unexpected exception: " << e.what() << std::endl;
    }

	// Case C: Shrubbery Creation
	std::cout << "\nCase C: Shrubbery Creation" << std::endl;
    try {
        form_ptr = poor_intern.makeForm("shrubbery creation", "Home_Garden");

        std::cout << *form_ptr << std::endl;
        boss.signForm(*form_ptr);
        boss.executeForm(*form_ptr); // Requires grade 137
        
        delete form_ptr;
        form_ptr = NULL;
    } catch (std::exception& e) {
        std::cerr << "Caught unexpected exception: " << e.what() << std::endl;
    }

    // --- 2. Test Form Not Exists Exception ---
    test_section("2. Test Form Not Exists Exception");

    try {
        form_ptr = poor_intern.makeForm("campero request", "Carpantita");
        
        // This line should not be reached
        std::cout << "Error: Form created successfully: " << *form_ptr << std::endl; 
        delete form_ptr;
    } catch (Intern::FormNotExsist& e) {
        // Expected Catch
        std::cerr << "Caught expected exception: " << e.what() << std::endl;
    } catch (std::exception& e) {
        std::cerr << "Caught unexpected generic exception: " << e.what() << std::endl;
    }

    return 0;
}