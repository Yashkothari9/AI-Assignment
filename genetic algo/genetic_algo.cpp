#include<bits/stdc++.h>
using namespace std;
vector<double> avg_marks_of_stu;
int tot_groups;
vector<double> average(vector<vector<int>> stu_marks)
{
    vector<double> avg_marks(stu_marks.size(),0.0);
    for(int i=0;i<stu_marks.size();i++)
    {
        int tot=0;
        double avg;
        int siz=stu_marks[i].size();
        for(int j=0;j<stu_marks[i].size();j++)
        {
            tot+=stu_marks[i][j];
        }
        avg=(double)(tot/siz);
        avg_marks[i]=avg;
    }
    return avg_marks;
}
double fitness_func(vector<int> vec)
{
    int siz=vec.size();
    double fitness_val=0;
    vector<int> tot_marks_of_group(tot_groups,0);
    vector<double> avg_marks_of_grp(tot_groups,0);
    vector<int> cnt(tot_groups,0);
    for(int i=0;i<siz;i++)
    {
      tot_marks_of_group[vec[i]]+=avg_marks_of_stu[i];//calculating the total avg marks of the students of the group by calculating the sum of avg marks of the student
      cnt[i]++;
    }
    for(int i=0;i<tot_groups;i++)
    {
        avg_marks_of_grp[i]=((tot_marks_of_group[i])/cnt[i]);//avg marks in the group
    }
    for(int i=0;i<siz;i++)
    {
      fitness_val+=((avg_marks_of_grp[vec[i]]-avg_marks_of_stu[i])*(avg_marks_of_grp[vec[i]]-avg_marks_of_stu[i]));
      //using square value of the ith student's average marks ang the average marks of the group to find the fitness function
    }
    return fitness_val;
}

bool fitness_comparison(vector<int> a,vector<int> b)
{
    return fitness_func(a)<fitness_func(b);//sorting in an ascending fitness value
}

vector<vector<int>> sort_acc_fitness(vector<vector<int>> init)
{
    sort(init.begin(),init.end(),fitness_comparison);
    return init;
}


vector<vector<int>> initial_pop(int n,int k,int initial_pop_given)
{
    vector<vector<int>> init(initial_pop_given,vector<int>(n));
    vector<int> grp_sz(k,0);
    for(int j=0;j<initial_pop_given;j++)
    {
        for(int l=0;l<initial_pop_given;l++)
        {
            init[j][l]=rand()%k;//here we are randomly assigning each one to a random group
        }
        //there might be a possibility that some one might not have been assigned any group for that we are assigning some one atelast a particular group
        int f=rand()%n;
        for(int l=0;l<k;l++)
        {
            init[j][(l+f)%n]=l;//this will make sure that atleat one student is there is a group;
        }
    }
    return sort_acc_fitness(init);
}
void print_population(string s,vector<vector<int>> init)
{
    cout<<s<<"\n";
    for(int i=0;i<init.size();i++)
    {
        for(int j=0;j<init[i].size();j++)
        {
            cout<<init[i][j]<<" ";
        }cout<<"\n";
    }
}
vector<vector<int>> crossover(vector<vector<int>> population)
{
    int n=population.size();
    int m=population[0].size();
    vector<vector<int>> crossover_pop(population.size(),vector<int>(population[0].size()));
    int pos=rand()%(m);
    for(int i=0;i<n;i+=2)//here we are skipping 2 values because we will take 2 population and switch the groups between them
    {
        if(i+1<n){
        for(int j=0;j<m;j++)
        {
            if(j<=pos)
            {
                crossover_pop[i][j]=population[i+1][j];
                crossover_pop[i+1][j]=population[i][j];
            }
            else
            {
                crossover_pop[i][j]=population[i][j];
                crossover_pop[i+1][j]=population[i+1][j];
            }
        }
        }
        else{
            crossover_pop[i]=population[i];
        }
    }
     return sort_acc_fitness(crossover_pop);
}

vector<vector<int>> mutation(vector<vector<int>> pop)
{
    //here we are randomly mutating within the population
     int population_size=pop.size();
     int no_of_stu=pop[0].size();
     int randm=rand()%population_size;
     for(int i=0;i<randm;i++)
     {
         int pop_idx=rand()%population_size;
         int a=rand()%no_of_stu;
         int b=rand()%no_of_stu;
         int temp=pop[pop_idx][a];
         pop[pop_idx][a]=pop[pop_idx][b];
         pop[pop_idx][b]=temp;
     }
     return sort_acc_fitness(pop);
}


int main()
{
    cout<<"enter no. of students n \n";
    int n,k;
    cin>>n;//no. of students
    cout<<"enter value of k for dividing students in k groups";
    cin>>k;//no. of groups
    tot_groups=k;
    int no_of_subjects;
    cout<<"enter number of subjects you will take\n";
    cin>>no_of_subjects;
    vector<vector<int>> stu_marks(n,vector<int>(no_of_subjects));
    for(int i=0;i<n;i++)
    {
       cout<<"enter the marks of "<<no_of_subjects<<" subjects of Student no. "<<i+1<<"\n";
       for(int k=0;k<no_of_subjects;k++)
       {
         cin>>stu_marks[i][k];
       }
    }
    vector<double> avg_marks(n,0);
    avg_marks=average(stu_marks);
    avg_marks_of_stu=avg_marks;

    vector<vector<int>> init_population;
    init_population=initial_pop(n,k,5);//initially iam assigning the population of the group to 5

    print_population("Initial_Population: ",init_population);
    //now doing crossover between the populations
    vector<vector<int>> crossover_pop;
    crossover_pop=crossover(init_population);

    print_population("after 1st crossover-",crossover_pop);

    int stopper=0;
    int generation=1;//this will signify how many generations(i.e how many crossover/
    while(1)
    {
        generation++;
        for(int i=0;i<crossover_pop.size();i++)
        {
            int less=0;
            for(int j=0;j<init_population.size();j++)
            {
                if(fitness_func(crossover_pop[i])<fitness_func(init_population[j]))//when the crossover is done and compared with the other functions then we check that if it has improves i.e the value of fitness function has reduced then it's working fine otherwise it isn't working fine
                {
                    less=1;
                    stopper=0;
                    init_population.pop_back();
                    init_population.push_back(crossover_pop[i]);
                    init_population=sort_acc_fitness(init_population);
                    break;
                }
            }
            if(less==0)
            {
                if(i==0)
                {
                    stopper++;
                }
                break;
            }
        }
        if(stopper>10)
        {
                break;//this is the condition when no goos population is generated wven after crossover's and mutations
        }
        if(rand()%3)
        {
            init_population=mutation(init_population);
        }
        crossover_pop=crossover(crossover_pop);
    }
    cout<<"the average marks of the students--\n";
    for(int i=0;i<avg_marks.size();i++)
    {
        cout<<avg_marks[i]<<" ";
    }cout<<"\n";

    print_population("THE FINAL POPULATION",init_population);

    cout<<"therefore the fitness value of each population in the final populations are as follows-\n";
    for(int i=0;i<init_population.size();i++)
    {
        cout<<fitness_func(init_population[i])<<" ";
    }
    cout<<"\n";
    cout<<"Total no. of generations :"<<generation<<"\n";

    return 0;
}
