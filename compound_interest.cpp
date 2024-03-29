#include "stdafx.h"
#include "compound_interest.h"

int main()
{
	bool repeat = true;
	std::string q_or_cont;

	while (repeat == true) {	//Continue running the program until the user enters 'q'
		Interest ci;

		ci.getP();		//Prompt user to enter starting amount
		ci.get_d();		//Prompt user to enter monthly deposit
		ci.get_r();		//Prompt user to enter interest rate
		ci.get_n();		//Prompt user to enter how often interest is compounded
		ci.get_t();		//Prompt the user to enter the time in years

		ci.print_money(ci.calc(ci.P, ci.d, ci.r, ci.n, ci.t));

		std::cout << "Press any key to do another calculation, or press 'q' to quit.\n";
		std::cin >> q_or_cont;
		if (q_or_cont == "q") {
			repeat = false;
		}
		std::cout << "\n\n\n***************\n\n\n";		//Make space between calculations to make it more readable
	}
	
    return 0;
}

