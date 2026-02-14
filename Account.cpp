#include "Account.h"

Account::Account(const std::string& username,const std::string& PIN, long long balance)
	: m_username(username),
	m_PIN(PIN),
	m_balance(balance)
{
}

bool Account::checkPIN(std::string PIN) const {
	return (m_PIN == PIN) ? true : false;
}

bool Account::deposit(long long amount)
{
	if (amount <= 0) {
		return false;
	}
	m_balance += amount;
	return true;
}

bool Account::withdraw(long long amount) {
	if (amount > m_balance || amount <= 0) {
		return false;
	}
	m_balance -= amount;
	return true;
}

long long Account::getBalance() const {
	return m_balance;
}

std::string Account::getUsername() const  {
	return m_username;
}