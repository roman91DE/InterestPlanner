#include "financial_plan_backend.h"
#include <iostream>

// Base Class Interface
financial_plan::financial_plan(double _initial_debt, double _interest_rate, int _total_time):
initial_debt(_initial_debt), interest_rate(_interest_rate), total_time(_total_time) {}

financial_plan::~financial_plan() {};

std::string financial_plan::plan_as_string() {
    std::string s = "Credit Sum: " + std::to_string(initial_debt) +
                    "; Runtime: " + std::to_string(total_time) + " periods" +
                    "; Interest Rate: " + std::to_string(interest_rate) + "%\n" +
    "t - Repayment  - Interest  -  Annuity  -  Remaining Debt\n";
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





int main() {
    financial_plan *f = new constant_repayment(1000, 10, 5);
    f->print_to_console();
    delete f;
    financial_plan *k = new constant_interest(100,10,5);
    k->print_to_console();
    delete k;

    return 0;
}