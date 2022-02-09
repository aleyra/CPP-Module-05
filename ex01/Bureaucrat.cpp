#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(){
}

Bureaucrat::Bureaucrat(Bureaucrat const &src){
	*this = src;
}

Bureaucrat::Bureaucrat(const std::string name,const int grade){
	this->_name = name;
	if (grade > 150){
		throw Bureaucrat::GradeTooLowException();
	}
	else if (grade < 1){
		throw Bureaucrat::GradeTooHighException();
	}
	else
		this->_grade = grade;
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

void	Bureaucrat::incrementGrade(){
	if (this->_grade != 1)
		this->_grade--;
}

void	Bureaucrat::decrementGrade(){
	if (this->_grade != 150)
		this->_grade++;
}

void	Bureaucrat::signForm(Form const &f){
	if (f.getSigned() == true)
		std::cout << this->_name << " signs " << f.getName() << std::endl;
	else
		std::cout << this->_name << " cannot sign " << f.getName() << " because "
			<< this->_name << "'s grade is too low\n"; 
}

std::ostream	&operator<<(std::ostream &o, Bureaucrat const &bc){
	o << bc.getName() << ", bureaucrat garde " << bc.getGrade();
	return (o); 
}