// Starter code for Lab 2: A BankAccount class that stores a name of an 
// account holder and the balance on the account. Public member functions
// include a 1-argument constructor, two mutators, and an accessor. Most are
// defined inline but withdraw is defined below main using scope resolution.

#include <iostream> 
using namespace std; 

class BankAccount {
public:
	//BankAccount(string name) : name(name), bal(0) { } // constructor
    BankAccount(string Name)
    {
        name = Name;
        bal = 0;
    }

	void deposit() 
    { 
        double amt;
        cout << "amount to deposit: " << endl;
        cin >> amt;

        while(amt < 0)
        {
        cout << "the amount should be positive. ";
        cout << "amount to deposit: " << endl;
        cin >> amt;
        }
        bal += amt;
    } 
    void deposit(double amt) 
    { 
        bal += amt; 
    } 

	void withdraw(double amt);
    void withdraw();

	double getBalance() { return bal; } // simple accessor
    string getName() { return name; }

     void setPin()
    {
        string pin;
        cout << "please set the 4-digit PIN code: ";
        cin >> pin;

        while (pin.length() != 4)
        { 
            cout << "please enter the 4-digit PIN code: ";
            cin >> pin;
        }

        PIN = pin;
    }
private:
	string name;
	double bal;
    string PIN;

};


//note scope resolution syntax for non-inline member function definitions
void BankAccount::withdraw(double amt) 
{
    if (bal >= amt) {
		bal -= amt;
        cout << "Amount withdrawn: " << amt << endl;
	}

    else
    {
        bal = 0;
        cout << "Balance is lower than the amount to withdraw. " << endl;
    }
    
}

void BankAccount::withdraw() {
    string enteredPin;
    cout << "please enter your PIN code: ";
    cin >> enteredPin;

    while(enteredPin != PIN)
    {
        cout << "please enter your PIN code: ";
        cin >> enteredPin;
    }
    double amt;
    cout << "amount to withdraw: " << endl;
    cin >> amt;

	if (bal >= amt) {
		bal -= amt;
        cout << "Amount withdrawn: " << amt << endl;
	}

    else
    {
        bal = 0;
        cout << "Balance is lower than the amount to withdraw. " << endl;
    }
}

void print_information(string name, double bal)
{
    cout << "Account holder: " << name << endl;
    cout << "Balance: " << bal << endl;
}

void deposit_or_withdraw(BankAccount acc)
{
    string choice;
    cout << "deposit, withdraw, or end: " << endl;
    cin >> choice;

    while(choice != "end")
    {
    if (choice == "deposit")
    {acc.deposit();
    cout << "Balance after deposit: " << acc.getBalance() << endl;}
    else if(choice == "withdraw")
    {acc.withdraw();
    cout << "Balance after withdraw: " << acc.getBalance() << endl;}

    cout << "deposit, withdraw, or end: " << endl;
    cin >> choice;
    }
    print_information(acc.getName(), acc.getBalance());
}

// test program
int main() {

	BankAccount acc1("Jenny Smith");
    acc1.setPin();
    acc1.deposit();
	cout << "Initial balance: " << acc1.getBalance() << endl;
	deposit_or_withdraw(acc1);

    

    BankAccount acc2("Anastasia");
    acc2.deposit(2500);
	cout << "Initial balance: " << acc2.getBalance() << endl;
	acc2.withdraw(800); 
	cout << "Balance after deposit: " << acc2.getBalance() << endl;
	acc2.withdraw(2000);
	cout << "Balance after withdrawal: " << acc2.getBalance() << endl;
    print_information(acc2.getName(), acc2.getBalance());

	return 0;
    
}