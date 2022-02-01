#ifndef ROBOTOMYREQUESTFORM_H
# define ROBOTOMYREQUESTFORM_H

# include "Bureaucrat.hpp"
# include "Form.hpp"

class Bureaucrat;

class RobotomyRequestForm: public Form{
public:
	RobotomyRequestForm();
	RobotomyRequestForm(RobotomyRequestForm const &src);
	RobotomyRequestForm(std::string target);
	virtual ~RobotomyRequestForm();

	RobotomyRequestForm &operator=(RobotomyRequestForm const &src);

	void	execute(Bureaucrat const &bc) const;

private:
	std::string	_target;
};

#endif