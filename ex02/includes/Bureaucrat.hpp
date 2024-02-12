/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-stra <ple-stra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 04:20:59 by ple-stra          #+#    #+#             */
/*   Updated: 2024/02/12 18:45:59 by ple-stra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <string>
#include <iostream>
#include "AForm.hpp"

class AForm;

class Bureaucrat
{
private:
	const std::string _name;
	int _grade;
public:
	Bureaucrat();
	Bureaucrat(std::string name, int grade);
	Bureaucrat(Bureaucrat const & src);
	~Bureaucrat();

	std::string getName() const;
	int getGrade() const;

	void incrementGrade();
	void decrementGrade();
	void signForm(AForm &form);
	void executeForm(AForm const &form);

	Bureaucrat &operator=(Bureaucrat const &rhs);

	class GradeTooHighException : public std::exception {
	public:
		virtual const char *what() const throw()
		{
			return ("Bureaucrat::GradeTooHigh");
		}
	};
	class GradeTooLowException : public std::exception {
	public:
		virtual const char *what() const throw()
		{
			return ("Bureaucrat::GradeTooLow");
		}
	};
};

std::ostream &operator<<(std::ostream &o, Bureaucrat const &rhs);
