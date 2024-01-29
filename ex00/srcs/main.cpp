/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-stra <ple-stra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 17:36:12 by ple-stra          #+#    #+#             */
/*   Updated: 2024/01/29 21:01:57 by ple-stra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

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

	// This will throw an exception that will not be catched,
	// so the program will crash.
	Bureaucrat("Kennedy", 151);
	return (0);
}