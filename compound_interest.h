#pragma once
#include "stdafx.h"
#include <iostream>
#include <math.h>
#include <iomanip>
#include <string>
#include <regex>



struct Interest
{
	double P;	//Starting amount
	std::string P_str;
	double d;	//Monthly deposit
	std::string d_str;
	double r;	//Interest rate
	std::string r_str;
	double n;	//Number of times compounded per year
	std::string n_str;
	double t;	//Time in years
	std::string t_str;

	void getP();
	void get_d();
	void get_r();
	void get_n();
	void get_t();
	bool valid_number(std::string input, int pos = 0, int non_zero = 0);
	double calc(double P, double d, double r, double n, double t);
	void print_money(double amount);
};

