#include <iostream>

#include "VisitorDrawShapeJAVA.h"
#include "../../../ConnectionHandler.h"
#include "../../simple/Circle.h"
#include "../../simple/Polygon.h"
#include "../../simple/Segment.h"
#include "../../simple/Triangle.h"
#include "../../composed/ComposedShape.h"
#include "WorldToScreen.h"

// TODO @Avan0x add screen sizes as variables to Visitor
// TODO @Avan0x Send screen size to server
// TODO @Avan0x Convert world's coordinates to screen's coordinates
// TODO @Avan0x Send datas to server (not (string)(*s))
// TODO @AvaN0x fix color problem

void VisitorDrawShapeJAVA::visit(const shape::Circle *s) const
{
    // Get coordinates of the screen
    Vector2D P1Screen(0, _screen_y);
    Vector2D P2Screen(_screen_x, 0);

    // Construct rectangle for circle
    Vector2D P1World(s->getCenter().x - s->getRadius(), s->getCenter().y + s->getRadius());
    Vector2D P2World(s->getCenter().x + s->getRadius(), s->getCenter().y - s->getRadius());

    cout << "P1World : " << P1World << endl;
    cout << "P2World : " << P2World << endl;

    double alpha = WorldToScreen::getLambda(P1World, P2World, P1Screen, P2Screen);
    double E1 = WorldToScreen::getE1(P1World, P2World, P1Screen, P2Screen);
    double E2 = WorldToScreen::getE2(P1World, P2World, P1Screen, P2Screen);
    double a = WorldToScreen::getA(P1World, P2World, P1Screen, P2Screen, alpha, E1);
    double b = WorldToScreen::getB(P1World, P2World, P1Screen, P2Screen, alpha, E2);

    // Create a random point on the perimeter of circle
    double tmpX = s->getCenter().x + s->getRadius();

    // Circle's center on screen size
    double x = alpha * E1 * s->getCenter().x + a;
    double y = alpha * E2 * s->getCenter().y + b;

    // New coordinates of random point on screen size
    double tmpNewX = alpha * E1 * tmpX + a;

    double newRadius = tmpNewX - x;

    ConnectionHandler connection = ConnectionHandler(_address, _port);
    connection.sendLine("|" + _name + ";" + to_string(_screen_x) + ";" + to_string(_screen_y) + "|" + "\n");

    cout << "|Circle;" + to_string((int)x) + ";" + to_string((int)y) + ";" + to_string((int)newRadius) + ";" + (string)s->getColor() + "|\n";
    connection.sendLine("|Circle;" + to_string((int)x) + ";" + to_string((int)y) + ";" + to_string((int)newRadius) + ";" + (string)s->getColor() + "|\n");

    connection.sendLine("disconnect\n");
    connection.receive();
    connection.close();
}

void VisitorDrawShapeJAVA::visit(const shape::Polygon *s) const
{
    ConnectionHandler connection = ConnectionHandler(_address, _port);
    connection.sendLine("|" + _name + ";" + to_string(_screen_x) + ";" + to_string(_screen_y) + "|" + "\n");
    connection.sendLine("|" + (string)(*s) + "|" + "\n");

    connection.sendLine("disconnect\n");
    connection.receive();
    connection.close();
}

void VisitorDrawShapeJAVA::visit(const shape::Segment *s) const
{
    ConnectionHandler connection = ConnectionHandler(_address, _port);
    connection.sendLine("|" + _name + ";" + to_string(_screen_x) + ";" + to_string(_screen_y) + "|" + "\n");
    connection.sendLine("|" + (string)(*s) + "|" + "\n");

    connection.sendLine("disconnect\n");
    connection.receive();
    connection.close();
}

void VisitorDrawShapeJAVA::visit(const shape::Triangle *s) const
{
    ConnectionHandler connection = ConnectionHandler(_address, _port);
    connection.sendLine("|" + _name + ";" + to_string(_screen_x) + ";" + to_string(_screen_y) + "|" + "\n");
    connection.sendLine("|" + (string)(*s) + "|" + "\n");

    connection.sendLine("disconnect\n");
    connection.receive();
    connection.close();
}

void VisitorDrawShapeJAVA::visit(const shape::ComposedShape *s) const
{
    ConnectionHandler connection = ConnectionHandler(_address, _port);
    connection.sendLine("|" + _name + ";" + to_string(_screen_x) + ";" + to_string(_screen_y) + "|" + "\n");
    connection.sendLine("|" + (string)(*s) + "|" + "\n");

    connection.sendLine("disconnect\n");
    connection.receive();
    connection.close();
}
