#include "../headers/Bureaucrat.hpp"

int main()
{
    try
    {
        Bureaucrat  taha("Taha", 1);
        std::cout<<taha<<std::endl;
    }
    catch(std::exception & e)
    {
        std::cout<<e.what();
    }
}