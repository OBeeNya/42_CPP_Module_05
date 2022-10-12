#ifndef AFORM_HPP
# define AFORM_HPP

# include <string>
# include <stdexcept>
# include "Bureaucrat.hpp"
class Bureaucrat;

class	AForm
{

	private:

		std::string	_name;
		bool		_isSigned;
		int			_signature;
		int			_execution;

	public:

		AForm(void);
		AForm(const AForm &src);
		AForm(const std::string name, const int signature, const int execution);
		virtual ~AForm(void);

		AForm	&operator=(const AForm &rhs);

		virtual void		beSigned(Bureaucrat bureaucrat);
		virtual std::string	getName(void) const;
		virtual bool		getIsSigned(void) const;
		virtual int			getSignature(void) const;
		virtual int			getExecution(void) const;
		virtual void		setName(const std::string name);
		virtual void		setSigned(const bool s);
		virtual void		execute(const Bureaucrat &executor) const = 0;

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

		class	FormNotSigned:
			public std::exception
		{
			public:
				virtual const char* what(void) const throw();
		};

};

std::ostream	&operator<<(std::ostream &o, const AForm &rhs);

#endif
