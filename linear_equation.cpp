#include "linear_equation.h"

bool isValidEquation(std::string equation) {
    std::size_t found_invalid_char = equation.find_first_not_of("01234567890xX=+-*/^() ");
    std::size_t first_equal = equation.find_first_of("=");
    std::size_t last_equal = equation.find_last_of("=");

    // Debug
    /*
    std::cout << "found_invalid_char=" << found_invalid_char << std::endl;
    std::cout << "found_invalid_char=" << first_equal << std::endl;
    std::cout << "found_invalid_char=" << last_equal << std::endl;
    */

    // Check if an invalid symbol is in the equation
    if(found_invalid_char == std::string::npos)
        // Check if multiple "=" signs are in the equation
        if(first_equal == last_equal)
            // TODO check for multiple + or - signs, a bit like a syntax for equations
            return true;
        else
            // Multiple "=" signs found, invalid equation
            return false;
    else
        // Invalid symbol found in equation, invalid equation
        return false;
}

// If an equation is one sided, it is considered to be equal to 0 on the right side
bool isOneSidedEquation(std::string equation) {
    std::size_t first_equal = equation.find_first_of("=");
    if(first_equal == std::string::npos)
        return true;
    else
        return false;
}

unsigned int countAmountOfSymbols(std::string text, std::string symbol) {
    unsigned int counter = 0;
    std::size_t position = text.find(symbol);

    while(position != std::string::npos) {
        counter++;
        position = text.find(symbol, position+1);
    }
    return counter;
}

unsigned int amountOfTerms(std::string equation, bool isMinusFirstSymbol) {
    unsigned int counter_plus = countAmountOfSymbols(equation, "+");
    unsigned int counter_minus = countAmountOfSymbols(equation, "-");

    if(isMinusFirstSymbol) {
        return counter_plus + counter_minus;
    } else {
        return counter_plus + counter_minus + 1;
    }
}

bool isMinusFirstSymbol(std::string equation) {
    bool res = false;
    std::size_t minus = equation.find("-");
    if(minus == 0)
        res = true;  

    return res;
}

void printTerms(std::string equation, bool isMinusFirstSymbol) {
    std::size_t next_plus_position = 0;
    std::size_t next_minus_position = (isMinusFirstSymbol) ? 1 : 0; // Short Hand If Else
    std::size_t next_position = 1;

    unsigned int counter = 0;

    std::string term = "";

    next_plus_position = equation.find("+");
    next_minus_position = equation.find("-", next_minus_position);

    std::cout << "next_plus_position=" << next_plus_position << " - next_minus_position=" << next_minus_position << " - next_position=" << next_position << std::endl;

    std::cout << std::endl;
    while(next_plus_position != std::string::npos || next_minus_position != std::string::npos) {
        std::cout << "equation[next_position-1]=" << equation[next_position-1] << " ; next_position-1=" << next_position-1 << std::endl;
        term = (equation[next_position-1] == '-') ? "-" : "";

        if(next_plus_position < next_minus_position) {
            term += equation.substr(next_position, next_plus_position-next_position);
            next_position = next_plus_position + 1;
            next_plus_position = equation.find("+",next_position);
        } else {
            term += equation.substr(next_position, next_minus_position-next_position);
            next_position = next_minus_position + 1;
            next_minus_position = equation.find("-",next_position);
        }
        
        std::cout << "Term " << counter << ": " << term << std::endl; 
        std::cout << "next_plus_position=" << next_plus_position << " - next_minus_position=" << next_minus_position << " - next_position=" << next_position << std::endl;

        counter++;
        std::cout << std::endl;
    }

    term = (equation[next_position-1] == '-') ? "-" : "";
    term += equation.substr(next_position, equation.length()-next_position);
    std::cout << "Term " << counter << ": " << term << std::endl; 
}

// TODO
int calcConstantTerms(std::string equation, bool isMinusFirstSymbol) {
    int sum = 0;
    std::size_t first_position = 0;
    std::size_t second_position = 0;

    return 0;
}

// TODO
std::string simplifyEquation(std::string equation) {
    std::string res = "";

    bool isMinusFirstSymbol = false;
    std::size_t minus = equation.find("-");
    if(minus == 0)
        isMinusFirstSymbol = true;
    std::cout << "isMinusFirstSymbol=" << isMinusFirstSymbol << std::endl;

    unsigned int numberOfTerms = 0;
    

    return res;
}

std::string get_left_side_of_equation(std::string equation) {
    std::string res = "Invalid equation";
    std::size_t found = equation.find("=");

    if(found != std::string::npos) {
        std::cout << "Equal (=) sign found at position: " << found << std::endl;
        res = equation.substr(0, found);
    }
    else
        return res;

    return res;
}