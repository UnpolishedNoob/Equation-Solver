#include <bits/stdc++.h>
using namespace std;


double a4,a3,a2,a1,a0;
double f(double x) {
    return a4*pow(x,4)+a3*pow(x,3)+a2*x*x+a1*x+a0;
}

void bisectionsolver(double a, double b) {
    double a0 = INT_MAX;
    double o;
    while(true) {
        o =a0;
        a0 =(a + b)/2;
        if (f(a)*f(a0)<0)
            b=a0;
        else
            a =a0;
        if (f(a0)==0||abs(a0 - o)<0.0001) {
            cout << "Absolute root: " <<a0<<"\n";
            return;
        }
    }
}

void bisection()
{
    double key;
    cout<<"Choose format: "<<endl;
    cout<<"1.ax^2+bx+c."<<endl;
    cout<<"2.ax^3+bx^2+cx+d."<<endl;
    cout<<"3.ax^4+bx^3+cx^2+dx+e."<<endl;
    cout<<"enter a key: ";
    cin>>key;

   if(key==1)
   {
    cout << "The format is defined as ax^2 + bx+ c."<<endl;
    cout << "Now enter values of coefficients a, b, c:\n";
    cin>>a2>>a1>>a0;
    a4=0;a3=0;
   }
   else if(key==2){
     cout << "The format is defined as ax^3+ bx^2+ cx+d."<<endl;
    cout << "Now enter values of coefficients a, b, c, d:\n";
    cin>>a3>>a2>>a1>>a0;
    a4=0;
   }

    else if(key==3)
    {
         cout << "The format is defined as ax^4+ bx^3+ cx^2+dx+e."<<endl;
    cout << "Now enter values of coefficients a, b, c, d, e:\n";
    cin>>a4>>a3>>a2>>a1>>a0;
    }
    else
    {
        cout<<"invalid key"<<endl;
        return;
    }
    double n = floor(sqrt(abs(a4+a3+a2+a1+a0))) + 10;

    vector<pair<double, double>> intervals;
    for (double i=-n;i<n;i+= 0.1) {
        if (f(i)*f(i+0.1)<0) {
            intervals.push_back({i,i+0.1});
        }
    }

    if (intervals.empty()) {
        cout << "No roots found in the given range.\n";
    } else {
        for (auto interval : intervals) {
            cout << "Searching root in interval [" << interval.first << ", " << interval.second << "]\n";
            bisectionsolver(interval.first, interval.second);
        }
    }
}


