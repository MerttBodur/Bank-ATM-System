#include <iostream>
#include "Account.h"
#include "Bank.h"
#include "ATM.h"

int main()
{
	Bank bank;
	ATM atm(bank);
	atm.run();


	return 0;
}