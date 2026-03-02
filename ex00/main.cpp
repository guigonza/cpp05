/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Guille <Guille@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/02 12:52:52 by Guille            #+#    #+#             */
/*   Updated: 2026/03/02 16:36:36 by Guille           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main(void)
{
	std::cout << "======== Creation and printing whith operator =======\n" << std::endl;
	{
		Bureaucrat A("Alice", 42);
		std::cout << A;
	}
	std::cout << "\n======== Try/catch high and low =======\n" << std::endl;

	try
	{
		Bureaucrat TooHigh("Super Boss", 0);
		//try to create a bureaucraat and fails that`s why doesn`t prints next row
		std::cout << TooHigh << std::endl;
	}
	catch (const std::exception& ex)
	{
		std::cerr << "Constructor High: " << ex.what() << std::endl;
	}
		try
	{
		Bureaucrat TooLow("Intern", 151);
		//try to create a bureaucraat and fails that`s why doesn`t prints next row
		std::cout << TooLow << std::endl;
	}
	catch (const std::exception& ex)
	{
		std::cerr << "Constructor Low: " << ex.what() << std::endl;
	}
	std::cout << "\n======== Increment and decrement =======\n" << std::endl;
	Bureaucrat Boss("Boss", 2);
	std::cout << "Before increment: " << Boss;
	Boss.increment();
	std::cout << "After increment: " << Boss;
		Bureaucrat Intern("Intern", 149);
	std::cout << "Before decrement: " << Intern;
	Intern.decrement();
	std::cout << "After decrement: " << Intern;
	std::cout << "\n======== Copy and self assigment =======\n" << std::endl;
	Bureaucrat Original("original", 30);
	Bureaucrat Copy(Original);
	std::cout << "Original: " << Original << "copy: " << Copy << std::endl;
	Bureaucrat x("German", 20);
	Bureaucrat y ("Will", 130);
	std::cout << x;
	std::cout << y;
	x = y;
	std::cout << "after aasign y: " << x;
	Bureaucrat* p = &x;
	x = *p;
	std::cout << "after self assign x = x: " << x;
	std::cout << "\n======== Bucle and try/catch =======\n" << std::endl;
	{
		Bureaucrat b("Ascending boss", 5);
		while(1)
		{
			try
			{
				b.increment();
				std::cout << b;
			}
			catch (const std::exception& e)
			{
				std::cerr << "Reached top of pyramid: "	<< e.what() << std::endl;
				break ;
			}
		}
	}
	std::cout << "\n";
	{
		Bureaucrat i("Descending intern", 145);
		while(1)
		{
			try
			{
				i.decrement();
				std::cout << i;
			}
			catch (const std::exception& e)
			{
				std::cerr << "Reached base of pyramid: "	<< e.what() << std::endl;
				break ;
			}
		}
	}
	return (0);
}