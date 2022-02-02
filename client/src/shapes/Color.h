#include <vector>

class Color
{
private:
    std::vector<int[3]> colourMap;
    int _r, _g, _b;

public:
    enum colors
    {
        BLACK = 0,
        BLUE = 1,
        RED = 2,
        GREEN = 3,
        YELLOW = 4,
        CYAN = 5
    };

    Color(int r, int g, int b)
    {
        _r = r<0 | r> 255 ? 0 : r;
        _g = g<0 | g> 255 ? 0 : g;
        _b = b<0 | b> 255 ? 0 : b;
    }

    Color getColor(int i)
    {
        return Color(colourMap[i][0], colourMap[i][1], colourMap[i][2]);
    }

    static void addAllColors()
    {

        int tmp[][3] = {
            {0, 0, 0},
            {0, 0, 255},
            {255, 0, 0},
            {0, 255, 0},
            {255, 255, 0},
            {0, 255, 255}};

        colourMap.clear();
        for (int[3] rgb : tmp)
        {
            colourMap.push_back(rgb);
        };
    }
};