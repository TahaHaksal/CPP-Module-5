#include "../headers/Bureaucrat.hpp"
#include "../headers/Form.hpp"

int main()
{
    try
    {
        Bureaucrat  taha("Taha", 10);
        Form        rando("ikametgah", 1, 5);
        taha.signForm(rando);
    }
    catch(std::exception & e)
    {
        std::cout<< "\n" << e.what() << "\n";
    }
}