#include <iostream>
#include <string>
#include "ascii_to_binary.h"

int main()
{
    while (true)
    {
        std::cout << "ASCII To Binary/Binary To ASCII - Berkay Gediz\n";
        std::cout << "Enter the character: ";
        try
        {
            char key;
            std::cin >> key;

            AsciiToBinary(key);
        }
        catch (const std::exception &e)
        {
            std::cout << "Error: " << e.what() << std::endl;
        }
        std::cout << "\nEnter the binary string (8 digit): ";
        try
        {
            std::string binaries;
            std::cin >> binaries;
            BinaryToAscii(binaries);
        }
        catch (const std::exception &e)
        {
            std::cout << "Error: " << e.what() << std::endl;
        }
        std::cout << "\nPress Enter to continue, or Ctrl+C to exit.";
        std::cin.ignore();
        std::cin.get();
    }
    return 0;
}
