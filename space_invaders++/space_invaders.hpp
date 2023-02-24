#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

class Ship
{

public:
    sf::Sprite ship_sprite;
    sf::Vector2i ship_position;
    bool isMovingRight;
    bool isMovingLeft;
    bool isShooting;

private:
    sf::Texture m_ship_tex;
    int m_movement_speed;
    int m_ship_sprite_height;
    int m_ship_sprite_width;

public:
    Ship(sf::RenderWindow *window);
    void moveShip(sf::RenderWindow *window);
    void moveRight();
    void moveLeft();
    void shoot();
    ~Ship();
};

class Enemy
{
private:
    sf::Texture m_enemy_texture;
    int m_enemy_sprite_height;
    int m_enemy_sprite_width;
    int m_enemy_speed;

public:
    sf::Sprite enemy_sprite;
    sf::Vector2i enemy_position;
    void move(sf::RenderWindow *window);
    Enemy();
};