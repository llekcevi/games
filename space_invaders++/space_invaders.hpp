#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

class LaserManager
{
    std::vector<sf::Sprite> projectiles;

public:
    void Update(sf::Time delta);
    void spawnProjectile(sf::Vector2i position, sf::Vector2i speed);
    bool hasProjectiles();
    std::vector<sf::Sprite> getProjectiles();
};

class Laser
{
public:
    sf::Sprite laser_sprite;
    int laser_position_x;
    int laser_position_y;
    int laser_speed;
    bool isShooting;

private:
    sf::Texture m_laser_tex;
    int m_laser_sprite_height;
    int m_laser_sprite_width;

public:
    Laser();
    void shoot(int ship_x, int ship_y);
    void position(int ship_x, int ship_y);
    void moveUp();
    ~Laser();
};

class Ship
{
    LaserManager* laserManager; 
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
    void setLaserManager(LaserManager* lm);
    void moveShip(sf::RenderWindow *window);
    void moveRight();
    void moveLeft();
    void shoot();
    ~Ship();
};
