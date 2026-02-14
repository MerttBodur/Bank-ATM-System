#pragma once
#include <string>
#include <unordered_map>
#include "Account.h"

class Bank {
private:
	std::unordered_map<std::string, Account> m_accounts;

public:
	bool createAccount(const std::string& username, const std::string& pin);
	bool login(const std::string& username, const std::string& pin);
	bool withdraw(const std::string& username, long long amount);
	bool deposit(const std::string& username, long long amount);
	bool getBalance(const std::string& username, long long& balance);
};
