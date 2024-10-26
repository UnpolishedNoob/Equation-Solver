#include <bits/stdc++.h>
using namespace std;

double coeff4, coeff3, coeff2, coeff1, coeff0;

double polynomialFunc(double x) {
    return coeff4 * pow(x, 4) + coeff3 * pow(x, 3) + coeff2 * x * x + coeff1 * x + coeff0;
}

void solveFalsePosition(double lower, double upper) {
    double rootEstimate = INT_MAX;
    double previousEstimate;

    while (true) {
        previousEstimate = rootEstimate;
        rootEstimate = (lower * polynomialFunc(upper) - upper * polynomialFunc(lower)) / 
                       (polynomialFunc(upper) - polynomialFunc(lower));
        
        if (polynomialFunc(lower) * polynomialFunc(rootEstimate) < 0) {
            upper = rootEstimate;
        } else {
            lower = rootEstimate;
        }

        if (polynomialFunc(rootEstimate) == 0 || abs(rootEstimate - previousEstimate) < 0.0001) {
            cout << "Root found: " << rootEstimate << "\n";
            return;
        }
    }
}

int false_position() {
    double formatOption;
    cout << "Choose equation format: " << endl;
    cout << "1. ax^2 + bx + c." << endl;
    cout << "2. ax^3 + bx^2 + cx + d." << endl;
    cout << "3. ax^4 + bx^3 + cx^2 + dx + e." << endl;
    cout << "Enter your choice: ";
    cin >> formatOption;

    if (formatOption == 1) {
        cout << "Selected format: ax^2 + bx + c." << endl;
        cout << "Enter coefficients a, b, and c:\n";
        cin >> coeff2 >> coeff1 >> coeff0;
        coeff4 = 0; coeff3 = 0;
    } else if (formatOption == 2) {
        cout << "Selected format: ax^3 + bx^2 + cx + d." << endl;
        cout << "Enter coefficients a, b, c, and d:\n";
        cin >> coeff3 >> coeff2 >> coeff1 >> coeff0;
        coeff4 = 0;
    } else if (formatOption == 3) {
        cout << "Selected format: ax^4 + bx^3 + cx^2 + dx + e." << endl;
        cout << "Enter coefficients a, b, c, d, and e:\n";
        cin >> coeff4 >> coeff3 >> coeff2 >> coeff1 >> coeff0;
    } else {
        cout << "Invalid selection." << endl;
        return 0;
    }

    double rangeLimit = floor(sqrt(abs(coeff4 + coeff3 + coeff2 + coeff1 + coeff0))) + 10;
    vector<pair<double, double>> intervals;
    
    for (double i = -rangeLimit; i < rangeLimit; i += 0.1) {
        if (polynomialFunc(i) * polynomialFunc(i + 0.1) < 0) {
            intervals.push_back({i, i + 0.1});
        }
    }

    if (intervals.empty()) {
        cout << "No roots found in the given range.\n";
    } else {
        for (auto interval : intervals) {
            cout << "Searching for root in interval [" << interval.first << ", " << interval.second << "]\n";
            solveFalsePosition(interval.first, interval.second);
        }
    }

    return 0;
}
