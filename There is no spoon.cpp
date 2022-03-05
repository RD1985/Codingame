#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * Don't let the machines win. You are humanity's last hope...
 **/

int main()
{
    int width; // the number of cells on the X axis
    cin >> width; cin.ignore();
    int height; // the number of cells on the Y axis
    cin >> height; cin.ignore();
    int grid [width][height];
    int widthIndex;
    int heightIndex= 0;
    for (int i = 0; i < height; i++) {
        string line;
        getline(cin, line); // width characters, each either 0 or .
        widthIndex = 0;
        for (int j=0; j < line.length(); j++, widthIndex++)
        {
            if(line[j] == '0')
                grid[widthIndex][heightIndex] = 1;
            else if(line[j] == '.')
                grid[widthIndex][heightIndex] = 0;
        }
        heightIndex++;
    }

    for(int htIndex = 0; htIndex < height; htIndex ++)
    {
        for( int wtIndex = 0; wtIndex < width; wtIndex++)
        {
            if( grid[wtIndex][htIndex])
            {
            cout << wtIndex << " " << htIndex << " ";
            if (wtIndex +1 < width)
            {
                int rightNeighbor = false;
                for( int rightIndex = wtIndex+1; rightIndex < width; rightIndex++)
                {
                    if(grid[rightIndex][htIndex])
                    {
                        cout << rightIndex << " " << htIndex << " ";
                        rightNeighbor = true;
                    }
                    if(rightNeighbor)
                        break;
                }
                if(!rightNeighbor)
                    cout << "-1 -1 ";
            }
            else
            {
                cout << "-1 -1 ";
            }

            if (htIndex +1 < height)
            {
                int bottomNeighbor = false;
                for (int belowIndex = htIndex+1; belowIndex < height; belowIndex++)
                {
                        if (grid[wtIndex][belowIndex])
                        {
                            cout << wtIndex << " " << belowIndex << " ";
                            bottomNeighbor = true;
                        }
                        if (bottomNeighbor)
                            break;
                }
                if (!bottomNeighbor)
                    cout << "-1 -1 ";
            }
            else
            {
                cout << "-1 -1 ";
            }        
            cout << endl;
            }
        }

    }

     // Write an action using cout. DON'T FORGET THE "<< endl"
    // To debug: cerr << "Debug messages..." << endl;


    // Three coordinates: a node, its right neighbor, its bottom neighbor
    //cout << "0 0 1 0 0 1" << endl;
}