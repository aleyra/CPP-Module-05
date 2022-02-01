#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int	main(){
	Bureaucrat	kate("Kate", 1);
	Bureaucrat	jim("Jim", 40);
	Bureaucrat	bob("Bob", 140);

	std::cout << kate << std::endl << jim << std::endl << bob << std::endl;

	ShrubberyCreationForm	sc("Aleyra");
	RobotomyRequestForm		rr("Candjix");
	PresidentialPardonForm	pp("toto");

	std::cout << sc << rr << pp;

	sc.beSigned(kate);
	kate.signForm(sc);
	rr.beSigned(kate);
	kate.signForm(rr);

	try{
		bob.executeForm(sc);
		sc.execute(bob);
	}
	catch(std::exception &e){
		std::cout << e.what() << std::endl;
	}
	try{
		jim.executeForm(sc);
		sc.execute(jim);
	}
	catch(std::exception &e){
		std::cout << e.what() << std::endl;
	}
	try{
		jim.executeForm(rr);
		rr.execute(jim);
	}
	catch(std::exception &e){
		std::cout << e.what() << std::endl;
	}
	try{
		kate.executeForm(pp);
		pp.execute(kate);
	}
	catch(std::exception &e){
		std::cout << e.what() << std::endl;
	}
	try{
		pp.beSigned(kate);
		kate.signForm(pp);
		kate.executeForm(pp);
		pp.execute(kate);
	}
	catch(std::exception &e){
		std::cout << e.what() << std::endl;
	}

	return (0);
}