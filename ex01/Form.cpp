#include "Form.hpp"

Form::Form():_name(""), _sLvl(1), _exeLvl(150){
	this->_signed = false;
}

Form::Form(std::string name, int sLvl, int exeLvl):_name(name), _sLvl(sLvl), _exeLvl(exeLvl){
	this->_signed = false;
	if (sLvl < 1)
		throw Form::GradeTooHighException();
	else if (sLvl > 150)
		throw Form::GradeTooLowException();
	if (exeLvl < 1)
		throw Form::GradeTooHighException();
	else if (exeLvl > 150)
		throw Form::GradeTooLowException();
}

Form::Form(Form const &src):_name(src._name), _sLvl(src._sLvl), _exeLvl(src._exeLvl){
	*this = src;
}

Form::~Form(){
}

Form&	Form::operator=(Form const &src){
	this->_signed = src.getSigned();
	return (*this);
}

std::string const	&Form::getName() const{
	return (this->_name);
}

int	Form::getSigned() const{
	return (this->_signed);
}

int	Form::getSLvl() const{
	return (this->_sLvl);
}

int	Form::getExeLvl() const{
	return (this->_exeLvl);
}

Form	&Form::beSigned(Bureaucrat &bc){
	if(bc.getGrade() <= this->getSLvl())
		this->_signed = true;
	else
		throw Form::GradeTooLowException();
	return (*this);
}

std::ostream	&operator<<(std::ostream &o, Form const &f){
	o << "Form: " << f.getName() << std::endl << "\tsigned: ";
	if (f.getSigned() == 1)
		o << "yes";
	else
		o << "no";
	o << std::endl << "\tgrade level required to sign: " << f.getSLvl()
		<< std::endl << "\tgrade level required to execute: " << f.getExeLvl()
		<< std::endl;
	return (o);
}
