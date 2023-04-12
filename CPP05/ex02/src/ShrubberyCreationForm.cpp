#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(): AForm("Shrubbery", 145, 137)
{
	_target = "NoName";
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target): AForm("Shrubbery", 145, 137)
{
	_target = target;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &ori) : AForm("Shrubbery", 145, 137)
{
	_target = ori.getTarget();
	signature = ori.getSigned();
}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm &ori)
{
	_target = ori.getTarget();
	signature = ori.getSigned();
	return *this;
}

std::string	ShrubberyCreationForm::getTarget() const
{
	return _target;
}

void ShrubberyCreationForm::execAction()
{
	std::string		fileName = this->_target + "_shrubbery";
	std::ofstream	fd_out(fileName.c_str());
	// fd_out.open(fileName.c_str());
	if (!fd_out)
	{
		std::cerr << "can't open new file " << fileName << "\n";
		return;
	}
	fd_out << "                      ___ " << std::endl;
	fd_out << "                _,-'''   ''''`--. " << std::endl;
	fd_out << "             ,-'          __,,-- \\ " << std::endl;
	fd_out << "           ,'    __,--""""dF      ) " << std::endl;
	fd_out << "          /   .-'Hb_,--""dF      / " << std::endl;
	fd_out << "        ,'       _Hb ___dF'-._,-' " << std::endl;
	fd_out << "      ,'      _,-"""   """--..__ " << std::endl;
	fd_out << "     (     ,-'                  `. " << std::endl;
	fd_out << "      `._,'     _   _             ; " << std::endl;
	fd_out << "       ,'     ,' `-'Hb-.___..._,-' " << std::endl;
	fd_out << "       \\    ,''Hb.-'HH`-.dHF'' " << std::endl;
	fd_out << "        `--'   \"Hb  HH  dF\" " << std::endl;
	fd_out << "                \"Hb HH dF \"" << std::endl;
	fd_out << "                 \"HbHHdF \"" << std::endl;
	fd_out << "                  |HHHF " << std::endl;
	fd_out << "                  |HHH| " << std::endl;
	fd_out << "                  |HHH| " << std::endl;
	fd_out << "                  |HHH| " << std::endl;
	fd_out << "                  |HHH| " << std::endl;
	fd_out << "                  dHHHb " << std::endl;
	fd_out << "                .dFd|bHb.              o " << std::endl;
	fd_out << "      o       .dHFdH|HbTHb.         o / " << std::endl;
	fd_out << "  Y  |  __,dHHFdHH|HHhoHHb.__  | __  Y " << std::endl;
	fd_out.close();
}
