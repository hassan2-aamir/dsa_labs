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

}

/*   - SavingsAccount:
     - Has an `interestRate` (double) as an additional attribute.
     - Override the `deposit()` method to calculate the interest.
     - Implement `withdraw()` such that no withdrawal is allowed if the balance falls below a certain minimum.
*/
class SavingAccount : public Account{
    private:
        double interestRate;
    
    public:
        void deposit(double amount) override{
            this->balance += amount * (1+interestRate);
        }

}