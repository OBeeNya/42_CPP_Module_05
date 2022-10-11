#ifndef FORM_HPP
# define FORM_HPP

# include <string>
# include <stdexcept>
# include "Bureaucrat.hpp"
class Bureaucrat;

class	Form
{

	private:

		std::string	_name;
		bool		_isSigned;
		int			_signature;
		int			_execution;

	public:

		Form(void);
		Form(const Form &src);
		Form(const std::string name, const int signature, const int execution);
		~Form(void);

		Form	&operator=(const Form &rhs);

		void		beSigned(Bureaucrat bureaucrat);
		std::string	getName(void) const;
		bool		getIsSigned(void) const;
		int			getSignature(void) const;
		int			getExecution(void) const;

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

std::ostream	&operator<<(std::ostream &o, const Form &rhs);

#endif
