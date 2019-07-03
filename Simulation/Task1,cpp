#include <bits/stdc++.h>

using namespace std;

int arr[100] = {};

int generateC1()    //discrete dist
{
    srand(time(0));
    int r = 0, c1 = 0;
    r = rand() % 10;
    if(r >= 0 && r < 1) c1 = 43;
    if(r >= 1 && r < 3) c1 = 44;
    if(r >= 3 && r < 7) c1 = 45;
    if(r >= 7 && r < 9) c1 = 46;
    if(r >= 9 && r < 10) c1 = 47;
    return c1;
}


int generateC2()     //uniform dist
{
    srand(time(0));
    return 80 + (rand() % (100 - 80 + 1));  //there is also a+r(b-a)
}

void generateX()    //normal dist
{
    default_random_engine generator;
    normal_distribution <double> distribution(15000, 4500); //15000 = mean, 4500 = std

    //
    //double number  = distribution(generator);

    for(int i=0 ; i<100 ; ++i)
    {
        int number = distribution(generator);
        //if((number >= 0.0) && (number < 10.0)) ++arr[int(number)]; //casting the index to integer.
        arr[i] = number;
    }
}
int main()

{
    int profit, c1, c2, Max, ctr = 0;
    vector <int> data;  //profit array.
    generateX();
    for(int i = 0 ; i<10 ; i++)
    {
        c1 = generateC1();   c2 = generateC2();
        profit = (249 - c1 - c2)*arr[i] - 1000000;  //arr[i] = x = demand
        arr[i] = profit;
    }
    for(int i=0 ; i<10 ; i++)
    {
        data.push_back(arr[i]);
    }
    for(int i=0 ; i<10 ; i++)
    {
        cout << data[i] << " " ;
    }
    cout << endl;

    Max = *max_element(data.begin(), data.end());
    cout << "Max profit is : " << Max << endl;

    cout << "Average profit is : " << (accumulate(data.begin(), data.end(), 0))/ data.size() << endl;

    cout << "Max loss : " << *min_element(data.begin(), data.end()) << endl;

    for(int i=0 ; i<10 ; i++)
    {
        if(data[i] < 0)
        {
            ctr++;
        }
    }
    cout << "Probability of loss = " << float(ctr/float(data.size())) << endl;

    return 0;
}
