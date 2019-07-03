#include <iostream>
#include <vector>
using namespace std;

float random(int seed)
{
    float current_state = (7*seed)%11/10.0;
    if(current_state == 1 )
        current_state-=0.1 ;
    else if(current_state == 0)
        current_state +=0.1 ;
    return current_state ;
}
int main()
{
     for(int x = 1 ; x<=100 ; x++)
        cout<<random(x) << endl ;

    return 0 ;

}
