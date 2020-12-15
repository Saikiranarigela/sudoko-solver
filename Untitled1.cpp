#include<bits/stdc++.h>
using namespace std;
int N;
bool issafe(vector< vector<int> >grid,int row,int col,int num)
{
	for(int i=0;i<N;i++)
	{
		if(grid[i][col]==num||grid[row][i]==num)
		return false;
		
	}
	int s=sqrt(N);
	int rs=row-(row%s);
	int cs=col-(col%s);
	for(int i=rs;i<=row;i++)
	{
		for(int j=cs;j<=col;j++)
		{
			if(grid[i][j]==num)
			return false;
		}
	}
	return true;
}
bool solve(vector< vector<int> > &grid)
{
	int col=-1;
	int row=-1;
	bool isempty=true;
	for(int i=0;i<N;i++)
	{
		for(int j=0;j<N;j++)
		{
			if(grid[i][j]==0)
			{
				isempty=false;
				col=j;
				row=i;
				break;
			}
		}
	}
	if(isempty==true)
	return true;
	for(int num=1;num<=N;num++)
	{
		if(issafe(grid,row,col,num))
		{
			grid[row][col]=num;
			if(solve(grid))
			return true;
			else
			grid[row][col]=0;
		}
		
	}
	return false;
}
int main()
{
	vector< vector<int> >grid;
	cout<<"enter the puzzle size : "<<endl;
	int x;
	cin>>x;
	N=x;
	if(ceil(sqrt(N))==floor(sqrt(N)))
	{    cout<<"if the value is to be find in grid enter zero "<<endl;
	     for(int i=0;i<N;i++)
	    {    vector<int>v;
	        cout<<endl<<" enter the values in "<<i+1<<" th row  "<<endl;
	    	for(int j=0;j<N;j++)
	    	{   int data;
	    		cin>>data;
	    		v.push_back(data);
			}
			grid.push_back(v);
		}
	  
     if(solve(grid))
     { cout<<" solution of the puzzle is : "<<endl;
	   for(int i=0;i<N;i++)
	 {
		for(int j=0;j<N;j++)
		{
			cout<<grid[i][j]<<" ";
		}
		cout<<endl;
	}
   }
   else
    cout<<"slution does not exist"<<endl;
    }
    else
    cout<<"puzzle size is not valid .";
    } 
