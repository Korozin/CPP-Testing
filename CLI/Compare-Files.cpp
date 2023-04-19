#include <iostream>
#include <fstream>
#include <string>

int main() {
    std::ifstream file1("file1.txt");
    std::ifstream file2("file2.txt");

    bool same = true;
    std::string line1, line2;
    for (int i = 1; std::getline(file1, line1) && std::getline(file2, line2); i++) {
        if (line1 != line2) {
            same = false;
            std::cout << "Line " << i << ":\n";
            std::cout << "File 1: " << line1 << "\n";
            std::cout << "File 2: " << line2 << "\n";
        }
    }

    if (same) {
        std::cout << "The files are the same.\n";
    } else {
        std::cout << "The files are different.\n";
    }

    return 0;
}
