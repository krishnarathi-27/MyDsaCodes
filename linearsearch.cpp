#include<iostream>

using namespace std;

int search(int a[],int key,int n)
{
    for(int j=0;j<n;j++)
    {
        if(a[j] == key )
        return j;
    }

return -1;
    
}

int main()
{
    int array[10],key,n,i;

    cout << "Enter the number of elements : " << endl;
    cin >> n;

    cout << "Enter the elements : ";
    for(i=0;i<n;i++)
    {
        cin >> array[i];
    }

    for(i=0;i<n;i++)
    {
        cout << array[i] << endl;
    }

    cout << "Enter the number you want to search in the array : " << endl;
    cin >> key;

    int s=search(array,key,n);

    if(s== -1 )
    cout << "Element not found in the array " << endl;
    else 
    
    cout << "Element found in the array at position " << s << endl;
    

    return 0; 
}