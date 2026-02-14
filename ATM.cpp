#include "ATM.h"
#include <string>
#include <iostream>
#include "Bank.h"

ATM::ATM(Bank& bank)
	:m_bank(bank),
	m_currentUser(""),
	m_running(true)
{ }

void ATM::showMainMenu() {
	std::cout << "1)Create Account\n2)Login\n3)Exit\nChoice:";
	int choice;
	std::cin >> choice;
	switch (choice) {
	case 1:createAccount();
		break;
	case 2:login();
		break;
	case 3:m_running = false;
		break;
	default:std::cout << "Invalid Input\n";
	}
}

void ATM::createAccount() {
	std::string username;
	std::string pin;
	std::cout << "Please enter your username and PIN!\n";
	std::cout << "Username:";
	std::cin >> username;
	std::cout << "PIN:";
	std::cin >> pin;
	
	bool result = m_bank.createAccount(username, pin);
	if (result) {
		std::cout << "Account created successfully!\n";
	}
	else {
		std::cout << "Failed(username taken or invalid!\n";
	}

}

void ATM::showAccountMenu() {
	std::cout << "1)Show Balance\n2)Deposit\n3)Withdraw\n4)Logout\nChoice:";
	int choice;
	std::cin >> choice;
	switch (choice) {
	case 1:showBalance();
		break;
	case 2:deposit();
		break;
	case 3:withdraw();
		break;
	case 4:logout();
		break;
	default:std::cout << "Invalid Input\n";
	}

}

void ATM::login() {
	std::string username, pin;
	std::cout << "Username:";
	std::cin >> username;
	std::cout << "PIN:";
	std::cin >> pin;
	bool result = m_bank.login(username, pin);
	if (result) {
		m_currentUser = username;
		std::cout << "Login successful.\n";
	}
	else {
		std::cout << "Login failed.\n";
	}
}

void ATM::showBalance() {
	long long balance;
	bool result = m_bank.getBalance(m_currentUser, balance);
	long long kr = balance % 100;
	if (result) {
		std::cout << "Your balance is:\n" << balance / 100 << " TL";
		if (kr > 0 && kr < 10) {
			std::cout << " 0 " << kr << "Kr\n";
		}
		else if (kr == 0) {
			std::cout << " 00 " << "Kr\n";

		}
		else {
			std::cout << " " << kr << "Kr\n";
		}
	}
	else {
		std::cout << "Error retrieving balance!\n";
	}
}

void ATM::deposit() {
	long long amount;
	std::cout << "Deposit amount:";
	std::cin >> amount;
	bool result = m_bank.deposit(m_currentUser, amount);

	if (result) {
		long long balance;
		m_bank.getBalance(m_currentUser, balance);
		std::cout << "Deposit successful. Your new balance is:" << balance;
	}
	else {
		std::cout << "Deposit failed!\n";
	}
}

void ATM::withdraw() {
	long long amount;
	std::cout << "Withdraw amount:";
	std::cin >> amount;
	bool result = m_bank.withdraw(m_currentUser, amount);

	if (result) {
		long long balance;
		m_bank.getBalance(m_currentUser, balance);
		std::cout << "Withdraw successful. Your new balance is:" << balance;
	}
	else {
		std::cout << "Deposit Failed!\n";
	}
}

void ATM::logout() {
	m_currentUser.clear();
}

void ATM::run() {
	while (m_running) {
		if (m_currentUser.empty()) {
			showMainMenu();
		}
		else {
		    showAccountMenu();
		}
	}
}



