#include <iostream>
#include <math.h>
#include <iomanip>
using namespace std;
const char UP = '1';
const char DOWN = '2';
const char LEFT = '3';
const char RIGHT = '4';
void printArray(int **array)
{
 for (int a = 0; a < 3; a++)
 {
 for (int b = 0; b < 3; b++)
 cout << setw(8) << array[a][b];
 cout << endl;
 }
 cout << endl;
}
// Calculate Heuristic value (Count of elements which are at correct position)
int heuristic(int **start_state, int **goal_state)
{
 int hValue = 0;
 for (int i = 0; i < 3; i++)
 for (int j = 0; j < 3; j++)
 if (start_state[i][j] > 0)
 if (goal_state[i][j] == start_state[i][j])
 hValue++;
 return hValue;
}
// Make Move
void makeMove(int **temp, int move)
{
 int flag = 0;
 for (int i = 0; i < 3; i++)
 {
 for (int j = 0; j < 3; j++)
 {
 if (temp[i][j] == 0)
 {
 if (move == 1)
 {
 temp[i][j] = temp[i - 1][j];
 temp[i - 1][j] = 0;
 flag = 1;
break;
 }
 else if (move == 2)
 {
 temp[i][j] = temp[i + 1][j];
temp[i + 1][j] = 0;
flag = 1;
break;
 }
 else if (move == 3)
 {
 temp[i][j] = temp[i][j - 1];
 temp[i][j - 1] = 0;
 flag = 1;
break;
 }
 else
 {
 temp[i][j] = temp[i][j + 1];
temp[i][j + 1] = 0;
flag = 1;
break;
 }
 }
 }
 if (flag == 1)
 break;
 }
}
int tile_Ordering(int **current_state, int **goal_state, int move)
{
 int **temp = new int *[3]; // allocate an array of 3 int pointers - these represents rows
 for (int i = 0; i < 3; i++)
 {
 temp[i] = new int[3]; // these represents columns
 for (int j = 0; j < 3; j++)
 temp[i][j] = current_state[i][j];
 }
 makeMove(temp, move);
 printArray(temp);
 int hValue = heuristic(temp, goal_state);
 cout << "Current Heuristic value :" << hValue << endl
 << endl;
 for (int i = 0; i < 3; i++)
 delete temp[i];
 delete temp;
 return hValue;
}
// Hill Climbing
void steepestAscentHillClimbing(int **start_state, int **goal_state, int former_move)
{
 int arr[4] = {-1, -1, -1, -1};
 cout << "--------------------------------------------------------------------------------" << endl;
 for (int i = 0; i < 3; i++)
 {
 for (int j = 0; j < 3; j++)
 {
 if (start_state[i][j] == 0)
 {
 if (i > 0 && former_move != 2)
 {
 cout << "Checking child (moving 0 up) " << endl;
 arr[0] = tile_Ordering(start_state, goal_state, 1);
 }
 if (i < 2 && former_move != 1)
 {
 cout << "Checking child (moving 0 down) " << endl;
arr[1] = tile_Ordering(start_state, goal_state, 2);
 }
 if (j > 0 && former_move != 4)
 {
 cout << "Checking child (moving 0 left) " << endl;
arr[2] = tile_Ordering(start_state, goal_state, 3);
 }
 if (j < 2 && former_move != 3)
 {
 cout << "Checking child (moving 0 right) " << endl;
arr[3] = tile_Ordering(start_state, goal_state, 4);
 }
 }
 }
 }
 int localOptimum = -1;
 int index = 0;
 for (int i = 0; i < 4; i++)
 if (arr[i] > localOptimum)
 {
 localOptimum = arr[i];
 index = i + 1;
 }
 cout << "localOptimum = " << localOptimum << endl
 << endl;
 makeMove(start_state, index);
 cout << "Next state = Maximum Heuristic value :" << endl;
 printArray(start_state);
 if (localOptimum == 8)
 {
 cout << "Goal state reached !" << endl;
 return;
 }
 else
 steepestAscentHillClimbing(start_state, goal_state, index);
}
// Main
int main()
{
 int **initial = new int *[3]; // allocate an array of 3 int pointers - these represents rows
 for (int i = 0; i < 3; i++)
 initial[i] = new int[3]; // these represents columns
 int **final = new int *[3]; // allocate an array of 3 int pointers - these represents rows
 for (int i = 0; i < 3; i++)
 final[i] = new int[3]; // these represents columns
 cout << "Name: Divyesh Lahane - B-180"<< "\n";
 int player_Input;
 cout << "Enter initial state - enter 0 for empty position" << endl;
 for (int i = 0; i < 3; i++)
 for (int j = 0; j < 3; j++)
 {
 cout << "Enter input A[" << i << "][" << j << "]" << endl;
 cin >> player_Input;
 initial[i][j] = player_Input;
 }
 cout << "--------------------------------------------------------------------------------" << endl;
 cout << "Enter final state - enter 0 for empty position" << endl;
 for (int i = 0; i < 3; i++)
 for (int j = 0; j < 3; j++)
 {
 cout << "Enter input A[" << i << "][" << j << "]" << endl;
 cin >> player_Input;
 final[i][j] = player_Input;
 }
 cout << "\n---------------------------The initial matrix is-------------------------------\n"
 << endl;
 for (int i = 0; i < 3; i++)
 {
 for (int j = 0; j < 3; j++)
 cout << setw(8) << initial[i][j];
 cout << endl;
 }
 cout << "\n---------------------------The final matrix is--------------------------------\n"
 << endl;
 for (int i = 0; i < 3; i++)
 {
 for (int j = 0; j < 3; j++)
 cout << setw(8) << final[i][j];
 cout << endl;
 }
 cout << "\nHeuristic value = Count of elements which are at correct position.\n";
 cout << "\n--------------------------------------------------------------------------------" << endl;
 cout << "\n--------------------------------------------------------------------------------" << endl;
 cout << "\nCalling Steepest Ascent Hill Climbing function\n"
 << endl;
 steepestAscentHillClimbing(initial, final, 0);
 for (int i = 0; i < 3; i++)
 {
 delete initial[i];
 delete final[i];
 }
 delete initial;
 delete final;
 return 0;
}