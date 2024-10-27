/* You are tasked with creating a banking system in C++ using Object-Oriented Programming (OOP)
concepts. The system should track the total number of bank accounts created across all customers
and include logic to identify high-value customers based on their account balance.
Requirements:
1. Create a class BankAccount with the following:
o A _________data member to store the total number of accounts.
o A _________data member MIN_HIGH_VALUE that stores the minimum balance
required to be considered a high-value account (e.g., $1000).
o A ________data member to store the account number. (auto generated)
o A ________ data member to store the account balance.
o A constructor to initialize the account with an initial balance and assign a unique
account number by incrementing the static member.
o A ________member function getTotalAccounts() to return the total number of
accounts created.
o A ________member function deposit() to deposit money into the account.
o A _______member function withdraw() to withdraw money from the account (but
only if sufficient balance is available).
o A _______member function display() to display account details (account number and
balance).
o Logic-building function: A _______member function isHighValueAccount() that
returns true if the account balance is greater than or equal to MIN_HIGH_VALUE,
otherwise returns false.
2. Write a second class, Bank, that:
o Contains a _______ array of BankAccount objects.
o Has a ________function addAccount() to create new BankAccount objects with a
provided initial balance.
o Implements a _______ function displayHighValueAccounts() that iterates through all
accounts and displays details of high-value accounts (those where
isHighValueAccount() returns true).
3. Implement logic in the main function to:
o Create at least 5 bank accounts with varying balances using the Bank class.
o Deposit and withdraw from some accounts.
o Display the details of all accounts.
o Use the displayHighValueAccounts() function to show which accounts qualify as highvalue.
o Display the total number of accounts created using the static function.
Note: Here ______: chooses the best-fit specifier and storage class: private/public/static/nonstatic/const
 */


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
