#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include "AForm.hpp"
# include <random>

class	RobotomyRequestForm:
	public AForm
{

	private:

		RobotomyRequestForm(void);

		std::string	_target;

	public:

		RobotomyRequestForm(const RobotomyRequestForm &src);
		RobotomyRequestForm(const std::string target);
		~RobotomyRequestForm(void);

		RobotomyRequestForm	&operator=(const RobotomyRequestForm &rhs);

		std::string		getTarget(void) const;
		void			execute(const Bureaucrat &executor) const;

};

#endif
