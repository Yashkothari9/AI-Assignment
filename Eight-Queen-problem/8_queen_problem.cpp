#include<bits/stdc++.h>
struct state
{
    char Q[8][8];
    int cost;
    vector<int> q;

};
void initialize(state s)
{
    for(int i=0;i<8;i++)
    {
        for(int j=0;j<8;j++)
        {
            s.Q[i][j]='_';
        }
    }
    s.cost=0;
    for(int i=0;i<8;i++)
    {
        s.q[i]=-1;
    }
}
int validity(state s)
{

}
int main()
{

}
