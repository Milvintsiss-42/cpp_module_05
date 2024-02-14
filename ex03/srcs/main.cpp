/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-stra <ple-stra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 17:36:12 by ple-stra          #+#    #+#             */
/*   Updated: 2024/02/14 18:13:55 by ple-stra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int	main(void)
{
	Bureaucrat lancelot = Bureaucrat("Lancelot", 1);
	Bureaucrat lancebas = Bureaucrat("Lancebas", 149);
	try
	{
		Bureaucrat("George", 152);
	}
	catch (std::exception &e)
	{
		std::cout << "Exception 1: " << e.what() << std::endl;
	}
	try
	{
		std::cout << lancebas << std::endl;
		lancebas.decrementGrade();
		std::cout << lancebas << std::endl;
		lancebas.decrementGrade();
	}
	catch (Bureaucrat::GradeTooHighException &e)
	{
		std::cout << "This will not be thrown.";
	}
	catch (Bureaucrat::GradeTooLowException &e)
	{
		std::cout << "Exception 2: " << e.what() << std::endl;
	}
	std::cout << lancebas << std::endl;
	try
	{
		std::cout << lancelot << std::endl;
		lancelot.incrementGrade();
		std::cout << lancelot << std::endl;
		lancelot.incrementGrade();
	}
	catch (Bureaucrat::GradeTooLowException &e)
	{
		std::cout << "This will not be thrown.";
	}
	catch (Bureaucrat::GradeTooHighException &e)
	{
		std::cout << "Exception 3: " << e.what() << std::endl;
	}
	std::cout << lancelot << std::endl;

	Bureaucrat treeman("Treeman", 130);
	ShrubberyCreationForm treeForm("42");
	std::cout << treeForm << std::endl;
	lancebas.signForm(treeForm);
	lancebas.executeForm(treeForm);
	std::cout << treeForm << std::endl;
	lancelot.signForm(treeForm);
	std::cout << treeForm << std::endl;
	lancebas.executeForm(treeForm);
	treeman.executeForm(treeForm);

	RobotomyRequestForm robotomyForm("Bob");
	lancelot.signForm(robotomyForm);
	lancelot.executeForm(robotomyForm);

	PresidentialPardonForm pardonForm("Gollum");
	lancelot.signForm(pardonForm);
	lancelot.executeForm(pardonForm);

	Intern someRandomIntern;
	AForm *rrf;

	rrf = someRandomIntern.makeForm("robotomy request", "Bender");
	lancelot.signForm(*rrf);
	lancelot.executeForm(*rrf);
	delete rrf;
	someRandomIntern.makeForm("a38", "Obelix");
	return (0);
}
