#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include "AForm.hpp"
# include <fstream>

class	ShrubberyCreationForm:
	public AForm
{

	private:

		ShrubberyCreationForm(void);

		std::string	_target;

	public:

		ShrubberyCreationForm(const ShrubberyCreationForm &src);
		ShrubberyCreationForm(const std::string target);
		~ShrubberyCreationForm(void);

		ShrubberyCreationForm	&operator=(const ShrubberyCreationForm &rhs);

		std::string		getTarget(void) const;
		void			execute(const Bureaucrat &executor) const;

};

#endif
