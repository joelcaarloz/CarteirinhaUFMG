#include <iostream>
#include <string>

int main() {
    std::string minhaString = "123456789";

    // Usando length()
    std::cout << "Comprimento da string usando length(): " << minhaString.length() << std::endl;

    // Usando size()
    std::cout << "Comprimento da string usando size(): " << minhaString.size() << std::endl;

    return 0;
}