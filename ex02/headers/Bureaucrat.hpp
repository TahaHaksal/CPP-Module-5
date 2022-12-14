#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <string>
# include "Form.hpp"

class	Form;

class Bureaucrat
{
	public:
		// Constructors
		Bureaucrat(std::string	const & name, int const & grade);
		Bureaucrat(const Bureaucrat &copy);
		
		// Destructor
		~Bureaucrat();
		
		// Operators
		Bureaucrat & operator=(const Bureaucrat &assign);
		Bureaucrat & operator++();
		Bureaucrat & operator++(int);
		Bureaucrat & operator--();
		Bureaucrat & operator--(int);

		//Exceptions
		class	GradeTooHighException : public std::exception
		{
			public:
				GradeTooHighException() {}
				~GradeTooHighException() {}
				const char * what() const noexcept override {return "Grade is too high!\n";}
		};

		class	GradeTooLowException : public std::exception
		{
			public:
				GradeTooLowException(){}
				~GradeTooLowException() {}
				const char * what() const noexcept override {return "Grade is too low!\n";}
		};


		std::string	getName() const;
		int			getGrade() const;

		//Member Functinons
		void	signForm( Form & form);
		void	executeForm( Form & form);

	private:
		std::string const	_name;
		int				_grade;
};

std::ostream& operator<< (std::ostream &os, Bureaucrat const& obj);

#endif
