#include "Account.hpp"

// int Account::_nbAccounts = 0;
// int Account::_totalAmount = 0;
// int Account::_totalNbDeposits = 0;
// int Account::_totalNbWithdrawals = 0;

void Account::displayAccountsInfos( void )
{

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

}

int		Account::checkAmount( void ) const
{
    return _amount;
}

void	Account::displayStatus( void ) const
{

}