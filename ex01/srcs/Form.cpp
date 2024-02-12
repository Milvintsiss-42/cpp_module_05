/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-stra <ple-stra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 21:21:29 by ple-stra          #+#    #+#             */
/*   Updated: 2024/02/12 14:05:24 by ple-stra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form() : _name("default"), _is_signed(false), _req_sign_grade(150), _req_exec_grade(150)
{
}

Form::Form(std::string name, int req_sign_grade, int req_exec_grade)
	: _name(name),
	 _is_signed(false),
	_req_sign_grade(req_sign_grade),
	_req_exec_grade(req_exec_grade)
{
	if (_req_sign_grade < 1 || _req_exec_grade < 1)
		throw Form::GradeTooHighException();
	else if (_req_sign_grade > 150 || _req_exec_grade > 150)
		throw Form::GradeTooLowException();
	std::cout << this->_name << " form as been initiated with a sign grade of "
		<< this->_req_sign_grade << " and an exec grade of "
		<< this->_req_exec_grade << "." << std::endl;
}

Form::Form(Form const & src)
	: _name(src.getName()),
	_is_signed(src.isSigned()),
	_req_sign_grade(src.getRequiredSignGrade()),
	_req_exec_grade(src.getRequiredExecutionGrade())
{
	std::cout << this->_name << " form as been initiated with a sign grade of "
		<< this->_req_sign_grade << " and an exec grade of "
		<< this->_req_exec_grade << "." << std::endl;
}

Form::~Form()
{
}

std::string Form::getName() const
{
	return this->_name;
}

bool Form::isSigned() const
{
	return this->_is_signed;
}

int Form::getRequiredSignGrade() const
{
	return this->_req_sign_grade;
}

int Form::getRequiredExecutionGrade() const
{
	return this->_req_exec_grade;
}

void Form::beSigned(Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() > this->getRequiredSignGrade())
		throw Form::GradeTooLowException();
	this->_is_signed = true;
}

Form &Form::operator=(Form const &rhs)
{
	this->_is_signed = rhs.isSigned();
	return *this;
}

std::ostream &operator<<(std::ostream &o, Form const &rhs)
{
	o << rhs.getName() << ", Form require a sign grade of "
		<< rhs.getRequiredSignGrade() << " and an exec grade of "
		<< rhs.getRequiredExecutionGrade() << ". State: "
		<< (rhs.isSigned() ? "signed" : "unsigned");
	return o;
}
