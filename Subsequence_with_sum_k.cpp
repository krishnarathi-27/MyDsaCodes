#include<bits/stdc++.h>

using namespace std;

void sumSubsequence(int i,int array[],vector <int> &array1,int sum,int s,int n)
{
    if(i == n)
    {
        if(s==sum)
        {
            cout << "[";
            for(int i : array1)
                cout << i  ; 
            cout << " ]" << endl;
        }
     return;
    }

    array1.push_back(array[i]);
    s+=array[i];
    sumSubsequence(i+1,array,array1,sum,s,n);

    s-=array[i];
    array1.pop_back();

    sumSubsequence(i+1,array,array1,sum,s,n);

}

int main()
{
    int n;
    cout << "Enter the number of elements in the array " << endl;
    cin >> n;

    int array[n],sum;
    cout << "Enter the array elements :- " << endl;

    for(int i=0;i<n;i++)
     cin >> array[i];

    cout << "Enter the sum " << endl;
    cin >> sum;

    vector <int> array1;
    sumSubsequence(0,array,array1,sum,0,n);

    return 0;

}