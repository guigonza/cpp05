/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Guille <Guille@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/27 13:29:41 by Guille            #+#    #+#             */
/*   Updated: 2026/03/02 17:21:53 by Guille           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

Bureaucrat::Bureaucrat(const std::string& name, int grade) : _name(name), _grade(grade)
{
	if (grade < 1)
		throw GradeTooHighException();
	else if (grade > 150)
		throw GradeTooLowException();
}
Bureaucrat::Bureaucrat(const Bureaucrat& other) : _name(other._name), _grade(other._grade)
{}
Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other)
{
	if (this == &other)
		return (*this);
	_grade = other._grade;
	return (*this);
}
Bureaucrat::~Bureaucrat()
{
}
const std::string& Bureaucrat::getName(void) const
{
	return (_name);
}
int Bureaucrat::getGrade(void) const
{
	return (_grade);
}

void Bureaucrat::increment(void)
{
	if ((_grade -1) < 1)
		throw GradeTooHighException();
	--_grade;
}
void Bureaucrat::decrement(void)
{
	if ((_grade +1) > 150)
		throw GradeTooLowException();
	++_grade;
}
void Bureaucrat::signForm(Form& f)
{
	try
	{
		f.beSigned(*this);
		std::cout << getName() << " signed " << f.getName() << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cout << getName() << " couldn't sign " << f.getName() << " because " << e.what() << std::endl;
	}
}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Grade too high");
}
const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Grade too low");
}
std::ostream& operator<<(std::ostream& os, const Bureaucrat& bu)
{
	os << bu.getName() << ", bureaucrat grade " << bu.getGrade() << "." << std::endl;
	return (os);
}