#include<iostream>
#include"list.h"

template<typename T>
void printVals(const std::vector<T>& vals) {
    std::cout << "[ ";
    for(const auto& v : vals) std::cout << v << " ";
    std::cout << "]\n";
}

int main() {
    std::cout << "===== 1. Default Constructor =====\n";
    DoublyLinkedList<int> list;
    std::cout << "size(): " << list.size() << "\n";
    std::cout << "empty(): " << std::boolalpha << list.empty() << "\n\n";

    std::cout << "===== 2. insert() =====\n";
    list.insert(10, 1);              // insert into empty list
    list.insert(20, 2);              // insert at end
    list.insert(5, 1);               // insert at front
    list.insert(15, 3);              // insert in the middle
    std::cout << "Forward values after inserts: ";
    printVals(list.values());
    std::cout << "size(): " << list.size() << "\n\n";

    std::cout << "===== 3. Invalid insert() (out_of_range) =====\n";
    try {
        list.insert(100, 99);
    } catch(const std::out_of_range& e) {
        std::cout << "Caught exception: " << e.what();
    }
    std::cout << "\n";

    std::cout << "===== 4. search() =====\n";
    std::cout << "search(15): position " << list.search(15) << "\n";
    std::cout << "search(999): position " << list.search(999) << " (not found)\n\n";

    std::cout << "===== 5. values() with reverse=true =====\n";
    std::cout << "Reverse values: ";
    printVals(list.values(true));
    std::cout << "\n";

    std::cout << "===== 6. Copy Constructor =====\n";
    DoublyLinkedList<int> listCopy(list);
    std::cout << "Copied list values: ";
    printVals(listCopy.values());
    listCopy.remove(1); // modify the copy
    std::cout << "After removing from copy, copy: ";
    printVals(listCopy.values());
    std::cout << "Original list is unaffected: ";
    printVals(list.values());
    std::cout << "\n";

    std::cout << "===== 7. remove() =====\n";
    std::cout << "Before removal: ";
    printVals(list.values());
    list.remove(1);                  // remove front
    std::cout << "After removing pos 1 (front): ";
    printVals(list.values());
    list.remove(list.size());        // remove back
    std::cout << "After removing last position (back): ";
    printVals(list.values());
    list.insert(99, 1);
    list.insert(100, 2);
    std::cout << "Before middle removal: ";
    printVals(list.values());
    list.remove(2);                  // remove middle
    std::cout << "After removing pos 2 (middle): ";
    printVals(list.values());
    std::cout << "\n";

    std::cout << "===== 8. Invalid remove() (out_of_range) =====\n";
    try {
        list.remove(50);
    } catch(const std::out_of_range& e) {
        std::cout << "Caught exception: " << e.what();
    }
    std::cout << "\n";

    std::cout << "===== 9. clear() =====\n";
    list.clear();
    std::cout << "size() after clear(): " << list.size() << "\n";
    std::cout << "empty() after clear(): " << list.empty() << "\n\n";

    std::cout << "===== 10. remove() on empty list (underflow_error) =====\n";
    try {
        list.remove(1);
    } catch(const std::underflow_error& e) {
        std::cout << "Caught exception: " << e.what();
    }
    std::cout << "\n";

    std::cout << "===== 11. Works with other types (std::string) =====\n";
    DoublyLinkedList<std::string> strList;
    strList.insert("world", 1);
    strList.insert("hello", 1);
    strList.insert("!", 3);
    std::cout << "String list: ";
    printVals(strList.values());

    return 0;
}