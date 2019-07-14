#include "stdafx.h"
#include "compound_interest.h"

void Interest::getP() {
	bool valid = false;
	std::cout << "Enter the starting amount: ";

	while (valid == false) {				//Keep prompting until user enters valid entry
		std::cin >> P_str;					//Take input as a string so we can do regex check, to avoid crash

		if (valid_number(P_str, 1, 1)) {
			valid = true;
			P = std::stod(P_str);			//Convert input to a double now that you know it won't cause crash
		}
		else {
			std::cout << "Must be a number greater than zero, without the $ sign. Ex: 1025.75\n";
		}
	}
}

void Interest::get_d() {
	bool valid = false;

	std::cout << "Enter the amount of monthly deposit. (If there is none, enter 0): ";

	while (valid == false) {			//Keep prompting until user enters valid entry
		std::cin >> d_str;				//Take input as a string so we can do regex check, to avoid crash

		if (valid_number(d_str)) {
			valid = true;
			d = std::stod(d_str);		//Convert input to a double now that you know it won't cause crash
		}
		else {
			std::cout << "Invalid entry. Must be a number without the $ sign. If amount is 0, just enter 0.\n";
		}
	}
}

void Interest::get_r() {
	bool valid = false;

	std::cout << "Enter the interest rate, without the percent sign. (e.g. if it is 5 percent, just enter 5)\n";
	
	while (valid == false) {			//Keep prompting until user enters valid entry
		std::cin >> r_str;				//Take input as a string so we can do regex check, to avoid crash
		
		if (valid_number(r_str, 1, 1)) {
			valid = true;
			r = std::stod(r_str);		//Convert input to a double now that you know it won't cause crash
			r = r / 100;				//Interest rate is a percentage, so divide it by 100
		}
		else {
			std::cout << "Invalid entry. Remember, don't include the percent sign. (e.g. if it is 5 percent, just enter 5)\n";
		}
	}	
}

void Interest::get_n() {
	bool valid = false;

	std::regex valid_input("[a-dA-D]{1}");
	
	std::string selection = "";
	std::string selection_caps = "";
	std::cout << "Select how often interest is compounded:\n";
	std::cout << "A: Annualy\n";
	std::cout << "B: Semi-annualy\n";
	std::cout << "C: Quarterly\n";
	std::cout << "D: Monthly\n";

	while (valid == false) {								//Keep prompting until user enters A, B, C, or D
		std::cin >> selection;
		selection_caps = toupper(selection[0]);				//Make input uppercase if it isn't already
		if (regex_match(selection_caps, valid_input)) {		//Check that the input is A, B, C, or D
			valid = true;
		}
		else {
			std::cout << "Invalid entry.\n";
		}

	}
	
	if (selection_caps == "A") {
		n = 1;								//n=1, meaning interest is compounded 1 time a year
	}
	else if (selection_caps == "B") {
		n = 2;								//n=2, meaning interest is compounded 2 times a year
	}
	else if (selection_caps == "C") {
		n = 4;								//n=4, meaning interest is compounded 4 times a year
	}
	else if (selection_caps == "D") {
		n = 12;								//n=12, meaning interest is compounded 12 times a year
	}
}

void Interest::get_t() {
	bool valid = false;

	std::cout << "Enter the time, in years. (Ex. for 3 and a half years, enter 3.5, for 5 years just enter 5.\n";

	while (valid == false) {					//Keep prompting until user enters valid entry
		std::cin >> t_str;						//Take input as a string so we can do regex check, to avoid crash

		if (valid_number(t_str, 1, 1)) {
			valid = true;
			t = std::stod(t_str);				//Convert input to a double now that you know it won't cause crash
		}
		else {
			std::cout << "Invalid entry. Try again.\n";
		}
	}
}

bool Interest::valid_number(std::string input, int pos, int non_zero) {

	std::regex valid_input("[\\d]+[\\.]*[\\d]*");		//Regex for a number with a decimal point
	if (regex_match(input, valid_input) == false) {
		return false;								//Make sure input is a double and not something else
	}

	if (pos == 1) {									//Optional check to see if number is positive
		double p = std::stod(input);				//Convert the input back to a double
		if (p < 0) {								//Check if the input is negative
			return false;
		}
	}

	if (non_zero == 1) {							//Optional check to see if number is non zero
		double z = std::stod(input);				//Convert the input back to a double			
		if (z == 0) {								//Check if the input is zero
			return false;
		}
	}

	return true;									//If it passes the above tests, it is valid
}

double Interest::calc(double P, double d, double r, double n, double t) {
	double base = (1 + r / n);
	double exponent = (n*t);
	return (P + d*(n*t))*pow(base, exponent);
}

void Interest::print_money(double amount) {
	std::cout << std::fixed;
	std::cout << "$" << std::setprecision(2) << amount << "\n";	  //Print dollar amount, so round to 2 decimal places
}