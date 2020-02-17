#include<bits/stdc++.h>
using namespace std;
int isPresent(vector<int> a,int x)
{
    for(int i=0;i<a.size();i++)
    {
        if(a[i]==x)
        {
            return 1;
        }
    }
    return 0;
}
//this function will be used to sort by compairing the first element of the pair
bool sortbyfirst(const pair<int,int> &a,
			const pair<int,int> &b)
{
	return (a.first < b.first);
}
//DOING USING GREEDY FUNCTION
vector<int> calc_heu(vector<pair<int,int>> ver[],int V)
{
    vector<int> path;//will store the heuristic path i.e the greedy path
    path.push_back(0);
    int min;
    int next=-1;
    int cost=0;//calculating the total heuristics
    int point=0;
    int i=0;
    cout<<"reached\n";
    while(i<V)
    {
        i++;
        min=INT_MAX;
        int loc =-1;//loc will store the minimum weight node
        //here point refers to the current node in which we are currently present and loc will be used to find the next minimum
        //to store the minimum next node
        for(int j=0;j<ver[point].size();j++)
        {
            if(ver[point][j].second<min)
            {
                if(isPresent(path,ver[i][j].first)==0)//checking that if the node has alredy been visited then we wont traverse that path
                {//calculating the minimum heuristic function
                min=ver[point][j].second;
                loc=ver[point][j].first;
                }
                else
                {
                    continue;
                }
            }
        }
        if(loc==-1)//when node has already reached its end and it has to be connected to the first node
        {

            cost = cost + ver[point][0].second;
            break;
        }
        else//when still loc has a definite value, i.e some of the nodes are still left to be visited
        {
            path.push_back(loc);
            cost = cost + ver[point][loc].second;
            point=loc;
        }
    }
    int k=0;
    int ccost=cost;//making an instance of cost
    vector<int> heuristic;//first will initialize the calculated huri
    for(int i=0;i<V;i++)
    {
        heuristic.push_back(0);//intialzing each and every heuristic with 0 initially
    }
    heuristic[path[0]]=ccost;
    for(k=1;k<V;k++)
    {
        ccost=ccost-ver[path[k-1]][k].second;//this represent the total cost - the g(n) function
        heuristic[path[k]]=ccost;
    }
    return heuristic;//returning the vector which consists the heuristic value ,index represents the node at which we are and its value greater
                    //gives us what is the heuristic cost till the goal node
}
void TSP(vector<pair<int,int>> ver[],vector<int> hur,int V,int E)
{
    priority_queue <int, vector<int>, greater<int>> open;//Declaring the open list using min priority_queue
    vector<int> pth;//will store the actual cost
    open.push(hur[0]);
    int i=0;
    int g(n)=0;
    int tot_cost=0;
    int pt=0;//storing the next point that would be choosed after calculating the A* cost
    while(i<V)
    {
        int min=INT_MAX;
        int lo=-1;
        //calculating the f(n)=g(n)+h(n) value of the new node
        for(int j=0;j<ver[pt].size();i++)
        {
            g(n)=ver[pt][j].second;
            int h(n)=
            open.push()
            /*if(min>(hur[ver[pt][j].first]+g(n)))
            {
                min=(hur[ver[pt][j].first]+g(n));
            }*/
        }
    }
}
int main()
{
    int V,E;
    //V-> total no. of vertex
    //E->total no. of edges
    cin>>V>>E;
    pair<int,int> mp;
    vector<pair<int,int>> ver[V];
    //v->the start vertex
    //u->the other vertex to which v is connected
    //w-> weight of that particular edge(u-v)
    int w,u,v;
    for(int i=0;i<E;i++)
    {
        cin>>v>>u>>w;
        ver[v].push_back(make_pair(u,w));
        ver[u].push_back(make_pair(v,w));
    }
    cout<<"done\n";
    //here we are sortin
    for(int i=0;i<V;i++)
    {
        sort(ver[i].begin(),ver[i].end(),sortbyfirst);//sortbyfirst function is used to sort the vector using the first
    }
    vector<int> hur=calc_heu(ver,V);
   // TSP(ver,hur,V,E);
    for(int i=0;i<hur.size();i++)
    {
        cout<<"heuristic of "<<i+1<<"th node is: "<<hur[i]<<"\n";
    }
    return 0;
}