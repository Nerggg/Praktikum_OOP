#include "NegativeExpression.hpp"

NegativeExpression::NegativeExpression(Expression *x) : UnaryExpression(x) {}
int NegativeExpression::solve() {
    return x->solve() * -1;
}