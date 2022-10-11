#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <string>
# include <iostream>
# include <stdexcept>
# include "Form.hpp"
class	Form;

class	Bureaucrat
{

	private:
	
		const std::string	_name;
		int					_grade;

	public:

		Bureaucrat(void);
		Bureaucrat(const Bureaucrat &src);
		Bureaucrat(const std::string, const int);
		~Bureaucrat(void);

		Bureaucrat	&operator=(const Bureaucrat &rhs);

		std::string	getName(void) const;
		int			getGrade(void) const;
		void		incrementGrade(void);
		void		decrementGrade(void);
		void		signForm(Form *form);

		class	GradeTooHighException:
			public std::exception
		{
			public:
				virtual const char* what(void) const throw();
		};

		class	GradeTooLowException:
			public std::exception
		{
			public:
				virtual const char* what(void) const throw();
		};

};

std::ostream	&operator<<(std::ostream &o, const Bureaucrat &rhs);

#endif
