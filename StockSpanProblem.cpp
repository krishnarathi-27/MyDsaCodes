#include<bits/stdc++.h>
#include<iostream>

using namespace std;

int main()
{
    vector<int> v;
    stack<pair<int,int> > s;
    int arr[] ={100,80,60,70,60,75,85};

    for(int i=0;i<7;i++)
    {
        if(s.size()==0)         v.push_back(-1);
        else if(s.size() >0 && s.top().first > arr[i])      v.push_back(s.top().second);
        else if(s.size()>0 && s.top().first<= arr[i])
        {
            while(s.size() >0 && s.top().first<=arr[i])
                s.pop();
            if(s.size()==0)         v.push_back(-1);
            else                    v.push_back(s.top().second);
        }
        s.push({arr[i],i});
    }

    for(int i=0;i<v.size();i++)
    {
        v[i] = i-v[i];
        cout << v[i] << " ";
    }
    return 0;
}