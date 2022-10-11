#include "Bureaucrat.hpp"

int	main(void)
{
	std::cout << std::endl;

	std::cout << " *** Trying to create a bureaucrat with an invalid grade *** " << std::endl;
	try
	{
		Bureaucrat	tom = Bureaucrat("Tom", -5);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;
	
	std::cout << " *** Decrementing a bureaucrat's grade *** " << std::endl;
	Bureaucrat	ben = Bureaucrat("Ben", 1);
	std::cout << ben << std::endl;
	ben.decrementGrade();
	std::cout << ben << std::endl;
	std::cout << std::endl;
	
	std::cout << " *** Incrementing a bureaucrat's grade *** " << std::endl;
	ben.incrementGrade();
	std::cout << ben << std::endl;
	std::cout << std::endl;
	
	std::cout << " *** Trying to increment a bureaucrat at grade 1 *** " << std::endl;
	try
	{
		ben.incrementGrade();
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << ben << std::endl;
	std::cout << std::endl;

	std::cout << " *** Trying to decrement a bureaucrat at grade 150 *** " << std::endl;
	Bureaucrat	jim = Bureaucrat("Jim", 150);
	std::cout << jim << std::endl;
	try
	{
		jim.decrementGrade();
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << jim << std::endl;
	std::cout << std::endl;

	return (0);
}
