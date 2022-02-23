#include <iostream>

#include "VisitorDrawShapeJAVA.h"
#include "../../../ConnectionHandler.h"
#include "../../simple/Circle.h"
#include "../../simple/Polygon.h"
#include "../../simple/Segment.h"
#include "../../simple/Triangle.h"
#include "../../composed/ComposedShape.h"
#include "WorldToScreen.h"

// TODO @Avan0x Convert world's coordinates to screen's coordinates
// TODO @Avan0x Send datas to server (not (string)(*s))

void VisitorDrawShapeJAVA::visit(const shape::Circle *s) const
{
    ConnectionHandler connection = ConnectionHandler(_address, _port);
    connection.sendLine("|" + _name + ";" + to_string(_screenX) + ";" + to_string(_screenY) + "|" + "\n");

    // Construct rectangle for circle
    WorldToScreen wts(s->getBottomLeft(), s->getTopRight(), _screenX, _screenY);

    // Circle's center on screen size
    Vector2D centerS = wts.toScreen(s->getCenter());
    // New coordinates of random point on screen size
    double screenRadius = wts.toScreen(Vector2D(s->getCenter().x + s->getRadius(), 0)).x - centerS.x;

    ostringstream str;
    str << "|Circle;" << (int)centerS.x << ";" << (int)centerS.y << ";" << (int)screenRadius << ";" << (string)s->getColor() << "|\n";
    cout << str.str();
    connection.sendLine(str.str());

    connection.sendLine("disconnect\n");
    connection.receive();
    connection.close();
}

void VisitorDrawShapeJAVA::visit(const shape::Polygon *s) const
{
    ConnectionHandler connection = ConnectionHandler(_address, _port);
    connection.sendLine("|" + _name + ";" + to_string(_screenX) + ";" + to_string(_screenY) + "|" + "\n");
    connection.sendLine("|" + (string)(*s) + "|" + "\n");

    connection.sendLine("disconnect\n");
    connection.receive();
    connection.close();
}

void VisitorDrawShapeJAVA::visit(const shape::Segment *s) const
{
    ConnectionHandler connection = ConnectionHandler(_address, _port);
    connection.sendLine("|" + _name + ";" + to_string(_screenX) + ";" + to_string(_screenY) + "|" + "\n");
    connection.sendLine("|" + (string)(*s) + "|" + "\n");

    connection.sendLine("disconnect\n");
    connection.receive();
    connection.close();
}

void VisitorDrawShapeJAVA::visit(const shape::Triangle *s) const
{
    ConnectionHandler connection = ConnectionHandler(_address, _port);
    connection.sendLine("|" + _name + ";" + to_string(_screenX) + ";" + to_string(_screenY) + "|" + "\n");
    connection.sendLine("|" + (string)(*s) + "|" + "\n");

    connection.sendLine("disconnect\n");
    connection.receive();
    connection.close();
}

void VisitorDrawShapeJAVA::visit(const shape::ComposedShape *s) const
{
    ConnectionHandler connection = ConnectionHandler(_address, _port);
    connection.sendLine("|" + _name + ";" + to_string(_screenX) + ";" + to_string(_screenY) + "|" + "\n");
    connection.sendLine("|" + (string)(*s) + "|" + "\n");

    connection.sendLine("disconnect\n");
    connection.receive();
    connection.close();
}
