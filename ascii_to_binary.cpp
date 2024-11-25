#include <iostream>
#include <bitset>
#include <cmath>
#include "ascii_to_binary.h"

void AsciiToBinary(char key)
{
    try
    {
        unsigned char asciivalue = static_cast<unsigned char>(key);
        std::bitset<8> binary(asciivalue);
        std::cout << "Binary: " << binary << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cout << "Error: " << e.what() << std::endl;
    }
}

void BinaryToAscii(const std::string &binary)
{
    try
    {
        if (binary.length() != 8)
        {
            throw std::invalid_argument("Binary string must be 8 digits long.");
        }

        int asciivalue = 0;
        for (int i = 0; i < 8; ++i)
        {
            if (binary[i] == '1')
            {
                asciivalue += static_cast<int>(std::pow(2, 7 - i));
            }
            else if (binary[i] != '0')
            {
                throw std::invalid_argument("Binary string must only contain '0' or '1'.");
            }
        }
        std::cout << "ASCII: " << asciivalue << " - Char: " << static_cast<char>(asciivalue) << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cout << "Error: " << e.what() << std::endl;
    }
}
