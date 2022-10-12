#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &src):
	AForm(src.getName(), 145, 137),
	_target(src.getTarget())
{
	// std::cout << "ShrubberyCreationForm copy constructor called" << std::endl;
	return ;
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string target):
	AForm("ShrubberyCreationForm", 145, 137),
	_target(target)
{
	// std::cout << "ShrubberyCreationForm target constructor called" << std::endl;
	return ;
}

ShrubberyCreationForm::~ShrubberyCreationForm(void)
{
	// std::cout << "ShrubberyCreationForm default destructor called" << std::endl;
	return ;
}

ShrubberyCreationForm	&ShrubberyCreationForm::operator=(const ShrubberyCreationForm &rhs)
{
	if (this == &rhs)
		return (*this);
	this->setName(rhs.getName());
	this->_target = rhs.getTarget();
	this->setSigned(rhs.getIsSigned());
	return (*this);
}

std::string	ShrubberyCreationForm::getTarget(void) const
{
	return (this->_target);
}

void	ShrubberyCreationForm::execute(const Bureaucrat &executor) const
{
	if (this->getIsSigned() == false)
		throw (AForm::FormNotSigned());
	else if (this->getExecution() < executor.getGrade())
		throw (AForm::GradeTooLowException());
	else
	{
		std::ofstream	o(this->_target + "_shrubbery");
		o << "       _-_" << std::endl \
		<< "   /~~    ~~ \\" << std::endl \
		<< " /~~         ~~\\" << std::endl \
		<< "{               }" << std::endl \
		<< " \\  _-     -_  /" << std::endl \
		<< "   ~  \\ //  ~" << std::endl \
		<< "_- -   | | _- _" << std::endl \
		<< "  _ -  | |   -_" << std::endl \
		<< "      // \\\\" << std::endl;
		o.close();
	}
}
