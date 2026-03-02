/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Guille <Guille@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/02 12:52:52 by Guille            #+#    #+#             */
/*   Updated: 2026/03/02 17:43:28 by Guille           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main(void)
{
    // --- Creación e impresión ---
    std::cout << "======== Creation and printing with operator =======\n" << std::endl;
    {
        Bureaucrat A("Alice", 42);
        Form f("FormA", 50, 30);
        std::cout << A << f << "\n";
    }

    // --- Constructores inválidos de Form ---
    std::cout << "\n======== Try/catch high and low =======\n" << std::endl;
    try { Form TooHigh("Super Form", 0, 10); }
    catch (const std::exception& ex) { std::cerr << "Constructor High: " << ex.what() << std::endl; }
    try { Form TooLow("Intern Form", 10, 151); }
    catch (const std::exception& ex) { std::cerr << "Constructor Low: " << ex.what() << std::endl; }

    // --- beSigned / signForm y límites ---
    std::cout << "\n======== Sign behaviour =======\n" << std::endl;
    {
        Bureaucrat boss("Boss", 2);
        Form doc("Document", 1, 10);

        std::cout << "Before sign attempt: " << boss;
        boss.signForm(doc); // grado insuficiente (2 > 1) -> fallo
        boss.increment();   // ahora boss = 1
        std::cout << "After increment: " << boss;
        boss.signForm(doc); // ahora debe firmar
        std::cout << "Document state: " << doc << std::endl;
    }

    // --- beSigned con método directo y fallo esperado ---
    std::cout << "\n======== beSigned direct tests =======\n" << std::endl;
    {
        Bureaucrat low("Low", 100);
        Form secret("Secret", 50, 25);
        try {
            secret.beSigned(low); // debe lanzar
        } catch (const std::exception& e) {
            std::cout << "Sign failed as expected: " << e.what() << '\n';
            std::cout << "Still unsigned: " << secret << '\n';
        }
    }

    // --- Doble firma (idempotencia) ---
    std::cout << "\n======== Double sign =======\n" << std::endl;
    {
        Bureaucrat s("Signer", 10);
        Form once("Once", 50, 10);
        s.signForm(once);
        s.signForm(once); // no debe fallar, sigue firmado
        std::cout << "After double sign: " << once << '\n';
    }

    // --- Límites extremos para grades 1 y 150 ---
    std::cout << "\n======== Boundary grades =======\n" << std::endl;
    {
        Bureaucrat top("Top", 1);
        Bureaucrat bottom("Bottom", 150);
        Form needTop("NeedTop", 1, 1);
        Form needBot("NeedBot", 150, 150);
        top.signForm(needTop);     // ok
        bottom.signForm(needBot);  // ok (igual al requerido)
        std::cout << needTop << needBot << '\n';
    }

    // --- Copia y asignación de Form (estado signed debe copiarse) ---
    std::cout << "\n======== Form copy/assign =======\n" << std::endl;
    {
        Form a("A", 50, 10);
        Bureaucrat s("S", 30);
        s.signForm(a);    // a pasa a signed = true
        Form b(a);        // copia: signed == true
        Form c("C", 50, 10);
        c = a;            // operador= copia estado signed
        std::cout << "copy b: " << b << " assign c: " << c << '\n';
    }

    // --- Stress: subir/bajar hasta límites y capturar excepciones ---
    std::cout << "\n======== Increment/Decrement loops =======\n" << std::endl;
    {
        Bureaucrat up("Ascending boss", 5);
        while (1) {
            try { up.increment(); std::cout << up; }
            catch (const std::exception& e) { std::cerr << "Reached top: " << e.what() << std::endl; break; }
        }
    }
    {
        Bureaucrat down("Descending intern", 145);
        while (1) {
            try { down.decrement(); std::cout << down; }
            catch (const std::exception& e) { std::cerr << "Reached base: " << e.what() << std::endl; break; }
        }
    }

    return 0;
}