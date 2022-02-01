#ifndef SHRUBBERYCREATIONFORM_H
# define SHRUBBERYCREATIONFORM_H

# include "Bureaucrat.hpp"
# include "Form.hpp"

class Bureaucrat;

class ShrubberyCreationForm: public Form{
public:
	ShrubberyCreationForm();
	ShrubberyCreationForm(ShrubberyCreationForm const &src);
	ShrubberyCreationForm(std::string target);
	virtual ~ShrubberyCreationForm();

	ShrubberyCreationForm &operator=(ShrubberyCreationForm const &src);

	void	execute(Bureaucrat const &bc) const;

private:
	std::string	_target;
};

#endif