#include<bits/stdc++.h>
using namespace std;

void lu_factorization_for_2(){
    cout<<endl<<"Input format : ax +by + cz... ... = z"<<endl;
        double arr[3][4];
        for(int i=1;i<3;i++){
            for(int j=1;j<4;j++){
                cin>>arr[i][j];
            }
        }
        double l21=arr[2][1]/arr[1][1];
        double u11=arr[1][1];
        double u12=arr[1][2];
        double u22=arr[2][2]-l21*u12;


        double y1=arr[1][3];
        double y2=arr[2][3]-l21*y1;


        double x2=y2/u22;
        double x1=(y1-u12*x2)/u11;
        cout<<"SOLUTIONS : "<<endl;
        cout<<x1<<" "<<x2<<endl;
}

void lu_factorization_for_3(){
    cout<<endl<<"Input format : ax +by + cz... ... = z"<<endl;
        double arr[4][5];
        for(int i=1;i<4;i++){
            for(int j=1;j<5;j++){
                cin>>arr[i][j];
            }
        }

    double u11 = arr[1][1];
    double u12 = arr[1][2];
    double u13 = arr[1][3];
    double l21 = arr[2][1] / u11;
    double u22 = arr[2][2] - l21 * u12;
    double u23 = arr[2][3] - l21 * u13;
    double l31 = arr[3][1] / u11;
    double l32 = (arr[3][2] - l31 * u12) / u22;
    double u33 = arr[3][3] - l31 * u13 - l32 * u23;

   
    double y1 = arr[1][4];
    double y2 = arr[2][4] - l21 * y1;
    double y3 = arr[3][4] - l31 * y1 - l32 * y2;

    
    double x3 = y3 / u33;
    double x2 = (y2 - u23 * x3) / u22;
    double x1 = (y1 - u12 * x2 - u13 * x3) / u11;
    cout<<"SOLUTIONS : "<<endl;
    cout<<x1<<" "<<x2<<" "<<x3<<endl;
}

void lu_factorization_for_4(){
    cout<<endl<<"Input format : ax +by + cz... ... = z"<<endl;
    double arr[5][6];
    for (int i = 1; i < 5; i++) {
        for (int j = 1; j < 6; j++) {
            cin >> arr[i][j];
        }
    }

    
    double u11 = arr[1][1];
    double u12 = arr[1][2];
    double u13 = arr[1][3];
    double u14 = arr[1][4];
    double l21 = arr[2][1] / u11;
    double u22 = arr[2][2] - l21 * u12;
    double u23 = arr[2][3] - l21 * u13;
    double u24 = arr[2][4] - l21 * u14;
    double l31 = arr[3][1] / u11;
    double l32 = (arr[3][2] - l31 * u12) / u22;
    double u33 = arr[3][3] - l31 * u13 - l32 * u23;
    double u34 = arr[3][4] - l31 * u14 - l32 * u24;
    double l41 = arr[4][1] / u11;
    double l42 = (arr[4][2] - l41 * u12) / u22;
    double l43 = (arr[4][3] - l41 * u13 - l42 * u23) / u33;
    double u44 = arr[4][4] - l41 * u14 - l42 * u24 - l43 * u34;

    
    double y1 = arr[1][5];
    double y2 = arr[2][5] - l21 * y1;
    double y3 = arr[3][5] - l31 * y1 - l32 * y2;
    double y4 = arr[4][5] - l41 * y1 - l42 * y2 - l43 * y3;

    
    double x4 = y4 / u44;
    double x3 = (y3 - u34 * x4) / u33;
    double x2 = (y2 - u23 * x3 - u24 * x4) / u22;
    double x1 = (y1 - u12 * x2 - u13 * x3 - u14 * x4) / u11;
    cout<<"SOLUTIONS : "<<endl;
    cout<<x1<<" "<<x2<<" "<<x3<<" "<<x4<<endl;
}

void lu_factorization_for_5(){
    cout<<endl<<"Input format : ax +by + cz... ... = z"<<endl;
double arr[6][7];
    for (int i = 1; i < 6; i++) {
        for (int j = 1; j < 7; j++) {
            cin >> arr[i][j];
        }
    }

    // LU Decomposition
    double u11 = arr[1][1];
    double u12 = arr[1][2];
    double u13 = arr[1][3];
    double u14 = arr[1][4];
    double u15 = arr[1][5];
    double l21 = arr[2][1] / u11;
    double u22 = arr[2][2] - l21 * u12;
    double u23 = arr[2][3] - l21 * u13;
    double u24 = arr[2][4] - l21 * u14;
    double u25 = arr[2][5] - l21 * u15;
    double l31 = arr[3][1] / u11;
    double l32 = (arr[3][2] - l31 * u12) / u22;
    double u33 = arr[3][3] - l31 * u13 - l32 * u23;
    double u34 = arr[3][4] - l31 * u14 - l32 * u24;
    double u35 = arr[3][5] - l31 * u15 - l32 * u25;
    double l41 = arr[4][1] / u11;
    double l42 = (arr[4][2] - l41 * u12) / u22;
    double l43 = (arr[4][3] - l41 * u13 - l42 * u23) / u33;
    double u44 = arr[4][4] - l41 * u14 - l42 * u24 - l43 * u34;
    double u45 = arr[4][5] - l41 * u15 - l42 * u25 - l43 * u35;
    double l51 = arr[5][1] / u11;
    double l52 = (arr[5][2] - l51 * u12) / u22;
    double l53 = (arr[5][3] - l51 * u13 - l52 * u23) / u33;
    double l54 = (arr[5][4] - l51 * u14 - l52 * u24 - l53 * u34) / u44;
    double u55 = arr[5][5] - l51 * u15 - l52 * u25 - l53 * u35 - l54 * u45;

    // Forward substitution to solve Ly = b
    double y1 = arr[1][6];
    double y2 = arr[2][6] - l21 * y1;
    double y3 = arr[3][6] - l31 * y1 - l32 * y2;
    double y4 = arr[4][6] - l41 * y1 - l42 * y2 - l43 * y3;
    double y5 = arr[5][6] - l51 * y1 - l52 * y2 - l53 * y3 - l54 * y4;

    // Backward substitution to solve Ux = y
    double x5 = y5 / u55;
    double x4 = (y4 - u45 * x5) / u44;
    double x3 = (y3 - u34 * x4 - u35 * x5) / u33;
    double x2 = (y2 - u23 * x3 - u24 * x4 - u25 * x5) / u22;
    double x1 = (y1 - u12 * x2 - u13 * x3 - u14 * x4 - u15 * x5) / u11;
    cout<<"SOLUTIONS : "<<endl;
    cout<<x1<<" "<<x2<<" "<<x3<<" "<<x4<<" "<<x5<<endl;
}

void lu_factorization(){
    cout<<"Number of equations (2/3/4/5 ): ";
    int n;
    cin>>n;
    if(n==5){
        lu_factorization_for_5();
    }else if(n==4){
        lu_factorization_for_4();
    }else if(n==3){
        lu_factorization_for_3();
    }else{
        lu_factorization_for_2();
    }

}