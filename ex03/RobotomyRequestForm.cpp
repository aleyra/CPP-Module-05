#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(): Form("Robotomy_Request", 72, 45){
	this->_target = "Jane Doe";
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const &src){
	*this = src;
}

RobotomyRequestForm::RobotomyRequestForm(std::string target): Form("Robotomy_Request", 72, 45){
	this->_target = target;
}

RobotomyRequestForm::~RobotomyRequestForm(){}

RobotomyRequestForm &RobotomyRequestForm::operator=(RobotomyRequestForm const &src){
	this->_target = src._target;
	return (*this);
}

void	RobotomyRequestForm::execute(Bureaucrat const &bc) const{
	std::srand(time(NULL));
	int	rand = std::rand() % 2;
	if (this->getSigned() == false)
		throw Form::NotSignedException();
	else if (bc.getGrade() > this->getExeLvl())
		throw Form::GradeTooLowException();
	else{
			std::cout << "[Drill Noises]\t";
		if (rand)
			std::cout << this->_target << " as been robotomized successfully\n";
		else
			std::cout << "Robotomy of " << this->_target << " failed\n";
	}
}
