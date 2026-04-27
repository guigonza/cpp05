/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guigonza <guigonza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/02 12:52:52 by Guille            #+#    #+#             */
/*   Updated: 2026/04/27 17:49:17 by guigonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>

int main()
{
    {
        std::cout << "=== Shrubbery test ===\n";
        ShrubberyCreationForm form("home");
        Bureaucrat lowSigner("LowSigner", 150);
        Bureaucrat signer("Signer", 140);    
        Bureaucrat executor("Executor", 137); 

        lowSigner.signForm(form);    
        signer.signForm(form);      
        executor.executeForm(form); 
        std::cout << '\n';
    }

    {
        std::cout << "=== Robotomy test ===\n";
        RobotomyRequestForm form("Bender");
        Bureaucrat signer("RSigner", 70);    
        Bureaucrat executor("RExecutor", 45); 

        executor.executeForm(form);
        signer.signForm(form);
        executor.executeForm(form);
        std::cout << '\n';
    }

    {
        std::cout << "=== Pardon test ===\n";
        PresidentialPardonForm form("Ford");
        Bureaucrat signer("PSigner", 25);
        Bureaucrat executor("PExecutor", 5);

        signer.signForm(form);
        executor.executeForm(form);
        std::cout << '\n';
    }

    return 0;
}