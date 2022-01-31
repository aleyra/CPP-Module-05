#ifndef BUREAUCRAT_H
# define BUREAUCRAT_H

# include <iostream>
# include <string>
#include "Form.hpp"

class Form;

class Bureaucrat {
public:
	Bureaucrat();
	Bureaucrat(Bureaucrat const &src);
	Bureaucrat(const std::string name,const int grade);
	virtual ~Bureaucrat();

	Bureaucrat	&operator=(Bureaucrat const &src);

	std::string const	&getName() const;
	int 				getGrade() const;
	Bureaucrat		operator++();
	Bureaucrat		operator++(int );
	Bureaucrat		operator--();
	Bureaucrat		operator--(int );

	void			beSigned(Form const &f);

	class GradeTooHighException : public std::exception{
		public:
			virtual const char* what() const throw(){
				return("Grade too High, grade set at 1");
			}
	};

	class GradeTooLowException : public std::exception{
		public:
			virtual const char* what() const throw(){
				return("Grade too low, grade set at 150");
			}
	};

protected:

private:
	std::string	_name;
	int			_grade;
};

	std::ostream	&operator<<(std::ostream &o, Bureaucrat const &bc);
#endif