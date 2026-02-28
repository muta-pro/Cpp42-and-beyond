/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imutavdz <imutavdz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 21:19:15 by imutavdz          #+#    #+#             */
/*   Updated: 2026/01/28 13:28:55 by imutavdz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
 
#include "Account.hpp"
#include <iostream>
#include <iomanip>
#include <ctime>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

int Account::getNbAccounts (void)
{return (_nbAccounts);}

int Account::getTotalAmount (void)
{return (_totalAmount);}

int Account::getNbDeposits (void)
{return (_totalNbDeposits);}

int Account::getNbWithdrawals (void)
{return (_totalNbWithdrawals);}

void Account::_displayTimestamp (void)
{
	std::time_t now = std::time(NULL);
	std::tm *lt = std::localtime((&now));

	std::cout << "["
			  << (lt->tm_year + 1900)
			  << std::setw(2) << std::setfill('0') << (lt->tm_mon + 1)
			  << std::setw(2) << std::setfill('0') << lt->tm_mday
			  << "_"
			  << std::setw(2) << std::setfill('0') << lt->tm_hour
			  << std::setw(2) << std::setfill('0') << lt->tm_min
			  << std::setw(2) << std::setfill('0') << lt->tm_sec
			  << "]";
}

void Account::displayAccountsInfos(void)
{
	_displayTimestamp();
	std::cout << "accounts:" << Account::getNbAccounts() 
			  << ";total:" << Account::getTotalAmount() 
			  << ";deposits:" << Account::getNbDeposits()
			  << ";withdrawals:" << Account::getNbWithdrawals()
			  << std::endl;
}


Account::Account(int initial_deposit) : _accountIndex(Account::_nbAccounts),
										_amount(initial_deposit),
										_nbDeposits(0),
										_nbWithdrawals(0)
{
	Account::_nbAccounts++;
	Account::_totalAmount += initial_deposit;
	Account::_displayTimestamp();
	std::cout << "index:" << _accountIndex
			  << ";amount:" << _amount
			  << ";created"
			  << std::endl;
}

Account::~Account (void)
{
	Account::_displayTimestamp();
	std::cout << "index:" << _accountIndex
			  << ";amount:" << _amount 
			  << ";closed"
			  << std::endl;
}
Account::Account(void): _accountIndex(0), _amount(0), _nbDeposits(0), _nbWithdrawals(0){}

void Account::makeDeposit( int deposit )
{
	int prev = _amount;

	_amount += deposit;
	_nbDeposits++;
	Account::_totalAmount += deposit;
	Account::_totalNbDeposits++;
	Account::_displayTimestamp();
	std::cout << "index:" << _accountIndex
			  << ";p_amount:" << prev
			  << ";deposits:" << deposit
			  << ";amount:" << _amount
			  << ";nb_deposits:" << _nbDeposits
			  << std::endl;
}

bool Account::makeWithdrawal(int withdrawal)
{
	int prev = _amount;

	Account::_displayTimestamp();
	std::cout << "index:" << _accountIndex
			  << ";p_amount:" << prev
			  << ";withdrawal:";
	if (withdrawal > _amount)
	{
		std::cout << "refused" << std::endl;
		return (false);
	}
	_amount -= withdrawal;
	_nbWithdrawals++;
	Account::_totalAmount -= withdrawal;
	Account::_totalNbWithdrawals++;
	std::cout << withdrawal
			  << ";amount:" << _amount
			  << ";nb_Withdrawals:" << _nbWithdrawals
			  << std::endl;
	return (true);
}

int Account::checkAmount(void) const
{ return (_amount); }

void Account::displayStatus(void) const
{
	Account::_displayTimestamp();
	std::cout << "index:" << _accountIndex
			  << ";amount:" << _amount
			  << ";deposits:" << _nbDeposits
			  << ";withdrawals:" << _nbWithdrawals
			  <<std::endl;

}
