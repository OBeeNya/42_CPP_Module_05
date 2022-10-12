#include "Bureaucrat.hpp"
#include "Form.hpp"

int	main(void)
{
	{
		std::cout << std::endl;
		std::cout << " *** Trying to sign a grade 75 form with a grade 70 bureaucrat with the beSigned() function *** " << std::endl;
		Form		f1 = Form("f1 form", 75, 25);
		Bureaucrat	ben = Bureaucrat("ben", 70);
		std::cout << f1 << std::endl;
		std::cout << std::endl;
		f1.beSigned(ben);
		std::cout << f1 << std::endl;
	}

	{
		std::cout << std::endl;
		std::cout << " *** Trying to sign a grade 75 form with a grade 70 bureaucrat with the signForm() function *** " << std::endl;
		Form		f2 = Form("f2 form", 75, 25);
		Bureaucrat	ben = Bureaucrat("ben", 70);
		std::cout << f2 << std::endl;
		std::cout << std::endl;
		ben.signForm(&f2);
		std::cout << f2 << std::endl;
	}

	{
		std::cout << std::endl;
		std::cout << " *** Trying to sign a grade 70 form with a grade 80 bureaucrat *** " << std::endl;
		Bureaucrat	ben = Bureaucrat("ben", 80);
		Form		f3 = Form("f3 form", 75, 25);
		std::cout << f3 << std::endl;
		ben.signForm(&f3);
		std::cout << std::endl << f3 << std::endl;
	}

	std::cout << std::endl;
	return (0);
}
