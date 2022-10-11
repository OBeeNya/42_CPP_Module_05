#include "Form.hpp"

Form::Form(void):
	_name(""),
	_isSigned(false),
	_signature(150),
	_execution(150)
{
	std::cout << "Form default constructor called" << std::endl;
	return ;
}

Form::Form(const Form &src):
	_name(src.getName()),
	_isSigned(src.getIsSigned()),
	_signature(src.getSignature()),
	_execution(src.getExecution())
{
	std::cout << "Form copy constructor called" << std::endl;
	return ;
}

Form::Form(const std::string name, const int signature, const int execution):
	_name(name),
	_isSigned(false),
	_signature(signature),
	_execution(execution)
{
	std::cout << "Form full constructor called" << std::endl;
	if (signature < 1 || execution < 1)
		throw (Form::GradeTooHighException());
	else if (signature > 150 || execution > 150)
		throw (Form::GradeTooLowException());
	return ;
}

Form::~Form(void)
{
	std::cout << "Form default destructor called" << std::endl;
	return ;
}

Form	&Form::operator=(const Form &rhs)
{
	if (this == &rhs)
		return (*this);
	this->_name = rhs.getName();
	this->_isSigned = rhs.getIsSigned();
	this->_signature = rhs.getSignature();
	this->_execution = rhs.getExecution();
	return (*this);
}

void	Form::beSigned(const Bureaucrat bureaucrat)
{
	if (bureaucrat.getGrade() > this->_signature)
		throw (Form::GradeTooLowException());
	else
		this->_isSigned = true;
}

std::string	Form::getName(void) const
{
	return (this->_name);
}

bool	Form::getIsSigned(void) const
{
	return (this->_isSigned);
}

int	Form::getSignature(void) const
{
	return (this->_signature);
}

int	Form::getExecution(void) const
{
	return (this->_execution);
}

const char	*Form::GradeTooHighException::what(void) const throw()
{
	return ("Grade too high.");
}

const char	*Form::GradeTooLowException::what(void) const throw()
{
	return ("Grade too low.");
}

std::ostream	&operator<<(std::ostream &o, const Form &rhs)
{
	return (o << "Name: " << rhs.getName() << std::endl \
	<< "Is signed: " << rhs.getIsSigned() << std::endl \
	<< "Signature grade: " << rhs.getSignature() << std::endl \
	<< "Execution grade: " << rhs.getExecution());
}
