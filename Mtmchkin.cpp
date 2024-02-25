#include "Mtmchkin.h"
#include <string>
#include "Card.h"

bool DEFEAT=true;


//Constructor of the game
Mtmchkin::Mtmchkin(const char* playerName, const Card* cardsArray, int numOfCards) :
    m_player(playerName), m_cardsArray(copyCardsArray(cardsArray, numOfCards)),
    m_numberOfCards(numOfCards), m_status(GameStatus::MidGame), m_cardIndex(0){}

//static member function to copy the cards array
Card* Mtmchkin::copyCardsArray(const Card* cardsArray, int numOfCards) 
{
    Card* newCardsArray = new Card[numOfCards];
    for(int i = 0; i < numOfCards; i++){
        newCardsArray[i] = cardsArray[i];
    }
    return newCardsArray;
}

//ynon
//Destructor of the game
Mtmchkin::~Mtmchkin()
{
    delete[] m_cardsArray;
}

//YNON
//play next card and update player status
void Mtmchkin::playNextCard()
{
    if(m_status==GameStatus::MidGame){
        if(m_cardIndex>=m_numberOfCards)
        {
        m_cardIndex=0;
        }
        m_cardsArray[m_cardIndex].printInfo();
        m_cardsArray[m_cardIndex].applyEncounter(m_player);
        m_player.printInfo();
        m_cardIndex++;                
        if(m_cardIndex==m_numberOfCards)
        {
            m_cardIndex=0;
        }
        if(m_player.getLevel()==Player::MAX_LEVEL)
        {
            m_status=GameStatus::Win;
        }else if(m_player.isKnockedOut()==DEFEAT)
        {
            m_status=GameStatus::Loss;
        }
    }
}

//YNON
//check if the game is over
bool Mtmchkin::isOver() const
{
    if (m_status == GameStatus::MidGame) {
        return false;
    }
    else {
        return true;
    }
}

// return the status of the game
GameStatus Mtmchkin::getGameStatus() const
{
    return m_status;
}