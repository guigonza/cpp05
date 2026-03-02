/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Guille <Guille@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/02 12:52:52 by Guille            #+#    #+#             */
/*   Updated: 2026/03/02 19:32:27 by Guille           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>

int main()
{
    // ShrubberyCreationForm: sign(145)/exec(137)
    {
        std::cout << "=== Shrubbery test ===\n";
        ShrubberyCreationForm form("home");
        Bureaucrat lowSigner("LowSigner", 150);
        Bureaucrat signer("Signer", 140);    // can sign (140 <= 145)
        Bureaucrat executor("Executor", 137); // can execute (137 <= 137)

        lowSigner.signForm(form);    // expected: couldn't sign
        signer.signForm(form);       // expected: signed
        executor.executeForm(form);  // expected: file created
        std::cout << '\n';
    }

    // RobotomyRequestForm: sign(72)/exec(45)
    {
        std::cout << "=== Robotomy test ===\n";
        RobotomyRequestForm form("Bender");
        Bureaucrat signer("RSigner", 70);    // can sign
        Bureaucrat executor("RExecutor", 45); // can execute

        // try execute before signing (should fail)
        executor.executeForm(form);
        signer.signForm(form);
        executor.executeForm(form); // many runs show 50% success
        std::cout << '\n';
    }

    // PresidentialPardonForm: sign(25)/exec(5)
    {
        std::cout << "=== Pardon test ===\n";
        PresidentialPardonForm form("Ford");
        Bureaucrat signer("PSigner", 25);
        Bureaucrat executor("PExecutor", 5);

        signer.signForm(form);
        executor.executeForm(form); // should print pardon message
        std::cout << '\n';
    }

    return 0;
}