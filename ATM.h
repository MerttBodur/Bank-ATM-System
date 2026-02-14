#pragma once
#include <string>
#include "Bank.h"


class ATM {
private:
	Bank& m_bank;
	std::string m_currentUser;
	bool m_running;

	void showMainMenu();
	void showAccountMenu();
	void createAccount();
	void login();
	void showBalance();
	void deposit();
	void withdraw();
	void logout();


public:
	ATM(Bank& bank);

	void run();

};
