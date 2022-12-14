#include "../headers/Bureaucrat.hpp"

// Constructors
Bureaucrat::Bureaucrat(std::string	const & name, int const & grade) : _name(name)
{
	if ( grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	else
		_grade = grade;
	std::cout << "\e[0;33mDefault Constructor called of Bureaucrat\e[0m" << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat &copy) : _name(copy.getName()), _grade(copy.getGrade())
{
	std::cout << "\e[0;33mCopy Constructor called of Bureaucrat\e[0m" << std::endl;
}


// Destructor
Bureaucrat::~Bureaucrat()
{
	std::cout << "\e[0;31mDestructor called of Bureaucrat\e[0m" << std::endl;
}


// Operators
Bureaucrat & Bureaucrat::operator=(const Bureaucrat &assign)
{
	(void) assign;
	return *this;
}

Bureaucrat & Bureaucrat::operator++()
{
	_grade--;
	if ( _grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else
		return *this;
}

Bureaucrat & Bureaucrat::operator++(int)
{
	_grade--;
	if ( _grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else
		return *this;
}

Bureaucrat & Bureaucrat::operator--()
{
	_grade++;
	if ( _grade > 150)
		throw Bureaucrat::GradeTooLowException();
	else
		return *this;
}

Bureaucrat & Bureaucrat::operator--(int)
{
	_grade++;
	if ( _grade > 150)
		throw Bureaucrat::GradeTooLowException();
	else
		return *this;
}

std::ostream& operator<< (std::ostream &os, Bureaucrat const& obj)
{
	return os << obj.getName() << ", bureaucrat grade " << obj.getGrade() << ".";
}

// Getters and Setters

std::string Bureaucrat::getName() const
{
	return _name;
}

int Bureaucrat::getGrade() const
{
	return _grade;
}

// Member Functions

void	Bureaucrat::signForm( Form & form)
{
	try
	{
		form.beSigned(*this);
		std::cout<< _name << " signed " << form.getName() << "\n";
	}
	catch(const std::exception& e)
	{
		std::cout << _name << " couldn't sign " << form.getName() << " becuase: " << e.what();
	}
	
}
