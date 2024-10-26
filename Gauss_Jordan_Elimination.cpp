#include <bits/stdc++.h>
using namespace std;

#define t .01
#define max_iteration 1000
void gauss_jordan_elimination()
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

    for (int i = n - 1; i > -1; i--)
    {
        for (int j = i - 1; j > -1; j--)
        {
            double ratio = eqn[j][i] / eqn[i][i];
            for (int k = 0; k <= n; k++)
            {
                eqn[j][k] -= (eqn[i][k] * ratio);
            }
        }
    }

    double ans[n];
    cout<<"SOLUTIONS : "<<endl;
    for (int i = 0; i < n; i++)
    {
        ans[i] = eqn[i][n] / eqn[i][i];
        cout << ans[i] << " ";
    }
    cout << endl;

    // for(int i=0;i<n;i++){
    //     for(int j=0;j<=n;j++){
    //         cout<<eqn[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
}
