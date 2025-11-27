/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejhern <alejhern@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 12:49:05 by alejhern          #+#    #+#             */
/*   Updated: 2025/11/27 13:02:53 by alejhern         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include <iostream>
#include <cctype>

int main(int argc, char **argv)
{
    int i;
    int j;

    if (argc == 1)
    {
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
        return (0);
    }
    i = 0;
    while (argv[++i])
    {
        j = -1;
        std::string arg = argv[i];
        while (arg[++j])
            arg[j] = std::toupper(arg[j]);
        std::cout << arg << std::endl;
    }
    return (0);
}
