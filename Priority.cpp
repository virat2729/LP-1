//PRIORITY CPU SCHEDULING ALGORITHM
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
    int n, temp;
    float wtavg, tatavg;
    cout << "Enter the number of processes: ";
    cin >> n;
    int p[n], bt[n], pri[n], wt[n], tat[n];
    for (int i = 0; i < n; i++)
    {
        p[i] = i;
        cout << "Enter the Burst Time & Priority of Process " << i << ": ";
        cin >> bt[i] >> pri[i];
    }
    for (int i = 0; i < n; i++)
    {
        for (int k = i + 1; k < n; k++)
        {
            if (pri[i] > pri[k])
            {
                swap(p[i], p[k]);
                swap(bt[i], bt[k]);
                swap(pri[i], pri[k]);
            }
        }
    }
    wtavg = wt[0] = 0;
    tatavg = tat[0] = bt[0];
    for (int i = 1; i < n; i++)
    {
        wt[i] = wt[i - 1] + bt[i - 1];
        tat[i] = tat[i - 1] + bt[i];
        wtavg = wtavg + wt[i];
        tatavg = tatavg + tat[i];
    }
    cout << "\nPROCESS\t\tPRIORITY\tBURST TIME\tWAITING TIME\tTURNAROUND TIME\n";
    for (int i = 0; i < n; i++) cout << p[i] << "\t\t" << pri[i] << "\t\t" << bt[i] << "\t\t" << wt[i] << "\t\t" << tat[i] << endl;\
    cout << "\nAverage Waiting Time is: " << wtavg / n << endl;
    cout << "Average Turnaround Time is: " << tatavg / n << endl;\
    return 0;
}

/*
INPUT
Enter the number of processes -- 5
Enter the Burst Time & Priority of Process 0 --- 10 3
Enter the Burst Time & Priority of Process 1 --- 1 1
Enter the Burst Time & Priority of Process 2 --- 2 4
Enter the Burst Time & Priority of Process 3 --- 1 5
Enter the Burst Time & Priority of Process 4 --- 5 2

OUTPUT
PROCESS PRIORITY BURST TIME WAITING TIME TURNAROUND TIME
1 1 1 0 1
4 2 5 1 6
0 3 10 6 16
2 4 2 16 18
3 5 1 18 19
Average Waiting Time is --- 8.200000
Average Turnaround Time is --- 12.000000
*/
