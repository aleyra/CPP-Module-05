#ifndef FORM_H
# define FORM_H

# include "Bureaucrat.hpp"
# include <fstream>
# include <random>

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
	virtual void		execute(Bureaucrat const &bc) const = 0;

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

	class NotSignedException :public std::exception{
		public:
			virtual const char* what() const throw(){
				return ("Form not signed yet");
			}
	};

protected:

private:
	std::string const	_name;
	bool				_signed;
	int const			_sLvl;
	int	const			_exeLvl;

};

std::ostream	&operator<<(std::ostream &o, Form const &f);

#endif