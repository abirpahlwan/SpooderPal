#include <GL/glut.h>

bool isJumping = false;
bool isFalling = false;

void body(int x, int y)
{
    //Torso
    glColor3ub(255, 0, 0);
    glBegin(GL_POLYGON);
        glVertex2i(x+16, y+30);     //most right-up point,  for red part
        glVertex2i(x+17, y+29);
        glVertex2i(x+18, y+29);
        glVertex2i(x+18, y+19);
        glVertex2i(x+17, y+19);
        glVertex2i(x+16, y+18);
        glVertex2i(x+15, y+17);
        glVertex2i(x+13, y+17);
        glVertex2i(x+12, y+18);
        glVertex2i(x+11, y+19);
        glVertex2i(x+11, y+22);
        glVertex2i(x+10, y+21);
        glVertex2i(x+10, y+24);
        glVertex2i(x+9, y+25);
        glVertex2i(x+9, y+26);
        glVertex2i(x+8, y+26);
        glVertex2i(x+7, y+27);
        glVertex2i(x+7, y+32);
        glVertex2i(x+8, y+32);
        glVertex2i(x+9, y+31);
    glEnd();

    glColor3ub(0, 0, 255);
    glBegin(GL_POLYGON);
        glVertex2i(x+12, y+22);     //most right-up point, for blue part
        glVertex2i(x+12, y+18);
        glVertex2i(x+9, y+18);
        glVertex2i(x+9, y+19);
        glVertex2i(x+10, y+20);
        glVertex2i(x+10, y+22);
        glVertex2i(x+9, y+23);
        glVertex2i(x+8, y+24);
        glVertex2i(x+7, y+24);
        glVertex2i(x+7, y+27);
        glVertex2i(x+8, y+27);
        glVertex2i(x+9, y+26);
        glVertex2i(x+10, y+26);
        glVertex2i(x+10, y+25);
        glVertex2i(x+11, y+24);
        glVertex2i(x+11, y+23);
    glEnd();

    glBegin(GL_LINE_LOOP);
        glColor3ub(32, 32, 32);
        glVertex2i(x+16, y+30);
        glVertex2i(x+17, y+29);
        glVertex2i(x+18, y+29);
        glVertex2i(x+18, y+19);
        glVertex2i(x+17, y+19);
        glVertex2i(x+16, y+18);
        glVertex2i(x+15, y+17);

        glVertex2i(x+13, y+17);
        glColor3ub(0, 0, 255);
        glVertex2i(x+13, y+17);

        glVertex2i(x+12, y+18);
        glColor3ub(32, 32, 32);
        glVertex2i(x+12, y+18);

        glVertex2i(x+9, y+18);
        glVertex2i(x+9, y+19);
        glVertex2i(x+10, y+20);
        glVertex2i(x+10, y+22);
        glVertex2i(x+9, y+23);
        glVertex2i(x+8, y+24);
        glVertex2i(x+7, y+24);
        glVertex2i(x+7, y+27);
        glVertex2i(x+7, y+32);
    glEnd();

    //Head
    glColor3ub(255, 0, 0);
    glBegin(GL_POLYGON);
        glVertex2i(x+10, y+44);     //most left-up point
        glVertex2i(x+11, y+45);
        glVertex2i(x+15, y+45);
        glVertex2i(x+16, y+44);
        glVertex2i(x+17, y+44);
        glVertex2i(x+18, y+43);
        glVertex2i(x+19, y+42);
        glVertex2i(x+19, y+41);
        glVertex2i(x+20, y+40);
        glVertex2i(x+20, y+36);
        glVertex2i(x+19, y+35);
        glVertex2i(x+19, y+33);
        glVertex2i(x+18, y+32);
        glVertex2i(x+17, y+31);
        glVertex2i(x+16, y+30);
        glVertex2i(x+13, y+30);
        glVertex2i(x+12, y+31);
        glVertex2i(x+11, y+31);
        glVertex2i(x+10, y+32);
        glVertex2i(x+9, y+33);
        glVertex2i(x+8, y+33);
        glVertex2i(x+7, y+34);
        glVertex2i(x+7, y+36);
        glVertex2i(x+6, y+37);
        glVertex2i(x+6, y+40);
        glVertex2i(x+7, y+41);
        glVertex2i(x+7, y+42);
        glVertex2i(x+8, y+43);
        glVertex2i(x+9, y+44);
    glEnd();

    glColor3ub(32, 32, 32);
    glBegin(GL_LINE_LOOP);
        glVertex2i(x+10, y+44);
        glVertex2i(x+11, y+45);
        glVertex2i(x+15, y+45);
        glVertex2i(x+16, y+44);
        glVertex2i(x+17, y+44);
        glVertex2i(x+18, y+43);
        glVertex2i(x+19, y+42);
        glVertex2i(x+19, y+41);
        glVertex2i(x+20, y+40);
        glVertex2i(x+20, y+36);
        glVertex2i(x+19, y+35);
        glVertex2i(x+19, y+33);
        glVertex2i(x+18, y+32);
        glVertex2i(x+17, y+31);
        glVertex2i(x+16, y+30);
        glVertex2i(x+13, y+30);
        glVertex2i(x+12, y+31);
        glVertex2i(x+11, y+31);
        glVertex2i(x+10, y+32);
        glVertex2i(x+9, y+33);
        glVertex2i(x+8, y+33);
        glVertex2i(x+7, y+34);
        glVertex2i(x+7, y+36);
        glVertex2i(x+6, y+37);
        glVertex2i(x+6, y+40);
        glVertex2i(x+7, y+41);
        glVertex2i(x+7, y+42);
        glVertex2i(x+8, y+43);
        glVertex2i(x+9, y+44);
    glEnd();

    //Eye
    glColor3ub(255, 255, 255);
    glBegin(GL_POLYGON);
        glVertex2i(x+15, y+33);
        glVertex2i(x+13, y+33);
        glVertex2i(x+12, y+34);
        glVertex2i(x+11, y+35);
        glVertex2i(x+10, y+36);
        glVertex2i(x+10, y+38);
        glVertex2i(x+11, y+38);
        glVertex2i(x+12, y+37);
        glVertex2i(x+13, y+37);
        glVertex2i(x+14, y+36);
        glVertex2i(x+15, y+35);
        glVertex2i(x+16, y+34);
    glEnd();

    glColor3ub(32, 32, 32);
    glBegin(GL_LINE_LOOP);
        glVertex2i(x+15, y+33);
        glVertex2i(x+13, y+33);
        glVertex2i(x+12, y+34);
        glVertex2i(x+11, y+35);
        glVertex2i(x+10, y+36);
        glVertex2i(x+10, y+38);
        glVertex2i(x+11, y+38);
        glVertex2i(x+12, y+37);
        glVertex2i(x+13, y+37);
        glVertex2i(x+14, y+36);
        glVertex2i(x+15, y+35);
        glVertex2i(x+16, y+34);
    glEnd();

    //Chest Spooder
    glBegin(GL_LINES);
        glVertex2i(x+12, y+24);
        glVertex2i(x+14, y+24);

        glVertex2i(x+12, y+26);
        glVertex2i(x+14, y+26);

        glVertex2i(x+17, y+24);
        glVertex2i(x+18, y+24);

        glVertex2i(x+17, y+26);
        glVertex2i(x+18, y+26);

        glVertex2i(x+14, y+23);
        glVertex2i(x+17, y+23);

        glVertex2i(x+14, y+25);
        glVertex2i(x+17, y+25);

        glVertex2i(x+15, y+22);
        glVertex2i(x+15, y+26);
    glEnd();


}

