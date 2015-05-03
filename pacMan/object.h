#ifndef OBJECT_H
#define OBJECT_H
#include "coords.h"
#include "constants.h"
class object
{
public:
    //constructors
    object(coords position, char objectType, int age=0, bool hasMoved=false, int speed=1);

    //destructor
    ~object();

    //accessors
    coords get_position();
    coords get_spawnPosition();
    char virtual get_objectType();
    int get_age();
    bool get_hasmoved();
    int get_speed();
    sf::Sprite get_sprite();
    sf::Texture get_texture();

    //mutators
    void set_position(coords position);
    //don't make a mutator for _spawnPosition
    void set_objectType(char objectType);
    void set_age(int age);
    void set_hasMoved(bool hasMoved);
    void set_speed(int speed);


    //main functions
    void virtual move(object *board[][X_DIMENSION], object* pellets[][X_DIMENSION], directions direction);
    void virtual move(object* board[][X_DIMENSION],object* pellets[][X_DIMENSION], coords newDirect);
    void virtual die(object* board[][X_DIMENSION]);
    bool virtual isNULL(object* board[][X_DIMENSION], coords checkHere);
    int getType();
    void reset_age();
    void virtual increment_age();
    void decrement_age();

    //public variables
    sf::Texture _texture;
    sf::Sprite _sprite;
    coords _position;


    //tool functions
protected:
    void loadTexture(char *fileName);
    void loadSprite();

private:
    char _objectType;
    bool _hasMoved;
    int _speed;
    int _age;
    coords _spawnPosition;

    //directions _direction;

};

#endif // OBJECT_H
