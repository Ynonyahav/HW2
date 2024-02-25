#ifndef EX2_PLAYER_H
#define EX2_PLAYER_H

#include <string>
#include "utilities.h"

class Player {
public:
    /**
     * The default values of the player
    */
    int static const DEFAULT_MAX_HP = 100; // The maximum HP of the player
    int static const MAX_LEVEL = 10; // The level of the player
    int static const DEFAULT_FORCE = 5; // The maximum force of the player
    /**
     * C'tor of Player class
     *
     * @param name - The name of the player.
     * @param maxHP - The maximum HP of the player.
     * @param force - The force of the player.
     * @return
     *      New instance of Player.
     */
    Player(const char* name, int maxHP = DEFAULT_MAX_HP, int force = DEFAULT_FORCE);
    /**
     * print the player's info
     * @return
     *     void
    */
    void printInfo() const;
    /**
     * if the player's level is less than 10, level up the player
     *
     * @return
     *      void
     */
    void levelUp();
    /**
     * Get the level of the player.
     *
     * @return
     *      The level of the player.
     */
    int getLevel() const;
    /**
     * if the buff is greater than 0, buff the player
     *
     * @param buff - the amount of force to buff the player
     * @return
     *      void
     */
    void buff(int buff);
    /**
     * if the heal is greater than 0, heal the player
     *
     * @param heal - the amount of HP to heal the player
     * @return
     *      void
     */
    void heal(int heal);
    /**
     * if the damage is greater than 0, damage the player
     *
     * @param damage - the amount of HP to damage the player
     * @return
     *      void
     */
    void damage(int damage);
    /**
     * check if the player is knocked out
     *
     * @return
     *      true if the player is knocked out, false otherwise
     */
    bool isKnockedOut() const;
    /**
     * if the coins is greater than 0, add the coins to the player
     *
     * @param coins - the amount of coins to add to the player
     * @return
     *      void
     */
    void addCoins(int coins);
    /**
     * if the coins is greater than 0, pay the coins
     *
     * @param coins - the amount of coins to pay
     * @return
     *      true if the player has enough coins to pay, false otherwise
     */
    bool pay(int coins);
    /**
     * Get the attack strength of the player.
     *
     * @return
     *      The attack strength of the player.
     */
    int getAttackStrength() const;

    /**
     * Here we are explicitly telling the compiler to use the default methods
     *      for the copy constructor, destructor and the override of the "=" operator
    */
    Player(const Player& other) = default;
    ~Player() = default;
    Player& operator=(const Player& other) = default;
   
    private:
    std::string m_name; // The name of the player
    int m_maxHP; // The maximum HP of the player
    int m_HP; // The current HP of the player
    int m_force; // The force of the player
    int m_coins; // The amount of coins the player has
    int m_level; // The level of the player
};
    


#endif //EX2_PLAYER_H