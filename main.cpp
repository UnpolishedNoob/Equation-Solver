#include<bits/stdc++.h>
#include "Gauss_Elimination.cpp"
#include "Gauss_Jordan_Elimination.cpp"
#include "LU_factorization.cpp"
#include "Matrix_Inversion.cpp"
#include "jacobi.cpp"
#include "Gauss_Seidel.cpp"
using namespace std;

int main(){
    cout << "HELLO\nWELCOME TO Equation Solver !" << endl << endl;
    while(1){
    cout << endl<< "Which type of equation do you want to solve: \n"
            "1. Linear Equations\n"
            "2. Non-linear Equations\n"
            "3. Differential Equations\n"
            "4. Matrix Inversion\n" 
            "5. QUIT\n"
            "============================Make your choice : ";

    int n;
    cin >> n;
    if(n==5){break;;}

    if (n == 1) {
        cout <<endl<< "Which method would you like to try:\n"
                "1. Jacobi iterative method\n"
                "2. Gauss-Seidel iterative method\n"
                "3. Gauss elimination\n"
                "4. Gauss-Jordan elimination\n"
                "5. LU factorization\n"
                "6. QUIT\n" 
                 "============================Make your choice : ";

        int method;
        cin >> method;
            if(method==6){break;}

        // Call the appropriate function based on the user’s choice
        switch (method) {
            case 1: jacobi(); break;
            case 2: gauss_seidel(); break;
            case 3: gauss_elimination(); break;
            case 4: gauss_jordan_elimination(); break;
            case 5: lu_factorization(); break;
            default: cout << "Invalid choice. Please choose a valid method." << endl;
        }
    } else if (n == 4) {
        inverse_matrix();
    } else {
        cout << "Currently, only options 1 and 4 are implemented." << endl;
    }
    }
    cout<<"THANKS FOR USING"<<endl;
    return 0;
}