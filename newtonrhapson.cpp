#include <bits/stdc++.h>
using namespace std;


double a, b, c, d, e;
double f(double x) {
    return a*x*x*x*x+b*x*x*x+c*x*x+d*x+ e;
}

double ff(double x) {
    return 4*a*x*x*x+3*b*x*x + 2*c*x+d;
}

void newtonRaphsonsolver(double x0, set<double>& r) {
    double it = 0;
    while (true) {
        it++;
        double f1 =f(x0);
        double ff1 =ff(x0);

        if (ff1 == 0) {
            cout << "Derivative zero; Newton-Raphson cannot proceed.\n";
            return;
        }

        double x1 =x0-f1/ff1;

        if (abs(x1 - x0) <= 0.00001||f(x1) == 0) {
            bool is_new_root = true;
            for (auto root : r) {
                if (abs(root - x1) <= 0.001) {
                    is_new_root = false;
                    break;
                }
            }
            if (is_new_root) {
                r.insert(x1);
                cout << "Root found: " <<x1<<" after "<<it<<" iterations\n";
            }
            return;
        }

        x0 = x1;
    }
}

   int newton_raphson(){
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

    double range = 100;
    set<double> r;
    double step_size = 0.1;
    for (double i =-range;i<range;i+=step_size){
        if(f(i)*f(i+step_size)<0) {
            cout << "Starting Newton-Raphson at doubleerval [" <<i<<", "<<i+step_size<<"]\n";
            newtonRaphsonsolver(i, r);
        }
    }
    if (r.empty()) {
        cout << "No root found in the given range.\n";
    } else {
        cout << "Unique root found:\n";
        for (auto root : r) {
            cout << root << "\n";
        }
    }

    return 0;
}