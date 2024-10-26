#include <bits/stdc++.h>
using namespace std;

#define t .01
#define max_iteration 1000
void jacobi()
{
    int n;
    cout << "Equation number (can be any) : ";
    cin >> n;
    vector<vector<double>> eqn;
    for (int i = 0; i < n; i++)
    {
        int c = n + 1;
        vector<double> take;
        while (c--)
        {
            double a;
            cin >> a;
            take.push_back(a);
        }
        eqn.push_back(take);
    }
    double x[n] = {0}, x1[n] = {0};
    bool e;
    int iteration = 0;
    do
    {
        e = false;
        for (int i = 0; i < n; i++)
        {
            double sum = 0;
            for (int j = 0; j < n; j++)
            {
                if (i != j)
                {
                    sum += (eqn[i][j] * x[j]);
                }
            }
            x1[i] = (eqn[i][n] - sum) / eqn[i][i];
        }
        for (int i = 0; i < n; i++)
        {
            e = e || abs(x[i] - x1[i]) > t;
            x[i] = x1[i];
        }
        iteration++;
        if (iteration > max_iteration)
        {
            cout << "ERROR" << endl;
            return;
        }
    } while (e);
    for (int i = 0; i < n; i++)
    {
        cout << x[i] << " ";
    }
    cout << endl;
}

int main()
{
    jacobi();
}