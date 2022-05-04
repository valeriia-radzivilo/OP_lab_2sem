
#ifndef INC_4LAB_HEADER_H
#define INC_4LAB_HEADER_H
#include <iostream>
#include <math.h>
using namespace std;
class Line{
    private:
    // dot A - start of line:
        int startX, startY;
    // dot B - end of line
        int endX, endY;
        float line_length;
    public:
        Line(int startX, int endX,int startY, int endY);
        Line();
        // Getter
        float getLineLength();
        // print line as 2 coords
        void print();
        //overloading
        float operator ++ ();
        int operator ||(Line const &obj);
};



#endif //INC_4LAB_HEADER_H
