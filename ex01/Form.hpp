#ifndef FORM_H
# define FORM_H

#include "Bureaucrat.hpp"

class Bureaucrat;

class Form{
public:
	Form();
	Form(std::string name, int sLvl, int exeLvl);
	Form(Form const &src);
	virtual ~Form();

	Form&	operator=(Form const &src);

	std::string const	&getName() const;
	int 				getSigned()const ;
	int 				getSLvl() const;
	int 				getExeLvl() const;
	Form				&beSigned(Bureaucrat &bc);

	class GradeTooHighException :public std::exception{
		public:
			virtual const char* what() const throw(){
				return ("Grade too high");
			}
	};

	class GradeTooLowException :public std::exception{
		public:
			virtual const char* what() const throw(){
				return ("Grade too low");
			}
	};

protected:

private:
	std::string const	_name;
	bool				_signed;//0 = nok and 1 = ok
	int const			_sLvl;
	int	const			_exeLvl;

};

std::ostream	&operator<<(std::ostream &o, Form const &f);

#endif