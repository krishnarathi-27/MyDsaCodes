

#include<iostream>
#include<algorithm>
using namespace std;

class Array 
{
    int a[10],n,k;

    public:

    Array();
    int BinSearch ();
    void show();
   //`Array();
    
};

Array :: Array()
{
    cout << "Enter the number of elements in the array " << endl;
    cin >> n;

    cout << "Enter the elements of the array " << endl;
    for(int i=0;i<n;i++)
    cin >> a[i];

    cout << "Enter the element you want to search " << endl;
    cin >> k;
}

int Array :: BinSearch()
{
    int l,mid,h;
    l=0;
    h=n-1;
   
    sort(a,a+n);
    while(l<=h)
    {
        mid = (l+h)/2;

        if(k==a[mid]) 
            return mid;
        
        else if(k>a[mid])
            l=mid+1;

        else 
            h=mid-1;
    }
    return -1;
}

void Array :: show()
{

    int result ;
   result = BinSearch( );
   cout<<result<<endl;
    if(result != -1)
    cout << "Element  found " << result << endl;

    else 
     cout << "Element not found succesfully " << endl;

}

int main()
{
    Array A;

    A.show();

    return 0;
}