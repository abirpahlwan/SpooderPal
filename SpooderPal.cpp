#include <cstdlib>
#include <time.h>
#include <GL/glut.h>
#include "Cityscape.h"
#include "Spooder.h"
#include "Scene.h"

int x = 0;
int y = 380;

int hookX;
int hookY;

const int nDarkBuilding = 20;
DarkBuilding dkb[nDarkBuilding];

const int nBlueBuilding = 15;
BlueBuilding blb[nBlueBuilding];


const int nBlackBuilding = 25;
BlackBuilding bkb[nBlackBuilding];

const int nSmallBuilding = 25;
SmallBuilding smb[nSmallBuilding];

void buildCityscape()
{
    srand(time(NULL));

    int previousBuildingPosition = -200;    //to fill the left side
    for(int i = 0; i < nDarkBuilding; i++)
    {
        int currentBuildingPosition = previousBuildingPosition + (rand() % 2000)/10 + 100;
        dkb[i] = DarkBuilding(currentBuildingPosition);
        previousBuildingPosition = currentBuildingPosition;
    }

    previousBuildingPosition = -140;    //to fill the left side
    for(int i = 0; i < nBlueBuilding; i++)
    {
        int currentBuildingPosition = previousBuildingPosition + (rand() % 2000)/10 + 200;
        blb[i] = BlueBuilding(currentBuildingPosition);
        previousBuildingPosition = currentBuildingPosition;
    }

    previousBuildingPosition = -10;    //to fill the left side
    for(int i = 0; i < nBlackBuilding; i++)
    {
        int currentBuildingPosition = previousBuildingPosition + (rand() % 2000)/10 + 20;
        bkb[i] = BlackBuilding(currentBuildingPosition);
        previousBuildingPosition = currentBuildingPosition;
    }

    previousBuildingPosition = -10;    //to fill the left side
    for(int i = 0; i < nSmallBuilding; i++)
    {
        int currentBuildingPosition = previousBuildingPosition + (rand() % 2000)/10 + 10;
        smb[i] = SmallBuilding(currentBuildingPosition);
        previousBuildingPosition = currentBuildingPosition;
    }

}

void spooder()
{
    leftHand(x, y);
    leftLeg(x, y);
    body(x, y);
    rightLeg(x, y);
    rightHand(x, y);
}

void jump()
{
    if(!isFalling)
    {
        glColor3f(1.0, 1.0, 1.0);
        glBegin(GL_LINES);
            glVertex2i(hookX, hookY);
            glVertex2i(x+5, y+14);
        glEnd();
    }

	if(x < hookX && y < hookY)
    {
        x+=5;
        y+=4;
    }
    else if(y > 380)
    {
        if(x > hookX+12)
            isFalling = true;

        x+=4;
        y-=5;
    }
    else
        isJumping = false;
}

void myDisplay(void)
{
    glClear (GL_COLOR_BUFFER_BIT);

    background();

    for (int n = 0; n < nDarkBuilding; n++)
    {
        dkb[n].drawBuilding();
    }

    for (int n = 0; n < nBlueBuilding; n++)
    {
        blb[n].drawBuilding();
    }


    road();

    spooder();

    if(isJumping)
        jump();


    for (int n = 0; n < nBlackBuilding; n++)
    {
        bkb[n].drawBuilding();
    }

    for (int n = 0; n < nSmallBuilding; n++)
    {
        smb[n].drawBuilding();
    }


    //glFlush ();
    glutSwapBuffers();        //swaps buffered drawings, replaces glFlush()


    //Autorun
/*    if(x < 2560)
        x+=10;
    else
        x=0;
*/

    if(x > 2560)
    {
        x=0;
        y=380;
        isJumping = false;
    }
}

void myTimer(int unused)
{
    glutPostRedisplay();
    glutTimerFunc(20, myTimer, unused);
}

void myKeyboard(unsigned char key, int a, int b)
{
	switch(key)
	{
    case 'd':
        x+=15;/*
        if(x > 2560)
        {
            glutDestroyWindow(glutGetWindow());
            exit (0);
        }*/
		break;

    case 'w':
        for (int n = 0; n < nBlueBuilding; n++)
        {
            if(blb[n].hPosition > x)    //the next blue building
            {
                hookX = blb[n].hPosition + blb[n].width/2;
                hookY = blb[n].vPosition + blb[n].height*9/10;
                break;
            }
        }
        isJumping = true;
        isFalling = false;
        jump();
		break;

    case 27:
        glutDestroyWindow(glutGetWindow());
        exit(0);
        break;
	}

	glutPostRedisplay();
}

void myInit (void)
{
    glLineWidth(1);
    glClearColor(1.0, 1.0, 1.0, 0.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    //gluOrtho2D(0.0, 1280.0, 0.0, 544.0);      //True scaling
    gluOrtho2D(0.0, 2560.0, 0.0, 1088.0);       //
    //gluOrtho2D(0.0, 160.0, 0.0, 45.0);        //Preview large Spooder

}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    //glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
    glutInitDisplayMode (GLUT_DOUBLE | GLUT_RGB);     //Double buffer reduces flickering
    glutInitWindowSize (1280, 544);
    glutInitWindowPosition (100, 150);
    glutCreateWindow ("SpooderPal");
    glutDisplayFunc(myDisplay);
    glutKeyboardFunc(myKeyboard);
    myInit();
    buildCityscape();
    myTimer(0);
    glutMainLoop();

    return 0;
}
