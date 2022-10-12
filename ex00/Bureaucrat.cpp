#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(void):
	_name(""),
	_grade(150)
{
	std::cout << "Bureaucrat default constructor called" << std::endl;
	return ;
}

Bureaucrat::Bureaucrat(const Bureaucrat &src):
	_name(src.getName()),
	_grade(src.getGrade())
{
	std::cout << "Bureaucrat copy constructor called" << std::endl;
	return ;
}

Bureaucrat::Bureaucrat(const std::string name, const int grade):
	_name(name)
{
	std::cout << "Bureaucrat full constructor called" << std::endl;
	if (grade < 1)
		throw (Bureaucrat::GradeTooHighException());
	else if (grade > 150)
		throw (Bureaucrat::GradeTooLowException());
	else
		this->_grade = grade;
	return ;
}

Bureaucrat::~Bureaucrat(void)
{
	std::cout << "Bureaucrat default destructor called" << std::endl;
	return ;
}

Bureaucrat	&Bureaucrat::operator=(const Bureaucrat &rhs)
{
	if (this == &rhs)
		return (*this);
	else
	{
		this->_grade = rhs.getGrade();
		std::string *s = (std::string *)&this->_name; 
		*s = rhs.getName();
		return (*this);
	}
}

std::string	Bureaucrat::getName(void) const
{
	return (this->_name);
}

int	Bureaucrat::getGrade(void) const
{
	return (this->_grade);
}

void	Bureaucrat::incrementGrade(void)
{
	if (this->_grade == 1)
		throw (Bureaucrat::GradeTooHighException());
	else
		this->_grade--;
	return ;
}

void	Bureaucrat::decrementGrade(void)
{
	if (this->_grade == 150)
		throw(Bureaucrat::GradeTooLowException());
	else
		this->_grade++;
	return ;
}

const char	*Bureaucrat::GradeTooHighException::what(void) const throw()
{
	return ("Grade cannot get higher than that.");
}

const char	*Bureaucrat::GradeTooLowException::what(void) const throw()
{
	return ("Grade cannot get lower than that.");
}

std::ostream	&operator<<(std::ostream &o, const Bureaucrat &rhs)
{
	return (o << rhs.getName() << ", bureaucrat grade " << rhs.getGrade() << ".");
}
