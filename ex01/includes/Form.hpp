/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-stra <ple-stra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 04:20:59 by ple-stra          #+#    #+#             */
/*   Updated: 2024/02/12 14:23:37 by ple-stra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <string>
#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
private:
	const std::string _name;
	bool _is_signed;
	const int _req_sign_grade;
	const int _req_exec_grade;
public:
	Form();
	Form(std::string name, int req_sign_grade, int req_exec_grade);
	Form(Form const & src);
	~Form();

	std::string getName() const;
	bool isSigned() const;
	int getRequiredSignGrade() const;
	int getRequiredExecutionGrade() const;

	void beSigned(Bureaucrat &bureaucrat);
	Form &operator=(Form const &rhs);

	class GradeTooHighException : public std::exception {
	public:
		virtual const char *what() const throw()
		{
			return ("Form::GradeTooHigh");
		}
	};
	class GradeTooLowException : public std::exception {
	public:
		virtual const char *what() const throw()
		{
			return ("Form::GradeTooLow");
		}
	};
};

std::ostream &operator<<(std::ostream &o, Form const &rhs);
