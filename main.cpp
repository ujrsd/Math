#include <iostream>
#include <string>
#include "linear_equation.h"

int main(){
    int number = 0;
    std::string equation;
    std::cout << "Insert equation: ";
    std::getline(std::cin, equation);

    if(isValidEquation(equation))
    {
        bool isOneSided = isOneSidedEquation(equation);
        std::cout << "One sided equation? ";
        if(isOneSided) {
            bool firstPosMinus = isMinusFirstSymbol(equation);
            unsigned int numberOfTerms = amountOfTerms(equation, firstPosMinus);
            std::cout << "Yes" << std::endl;
            std::cout << "Amount of '+' symbols in equation: " << countAmountOfSymbols(equation,"+") << std::endl;
            std::cout << "Amount of '-' symbols in equation: " << countAmountOfSymbols(equation,"-") << std::endl;
            std::cout << "Amount of terms in equation: " << numberOfTerms << std::endl;

            printTerms(equation, firstPosMinus);
            simplifyEquation(equation);
        }
        else
            std::cout << "No" << std::endl;
        std::cout << get_left_side_of_equation(equation);
        return 1;
    }
    else
    {
        std::cout << "Invalid characters found in given equation!";
        return -1;
    }
}

