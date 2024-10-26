#include <bits/stdc++.h>
using namespace std;

#define t .01
#define max_iteration 1000
void gauss_elimination()
{
   
    int n;
    cout << "Equation number (can be any) : ";
    cin >> n;
     cout<<endl<<"Input format : ax +by + cz... ... = z"<<endl;
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

    for (int i = 0; i < n; i++)
    {
        if (eqn[i][i] == 0)
        {
            cout << "ERROR" << endl;
            return;
        }
        for (int j = i + 1; j < n; j++)
        {
            double ratio = eqn[j][i] / eqn[i][i];
            for (int k = 0; k <= n; k++)
            {
                eqn[j][k] -= (ratio * eqn[i][k]);
            }
        }
    }

    double ans[n];
    ans[n - 1] = eqn[n - 1][n] / eqn[n - 1][n - 1];

    for (int i = n - 2; i > -1; i--)
    {
        ans[i] = eqn[i][n];
        for (int k = i + 1; k < n; k++)
        {
            ans[i] -= (eqn[i][k] * ans[k]);
        }
        ans[i] /= eqn[i][i];
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            cout << eqn[i][j] << " ";
        }
        cout << endl;
    }
    cout<<"SOLUTIONS : "<<endl;
    for (int i = 0; i < n; i++)
    {
        cout << ans[i] << " ";
    }
    cout << endl;
}

