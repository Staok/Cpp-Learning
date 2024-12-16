//https://www.jianshu.com/p/7c48c17b26b8
//Line类计算线段长度 

#include<iostream>
#include<cmath>
using namespace std;

class Point
{
public:
    Point(int xx = 0, int yy = 0)
    {
        x = xx;
        y = yy;
        cout << "Calling constructor of Point"  << endl;
    }
    //拷贝构造函数
    Point(Point& p);
    int getX()
    {
        return x;
    }
    int getY()
    {
        return y;
    }
private:
    int x, y;
};

Point::Point(Point& p)
{
    x = p.x;
    y = p.y;
    cout << "Calling the copy constructor of Point" << endl;
}

class Line
{
public:
    Line(Point xp1, Point xp2);
    Line(Line& l);
    double getLen()
    {
        return len;
    }
    
private:
    Point p1, p2;
    double len;
};

//组合类的构造函数
Line::Line(Point xp1, Point xp2):p1(xp1), p2(xp2)
{
    cout << "Calling constructor of Line" << endl;
    double x = static_cast<double>(p1.getX() - p2.getX());
    double y = static_cast<double>(p1.getY() - p2.getY());
    len = sqrt(x*x + y*y);

}

//组合类的复制构造函数
Line::Line(Line& l): p1(l.p1),p2(l.p2)
{
    cout << "Calling the copy constructor of Line" << endl;
    len = l.len;
}

//主函数
int main() {
    Point myp1(1, 1), myp2(4, 5);      
                            //建立Point类的对象 
    Line line(myp1, myp2);                                    //建立Line类的对象 
    
    Line line2(line);                                        //利用复制构造函数建立一个新对象 
    cout << "The length of the line is:";
    cout << line.getLen() << endl;
    cout << "The length of the line2 is:";
    cout << line2.getLen() << endl;
    return 0;
}