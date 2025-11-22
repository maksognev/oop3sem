// commit: "feat: add base Point class with constructors and methods"

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

int main() {
    setlocale(LC_ALL, "ru");
    test();
    return 0;
}