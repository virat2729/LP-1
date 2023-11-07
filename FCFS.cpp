#include <iostream>
using namespace std;

int main() {
    int bt[20], wt[20], tat[20], n;
    float wtavg = 0, tatavg = 0;

    cout << "Enter the number of processes: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        cout << "Enter Burst Time for Process " << i + 1 << ": ";
        cin >> bt[i];
        if (bt[i] < 0) {
            cout << "Invalid input. Burst time must be non-negative.\n";
            return 1;
        }
    }

    wt[0] = 0;
    tat[0] = bt[0];

    for (int i = 1; i < n; i++) {
        wt[i] = wt[i - 1] + bt[i - 1];
        tat[i] = tat[i - 1] + bt[i];
        wtavg += wt[i];
        tatavg += tat[i];
    }

    cout << "\nPROCESS\tBURST TIME\tWAITING TIME\tTURNAROUND TIME\n";
    for (int i = 0; i < n; i++) {
        cout << "P" << i + 1 << "\t" << bt[i] << "\t\t" << wt[i] << "\t\t" << tat[i] << endl;
    }

    cout << "Average Waiting Time: " << wtavg / n << endl;
    cout << "Average Turnaround Time: " << tatavg / n << endl;

    return 0;
}



//WT - WAITING TIME
//BT-BURST TIME
//TAT- TURN AROUND TIME
/*Enter the number of processes: 5
Enter Burst Time for Process 1: 2
Enter Burst Time for Process 2: 3
Enter Burst Time for Process 3: 4
Enter Burst Time for Process 4: 5
Enter Burst Time for Process 5: 6

PROCESS BURST TIME      WAITING TIME    TURNAROUND TIME
P1      2               0               2
P2      3               2               5
P3      4               5               9
P4      5               9               14
P5      6               14              20
Average Waiting Time: 6
Average Turnaround Time: 9.6
    */
