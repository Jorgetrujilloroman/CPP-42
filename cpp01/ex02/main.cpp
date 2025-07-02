/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotrujil <jotrujil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 13:09:47 by jotrujil          #+#    #+#             */
/*   Updated: 2025/07/02 13:19:24 by jotrujil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>

int	main(){
	std::string stringVAR = "HI THIS IS BRAIN";
	std::string *stringPTR = &stringVAR;
	std::string &stringREF = stringVAR;

	std::cout << "StringVAR address: " << &stringVAR << std::endl;
	std::cout << "StringPTR address: " << stringPTR << std::endl;
	std::cout << "StringREF address: " << &stringREF << std::endl;
	std::cout << std::endl;
	std::cout << "StringVAR value: " << stringVAR << std::endl;
	std::cout << "StringPTR value: " << *stringPTR << std::endl;
	std::cout << "StringREF value: " << stringREF << std::endl;
	
	return (0);
}