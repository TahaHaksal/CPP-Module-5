#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include <string>
# include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
	protected:
		Form(std::string const & name, int const signGrade, int const execGrade);
		Form( Form const & src );
		~Form();

		Form &		operator=( Form const & rhs );

	public:
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

		class FormNotSigned : public	std::exception
		{
			public:
				FormNotSigned() {}
				~FormNotSigned() {}
				const char * what() const noexcept override {return "This form is not signed!\n";}
		};

		//Member Functions
		void			beSigned( const Bureaucrat	&bureaucrat);
		void			beExecuted( const Bureaucrat &bureaucrat) const ;
		virtual void	execute ( Bureaucrat const & executor ) const = 0;
	private:
		std::string	const	_name;
		bool				_signed;
		const	int			_signGrade;
		const	int			_execGrade;
};

std::ostream &			operator<<( std::ostream & o, Form const & i );

#endif /* ************************************************************ FORM_H */