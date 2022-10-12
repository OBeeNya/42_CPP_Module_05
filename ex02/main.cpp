#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int	main(void)
{

	// {
	// 	std::cout << std::endl;
	// 	std::cout << " *** Trying to instanciate an AForm-class variable *** " << std::endl;
	// 	AForm	form;
	// }

	{
		std::cout << std::endl;
		std::cout << " *** Trying to draw an ascii tree with an unsigned form *** " << std::endl;
		AForm	*shrub = new ShrubberyCreationForm("tree");
		Bureaucrat	ben("Ben", 1);
		try
		{
			shrub->execute(ben);
		}
		catch (const std::exception &e)
		{
			std::cerr << e.what() << std::endl;
		}
		delete shrub;
	}

	{
		std::cout << std::endl;
		std::cout << " *** Trying to draw an ascii tree with a grade 140 bureaucrat *** " << std::endl;
		AForm	*shrub = new ShrubberyCreationForm("tree");
		Bureaucrat	ben("Ben", 140);
		ben.signForm(shrub);
		try
		{
			shrub->execute(ben);
		}
		catch (const std::exception &e)
		{
			std::cerr << e.what() << std::endl;
		}
		delete shrub;
	}

	{
		std::cout << std::endl;
		std::cout << " *** Drawing an ascii tree *** " << std::endl;
		AForm	*shrub = new ShrubberyCreationForm("tree");
		Bureaucrat	ben("Ben", 1);
		ben.signForm(shrub);
		try
		{
			shrub->execute(ben);
		}
		catch (const std::exception &e)
		{
			std::cerr << e.what() << std::endl;
		}
		delete shrub;
	}

	{
		std::cout << std::endl;
		std::cout << " *** Trying to robotize with an unsigned form *** " << std::endl;
		AForm	*rob = new RobotomyRequestForm("victim");
		Bureaucrat	ben("Ben", 1);
		try
		{
			rob->execute(ben);
		}
		catch (std::exception &e)
		{
			std::cerr << e.what() << std::endl;
		}
		delete rob;
	}

	{
		std::cout << std::endl;
		std::cout << " *** Trying to robotize with a grade 50 bureaucrat *** " << std::endl;
		AForm	*rob = new RobotomyRequestForm("victim");
		Bureaucrat	ben("Ben", 50);
		ben.signForm(rob);
		try
		{
			rob->execute(ben);
		}
		catch (std::exception &e)
		{
			std::cerr << e.what() << std::endl;
		}
		delete rob;
	}

	{
		std::cout << std::endl;
		std::cout << " *** Going for some robotization *** " << std::endl;
		AForm	*rob = new RobotomyRequestForm("victim");
		Bureaucrat	ben("Ben", 1);
		Bureaucrat	jim("Jim", 150);
		jim = ben;
		jim.signForm(rob);
		for (int i = 0; i < 10; i++)
		{
			try
			{
				rob->execute(jim);
			}
			catch (std::exception &e)
			{
				std::cerr << e.what() << std::endl;
			}
		}
		delete rob;
	}

	{
		std::cout << std::endl;
		std::cout << " *** Trying to pardon with an unsigned form *** " << std::endl;
		AForm	*pres = new PresidentialPardonForm("prisoner");
		Bureaucrat	ben("Ben", 1);
		try
		{
			pres->execute(ben);
		}
		catch (std::exception &e)
		{
			std::cerr << e.what() << std::endl;
		}
		delete pres;
	}

	{
		std::cout << std::endl;
		std::cout << " *** Trying to pardon with a grade 10 bureaucrat *** " << std::endl;
		AForm	*pres = new PresidentialPardonForm("prisoner");
		Bureaucrat	ben("Ben", 10);
		ben.signForm(pres);
		try
		{
			pres->execute(ben);
		}
		catch (std::exception &e)
		{
			std::cerr << e.what() << std::endl;
		}
		delete pres;
	}

	{
		std::cout << std::endl;
		std::cout << " *** Pardoning a prisoner *** " << std::endl;
		AForm	*pres = new PresidentialPardonForm("prisoner");
		Bureaucrat	ben("Ben", 1);
		ben.signForm(pres);
		try
		{
			pres->execute(ben);
		}
		catch (std::exception &e)
		{
			std::cerr << e.what() << std::endl;
		}
		delete pres;
	}

	{
		std::cout << std::endl;
		std::cout << " *** Trying to execute a form with the bureaucrat function, but the form is not signed *** " << std::endl;
		AForm	*pres = new PresidentialPardonForm("prisoner");
		Bureaucrat	ben("ben", 1);
		try
		{
			ben.executeForm(*pres);
		}
		catch (std::exception &e)
		{
			std::cerr << e.what() << std::endl;
		}
		delete pres;
	}

	{
		std::cout << std::endl;
		std::cout << " *** Trying to execute a form with the bureaucrat function, but the grade is too low *** " << std::endl;
		AForm	*pres = new PresidentialPardonForm("prisoner");
		Bureaucrat	ben("ben", 10);
		ben.signForm(pres);
		try
		{
			ben.executeForm(*pres);
		}
		catch (std::exception &e)
		{
			std::cerr << e.what() << std::endl;
		}
		delete pres;
	}

	{
		std::cout << std::endl;
		std::cout << " *** Executing a form with the bureaucrat function *** " << std::endl;
		AForm	*pres = new PresidentialPardonForm("prisoner");
		Bureaucrat	ben("ben", 1);
		ben.signForm(pres);
		try
		{
			ben.executeForm(*pres);
		}
		catch (std::exception &e)
		{
			std::cerr << e.what() << std::endl;
		}
		delete pres;
	}

	std::cout << std::endl;
	return (0);
}
