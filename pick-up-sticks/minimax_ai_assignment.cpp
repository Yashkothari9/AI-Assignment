#include<bits/stdc++.h>
using namespace std;
vector<int> memoization(100,0);//this is used to memoize the recursive calls
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
        if(memoization[n]==0){
        for(int j=1;j<4;j++)//going to all possible nodes starting from 3,then 2 and then 1
        { i=4-j;
          if(n>i)
          {
            if(player == 1)
            {
                //cout<<"hi9\n";
                vector<int> arr;
                arr=comp(n-i,2,alpha,beta);//the second parameter denotes the next player to whom the call is  made so it is calling min value
                //cout<<"hi\n";
                if(arr[2]<arr[3])//this is the case when max node recursively calls min node and then it will check whether alpha is smaller than beta if so it will copy the value of alpha
                {
                    alpha=arr[3];
                }
                if(alpha==1 || alpha>beta)
                {
                    break;
                }
            }
            else
            {//this is the min node which we would explore
                vector<int> arr1;
                arr1=comp(n-i,1,alpha,beta);//the second parameter denotes the next player to whom the call is  made so it is calling max value
                if(arr1[2]<arr1[3])//here we are dealing with min node so first we would check whether alpha has lesser value than beta if so we would change the value of beta to alpha
                {
                    beta=arr1[2];//if above condition satisfies then  we have to change the value of beta to alpha
                }
                if(beta == -1 || alpha>beta)
                {
                    break;
                }
            }

          }
        }
        memoization[n]=i;
        }
        else
        {
            i=memoization[n];
        }
         vector<int> man;
        man.push_back(i);
        man.push_back(player);
        man.push_back(alpha);
        man.push_back(beta);
        return man;

    }

}
int main()
{
    cout<<"enter the number of sticks from which the game will be played\n";
    int n;//the number of sticks used to play the game
    cin>>n;
    cout<<"please enter what do you want ? type 'AIvsAI' or 'HumanVsAI'\n";
    string str1;
    cin>>str1;

    if(str1=="HumanVsAI")
    {
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
            if(n==1||n-1==0)
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
            if(n==1||n-1==0)
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
        else if(loss==0)
        {
            cout<<"you have lost the game\n";
        }
    }
    else if(str1=="AIvsAI")
    {
        cout<<"there are two AI players,player1 and player2....\n";
        cout<<"tossing a coin to see who wins....\n";
        int toss;//checks who wins the toss
        toss=rand()%2;
        int winner;
        if(toss==1)
        {
            winner=1;
            cout<<"player 1 won the toss so he plays first....\n";
        }
        else{
            winner=2;
            cout<<"player 2 won the toss so he plays first...\n";
        }
        vector<int> comp1;
        vector<int> comp2;
        int loss=0;
        if(winner==1)
        {
            while(n>0)
            {
                cout<<"-------------------Player 1's turn----------------------\n";
            cout<<"\n";
            cout<<"number of sticks left = "<<n<<"\n";
            cout<<"\n";
            if(n==1 || n-1==0)
            {
                loss=0;
                break;
            }
            comp1=comp(n,1,INT_MIN,INT_MAX);
            cout<<"number of sticks you have picked up = "<<comp1[0]<<"\n";
            n=n-comp1[0];
            cout<<"----------------Player 2's turn--------------------\n";
            cout<<"\n";
            cout<<"number of sticks left = "<<n<<"\n";
            cout<<"\n";
            if(n==1 || n-1==0)
            {
                loss=1;
                break;
            }
           // cout<<"hi5\n";
            comp2=comp(n,1,INT_MIN,INT_MAX);
            //cout<<"hi6\n";
            cout<<"number of sticks computer has picked up-"<<comp2[0]<<"\n";
            n=n-comp2[0];

            }

        }
         else
        {
        while(n>0)
        {
            cout<<"---------------Player's 2 turn----------------------\n";
            cout<<"\n";
            cout<<"number of sticks left -"<<n<<"\n";
            cout<<"\n";
            if(n==1||n-1==0)
            {
                loss=1;
                break;
            }
           // cout<<"hi7\n";
            comp2=comp(n,1,INT_MIN,INT_MAX);
            //cout<<"hi8\n";
            cout<<"number of sticks computer has picked up-"<<comp2[0]<<"\n";
            n=n-comp2[0];
            cout<<"------------------Player's 1 turn--------------------------\n";
            cout<<"\n";
            cout<<"number of sticks left -"<<n<<"\n";
            cout<<"\n";
            if(n==1||n-1==0)
            {
                loss=0;
                break;
            }
            comp1=comp(n,1,INT_MIN,INT_MAX);
            n=n-comp1[0];
             cout<<"number of sticks computer has picked up-"<<comp1[0]<<"\n";
        }
    }
    if(loss==0)
    {
        cout<<"Player 2 won the game\n";
    }
    else{
        cout<<"player 1 won the game\n";
    }

    }
    return 0;
}
