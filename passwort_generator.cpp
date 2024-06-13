#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>


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
int main() {
    srand(static_cast<unsigned int>(time(0)));

    int length;
    char useNumbers, useLetters, useSpecialChars;

    std::cout << "Password Length: ";
    std::cin >> length;

    std::cout << "Include Numbers? (y/n): ";
    std::cin >> useNumbers;

    std::cout << "Include Letters? (y/n): ";
    std::cin >> useLetters;
    
    std::cout << "Include Special Characters? (y/n): ";
    std::cin >> useSpecialChars;

    bool includeNumbers = (useNumbers == 'y' || useNumbers == 'Y');
    bool includeLetters = (useLetters == 'y' || useLetters == 'Y');
    bool includeSpecialChars = (useSpecialChars == 'y' || useSpecialChars == 'Y');

    std::string password = generatePassword(length, includeNumbers, includeLetters, includeSpecialChars);

    if (!password.empty()) {
        std::cout << "Generated Password: " << password << std::endl;
    } else {
        std::cerr << "Error: Unable to generate password." << std::endl;
    }

    return 0;
}
