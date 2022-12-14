#include "../headers/Bureaucrat.hpp"
#include "../headers/Form.hpp"
#include "../headers/ShrubberyCreationForm.hpp"
#include "../headers/RobotomyRequestForm.hpp"

int main()
{
    try
    {
        Bureaucrat  taha("Taha", 130);
        ShrubberyCreationForm a("a0x87-T");
        taha.signForm(a);
        // a.execute(taha);
    }
    catch(std::exception & e)
    {
        std::cout << e.what() << "\n";
    }
}