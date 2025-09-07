#include "linear_equation.h"

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