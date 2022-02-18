#include <iostream>
#include <string>
#include <vector>
#include <string.h>
#include "test.h"

#include "utils/Color.h"
#include "shape/Vector2D.h"
#include "shape/composed/ComposedShape.h"
#include "shape/simple/Circle.h"
#include "shape/simple/Segment.h"
#include "shape/simple/Polygon.h"
#include "shape/simple/Triangle.h"
#include "shape/files/txt/VisitorSaveFileTXT.h"

using namespace std;
using namespace shape;

// #define TEST_SAVE_LOAD_FILES 1
#define TEST_AREAS 1

void mainTests()
{
    cout << FONT_YELLOW << "Create colors !" << FONT_DEFAULT << endl;

    Color color1("#f208408f");
    cout << "color1 : " << color1 << endl;
    Color color2("#180054");
    cout << "color2 : " << color2 << endl;

    try
    {
        Color color3("test");
        cout << "color3 : " << color3 << endl;
    }
    catch (const exception &e)
    {
        cerr << e.what() << endl;
    }

    cout << FONT_YELLOW << "Create shapes !" << FONT_DEFAULT << endl;

    Circle c1(vector<Vector2D>({Vector2D(628.4, -48.72)}), color1, 2.2);
    cout << "c1 : " << c1 << endl;
    Segment s1(vector<Vector2D>({Vector2D(0, 0), Vector2D(1, 1)}), Color(0, 254, 0));
    cout << "s1 : " << s1 << endl;
    shape::Polygon p1(vector<Vector2D>({Vector2D(2, 2), Vector2D(0, 3), Vector2D(4, 4), Vector2D(30, 5)}), Color(255, 255, 255));
    cout << "p1 : " << p1 << endl;
    Triangle t1(vector<Vector2D>({Vector2D(1.4, 2), Vector2D(3, 4.8), Vector2D(12, 4)}), Color(255, 0, 255));
    cout << "t1 : " << t1 << endl;

    ComposedShape cs1(vector<Shape *>({&c1}), Color("#ff00ffff"));
    cout << "cs1 : " << cs1 << endl;
    cs1.addShape(&s1);
    cout << "cs1 : " << cs1 << endl;
    cs1.addShape(&t1);
    cout << "cs1 : " << cs1 << endl;
    cs1.removeShape(&t1);
    cout << "cs1 : " << cs1 << endl;
    cs1.addShape(&cs1);
    cs1.addShape(&cs1);
    cout << "cs1 : " << cs1 << endl;

#ifdef TEST_SAVE_LOAD_FILES
    cout << FONT_YELLOW << "Save to files !" << FONT_DEFAULT << endl;

    VisitorSaveFileTXT *v = new VisitorSaveFileTXT;
    c1.saveFile(v, "output/c1.txt");
    s1.saveFile(v, "output/s1.txt");
    p1.saveFile(v, "output/p1.txt");
    t1.saveFile(v, "output/t1.txt");
    cs1.saveFile(v, "output/cs1.txt");

    cout << FONT_YELLOW << "Load from files !" << FONT_DEFAULT << endl;

    cout << "c1 : " << c1 << endl;
    Shape *c1txt = v->loadFile("output/c1.txt");
    if (c1txt != nullptr)
        cout << "c1txt : " << FONT_BLUE << *c1txt << FONT_DEFAULT << endl;

    cout << "s1 : " << s1 << endl;
    Shape *s1txt = v->loadFile("output/s1.txt");
    if (s1txt != nullptr)
        cout << "s1txt : " << FONT_BLUE << *s1txt << FONT_DEFAULT << endl;

    cout << "p1 : " << p1 << endl;
    Shape *p1txt = v->loadFile("output/p1.txt");
    if (p1txt != nullptr)
        cout << "p1txt : " << FONT_BLUE << *p1txt << FONT_DEFAULT << endl;

    cout << "t1 : " << t1 << endl;
    Shape *t1txt = v->loadFile("output/t1.txt");
    if (t1txt != nullptr)
        cout << "t1txt : " << FONT_BLUE << *t1txt << FONT_DEFAULT << endl;

    cout << "cs1 : " << cs1 << endl;
    Shape *cs1txt = v->loadFile("output/cs1.txt");
    if (cs1txt != nullptr)
        cout << "cs1txt : " << FONT_BLUE << *cs1txt << FONT_DEFAULT << endl;
#endif

#ifdef TEST_AREAS
    cout << FONT_YELLOW << "Shapes areas !" << FONT_DEFAULT << endl;

    cout << "c1 : " << c1.area() << endl;
    cout << "s1 : " << s1.area() << endl;
    cout << "p1 : " << p1.area() << endl;
    cout << "t1 : " << t1.area() << endl;
    cout << "cs1 : " << cs1.area() << endl;
#endif
}