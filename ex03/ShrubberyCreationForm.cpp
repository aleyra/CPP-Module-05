#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(): Form("Shrubbery_Creation", 145, 137){
	this->_target = "Jane Doe";
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &src){
	*this = src;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target): Form("Shrubbery_Creation", 145, 137){
	this->_target = target;
}

ShrubberyCreationForm::~ShrubberyCreationForm(){
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(ShrubberyCreationForm const &src){
	this->_target = src._target;
	return (*this);
}

void	ShrubberyCreationForm::execute(Bureaucrat const &bc) const{
	if (this->getSigned() == false)
		throw Form::NotSignedException();
	else if (bc.getGrade() > this->getExeLvl())
		throw Form::GradeTooLowException();
	else{
		std::ofstream	treeMadeInASCII;
		std::string	file_name = this->_target + "_shrubbery";
		treeMadeInASCII.open(file_name);
		if (treeMadeInASCII.fail())
		{
			std::cout << "Shrubbery File creation failed" << std::endl;
			return ;
		}
		else
		{
			treeMadeInASCII << "                                                     ." << std::endl;
			treeMadeInASCII << "                                              .         ;  " << std::endl;
			treeMadeInASCII << "                 .              .              ;%     ;;   " << std::endl;
			treeMadeInASCII << "                   ,           ,                :;%  %;   " << std::endl;
			treeMadeInASCII << "                    :         ;                   :;%;'     .,   " << std::endl;
			treeMadeInASCII << "           ,.        %;     %;            ;        %;'    ,; " << std::endl;
			treeMadeInASCII << "             ;       ;%;  %%;        ,     %;    ;%;    ,%' " << std::endl;
			treeMadeInASCII << "              %;       %;%;      ,  ;       %;  ;%;   ,%;' " << std::endl;
			treeMadeInASCII << "               ;%;      %;        ;%;        % ;%;  ,%;'" << std::endl;
			treeMadeInASCII << "                `%;.     ;%;     %;'         `;%%;.%;'" << std::endl;
			treeMadeInASCII << "                 `:;%.    ;%%. %@;        %; ;@%;%'" << std::endl;
			treeMadeInASCII << "                    `:%;.  :;bd%;          %;@%;'" << std::endl;
			treeMadeInASCII << "                      `@%:.  :;%.         ;@@%;'   " << std::endl;
			treeMadeInASCII << "                        `@%.  `;@%.      ;@@%;         " << std::endl;
			treeMadeInASCII << "                          `@%%. `@%%    ;@@%;        " << std::endl;
			treeMadeInASCII << "                            ;@%. :@%%  %@@%;       " << std::endl;
			treeMadeInASCII << "                              %@bd%%%bd%%:;     " << std::endl;
			treeMadeInASCII << "                                #@%%%%%:;;" << std::endl;
			treeMadeInASCII << "                                %@@%%%::;" << std::endl;
			treeMadeInASCII << "                                %@@@%(o);  . '         " << std::endl;
			treeMadeInASCII << "                                %@@@o%;:(.,'         " << std::endl;
			treeMadeInASCII << "                            `.. %@@@o%::;         " << std::endl;
			treeMadeInASCII << "                               `)@@@o%::;         " << std::endl;
			treeMadeInASCII << "                                %@@(o)::;        " << std::endl;
			treeMadeInASCII << "                               .%@@@@%::;         " << std::endl;
			treeMadeInASCII << "                               ;%@@@@%::;.          " << std::endl;
			treeMadeInASCII << "                              ;%@@@@%%:;;;. " << std::endl;
			treeMadeInASCII << "                          ...;%@@@@@%%:;;;;,..  " << std::endl << std::endl;
		}
		treeMadeInASCII.close();
	}
}
