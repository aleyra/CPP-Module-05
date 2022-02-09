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

RobotomyRequestForm::~RobotomyRequestForm(){
}

RobotomyRequestForm &RobotomyRequestForm::operator=(RobotomyRequestForm const &src){
	this->_target = src._target;
	return (*this);
}

void	RobotomyRequestForm::execute(Bureaucrat const &bc) const{
	if (this->getSigned() == false)
		throw Form::NotSignedException();
	else if (bc.getGrade() > this->getExeLvl())
		throw Form::GradeTooLowException();
	else{
		std::default_random_engine re;
		std::uniform_int_distribution<int> i{0, 1};
			std::cout << "[Drill Noises]\t";
		if (i(re) == 0)
			std::cout << this->_target << " as been robotomized successfully\n";
		else
			std::cout << "Robotomy of " << this->_target << " failed\n";
	}
}
