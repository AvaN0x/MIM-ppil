#include <iostream>

#include "VisitorDrawShapeJAVA.h"
#include "../../../ConnectionHandler.h"
#include "../../simple/Circle.h"
#include "../../simple/Polygon.h"
#include "../../simple/Segment.h"
#include "../../simple/Triangle.h"
#include "../../composed/ComposedShape.h"

void VisitorDrawShapeJAVA::visit(const shape::Circle *s, int port, const string &address) const
{
    ConnectionHandler connection = ConnectionHandler(address, port);
    connection.sendLine("|" + _name + "|" + "\n");

    // cout << (string)(*s);

    Vector2D center = s->getPoints().at(0);

    // cout << test;
    connection.sendLine("|Circle;" + to_string((int)center.x) + ";" + to_string((int)center.y) + ";" + to_string((int)s->getRadius()) + ";" + (string)s->getColor() + "|\n");

    connection.sendLine("disconnect\n");
    connection.receive();
    connection.close();
}

void VisitorDrawShapeJAVA::visit(const shape::Polygon *s, int port, const string &address) const
{
    ConnectionHandler connection = ConnectionHandler(address, port);
    connection.sendLine("|" + _name + "|" + "\n");
    connection.sendLine("|" + (string)(*s) + "|" + "\n");

    connection.sendLine("disconnect\n");
    connection.receive();
    connection.close();
}

void VisitorDrawShapeJAVA::visit(const shape::Segment *s, int port, const string &address) const
{
    ConnectionHandler connection = ConnectionHandler(address, port);
    connection.sendLine("|" + _name + "|" + "\n");
    connection.sendLine("|" + (string)(*s) + "|" + "\n");

    connection.sendLine("disconnect\n");
    connection.receive();
    connection.close();
}

void VisitorDrawShapeJAVA::visit(const shape::Triangle *s, int port, const string &address) const
{
    ConnectionHandler connection = ConnectionHandler(address, port);
    connection.sendLine("|" + _name + "|" + "\n");
    connection.sendLine("|" + (string)(*s) + "|" + "\n");

    connection.sendLine("disconnect\n");
    connection.receive();
    connection.close();
}

void VisitorDrawShapeJAVA::visit(const shape::ComposedShape *s, int port, const string &address) const
{
    ConnectionHandler connection = ConnectionHandler(address, port);
    connection.sendLine("|" + _name + "|" + "\n");
    connection.sendLine("|" + (string)(*s) + "|" + "\n");

    connection.sendLine("disconnect\n");
    connection.receive();
    connection.close();
}
