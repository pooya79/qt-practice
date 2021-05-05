#include "hexboard.h"
#include "game.h"

extern Game* game;

HexBoard::HexBoard()
{
}

QList<Hex*> HexBoard::getHexes()
{
    return hexes;
}

void HexBoard::placeHexes(int x, int y, int cols, int rows)
{
    int X_SHIFT = 82;
    int Y_SHIFT = 41;

    for (size_t i = 0, n = cols; i < n; i++)
    {
        createHexColumn(x+X_SHIFT*i, y+Y_SHIFT*(i%2), rows);
    }
}

void HexBoard::createHexColumn(int x, int y, int numOfRows)
{
    // create a column of Hexes at the specified location
    // with the specified number of rows
    for (size_t i = 0, n = numOfRows; i<n; i++)
    {
        Hex* hex = new Hex();
        hex->setIsPlaced(true);
        hex->setPos(x,y+82*i);
        hexes.append(hex);
        game->scene->addItem(hex);

        // set owner to NOONE initially
        hex->setOwner(QString("NOONE"));
    }
}
