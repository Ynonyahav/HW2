#include "Player.h"
#include "utilities.h"

//Constructor of the player
Player::Player(const char* name, int maxHP, int force) : m_name(name), m_maxHP(maxHP), m_HP(maxHP), m_force(force), m_coins(0), m_level(0){}
//Print the player's info
void Player::printInfo() const
{
    printPlayerInfo(m_name.c_str(), m_level, m_force, m_HP, m_coins);
}
//If the player's level is less than 10, level up the player
void Player::levelUp()
{
    if(m_level < DEFAULT_MAX_LEVEL){
        m_level++;
    }
}
//Get the level of the player
int Player::getLevel() const
{
    return m_level;
}
//If the buff is greater than 0, buff the player
void Player::buff(int buff)
{
    if(buff > 0)
    {
        m_force += buff;
    }
}
//If the heal is greater than 0, heal the player
void Player::heal(int heal)
{
    if(heal > 0)
    {
        m_HP += heal;
        if(m_HP > m_maxHP)
        {
            m_HP = m_maxHP;
        }
    }
}
//If the damage is greater than 0, damage the player
void Player::damage(int damage)
{
    if(damage > 0)
    {
        m_HP -= damage;
        if(m_HP < 0)
        {
            m_HP = 0;
        }
    }
}
//If the player's HP is 0, the player is knocked out
bool Player::isKnockedOut() const
{
    return m_HP == 0;
}
//If the coins is greater than 0, add the coins to the player
void Player::addCoins(int coins)
{
    if(coins > 0)
    {
        m_coins += coins;
    }
}
//If the coins is greater than 0, pay the coins
bool Player::pay(int coins)
{
    if(coins > 0 && m_coins >= coins)
    {
        m_coins -= coins;
        return true;
    }
    return false;
}
//Get the attack strength of the player
int Player::getAttackStrength() const
{
    return m_force + m_level;
}

