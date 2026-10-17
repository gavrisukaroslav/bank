
#include <iostream>
#include <string>
using namespace std;

class BankAccount {
protected:
    string accountNumber;
    double balance;

public:
    BankAccount(string number, double money) {
        accountNumber = number;
        balance = money;
    }

    void showInfo() {
        cout << "Номер рахунку: " << accountNumber << endl;
        cout << "Баланс: " << balance << " грн" << endl;
    }

    virtual void calculateIncome() {
        cout << "Розрахунок доходу" << endl;
    }

    virtual ~BankAccount() {}
};

class DebitAccount : public BankAccount {
private:
    double cashback;

public:
    DebitAccount(string number, double money, double cb)
        : BankAccount(number, money) {
        cashback = cb;
    }

    void calculateIncome() override {
        cout << "Дебетовий рахунок" << endl;
        showInfo();
        cout << "Кешбек: " << cashback << "%" << endl;
        cout << "Дохід: " << balance * cashback / 100
             << " грн" << endl;
    }
};

class CreditAccount : public BankAccount {
private:
    double creditRate;

public:
    CreditAccount(string number, double money, double rate)
        : BankAccount(number, money) {
        creditRate = rate;
    }

    void calculateIncome() override {
        cout << "Кредитний рахунок" << endl;
        showInfo();
        cout << "Кредитна ставка: " << creditRate << "%" << endl;
        cout << "Витрати на відсотки: "
             << balance * creditRate / 100 << " грн" << endl;
    }
};

class DepositAccount : public BankAccount {
private:
    double depositRate;

public:
    DepositAccount(string number, double money, double rate)
        : BankAccount(number, money) {
        depositRate = rate;
    }

    void calculateIncome() override {
        cout << "Депозитний рахунок" << endl;
        showInfo();
        cout << "Відсоткова ставка: " << depositRate << "%" << endl;
        cout << "Дохід: "
             << balance * depositRate / 100 << " грн" << endl;
    }
};

int main() {
    DebitAccount debit("1111", 10000, 2);
    CreditAccount credit("2222", 5000, 15);
    DepositAccount deposit("3333", 20000, 10);

    BankAccount* account;

    account = &debit;
    account->calculateIncome();

    cout << "\n-------------------\n" << endl;

    account = &credit;
    account->calculateIncome();

    cout << "\n-------------------\n" << endl;

    account = &deposit;
    account->calculateIncome();

    return 0;
}
