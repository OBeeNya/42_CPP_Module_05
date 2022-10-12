#include "Intern.hpp"

Intern::Intern(void)
{
	// std::cout << "Intern default constructor called" << std::endl;
	return ;
}

Intern::Intern(const Intern &src)
{
	// std::cout << "Intern copy constructor called" << std::endl;
	return ;
}

Intern::~Intern(void)
{
	// std::cout << "Intern default destructor called" << std::endl;
	return ;
}

Intern	&Intern::operator=(const Intern &rhs)
{
	return (*this);
}

AForm	*Intern::makeForm(const std::string name, const std::string target) const
{
	AForm	*forms[3] = {new PresidentialPardonForm(target), new RobotomyRequestForm(target), new ShrubberyCreationForm(target)};
	std::string	names[3] = {"presidential pardon", "robotomy request", "shrubbery creation"};

	int	i = 0;
	for (i; i < 3; i++)
	{
		if (name == names[i])
			break ;
	}

	for (int j = 0; j < 3; j++)
	{
		if (i != j)
			delete forms[j];
	}

	if (i == 3)
	{
		throw (Intern::UnknownFormType());
		return (NULL);
	}
	else
	{
		std::cout << "Intern creates form." << std::endl;
		return (forms[i]);
	}
}

const char	*Intern::UnknownFormType::what(void) const throw()
{
	return ("Unknown form type.");
}
