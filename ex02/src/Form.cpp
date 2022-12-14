#include "../headers/Form.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Form::Form(std::string const & name, int const signGrade, int const execGrade) : _name(name), _signed(false), _signGrade(signGrade), _execGrade(execGrade) 
{
	if (signGrade > 150 )
		throw Form::GradeTooLowException();
	else if (signGrade < 1)
		throw Form::GradeTooHighException();	
	std::cout << "\e[0;33mDefault Constructor called of Form\e[0m" << std::endl;
}

Form::Form( const Form & src ) : _name(src.getName()), _signed(false), _signGrade(src.getSignGrade()), _execGrade(src.getExecGrade())
{
	std::cout << "\e[0;33mCopy Constructor called of Form\e[0m" << std::endl;
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Form::~Form()
{
	std::cout << "\e[0;31mDestructor called of Form\e[0m" << std::endl;
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Form &				Form::operator=( Form const & rhs )
{
	if ( this != &rhs )
	{
		this->_signed = rhs.getSigned();
	}
	return *this;
}

std::ostream &			operator<<( std::ostream & o, Form const & i )
{
	o << 
	"Name = " 
	<< i.getName()
	<< ", Signed status = "
	<< i.getSigned()
	<< ", Required sign grade = "
	<< i.getSignGrade()
	<< ", Require execution grade = "
	<< i.getExecGrade()
	;
	return o;
}


// Getters

std::string	Form::getName() const
{
	return _name;
}

bool		Form::getSigned() const
{
	return _signed;
}
int			Form::getSignGrade() const
{
	return _signGrade;
}
int			Form::getExecGrade() const
{
	return _execGrade;
}


/*
** --------------------------------- METHODS ----------------------------------
*/

void	Form::beSigned( const Bureaucrat	&bureaucrat)
{
	if (bureaucrat.getGrade() > _signGrade)
		throw Form::GradeTooLowException();
	else
		_signed = true;
}

void	Form::beExecuted( const Bureaucrat &bureaucrat) const
{
	if (!_signed)
		throw Form::FormNotSigned();
	else if (bureaucrat.getGrade() > _execGrade)
		throw Form::GradeTooLowException();
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/


/* ************************************************************************** */