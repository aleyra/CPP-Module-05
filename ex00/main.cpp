#include "Bureaucrat.hpp"

int	main(){
	std::cout << "let's register 3 bureaucrats :" << std::endl
		<< "Jim with a grade of 150" << std::endl
		<< "bob with a grade of 151" << std::endl
		<< "kate with a grade of 0" << std::endl;
	Bureaucrat jim("jim", 150);
	Bureaucrat bob("bob", 151);
	Bureaucrat kate("kate", 0);
	
	std::cout << "here they are:" << std::endl
		<< jim << std::endl	<< bob << std::endl << kate << std::endl;

	jim++;
	++bob;
	std::cout << jim.getName() << " has got a promotion, is now grade "
		<< jim.getGrade() << std::endl;
	std::cout << "and " << bob.getName() << " also : " << bob.getGrade()
		<< std::endl;
	kate++;
	std::cout << " and " << kate.getName() << ": "
		<< kate.getGrade() << std::endl;
	return (0);
}