#include<bits/stdc++.h>
using namespace std;
vector<int> comp(int n,int player,int alpha,int beta)
{
    if(n==1 && player==1)
    {
        //cout<<"hi2\n";
        vector<int> ap1;//ap1[0]=no. of sticks,ap1[1]=players,ap[2]=alpha,ap1[3]=beta
        ap1.push_back(1);
        ap1.push_back(1);
        ap1.push_back(-1);
        ap1.push_back(beta);
        return ap1;
    }
    else if(n==1 && player==2)
    {
        //cout<<"hi3\n";
        vector<int> ap2;
        ap2.push_back(1);
        ap2.push_back(2);
        ap2.push_back(alpha);
        ap2.push_back(1);
        return ap2;
    }
    else
    {int i;
        for(int j=1;j<4;j++)
        { i=4-j;
          if(n>i)
          {
            if(player == 1)
            {
                //cout<<"hi9\n";
                vector<int> arr;
                arr=comp(n-i,2,alpha,beta);
                //cout<<"hi\n";
                if(arr[2]<arr[3])
                {
                    alpha=arr[3];
                }
                if(alpha==1 || alpha>beta)
                {
                    break;
                }
            }
            else
            {//cout<<"hi1\n";
                vector<int> arr1;
                arr1=comp(n-i,1,alpha,beta);
                if(arr1[2]<arr1[3])
                {
                    beta=arr1[2];
                }
                if(beta == -1 || alpha>beta)
                {
                    break;
                }
            }

          }
        vector<int> man;
        man.push_back(i);
        man.push_back(player);
        man.push_back(alpha);
        man.push_back(beta);
        return man;
        }

    }

}
int main()
{
    cout<<"enter the number of sticks from which the game will be played\n";
    int n;//the number of sticks used to play the game
    cin>>n;
    cout<<"lets have toss for who would play the first chance\n";
    cout<<"enter heads or tails\n";
    string s;
    cin>>s;
    int toss;//checks who wins the toss
    toss=rand()%2;
    string winner;//will record whether it is head or tail
    if(toss==1)
    {
        winner="heads";
    }
    else
    {
        winner="tails";
    }
    vector<int> computer;//computer's input
    int human;//the input that human/user will give
    int loss;//if loss =0 the human has lost otherwise if loss=1 computer has lost
    if(winner==s)
    {
        while(n>0)
        {
            cout<<"-------------------your turn----------------------\n";
            cout<<"\n";
            cout<<"number of sticks left = "<<n<<"\n";
            cout<<"\n";
            if(n==1 || n-1==0)
            {
                loss=0;
                break;
            }
            cout<<"enter the number of sticks from 1 to 3 you want to pick up\n";
            cin>>human;
            cout<<"number of sticks you have picked up = "<<human<<"\n";
            n=n-human;
            cout<<"----------------computer's turn--------------------\n";
            cout<<"\n";
            cout<<"number of sticks left = "<<n<<"\n";
            cout<<"\n";
            if(n==1 || n-1==0)
            {
                loss=1;
                break;
            }
           // cout<<"hi5\n";
            computer=comp(n,1,INT_MIN,INT_MAX);
            //cout<<"hi6\n";
            cout<<"number of sticks computer has picked up-"<<computer[0]<<"\n";
            n=n-computer[0];

        }

    }
    else
    {
        while(n>0)
        {
            cout<<"---------------computer's turn----------------------\n";
            cout<<"\n";
            cout<<"number of sticks left -"<<n<<"\n";
            cout<<"\n";
            if(n==1)
            {
                loss=1;
                break;
            }
           // cout<<"hi7\n";
            computer=comp(n,1,INT_MIN,INT_MAX);
            //cout<<"hi8\n";
            cout<<"number of sticks computer has picked up-"<<computer[0]<<"\n";
            n=n-computer[0];
            cout<<"------------------your turn--------------------------\n";
            cout<<"\n";
            cout<<"number of sticks left -"<<n<<"\n";
            cout<<"\n";
            if(n==1)
            {
                loss=0;
                break;
            }
            cout<<"enter the number of sticks from 1 to 3 you want to pick up\n";
            cin>>human;
            n=n-human;
        }
    }
        if(loss==1)
        {
            cout<<"you have won the game\n";
        }
        else
        {
            cout<<"you have lost the game\n";
        }

    return 0;
}
