#include <iostream>
#include "BigDecimal.h"
using namespace std;
int main()
{
    BigDecimalInt num1("-5100");
    BigDecimalInt num2("5000");
    cout<<num1+num2<<endl;
    return 0;
}
