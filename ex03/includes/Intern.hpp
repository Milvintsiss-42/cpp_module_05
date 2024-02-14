/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-stra <ple-stra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 19:35:10 by ple-stra          #+#    #+#             */
/*   Updated: 2024/02/14 17:46:18 by ple-stra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include <iostream>
#include "AForm.hpp"

class AForm;

class Intern
{
public:
	Intern();
	Intern(Intern const &src);
	~Intern();

	AForm *makeForm(std::string formName, std::string formTarget) const;

	Intern &operator=(Intern const &rhs);
};

typedef AForm *(*FormMaker)(std::string);
