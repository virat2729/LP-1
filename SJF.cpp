#include <iostream>
using namespace std;

void swap(int& a, int& b)
{
    int temp = a;
    a = b;
    b = temp;
}
int main()
{
    int n;
    float wtavg, tatavg;
    cout << "\nEnter the number of processes: ";
    cin >> n;
    int p[n], bt[n], wt[n], tat[n];
    for (int i = 0; i < n; i++)
    {
        p[i] = i;
        cout << "Enter Burst Time for Process " << i << ": ";
        cin >> bt[i];
    }
    for (int i = 0; i < n; i++)
    {
        for (int k = i + 1; k < n; k++)
        {
            if (bt[i] > bt[k])
            {
                swap(bt[i], bt[k]);
                swap(p[i], p[k]);
            }
        }
    }
    wt[0] = wtavg = 0;
    tat[0] = tatavg = bt[0];
    for (int i = 1; i < n; i++)
    {
        wt[i] = wt[i - 1] + bt[i - 1];
        tat[i] = tat[i - 1] + bt[i];
        wtavg += wt[i];
        tatavg += tat[i];
    }
    cout << "\nPROCESS \tBURST TIME \t WAITING TIME\t TURNAROUND TIME";
    for (int i = 0; i < n; i++) cout << "\nP" << p[i] << "\t\t" << bt[i] << "\t\t" << wt[i] << "\t\t" << tat[i];
    cout << "\n\nAverage Waiting Time: " << wtavg / n << endl;
    cout << "Average Turnaround Time: " << tatavg / n << endl << endl;
    return 0;
}
