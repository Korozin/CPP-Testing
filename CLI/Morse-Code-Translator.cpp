#include <iostream>
#include <map>
#include <string>

using namespace std;

// Function to convert text to Morse code
string textToMorse(string text, map<char, string> morseMap)
{
    string morse = "";
    for (char c : text)
    {
        if (c == ' ')
        {
            morse += "/ ";
        }
        else
        {
            morse += morseMap[toupper(c)] + " ";
        }
    }
    return morse;
}

// Function to convert Morse code to text
string morseToText(string morse, map<string, char> morseMap)
{
    string text = "";
    string curr = "";
    for (char c : morse)
    {
        if (c == ' ')
        {
            text += morseMap[curr];
            curr = "";
        }
        else if (c == '/')
        {
            text += ' ';
        }
        else
        {
            curr += c;
        }
    }
    text += morseMap[curr];
    return text;
}

int main()
{
    // Define the Morse code map
    map<char, string> morseMap = {
        {'A', ".-"},
        {'B', "-..."},
        {'C', "-.-."},
        {'D', "-.."},
        {'E', "."},
        {'F', "..-."},
        {'G', "--."},
        {'H', "...."},
        {'I', ".."},
        {'J', ".---"},
        {'K', "-.-"},
        {'L', ".-.."},
        {'M', "--"},
        {'N', "-."},
        {'O', "---"},
        {'P', ".--."},
        {'Q', "--.-"},
        {'R', ".-."},
        {'S', "..."},
        {'T', "-"},
        {'U', "..-"},
        {'V', "...-"},
        {'W', ".--"},
        {'X', "-..-"},
        {'Y', "-.--"},
        {'Z', "--.."},
        {'0', "-----"},
        {'1', ".----"},
        {'2', "..---"},
        {'3', "...--"},
        {'4', "....-"},
        {'5', "....."},
        {'6', "-...."},
        {'7', "--..."},
        {'8', "---.."},
        {'9', "----."}
    };
    
    // Define the reverse Morse code map
    map<string, char> reverseMorseMap;
    for (auto const &entry : morseMap)
    {
        reverseMorseMap[entry.second] = entry.first;
    }
    
    // Get user input
    int choice;
    string input;
    cout << "Choose an option:\n1. Text to Morse code\n2. Morse code to text\n";
    cin >> choice;
    cin.ignore();
    cout << "Enter input: ";
    getline(cin, input);
    
    // Translate the input
    string output;
    if (choice == 1)
    {
        output = textToMorse(input, morseMap);
    }
    else if (choice == 2)
    {
        output = morseToText(input, reverseMorseMap);
    }
    else
    {
        cout << "Invalid choice\n";
        return 0;
    }
    
    // Print the output
    cout << "Output: " << output << "\n";
    
    return 0;
}
