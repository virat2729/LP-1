//Worst Fit
#include <iostream>
using namespace std;

int main()
{
    int frag[25], b[25], f[25], i, j, nb, nf, temp;
    static int bf[25], ff[25];
    cout << "\n\tMemory Management Scheme - Worst Fit" << endl;
    cout << "Enter the number of blocks: ";
    cin >> nb;
    cout << "Enter the number of files: ";
    cin >> nf;
    cout << "\nEnter the size of the blocks:" << endl;
    for (i = 1; i <= nb; i++)
    {
        cout << "Block " << i << ": ";
        cin >> b[i];
    }
    cout << "Enter the size of the files:" << endl;
    for (i = 1; i <= nf; i++)
    {
        cout << "File " << i << ": ";
        cin >> f[i];
    }
    for (i = 1; i <= nf; i++)
    {
        for (j = 1; j <= nb; j++)
        {
            if (bf[j] != 1)
            {
                temp = b[j] - f[i];
                if (temp >= 0)
                {
                    ff[i] = j;
                    break;
                }
            }
        }
        frag[i] = temp;
        bf[ff[i]] = 1;
    }
    cout << "\nFile_no:\tFile_size:\tBlock_no:\tBlock_size:\tFragmentation" << endl;
    for (i = 1; i <= nf; i++) cout<<i<<"\t\t"<<f[i]<<"\t\t"<<ff[i]<<"\t\t"<<b[ff[i]]<<"\t\t"<<frag[i]<<endl;
    return 0;
}

/*
INPUT
Enter the number of blocks: 3
Enter the number of files: 2
Enter the size of the blocks:-
Block 1: 5
Block 2: 2
Block 3: 7
Enter the size of the files:-
File 1: 1
File 2: 4

OUTPUT
File No 	File Size		Block No	Block Size 	Fragment
1 	1 		1 		5 		4
2 	4		 3 		7 		3
*/
