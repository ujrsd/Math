#include <iostream>
#include <string>

std::string get_left_side_of_equation(std::string equation);
std::string simplifyEquation(std::string equation);

unsigned int countAmountOfSymbols(std::string text, std::string symbol);
unsigned int amountOfTerms(std::string equation, bool isMinusFirstSymbol);

bool isValidEquation(std::string equation);
bool isOneSidedEquation(std::string equation);
bool isMinusFirstSymbol(std::string equation);

void printTerms(std::string equation, bool isMinusFirstSymbol);
