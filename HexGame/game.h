#ifndef GAME_H
#define GAME_H

#include <QGraphicsView>
#include <QGraphicsScene>
#include <QString>
#include "hexboard.h"

class Game : public QGraphicsView
{
    Q_OBJECT
public:
    // constructors
    Game(QWidget* parent=NULL);

    // public methods
    void displayMainMenu();
    QString getWhosTurn();
    void setWhosTurn(QString player);
    void pickUpCard(Hex* card);
    void placeCard(Hex* hexToReplace);
    void nextPlayersTurn();
    void removeFromDeck(Hex* card, QString player);
    void gameOver();
    void displayGameOverWindow(QString textToDisplay);

    // events
    void mouseMoveEvent(QMouseEvent* event);
    void mousePressEvent(QMouseEvent* event);

    // public attributes
    QGraphicsScene* scene;
    HexBoard* hexBoard;
    Hex* cardToPlace;
    QPointF originalPos;
    int numCardPlaced;

public slots:
    void start();
    void restartGame();

private:
    // private methods
    void drawPanel(int x, int y, int width, int height, QColor color, double opacity=1);
    void drawGUI();
    void createNewCard(QString player);
    void createInitialCards();
    void drawCards();

    // private attributes
    QString whosTurn;
    QGraphicsTextItem* whosTurnText;
    QList<Hex*> player1Cards;
    QList<Hex*> player2Cards;
};

#endif // GAME_H
