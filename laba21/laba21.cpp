#include <iostream>
#include <windows.h>
using namespace std;

class Point {
public:
    int x, y;
    Point() {
        cout << "[Point] Статичический\n";
        x = 0;
        y = 0;
    }
    Point(int x, int y) {
        cout << "[Point] С параметрами\n";
        this->x = x;
        this->y = y;
    }
    Point(const Point& p) {
        cout << "[Point] Копирования\n";
        x = p.x;
        y = p.y;
    }
    ~Point() { cout << "[~Point]\n"; }

    void setX(int x) { this->x = x; }
    void setY(int y) { this->y = y; }
    int getX() const { return x; }
    int getY() const { return y; }

    void print() const {
        cout << "Point: x=" << x << ", y=" << y << endl;
    }
};

class ColoredPoint : public Point {
private:
    string color;
public:
    ColoredPoint() : Point() {
        color = "black";
        cout << "Вызван конструктор ColoredPoint() без параметров\n";
    }
    ColoredPoint(int x, int y, const string& color) : Point(x, y) {
        this->color = color;
        cout << "Вызван конструктор ColoredPoint(int x, int y, string color)\n";
    }
    ColoredPoint(const ColoredPoint& other) : Point(other) {
        this->color = other.color;
        cout << "Вызван конструктор копирования ColoredPoint(const ColoredPoint& other)\n";
    }
    ~ColoredPoint() {
        cout << "~ColoredPoint()\n";
    }
    void setColor(const string& color) { this->color = color; }
    string getColor() const { return color; }

    void print() const {
        cout << "ColoredPoint: x=" << getX() << ", y=" << getY() << ", color=" << color;
    }

    void printBase() const {
        Point::print();
    }
};

void test() {
    cout << "1. Статическое создание:" << endl;
    Point p1;
    p1.print();

    cout << "\n2. Статическое создание с параметрами:" << endl;
    Point p2(10, 20);
    p2.print();

    cout << "\n3. Динамическое создание:" << endl;
    Point* p3 = new Point(30, 40);
    p3->print();

    cout << "\n4. Конструктор копирования:" << endl;
    Point p4(p2);
    p4.print();

    cout << "\n5. Удаление динамического объекта:" << endl;
    delete p3;
}

void testInheritance() {
    cout << "\n\n1. Создание ColoredPoint статически:\n";
    ColoredPoint cp1(5, 15, "red");
    cp1.print();

    cout << "\n2. Создание ColoredPoint динамически:\n";
    ColoredPoint* cp2 = new ColoredPoint(25, 35, "blue");
    cp2->print();

    cout << "\n3. Вызов методов:";
    cp2->print();
    cp2->printBase();

    cout << "\n4. Указатель базового класса на объект наследника:\n";
    Point* basePtr = new ColoredPoint(45, 55, "green");
    basePtr->print();

    delete cp2;
    delete basePtr;
}

int main() {
    setlocale(LC_ALL, "ru");
    test();
    testInheritance();
    return 0;
}