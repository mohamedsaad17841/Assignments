#include <iostream>
#include <random>
#include <bits/algorithmfwd.h>
#include <vector>
#include <cstdlib>
#include <bits/stdc++.h>
using namespace std;

int num_clerks=0;
int num_of_hours=10;
int salary_Clerk=20*num_of_hours;
int average_sale=22;
double IAT;
double AT;
double SST;
double ST;
double WT;
double CT;
double TIS;
double c1;
double total_time;
vector<double>inter_arrival_time;
vector<double>arrival_time;
vector<double>start_service_time;
vector<double>service_time;
vector<double>wating_time;
vector<double>completion_time;
vector<double>time_in_system;
vector<double>clerk1;
vector<double>clerk2;
vector<double>clerk3;
vector<double>clerk4;
vector<double>clerk5;
vector<double>clerk6;


int waiting=0;


double generate_IAT()
{
    unsigned seed = chrono::system_clock::now().time_since_epoch().count();
    default_random_engine generator(seed);
    normal_distribution<double> distribution(1.5,0.15);
    double IAT= distribution(generator);
    return IAT;
}


double generate_Service_Time()
{
    unsigned seed = chrono::system_clock::now().time_since_epoch().count();
    default_random_engine generator(seed);
    normal_distribution<double> distribution(6.0,1.0);
    double ST= distribution(generator);
    return ST;

}
//bool comp(int a, int b)
//{
//    return (a < b);
//}

void smallshop()
{
    int check;
    int rent=200;
    num_clerks=2;
    double sales;
    double revenue;
    int i=0;
    double total_salary = num_clerks * salary_Clerk;

    while(true)
    {
        IAT=generate_IAT();
        inter_arrival_time.push_back(IAT);
        //cout<<inter_arrival_time[i]<<"     |";

        if( i==0 )
        {
            AT = inter_arrival_time[i];
            arrival_time.push_back(AT);
            //cout<<arrival_time[i]<<"     |";
        }
        else
        {
            AT=arrival_time[i-1]+inter_arrival_time[i];
            arrival_time.push_back(AT);
            //cout<<arrival_time[i]<<"     |";
        }

        if (arrival_time[i]>=600) //shop will close  after 10 hours
            break;


        if (i==0 || i==1)
        {
            SST=arrival_time[i];
            start_service_time.push_back(SST);
            //cout<<start_service_time[i]<<"     |";
        }

        else
        {
            SST=max(arrival_time[i] , min(clerk1[i-1] , clerk2[i-1]));

            start_service_time.push_back(SST);
          //  cout<<start_service_time[i]<<"     |";
        }


        if( i==0 )
        {
            ST = generate_Service_Time();
            service_time.push_back(ST);

            //cout<<service_time[i]<<"     |";


            check=1;
        }

        else
        {
                if(clerk1[i-1] <= clerk2[i-1]){

                    ST=generate_Service_Time();
                    service_time.push_back(ST);
                    check=1;
                }

                else{

                    ST=generate_Service_Time();
                    service_time.push_back(ST);
                    check=2;

                }

        }

            WT=start_service_time[i]-arrival_time[i];
            if(WT>0)
                waiting+=1;
            total_time+=WT;

        //cout<<"wataing time is :"<<fixed<<WT<<endl;

            wating_time.push_back(WT);
        //cout<<wating_time[i]<<"     |";
//        total_waiting_time+=WT;

        CT=start_service_time[i]+service_time[i];
        completion_time.push_back(CT);
        //cout<<completion_time[i]<<"     |";

        TIS=service_time[i]+wating_time[i];     ///time in system.
        time_in_system.push_back(TIS);
       // cout<<time_in_system[i]<<"     |";


        if( i==0 )
        {
            clerk1.push_back(CT);
            clerk2.push_back(0);
        }

        else{

        if (check == 1){
            clerk1.push_back(CT);
            clerk2.push_back(clerk2[i-1]);
        }

        else if (check == 2){

            clerk2.push_back(CT);
            clerk1.push_back(clerk1[i-1]);
        }

        }
        i++;
}
    double cost=total_salary+rent+((10/60)*total_time);     ///1/6 * total time.
    sales=i*22;
    revenue=sales-cost;
    cout<<"Small Shop Revenue Is : "<< revenue <<endl;

}

