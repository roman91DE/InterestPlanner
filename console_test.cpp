#include "financial_plan_backend.cpp"
#include <memory>

int main() {
  std::unique_ptr<financial_plan> f =
      std::make_unique<constant_repayment>(1000, 10, 5);
  f->print_to_console();

  std::unique_ptr<financial_plan> k =
      std::make_unique<constant_interest>(1000, 10, 5);
  k->print_to_console();

  std::unique_ptr<financial_plan> a =
      std::make_unique<constant_annuity>(1000, 10, 5);
  a->print_to_console();

  return 0;
}