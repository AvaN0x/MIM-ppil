#include <iostream>

#include "VisitorDrawShapeJAVA.h"
#include "../../../ConnectionHandler.h"
#include "../../simple/Circle.h"
#include "../../simple/Polygon.h"
#include "../../simple/Segment.h"
#include "../../simple/Triangle.h"
#include "../../composed/ComposedShape.h"
#include "WorldToScreen.h"

/**
 * @brief vectorPointsToScreen
 * @param points vector of points
 * @param wts WorldToScreen object
 * @return std::string : the string to send to the server
 */
std::string vectorPointsToScreen(const vector<Vector2D> &points, const WorldToScreen &wts)
{
    ostringstream oss;
    for (const Vector2D &point : points)
    {
        Vector2D screenPoint = wts.toScreen(point);
        oss << ";" << (int)screenPoint.x << ";" << (int)screenPoint.y;
    }
    return oss.str();
}

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

    // Construct rectangle for circle
    WorldToScreen wts(s->getBottomLeft(), s->getTopRight(), _screenX, _screenY);

    ostringstream str;
    str << "|AnyPolygon" << vectorPointsToScreen(s->getPoints(), wts) << ";" << (string)s->getColor() << "|\n";
    cout << str.str();
    connection.sendLine(str.str());

    connection.sendLine("disconnect\n");
    connection.receive();
    connection.close();
}

void VisitorDrawShapeJAVA::visit(const shape::Segment *s) const
{
    ConnectionHandler connection = ConnectionHandler(_address, _port);
    connection.sendLine("|" + _name + ";" + to_string(_screenX) + ";" + to_string(_screenY) + "|" + "\n");

    // Construct rectangle for circle
    WorldToScreen wts(s->getBottomLeft(), s->getTopRight(), _screenX, _screenY);

    ostringstream str;
    str << "|Segment" << vectorPointsToScreen(s->getPoints(), wts) << ";" << (string)s->getColor() << "|\n";

    cout << str.str();
    connection.sendLine(str.str());

    connection.sendLine("disconnect\n");
    connection.receive();
    connection.close();
}

void VisitorDrawShapeJAVA::visit(const shape::Triangle *s) const
{
    ConnectionHandler connection = ConnectionHandler(_address, _port);
    connection.sendLine("|" + _name + ";" + to_string(_screenX) + ";" + to_string(_screenY) + "|" + "\n");

    // Construct rectangle for circle
    WorldToScreen wts(s->getBottomLeft(), s->getTopRight(), _screenX, _screenY);

    ostringstream str;
    str << "|Triangle" << vectorPointsToScreen(s->getPoints(), wts) << ";" << (string)s->getColor() << "|\n";

    cout << str.str();
    connection.sendLine(str.str());

    connection.sendLine("disconnect\n");
    connection.receive();
    connection.close();
}

void VisitorDrawShapeJAVA::visit(const shape::ComposedShape *s) const
{
    ConnectionHandler connection = ConnectionHandler(_address, _port);
    connection.sendLine("|" + _name + ";" + to_string(_screenX) + ";" + to_string(_screenY) + "|" + "\n");
    connection.sendLine("|" + (string)(*s) + "|" + "\n");

    // TODO

    connection.sendLine("disconnect\n");
    connection.receive();
    connection.close();
}
