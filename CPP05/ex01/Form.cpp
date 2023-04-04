
std::ostream& operator<<(std::ostream& out, const Form &target)
{
	std::cout <<"Form : " target.getName() << " need grade " << (int)target.getSignatureGrade() << " to be signed, ";
	std::cout << (int)target.getExecuteGrade() << "to be executed. Is signed : " << target.getSigned() << std::endl;
	return out;
}