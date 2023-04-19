#include <iostream>
#include <vector>

using namespace std;

class BankAccount {
    private:
        double balance;
        vector<string> transactions;

    public:
        BankAccount() {
            balance = 0.0;
        }

        void deposit(double amount) {
            balance += amount;
            transactions.push_back("Deposit: +" + to_string(amount));
        }

        void withdraw(double amount) {
            if (amount <= balance) {
                balance -= amount;
                transactions.push_back("Withdrawal: -" + to_string(amount));
            } else {
                cout << "Error: Insufficient balance!" << endl;
            }
        }

        void check_balance() {
            cout << "Current balance: $" << balance << endl;
        }

        void print_transactions() {
            cout << "Transaction history:" << endl;
            for (int i = 0; i < transactions.size(); i++) {
                cout << i+1 << ". " << transactions[i] << endl;
            }
        }
};

int main() {
    BankAccount account;

    int choice;
    double amount;

    do {
        cout << "Bank Account Menu" << endl;
        cout << "1. Deposit" << endl;
        cout << "2. Withdraw" << endl;
        cout << "3. Check balance" << endl;
        cout << "4. View transaction history" << endl;
        cout << "5. Exit" << endl;

        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter amount to deposit: $";
                cin >> amount;
                account.deposit(amount);
                break;

            case 2:
                cout << "Enter amount to withdraw: $";
                cin >> amount;
                account.withdraw(amount);
                break;

            case 3:
                account.check_balance();
                break;

            case 4:
                account.print_transactions();
                break;

            case 5:
                cout << "Exiting program..." << endl;
                break;

            default:
                cout << "Invalid choice. Please try again." << endl;
                break;
        }

        cout << endl;

    } while (choice != 5);

    return 0;
}
