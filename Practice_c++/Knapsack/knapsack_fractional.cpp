#include<iostream>
using namespace std;
int main()
{
    int array[2][100], n, w, i, currentWeight, used[100], maxi = -1, T_prof = 0;

    cout << "Enter number of values : ";
    cin >> n;
    cout << "Enter the capacity of the knapsack bag : ";
    cin >> w;
    cout << "Enter the values : ";
    for (i = 0; i < n; i++)
    {
        cin >> array[0][i];
    }
    cout << "Enter the corresponding weights : ";
    for (i = 0; i < n; i++)
    {
        cin >> array[1][i];
    }
    for (i = 0; i < n; i++)
    {
        used[i] = 0;
    }
    currentWeight = w;
    while (currentWeight >= 0)
    {
        maxi = -1;
        for (i = 0; i < n; i++)
        {
            if ((used[i] == 0) && ((maxi == -1) || (((float) array[1][i]
                    / (float) array[0][i]) > ((float) array[1][maxi]
                    / (float) array[0][maxi]))))
            {
                maxi = i;
            }
        }
        used[maxi] = 1;
        //decrease current wight
        currentWeight -= array[0][maxi];
        //increase total profit
        T_prof += array[1][maxi];
        if (currentWeight >= 0)
        {
            cout << "\nAdded object " << maxi + 1 << " Weight: "
                    << array[0][maxi] << " Profit: " << array[1][maxi];
        }
        else
        {
            cout << "\nAdded object " << maxi + 1 << " Weight: "
                    << (array[0][maxi] + currentWeight) << " Profit: "
                    << (array[1][maxi] / array[0][maxi]) * (array[0][maxi]
                            + currentWeight) <<" Weight added is: " << currentWeight + array[0][maxi];
            T_prof -= array[1][maxi];
            T_prof += ((array[1][maxi] / array[0][maxi]) * (array[0][maxi]
                    + currentWeight));
        }
    }
    cout << "\n Profit achieved after 'Knapsack fractional Algo' : " << T_prof;
    return 0;
}