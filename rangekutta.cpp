#include <bits/stdc++.h>
using namespace std;

double eq(double a,double b){
    return 7*a-8*b;
}

double exact(double a){
    return 57.0/64.0*exp(-8.0*a)+(7.0/8.0)*a+(7.0/64.0);
}

void rk(double x0,double y0,int steps,double h){
    vector<double>xv,yv,ev;
    double x=x0,y=y0;
    cout<<left<<setw(10)<<"Iteration"<<setw(15)<<"X Value"<<setw(15)<<"RK4 Y Value"<<setw(15)<<"Exact Y Value"<<setw(15)<<"Absolute Error"<<endl;
    cout<<string(70,'-')<<endl;

    for(int i=0;i<steps;i++){
        double k1=h*eq(x,y);
        double k2=h*eq(x+h/2.0,y+k1/2.0);
        double k3=h*eq(x+h/2.0,y+k2/2.0);
        double k4=h*eq(x+h,y+k3);
        y+= (k1+2*k2+2*k3+k4)/6.0;
        x+=h;
        xv.push_back(x);
        yv.push_back(y);
        double exact_y=exact(x);
        double error=fabs(y-exact_y);
        ev.push_back(error);
        cout<<left<<setw(10)<<(i+1)<<setw(15)<<fixed<<setprecision(4)<<x<<setw(15)<<fixed<<setprecision(4)<<y<<setw(15)<<fixed<<setprecision(4)<<exact_y<<setw(15)<<fixed<<setprecision(4)<<error<<endl;
    }

    ofstream file("results.txt");
    file<<"Iteration,X Value,RK4 Y Value,Exact Y Value,Absolute Error\n";
    for(size_t j=0;j<xv.size();j++)
        file<<(j+1)<<", "<<xv[j]<<", "<<yv[j]<<", "<<exact(xv[j])<<", "<<ev[j]<<"\n";
    file.close();
}

int main(){
    cout<<"This method works the differential equation 8*x - 7*y"<<"\n";
    double ix=0,iy=1;
    int s=15;
    double h=0.1;
    rk(ix,iy,s,h);
    return 0;
}
