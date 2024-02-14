/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-stra <ple-stra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 04:20:59 by ple-stra          #+#    #+#             */
/*   Updated: 2024/02/13 22:49:28 by ple-stra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <string>
#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
private:
	const std::string _name;
	bool _is_signed;
	const int _req_sign_grade;
	const int _req_exec_grade;
public:
	AForm();
	AForm(std::string name, int req_sign_grade, int req_exec_grade);
	AForm(AForm const & src);
	virtual ~AForm();

	std::string getName() const;
	bool isSigned() const;
	int getRequiredSignGrade() const;
	int getRequiredExecutionGrade() const;

	void beSigned(Bureaucrat &bureaucrat);
	void verifyExecutionConditions(Bureaucrat const &executor) const;
	virtual void execute(Bureaucrat const &executor) const = 0;
	AForm &operator=(AForm const &rhs);

	class GradeTooHighException : public std::exception {
	public:
		virtual const char *what() const throw()
		{
			return ("AForm::GradeTooHigh");
		}
	};
	class GradeTooLowException : public std::exception {
	public:
		virtual const char *what() const throw()
		{
			return ("AForm::GradeTooLow");
		}
	};
	class NotSignedYetException : public std::exception {
	public:
		virtual const char *what() const throw()
		{
			return ("AForm::NotSignedYet");
		}
	};
};

std::ostream &operator<<(std::ostream &o, AForm const &rhs);
