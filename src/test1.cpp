// C++ program to demonstrate how vectors
// can be passed by reference.
#include <bits/stdc++.h>
using namespace std;
  
// The vect is passed by reference and changes
// made here reflect in main()
// void func(vector<int>& vect) { vect.push_back(30); }
  
int main()
{
    char a[10] = { 'C', 'O', 'D', 'E' };
    char b[] = "geeksforgeeks";
 
    string s_a;
		s_a(a);
    // string s_b = convertToString(b);
 
    cout << s_a.size() << endl;
    // cout << s_b << endl;
 
    return 0;
}
