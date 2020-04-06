#include<bits/stdc++.h>
using namespace std;
struct stu_avg
{
    int id;
    int marks[5];
    double avg;
};
int main()
{
    cout<<"enter no. of students n \n";
    int n,k;
    cin>>n;
    cout<<"enter value of k for dividing students in k groups";
    cin>>k;
    stu_avg s[n];
    for(int i=0;i<n;i++)
    {
        s[i].id=i+1;
        cout<<"For "<<i+1<<" Student enter the marks in five subjects\n";
        for(int j=0;j<5;j++)
        {
            cin>>s[i].marks[j];
        }
        int sum=0;
        for(int j=0;j<5;j++)
        {
            sum+=s[i].marks[j];
        }
        s[i].avg=((float)(sum)/5);
    }
    int chromomsome[n];
    s

    return 0;
}
