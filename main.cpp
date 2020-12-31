#include "atm.h"
#include <iostream>
using namespace std;

int main(){
  BankAccount Chris(888, 110, 444, "Chris");
  Atm p(50,30);
  cout<<p;

  cout<<Chris;
  p.get_cash(50, Chris);
  cout<<Chris;
}
