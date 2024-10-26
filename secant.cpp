#include <bits/stdc++.h>
using namespace std;

double a_secant, b_secant, c_secant, d_secant, e_secant;
double f_secant(double x) {
    return a_secant * x * x * x * x + b_secant * x * x * x + c_secant * x * x + d_secant * x + e_secant;
}

void secantSolver(double x1, double x2) {
    double iterations = 0;
    double previous_x = INT_MAX;
    while (true) {
        iterations++;
        double f1 = f_secant(x1);
        double f2 = f_secant(x2);
        double x3 = x2 - (f2 * (x2 - x1)) / (f2 - f1);
        if (f_secant(x3) == 0 || abs(x3 - previous_x) <= 0.00001) {
            cout << "Absolute root: " << x3 << "\n";
            return;
        }
        previous_x = x3;
        x1 = x2;
        x2 = x3;
    }
}

int secant() {
    double key_secant;
    cout << "Choose format: " << endl;
    cout << "1. ax^2 + bx + c" << endl;
    cout << "2. ax^3 + bx^2 + cx + d" << endl;
    cout << "3. ax^4 + bx^3 + cx^2 + dx + e" << endl;
    cout << "Enter a key: ";
    cin >> key_secant;

    if (key_secant == 1) {
        cout << "The format is defined as ax^2 + bx + c." << endl;
        cout << "Now enter values of coefficients a, b, c:\n";
        cin >> c_secant >> d_secant >> e_secant;
        a_secant = 0; b_secant = 0;
    } else if (key_secant == 2) {
        cout << "The format is defined as ax^3 + bx^2 + cx + d." << endl;
        cout << "Now enter values of coefficients a, b, c, d:\n";
        cin >> b_secant >> c_secant >> d_secant >> e_secant;
        a_secant = 0;
    } else if (key_secant == 3) {
        cout << "The format is defined as ax^4 + bx^3 + cx^2 + dx + e." << endl;
        cout << "Now enter values of coefficients a, b, c, d, e:\n";
        cin >> a_secant >> b_secant >> c_secant >> d_secant >> e_secant;
    } else {
        cout << "Invalid key." << endl;
        return 0;
    }

    double range_secant = floor(sqrt(abs(a_secant + b_secant + c_secant + d_secant + e_secant))) + 10;
    vector<pair<double, double>> intervals_secant;
    for (double i = -range_secant; i < range_secant; i += 0.1) {
        if (f_secant(i) * f_secant(i + 0.1) < 0) {
            intervals_secant.push_back({i, i + 0.1});
        }
    }

    if (intervals_secant.empty()) {
        cout << "No roots found in the given range.\n";
    } else {
        for (auto interval : intervals_secant) {
            cout << "Searching root in interval [" << interval.first << ", " << interval.second << "]\n";
            secantSolver(interval.first, interval.second);
        }
    }

    return 0;
}
