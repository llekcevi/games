#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include "space_invaders.hpp"
//
// --- SHIP ---
//
Ship::Ship(sf::RenderWindow *window)
{
    m_ship_tex.loadFromFile("/Users/llekcevic/Downloads/spaceArt/png/player.png");
    ship_sprite.setTexture(m_ship_tex);
    m_ship_sprite_height = ship_sprite.getLocalBounds().height;
    m_ship_sprite_width = ship_sprite.getLocalBounds().width;
    ship_sprite.setOrigin(m_ship_sprite_width / 2.f, m_ship_sprite_height / 2.f);
    ship_position.x = window->getSize().x / 2;
    ship_position.y = window->getSize().y - m_ship_sprite_height / 2.f;
    m_movement_speed = 3;
}

// --- SHIP - movement ---
void Ship::moveShip(sf::RenderWindow *window)
{
    bool canMoveRight = (ship_position.x - m_ship_sprite_width / 2.f) < (window->getSize().x - m_ship_sprite_width);
    bool canMoveLeft = (ship_position.x - m_ship_sprite_width / 2.f) > 0;

    if (isMovingRight && canMoveRight)
    {
        moveRight();
    }
    else if (isMovingLeft && canMoveLeft)
    {
        moveLeft();
    }
    ship_sprite.setPosition(ship_position.x, ship_position.y);
}

void Ship::moveRight()
{
    ship_position.x += m_movement_speed;
}

void Ship::moveLeft()
{
    ship_position.x -= m_movement_speed;
}

Ship::~Ship() {}
//
// --- ENEMY ---
//
Enemy::Enemy()
{
    m_enemy_texture.loadFromFile("/Users/llekcevic/Downloads/spaceArt/png/enemyShip.png");
    enemy_sprite.setTexture(m_enemy_texture);
    m_enemy_sprite_height = enemy_sprite.getLocalBounds().height;
    m_enemy_sprite_width = enemy_sprite.getLocalBounds().width;
    enemy_sprite.setOrigin(m_enemy_sprite_width / 2.f, m_enemy_sprite_height / 2.f);
    enemy_position = {100, 100};
    enemy_sprite.setPosition(enemy_position.x, enemy_position.y);
    m_enemy_speed = 3;
}
// --- ENEMY - movement ---
void Enemy::move(sf::RenderWindow *window)
{
    int max_left = 0 + m_enemy_sprite_width;
    int max_right = window->getSize().x - m_enemy_sprite_width;

    enemy_position.x += m_enemy_speed;
    if (enemy_position.x<= max_left || enemy_position.x >= max_right)
    {   
        enemy_position.y += m_enemy_sprite_height;
        m_enemy_speed *= -1;
    }

    enemy_sprite.setPosition(enemy_position.x, enemy_position.y);
}