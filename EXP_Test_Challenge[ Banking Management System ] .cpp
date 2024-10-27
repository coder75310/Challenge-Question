#include <iostream>
#include<vector>
using namespace std;

class BankAccount {
private:
    static int totalAccounts;             
    static const int MIN_HIGH_VALUE = 1000; 
    int accountNumber;                      
    double accountBalance;                  

public:
    BankAccount(double initialBalance) : accountBalance(initialBalance) {
        totalAccounts++;                 
        accountNumber = totalAccounts;      
    }

    static int getTotalAccounts() {
        return totalAccounts;
    }

    void deposit(double amount) {
        if (amount > 0) {
            accountBalance += amount;
            cout << "Deposited $" << amount << " into account #" << accountNumber << endl;
        } else {
            cout << "Invalid deposit amount." << endl;
        }
    }

    void withdraw(double amount) {
        if (amount > 0 && accountBalance >= amount) {
            accountBalance -= amount;
            cout << "Withdraw $" << amount << " from account #" << accountNumber << endl;
        } else {
            cout << "Insufficient balance or invalid withdrawal amount." << endl;
        }
    }

    bool isHighValueAccount() const {
        return accountBalance >= MIN_HIGH_VALUE;
    }

    void display() const {
        cout << "Account #" << accountNumber << " | Balance: $" << accountBalance;
        if (isHighValueAccount()) {
            cout << " (High-Value Account)";
        }
        cout << endl;
    }

};

int BankAccount::totalAccounts = 0;

class Bank {
private:
    vector<BankAccount> accounts;  

public:
    void addAccount(double initialBalance) {
        BankAccount newAccount(initialBalance);
        accounts.push_back(newAccount);
        cout << "New account created Account #" << BankAccount::getTotalAccounts() << " | Initial balance: $" << initialBalance << endl;
    }

    void displayAllAccounts() const {
        for (const auto& account : accounts) {
            account.display();
        }
    }   

};

int main() {
    Bank bank;

    bank.addAccount(500.0); 
    bank.addAccount(1500.0);
    bank.addAccount(750.0); 

    cout << "\nDisplaying all accounts:\n";
    bank.displayAllAccounts();

    bank.addAccount(2000.0); 
    bank.addAccount(2500.0);

    cout << "\nDisplaying updated account details:\n";
    bank.displayAllAccounts();

    cout << "\nTotal accounts created: " << BankAccount::getTotalAccounts() << endl;

    return 0;
}