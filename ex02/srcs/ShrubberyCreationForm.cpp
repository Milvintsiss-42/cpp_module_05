/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-stra <ple-stra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 14:46:17 by ple-stra          #+#    #+#             */
/*   Updated: 2024/02/12 19:05:10 by ple-stra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fstream>
#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm()
	: AForm("ShrubberyCreationForm", 145, 137),
	_target("default")
{
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target)
	: AForm("ShrubberyCreationForm", 145, 137),
	_target(target)
{
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const & src)
	: AForm(src.getName(), src.getRequiredSignGrade(),
		src.getRequiredExecutionGrade()),
	_target(src.getTarget())
{
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
}

std::string ShrubberyCreationForm::getTarget() const
{
	return this->_target;
}

void ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
	this->AForm::verifyExecutionConditions(executor);
	std::string filename = this->getTarget() + "_shrubbery";
	std::ofstream fileStream(filename.c_str());
	if (!fileStream)
		return ;
	fileStream <<
"          &&& &&  & &&" << std::endl <<
"      && &\\/&\\|& ()|/ @, &&" << std::endl <<
"      &\\/(/&/&||/& /_/)_&/_&" << std::endl <<
"   &() &\\/&|()|/&\\/ '%\" & ()" << std::endl <<
"  &_\\_&&_\\ |& |&&/&__%_/_& &&" << std::endl <<
"&&   && & &| &| /& & % ()& /&&" << std::endl <<
" ()&_---()&\\&\\|&&-&&--%---()~" << std::endl <<
"     &&     \\|||" << std::endl <<
"             |||" << std::endl <<
"             |||" << std::endl <<
"             |||" << std::endl <<
"       , -=-~  .-^- _" << std::endl;
	fileStream.close();
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(ShrubberyCreationForm const &rhs)
{
	this->_target = rhs.getTarget();
	return *this;
}
