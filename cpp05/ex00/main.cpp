#include "Bureaucrat.hpp"
#include <iostream>

void testCase(const std::string& title, void (*func)()) {
    std::cout << "\n=========================================\n";
    std::cout << "TEST: " << title << "\n";
    std::cout << "=========================================\n";
    try {
        func();
    }
    catch (std::exception &e) {
        // Catch-all block for unexpected exceptions
        std::cerr << "!!! UNEXPECTED EXCEPTION: " << e.what() << std::endl;
    }
}

// Helper function to test valid operations
void testValidOperations() {
    Bureaucrat worker("John Doe", 75);
    std::cout << "Initial status: " << worker << std::endl;

    // Valid increment
    worker.incrementGrade();
    std::cout << "Current status: " << worker << std::endl;
    
    // Valid decrement
    worker.decrementGrade();
    std::cout << "Current status: " << worker << std::endl;
}

// Helper function to test constructor failures
void testInvalidConstruction() {
    std::cout << "--- Testing GradeTooHighException (Grade 0) ---\n";
    try {
        Bureaucrat b_high("Zero", 0);
        std::cout << "ERROR: Object created successfully.\n"; // Should not reach
    }
    catch (Bureaucrat::GradeTooHighException &e) {
        std::cerr << "Caught expected exception: " << e.what() << std::endl;
    }

    std::cout << "\n--- Testing GradeTooLowException (Grade 151) ---\n";
    try {
        Bureaucrat b_low("OneFiftyOne", 151);
        std::cout << "ERROR: Object created successfully.\n"; // Should not reach
    }
    catch (Bureaucrat::GradeTooLowException &e) {
        std::cerr << "Caught expected exception: " << e.what() << std::endl;
    }
}

// Helper function to test modification failures
void testInvalidModification() {
    // Test incrementing grade 1
    std::cout << "--- Testing Increment Grade 1 ---\n";
    try {
        Bureaucrat top_bureaucrat("The Boss", 1);
        top_bureaucrat.incrementGrade(); // Should throw
    }
    catch (Bureaucrat::GradeTooHighException &e) {
        std::cerr << "Caught expected exception: " << e.what() << std::endl;
    }

    // Test decrementing grade 150
    std::cout << "\n--- Testing Decrement Grade 150 ---\n";
    try {
        Bureaucrat low_bureaucrat("The Intern", 150);
        low_bureaucrat.decrementGrade(); // Should throw
    }
    catch (Bureaucrat::GradeTooLowException &e) {
        std::cerr << "Caught expected exception: " << e.what() << std::endl;
    }
}


int main() {
    testCase("Valid Operations and Insertion Operator", testValidOperations);
    testCase("Invalid Construction", testInvalidConstruction);
    testCase("Invalid Grade Modification", testInvalidModification);

    return 0;
}