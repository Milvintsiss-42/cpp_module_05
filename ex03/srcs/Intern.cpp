/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-stra <ple-stra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 19:35:23 by ple-stra          #+#    #+#             */
/*   Updated: 2024/02/14 18:13:49 by ple-stra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

Intern::Intern()
{
}

Intern::Intern(Intern const &src)
{
	*this = src;
}

Intern::~Intern()
{
}

AForm *Intern::makeForm(std::string formName, std::string formTarget) const
{
	const int formsCount = 3;
	std::string formNames[formsCount] = {
		"shrubbery creation",
		"robotomy request",
		"presidential pardon"
	};
	FormMaker formMakers[formsCount] = {
		ShrubberyCreationForm::make,
		RobotomyRequestForm::make,
		PresidentialPardonForm::make
	};

	for (int i = 0; i < formsCount; i++)
	{
		if (formNames[i] == formName)
		{
			std::cout << "Intern creates " << formName << "." << std::endl;
			return formMakers[i](formTarget);
		}
	}
	std::cout << "Intern didn't found the " << formName << " form."
		<< std::endl;
	return 0;
}

Intern &Intern::operator=(Intern const &rhs)
{
	(void)rhs;
	return *this;
}
