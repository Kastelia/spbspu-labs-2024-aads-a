#include "input_list.hpp"
#include <istream>
#include <string>
#include <list.hpp>
#include "queue.hpp"
#include "expression_type.hpp"

void inputExpressionType(nikitov::ExpressionType& type, std::string& line)
{
  if (std::isdigit(line[0]))
  {
    type.value.num = std::stoi(line);
    type.storedType = 1;
  }
  else
  {
    type.value.symb = line[0];
    type.storedType = 2;
  }
  line = {};
}

void nikitov::inputList(List< Queue< ExpressionType > >& expressionList, std::istream& input)
{
  input >> std::noskipws >> std::fixed;
  while (input)
  {
    Queue< ExpressionType > expression;
    std::string line = {};
    char symb = {};
    while (input >> symb)
    {
      ExpressionType type;
      if (symb == ' ')
      {
        inputExpressionType(type, line);
        expression.push(type);
      }
      else if (symb == '\n')
      {
        if (!line.empty())
        {
          inputExpressionType(type, line);
          expression.push(type);
          expressionList.push_front(expression);
        }
        break;
      }
      else
      {
        line += symb;
      }
    }
  }
  input >> std::skipws >> std::fixed;
}
