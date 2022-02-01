#include "Bureaucrat.hpp"

int	main(){
	try{
		Form A39("A39", 150, 151);
	}
	catch(std::exception &e){
		std::cout << e.what() << std::endl;
	}
	try{
		Form A39("A40", 0, 1);
	}
	catch(std::exception &e){
		std::cout << e.what() << std::endl;
	}
	try{
		Form 		A38("A38", 50, 51);
		Bureaucrat	jim("Jim", 100);

		std::cout << A38 << jim << std::endl;
		jim.signForm(A38);
		A38.beSigned(jim);

	}
	catch(std::exception &e){
		std::cout << e.what() << std::endl;
	}
	try{
		Form 		A38("A38", 50, 51);
		Bureaucrat	kate("Kate", 50);

		std::cout << A38 << kate << std:: endl;
		A38.beSigned(kate);
		kate.signForm(A38);
	}
	catch(std::exception &e){
		std::cout << e.what() << std::endl;
	}
	return (0);
}