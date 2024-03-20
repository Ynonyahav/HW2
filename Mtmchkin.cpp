#include "Mtmchkin.h"

#define DEFEAT true

//Constructor of the game
Mtmchkin::Mtmchkin(const char* playerName, const Card* cardsArray, int numOfCards) :
    m_player(playerName), m_cardsArray(copyCardsArray(cardsArray, numOfCards)),
    m_numberOfCards(numOfCards), m_status(GameStatus::MidGame), m_cardIndex(0){}

//copy constuctor
Mtmchkin::Mtmchkin(const Mtmchkin& mtmchkin) : m_player(mtmchkin.m_player), m_cardsArray(mtmchkin.m_cardsArray),
    m_numberOfCards(mtmchkin.m_numberOfCards), m_status(mtmchkin.m_status), m_cardIndex(mtmchkin.m_cardIndex){}

//operator= constructo
Mtmchkin&  Mtmchkin::operator=(const Mtmchkin& other)
{
    m_player = other.m_player;
    m_cardsArray = other.m_cardsArray;
    m_numberOfCards = other.m_numberOfCards;
    m_status = other.m_status;
    m_cardIndex = other.m_cardIndex;
    return *this;
}
//static member function to copy the cards array
Card* Mtmchkin::copyCardsArray(const Card* cardsArray, int numOfCards) 
{
    Card* newCardsArray = new Card[numOfCards];
    for(int i = 0; i < numOfCards; i++){
        newCardsArray[i] = cardsArray[i];
    }
    return newCardsArray;
}

//Destructor of the game
Mtmchkin::~Mtmchkin()
{
    delete[] m_cardsArray;
}

//play next card and update player status
void Mtmchkin::playNextCard()
{
    if(m_status==GameStatus::MidGame)
    {
        m_cardsArray[m_cardIndex].printInfo();
        m_cardsArray[m_cardIndex].applyEncounter(m_player);
        m_player.printInfo();
        m_cardIndex++;                
        if(m_cardIndex==m_numberOfCards)
        {
            m_cardIndex=0;
        }
    }
}

//check if the game is over
bool Mtmchkin::isOver()
{
    if(m_player.getLevel()==Player::MAX_LEVEL)
    {
        m_status=GameStatus::Win;
        return true;
    }
    if(m_player.isKnockedOut()==DEFEAT)
    {
        m_status=GameStatus::Loss;
        return true;
    }
    return false;
}

// return the status of the game
GameStatus Mtmchkin::getGameStatus() const
{
    return m_status;
}