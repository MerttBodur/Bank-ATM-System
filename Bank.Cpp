#include "Bank.h"
#include "Account.h"

bool Bank::createAccount(const std::string& username, const std::string& pin)
{
	if (username.empty() || pin.empty()) {
		return false;
	}
	auto it = m_accounts.find(username);

	if (it != m_accounts.end()) {
		return false;
	}
	m_accounts.emplace(username, Account(username, pin, 0));
	return true;
}

bool Bank::login(const std::string& username, const std::string& pin) {
	if (username.empty() || pin.empty()) {
		return false;
	}
	auto it = m_accounts.find(username);

	if (it == m_accounts.end()) {
		return false;
	}
	return (it->second.checkPIN(pin));
}

bool Bank::withdraw(const std::string& username, long long amount) 
{
	auto it = m_accounts.find(username);
	if (it == m_accounts.end()) {
		return false;
	 }
	return it->second.withdraw(amount);

}

bool Bank::deposit(const std::string& username, long long amount)
{
	auto it = m_accounts.find(username);
	if (it == m_accounts.end()) {
		return false;
	}
	return it->second.deposit(amount);
}

bool Bank::getBalance(const std::string& username, long long& balance) {
	auto it = m_accounts.find(username);
	if (it == m_accounts.end()) {
		return false;
	}
	balance = it->second.getBalance();
	
	return true;

	
}
