#include "BigDecimal.h"
#include <iostream>
#include <string>
using namespace std;
BigDecimalInt::BigDecimalInt()
{
    num1=" ";
}
BigDecimalInt::BigDecimalInt(string num1)
{
    this->num1=num1;
}
BigDecimalInt BigDecimalInt::Except (BigDecimalInt &num2){
    int diff=0;
    if(num1.size()==num2.num1.size())
    {
        if(num1[0]<num2.num1[0])
        {
            string temp ;
            temp=num1;
            num1=num2.num1;
            num2.num1=temp;
            diff=num1.size()-num2.num1.size();
            for(int i=num1.size()-1; i>=0; i--)
            {
                num1[i]=int(num1[i]-48);
                num2.num1[i]=int(num2.num1[i]-48);
                if(num1[i]<num2.num1[i])
                {
                    num1[i]=num1[i]+10;
                    num1[i-1]=num1[i-1]-1;
                    num2.num1[i]=num1[i]-num2.num1[i];
                    num2.num1[i]=char(num2.num1[i]+48);
                }
                if(num1[i]>=num2.num1[i])
                {
                    num2.num1[i]=(num1[i]-num2.num1[i]);
                    num2.num1[i]=char(num2.num1[i]+48);
                }
            }
            return num2;
        }
        else
        {
            for(int i=num1.size()-1; i>=0; i--)
            {
                num1[i]=int(num1[i]-48);
                num2.num1[i]=int(num2.num1[i]-48);
                if(num1[i]<num2.num1[i])
                {
                    num1[i]=num1[i]+10;
                    num1[i-1]=num1[i-1]-1;
                    num2.num1[i]=num1[i]-num2.num1[i];
                    num2.num1[i]=char(num2.num1[i]+48);
                }
                if(num1[i]>=num2.num1[i])
                {
                    num2.num1[i]=(num1[i]-num2.num1[i]);
                    num2.num1[i]=char(num2.num1[i]+48);
                }
            }
            cout<<"-";
            return num2;

        }
    }
}
BigDecimalInt BigDecimalInt:: Subtract (BigDecimalInt &num2)
{
    int diff=0,counter=0;
    if(num1.size()>num2.num1.size())
    {
        diff=num1.size()-num2.num1.size();
        while(counter<diff)
        {
            num2.num1='0'+num2.num1;
            counter++;
        }
        for(int i=num1.size()-1; i>=0; i--)
        {
            num1[i]=int(num1[i]-48);
            num2.num1[i]=int(num2.num1[i]-48);
            if(num1[i]<num2.num1[i])
            {
                num1[i]=num1[i]+10;
                num1[i-1]=num1[i-1]-1;
                num2.num1[i]=num1[i]-num2.num1[i];
                num2.num1[i]=char(num2.num1[i]+48);
            }
            if(num1[i]>=num2.num1[i])
            {
                num2.num1[i]=(num1[i]-num2.num1[i]);
                num2.num1[i]=char(num2.num1[i]+48);
            }

        }
        num2.num1='-'+num2.num1;;
        return num2;
    }
    if(num1.size()<num2.num1.size())
    {
        string temp ;
        temp=num1;
        num1=num2.num1;
        num2.num1=temp;
        diff=num1.size()-num2.num1.size();
        while(counter<diff)
        {
            num2.num1='0'+num2.num1;
            counter++;
        }
        for(int i=num1.size()-1; i>=0; i--)
        {
            num1[i]=int(num1[i]-48);
            num2.num1[i]=int(num2.num1[i]-48);
            if(num1[i]<num2.num1[i])
            {
                num1[i]=num1[i]+10;
                num1[i-1]=num1[i-1]-1;
                num2.num1[i]=num1[i]-num2.num1[i];
                num2.num1[i]=char(num2.num1[i]+48);
            }
            if(num1[i]>=num2.num1[i])
            {
                num2.num1[i]=(num1[i]-num2.num1[i]);
                num2.num1[i]=char(num2.num1[i]+48);
            }
        }
        return num2;
    }

    if(num1.size()==num2.num1.size())
    {
        if(num1[0]<num2.num1[0])
        {
            string temp ;
            temp=num1;
            num1=num2.num1;
            num2.num1=temp;
            diff=num1.size()-num2.num1.size();
            for(int i=num1.size()-1; i>=0; i--)
            {
                num1[i]=int(num1[i]-48);
                num2.num1[i]=int(num2.num1[i]-48);
                if(num1[i]<num2.num1[i])
                {
                    num1[i]=num1[i]+10;
                    num1[i-1]=num1[i-1]-1;
                    num2.num1[i]=num1[i]-num2.num1[i];
                    num2.num1[i]=char(num2.num1[i]+48);
                }
                if(num1[i]>=num2.num1[i])
                {
                    num2.num1[i]=(num1[i]-num2.num1[i]);
                    num2.num1[i]=char(num2.num1[i]+48);
                }
            }
            cout<<"-";
            return num2;
        }
        else
        {
            for(int i=num1.size()-1; i>=0; i--)
            {
                num1[i]=int(num1[i]-48);
                num2.num1[i]=int(num2.num1[i]-48);
                if(num1[i]<num2.num1[i])
                {
                    num1[i]=num1[i]+10;
                    num1[i-1]=num1[i-1]-1;
                    num2.num1[i]=num1[i]-num2.num1[i];
                    num2.num1[i]=char(num2.num1[i]+48);
                }
                if(num1[i]>=num2.num1[i])
                {
                    num2.num1[i]=(num1[i]-num2.num1[i]);
                    num2.num1[i]=char(num2.num1[i]+48);
                }
            }
            return num2;

        }
    }
}
BigDecimalInt BigDecimalInt:: Sum (BigDecimalInt &num2)
{
    int diff=0,counter=0;
    if(num1.size()>num2.num1.size())
    {
        diff=num1.size()-num2.num1.size();
        while(counter<diff)
        {
            num2.num1='0'+num2.num1;
            counter++;
        }
    }
    if(num2.num1.size()>num1.size())
    {
        diff=num2.num1.size()-num1.size();
        while(counter<diff)
        {
            num1='0'+num1;
            counter++;
        }
    }
    for(int i=num1.size()-1; i>=0; i--)
    {
        num1[i]=int(num1[i]-48);
        num2.num1[i]=int(num2.num1[i]-48);
        if(num1[i]+num2.num1[i]>=10)
        {
            if(i==0)
            {
                num2.num1[i]=num1[i]+num2.num1[i]-10;
                num2.num1[i]=char(num2.num1[i]+48);
                num2.num1='1'+num2.num1;
            }
            else
            {
                num2.num1[i]=(num1[i]+num2.num1[i])-10;
                num2.num1[i-1]+=1;
                num2.num1[i]=char(num2.num1[i]+48);
            }
        }
        else
        {
            num2.num1[i]=num1[i]+num2.num1[i];
            num2.num1[i]=char(num2.num1[i]+48);
        }
    }
    return num2;
    if(num1.size()==num2.num1.size())
    {
    for(int i=num1.size()-1; i>=0; i--)
    {
        num1[i]=int(num1[i]-48);
        num2.num1[i]=int(num2.num1[i]-48);
        if(num1[i]+num2.num1[i]>=10)
        {
            if(i==0)
            {
                num2.num1[i]=num1[i]+num2.num1[i];
                num2.num1[i]-=10;
                 num2.num1[i]='1'+num2.num1[i];
            }
            else
            {
                num2.num1[i]=(num1[i]+num2.num1[i])-10;
                num1[i-1]+=1;
                num2.num1[i]=char(num2.num1[i]+48);
            }
        }
        else
        {
            num2.num1[i]=num1[i]+num2.num1[i];
            num2.num1[i]=char(num2.num1[i]+48);
        }
    }
    return num2;
}
}
BigDecimalInt BigDecimalInt:: operator+ (BigDecimalInt &num2)
{
    bool c=true;
    int diff=0,counter=0;
    if(c==true){
    if(num1[0]=='-' && num2.num1[0]!='-')
    {
        num1.erase(num1.begin()+ 0) ;
        if(num1.size()==num2.num1.size()){
        Except(num2);
        }
        else{Subtract(num2);}
       //cout<<'-';
        return num2;
        }
        }
    if(num1[0]=='-' && num2.num1[0]=='-')
    {
        num1.erase(num1.begin()+ 0) ;
        num2.num1.erase(num2.num1.begin()+0);
        num2=Sum(num2);
        num2.num1='-'+num2.num1;
        return num2;
    }
      if(num1[0]!='-' && num2.num1[0]=='-')
    {
        num2.num1.erase(num2.num1.begin()+0);
        num2=Subtract(num2);
        return num2;
    }

    if(num1.size()>num2.num1.size())
    {
        diff=num1.size()-num2.num1.size();
        while(counter<diff)
        {
            num2.num1='0'+num2.num1;
            counter++;

        }
    }
    if(num2.num1.size()>num1.size())
    {
        diff=num2.num1.size()-num1.size();
        while(counter<diff)
        {
            num1='0'+num1;
            counter++;
        }
    }
    for(int i=num1.size()-1; i>=0; i--)
    {
        num1[i]=int(num1[i]-48);
        num2.num1[i]=int(num2.num1[i]-48);
        if(num1[i]+num2.num1[i]>=10)
        {
            if(i==0)
            {
                num2.num1[i]=num1[i]+num2.num1[i]-10;
                num2.num1[i]=char(num2.num1[i]+48);
                cout<<"1";
            }
            else
            {
                num2.num1[i]=(num1[i]+num2.num1[i])-10;
                num1[i-1]+=1;
                num2.num1[i]=char(num2.num1[i]+48);
            }
        }
        else
        {
            num2.num1[i]=num1[i]+num2.num1[i];
            num2.num1[i]=char(num2.num1[i]+48);
        }

    }
    return num2;

}
BigDecimalInt BigDecimalInt:: operator- (BigDecimalInt &num2)
{
    if(num2.num1 == num1){
        num2.num1= '0';
        return num2;
    }
    int diff=0,counter=0;
    if(num1[0]=='-' && num2.num1[0]!='-')
    {
        if(num1.size()>num2.num1.size())
        {
            diff=num1.size()-num2.num1.size();
            while(diff>0)
            {
                num2.num1='0'+num2.num1;
                diff--;
            }
        }
        else if(num1.size()<num2.num1.size())
        {
            diff=num2.num1.size()-num1.size();
            while(diff>0)
            {
                num2.num1='0'+num2.num1;
                diff--;
            }
        }
        num1.erase(num1.begin()+ 0) ;
        Sum(num2);
        cout<<'-';
        return num2;
    }
    if(num1[0]=='-' && num2.num1[0]=='-')
    {
        if(num1.size()>num2.num1.size())
        {
            diff=num1.size()-num2.num1.size();
            while(diff>0)
            {
                num2.num1='0'+num2.num1;
                diff--;
            }
        }
        else if(num1.size()<num2.num1.size())
        {
            diff=num2.num1.size()-num1.size();
            while(diff>0)
            {
                num2.num1='0'+num2.num1;
                diff--;
            }
        }
        num1.erase(num1.begin()+ 0) ;
        num2.num1.erase(num2.num1.begin()+ 0) ;
        cout<<"-";
        Subtract(num2);
        return num2;
    }
    if(num1[0]!='-' && num2.num1[0]=='-')
    {
        num2.num1.erase(num2.num1.begin()+ 0) ;
        if(num1.size()>num2.num1.size())
        {
            diff=num1.size()-num2.num1.size();
            while(diff>0)
            {
                num2.num1='0'+num2.num1;
                diff--;
            }
        }
        else if(num1.size()<num2.num1.size())
        {
            diff=num2.num1.size()-num1.size();
            while(diff>0)
            {
                num1='0'+num1;
                diff--;
            }
        }
        num2=Sum(num2);
        return num2;
    }
    if(num1.size()>num2.num1.size())
    {
        diff=num1.size()-num2.num1.size();
        while(counter<diff)
        {
            num2.num1='0'+num2.num1;
            counter++;
        }
        for(int i=num1.size()-1; i>=0; i--)
        {
            num1[i]=int(num1[i]-48);
            num2.num1[i]=int(num2.num1[i]-48);
            if(num1[i]<num2.num1[i])
            {
                num1[i]=num1[i]+10;
                num1[i-1]=num1[i-1]-1;
                num2.num1[i]=num1[i]-num2.num1[i];
                num2.num1[i]=char(num2.num1[i]+48);
            }
            if(num1[i]>=num2.num1[i])
            {
                num2.num1[i]=(num1[i]-num2.num1[i]);
                num2.num1[i]=char(num2.num1[i]+48);
            }
        }
        return num2;
    }
    if(num1.size()<num2.num1.size())
    {
        string temp ;
        temp=num1;
        num1=num2.num1;
        num2.num1=temp;
        diff=num1.size()-num2.num1.size();
        while(counter<diff)
        {
            num2.num1='0'+num2.num1;
            counter++;
        }
        for(int i=num1.size()-1; i>=0; i--)
        {
            num1[i]=int(num1[i]-48);
            num2.num1[i]=int(num2.num1[i]-48);
            if(num1[i]<num2.num1[i])
            {
                num1[i]=num1[i]+10;
                num1[i-1]=num1[i-1]-1;
                num2.num1[i]=num1[i]-num2.num1[i];
                num2.num1[i]=char(num2.num1[i]+48);
            }
            if(num1[i]>=num2.num1[i])
            {
                num2.num1[i]=(num1[i]-num2.num1[i]);
                num2.num1[i]=char(num2.num1[i]+48);
            }
        }
        cout<<"-";
        return num2;
    }
    if(num1.size()==num2.num1.size())
    {
        if(num1[0]<num2.num1[0])
        {
            string temp ;
            temp=num1;
            num1=num2.num1;
            num2.num1=temp;
            diff=num1.size()-num2.num1.size();
            while(counter<diff)
            {
                num2.num1='0'+num2.num1;
                counter++;
            }
            for(int i=num1.size()-1; i>=0; i--)
            {
                num1[i]=int(num1[i]-48);
                num2.num1[i]=int(num2.num1[i]-48);
                if(num1[i]<num2.num1[i])
                {
                    num1[i]=num1[i]+10;
                    num1[i-1]=num1[i-1]-1;
                    num2.num1[i]=num1[i]-num2.num1[i];
                    num2.num1[i]=char(num2.num1[i]+48);
                }
                if(num1[i]>=num2.num1[i])
                {
                    num2.num1[i]=(num1[i]-num2.num1[i]);
                    num2.num1[i]=char(num2.num1[i]+48);
                }
            }
            cout<<"-";
            return num2;
        }
        else
        {
            for(int i=num1.size()-1; i>=0; i--)
            {
                num1[i]=int(num1[i]-48);
                num2.num1[i]=int(num2.num1[i]-48);
                if(num1[i]<num2.num1[i])
                {
                    num1[i]=num1[i]+10;
                    num1[i-1]=num1[i-1]-1;
                    num2.num1[i]=num1[i]-num2.num1[i];
                    num2.num1[i]=char(num2.num1[i]+48);
                }
                if(num1[i]>=num2.num1[i])
                {
                    num2.num1[i]=(num1[i]-num2.num1[i]);
                    num2.num1[i]=char(num2.num1[i]+48);
                }
            }
            return num2;

        }
    }
}
ostream &operator<<(ostream&out,const BigDecimalInt&num)
{
    for(int i=0; i<num.num1.size(); ++i)
    {
        out<<num.num1[i];
    }
    return out;
}
