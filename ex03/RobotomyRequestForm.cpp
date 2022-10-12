#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &src):
	AForm(src.getName(), 72, 45),
	_target(src.getTarget())
{
	// std::cout << "RobotomyRequestForm copy constructor called" << std::endl;
	return ;
}

RobotomyRequestForm::RobotomyRequestForm(const std::string target):
	AForm("RobotomyRequestForm", 72, 45),
	_target(target)
{
	// std::cout << "RobotomyRequestForm target constructor called" << std::endl;
	return ;
}

RobotomyRequestForm::~RobotomyRequestForm(void)
{
	// std::cout << "RobotomyRequestForm default destructor called" << std::endl;
	return ;
}

RobotomyRequestForm	&RobotomyRequestForm::operator=(const RobotomyRequestForm &rhs)
{
	if (this == &rhs)
		return (*this);
	this->setName(rhs.getName());
	this->_target = rhs.getTarget();
	this->setSigned(rhs.getIsSigned());
	return (*this);
}

std::string	RobotomyRequestForm::getTarget(void) const
{
	return (this->_target);
}

void	RobotomyRequestForm::execute(const Bureaucrat &executor) const
{
	if (this->getIsSigned() == false)
		throw (AForm::FormNotSigned());
	else if (this->getExecution() < executor.getGrade())
		throw (AForm::GradeTooLowException());
	else
	{
		int	b = rand() % 100 + 1;
		if (b % 2)
			std::cout << "SWIFTYBOOM !!! " << this->_target << " has been robotomised." << std::endl;
		else
			std::cout << "Robotomisation was unsuccessful..." << std::endl;
	}
}
