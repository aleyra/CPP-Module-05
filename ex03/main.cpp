# include "Intern.hpp"

int main(){
	Form*	sc;
	Form*	rr;
	Form*	pp;
	Form*	oups;
	Intern	max;

	pp = max.makeForm("presidential pardon", "toto");
	rr = max.makeForm("robotomy request", "titi");
	sc = max.makeForm("shrubbery creation", "doudou");
	oups = max.makeForm("holyday request", "lazy guy");

	delete pp;
	delete rr;
	delete sc;

	return (0);
}