/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Guille <Guille@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/02 16:18:25 by Guille            #+#    #+#             */
/*   Updated: 2026/03/02 18:04:34 by Guille           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
#define AFORM_HPP

#include <iostream>
#include <string>

class Bureaucrat;

class AForm
{
	private:
		const std::string _name;
		bool 			 _isSigned;
		const int		_gradeToSign;
		const int		_gradeToExec;
	public:
		AForm(const std::string& name, int gradeToSign, int gradeToExec);
		AForm(const AForm& other);
		AForm& operator=(const AForm& other);
		virtual ~AForm();

		const std::string& getName(void) const;
		bool			   isSigned(void) const;
		int				   getGradeToSign(void) const;
		int				   getGradeToExec(void) const;
		void			   beSigned(const Bureaucrat& bu);
		void			   execute(const Bureaucrat& executor) const;
		virtual void	   executeAction(void) const = 0;
		
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
		class NotSignedException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
};

std::ostream& operator<<(std::ostream& os, const AForm& f);


#endif