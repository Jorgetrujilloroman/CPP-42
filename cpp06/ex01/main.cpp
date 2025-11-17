#include "Serializer.hpp"
#include "Data.hpp"

using std::cout;
using std::endl;

void print_info(Data* ptr) {
    cout << "Name: " << ptr->name << endl;
    cout << "Value: " << ptr->value << endl;
}

int main() {
    Data original_data = {"Project 42", 99};
    Data* original_ptr = &original_data;

    cout << "Original Data:" << endl;
    print_info(original_ptr);
    cout << "Original Address: " << original_ptr << endl;

    cout << "\nSerializing Data's address to a number..." << endl;
    uintptr_t raw_value = Serializer::serialize(original_ptr);
    
    cout << "\nRaw Integer Value: " << raw_value << endl;

    cout << "\nDeserializing the number to retrieve the address..." << endl;
    Data* deserialized_ptr = Serializer::deserialize(raw_value);

    cout << "\nRestored Data:" << endl;
    print_info(deserialized_ptr);
    cout << "Restored Address: " << deserialized_ptr << endl;

    if (original_ptr == deserialized_ptr) {
        cout << "\nPointers match. Success." << endl;
    } else {
        cout << "\nPointers do not match. Failure." << endl;
    }

    return 0;
}