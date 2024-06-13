#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <cassert>


char getRandomChar(const std::string &charset) {
    return charset[rand() % charset.size()];
}


std::string generatePassword(int length, bool useNumbers, bool useLetters, bool useSpecialChars) {
    std::string numbers = "0123456789";
    std::string letters = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
    std::string specialChars = "!@#$%^&*()-_=+[]{}|;:',.<>?/";
    std::string charset;

    if (useNumbers) charset += numbers;
    if (useLetters) charset += letters;
    if (useSpecialChars) charset += specialChars;

    if (charset.empty()) {
        std::cerr << "Error: No character sets selected." << std::endl;
        return "";
    }

    std::string password;
    for (int i = 0; i < length; ++i) {
        password += getRandomChar(charset);
    }

    return password;
}

void testGeneratePassword() {
    srand(static_cast<unsigned int>(time(0)));

    
    {
        std::string password = generatePassword(10, true, false, false);
        assert(password.length() == 10);
        for (char c : password) {
            assert(isdigit(c));
        }
    }

    {
        std::string password = generatePassword(10, false, true, false);
        assert(password.length() == 10);
        for (char c : password) {
            assert(isalpha(c));
        }
    }

    
    {
        std::string specialChars = "!@#$%^&*()-_=+[]{}|;:',.<>?/";
        std::string password = generatePassword(10, false, false, true);
        assert(password.length() == 10);
        for (char c : password) {
            assert(specialChars.find(c) != std::string::npos);
        }
    }

    {
        std::string numbers = "0123456789";
        std::string letters = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
        std::string specialChars = "!@#$%^&*()-_=+[]{}|;:',.<>?/";
        std::string charset = numbers + letters + specialChars;

        std::string password = generatePassword(10, true, true, true);
        assert(password.length() == 10);
        for (char c : password) {
            assert(charset.find(c) != std::string::npos);
        }
    }

    {
        std::string password = generatePassword(0, true, true, true);
        assert(password.empty());
    }

    
    {
        std::string password = generatePassword(10, false, false, false);
        assert(password.empty());
        std::cerr << "Expected error occurred for no character sets selected." << std::endl;
    }

    std::cout << "All tests passed!" << std::endl;
}

int main() {
    testGeneratePassword();
    return 0;
}