/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Guille <Guille@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/02 16:18:25 by Guille            #+#    #+#             */
/*   Updated: 2026/03/02 17:33:01 by Guille           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include <string>

class Bureaucrat;

class Form
{
	private:
		const std::string _name;
		bool 			 _isSigned;
		const int		_gradeToSign;
		const int		_gradeToExec;
	public:
		Form(const std::string& name, int gradeToSign, int gradeToExec);
		Form(const Form& other);
		Form& operator=(const Form& other);
		~Form();

		const std::string& getName(void) const;
		bool			   isSigned(void) const;
		int				   getGradeToSign(void) const;
		int				   getGradeToExec(void) const;
		void			   beSigned(const Bureaucrat& bu);
		
		class GradeTooHighException : public std::exception 
		{
			public:
				virtual const char* what() const throw();
		};
		class GradeTooLowException : public std::exception 
		{
			public:
				virtual const char* what() const throw();
		};
};

std::ostream& operator<<(std::ostream& os, const Form& f);


#endif