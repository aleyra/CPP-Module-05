#ifndef BUREAUCRAT_H
# define BUREAUCRAT_H

# include <iostream>
# include <string>

class Bureaucrat {
public:
	Bureaucrat();
	Bureaucrat(Bureaucrat const &src);
	Bureaucrat(const std::string name,const int grade);
	virtual ~Bureaucrat();

	Bureaucrat	&operator=(Bureaucrat const &src);

	std::string const	&getName() const;
	int 				getGrade() const;
	void				incrementGrade();
	void				decrementGrade();

	class GradeTooHighException : public std::exception{
		public:
			virtual const char* what() const throw(){
				return("Grade too High");
			}
	};

	class GradeTooLowException : public std::exception{
		public:
			virtual const char* what() const throw(){
				return("Grade too low");
			}
	};

protected:

private:
	std::string	_name;
	int			_grade;
};

	std::ostream	&operator<<(std::ostream &o, Bureaucrat const &bc);
#endif