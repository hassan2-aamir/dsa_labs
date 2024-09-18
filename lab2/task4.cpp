#include <iostream>
using namespace std;

//Implement a base class `Account` that contains An `accountNumber` (int), A `balance` (double) and customerName` (string)
class Account{
        
    public:
        int account_number;
        double balance;
        string customer_name;
        //A constructor to initialize these fields.
        Account(int account_number,double balance,string customer_name){
            this->account_number = account_number;
            this->balance= balance;
            this->customer_name=customer_name;
        }
        //A pure virtual method `deposit(double amount)` to deposit money into the account
        virtual void deposit(double amount){
            this->balance+= amount;
        }
        //A pure virtual method `withdraw(double amount)` to withdraw money.
        virtual void withdraw(double amount){
            this->balance-= amount;
        }
        //A method `displayInfo()` to display account details.
        void displayInfo(){
            cout<<endl<<"Acc no. : "<<this->account_number<<endl;
            cout<<"Name : "<<this->customer_name<<endl;
            cout<<"balance : "<<this->balance<<endl;
        }

        //. Implement **operator overloading** to compare two accounts based on their balances (`>`, `<`, `==`).
        bool operator> (Account const& obj){
            return this->balance > obj.balance;
        }

        bool operator< (Account const& obj){
            return this->balance < obj.balance;
        }

        bool operator== (Account const& obj){
            return this->balance == obj.balance;
        }


};

/*   - SavingsAccount:
     - Has an `interestRate` (double) as an additional attribute.
     - Override the `deposit()` method to calculate the interest.
     - Implement `withdraw()` such that no withdrawal is allowed if the balance falls below a certain minimum.*/
class SavingAccount : public Account{
    
    public:
        double interestRate;

        SavingAccount(int account_number,double balance,string customer_name,double interestRate):Account(account_number, balance, customer_name){
            this->interestRate=interestRate;
        }

        void deposit(double amount) override{
            this->balance += amount * (1+interestRate);
        }

        void withdraw(double amount) override{
            if (this->balance< 0.0){
                cout<<"Insufficient balance for withdrawal"<<endl;
            }
            else{
                this->balance -= amount;
            }
        }


};
/*   - CheckingAccount:
     - Has an `overdraftLimit` (double).
     - Implement `withdraw()` such that withdrawals beyond the balance are allowed up to the overdraft limit.
*/
class CheckingAccount : public Account{
    
    public:
        double overdraftLimit;

        CheckingAccount(int account_number,double balance,string customer_name,double  overdraftLimit):Account(account_number, balance, customer_name){
            this->overdraftLimit= overdraftLimit;
        }

        void deposit(double amount) override{
            this->balance += amount;
        }

        void withdraw(double amount) override{
            if (this->balance<  this->overdraftLimit){
                cout<<"Insufficient balance for withdrawal"<<endl;
            }
            else{
                this->balance -= amount;
            }
        }


};

/*   - InvestmentAccount:
     - Has an `investmentDuration` (int) and `riskFactor` (double).
     - Override `deposit()` and `withdraw()` to handle risk-based profit/loss when depositing or withdrawing.
*/
class InvestmentAccount : public Account{
    
    public:
        double riskFactor;
        int investmentDuration;

        InvestmentAccount(int account_number,double balance,string customer_name,double  riskFactor,int investmentDuration):Account(account_number, balance, customer_name){
            this->riskFactor= riskFactor;
            this->investmentDuration= investmentDuration;
        }

        void deposit(double amount) override{
            if (this->riskFactor<1.5){
                this->balance += amount;
            }
            else{
                cout<<"Risk factor too great to deposit"<<endl;
            }
        }

        void withdraw(double amount) override{
            if (this->riskFactor>1.5){
                cout<<"risk factor too great to withdraw funds"<<endl;
            }
            else{
                this->balance -= amount;
            }
        }


};


/*. In the **main** function:
    - Create objects for all three types of accounts.
    - Perform deposit and withdraw operations.
    - Compare the accounts using the overloaded operators.
    - Use polymorphism to manage the different types of accounts through base class pointers.
    - Ensure proper memory management using virtual destructors
*/
int main() {
    // Create account objects
    SavingAccount* savings = new SavingAccount(1, 1234.5, "Hassan", 0.05);
    CheckingAccount* checking = new CheckingAccount(2, 456.8, "Ali", 200.0);
    InvestmentAccount* investment = new InvestmentAccount(3, 1500.0, "Ahmad", 1.2, 12);

    // Perform deposit and withdrawal operations
    savings->deposit(200);
    checking->withdraw(100);
    investment->deposit(500);
    investment->withdraw(200);

    // Display account information
    savings->displayInfo();
    checking->displayInfo();
    investment->displayInfo();

    // Compare accounts
    if (*savings > *checking) {
        cout << "Savings account has a higher balance than Checking account." << endl;
    } else if (*savings < *checking) {
        cout << "Checking account has a higher balance than Savings account." << endl;
    } else {
        cout << "Both accounts have the same balance." << endl;
    }

    if (*checking > *investment) {
        cout << "Checking account has a higher balance than Investment account." << endl;
    } else if (*checking < *investment) {
        cout << "Investment account has a higher balance than Checking account." << endl;
    } else {
        cout << "Both accounts have the same balance." << endl;
    }

    // Use polymorphism to manage accounts
    Account* accounts[3] = {savings, checking, investment};
    for (int i = 0; i < 3; ++i) {
        accounts[i]->displayInfo();
    }

    // Clean up memory
    for (int i = 0; i < 3; ++i) {
        delete accounts[i];
    }

    return 0;
}