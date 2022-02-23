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
std::string vectorPointsToScreen(const vector<Vector2D> &points, const WorldToScreen *wts)
{
    ostringstream oss;
    for (const Vector2D &point : points)
    {
        Vector2D screenPoint = wts->toScreen(point);
        oss << ";" << (int)screenPoint.x << ";" << (int)screenPoint.y;
    }
    return oss.str();
}

void VisitorDrawShapeJAVA::visit(const shape::Circle *s, ConnectionHandler *connection, WorldToScreen *wts) const
{
    bool initializer = false;
    if (connection == nullptr || wts == nullptr)
    {
        initializer = true;
        connection = new ConnectionHandler(_address, _port);
        connection->sendLine("|" + _name + ";" + to_string(_screenX) + ";" + to_string(_screenY) + "|" + "\n");

        // Construct rectangle for shape
        wts = new WorldToScreen(s->getBottomLeft(), s->getTopRight(), _screenX, _screenY);
    }

    // Circle's center on screen size
    Vector2D centerS = wts->toScreen(s->getCenter());
    // New coordinates of random point on screen size
    double screenRadius = wts->toScreen(Vector2D(s->getCenter().x + s->getRadius(), 0)).x - centerS.x;

    ostringstream str;
    str << "|Circle;" << (int)centerS.x << ";" << (int)centerS.y << ";" << (int)screenRadius << ";" << (string)s->getColor() << "|\n";
    cout << str.str();
    connection->sendLine(str.str());

    if (initializer)
    {
        connection->sendLine("disconnect\n");
        connection->receive();
        connection->close();

        delete connection;
        delete wts;
    }
}

void VisitorDrawShapeJAVA::visit(const shape::Polygon *s, ConnectionHandler *connection, WorldToScreen *wts) const
{
    bool initializer = false;
    if (connection == nullptr || wts == nullptr)
    {
        initializer = true;
        connection = new ConnectionHandler(_address, _port);
        connection->sendLine("|" + _name + ";" + to_string(_screenX) + ";" + to_string(_screenY) + "|" + "\n");

        // Construct rectangle for shape
        wts = new WorldToScreen(s->getBottomLeft(), s->getTopRight(), _screenX, _screenY);
    }

    ostringstream str;
    str << "|AnyPolygon" << vectorPointsToScreen(s->getPoints(), wts) << ";" << (string)s->getColor() << "|\n";
    cout << str.str();
    connection->sendLine(str.str());

    if (initializer)
    {
        connection->sendLine("disconnect\n");
        connection->receive();
        connection->close();

        delete connection;
        delete wts;
    }
}

void VisitorDrawShapeJAVA::visit(const shape::Segment *s, ConnectionHandler *connection, WorldToScreen *wts) const
{
    bool initializer = false;
    if (connection == nullptr || wts == nullptr)
    {
        initializer = true;
        connection = new ConnectionHandler(_address, _port);
        connection->sendLine("|" + _name + ";" + to_string(_screenX) + ";" + to_string(_screenY) + "|" + "\n");

        // Construct rectangle for shape
        wts = new WorldToScreen(s->getBottomLeft(), s->getTopRight(), _screenX, _screenY);
    }

    ostringstream str;
    str << "|Segment" << vectorPointsToScreen(s->getPoints(), wts) << ";" << (string)s->getColor() << "|\n";

    cout << str.str();
    connection->sendLine(str.str());

    if (initializer)
    {
        connection->sendLine("disconnect\n");
        connection->receive();
        connection->close();

        delete connection;
        delete wts;
    }
}

void VisitorDrawShapeJAVA::visit(const shape::Triangle *s, ConnectionHandler *connection, WorldToScreen *wts) const
{
    bool initializer = false;
    if (connection == nullptr || wts == nullptr)
    {
        initializer = true;
        connection = new ConnectionHandler(_address, _port);
        connection->sendLine("|" + _name + ";" + to_string(_screenX) + ";" + to_string(_screenY) + "|" + "\n");

        // Construct rectangle for shape
        wts = new WorldToScreen(s->getBottomLeft(), s->getTopRight(), _screenX, _screenY);
    }

    ostringstream str;
    str << "|Triangle" << vectorPointsToScreen(s->getPoints(), wts) << ";" << (string)s->getColor() << "|\n";

    cout << str.str();
    connection->sendLine(str.str());

    if (initializer)
    {
        connection->sendLine("disconnect\n");
        connection->receive();
        connection->close();

        delete connection;
        delete wts;
    }
}

void VisitorDrawShapeJAVA::visit(const shape::ComposedShape *s, ConnectionHandler *connection, WorldToScreen *wts) const
{
    bool initializer = false;
    if (connection == nullptr || wts == nullptr)
    {
        initializer = true;
        connection = new ConnectionHandler(_address, _port);
        connection->sendLine("|" + _name + ";" + to_string(_screenX) + ";" + to_string(_screenY) + "|" + "\n");

        // Construct rectangle for shape
        wts = new WorldToScreen(s->getBottomLeft(), s->getTopRight(), _screenX, _screenY);
    }

    for (const shape::Shape *shape : s->getShapes())
        shape->draw(this, connection, wts);

    if (initializer)
    {
        connection->sendLine("disconnect\n");
        connection->receive();
        connection->close();

        delete connection;
        delete wts;
    }
}
