#include "atm.h"

int Atm::get_twenties(){
  return twenties_;
}
int Atm::get_tens(){
  return tens_;
}
Atm::Atm(){
  twenties_ = 0;
  tens_ = 0;
}
Atm::Atm(int twenties, int tens){
  twenties_ = twenties;
  tens_ = tens;
}

BankAccount Atm::get_cash(int amount, Account& b){
  //check if amount is divisble by 10

  if(amount%10 != 0) {
    return b;
  }

  int num20 = amount / 20;
  int num10 = (amount % 20) / 10;

  if(twenties_ < num20 || tens_ < num10) { //check if there are enough 20s and 10s in Atm
    return b;
  }

  num10 = (amount % 20) / 10;
  double damount = (double)amount;
  b.withdraw(damount);
  //std::cout<<"the amount you want to withdraw is "<<damount<<std::endl;
  twenties_ -= num20;
  tens_ -= num10;
  std::cout<<"You will get "<<num20<<" twenties and "<<num10<<" tens."<<std::endl;
  return b;
}

void operator +=(Atm& rhs, BankAccount ba) {
  int amount = rhs.get_twenties() + rhs.get_tens();
  ba.deposit(amount);
}

void Atm::restock(int new20s, int new10s) {
  twenties_ += new20s;
  tens_ += new10s;
}

bool operator ==(Atm lhs, Atm rhs) {
  if (lhs.get_tens() == rhs.get_tens() && lhs.get_twenties() == rhs.get_twenties()) {
    return true;
  } else {
    return false;
  }
}

std::ostream& operator <<(std::ostream& out, Atm a) {
  out<<"There are "<<a.get_tens()<<" tens and there are "<<a.get_twenties()<<" twenties."<<std::endl;
  return out;
}
