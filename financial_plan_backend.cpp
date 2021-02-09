#include "financial_plan_backend.h"
#include <iostream>

financial_plan::financial_plan(double _initial_debt, double _interest_rate, int _total_time):
initial_debt(_initial_debt), interest_rate(_interest_rate), total_time(_total_time) {
    compute();
}


financial_plan::~financial_plan() {};


std::string financial_plan::plan_as_string() {
    std::string s = "Year - Repayment - Interest - Annuity - Remaining Debt\n";
    for (int i = 0; i <total_time; i++) {
        s += ( std::to_string(i)                            // cur_year i
              + " - " + std::to_string(plan[i][0])          // repay    [0]
              + " - " + std::to_string(plan[i][1])          // interest [1]
              + " - " + std::to_string(plan[i][2])          // annuity  [2]
              + " - " + std::to_string(plan[i][3]) + "\n"   // remaider [3]
              );
    }
    return s;
}

void financial_plan::print_to_console() {
    std::cout << "Financial Plan:\n" << plan_as_string();
}