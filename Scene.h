#include <GL/glut.h>

void background()
{
    glBegin(GL_QUADS);
        glColor3ub(0, 0, 0);
        glVertex2i(0, 0);
        glVertex2i(2560, 0);
        glVertex2i(2560, 200);
        glVertex2i(0, 200);

        glColor3ub(0, 0, 128);
        glVertex2i(0, 400);
        glVertex2i(2560, 400);
        glColor3ub(0, 0, 64);
        glVertex2i(2560, 1088);
        glVertex2i(0, 1088);
    glEnd();
}

void lampPost()
{

}

void road()
{
    glBegin(GL_QUADS);
        glColor3ub(16, 16, 16);
        glVertex2i(0, 200);
        glVertex2i(2560, 200);
        glVertex2i(2560, 400);
        glVertex2i(0, 400);
    glEnd();

    glLineWidth(4);

    glColor3ub(255, 255, 255);
    for(int i = -40; i < 2600; i+=40)
    {
        glBegin(GL_LINES);
            glVertex2i(i, 300);
            glVertex2i(i+20, 300);
        glEnd();
    }

    glLineWidth(1);     //glLineWidth() is universal, needs to be reset
}
