#include <QCoreApplication>
#include <stdlib.h>
#include <iostream>
#include "index.h"

using namespace std;

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    int i, j, k;

    int map[PointNum][PointNum] = {0};

    map[A][B] = 12;
    map[A][C] = map[A][D] = map[A][E] = INF;
    map[A][F] = 16;
    map[A][G] = 14;

    map[B][C] = 10;
    map[B][D] = map[B][E] = map[B][G] = INF;
    map[B][F] = 7;

    map[C][D] = 3;
    map[C][E] = 5;
    map[C][F] = 6;
    map[C][G] = INF;

    map[D][E] = 4;
    map[D][F] = map[D][G] = INF;

    map[E][F] = 2;
    map[E][G] = 8;

    map[F][G] = 9;

    for(i = 1; i < PointNum; i++)
    {
        for(j = 0; j < i; j++)
            map[i][j] = map[j][i];
    }

    for(k = 0; k < PointNum; k++)
    {
        for(i = 0; i < PointNum; i++)
            for(j = 0; j < PointNum; j++)
            {
                if(map[i][k] + map[k][j] < map[i][j])
                    map[i][j] = map[i][k] + map[k][j];
            }
    }

    for(i = 0; i < PointNum; i++)
    {
        cout << char('A' + V) << "," << char('A' + i) << " ";
        cout << map[V][i] << endl;
    }



    return 0;
}
