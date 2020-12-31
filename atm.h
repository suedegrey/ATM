#ifndef Atm_H
#define Atm_H

#include <string>
#include <iostream>

class Account {
public:
  Account(float b) : balance(b) { };
  Account() : balance(0.0) { };
  float GetBalance() const { return balance; };
  float Withdraw(float amount) { balance -= amount; };
  void Print() { cout << "balance: " << balance << endl; };
private:
  float balance;
};

class Atm{
private:
  int twenties_;
  int tens_;

public:
  int get_twenties();

  int get_tens();

  Atm();

  Atm(int twenties, int tens);

  //pre: check if amount is divisble by 10 and if there are enough 20s and 10s in Atm
  //post: takes amount desired out of bankaccount from atm
  BankAccount get_cash(int amount, Account& b);

  //pre: none
  //post: adds new20 and new10s to total amount
  void operator +=(Atm& rhs);

  //pre: none
  //post: adds new20 and new10s to total 20s and total 10s
  void restock(int new20s, int new10s);
};

 //pre: none
 //post: compares amount of twenties and tens to different bank accounts
 bool operator ==(Atm lhs, Atm rhs);

 //pre: none
 //post: basically cout amount of twenties and tens in a
 std::ostream& operator <<(std::ostream& out, Atm a);

#endif
