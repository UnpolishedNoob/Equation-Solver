#include <bits/stdc++.h>
using namespace std;


double a, b, c, d, e;
double f(double x){
    return a*x*x*x*x+b*x*x*x+c*x*x+d* x+ e;
}

void secantsolver(double x1, double x2) {
    double it = 0;
    double ox = INT_MAX;
    while (true) {
        it++;
        double f1 = f(x1);
        double f2 = f(x2);
        double x3 = x2-(f2*(x2-x1))/(f2-f1);
        if (f(x3)==0||abs(x3-ox)<=0.00001) {
            cout <<"Absolute root: "<<x3<<"\n";
            return;
        }
        ox = x3;
        x1 = x2;
        x2 = x3;
    }
}

int secant(){
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
    cin>>c>>d>>e;
    a=0;b=0;
   }
   else if(key==2){
     cout << "The format is defined as ax^3+ bx^2+ cx+d."<<endl;
    cout << "Now enter values of coefficients a, b, c, d:\n";
    cin>>b>>c>>d>>e;
    a=0;
   }

    else if(key==3)
    {
         cout << "The format is defined as ax^4+ bx^3+ cx^2+dx+e."<<endl;
    cout << "Now enter values of coefficients a, b, c, d, e:\n";
    cin>>a>>b>>c>>d>>e;
    }
    else
    {
        cout<<"invalid key"<<endl;
        return 0;
    }
    double n =floor(sqrt(abs(a+b+c+d+e)))+10;

    vector<pair<double, double>> doubleervals;
    for (double i=-n;i< n;i+=0.1) {
        if(f(i)*f(i+0.1)<0) {
            doubleervals.push_back({i,i+0.1});
        }
    }

    if (doubleervals.empty()) {
        cout << "No roots found in the given range.\n";
    } else {
        for (auto doubleerval : doubleervals) {
            cout << "Searching root in doubleerval [" << doubleerval.first << ", " << doubleerval.second << "]\n";
            secantsolver(doubleerval.first, doubleerval.second);
        }
    }

    return 0;
}
