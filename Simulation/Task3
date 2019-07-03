#include <bits/stdc++.h>

using namespace std;

const int profit_of_selling = 450;
const int carrying_cost = 50;
const int shortage_cost = 100;
const int num_of_orders = 2;
const int num_of_weeks= 50;


int generate_D (){
    int r,D;
    r = rand() % 10;
    if(r>=0 && r<2) D = 0;
    else if(r>=2 && r<6) D = 1;
    else if(r>=6 && r<8) D = 2;
    else if(r>=8 && r<9) D = 3;
    else if(r>=9 && r<10) D = 4;

    return D;
}



int main()
{
    srand(time(0));

    int avail_PCs = 0, sales = 0, demand = 0, profit = 0, NetProfit = 0, avg_netProfit = 0;

    for (int i = 1 ; i <= num_of_orders ; i++)
    {
        for(int j=0 ; j<num_of_weeks ; j++)
        {
            avail_PCs += i ;
            demand = generate_D();

            sales = min(avail_PCs, demand);
            profit = profit_of_selling * sales;
            avail_PCs -= sales;
            if (avail_PCs > demand) NetProfit += profit - carrying_cost*(avail_PCs - demand);
            else if (demand > avail_PCs) NetProfit += profit - shortage_cost*(demand - avail_PCs);


        }
        cout << "Net Profit = " << NetProfit <<endl;
        avg_netProfit = NetProfit / num_of_weeks;
        cout << "Average net profit = " << avg_netProfit << endl <<endl;
    }
}
