/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-stra <ple-stra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 14:46:17 by ple-stra          #+#    #+#             */
/*   Updated: 2024/02/12 18:55:44 by ple-stra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm() : _name("default"), _is_signed(false), _req_sign_grade(150), _req_exec_grade(150)
{
}

AForm::AForm(std::string name, int req_sign_grade, int req_exec_grade)
	: _name(name),
	 _is_signed(false),
	_req_sign_grade(req_sign_grade),
	_req_exec_grade(req_exec_grade)
{
	if (_req_sign_grade < 1 || _req_exec_grade < 1)
		throw AForm::GradeTooHighException();
	else if (_req_sign_grade > 150 || _req_exec_grade > 150)
		throw AForm::GradeTooLowException();
	std::cout << this->_name << " form as been initiated with a sign grade of "
		<< this->_req_sign_grade << " and an exec grade of "
		<< this->_req_exec_grade << "." << std::endl;
}

AForm::AForm(AForm const & src)
	: _name(src.getName()),
	_is_signed(src.isSigned()),
	_req_sign_grade(src.getRequiredSignGrade()),
	_req_exec_grade(src.getRequiredExecutionGrade())
{
	std::cout << this->_name << " form as been initiated with a sign grade of "
		<< this->_req_sign_grade << " and an exec grade of "
		<< this->_req_exec_grade << "." << std::endl;
}

AForm::~AForm()
{
}

std::string AForm::getName() const
{
	return this->_name;
}

bool AForm::isSigned() const
{
	return this->_is_signed;
}

int AForm::getRequiredSignGrade() const
{
	return this->_req_sign_grade;
}

int AForm::getRequiredExecutionGrade() const
{
	return this->_req_exec_grade;
}

void AForm::beSigned(Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() > this->getRequiredSignGrade())
		throw AForm::GradeTooLowException();
	this->_is_signed = true;
}

void AForm::verifyExecutionConditions(Bureaucrat const &executor) const
{
	if (!this->isSigned())
		throw AForm::NotSignedYetException();
	if (executor.getGrade() > this->getRequiredExecutionGrade())
		throw AForm::GradeTooLowException();
}

AForm &AForm::operator=(AForm const &rhs)
{
	this->_is_signed = rhs.isSigned();
	return *this;
}

std::ostream &operator<<(std::ostream &o, AForm const &rhs)
{
	o << rhs.getName() << ", Form require a sign grade of "
		<< rhs.getRequiredSignGrade() << " and an exec grade of "
		<< rhs.getRequiredExecutionGrade() << ". State: "
		<< (rhs.isSigned() ? "signed" : "unsigned") << ".";
	return o;
}
