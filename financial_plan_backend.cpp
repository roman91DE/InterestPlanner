#include "financial_plan_backend.h"
#include <iostream>
#include <cmath>

// Base Class Interface
financial_plan::financial_plan(double _initial_debt, double _interest_rate, int _total_time):
initial_debt(_initial_debt), interest_rate(_interest_rate), total_time(_total_time) {}

financial_plan::~financial_plan() {};

std::string financial_plan::plan_as_string() {
    std::string s = "Credit Sum: " + std::to_string(initial_debt) +
                    "; Runtime: " + std::to_string(total_time) + " periods" +
                    "; Interest Rate: " + std::to_string(interest_rate) + "%\n" +
    "t - Repayment - Interest - Annuity - Remaining Debt\n";
    for (unsigned int i = 0; i <total_time; i++) {
        s += (          std::to_string(int(plan[i][0]))     // cur_year [0]
              + " - " + std::to_string(plan[i][1])          // repay    [1]
              + " - " + std::to_string(plan[i][2])          // interest [2]
              + " - " + std::to_string(plan[i][3])          // annuity  [3]
              + " - " + std::to_string(plan[i][4]) + "\n"   // remaider [4]
              );
    }
    return s;
}

void financial_plan::print_to_console() {
    std::cout << "Financial Plan:\n" << plan_as_string();
}

double financial_plan::calculate_interest(double rate, double debt) {
    return (rate*debt/100);
}

std::vector < std::vector<double> > financial_plan::get_matrix() {
    return plan;
}


// konstante tilgung
constant_repayment::constant_repayment(double _initial_debt, double _interest_rate, int _total_time) :
financial_plan(_initial_debt, _interest_rate, _total_time) {
    compute();
}



constant_repayment::~constant_repayment() {};

void constant_repayment::compute() {
    double repay_rate = initial_debt / double(total_time);
    double remainder = initial_debt;
    for (unsigned int i = 0; i < total_time; i++) {
        std::vector<double> cur_year;
        plan.push_back(cur_year);
        plan[i].push_back(float(i)+1);
        plan[i].push_back(repay_rate);
        plan[i].push_back(financial_plan::calculate_interest(interest_rate, remainder));
        plan[i].push_back(plan[i][1] + plan[i][2]);
        remainder -= repay_rate;
        plan[i].push_back(remainder);
    }
}


// konstante annuität
constant_annuity::constant_annuity(double _initial_debt, double _interest_rate, int _total_time) :
financial_plan(_initial_debt, _interest_rate, _total_time) {
    compute();
 }

constant_annuity::~constant_annuity() {};

double constant_annuity::get_annuity() {
    double z = (interest_rate/100) * std::pow((1+(interest_rate/100)), (total_time));
    double n = std::pow((1+(interest_rate/100)), (total_time)) - 1;
    return (initial_debt * (z/n));
}

void constant_annuity::compute() {
    double annuity = get_annuity();
    double remainder = initial_debt;
    for (unsigned int i = 0; i < total_time; i++) {
        double interest = remainder * (interest_rate/100);
        double repay = annuity - interest;
        remainder = remainder - repay;
        std::vector<double> cur_year;
        plan.push_back(cur_year);
        plan[i].push_back(float(i)+1);
        plan[i].push_back(repay);
        plan[i].push_back(interest);
        plan[i].push_back(annuity);
        plan[i].push_back(remainder);
    }
}





// konstante tilgung
constant_interest::constant_interest(double _initial_debt, double _interest_rate, int _total_time) :
financial_plan(_initial_debt, _interest_rate, _total_time) {
    compute();
}

constant_interest::~constant_interest() {};

void constant_interest::compute() {
    double interest = financial_plan::calculate_interest(interest_rate, initial_debt);
    for (unsigned int i = 0; i < total_time; i++) {
        std::vector<double> cur_year;
        plan.push_back(cur_year);
        plan[i].push_back(float(i)+1);
        if (i < total_time-1)
            plan[i].push_back(0.0);
        else 
            plan[i].push_back(initial_debt);
        plan[i].push_back(interest);
        plan[i].push_back(plan[i][1] + plan[i][2]);
        plan[i].push_back(initial_debt-(plan[i][1]));
    }
}