void bigshop()
{
    int check;
    num_clerks=6;
    int rent=2000;
    double sales;
    int counter=0;
    int i=0;
    double total_salary = num_clerks*salary_Clerk;
    while(true)
    {
        IAT=generate_IAT();
        inter_arrival_time.push_back(IAT);
        //cout<<inter_arrival_time[i]<<"     |";

        if( i==0 )
        {
            AT=inter_arrival_time[i];
            arrival_time.push_back(AT);
            //cout<<arrival_time[i]<<"     |";
        }
        else
        {
            AT=arrival_time[i-1]+inter_arrival_time[i];
            arrival_time.push_back(AT);
            //cout<<arrival_time[i]<<"     |";
        }

        if (arrival_time[i]>=600)
            break;


        if (i==0 ||i==1||i==2||i==3||i==4||i==5)
        {
            SST=arrival_time[i];
            start_service_time.push_back(SST);
            //cout<<start_service_time[i]<<"     |";
        }

        else
        {
            double min1=min(clerk1[i-1],clerk2[i-1]);
            double min2=min(clerk3[i-1],clerk4[i-1]);
            double min3=min(clerk5[i-1],clerk6[i-1]);

            SST=max(arrival_time[i] , min({min1,min2,min3}));

            start_service_time.push_back(SST);
          //  cout<<start_service_time[i]<<"     |";
        }

        if( i==0 ){
        ST=generate_Service_Time();
        service_time.push_back(ST);
        //cout<<service_time[i]<<"     |";



        }
        else {
                if(clerk1[i-1] <= clerk2[i-1] && clerk1[i-1] <= clerk3[i-1]  &&  clerk1[i-1]<= clerk4[i-1] && clerk1[i-1]<= clerk5[i-1] &&  clerk1[i-1]<= clerk6[i-1]){

                    ST=generate_Service_Time();
                    service_time.push_back(ST);
                    check=1;
                }

                else if (clerk2[i-1] <= clerk1[i-1] && clerk2[i-1] <= clerk3[i-1]  &&  clerk2[i-1]<= clerk4[i-1] && clerk2[i-1]<= clerk5[i-1] &&  clerk2[i-1]<= clerk6[i-1]){

                    ST=generate_Service_Time();
                    service_time.push_back(ST);
                    check=2;

                }

                else if (clerk3[i-1] <= clerk1[i-1] && clerk3[i-1] <= clerk2[i-1]  &&  clerk3[i-1]<= clerk4[i-1] && clerk3[i-1]<= clerk5[i-1] &&  clerk3[i-1]<= clerk6[i-1]){

                    ST=generate_Service_Time();
                    service_time.push_back(ST);
                    check=3;

                }

                else if (clerk4[i-1] <= clerk1[i-1] && clerk4[i-1] <= clerk3[i-1]  &&  clerk4[i-1]<= clerk2[i-1] && clerk4[i-1]<= clerk5[i-1] &&  clerk4[i-1]<= clerk6[i-1]){

                    ST=generate_Service_Time();
                    service_time.push_back(ST);
                    check=4;

                }
                else if (clerk5[i-1] <= clerk1[i-1] && clerk5[i-1] <= clerk3[i-1]  &&  clerk5[i-1]<= clerk4[i-1] && clerk5[i-1]<= clerk2[i-1] &&  clerk5[i-1]<= clerk6[i-1]){

                    ST=generate_Service_Time();
                    service_time.push_back(ST);
                    check=5;

                }
                else if (clerk6[i-1] <= clerk1[i-1] && clerk6[i-1] <= clerk3[i-1]  &&  clerk6[i-1]<= clerk4[i-1] && clerk6[i-1]<= clerk5[i-1] &&  clerk6[i-1]<= clerk2[i-1]){

                    ST=generate_Service_Time();
                    service_time.push_back(ST);
                    check=6;

                }

        }

            WT=start_service_time[i]-arrival_time[i];
            if(WT>0)
                waiting+=1;
            total_time+=WT;

        //cout<<"wataing time is :"<<fixed<<WT<<endl;

            wating_time.push_back(WT);
        //cout<<wating_time[i]<<"     |";
//        total_waiting_time+=WT;

        CT=start_service_time[i]+service_time[i];
        completion_time.push_back(CT);
        //cout<<completion_time[i]<<"     |";

        TIS=service_time[i]+wating_time[i];
        time_in_system.push_back(TIS);
       // cout<<time_in_system[i]<<"     |";


        if( i==0 ){

        clerk1.push_back(CT);
        clerk2.push_back(0);
        clerk3.push_back(0);
        clerk4.push_back(0);
        clerk5.push_back(0);
        clerk6.push_back(0);

            }

        else{

        if (check == 1){
            clerk1.push_back(CT);
            clerk2.push_back(clerk2[i-1]);
            clerk3.push_back(clerk3[i-1]);
            clerk4.push_back(clerk4[i-1]);
            clerk5.push_back(clerk5[i-1]);
            clerk6.push_back(clerk6[i-1]);
        }

        else if (check == 2){

            clerk2.push_back(CT);
            clerk1.push_back(clerk1[i-1]);
            clerk3.push_back(clerk3[i-1]);
            clerk4.push_back(clerk4[i-1]);
            clerk5.push_back(clerk5[i-1]);
            clerk6.push_back(clerk6[i-1]);
        }

         else if (check == 3){

            clerk3.push_back(CT);
            clerk1.push_back(clerk1[i-1]);
            clerk2.push_back(clerk2[i-1]);
            clerk4.push_back(clerk4[i-1]);
            clerk5.push_back(clerk5[i-1]);
            clerk6.push_back(clerk6[i-1]);
        }

         else if (check == 4){

            clerk4.push_back(CT);
            clerk1.push_back(clerk1[i-1]);
            clerk3.push_back(clerk3[i-1]);
            clerk2.push_back(clerk2[i-1]);
            clerk5.push_back(clerk5[i-1]);
            clerk6.push_back(clerk6[i-1]);
        }

         else if (check == 5){

            clerk5.push_back(CT);
            clerk1.push_back(clerk1[i-1]);
            clerk3.push_back(clerk3[i-1]);
            clerk4.push_back(clerk4[i-1]);
            clerk2.push_back(clerk2[i-1]);
            clerk6.push_back(clerk6[i-1]);
        }

         else if (check == 6){

            clerk6.push_back(CT);
            clerk1.push_back(clerk1[i-1]);
            clerk3.push_back(clerk3[i-1]);
            clerk4.push_back(clerk4[i-1]);
            clerk5.push_back(clerk5[i-1]);
            clerk2.push_back(clerk2[i-1]);

        }

        }
        i++;
}
    double cost=total_salary+rent+((10/60)*total_time);
     sales=i*22;
     double revenue=sales-cost;
    cout<<"Big Shop revenue Is : "<<revenue <<endl;

}



int main()
{
    smallshop();
    bigshop();

    return 0;
}
