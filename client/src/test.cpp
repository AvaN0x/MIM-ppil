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
#include "shape/draw/java/WorldToScreen.h"
#include "shape/draw/java/VisitorDrawShapeAWT.h"

using namespace std;
using namespace shape;

// #define TEST_SAVE_LOAD_FILES 1
#define TEST_AREAS 0
#define TEST_ROTATIONS 0
#define TEST_REPERES 0
#define TEST_DRAW_CIRCLE 1

void mainTests()
{
    cout << FONT_YELLOW << "Create colors !" << FONT_DEFAULT << endl;

    Color color1("#f20840b0");
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

    Circle c1(vector<Vector2D>({Vector2D(2.4, 8.2)}), color1, 2.2);
    cout << "c1 : " << c1 << endl;
    Segment s1(vector<Vector2D>({Vector2D(0, 0), Vector2D(1, 1)}), Color(0, 255, 0));
    cout << "s1 : " << s1 << endl;
    shape::Polygon p1(vector<Vector2D>({Vector2D(2, 2), Vector2D(0, 3), Vector2D(4, 4), Vector2D(30, 5)}), Color(255, 0, 0));
    cout << "p1 : " << p1 << endl;
    Triangle t1(vector<Vector2D>({Vector2D(-4, -4), Vector2D(-8, -8), Vector2D(0, -8)}), Color(0, 0, 255));
    cout << "t1 : " << t1 << endl;

    ComposedShape cs1(vector<Shape *>({&c1}), Color("#ff00ffff"));
    cout << "cs1 : " << cs1 << endl;
    cs1.addShape(&s1);
    cs1.addShape(&t1);
    cout << "cs1 : " << cs1 << endl;
    cs1.removeShape(&t1);
    cout << "cs1 : " << cs1 << endl;
    cs1.addShape(&cs1);
    cs1.addShape(&t1);
    cs1.addShape(&p1);
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

#ifdef TEST_ROTATIONS
    cout << FONT_YELLOW << "Shapes rotations !" << FONT_DEFAULT << endl;

    Circle c2 = *(Circle *)c1.rotation(Vector2D(0, 0), 3.14 / 2);
    cout << "c2 : " << c2 << endl;
    Segment s2 = *(Segment *)s1.rotation(Vector2D(0, 0), 3.14 / 2);
    cout << "s2 : " << s2 << endl;
    Polygon p2 = *(Polygon *)p1.rotation(Vector2D(0, 0), 3.14 / 2);
    cout << "p2 : " << p2 << endl;
    Triangle t2 = *(Triangle *)t1.rotation(Vector2D(0, 0), 3.14 / 2);
    cout << "t2 : " << t2 << endl;
    Triangle t3 = *(Triangle *)t1.rotation(Vector2D(0, 0), 3.14);
    cout << "t2 : " << t2 << endl;
    ComposedShape cs2 = *(ComposedShape *)cs1.rotation(Vector2D(0, 0), 3.14 / 2);
    cout << "cs2 : " << cs2 << endl;
#endif

#ifdef TEST_REPERES
    cout << FONT_YELLOW << "Soit R le repere monde def par P1World(Vector2D(-1.5,-1.5)) et par P2World(Vector2D(4.5,4.5))" << FONT_DEFAULT << endl;
    cout << FONT_YELLOW << "Soit R' le repere monde def par P1Screen(Vector2D(0,500)) et par P2Screen(Vector2D(800,0))" << FONT_DEFAULT << endl;

    Vector2D P1World(-1.5, -1.5);
    Vector2D P2World(4.5, 4.5);
    Vector2D P1Screen(0, 500);
    Vector2D P2Screen(800, 0);

    double alpha = WorldToScreen::getLambda(P1World, P2World, P1Screen, P2Screen);
    cout << "alpha : " << alpha << endl;

    double E1 = WorldToScreen::getE1(P1World, P2World, P1Screen, P2Screen);
    cout << "E1 : " << E1 << endl;
    double E2 = WorldToScreen::getE2(P1World, P2World, P1Screen, P2Screen);
    cout << "E2 : " << E2 << endl;

    double a = WorldToScreen::getA(P1World, P2World, P1Screen, P2Screen, alpha, E1);
    cout << "a : " << a << endl;
    double b = WorldToScreen::getB(P1World, P2World, P1Screen, P2Screen, alpha, E2);
    cout << "b : " << b << endl;
#endif

#ifdef TEST_DRAW_CIRCLE
    cout << FONT_YELLOW << "Draw circle !" << FONT_DEFAULT << endl;

    VisitorDrawShapeAWT vDraw = VisitorDrawShapeAWT();
    // vDraw.setWindowSize(800, 600);
    c1.draw(&vDraw);
    s1.draw(&vDraw);
    p1.draw(&vDraw);
    t1.draw(&vDraw);
    t2.draw(&vDraw);
    t3.draw(&vDraw);
    cs1.draw(&vDraw);
#endif
}