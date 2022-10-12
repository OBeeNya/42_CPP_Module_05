#include "Intern.hpp"

int	main(void)
{

	{
		std::cout << std::endl;
		std::cout << " *** Trying to create a form of unknown type *** " << std::endl;
		Intern	intern = Intern();
		AForm	*form;
		try
		{
			form = intern.makeForm("blablabla", "target");
		}
		catch (std::exception &e)
		{
			std::cerr << e.what() << std::endl;
		}
	}

	{
		std::cout << std::endl;
		std::cout << " *** Creating a presidential pardon form *** " << std::endl;
		Intern	intern = Intern();
		AForm	*form;
		try
		{
			form = intern.makeForm("presidential pardon", "target");
		}
		catch (std::exception &e)
		{
			std::cerr << e.what() << std::endl;
		}
		Bureaucrat	ben = Bureaucrat("Ben", 1);
		ben.signForm(form);
		ben.executeForm(*form);
		delete form;
	}

	{
		std::cout << std::endl;
		std::cout << " *** Creating a robotomy request form *** " << std::endl;
		Intern	intern = Intern();
		AForm	*form;
		try
		{
			form = intern.makeForm("robotomy request", "target");
		}
		catch (std::exception &e)
		{
			std::cerr << e.what() << std::endl;
		}
		Bureaucrat	ben = Bureaucrat("Ben", 1);
		ben.signForm(form);
		ben.executeForm(*form);
		delete form;
	}

	{
		std::cout << std::endl;
		std::cout << " *** Creating a shrubbery creation form *** " << std::endl;
		Intern	intern = Intern();
		AForm	*form;
		try
		{
			form = intern.makeForm("shrubbery creation", "target");
		}
		catch (std::exception &e)
		{
			std::cerr << e.what() << std::endl;
		}
		Bureaucrat	ben = Bureaucrat("Ben", 1);
		ben.signForm(form);
		ben.executeForm(*form);
		delete form;
	}

	std::cout << std::endl;
	return (0);
}
