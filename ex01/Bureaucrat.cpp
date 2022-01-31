#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(){
}

Bureaucrat::Bureaucrat(Bureaucrat const &src){
	*this = src;
}

Bureaucrat::Bureaucrat(const std::string name,const int grade){
	this->_name = name;
	try{
		if (grade > 150){
			throw Bureaucrat::GradeTooLowException();
		}
		else if (grade < 1){
			throw Bureaucrat::GradeTooHighException();
		}
		else
			this->_grade = grade;
	}
	catch (Bureaucrat::GradeTooHighException &e){
		this->_grade = 1;
		std::cerr << e.what() << std::endl;
	}
	catch (Bureaucrat::GradeTooLowException &e){
		this->_grade = 150;
		std::cerr << e.what() << std::endl;
	}
}

Bureaucrat::~Bureaucrat(){
}

Bureaucrat	&Bureaucrat::operator=(Bureaucrat const &src){
	this->_name = src.getName();
	this->_grade = src.getGrade();
	return(*this);
}

std::string const	&Bureaucrat::getName() const{
	return (this->_name);
}

int	Bureaucrat::getGrade() const{
	return(this->_grade);
}

Bureaucrat	Bureaucrat::operator++(){
	try{
		if (this->getGrade() == 1)
			throw Bureaucrat::GradeTooHighException();
		else
			this->_grade--;
	}
	catch(Bureaucrat::GradeTooHighException &e){
		this->_grade = 1;
		std::cerr << e.what() << std::endl;
	}
	return (*this);
}

Bureaucrat	Bureaucrat::operator++(int ){
	Bureaucrat	t(*this);

	this->operator++();
	return(t);
}

Bureaucrat	Bureaucrat::operator--(){
	try{
		if (this->getGrade() == 150)
			throw Bureaucrat::GradeTooLowException();
		else
			this->_grade++;
	}
	catch(Bureaucrat::GradeTooLowException &e){
		this->_grade = 150;
		std::cerr << e.what() << std::endl;
	}
	return (*this);
}

Bureaucrat	Bureaucrat::operator--(int ){
	Bureaucrat	t(*this);

	this->operator--();
	return(t);
}

void	Bureaucrat::beSigned(Form const &f){
	std::cout << this->getName();
	if (f.getSigned() == 1)
		std::cout << " signs " << f.getName();
	else
		std::cout << " cannot sign because his grade is too low";
	std::cout << std::endl;
}

std::ostream	&operator<<(std::ostream &o, Bureaucrat const &bc){
	o << bc.getName() << ", bureaucrat garde " << bc.getGrade();
	return (o); 
}