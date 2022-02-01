#ifndef INTERN_H
# define INTERN_H

# include "Bureaucrat.hpp"
# include "PresidentialPardonForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "ShrubberyCreationForm.hpp"

class Intern{

public :
	Intern();
	Intern(Intern const &src);
	virtual ~Intern();

	Intern	&operator=(Intern const &src);

	Form*	makeForm(std::string type_form, std::string target);

};

#endif