#include "AForm.hpp"

AForm::AForm(void):
	_name(""),
	_isSigned(false),
	_signature(150),
	_execution(150)
{
	// std::cout << "AForm default constructor called" << std::endl;
	return ;
}

AForm::AForm(const AForm &src):
	_name(src.getName()),
	_isSigned(src.getIsSigned()),
	_signature(src.getSignature()),
	_execution(src.getExecution())
{
	// std::cout << "AForm copy constructor called" << std::endl;
	return ;
}

AForm::AForm(const std::string name, const int signature, const int execution):
	_name(name),
	_isSigned(false),
	_signature(signature),
	_execution(execution)
{
	// std::cout << "AForm full constructor called" << std::endl;
	if (signature < 1 || execution < 1)
		throw (AForm::GradeTooHighException());
	else if (signature > 150 || execution > 150)
		throw (AForm::GradeTooLowException());
	return ;
}

AForm::~AForm(void)
{
	// std::cout << "AForm default destructor called" << std::endl;
	return ;
}

AForm	&AForm::operator=(const AForm &rhs)
{
	if (this == &rhs)
		return (*this);
	this->_name = rhs.getName();
	this->_isSigned = rhs.getIsSigned();
	this->_signature = rhs.getSignature();
	this->_execution = rhs.getExecution();
	return (*this);
}

void	AForm::beSigned(const Bureaucrat bureaucrat)
{
	if (bureaucrat.getGrade() > this->_signature)
		throw (AForm::GradeTooLowException());
	else
		this->_isSigned = true;
}

void	AForm::setName(const std::string name)
{
	this->_name = name;
	return ;
}

std::string	AForm::getName(void) const
{
	return (this->_name);
}

bool	AForm::getIsSigned(void) const
{
	return (this->_isSigned);
}

void	AForm::setSigned(const bool s)
{
	if (s == true)
		this->_isSigned = true;
	else if (s == false)
		this->_isSigned = false;
	return ;
}

int	AForm::getSignature(void) const
{
	return (this->_signature);
}

int	AForm::getExecution(void) const
{
	return (this->_execution);
}

const char	*AForm::GradeTooHighException::what(void) const throw()
{
	return ("Grade is too high.");
}

const char	*AForm::GradeTooLowException::what(void) const throw()
{
	return ("Grade is too low.");
}

const char	*AForm::FormNotSigned::what(void) const throw()
{
	return ("Form is not signed.");
}

std::ostream	&operator<<(std::ostream &o, const AForm &rhs)
{
	return (o << "Name: " << rhs.getName() << std::endl \
	<< "Is signed: " << rhs.getIsSigned() << std::endl \
	<< "Signature grade: " << rhs.getSignature() << std::endl \
	<< "Execution grade: " << rhs.getExecution());
}
