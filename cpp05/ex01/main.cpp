#include "Bureaucrat.hpp"
#include "Form.hpp"

void test_title(const std::string& title) {
    std::cout << "\n--- " << title << " ---\n" << std::endl;
}

int main() {
    
    // --- 1. Test Form Validation (Constructor Exceptions) ---
    test_title("1. Testing Form Constructor Exceptions");
    
    try {
        // Case A: Grade Too High (Sign: 0)
        Form f_invalid_high("HighPriority", 0, 100);
        std::cout << "Error: Should not be created: " << f_invalid_high << std::endl;
    } catch (std::exception &e) {
        std::cerr << "Caught expected exception: " << e.what() << std::endl;
    }

    try {
        // Case B: Grade Too Low (Exec: 151)
        Form f_invalid_low("LowPriority", 50, 151);
        std::cout << "Error: Should not be created: " << f_invalid_low << std::endl;
    } catch (std::exception &e) {
        std::cerr << "Caught expected exception: " << e.what() << std::endl;
    }
    
    // --- 2. Test Successful Signing ---
    test_title("2. Testing Successful Signing (beSigned/signForm)");

    try {
        Bureaucrat b_boss("Mr. Boss", 5);
        Form f1("VacationRequest", 10, 5); // Requires grade 10 or better (lower number)
        
        std::cout << b_boss << std::endl;
        std::cout << f1 << std::endl;
        
        b_boss.signForm(f1);
        
        std::cout << f1 << std::endl;
    } catch (std::exception &e) {
        std::cerr << "Caught unexpected exception: " << e.what() << std::endl;
    }

    // --- 3. Test Failed Signing (GradeTooLowException) ---
    test_title("3. Testing Failed Signing (Grade Too Low)");

    try {
        Bureaucrat b_intern("Intern Dan", 140);
        Form f2("BudgetApproval", 50, 50); // Requires grade 50 or better
        
        std::cout << b_intern << std::endl;
        std::cout << f2 << std::endl;
        
        // This call should result in b_intern.signForm() calling f2.beSigned() which throws
        b_intern.signForm(f2);
        
        std::cout << f2 << std::endl; // Should remain unsigned
    } catch (std::exception &e) {
        std::cerr << "Caught unexpected exception: " << e.what() << std::endl;
    }

    // --- 4. Test Double Signing ---
    test_title("4. Testing Signing an Already Signed Form");
    
    try {
        Bureaucrat b_admin("Ms. Admin", 20);
        Form f3("TravelVoucher", 30, 10);
        
        b_admin.signForm(f3); // First sign (success)
        
        // Second attempt to sign (should be caught/handled inside beSigned/signForm)
        std::cout << "Attempting to sign again:" << std::endl;
        b_admin.signForm(f3);
        
        std::cout << f3 << std::endl;
    } catch (std::exception &e) {
        std::cerr << "Caught unexpected exception: " << e.what() << std::endl;
    }

    return 0;
}