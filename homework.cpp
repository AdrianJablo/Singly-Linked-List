#include "LinkedList.h"

int main() 
{
    // Creating a LinkedList
    LinkedList<int> list = { 3, 42, 1 };

    // Print the list
    std::cout << "List: ";
    list.print();

    // Add element to the front
    list.push_front(99);
    std::cout << "After adding number 99: ";
    list.print();

    // Add element to the back
    list.push_back(7);
    std::cout << "After adding number 7 to the end of list: ";
    list.print(); 

    // Checking size of the list
    std::cout << "List size: " << list.size() << std::endl;

    // Remove the front number
    list.pop_front();
    std::cout << "After removing the front number: ";
    list.print();

    // Split the list at element 42
    auto tail = list.split_when([](const int& value) { return value == 42; });
    std::cout << "List after split: ";
    list.print();

    std::cout << "Tail list after split: ";
    tail.print();

    // Final size check after split
    std::cout << "List size: " << list.size() << std::endl; 
    std::cout << "Tail list size: " << tail.size() << std::endl;     

    return 0;
}
