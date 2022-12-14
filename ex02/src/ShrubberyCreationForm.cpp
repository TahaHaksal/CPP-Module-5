#include "../headers/ShrubberyCreationForm.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : Form("ShrubberyCreationForm", 145, 137)
{
	_target = target;
}

ShrubberyCreationForm::ShrubberyCreationForm( const ShrubberyCreationForm & src ) : Form("ShrubberyCreationForm", 145, 137)
{
	_target = src.getTarget();
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

ShrubberyCreationForm::~ShrubberyCreationForm()
{
}

/*
** --------------------------------- OVERLOAD ---------------------------------
*/

ShrubberyCreationForm &				ShrubberyCreationForm::operator=( ShrubberyCreationForm const & rhs )
{
	if ( this != &rhs )
	{
		this->_target = rhs.getTarget();
	}
	return *this;
}

std::ostream &			operator<<( std::ostream & o, ShrubberyCreationForm const & i )
{
	//o << "Value = " << i.getValue();
	return o;
}


/*
** --------------------------------- METHODS ----------------------------------
*/

std::string	ShrubberyCreationForm::getTarget(  void ) const
{
	return _target;
}

void	ShrubberyCreationForm::execute(Bureaucrat const & executor) const 
{
	std::string tree = R"(
                                                        ,
                                            .__ ._       \_.
                                     _, _.  '  \/   \.-  /
                                      \/     .-_`   // |/     \,
                     .-""""-.          \.   '   \`. ||  \.-'  /
                    F        Y        .-.`-(   _/\ V/ \\//,-' >-'   ._,
                   F          Y   .__/   `. \.   ' J   ) ./  / __._/
                  J         \, I    '   _/ \  \  | |  / /  .'-'.-' `._,
           (       L   \_.--.| \_.      ' .___ `\: | / .--'.-'"     \
         \ '\    .  L   /    \\/        ._/`-.`  \ .'.' .'---./__   '
    \__  '\ ) \._/   `-.__. ` \\_. '   .---.  \     /  /  ,   `  `
  --'  \\  ): // \,            `-.`__.'     `- \  /   / _/-.---.__.- .
     _.-`.'/ /'\_, ._     >--.-""'____.--"`_     '   /.'..' \   \   _/`
 _ .---._\ \'/ '__./__.-..  / .-|(    x_.-'___  |   :' /    _..---_' \
 .:' /`\ `. `..'.--'\      /.' /`-`._  `-,'   ` '   I '_.--'__--..___.--._.-
     `  `. `\/'/  _.   _.-'      _.____./ .-.--""-. .-"    ' _..-.---'   \
  -._ .--.\ / /-./     /   .---'-//.___. .-'       \__ .--.  `    `.     '`-
 ,--'/.-. ^.   .-.--.  ` _/    _//     ./   _..   .'  `.    \ \    |_.
    /' | >.   ' | \._.-       '    _..'  `.' . `.       )    | |\  `
  ./ \ \'  ) c| /  \     \_..  .--'    ,\ \_/`  :    )  (`-. `.|`\\
   \'  / ,-.  | ` ./`  ._/ `\\'.--.,-((  `.`.__ |   _/   \    |)  `--._/`
______'\   |  < __________  //'  //  _)   )/-._`.  (,-')  )  / \_.    /\. _____
a:f        |  |        .__./    //  '\  |//    `.\ '\ (  (  <`   ._  '
           >  |      _.  /   ..-\ _    _/ \_.  \ `\    \_ `---.-'__
        . /  `-   _.'        /   `   _/|       J  /`     `-,,-----.`-.
            '  .:'          '`      '          < `   f  I //        `­\_,
              '                         \.     J        I/\_.        ./
         __/                            `:     I  .:    K  `          `
         \/ )                            `,   J         L
          )_(_                             .  F  .-'    J
         /    `.                           .  I  (.   . I _.-.._
   '    <'    \ )                     _.---.J/      :'   L -'
 .:.     \. _.->/                        _.-'_.)     ` `-.`---.,_.
:<        (    \                    .--""   .F' J) `.`L.__`-.___
.:        |-'\_.|                          Y ..Z     ))   `--'  `-
.         ) | > :                            . '    :'
          / ) L_J                            .x,.
          L_J .,                             .:<.,
        .'`   `                               :J.,`
                                           . ;.+K,:.
                                               .,L+.,
  )";
  try
  {
    beExecuted(executor);
    std::ofstream	fileName(_target + "_shrubbery");
    fileName << tree;
    fileName.close();
  }
  catch ( std::exception & e)
  {
    std::cout << "The file hasn't been executed because: " << e.what() << std::endl;
    }
}


/*
** --------------------------------- ACCESSOR ---------------------------------
*/


/* ************************************************************************** */