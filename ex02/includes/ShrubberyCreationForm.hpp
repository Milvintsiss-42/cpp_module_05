/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-stra <ple-stra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 04:20:59 by ple-stra          #+#    #+#             */
/*   Updated: 2024/02/12 18:06:46 by ple-stra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <string>
#include <iostream>
#include "AForm.hpp"

class ShrubberyCreationForm : public AForm
{
private:
	std::string _target;
public:
	ShrubberyCreationForm();
	ShrubberyCreationForm(std::string target);
	ShrubberyCreationForm(ShrubberyCreationForm const & src);
	~ShrubberyCreationForm();

	std::string getTarget() const;

	void execute(Bureaucrat const &executor) const;
	ShrubberyCreationForm &operator=(ShrubberyCreationForm const &rhs);
};
