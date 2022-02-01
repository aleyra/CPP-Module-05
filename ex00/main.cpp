#include "Bureaucrat.hpp"

int	main(){
	std::cout << "let's try to register 3 bureaucrats :" << std::endl
		<< "Jim with a grade of 150" << std::endl
		<< "bob with a grade of 151" << std::endl
		<< "kate with a grade of 0" << std::endl;
	try{
		Bureaucrat jim("jim", 150);

		std::cout << jim << std::endl;
		jim.incrementGrade();
		std::cout << jim << std::endl;
		jim.decrementGrade();
		std::cout << jim << std::endl;
	}
	catch(std::exception &e){
		std::cout << e.what() << std::endl;
	}
	try{
		Bureaucrat bob("bob", 151);

		std::cout << bob << std::endl;
		bob.incrementGrade();
		std::cout << bob << std::endl;
		bob.decrementGrade();
		std::cout << bob << std::endl;
	}
	catch(std::exception &e){
		std::cout << e.what() << std::endl;
	}
	try{
		Bureaucrat kate("kate", 0);

		std::cout << kate << std::endl;
		kate.incrementGrade();
		std::cout << kate << std::endl;
		kate.decrementGrade();
		std::cout << kate << std::endl;
	}
	catch(std::exception &e){
		std::cout << e.what() << std::endl;
	}

	return (0);
}