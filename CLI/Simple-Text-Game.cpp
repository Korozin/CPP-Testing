#include <iostream>
#include <string>

using namespace std;

int main() {
    string playerName;
    int choice1, choice2;
    
    cout << "Welcome to the adventure game!" << endl;
    cout << "What's your name? ";
    cin >> playerName;
    
    cout << "Hello " << playerName << ", you are on a quest to find a treasure." << endl;
    cout << "You come across a fork in the road, which path do you take?" << endl;
    cout << "1. Left" << endl;
    cout << "2. Right" << endl;
    cout << "Enter your choice (1 or 2): ";
    cin >> choice1;
    
    if (choice1 == 1) {
        cout << "You have chosen the left path." << endl;
        cout << "You see a river, do you want to swim across or find a bridge?" << endl;
        cout << "1. Swim" << endl;
        cout << "2. Find a bridge" << endl;
        cout << "Enter your choice (1 or 2): ";
        cin >> choice2;
        
        if (choice2 == 1) {
            cout << "You tried to swim across the river but were caught in a strong current and drowned." << endl;
            cout << "GAME OVER" << endl;
        }
        else if (choice2 == 2) {
            cout << "You found a bridge and crossed the river safely." << endl;
            cout << "You continue on your journey and come across a cave." << endl;
            cout << "Do you enter the cave or continue on the path?" << endl;
            cout << "1. Enter the cave" << endl;
            cout << "2. Continue on the path" << endl;
            cout << "Enter your choice (1 or 2): ";
            cin >> choice2;
            
            if (choice2 == 1) {
                cout << "You entered the cave and found the treasure!" << endl;
                cout << "Congratulations, you win the game!" << endl;
            }
            else if (choice2 == 2) {
                cout << "You continue on the path but get lost and never find the treasure." << endl;
                cout << "GAME OVER" << endl;
            }
        }
        else {
            cout << "Invalid input." << endl;
            cout << "GAME OVER" << endl;
        }
    }
    else if (choice1 == 2) {
        cout << "You have chosen the right path." << endl;
        cout << "You come across a pack of wolves, do you fight them or run away?" << endl;
        cout << "1. Fight" << endl;
        cout << "2. Run away" << endl;
        cout << "Enter your choice (1 or 2): ";
        cin >> choice2;
        
        if (choice2 == 1) {
            cout << "You fought the wolves but were outnumbered and killed." << endl;
            cout << "GAME OVER" << endl;
        }
        else if (choice2 == 2) {
            cout << "You ran away from the wolves and continue on your journey." << endl;
            cout << "You come across a river, do you want to swim across or find a bridge?" << endl;
            cout << "1. Swim" << endl;
            cout << "2. Find a bridge" << endl;
            cout << "Enter your choice (1 or 2): ";
            cin >> choice2;
            
            if (choice2 == 1) {
                cout << "You tried to swim across the river but were caught in a strong current and drowned." << endl;
                cout << "GAME OVER" << endl;
            }
            else if (choice2 == 2) {
                cout << "You found a bridge and crossed the river safely." << endl;
                cout << "You continue on your journey and come across a cave." << endl;
                cout << "Do you enter the cave or continue on the path?" << endl;
                cout << "1. Enter the cave" << endl;
                cout << "2. Continue on the path" << endl;
                cout << "Enter your choice (1 or 2): ";
                cin >> choice2;
                
                if (choice2 == 1) {
                    cout << "You entered the cave and found the treasure!" << endl;
                    cout << "Congratulations, you win the game!" << endl;
                }
                else if (choice2 == 2) {
                    cout << "You continue on the path but get lost and never find the treasure." << endl;
                    cout << "GAME OVER" << endl;
                }
            }
            else {
                cout << "Invalid input." << endl;
                cout << "GAME OVER" << endl;
            }
        }
        else {
            cout << "Invalid input." << endl;
            cout << "GAME OVER" << endl;
        }
    }
    else {
        cout << "Invalid input." << endl;
        cout << "GAME OVER" << endl;
    }
    
    return 0;
}