void leftLeg(int x, int y)
{
    glColor3ub(0, 0, 255);
    glBegin(GL_POLYGON);
        glVertex2i(x+14, y+17);     //most left-up point, y+for blue part
        glVertex2i(x+15, y+17);
        glVertex2i(x+16, y+18);
        glVertex2i(x+17, y+19);
        glVertex2i(x+18, y+19);
        glVertex2i(x+18, y+17);
        glVertex2i(x+19, y+17);
        glVertex2i(x+19, y+10);
        glVertex2i(x+14, y+10);
    glEnd();

    glColor3ub(255, 0, 0);
    glBegin(GL_POLYGON);
        glVertex2i(x+14, y+4);     //most left-low point, y+for red part
        glVertex2i(x+14, y+10);
        glVertex2i(x+19, y+10);
        glVertex2i(x+19, y+5);
        glVertex2i(x+20, y+4);
        glVertex2i(x+21, y+3);
        glVertex2i(x+21, y+2);
        glVertex2i(x+16, y+2);
        glVertex2i(x+15, y+3);
    glEnd();

    glColor3ub(32, 32, 32);
    glBegin(GL_LINE_LOOP);
        glVertex2i(x+14, y+17);
        glVertex2i(x+15, y+17);
        glVertex2i(x+16, y+18);
        glVertex2i(x+17, y+19);
        glVertex2i(x+18, y+19);
        glVertex2i(x+18, y+17);
        glVertex2i(x+19, y+17);
        glVertex2i(x+19, y+10);
        glVertex2i(x+14, y+10);
    glEnd();

    glBegin(GL_LINE_LOOP);
        glVertex2i(x+14, y+4);
        glVertex2i(x+14, y+10);
        glVertex2i(x+19, y+10);
        glVertex2i(x+19, y+5);
        glVertex2i(x+20, y+4);
        glVertex2i(x+21, y+3);
        glVertex2i(x+21, y+2);
        glVertex2i(x+16, y+2);
        glVertex2i(x+15, y+3);
    glEnd();
}

