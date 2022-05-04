#include "header.h"

Line::Line(int startX, int endX,int startY, int endY){
    this->startX = startX;
    this->startY = startY;
    this->endX = endX;
    this->endY = endY;
}
Line::Line(){
    cout<<"First dot:"<<endl<<"X: ";
    cin>>startX;
    cout<<"Y: ";
    cin>>endX;
    cout<<"Second dot:" <<endl<<"X: ";
    cin>>startY;
    cout<<"Y: ";
    cin >>endY;
}

void Line::print() {
    cout << "Line: "<<"("<<startX<<","<<endX<<")" <<"(" <<startY <<","<<endY<<")" << endl;
}

int Line::operator||(const Line &obj)
{
    float k_one = (float)((endX - endY) /(startX - startY));
    float k_two = (float)((obj.endX - obj.endY) /(obj.startX - obj.startY));
    if(k_one == k_two)
        return 1;

    else return 0;

}

float Line::operator++()
{
    line_length += 1.0;
    return line_length;
}

float Line::getLineLength()
{
    line_length =pow(pow(startY - startX, 2)+pow(endY - endX,2),0.5);
    return line_length;
}