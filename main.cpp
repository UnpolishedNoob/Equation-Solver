#include <bits/stdc++.h>
#include "Gauss_Elimination.cpp"
#include "Gauss_Jordan_Elimination.cpp"
#include "LU_factorization.cpp"
#include "Matrix_Inversion.cpp"
#include "jacobi.cpp"
#include "Gauss_Seidel.cpp"
#include "bisection.cpp"
#include "newtonrhapson.cpp"
#include "rangekutta.cpp"
#include "falseposition.cpp"
#include "secant.cpp"
using namespace std;

int main()
{
    cout << "HELLO\nWELCOME TO Equation Solver !" << endl
         << endl;
    while (1)
    {
        cout << endl
             << "Which type of equation do you want to solve: \n"
                "1. Linear Equations\n"
                "2. Non-linear Equations\n"
                "3. Differential Equations\n"
                "4. Matrix Inversion\n"
                "5. QUIT\n"
                "============================Make your choice : ";

        int n;
        cin >> n;
        if (n == 5)
        {
            break;
        }

        if (n == 1)
        {
            cout << endl
                 << "Which method would you like to try:\n"
                    "1. Jacobi iterative method\n"
                    "2. Gauss-Seidel iterative method\n"
                    "3. Gauss elimination\n"
                    "4. Gauss-Jordan elimination\n"
                    "5. LU factorization\n"
                    "6. QUIT\n"
                    "============================Make your choice : ";

            int method;
            cin >> method;
            if (method == 6)
            {
                break;
            }

            switch (method)
            {
            case 1:
                jacobi();
                break;
            case 2:
                gauss_seidel();
                break;
            case 3:
                gauss_elimination();
                break;
            case 4:
                gauss_jordan_elimination();
                break;
            case 5:
                lu_factorization();
                break;
            default:
                cout << "Invalid choice. Please choose a valid method." << endl;
            }
        }
        else if (n == 2)
        {
            cout << endl
                 << "Choose a method for Non-linear Equations:\n"
                    "1. Bisection Method\n"
                    "2. False Position Method\n"
                    "3. Secant Method\n"
                    "4. Newton-Raphson Method\n"
                    "5. QUIT\n"
                    "============================Make your choice : ";

            int method;
            cin >> method;
            if (method == 5)
            {
                break;
            }

            switch (method)
            {
            case 1:
                bisection();
                break;
            case 2:
                false_position();
                break;
            case 3:
                secant();
                break;
            case 4:
                newton_raphson();
                break;
            default:
                cout << "Invalid choice. Please choose a valid method." << endl;
            }
        }
        else if (n == 3)
        {
            cout << endl
                 << "Choose a method for Differential Equations:\n"
                    "1. Runge-Kutta Method\n"
                    "2. QUIT\n"
                    "============================Make your choice : ";

            int method;
            cin >> method;
            if (method == 2)
            {
                break;
            }

            switch (method)
            {
            case 1:
                rungekutta();
                break;
            default:
                cout << "Invalid choice. Please choose a valid method." << endl;
            }
        }
        else if (n == 4)
        {
            inverse_matrix();
        }
        else
        {
            cout << "Invalid choice. Please choose a valid option." << endl;
        }
    }
    cout << "THANKS FOR USING" << endl;
    return 0;
}