#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    string filename;
    cout << "Enter the filename: ";
    cin >> filename;

    ifstream infile;
    infile.open(filename);

    if (!infile.is_open()) {
        cout << "Unable to open file" << endl;
        return 0;
    }

    string line;
    int wordCount = 0, lineCount = 0, charCount = 0;

    while (getline(infile, line)) {
        lineCount++;

        charCount += line.size();

        bool word = false;
        for (auto c : line) {
            if (isspace(c)) {
                word = false;
            }
            else if (!word) {
                word = true;
                wordCount++;
            }
        }
    }

    cout << "Words: " << wordCount << endl;
    cout << "Lines: " << lineCount << endl;
    cout << "Characters: " << charCount << endl;

    infile.close();

    return 0;
}
