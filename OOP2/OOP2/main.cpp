#include "Hexagon.h"
#include <iostream>
#include "TSTACK.h"
#include "StackItem.h"

int main(){
    TStack stack;
    Hexagon hex;
    int key;
    std::cout << "0.Exit" << std::endl << "1.push" << std::endl << "2.pop" << std::endl << "3.Print stack" << std::endl;
    while (true) {
        std::cin >> key;
        if (key == 0)
            return 0;
        if (key == 1) {
            std::cin >> hex;
            stack.push(hex);
            std::cout << "pushed" << std::endl;
        }
        if (key == 2) {
            std::cout << stack.pop() << std::endl;
        }
        if (key == 3) {
            std::cout << stack << std::endl;
        }
    }
    return 0;
}

