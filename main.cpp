#include <iostream>
#include <string>
#include "linear_equation.h"

int main(){
    int number = 0;
    std::string equation;
    std::cout << "Insert equation: ";
    std::getline(std::cin, equation);
    std::cout << "Inserted number is: " << equation << std::endl;
    std::cout << get_left_side_of_equation(equation);
}

