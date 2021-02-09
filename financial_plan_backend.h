#ifndef FINANCIAL_PLAN_BACKEND_H
#define FINANCIAL_PLAN_BACKEND_H

#include <vector>
#include <string>

class financial_plan
{
    protected:
        double initial_debt;
        double interest_rate;
        int total_time;
        std::vector < std::vector <double> > plan;
    public:
        financial_plan(double _initial_debt, double _interest_rate, int _ttime);
        virtual ~financial_plan();
        virtual void compute() = 0;
        std::string plan_as_string();
        void print_to_console();
    };

// konstante annuität
class constant_annuity : financial_plan {

};

// konstante tilgung
class constant_repayment : financial_plan {

};

class constant_interest : financial_plan {
    
};

#endif // FINANCIAL_PLAN_BACKEND_H
