#include<bits/stdc++.h>
using namespace std;
#define MAX 100
int main()
{
int n,i,j,m=9999;
cout<<"Divyesh Lahane roll no. 180";
cout<<"\nEnter the number of Nodes\n";
cin>>n;
int matrix[n][n];
cout<<"\nEnter the Matrix elements\n";
for ( i = 0; i < n; i++)
{
for ( j = 0; j < n; j++)
{
cin>>matrix[i][j];
}
}
int arr[n];
cout<<"\nEnter The Heuristics\n";
for ( i = 0; i < n; i++)
{
cin>>arr[i];
}
int start,goal;
cout<<"\nEnter the start node\n";
cin>>start;
cout<<"\nEnter the Goal node\n";
cin>>goal;
int visited[MAX]={0};
int t=0;
visited[start]=1;
int x=start,p=0,y,v,sum=0;
printf("Start State is %c\n",start+65);
printf("Goal state is %c\n",goal+65);
printf("%c ",start+65);
while (x != goal)
{
for ( i = 0; i < n; i++)
{
if (matrix[x][i] !=0 && visited[i] != 1)
{
p = matrix[x][i] + arr[i];
if (m > p)
{
y = matrix[x][i];
m = p;
v = i;
}
}
}
sum += y;
visited[v] = 1;
printf("%c ",v+65);
x = v;
m = 9999;
}
printf("Cost is %d\n",sum);
return 0;
}
