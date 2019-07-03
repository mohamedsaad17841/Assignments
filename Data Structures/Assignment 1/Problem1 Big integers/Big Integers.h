#ifndef BIGDECIMAL_H
#define BIGDECIMAL_H
#include <string>
using namespace std;
class BigDecimalInt
{
    private:
    string num1;
    public:
    BigDecimalInt();
    BigDecimalInt(string num1);
    BigDecimalInt operator-(BigDecimalInt &num);
    BigDecimalInt operator+(BigDecimalInt &num2);
    friend ostream &operator<<(ostream&out,const BigDecimalInt&num);
    BigDecimalInt Except (BigDecimalInt &num2);
    BigDecimalInt Subtract (BigDecimalInt &num2);
    BigDecimalInt Sum (BigDecimalInt &num2);
};
#endif // BIGDECIMAL_H
