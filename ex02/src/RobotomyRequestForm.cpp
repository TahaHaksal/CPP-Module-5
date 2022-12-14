#include "../headers/RobotomyRequestForm.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

RobotomyRequestForm::RobotomyRequestForm(std::string target) : Form("RobotomyRequestForm", 72, 45), _target(target)
{
}

RobotomyRequestForm::RobotomyRequestForm( const RobotomyRequestForm & src ) : Form("RobotomyRequestForm", 72, 45), _target(src.getTarget())
{
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

RobotomyRequestForm::~RobotomyRequestForm()
{
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

RobotomyRequestForm &				RobotomyRequestForm::operator=( RobotomyRequestForm const & rhs )
{
	if ( this != &rhs )
	{
		_target = rhs.getTarget();
	}
	return *this;
}

std::ostream &			operator<<( std::ostream & o, RobotomyRequestForm const & i )
{
	//o << "Value = " << i.getValue();
	return o;
}


/*
** --------------------------------- METHODS ----------------------------------
*/

std::string RobotomyRequestForm::getTarget( void ) const
{
	return _target;
}

void	RobotomyRequestForm::execute ( Bureaucrat const & executor ) const
{
	try
	{
		execute (executor);
		srand(time(0));
		std::cout << "*BZZZzzzZZzzzZZzZZZzzZZZZZ*" << std::endl;
		if (rand() % 2)
			std::cout << _target << " has been succesfully robotomized. Congrats!" << std::endl;
		else
			std::cout << _target << " has been failed to be robotomized. I'm sorry. :'(\n";
	}
	catch (std::exception & e)
	{
		std::cout << "The file hasn't been executed because: " << e.what() << std::endl;
	}
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/


/* ************************************************************************** */