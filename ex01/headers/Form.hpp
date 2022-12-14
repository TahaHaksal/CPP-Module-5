#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include <string>
# include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{

	public:

		Form(std::string const & name, int const signGrade, int const execGrade);
		Form( Form const & src );
		~Form();

		Form &		operator=( Form const & rhs );

		// Getters and Setters
		std::string	getName() const;
		bool		getSigned() const;
		int			getSignGrade() const;
		int			getExecGrade() const;

		// Exceptions
		class GradeTooLowException : public	std::exception
		{
			public:
				GradeTooLowException() {}
				~GradeTooLowException() {}
				const char * what() const noexcept override {return "Grade is too low!\n";}
		};
		
		class GradeTooHighException : public	std::exception
		{
			public:
				GradeTooHighException() {}
				~GradeTooHighException() {}
				const char * what() const noexcept override {return "Grade is too high!\n";}
		};

		//Member Functions
		void	beSigned( const Bureaucrat	&bureaucrat);
		
	private:
		std::string	const	_name;
		bool				_signed;
		const	int			_signGrade;
		const	int			_execGrade;
};

std::ostream &			operator<<( std::ostream & o, Form const & i );

#endif /* ************************************************************ FORM_H */