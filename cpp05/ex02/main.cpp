#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <ctime>
#include <cstdlib>

void test_section(const std::string& title) {
    std::cout << "\n=============================================================\n";
    std::cout << "TEST: " << title << "\n";
    std::cout << "=============================================================\n";
}

int main() {
    // CRITICAL: Initialize random seed for RobotomyRequestForm
    std::srand(std::time(NULL)); 

    // --- 1. Testing Grade Too Low (Sign/Execute) ---
    test_section("1. Test Grade Too Low (Signing & Executing)");
    
    try {
        Bureaucrat intern("Bob the Intern", 150);
        ShrubberyCreationForm f1("Garden");
        
        std::cout << intern << std::endl;
        std::cout << f1 << std::endl;
        
        // Fails to sign (needs 145)
        intern.signForm(f1); 
        
        // Fails to execute (needs 137)
        intern.executeForm(f1); 
        
    } catch (std::exception& e) {
        std::cerr << "Caught unexpected exception: " << e.what() << std::endl;
    }

    // --- 2. Testing Execution Failure (Not Signed) ---
    test_section("2. Test Form Not Signed Exception");
    
    try {
        Bureaucrat mid_level("Puidgemont", 50);
        RobotomyRequestForm f2("Target_X"); // Needs sign 72, exec 45
        
        std::cout << mid_level << std::endl;
        
        // Alice CAN sign (50 <= 72) but doesn't
        // Alice CANNOT execute (50 > 45) but we test the 'Not Signed' first
        
        mid_level.executeForm(f2); // Should throw FormNotSignedException
        
    } catch (std::exception& e) {
        std::cerr << "Caught unexpected exception: " << e.what() << std::endl;
    }


    // --- 3. Test Successful Execution (Polymorphism & File Creation) ---
    test_section("3. Test Successful Shrubbery Creation");
    
    try {
        Bureaucrat worker("Gardener", 130); // Grade 130 is high enough for Shrubbery
        ShrubberyCreationForm f3("Park");
        
        worker.signForm(f3);
        std::cout << f3 << std::endl;
        
        worker.executeForm(f3); // Creates file 'Park_shrubbery'
        
    } catch (std::exception& e) {
        std::cerr << "Caught unexpected exception: " << e.what() << std::endl;
    }

    // --- 4. Test High Grade Required Execution (Presidential Pardon) ---
    test_section("4. Test Presidential Pardon (High Grade Exec)");
    
    AForm* f4 = NULL;
    try {
        Bureaucrat chief("The Chief", 6);
        Bureaucrat president("Pedro Sanxe", 1);
        
        f4 = new PresidentialPardonForm("Criminal"); // Needs sign 25, exec 5
        
        chief.signForm(*f4); // Chief CAN sign (6 <= 25)
        
        // Chief cannot execute (6 > 5) -> GradeTooLowException
        chief.executeForm(*f4); 

        // President CAN execute (1 <= 5)
        president.executeForm(*f4); 

    } catch (std::exception& e) {
        std::cerr << "Caught exception: " << e.what() << std::endl;
    }
    if (f4) delete f4; // Cleanup

    // --- 5. Test Robotomy (50% Chance) ---
    test_section("5. Test Robotomy (Requires Sign 72, Exec 45)");

    AForm* f5 = new RobotomyRequestForm("Subject_A");
    AForm* f6 = new RobotomyRequestForm("Subject_B");
    Bureaucrat surgeon("Dr. Surgeon", 40); // Grade 40 is good for both sign (72) and exec (45)

    try {
        surgeon.signForm(*f5);
        surgeon.signForm(*f6);

        std::cout << "--- Executing first subject (50/50):" << std::endl;
        surgeon.executeForm(*f5); 

        std::cout << "--- Executing second subject (50/50):" << std::endl;
        surgeon.executeForm(*f6); 
        
    } catch (std::exception& e) {
        std::cerr << "Caught exception: " << e.what() << std::endl;
    }

    delete f5;
    delete f6;
    
    return 0;
}