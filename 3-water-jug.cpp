#include <stdio.h>
#include <stdlib.h>
using namespace std;
struct node
{
int x, y;
struct node *next;
};
struct node *root, *left, *right, *ans;
struct node *getnode()
{
struct node *temp;
temp = (struct node *)malloc(sizeof(struct node));
temp->next = NULL;
return temp;
}
int check(struct node *nextt, int max1, int max2, int g1, int g2)
{
if ((nextt->x == g1) && (nextt->y == g2))
return (0);
if (((nextt->x == max1) && (nextt->y == max2)) || ((nextt->x == 0) && (nextt->y
== 0)))
return (1);
struct node *temp;
temp = left;
while (1)
{
if ((temp->x == nextt->x) && (temp->y == nextt->y))
return (1);
else if (temp->next == NULL)
break;
else
temp = temp->next;
}
temp = right;
while (1){
if ((temp->x == nextt->x) && (temp->y == nextt->y))
return (1);
else if (temp->next == NULL)
break;
temp = temp->next;
}
return (0);
}
struct node *newstate(struct node *curr, int max1, int max2, int g1, int g2)
{
struct node *nextt;
nextt = getnode();
nextt->x = max1;
nextt->y = curr->y;
if (check(nextt, max1, max2, g1, g2) != 1)
return (nextt);
nextt->x = curr->x;
nextt->y = max2;
if (check(nextt, max1, max2, g1, g2) != 1)
return (nextt);
nextt->x = 0;
nextt->y = curr->y;
if (check(nextt, max1, max2, g1, g2) != 1)
return (nextt);
nextt->x = curr->x;
nextt->y = 0;
if (check(nextt, max1, max2, g1, g2) != 1)
return (nextt);
int d;
if ((curr->y < max2) && (curr->x != 0))
{
d = max2 - curr->y;
if (d >= curr->x)
{
nextt->x = 0;
nextt->y = curr->x + curr->y;
}
else
{
nextt->x = curr->x - d;
nextt->y = curr->y + d;
}
if (check(nextt, max1, max2, g1, g2) != 1)
{
return (nextt);
}
}
if ((curr->x < max1) && (curr->y != 0))
{
d = max1 - curr->x;
if (d >= curr->y)
{
nextt->x = curr->x + curr->y;
nextt->y = 0;
}
else
{
nextt->x = curr->x + d;
nextt->y = curr->y - d;
}
if (check(nextt, max1, max2, g1, g2) != 1)
{
return (nextt);
}
}
return (NULL);
}
void tree(int max1, int max2, int g1, int g2)
{
root = getnode();
root->x = root->y = 0;
left = getnode();
left->x = 0;
left->y = max2;
right = getnode();
right->x = max1;
right->y = 0;
struct node *templ, *tempr;
templ = left;
tempr = right;
while (1)
{
if ((templ->x != g1) || (templ->y != g2))
{
templ->next = newstate(templ, max1, max2, g1, g2);
templ = templ->next;
templ->next = NULL;
}
if ((templ->x == g1) && (templ->y == g2))
{
ans = left;
break;
}
if ((tempr->x != g1) || (tempr->y != g2))
{
tempr->next = newstate(tempr, max1, max2, g1, g2);
tempr = tempr->next;
tempr->next = NULL;
}
if ((tempr->x == g1) && (tempr->y == g2))
{
ans = right;
break;
}
}
}
void print()
{
struct node *temp;
temp = ans;
printf("Steps to be followed :\n(%d,%d)\n", root->x, root->y);
while (1)
{
printf("(%d,%d)\n", temp->x, temp->y);
if (temp->next == NULL)
break;
temp = temp->next;
}
}
int main()
{
printf("Name : Divyesh Lahane\nRoll No: 180 \nReg No : 18010293\n");
int max1, max2, g1, g2;
printf("\nEnter maximum capacities of Jug 1 and Jug 2 : ");
scanf("%d%d", &max1, &max2);
printf("\nEnter the goal state : ");
scanf("%d%d", &g1, &g2);
tree(max1, max2, g1, g2);
print();
return 0;
}