/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-stra <ple-stra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 14:46:17 by ple-stra          #+#    #+#             */
/*   Updated: 2024/02/12 19:22:15 by ple-stra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm()
	: AForm("RobotomyRequestForm", 72, 45),
	_target("default")
{
}

RobotomyRequestForm::RobotomyRequestForm(std::string target)
	: AForm("RobotomyRequestForm", 72, 45),
	_target(target)
{
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const & src)
	: AForm(src.getName(), src.getRequiredSignGrade(),
		src.getRequiredExecutionGrade()),
	_target(src.getTarget())
{
}

RobotomyRequestForm::~RobotomyRequestForm()
{
}

std::string RobotomyRequestForm::getTarget() const
{
	return this->_target;
}

void RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
	this->AForm::verifyExecutionConditions(executor);
	std::cout << "brrr brrr..." << std::endl;
	srand((unsigned)time(NULL));
	if (rand() % 2)
		std::cout << this->getTarget() << " has been robotomized." << std::endl;
	else
		std::cout << "Failed to robotomize " << this->getTarget() << "."
			<< std::endl;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(RobotomyRequestForm const &rhs)
{
	this->_target = rhs.getTarget();
	return *this;
}
