#include <iostream>
#include <string>
#include <random>

std::string generate_password(int length, std::string complexity) {
    std::string chars;
    if (complexity == "low") {
        chars = "abcdefghijklmnopqrstuvwxyz";
    } else if (complexity == "medium") {
        chars = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
    } else if (complexity == "high") {
        chars = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789!\"#$%&'()*+,-./:;<=>?@[\\]^_`{|}~";
    }

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(0, chars.size() - 1);

    std::string password;
    for (int i = 0; i < length; ++i) {
        password += chars[dis(gen)];
    }
    return password;
}

int main() {
    int length;
    while (true) {
        std::cout << "Enter password length: ";
        if (!(std::cin >> length) || length <= 0) {
            std::cout << "Invalid password length. Please enter a positive integer greater than zero." << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        } else {
            break;
        }
    }

    std::string complexity;
    while (true) {
        std::cout << "Enter password complexity (low, medium, high): ";
        if (!(std::cin >> complexity) || (complexity != "low" && complexity != "medium" && complexity != "high")) {
            std::cout << "Invalid complexity level. Please choose from 'low', 'medium', or 'high'." << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        } else {
            break;
        }
    }

    std::string password = generate_password(length, complexity);
    std::cout << "Your generated password is: " << password << std::endl;

    return 0;
}
