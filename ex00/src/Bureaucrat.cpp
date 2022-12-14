#include "../headers/Bureaucrat.hpp"
#include <string>

// Constructors
Bureaucrat::Bureaucrat(std::string	const & name, int const & grade)
{
	if ( grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	else
	{
		_name = name;
		_grade = grade;
	}
	std::cout << "\e[0;33mDefault Constructor called of Bureaucrat\e[0m" << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat &copy)
{
	if ( copy._grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else if (copy._grade > 150)
		throw Bureaucrat::GradeTooLowException();
	else
	{
		_name = copy._name;
		_grade = copy._grade;
	}
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
