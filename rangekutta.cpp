#include <bits/stdc++.h>
using namespace std;
double a,b,c,d,e,key;
double eq(double x,double y){
    if(key==1)
    return a*x+b*y;
    else if(key==2)
        return a*sin(x);
    else if(key==3)
        return a*cos(x);
    else if(key==4)
        return a*cos(x)+b*sin(y);
    else if(key==5)
        return a*sin(x)+b*cos(y);

        return 0;
}


void rk(double x0,double y0,int steps,double h){
    vector<double>xv,yv;
    double x=x0,y=y0;
    cout<<left<<setw(10)<<"Iteration"<<setw(15)<<"X Value"<<setw(15)<<"RK4 Y Value"<<endl;
    cout<<string(50,'-')<<endl;

    for(int i=0;i<steps;i++){
        double k1=h*eq(x,y);
        double k2=h*eq(x+h/2.0,y+k1/2.0);
        double k3=h*eq(x+h/2.0,y+k2/2.0);
        double k4=h*eq(x+h,y+k3);
        y+= (k1+2*k2+2*k3+k4)/6.0;
        x+=h;
        xv.push_back(x);
        yv.push_back(y);
        cout<<left<<setw(10)<<(i+1)<<setw(15)<<fixed<<setprecision(4)<<x<<setw(15)<<fixed<<setprecision(4)<<y<<setw(15)<<setw(15)<<endl;
    }

}

void rungekutta()
{
    cout<<"choose format: "<<endl;
    cout<<"1.ax+by"<<endl;
    cout<<"2.asinx"<<endl;
    cout<<"3.acosx"<<endl;
    cout<<"4.asinx+bcosy"<<endl;
    cout<<"5.acosx+bsiny"<<endl;
    cout<<"enter a key: ";
    cin>>key;
    if(key==1){
            cout<<"This format is for ax+by : "<<endl;
    cout<<"Enter the value of a,b : ";
        cin>>a>>b;
    }
    else if(key==2){
    cout<<"This format is for asinx : "<<endl;
    cout<<"Enter the value of a : ";
    cin>>a;
    }
    else if(key==3){
      cout<<"This format is for acosx : "<<endl;
      cout<<"Enter the value of a : ";
        cin>>a;
    }
    else if(key==4){
    cout<<"This format is for asinx+bcosx : "<<endl;
    cout<<"Enter the value of a,b : ";
        cin>>a>>b;
    }
    else if(key==5){
    cout<<"This format is for acosx+bsinx : "<<endl;
    cout<<"Enter the value of a,b : ";
        cin>>a>>b;
    }
    else{
        cout<<"invalid key"<<endl;
        return;
    }
        rk(0,1,15,.1);
}
