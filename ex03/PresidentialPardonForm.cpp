#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(): Form("Presidential_Pardon", 25, 5){
	this->_target = "Jane Doe";
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const &src){
	*this = src;
}

PresidentialPardonForm::PresidentialPardonForm(std::string target): Form("Presidential_Pardon", 25, 5){
	this->_target = target;
}

PresidentialPardonForm::~PresidentialPardonForm(){
}

PresidentialPardonForm &PresidentialPardonForm::operator=(PresidentialPardonForm const &src){
	this->_target = src._target;
	return (*this);
}

void	PresidentialPardonForm::execute(Bureaucrat const &bc) const{
	if (this->getSigned() == false)
		throw Form::NotSignedException();
	else if (bc.getGrade() > this->getExeLvl())
		throw Form::GradeTooLowException();
	else
		std::cout << this->_target << " has been pardoned by Zafod Beeblebrox" << std::endl;
}