void rightLeg(int x, int y)
{
    glColor3ub(0, 0, 255);
    glBegin(GL_POLYGON);
        glVertex2i(x+13, y+18);    //most right-up point, y+for blue part
        glVertex2i(x+14, y+17);
        glVertex2i(x+14, y+16);
        glVertex2i(x+13, y+15);
        glVertex2i(x+13, y+13);
        glVertex2i(x+12, y+12);
        glVertex2i(x+12, y+11);
        glVertex2i(x+11, y+10);
        glVertex2i(x+8, y+10);
        glVertex2i(x+7, y+11);
        glVertex2i(x+6, y+11);
        glVertex2i(x+6, y+14);
        glVertex2i(x+7, y+14);
        glVertex2i(x+7, y+17);
        glVertex2i(x+8, y+17);
        glVertex2i(x+9, y+18);
    glEnd();

    glColor3ub(255, 0, 0);
    glBegin(GL_POLYGON);
        glVertex2i(x+8, y+10);     //most up-mid point, y+for red part
        glVertex2i(x+11, y+10);
        glVertex2i(x+11, y+9);
        glVertex2i(x+10, y+8);
        glVertex2i(x+10, y+7);
        glVertex2i(x+9, y+6);
        glVertex2i(x+9, y+4);
        glVertex2i(x+8, y+3);
        glVertex2i(x+8, y+1);
        glVertex2i(x+3, y+1);
        glVertex2i(x+3, y+4);
        glVertex2i(x+4, y+5);
        glVertex2i(x+4, y+6);
        glVertex2i(x+5, y+7);
        glVertex2i(x+5, y+10);
        glVertex2i(x+6, y+11);
        glVertex2i(x+7, y+11);
    glEnd();


    glBegin(GL_LINE_LOOP);
        glColor3ub(0, 0, 255);
        glVertex2i(x+13, y+18);
        glVertex2i(x+14, y+17);
        glColor3ub(32, 32, 32);
        glVertex2i(x+14, y+17);
        glVertex2i(x+14, y+16);
        glVertex2i(x+13, y+15);
        glVertex2i(x+13, y+13);
        glVertex2i(x+12, y+12);
        glVertex2i(x+12, y+11);
        glVertex2i(x+11, y+10);
        glVertex2i(x+8, y+10);
        glVertex2i(x+7, y+11);
        glVertex2i(x+6, y+11);
        glVertex2i(x+6, y+14);
        glVertex2i(x+7, y+14);
        glVertex2i(x+7, y+17);
        glVertex2i(x+8, y+17);
        glVertex2i(x+9, y+18);
        glColor3ub(0, 0, 255);
        glVertex2i(x+9, y+18);
    glEnd();

    glColor3ub(32, 32, 32);
    glBegin(GL_LINE_LOOP);
        glVertex2i(x+8, y+10);
        glVertex2i(x+11, y+10);
        glVertex2i(x+11, y+9);
        glVertex2i(x+10, y+8);
        glVertex2i(x+10, y+7);
        glVertex2i(x+9, y+6);
        glVertex2i(x+9, y+4);
        glVertex2i(x+8, y+3);
        glVertex2i(x+8, y+1);
        glVertex2i(x+3, y+1);
        glVertex2i(x+3, y+4);
        glVertex2i(x+4, y+5);
        glVertex2i(x+4, y+6);
        glVertex2i(x+5, y+7);
        glVertex2i(x+5, y+10);
        glVertex2i(x+6, y+11);
        glVertex2i(x+7, y+11);
    glEnd();
}

