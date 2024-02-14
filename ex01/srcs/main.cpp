/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-stra <ple-stra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 17:36:12 by ple-stra          #+#    #+#             */
/*   Updated: 2024/02/14 18:18:54 by ple-stra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int	main(void)
{
	std::cout << "Ex00" << std::endl;
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

	std::cout << std::endl << "Ex01" << std::endl;
	Form a38 = Form("A38", 1, 3);
	try
	{
		Form("404", 152, 1);
	}
	catch (Form::GradeTooLowException &e)
	{
		std::cout << "Exception 4: " << e.what() << std::endl;
	}
	try
	{
		Form("418", 1, 0);
	}
	catch (Form::GradeTooHighException &e)
	{
		std::cout << "Exception 5: " << e.what() << std::endl;
	}
	std::cout << a38 << std::endl;
	lancebas.signForm(a38);
	std::cout << a38 << std::endl;
	lancelot.signForm(a38);
	std::cout << a38 << std::endl;
	return (0);
}
