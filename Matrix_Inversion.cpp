#include <bits/stdc++.h>
using namespace std;

#define t .01
#define max_iteration 1000
void inverse_matrix()
{
    int n;
    cout << "Dimension of square matrix (can be any) : ";
    cin >> n;
    vector<vector<double>> eqn;
    for (int i = 0; i < n; i++)
    {
        int c = n;
        vector<double> take;
        while (c--)
        {
            double a;
            cin >> a;
            take.push_back(a);
        }
        for(int j=0;j<n;j++){
            if(j==i){take.push_back(1);}
            else{take.push_back(0);}
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
            for (int k = 0; k <n+n; k++)
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
            for (int k = 0; k <n+n; k++)
            {
                eqn[j][k] -= (eqn[i][k] * ratio);
            }
        }
    }

    for (int i = 0; i < n; i++) {
        double divisor = eqn[i][i];
        for (int j = 0; j < 2 * n; j++) {
            eqn[i][j] /= divisor;
        }
    }


    for(int i=0;i<n;i++){
        for(int j=n;j<n+n;j++){
            cout<<eqn[i][j]<<" ";
        }
        cout<<endl;
    }
}

int main()
{
    inverse_matrix();
}