/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Guille <Guille@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/02 16:39:11 by Guille            #+#    #+#             */
/*   Updated: 2026/03/02 18:06:32 by Guille           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm(const std::string& name, int gradeToSign, int gradeToExec) : _name(name), _isSigned(false), _gradeToSign(gradeToSign), _gradeToExec(gradeToExec)
{
	if (_gradeToSign < 1 || _gradeToExec < 1)
		throw GradeTooHighException();
	else if (_gradeToSign > 150 || _gradeToExec > 150)
		throw GradeTooLowException();
}
AForm::AForm(const AForm& other) : _name(other._name), _isSigned(other._isSigned), _gradeToSign(other._gradeToSign), _gradeToExec(other._gradeToExec)
{}
AForm& AForm::operator=(const AForm& other)
{
	if (this == &other)
		return (*this);
	_isSigned = other._isSigned;
	return (*this);
}
AForm::~AForm()
{
}
bool	AForm::isSigned(void) const
{
	return (_isSigned);
}
int		AForm::getGradeToSign(void) const
{
	return(_gradeToSign);
}
int		AForm::getGradeToExec(void) const
{
	return (_gradeToExec);
}
const std::string& AForm::getName() const
{
    return (_name);
}
void	AForm::beSigned(const Bureaucrat& bu)
{
	if (bu.getGrade() <= _gradeToSign)
		_isSigned = true;
	else
		throw GradeTooLowException();
}
void	AForm::execute(const Bureaucrat& executor) const
{
	if (!_isSigned)
		throw NotSignedException();
	if (executor.getGrade() > _gradeToExec)
		throw GradeTooLowException();
	executeAction();
}
const char* AForm::GradeTooHighException::what() const throw()
{
	return ("AForm grade too high");
}
const char* AForm::GradeTooLowException::what() const throw()
{
	return ("AForm grade too low");
}
const char* AForm::NotSignedException::what() const throw()
{
    return ("Form is not signed");
}
std::ostream& operator<<(std::ostream& os, const AForm& f)
{
    os << "AForm " << f.getName() << ", signed: ";
    if (f.isSigned())
        os << "true";
    else
        os << "false";
    os << ", sign grade: " << f.getGradeToSign()
       << ", exec grade: " << f.getGradeToExec()
       << "." << std::endl;
	return (os);
}