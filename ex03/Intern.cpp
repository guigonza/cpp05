/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Guille <Guille@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/02 22:49:08 by Guille            #+#    #+#             */
/*   Updated: 2026/03/02 23:32:49 by Guille           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>

Intern::Intern() 
{}
Intern::Intern(const Intern& other) 
{
	(void)other;
}
Intern& Intern::operator=(const Intern& other) 
{
	(void)other; 
	return (*this);
}
Intern::~Intern() {}

const char* Intern::UnknownFormException::what() const throw() {
    return ("Intern: unknown form request");
}

static AForm* createShrubbery(const std::string& target) {
    return new ShrubberyCreationForm(target);
}
static AForm* createRobotomy(const std::string& target) {
    return new RobotomyRequestForm(target);
}
static AForm* createPresidential(const std::string& target) {
    return new PresidentialPardonForm(target);
}

AForm* Intern::makeForm(const std::string& type, const std::string& target) const {
    typedef AForm* (*CreateFn)(const std::string&);
    const char* names[] = { "shrubbery creation", "robotomy request", "presidential pardon" };
    CreateFn funcs[] = { createShrubbery, createRobotomy, createPresidential };

    for (int i = 0; i < 3; ++i) {
        if (type == names[i]) {
            AForm* form = funcs[i](target);
            std::cout << "Intern creates " << names[i] << std::endl;
            return (form);
        }
    }
    throw UnknownFormException();
}