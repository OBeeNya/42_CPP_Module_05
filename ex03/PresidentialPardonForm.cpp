#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &src):
	AForm(src.getName(), 25, 5),
	_target(src.getTarget())
{
	// std::cout << "PresidentialPardonForm copy constructor called" << std::endl;
	return ;
}

PresidentialPardonForm::PresidentialPardonForm(const std::string target):
	AForm("PresidentialPardonForm", 25, 5),
	_target(target)
{
	// std::cout << "PresidentialPardonForm target constructor called" << std::endl;
	return ;
}

PresidentialPardonForm::~PresidentialPardonForm(void)
{
	// std::cout << "PresidentialPardonForm default destructor called" << std::endl;
	return ;
}

PresidentialPardonForm	&PresidentialPardonForm::operator=(const PresidentialPardonForm &rhs)
{
	if (this == &rhs)
		return (*this);
	this->setName(rhs.getName());
	this->_target = rhs.getTarget();
	this->setSigned(rhs.getIsSigned());
	return (*this);
}

std::string	PresidentialPardonForm::getTarget(void) const
{
	return (this->_target);
}

void	PresidentialPardonForm::execute(const Bureaucrat &executor) const
{
	if (this->getIsSigned() == false)
		throw (AForm::FormNotSigned());
	else if (this->getExecution() < executor.getGrade())
		throw (AForm::GradeTooLowException());
	else
		std::cout << this->_target << " was pardoned by Zaphod Beeblebrox." << std::endl;
}
