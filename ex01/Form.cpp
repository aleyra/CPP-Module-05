#include "Form.hpp"

Form::Form(){
}

Form::Form(std::string name, int sLvl, int exeLvl){
	this->_name = name;
	this->_signed = 0;
	try{
		if (sLvl < 1)
			throw Form::GradeTooHighException();
		else if (sLvl > 150)
			throw Form::GradeTooLowException();
		else
			this->_sLvl = sLvl;
	}
	catch (GradeTooHighException &e){
		this->_sLvl = 1;
		std::cerr << e.what() << std::endl;
	}
	catch (GradeTooLowException &e){
		this->_sLvl = 150;
		std::cerr << e.what() << std::endl;
	}
	try{
		if (exeLvl < 1)
			throw Form::GradeTooHighException();
		else if (exeLvl > 150)
			throw Form::GradeTooLowException();
		else
			this->_exeLvl = exeLvl;
	}
	catch (GradeTooHighException &e){
		this->_exeLvl = 1;
		std::cerr << e.what() << std::endl;
	}
	catch (GradeTooLowException &e){
		this->_exeLvl = 150;
		std::cerr << e.what() << std::endl;
	}
}

Form::Form(Form const &src){
	*this = src;
}

Form::~Form(){
}

Form&	Form::operator=(Form const &src){
	this->_name = src.getName();
	this->_signed = src.getSigned();
	this->_sLvl = src.getSLvl();
	this->_exeLvl = src.getExeLvl();
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
	try{
		if(bc.getGrade() > this->getSLvl())
			throw Form::GradeTooLowException();
		else
			this->_signed = 1;
	}
	catch(Form::GradeTooLowException &e){
		std::cerr << e.what() << std::endl;
	}
	bc.beSigned(*this);
	return (*this);
}

std::ostream	&operator<<(std::ostream &o, Form const &f){
	o << "Form: " << f.getName() << std::endl << "\tsigned: ";
	if (f.getSigned() == 1)
		o << "yes(1)";
	else
		o << "no(0)";
	o << std::endl << "\tgrade level required to sign: " << f.getSLvl()
		<< std::endl << "\tgrade level required to execute: " << f.getExeLvl()
		<< std::endl;
	return (o);
}
