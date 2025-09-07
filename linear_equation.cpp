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