void leftHand(int x, int y)
{
    glColor3ub(255, 0, 0);
    glBegin(GL_POLYGON);
        glVertex2i(x+21, y+16);     //subtract from 23, y+reverse right, y+for lower red part
        glVertex2i(x+20, y+15);
        glVertex2i(x+19, y+15);
        glVertex2i(x+18, y+14);
        glVertex2i(x+16, y+14);
        glVertex2i(x+16, y+16);
        glVertex2i(x+15, y+16);
        glVertex2i(x+15, y+18);
        glVertex2i(x+16, y+19);
        glVertex2i(x+20, y+19);
        glVertex2i(x+20, y+23);
        glVertex2i(x+21, y+23);
    glEnd();

    glBegin(GL_POLYGON);
        glVertex2i(x+16, y+30);     //reverse right, y+for upper red part
        glVertex2i(x+16, y+30);
        glVertex2i(x+17, y+30);
        glVertex2i(x+18, y+29);
        glVertex2i(x+19, y+28);
        glVertex2i(x+19, y+27);
        glVertex2i(x+20, y+26);
        glVertex2i(x+20, y+23);
        glVertex2i(x+19, y+24);
        glVertex2i(x+18, y+25);
        glVertex2i(x+17, y+26);
        glVertex2i(x+16, y+27);
    glEnd();

    glColor3ub(0, 0, 255);
    glBegin(GL_POLYGON);
        glVertex2i(x+20, y+23);     //most left-up point, y+for blue part
        glVertex2i(x+19, y+24);
        glVertex2i(x+18, y+25);
        glVertex2i(x+17, y+26);
        glVertex2i(x+16, y+27);
        glVertex2i(x+16, y+24);
        glVertex2i(x+17, y+23);
        glVertex2i(x+17, y+22);
        glVertex2i(x+18, y+21);
        glVertex2i(x+18, y+18);
        glVertex2i(x+19, y+17);
        glVertex2i(x+20, y+18);
    glEnd();

    glBegin(GL_LINE_LOOP);
        glColor3ub(32, 32, 32);
        glVertex2i(x+21, y+23);
        glVertex2i(x+21, y+16);
        glVertex2i(x+20, y+15);
        glVertex2i(x+19, y+15);
        glVertex2i(x+18, y+14);
        glVertex2i(x+16, y+14);
        glVertex2i(x+16, y+16);
        glVertex2i(x+15, y+16);
        glVertex2i(x+15, y+18);
        glVertex2i(x+16, y+19);

        glVertex2i(x+18, y+19);
        glVertex2i(x+18, y+21);
        glVertex2i(x+17, y+22);
        glVertex2i(x+17, y+23);
        glVertex2i(x+16, y+24);
        glColor3ub(0, 0, 255);
        glVertex2i(x+16, y+24);

        glVertex2i(x+16, y+27);
        glColor3ub(255, 0, 0);
        glVertex2i(x+16, y+27);

        glVertex2i(x+16, y+30);
        glColor3ub(32, 32, 32);
        glVertex2i(x+16, y+30);

        glVertex2i(x+17, y+30);
        glVertex2i(x+18, y+29);
        glVertex2i(x+19, y+28);
        glVertex2i(x+19, y+27);
        glVertex2i(x+20, y+26);
        glVertex2i(x+20, y+23);
    glEnd();
}

