#ifndef PRESIDENTIALPARDONFORM_H
# define PRESIDENTIALPARDONFORM_H

# include "Bureaucrat.hpp"
# include "Form.hpp"

class Bureaucrat;

class PresidentialPardonForm: public Form{
public:
	PresidentialPardonForm();
	PresidentialPardonForm(PresidentialPardonForm const &src);
	PresidentialPardonForm(std::string target);
	virtual ~PresidentialPardonForm();

	PresidentialPardonForm &operator=(PresidentialPardonForm const &src);

	void	execute(Bureaucrat const &bc) const;

private:
	std::string	_target;
};

#endif