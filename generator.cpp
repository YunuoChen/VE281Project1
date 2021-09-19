#include <iostream>
#include <cstdlib>
#include <ctime>
#include <assert.h>
using namespace std;

#define INT_MAX 0x7fffffff

#define INT_MIN 0x80000000

void generateRandomArray(int n, int rangeL, int rangeR) {
	assert(rangeL <= rangeR);
	
	int *arr = new int[n]; 
	
	// srand(time(NULL));
	for (int i = 0; i < n; i++)
    {
	    arr[i] = rand() % (rangeR - rangeL + 1) + rangeL;
        cout << arr[i] << " ";
        // if (i & 1) cout << " ";
        // else cout << endl;
    }
    cout << endl;
    delete[] arr;
	// return arr;
}


int main()
{
    srand((int)time(0));  // 产生随机种子
    // for (int i = 0; i < 10; i++)
    // {
        int len = rand()%100;
        cout << len << endl;
        generateRandomArray(len, -1000, 1000);
    // }
    // while (1)
    // {
    //     generateRandomArray(rand()%1000, -1000, 1000);
    // }
    
    return 0;
}
