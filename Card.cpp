#include <iostream>
#include "Card.h"

#define WIN true
#define LOSE false 

//Constructor of the card
Card::Card(CardType type, const CardStats& stats): m_effect(type), m_stats(stats){}

//print the reslt of player encountering card
void Card::applyEncounter(Player& player) const
{
    if(m_effect==CardType::Battle)
    {
        if(player.getAttackStrength()>=m_stats.force)
        {
            player.addCoins(m_stats.loot);
            player.levelUp();  //add only if level small then 10
            printBattleResult(WIN);
        }
        else 
        {
            player.damage(m_stats.hpLossOnDefeat);
            printBattleResult(LOSE);
        }
    }
    else if(m_effect==CardType::Buff)
    {
        if(player.pay(m_stats.cost))
        {
            player.buff(m_stats.buff);
        }
    }
    else if(m_effect==CardType::Heal)
    {
        if(player.pay(m_stats.cost))
        {
            player.heal(m_stats.heal);
        }
    }
    else if(m_effect==CardType::Treasure)
    {
        player.addCoins(m_stats.loot);
    }
}

//printing all the information of specific card
void Card::printInfo() const
{
    if(m_effect==CardType::Battle)
    {
        printBattleCardInfo(m_stats);
    }
    else if(m_effect==CardType::Buff)
    {
        printBuffCardInfo(m_stats);
    }
    else if(m_effect==CardType::Heal)
    {
       printHealCardInfo(m_stats);
    }
    else if(m_effect==CardType::Treasure)
    {
        printTreasureCardInfo(m_stats);
    }
}