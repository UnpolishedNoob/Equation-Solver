#include <bits/stdc++.h>
using namespace std;

double a_newton, b_newton, c_newton, d_newton, e_newton;
double f_newton(double x) {
    return a_newton * x * x * x * x + b_newton * x * x * x + c_newton * x * x + d_newton * x + e_newton;
}

double ff_newton(double x) {
    return 4 * a_newton * x * x * x + 3 * b_newton * x * x + 2 * c_newton * x + d_newton;
}

void newtonRaphsonSolver(double x0, set<double>& roots_newton) {
    double iterations = 0;
    while (true) {
        iterations++;
        double f1 = f_newton(x0);
        double ff1 = ff_newton(x0);

        if (ff1 == 0) {
            cout << "Derivative zero; Newton-Raphson cannot proceed.\n";
            return;
        }

        double x1 = x0 - f1 / ff1;

        if (abs(x1 - x0) <= 0.00001 || f_newton(x1) == 0) {
            bool is_new_root = true;
            for (auto root : roots_newton) {
                if (abs(root - x1) <= 0.001) {
                    is_new_root = false;
                    break;
                }
            }
            if (is_new_root) {
                roots_newton.insert(x1);
                cout << "Root found: " << x1 << " after " << iterations << " iterations\n";
            }
            return;
        }

        x0 = x1;
    }
}

int newton_raphson() {
    double key_newton;
    cout << "Choose format: " << endl;
    cout << "1. ax^2 + bx + c" << endl;
    cout << "2. ax^3 + bx^2 + cx + d" << endl;
    cout << "3. ax^4 + bx^3 + cx^2 + dx + e" << endl;
    cout << "Enter a key: ";
    cin >> key_newton;

    if (key_newton == 1) {
        cout << "The format is defined as ax^2 + bx + c." << endl;
        cout << "Now enter values of coefficients a, b, c:\n";
        cin >> c_newton >> d_newton >> e_newton;
        a_newton = 0; b_newton = 0;
    } else if (key_newton == 2) {
        cout << "The format is defined as ax^3 + bx^2 + cx + d." << endl;
        cout << "Now enter values of coefficients a, b, c, d:\n";
        cin >> b_newton >> c_newton >> d_newton >> e_newton;
        a_newton = 0;
    } else if (key_newton == 3) {
        cout << "The format is defined as ax^4 + bx^3 + cx^2 + dx + e." << endl;
        cout << "Now enter values of coefficients a, b, c, d, e:\n";
        cin >> a_newton >> b_newton >> c_newton >> d_newton >> e_newton;
    } else {
        cout << "Invalid key." << endl;
        return 0;
    }

    double range_newton = 100;
    set<double> roots_newton;
    double step_size_newton = 0.1;
    for (double i = -range_newton; i < range_newton; i += step_size_newton) {
        if (f_newton(i) * f_newton(i + step_size_newton) < 0) {
            cout << "Starting Newton-Raphson at interval [" << i << ", " << i + step_size_newton << "]\n";
            newtonRaphsonSolver(i, roots_newton);
        }
    }
    if (roots_newton.empty()) {
        cout << "No root found in the given range.\n";
    } else {
        cout << "Unique roots found:\n";
        for (auto root : roots_newton) {
            cout << root << "\n";
        }
    }

    return 0;
}
