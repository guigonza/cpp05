/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guigonza <guigonza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/02 12:52:52 by Guille            #+#    #+#             */
/*   Updated: 2026/04/27 17:49:36 by guigonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "Bureaucrat.hpp"
#include <iostream>

int main()
{
    Intern intern;

    std::cout << "=== Intern creates forms ===\n\n";

    try {
        AForm* f1 = intern.makeForm("shrubbery creation", "garden");
        Bureaucrat signer1("SignerShrub", 140);
        Bureaucrat exec1("ExecShrub", 137);

        signer1.signForm(*f1);
        exec1.executeForm(*f1); 
        delete f1;
    } catch (const std::exception& e) {
        std::cout << "Error Shrubbery: " << e.what() << '\n';
    }

    std::cout << '\n';

    try {
        AForm* f2 = intern.makeForm("robotomy request", "Bender");
        Bureaucrat signer2("SignerRobo", 70);
        Bureaucrat exec2("ExecRobo", 45);

        exec2.executeForm(*f2); 
        signer2.signForm(*f2);
        exec2.executeForm(*f2); 
        delete f2;
    } catch (const std::exception& e) {
        std::cout << "Error Robotomy: " << e.what() << '\n';
    }

    std::cout << '\n';

    try {
        AForm* f3 = intern.makeForm("presidential pardon", "Ford");
        Bureaucrat signer3("SignerP", 25);
        Bureaucrat exec3("ExecP", 5);

        signer3.signForm(*f3);
        exec3.executeForm(*f3); 
        delete f3;
    } catch (const std::exception& e) {
        std::cout << "Error Pardon: " << e.what() << '\n';
    }

    std::cout << '\n';

    try {
        AForm* bad = intern.makeForm("unknown form", "target");
        delete bad;
    } catch (const std::exception& e) {
        std::cout << "Expected failure: " << e.what() << '\n';
    }

    return 0;
}