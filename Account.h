#pragma once
#include <string>

class Account
{
private:
	std::string m_username;
	std::string m_PIN;
	long long m_balance; //Kuruþ Cinsinden

public:
	Account(const std::string& username, const std::string& PIN, long long balance);
	bool checkPIN(std::string PIN) const;
	bool deposit(long long amount);
	bool withdraw(long long amount);
	long long getBalance() const;
	std::string getUsername() const;;

};
