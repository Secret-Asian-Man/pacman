#ifndef COORDS_H
#define COORDS_H

//typedef int ITEM_TYPE;
class coords
{
public:

    //constructors
    coords();
    coords(int x, int y);
    coords(const coords &other);

    //accessors
    int get_x();
    int get_y();


    //mutators
    void set_x(int x);
    void set_y(int y);
    void set_xy(int x, int y);

    //prints
    void print_x();
    void print_y();
    void print_xy();

    //operators
    bool operator ==(const coords& other);
    bool operator !=(const coords& other);
    coords& operator =(const coords& other);



private:
    int _x;
    int _y;
};

#endif // COORDS_H
