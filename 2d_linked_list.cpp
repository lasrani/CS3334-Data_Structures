#include <iostream>
using namespace std;

class Linked
{
public:
    int value;
    Linked *nextx;
    Linked *nexty;
};

int main()
{
    int rowSize, colSize;
    rowSize = 3;
    colSize = 3;
    Linked *head = new Linked;
    Linked *n = head;
    Linked *temp = n;
    Linked *tempup = head;
    for (int i = 0; i < rowSize; i++)
    {
        for (int j = 0; j < colSize; j++)
        {
            if (j == (colSize - 1))
            {
                n->nextx = NULL;
                continue;
            }
            n->value = j;
            n = new Linked;
            temp->nextx = n;
            if (i > 0)
            {
                tempup->nexty = temp;
                tempup = tempup->nextx;
            }
            temp = n;
        }
    }
    return 0;
}