void rightHand(int x, int y)
{
    glColor3ub(255, 0, 0);
    glBegin(GL_POLYGON);
        glVertex2i(x+2, y+16);     //most left-down point, y+for lower red part
        glVertex2i(x+3, y+15);
        glVertex2i(x+4, y+15);
        glVertex2i(x+5, y+14);
        glVertex2i(x+7, y+14);
        glVertex2i(x+7, y+16);
        glVertex2i(x+8, y+16);
        glVertex2i(x+8, y+18);
        glVertex2i(x+7, y+19);
        glVertex2i(x+3, y+19);
        glVertex2i(x+3, y+23);
        glVertex2i(x+2, y+23);
    glEnd();

    glBegin(GL_POLYGON);
        glVertex2i(x+7, y+32);     //most up-left point, y+for upper red part
        glVertex2i(x+7, y+30);
        glVertex2i(x+6, y+30);
        glVertex2i(x+5, y+29);
        glVertex2i(x+4, y+28);
        glVertex2i(x+4, y+27);
        glVertex2i(x+3, y+26);
        glVertex2i(x+3, y+23);
        glVertex2i(x+4, y+24);
        glVertex2i(x+5, y+25);
        glVertex2i(x+6, y+26);
        glVertex2i(x+7, y+27);
    glEnd();

    glColor3ub(0, 0, 255);
    glBegin(GL_POLYGON);
        glVertex2i(x+3, y+23);     //most left-up point, y+for blue part
        glVertex2i(x+4, y+24);
        glVertex2i(x+5, y+25);
        glVertex2i(x+6, y+26);
        glVertex2i(x+7, y+27);
        glVertex2i(x+7, y+24);
        glVertex2i(x+6, y+23);
        glVertex2i(x+6, y+22);
        glVertex2i(x+5, y+21);
        glVertex2i(x+5, y+18);
        glVertex2i(x+4, y+17);
        glVertex2i(x+3, y+18);
    glEnd();

    glBegin(GL_LINE_LOOP);
        glColor3ub(32, 32, 32);
        glVertex2i(x+2, y+23);
        glVertex2i(x+2, y+16);
        glVertex2i(x+3, y+15);
        glVertex2i(x+4, y+15);
        glVertex2i(x+5, y+14);
        glVertex2i(x+7, y+14);
        glVertex2i(x+7, y+16);
        glVertex2i(x+8, y+16);
        glVertex2i(x+8, y+18);
        glVertex2i(x+7, y+19);

        glVertex2i(x+5, y+19);
        glVertex2i(x+5, y+21);
        glVertex2i(x+6, y+22);
        glVertex2i(x+6, y+23);
        glVertex2i(x+7, y+24);
        glColor3ub(0, 0, 255);
        glVertex2i(x+7, y+24);

        glVertex2i(x+7, y+27);
        glColor3ub(255, 0, 0);
        glVertex2i(x+7, y+27);

        glVertex2i(x+7, y+32);
        glColor3ub(32, 32, 32);
        glVertex2i(x+7, y+32);

        glVertex2i(x+6, y+30);
        glVertex2i(x+5, y+29);
        glVertex2i(x+4, y+28);
        glVertex2i(x+4, y+27);
        glVertex2i(x+3, y+26);
        glVertex2i(x+3, y+23);
    glEnd();
}
