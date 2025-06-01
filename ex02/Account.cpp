#include "Account.hpp"
#include <iostream>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

void Account::displayAccountsInfos( void )
{
    _displayTimestamp();
    std::cout << " accounts:" << _nbAccounts
              << "; total:" << _totalAmount
              << "; deposits:" << _totalNbDeposits
              << "; withdrawals:" << _totalNbWithdrawals
              << std::endl;
}

int Account::getNbAccounts( void )
{
    return _nbAccounts;
}
int Account::getTotalAmount( void )
{
    return _totalAmount;
}
int Account::getNbDeposits( void )
{
    return _totalNbDeposits;
}
int Account::getNbWithdrawals( void )
{
    return _totalNbWithdrawals;
}


Account::Account( int initial_deposit )
{
    _nbAccounts++;
    _accountIndex = _nbAccounts - 1;
    _amount = initial_deposit;
    _nbDeposits = 0;
    _nbWithdrawals = 0;
    _totalAmount += initial_deposit;
}

Account::~Account( void )
{
    _nbAccounts--;
    _totalAmount -= _amount;
    _totalNbDeposits -= _nbDeposits;
    _totalNbWithdrawals -= _nbWithdrawals;
}

void Account::makeDeposit(int deposit)
{
    _totalNbDeposits++;
    _amount += deposit;
    _nbDeposits++;
    _totalAmount += deposit;
}

bool Account::makeWithdrawal(int withdrawal)
{
    if( withdrawal > _amount)
    {
        return false;
    }
    else
    {
        _totalNbWithdrawals++;
        _amount -= withdrawal;
        _nbWithdrawals++;
        _totalAmount -= withdrawal;
        return true;
    }
}

int		Account::checkAmount( void ) const
{
    return _amount;
}

void	Account::displayStatus( void ) const
{
    _displayTimestamp();
    std::cout << " index:" << _accountIndex
              << "; amount:" << _amount
              << "; deposits:" << _nbDeposits
              << "; withdrawals:" << _nbWithdrawals
              << std::endl;
}

void Account::_displayTimestamp( void )
{
    time_t now = time(0);
    struct tm tstruct;
    char buf[80];
    tstruct = *localtime(&now);
    strftime(buf, sizeof(buf), "[%Y%m%d_%H%M%S] ", &tstruct);
    std::cout << buf;
}