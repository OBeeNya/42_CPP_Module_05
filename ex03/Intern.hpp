#ifndef INTERN_HPP
# define INTERN_HPP

# include "RobotomyRequestForm.hpp"
# include "PresidentialPardonForm.hpp"
# include "ShrubberyCreationForm.hpp"

class	Intern
{

	public:

		Intern(void);
		Intern(const Intern &src);
		~Intern(void);

		Intern	&operator=(const Intern &rhs);

		AForm	*makeForm(const std::string name, const std::string target) const;	

		class	UnknownFormType:
			public std::exception
		{
			public:
				virtual const char*	what(void) const throw();
		};

};

#endif

