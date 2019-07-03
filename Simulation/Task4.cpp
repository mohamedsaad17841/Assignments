#include <algorithm>
#include <iostream>
#include <random>
#include <numeric>
#include <random>
#include <vector>
#include <iomanip>  ///setw()

using namespace std;

const int customers = 10;
const int num_of_ATMS = 3;

default_random_engine generator1;
exponential_distribution <double> exponential(1);
default_random_engine generator2;
normal_distribution <double> norm(3, .5);


std::mt19937_64 eng;
    std::piecewise_linear_distribution<> dist({2., 3.3, 4.},
                                              [](double x)
                                              {
                                                  return x == 3.3 ? 1. : 0.;
                                              });

int main()
{
    ///initialize of zeros.
    double availTimeArray[num_of_ATMS] = {0, 0, 0};

    //**************************************

    ///Calculations variables
    double waitingTime_sum = 0;
    double num_of_wating = 0;
    double wating_more_than_one = 0;
    double Max = 0.0;
    double firstATM_serviceTime_sum = 0.0;
    double secondATM_serviceTime_sum = 0.0;
    double thirdATM_serviceTime_sum = 0.0;

    //**************************************

    float IAT;
    float serviceTime;

    float watingTime[customers];
    float completionTime[customers];
    float startServiceTime[customers];
    float arrivalTime[customers];


    for(int i=0 ; i<customers ; i++)
    {
        watingTime[i] = 0;
        completionTime[i] = 0;
        startServiceTime[i] = 0;
        arrivalTime[i] = 0;
    }

    cout << endl << setw(12) << "IAT" << setw(19) << "Arrival time" << setw(20) <<"Service start time" <<
     setw(15) << "Wating time" << setw(14) << "Service time" << setw(18) << "Completion time" << endl << endl;
    for(int i=0 ; i<customers ; i++)
    {
        IAT = exponential(generator1);
        if(i > 0)
            arrivalTime[i] = IAT + arrivalTime[i-1];
        else
        {
            arrivalTime[0] = IAT;
        }

        float Min = availTimeArray[0];
        int index = 0;
        for(int j=1 ; j<3 ; j++)
        {
            if(availTimeArray[j] < Min)
            {
                Min = availTimeArray[j];
                index = j;
            }
        }

        if(arrivalTime[i] > Min)
            startServiceTime[i] = arrivalTime[i];
        else
        {
            startServiceTime[i] = Min;
            watingTime[i] = startServiceTime[i] - arrivalTime[i];
        }
        if(index == 0)
        {
            serviceTime = 2.0 + (rand() % (4 - 2 + 1));  ///Uniform dist.
            firstATM_serviceTime_sum += serviceTime;    ///Calculations.
        }
        else if(index == 1)
        {
            serviceTime = dist(eng);   ///Triangle dist.
            secondATM_serviceTime_sum += serviceTime;    ///Calculations.
        }
        else if(index == 2)
        {
            serviceTime = norm(generator2);    ///normal dist.
            thirdATM_serviceTime_sum += serviceTime;    ///Calculations.
        }

        completionTime[i] = startServiceTime[i] + serviceTime;
        availTimeArray[index] = completionTime[i];

        //*******************************************************************************************************

        ///Calculations
        waitingTime_sum += watingTime[i];


        if(watingTime[i] > 0)
        {
            num_of_wating++;
        }

        if(watingTime[i] > 1)
            wating_more_than_one++;

        if(watingTime[i] > Max)
            Max = watingTime[i];


        //*******************************************************************************************************

        cout << setw(15) << IAT << setw(15) <<  setw(15) << arrivalTime[i] << setw(15) <<  startServiceTime[i]
        << setw(15) << watingTime[i] << setw(15) << serviceTime << setw(15) << completionTime[i] << endl;

    }

cout << endl << "Calculations : " << endl;
cout << "Average waiting time = " << waitingTime_sum/customers << endl;
cout << "Probability of waiting = " << num_of_wating/customers << endl;
cout << "Probability of waiting more than minute = " << wating_more_than_one/customers << endl;
cout << "Maximum waiting time = " << Max << endl;
cout << "Utilization of the first ATM machine = " << firstATM_serviceTime_sum/completionTime[customers-1] << endl;
cout << "Utilization of the second ATM machine = " << secondATM_serviceTime_sum/completionTime[customers-1] << endl;
cout << "Utilization of the third ATM machine = " << thirdATM_serviceTime_sum/completionTime[customers-1] << endl;


    return 0;
}
