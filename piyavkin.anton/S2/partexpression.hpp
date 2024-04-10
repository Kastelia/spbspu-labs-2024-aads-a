#ifndef PARTEXPRESSION_HPP
#define PARTEXPRESSION_HPP

namespace piyavkin
{
  namespace detail
  {
    struct Operand
    {
      Operand();
      Operand(unsigned long long val);
      unsigned long long number;
    };
    struct Operation
    {
      Operation();
      Operation(char val);
      bool operator>(const Operation& rhs);
      char operation;
    };
    struct Bracket
    {
      Bracket();
      Bracket(char val);
      char bracket;
    };
    enum TypesPartsExpression
    {
      operand = 0,
      operation = 1,
      bracket = 2
    };
  }
}
#endif
