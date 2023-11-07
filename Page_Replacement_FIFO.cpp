#include <iostream>
using namespace std;

int main()
{
    int k,f, pf = 0, count = 0, n;
    cout << "\nEnter the length of the reference string -- ";
    cin >> n;
    int rs[25];
    cout << "\nEnter the reference string -- ";
    for (int i = 0; i < n; i++)
        cin >> rs[i];
    cout << "\nEnter the number of frames -- ";
    cin >> f;
    int m[10];
    for (int i = 0; i < f; i++)
        m[i] = -1;
    cout << "\nThe Page Replacement Process is --" << endl;
    for (int i = 0; i < n; i++)
    {
        for (k = 0; k < f; k++)
            if (m[k] == rs[i])
                break;
        if (k == f)
        {
            m[count++] = rs[i];
            pf++;
        }
        for (int j = 0; j < f; j++)
            cout << "\t" << m[j];
        if (k == f)
            cout << "\tPF No. " << pf << endl;
        if (count == f)
            count = 0;
    }
    cout << "\nThe number of Page Faults using FIFO are " << pf << endl;
    return 0;
}
