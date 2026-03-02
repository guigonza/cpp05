/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Guille <Guille@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/02 16:39:11 by Guille            #+#    #+#             */
/*   Updated: 2026/03/02 17:38:29 by Guille           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form(const std::string& name, int gradeToSign, int gradeToExec) : _name(name), _isSigned(false), _gradeToSign(gradeToSign), _gradeToExec(gradeToExec)
{
	if (_gradeToSign < 1 || _gradeToExec < 1)
		throw GradeTooHighException();
	else if (_gradeToSign > 150 || _gradeToExec > 150)
		throw GradeTooLowException();
}
Form::Form(const Form& other) : _name(other._name), _isSigned(other._isSigned), _gradeToSign(other._gradeToSign), _gradeToExec(other._gradeToExec)
{}
Form& Form::operator=(const Form& other)
{
	if (this == &other)
		return (*this);
	_isSigned = other._isSigned;
	return (*this);
}
Form::~Form()
{
}
bool	Form::isSigned(void) const
{
	return (_isSigned);
}
int		Form::getGradeToSign(void) const
{
	return(_gradeToSign);
}
int		Form::getGradeToExec(void) const
{
	return (_gradeToExec);
}
const std::string& Form::getName() const
{
    return (_name);
}
void	Form::beSigned(const Bureaucrat& bu)
{
	if (bu.getGrade() <= _gradeToSign)
		_isSigned = true;
	else
		throw GradeTooLowException();
}
const char* Form::GradeTooHighException::what() const throw()
{
	return ("Form grade too high");
}
const char* Form::GradeTooLowException::what() const throw()
{
	return ("Form grade too low");
}
std::ostream& operator<<(std::ostream& os, const Form& f)
{
    os << "Form " << f.getName() << ", signed: ";
    if (f.isSigned())
        os << "true";
    else
        os << "false";
    os << ", sign grade: " << f.getGradeToSign()
       << ", exec grade: " << f.getGradeToExec()
       << "." << std::endl;
	return (os);
}