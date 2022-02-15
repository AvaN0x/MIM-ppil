#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <string.h>
#include "ConnectionHandler.h"

#include "utils/Color.h"
#include "shape/Vector2D.h"
#include "shape/composed/ComposedShape.h"
#include "shape/simple/Circle.h"
#include "shape/simple/Segment.h"
#include "shape/simple/Polygon.h"
#include "shape/simple/Triangle.h"
#include "shape/files/VisitorSaveFilePPIL.h"

#define FONT_DEFAULT "\033[0m"

#define FONT_RED "\033[0;31m"
#define FONT_GREEN "\033[0;32m"
#define FONT_YELLOW "\033[1;33m"
#define FONT_BLUE "\033[1;34m"
#define FONT_MAGENTA "\033[0;35m"
#define FONT_CYAN "\033[0;36m"
#define FONT_WHITE "\033[0;37m"

#define L 200

using namespace std;
using namespace shape;

int main(int argc, char *argv[])
{
    // try
    // {
    //     // User inputs
    //     string address;
    //     int port;
    //     cout << "Tapez l'adresse du serveur : " FONT_CYAN;
    //     cin >> address;

    //     cout << FONT_DEFAULT "Tapez le n° de port du serveur : " FONT_CYAN;
    //     cin >> port;

    //     cout << FONT_DEFAULT "Trying to connect to " FONT_CYAN << address << FONT_DEFAULT ":" FONT_CYAN << port << FONT_DEFAULT << endl;

    //     ConnectionHandler connection = ConnectionHandler(address, port);
    //     cout << FONT_YELLOW "Connexion au serveur de majuscule réussie" FONT_DEFAULT << endl;

    //     // Clear cin because for some reasons the first request is empty
    //     cin.clear();
    //     fflush(stdin);

    //     do
    //     {
    //         string request;
    //         cout << "Tapez la chaîne à mettre en majuscule ou tapez \"quitter\" : " FONT_CYAN;
    //         getline(cin, request);
    //         cout << FONT_DEFAULT;
    //         if (request.empty())
    //         {
    //             cout << endl;
    //             continue;
    //         }
    //         if (request == "quitter")
    //             break;

    //         request += "\r\n";
    //         connection.sendLine(request);

    //         string response = connection.receive();

    //         cout << FONT_GREEN ">> " FONT_DEFAULT << response << endl;
    //     } while (true);

    //     connection.close();
    //     cout << FONT_YELLOW "Arrêt normal du client" FONT_DEFAULT << endl;
    // }
    // catch (const exception &e)
    // {
    //     cerr << FONT_RED "[Exception]" FONT_DEFAULT " : " << e.what() << endl;
    // }

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

    Circle c1(vector<Vector2D>({Vector2D(0, 0)}), color1, 1);
    cout << "c1 : " << c1 << endl;
    Segment s1(vector<Vector2D>({Vector2D(0, 0), Vector2D(1, 1)}), Color(0, 254, 0));
    cout << "s1 : " << s1 << endl;
    shape::Polygon p1(vector<Vector2D>({Vector2D(0, 0), Vector2D(1, 1), Vector2D(2, 2)}), Color(255, 255, 255));
    cout << "p1 : " << p1 << endl;
    Triangle t1(vector<Vector2D>({Vector2D(0, 0), Vector2D(1, 1), Vector2D(2, 2)}), Color(255, 0, 255));
    cout << "t1 : " << t1 << endl;

    ComposedShape cs1(vector<Shape *>({&c1}), Color("#ff00ffff"));
    cout << "cs1 : " << cs1 << endl;
    cs1.addShape(&s1);
    cout << "cs1 : " << cs1 << endl;
    cs1.addShape(&t1);
    cout << "cs1 : " << cs1 << endl;
    cs1.removeShape(&t1);
    cout << "cs1 : " << cs1 << endl;

    VisitorSaveFilePPIL *v = new VisitorSaveFilePPIL;
    c1.saveFile(v, "c1.ppil");
    s1.saveFile(v, "s1.ppil");
    p1.saveFile(v, "p1.ppil");
    t1.saveFile(v, "t1.ppil");
    cs1.saveFile(v, "cs1.ppil");
}
