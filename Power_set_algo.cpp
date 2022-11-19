//using bits manipulation

#include<bits/stdc++.h>

using namespace std;

void printSubsequence(string str){

    int n = str.size();
    string sub = " ";

    for(int i=0;i<(1<<n);i++)
    {
        sub = " ";
            for(int j=0;j<n;j++)
            {
                if( i & (1<<j))
                sub += str[j];
            }
        cout << "[" << sub << " ]" << endl;
    }
}

//using backtracking recursion
void printSubsequence1(int i,string str,string &str1){

   if(i == str.size())
   {
     cout << "[" << str1 << " ]" << endl;
     return;
   }

   str1 += str[i];
   printSubsequence1(i+1,str,str1);

   str1.pop_back();
   printSubsequence1(i+1,str,str1);

}
int main()
{
    string str,str1=" ";

    cout << "Enter the string " << endl;
    cin >> str;

   printSubsequence(str);

   printSubsequence1(0,str,str1);
    return 0;
}