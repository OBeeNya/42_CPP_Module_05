#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include "AForm.hpp"

class	PresidentialPardonForm:
	public AForm
{

	private:

		PresidentialPardonForm(void);

		std::string	_target;

	public:

		PresidentialPardonForm(const PresidentialPardonForm &src);
		PresidentialPardonForm(const std::string target);
		~PresidentialPardonForm(void);

		PresidentialPardonForm	&operator=(const PresidentialPardonForm &rhs);

		std::string		getTarget(void) const;
		void			execute(const Bureaucrat &executor) const;

};

#endif
