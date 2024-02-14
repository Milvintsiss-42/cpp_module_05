/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-stra <ple-stra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 14:46:17 by ple-stra          #+#    #+#             */
/*   Updated: 2024/02/13 22:52:29 by ple-stra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm()
	: AForm("PresidentialPardonForm", 25, 5),
	_target("default")
{
}

PresidentialPardonForm::PresidentialPardonForm(std::string target)
	: AForm("PresidentialPardonForm", 25, 5),
	_target(target)
{
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const & src)
	: AForm(src.getName(), src.getRequiredSignGrade(),
		src.getRequiredExecutionGrade()),
	_target(src.getTarget())
{
}

PresidentialPardonForm::~PresidentialPardonForm()
{
}

AForm *PresidentialPardonForm::make(std::string target)
{
	return new PresidentialPardonForm(target);
}

std::string PresidentialPardonForm::getTarget() const
{
	return this->_target;
}

void PresidentialPardonForm::execute(Bureaucrat const &executor) const
{
	this->AForm::verifyExecutionConditions(executor);
	std::cout << this->getTarget() << " has been pardoned by Zaphod Beeblebrox."
		<< std::endl;
}

PresidentialPardonForm &PresidentialPardonForm::operator=(PresidentialPardonForm const &rhs)
{
	this->_target = rhs.getTarget();
	return *this;
}
