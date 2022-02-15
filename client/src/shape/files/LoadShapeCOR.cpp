#include "LoadShapeCOR.h"

LoadShapeCOR::LoadShapeCOR(LoadShapeCOR *next) : next(next) {}

shape::Shape *LoadShapeCOR::getShape(const string &text) const
{
    shape::Shape *res = this->_getShape(text);

    if (res != NULL) // Result is valid
        return res;
    else if (this->next != NULL) // Result is not valid, but there is a next COR
        return this->next->getShape(text);
    else // Result is not valid, and there is no next COR
        return NULL;
}
