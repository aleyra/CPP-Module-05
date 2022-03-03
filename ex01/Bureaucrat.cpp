#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat():_name(""), _grade(150){}

Bureaucrat::Bureaucrat(Bureaucrat const &src):_name(src._name), _grade(src._grade){}

Bureaucrat::Bureaucrat(const std::string name,const int grade): _name(name){
	if (grade > 150){
		throw Bureaucrat::GradeTooLowException();
	}
	else if (grade < 1){
		throw Bureaucrat::GradeTooHighException();
	}
	else
		this->_grade = grade;
}

Bureaucrat::~Bureaucrat(){}

Bureaucrat	&Bureaucrat::operator=(Bureaucrat const &src){
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
		std::cout << this->_name << " couldn’t sign " << f.getName() << " because "
			<< this->_name << "'s grade is too low\n"; 
}

std::ostream	&operator<<(std::ostream &o, Bureaucrat const &bc){
	o << bc.getName() << ", bureaucrat grade " << bc.getGrade();
	return (o); 
}