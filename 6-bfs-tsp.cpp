#include <bits/stdc++.h>
using namespace std;
#define V 4
int cost = 0;
int start = 0, goal = 0;
vector<int> visited;
int graph[][V] = {
  {0,11,16,21},
 {21,0,36,36},
 {26,36,0,31},
 {21,26,31,0}
 };
void calculate_cost()
{
 for(int i=0;i<visited.size();i++)
 {
 cost = cost +
graph[visited[i]][visited[i+1]];
 }
 cout<<"cost = "<<cost;
}
void best_first_search()
{
 int i,m;
 vector< pair<int,int> > straight_distance;

straight_distance.push_back(make_pair(1,6));

straight_distance.push_back(make_pair(2,4));

straight_distance.push_back(make_pair(3,2));
 cout<<"Straight distance from starting node A "<<endl;
 for(int i = 0; i < straight_distance.size();i++)
 {
 printf("%c = %d\n",straight_distance[i].first+65,straight_distance[i].second);
 }
 int size=straight_distance.size();
 visited.push_back(start);
 printf("%c-->",start+65);
 while(size--)
 {
 int saveIndex = 0;
 for(int i = 1; i <
straight_distance.size();i++)
 {
 if(straight_distance[saveIndex].second
> straight_distance[i].second)
 {
 saveIndex = i;
 }
 }
 int smallestValue = straight_distance[saveIndex].second;
 for(int i = 0; i <straight_distance.size();i++)
 {
 if(straight_distance[i].second == smallestValue)
 {

visited.push_back(straight_distance[i].first);
 printf("%c-->",straight_distance[i].first+65);

straight_distance.erase(straight_distance.begin() + saveIndex);
 }
 }
 }
 visited.push_back(goal);
 printf("%c\n",goal+65);
}
int main()
{
 int n = 4,i,j;
 cout<<"Name - Divyesh Lahane\nReg. No -19010872"<<endl<<endl<<endl;
 cout<<"ALL THE CITIES ARE:A,B,C,D"<<endl<<"Cost :"<<endl;
 for(i=0;i<4;i++)
 {
 for(j=0;j<4;j++)
 {
    printf("%c ->%c =%d\n",i+65,j+65,graph[i][j]);
 }
 printf("\n");
 }
 cout<<"PATH"<<endl;
 best_first_search();
 calculate_cost();
 return 0;
}