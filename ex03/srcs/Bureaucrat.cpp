/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-stra <ple-stra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 04:37:40 by ple-stra          #+#    #+#             */
/*   Updated: 2024/02/12 19:01:50 by ple-stra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("default"), _grade(150)
{
}

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name)
{
	this->_grade = 150;
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	this->_grade = grade;
	std::cout << this->_name << " bureaucrat as been initiated with a grade of "
		<< this->_grade << "." << std::endl;
}

Bureaucrat::Bureaucrat(Bureaucrat const & src) : _name(src.getName())
{
	*this = src;
	std::cout << this->_name << " bureaucrat as been initiated with a grade of "
		<< this->_grade << "." << std::endl;
}

Bureaucrat::~Bureaucrat()
{
}

std::string Bureaucrat::getName() const
{
	return this->_name;
}

int Bureaucrat::getGrade() const
{
	return this->_grade;
}

void Bureaucrat::incrementGrade()
{
	if (this->_grade == 1)
		throw Bureaucrat::GradeTooHighException();
	std::cout << this->_name << " grade as been incremented." << std::endl;
	this->_grade--;
}

void Bureaucrat::decrementGrade()
{
	if (this->_grade == 150)
		throw Bureaucrat::GradeTooLowException();
	std::cout << this->_name << " grade as been decremented." << std::endl;
	this->_grade++;
}

void Bureaucrat::signForm(AForm &form)
{
	try
	{
		form.beSigned(*this);
		std::cout << this->getName() << " signed " << form.getName() << "."
			<< std::endl;
	}
	catch (AForm::GradeTooLowException &e)
	{
		std::cout << this->getName() << " couldn't sign " << form.getName()
			<< " because signatory grade is too low." << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "Unexpected error: " << e.what() << std::endl;
	}
}

void Bureaucrat::executeForm(AForm const &form)
{
	try
	{
		form.execute(*this);
		std::cout << this->getName() << " executed " << form.getName() << "."
			<< std::endl;
	}
	catch (AForm::NotSignedYetException &e)
	{
		std::cout << this->getName() << " couldn't execute " << form.getName()
			<< " because the form is not signed." << std::endl;
	}
	catch (AForm::GradeTooLowException &e)
	{
		std::cout << this->getName() << " couldn't execute " << form.getName()
			<< " because executor grade is too low." << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "Unexpected error: " << e.what() << std::endl;
	}
}

Bureaucrat &Bureaucrat::operator=(Bureaucrat const &rhs)
{
	this->_grade = rhs.getGrade();
	return *this;
}

std::ostream &operator<<(std::ostream &o, Bureaucrat const &rhs)
{
	o << rhs.getName() << ", bureaucrat grade " << rhs.getGrade() << ".";
	return o;
}
