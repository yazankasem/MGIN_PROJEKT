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