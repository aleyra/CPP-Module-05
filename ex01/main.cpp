#include "Bureaucrat.hpp"

int	main(){
	Bureaucrat bob("bob", 100);
	Bureaucrat kate("kate", 1);
	Form A38("A38", 1, 2);
	Form A39("A39", 0, 151);
	
	std::cout << "There is 2 bureaucrats:" << std::endl
		<< bob << std::endl << kate << std::endl;
	std::cout <<"and 2 forms:" << std::endl;
	std::cout << A38 << A39;
	
	A38.beSigned(bob);
	A38.beSigned(kate);

	std::cout << A38;

	return (0);
}