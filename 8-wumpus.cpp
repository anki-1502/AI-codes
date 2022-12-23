#include <bits/stdc++.h>
using namespace std;
int main()
{
cout<<"Divyesh Lahane roll no:180";
// Credentials
cout << "Wumpus World Problem Implementation" << endl;
// Opening of the Program
srand(time(0));
cout << "============================" << endl;
cout << "|| WUMPUS WORLD PROBLEM ||" << endl;
cout << "============================" << endl;
// Construction of Environment using 3-D array.
// 4,4 is for the Matrix Space
// 7 is for the Multiple Flags of the Cell
int prepositional[4][4][7];
for (int i = 0; i < 4; i++)
{
for (int j = 0; j < 4; j++)
{
for (int k = 0; k < 7; k++)
{
prepositional[i][j][k] = 0;
}
}
}
prepositional[0][0][5] = 1;
prepositional[0][0][6] = 1;
// Take the user input of the Location of Wumpus
// Allot the Strench of the Flags
cout << "Enter the Location of Wumpus: " << endl;
int wumpus;
cin >> wumpus;
int w_r = wumpus / 4;
int w_c = wumpus % 4 - 1;
prepositional[w_r][w_c][1] = 1;
prepositional[w_r + 1][w_c][4] = 1;
prepositional[w_r - 1][w_c][4] = 1;
prepositional[w_r][w_c + 1][4] = 1;
prepositional[w_r][w_c - 1][4] = 1;
// Randomly Allot the Position of Gold in the Environment
// Set the Gold flag of the Cell
int gold = 0;
while (gold == 0 || gold == wumpus)
{
gold = (rand() % 16) + 1;
}
cout << "Location of Gold: " << gold << endl;
int g_r = gold / 4;
int g_c = gold % 4 - 1;
prepositional[g_r][g_c][0] = 1;
// Randomly Allot the No of Pits.
int no_of_pits = 0;
while (no_of_pits == 0)
{
srand(time(0));
no_of_pits = (rand() % 3) + 1;
}
cout << "No. of Pits: " << no_of_pits << endl;
// Randomly Allot the Position of the No of Pits
// Allot the Position of the Breeze in cells
// Also Set the Breeze and the Pit Flags
for (int i = 0; i < no_of_pits; i++)
{
int pit_loc = 1;
while (pit_loc == 1 || pit_loc == gold || pit_loc == wumpus || prepositional[pit_loc /
4][pit_loc % 4 - 1][2] == 1)
{
srand(time(0));
pit_loc = (rand() % 16) + 1;
}
cout << "Location of pit is: " << pit_loc << endl;
int p_r = pit_loc / 4;
int p_c = pit_loc % 4 - 1;
prepositional[p_r][p_c][2] = 1;
prepositional[p_r - 1][p_c][3] = 1;
prepositional[p_r + 1][p_c][3] = 1;
prepositional[p_r][p_c - 1][3] = 1;
prepositional[p_r][p_c + 1][3] = 1;
}
// Set the OK flag for the rest of the Cells
for (int i = 0; i < 4; i++)
{
for (int j = 0; j < 4; j++)
{
if (prepositional[i][j][1] == 1 || prepositional[i][j][2] == 1)
{
prepositional[i][j][5] = 0;
}
else
{
prepositional[i][j][5] = 1;
}
}
}
// Agent Function begins from here
cout << "Agent is at tile 1" << endl;
int score = 0;
int health = 1000;
int position = 1;
int arrow = 1;
int possible_moves[4];
// Agent steps
while (health > 0 && score != 1000)
{
// Assignment of all the Possible Moves
possible_moves[0] = position + 1;
possible_moves[1] = position - 1;
possible_moves[2] = position + 4;
possible_moves[3] = position - 4;
cout << "Possible Moves for the Agent:" << endl;
for (int i = 0; i < 4; i++)
{
if (possible_moves[i] > 0 && possible_moves[i] < 17)
{
cout << possible_moves[i] << " ";
}
}
cout << endl;
// Agent Chooses Randomly the Next Move
cout << "Agent Chooses the : " << endl;
int new_position;
int itr;
srand(time(NULL));
itr = rand() % 4;
while (possible_moves[itr] < 0 || possible_moves[itr] > 16)
{
srand(time(NULL));
itr = rand() % 4;
}
new_position = possible_moves[itr];
cout << new_position << endl;
position = new_position;
int row = position / 4;
int col = position % 4 - 1;
// Agent Finds Gold
if (prepositional[row][col][0] == 1)
{
cout << "Agent gets the Gold" << endl;
score += 1000;
break;
}
// Agent Falls in Pit
if (prepositional[row][col][2] == 1)
{
cout << "This is the Pit. Agent Falls in the Pit and dies" << endl;
health -= 1000;
break;
}
// Agent Meets the Wumpus
if (prepositional[row][col][1] == 1)
{
cout << "The Agent Faces the Wumpus" << endl;
cout << "Agent has an arrow and he uses against the Wumpus" << endl;
int hit;
srand(time(NULL));
hit = rand() % 2;
if (hit == 0)
{
cout << "Agent Misses the target and wumpus kills the agent" << endl;
health -= 1000;
break;
}
else
{
cout << "Agents hits the wumpus and killed it and hears a loud scream of wumpus" <<
endl;
prepositional[row][col][1] == 0;
}
arrow = 0;
health -= 10;
}
// Agent Feels the Breeze
if (prepositional[row][col][3] == 1)
{
cout << "The Agent Feels Breeze. Pit is near to this Position" << endl;
}
// Agent Feels the Strench
if (prepositional[row][col][4] == 1 && prepositional[row][col][1] == 1)
{
cout << "The Agent Feels Strench. Wumpus is near to this Position" << endl;
}
// Decrement of health per step
health--;
cout << endl;
}
// Output of the Code
cout << "Score of the Agent is : " << score << endl;
cout << "Health of the Agent is : " << health << endl;
cout << "Arrow left with agent is :" << arrow << endl;
if (score >= 1)
{
cout << "The Agent has successfully won the game" << endl;
}
else if (health <= 0)
{
cout << "The Agent has died and lost the game" << endl;
}
return 0;
}