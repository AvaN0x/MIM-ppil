#include <iostream>
#include <string>
#include "LoadShapeComposedShapeTXTCOR.h"
#include "../../composed/ComposedShape.h"
#include "../../files/txt/VisitorSaveFileTXT.h"

using namespace std;

LoadShapeComposedShapeTXTCOR::LoadShapeComposedShapeTXTCOR(LoadShapeCOR *next) : LoadShapeCOR(next) {}

shape::Shape *LoadShapeComposedShapeTXTCOR::_getShape(const string &s) const
{
    try
    {
        if (s.rfind("ComposedShape", 0) != 0)
            throw std::invalid_argument("The string is not a ComposedShape");

        shape::ComposedShape *res = new shape::ComposedShape;
        VisitorSaveFileTXT *v = new VisitorSaveFileTXT;

        int sLength = s.length();
        int subSquareBracketCount = 0;

        bool first = true;
        int i = s.find('[') + 1;
        int lastStart = i + 2; // 2 for "\n\t"
        while (i < sLength)
        {
            if (s[i] == '/' && subSquareBracketCount == 0)
            {
                shape::Shape *shape = v->getShapeFromString(s.substr(lastStart, i - lastStart));
                if (shape != NULL)
                {
                    if (first)
                    {
                        first = false;
                        res->setColor(shape->getColor());
                    }
                    res->addShape(shape);
                }
                lastStart = i + 3; // 3 for "/\n\t"
            }
            if (s[i] == '[')
                subSquareBracketCount++;
            else if (s[i] == ']')
                subSquareBracketCount--;
            i++;
        }
        return res;
    }
    catch (const std::exception &e)
    {
#ifdef DEBUG_LOAD_SHAPE_COR
        std::cerr << e.what() << std::endl;
#endif
    }

    return NULL;
}
