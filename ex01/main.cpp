#include "Bureaucrat.hpp"
#include "Form.hpp"

int	main(void)
{
	std::cout << std::endl;
	Form		f = Form("formulaire f", 75, 25);
	Bureaucrat	ben = Bureaucrat("ben", 70);

	std::cout << f << std::endl;

	std::cout << std::endl;
	std::cout << " *** Trying to sign either through the Form function or the Bureaucrat function *** " << std::endl;
	// b2.beSigned(ben);
	ben.signForm(&f);

	std::cout << f << std::endl;

	std::cout << std::endl;
	std::cout << " *** Trying to sign with a low grade Bureaucrat *** " << std::endl;
	Bureaucrat	ben2 = Bureaucrat("ben2", 80);
	Form		f2 = Form("formulaire f2", 75, 25);
	ben2.signForm(&f2);

	std::cout << std::endl;
	return (0);
}
