#include <cstdlib>
#include <time.h>
#include <GL/glut.h>

class Building
{
    int red;
    int green;
    int blue;

    void setWindowColor(int r, int g, int b)
    {
        red = r;
        green = g;
        blue = b;
    }

    void drawWindow(int x, int y, int w, int h)
    {
        glBegin(GL_QUADS);
            glColor3ub(red, green, blue);
            glVertex2i(x, y);
            glVertex2i(x+w-2, y);
            glVertex2i(x+w-2, y+h-2);

            if((red == 0 && green == 0 && blue == 0) || (red == 0 && green == 64 && blue == 128))
                glColor3ub(red, green, blue);
            else
                glColor3ub(255, 255, 255);

            glVertex2i(x, y+h-2);
        glEnd();
    }

public:
    int hPosition;
    int vPosition;
    int height;
    int width;
    int windowHeight;
    int windowWidth;

    char buildingType;

    int windowType[200][200];

    Building()
    {

    }

    void makeBuilding(int minH, int maxH, int minW, int maxW)
    {
        height = (rand() % (maxH-minH)*10)/10 + minH;
        width = (rand() % (maxW-minW)*10)/10 + minW;

        for (int i = 0; i < width/windowWidth; i++)
        {
            for(int j = 0; j < height/windowHeight; j++)
            {
                windowType[i][j] = rand() % 3;
            }
        }
    }

    void drawBuilding()
    {
        //Building Frame
        switch(buildingType)
        {
        case 'a':
            glColor3ub(8, 8, 8);
            break;
        case 'b':
            glColor3ub(0, 64, 128);
            break;
        case 'c':
            glColor3ub(0, 0, 0);
            break;
        }

        glBegin(GL_QUADS);
            glVertex2i(hPosition-5, vPosition-5);
            glVertex2i(hPosition+width+5, vPosition-5);
            glVertex2i(hPosition+width+5, vPosition+height+5);
            glVertex2i(hPosition-5, vPosition+height+5);

            glColor3ub(8, 8, 8);
            glVertex2i(hPosition+width+5, vPosition-5);
            glVertex2i(hPosition+width+40, vPosition-5);
            glVertex2i(hPosition+width+40, vPosition+height-10);
            glVertex2i(hPosition+width+5, vPosition+height+5);
        glEnd();

        //Windows
        for (int i = 0; i < width; i+=windowWidth)       //Horizontal increment
        {
            for(int j = 0; j < height; j+=windowHeight)   //Vertical increment
            {
                switch( windowType [i/windowWidth] [j/windowHeight] )
                {
                case 0:
                    switch(buildingType)
                    {
                    case 'a':
                        setWindowColor(0, 156, 208);
                        break;
                    case 'b':
                        setWindowColor(8, 208, 232);
                        break;
                    case 'c':
                        setWindowColor(255, 255, 255);
                        break;
                    }
                    break;

                case 1:
                    switch(buildingType)
                    {
                    case 'a':
                        setWindowColor(0, 104, 156);
                        break;
                    case 'b':
                        setWindowColor(232, 156, 32);
                        break;
                    case 'c':
                        setWindowColor(232, 156, 32);
                        break;
                    }
                    break;

                case 2:
                    switch(buildingType)
                    {
                    case 'a':
                        setWindowColor(0, 0, 0);
                        break;
                    case 'b':
                        setWindowColor(0, 64, 128);
                        break;
                    case 'c':
                        setWindowColor(0, 0, 0);
                        break;
                    }
                    break;
                }
                drawWindow(hPosition+i, vPosition+j, windowWidth, windowHeight);
            }
        }
    }
};

class DarkBuilding : public Building
{
    static const int minHeight = 300;
    static const int maxHeight = 600;
    static const int minWidth = 100;
    static const int maxWidth = 200;
    static const int verticalPosition = 450;
public:
    DarkBuilding()
    {

    }
    DarkBuilding(int horizontalPosition)
    {
        buildingType = 'a';

        hPosition = horizontalPosition;
        vPosition = verticalPosition;
        windowHeight = 10;
        windowWidth = 10;

        makeBuilding(minHeight, maxHeight, minWidth, maxWidth);
    }
};

class BlueBuilding : public Building
{
    static const int minHeight = 200;
    static const int maxHeight = 600;
    static const int minWidth = 100;
    static const int maxWidth = 240;
    static const int verticalPosition = 400;
public:
    BlueBuilding()
    {

    }

    BlueBuilding(int horizontalPosition)
    {
        buildingType = 'b';

        hPosition = horizontalPosition;
        vPosition = verticalPosition;
        windowHeight = 10;
        windowWidth = 20;

        makeBuilding(minHeight, maxHeight, minWidth, maxWidth);
    }

};

class BlackBuilding : public Building
{
    static const int minHeight = 60;
    static const int maxHeight = 300;
    static const int minWidth = 40;
    static const int maxWidth = 100;
    static const int verticalPosition = 180;
public:
    BlackBuilding()
    {

    }

    BlackBuilding(int horizontalPosition)
    {
        buildingType = 'c';

        hPosition = horizontalPosition;
        vPosition = verticalPosition;
        windowHeight = 8;
        windowWidth = 8;

        makeBuilding(minHeight, maxHeight, minWidth, maxWidth);
    }

};

class SmallBuilding : public Building
{
    static const int minHeight = 60;
    static const int maxHeight = 400;
    static const int minWidth = 40;
    static const int maxWidth = 100;
    static const int verticalPosition = 100;
public:
    SmallBuilding()
    {

    }

    SmallBuilding(int horizontalPosition)
    {
        buildingType = 'c';

        hPosition = horizontalPosition;
        vPosition = verticalPosition;
        windowHeight = 8;
        windowWidth = 8;

        makeBuilding(minHeight, maxHeight, minWidth, maxWidth);
    }

};

