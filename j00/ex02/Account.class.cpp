#include "Account.class.hpp"

int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;


Account::Account(int initial_deposit) : _amount(initial_deposit)
{

	this->_accountIndex = this->_nbAccounts;
	this->_nbDeposits = 0;
	this->_nbWithdrawals = 0;



	this->_nbAccounts++;
}

Account::~Account()
{

}

void	Account::makeDeposit( int deposit )
{
		this->_amount += deposit;
		this->_nbDeposits++;
}

bool	Account::makeWithdrawal( int withdrawal )
{
	if (this->_amount < withdrawal)
		return (false);
	this->_amount -= withdrawal;
	this->_nbWithdrawals++;
	return (true);
}



int		checkAmount( void ) const
{

}



void	displayStatus( void ) const
{

}



int	Account::getNbAccounts(void)
{
	return Account::_nbAccounts;
}

int	Account::getTotalAmount(void)
{
	return Account::_totalAmount;
}

int	Account::getNbDeposits(void)
{
	return Account::_totalNbDeposits;
}

int Account::getNbWithdrawals(void)
{
	return Account::_totalNbWithdrawals;
}

