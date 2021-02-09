#ifndef FINANCIAL_PLAN_BACKEND_H
#define FINANCIAL_PLAN_BACKEND_H

#include <vector>
#include <string>

class financial_plan {
    public:
        double initial_debt;
        double interest_rate;
        int total_time;
        std::vector < std::vector <double> > plan;
    public:
        financial_plan(double _initial_debt, double _interest_rate, int _total_time);
        virtual ~financial_plan();
        virtual void compute() = 0;
        std::string plan_as_string();
        void print_to_console();
        static double calculate_interest(double rate, double debt);
    };

// konstante tilgung
class constant_repayment : public financial_plan {
        public:
            constant_repayment(double _initial_debt, double _interest_rate, int _total_time);
            ~constant_repayment();
            void compute();
};


// konstante annuität
class constant_annuity : public financial_plan {
    public:
        constant_annuity(double _initial_debt, double _interest_rate, int _total_time);
        ~constant_annuity();
        void compute();
        double get_annuity();
};


class constant_interest : public financial_plan {
    public:
        constant_interest(double _initial_debt, double _interest_rate, int _total_time);
        ~constant_interest();
        void compute();
};



#endif // FINANCIAL_PLAN_BACKEND_H
