#include "Intern.hpp"

Intern::Intern(){}

Intern::Intern(Intern const &src){
	*this = src;
}

Intern::~Intern(){}

Intern	&Intern::operator=(Intern const &src){
	(void)src;
	return (*this);
}

Form*	Intern::makeForm(std::string type_form, std::string target){
	Form* ret;
	std::string	type[3] = {
		"presidential pardon",
		"robotomy request",
		"shrubbery creation"
	};
	int	j = 0;

	while (j < 3 && type_form.compare(type[j]) != 0)
		j++;
	
	switch(j){
		case 0:
			ret = new PresidentialPardonForm(target);
			break;
		case 1:
			ret = new RobotomyRequestForm(target);
			break;
		case 2:
			ret = new ShrubberyCreationForm(target);
			break;
		default:
			ret = NULL;
			break;
	}
	if (ret == NULL)
		std::cout << type_form << " is not an existing form\n";
	else
		std::cout << "Intern creates " << type_form << std::endl;
	return (ret);
}
