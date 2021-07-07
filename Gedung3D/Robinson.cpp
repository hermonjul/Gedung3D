#include <stdlib.h>
#include <windows.h>
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include <math.h>
//#include "loadImageBMP.h"

using namespace std;
GLUquadricObj* p = gluNewQuadric();
float xrot = 0;
float yrot = 0;
float xdiff = 0;
float ydiff = 0;
bool mousedown = false;

void init(void);
void display(void);
void keyboard(unsigned char, int, int);
void resize(int, int);
void mouseMove(int x, int y);
void mouseButton(int button, int state, int x, int y);
void silinder(float red, float green, float blue, float x, float y, float z, float jari_jari, float tinggi);
void kubus(float red, float green, float blue, float x, float y, float z, float panjang, float lebar, float tinggi, float rotation_z);
void silinderMeja(float red, float green, float blue, float x, float y, float z, float jari_jari, float tinggi);

int is_depth;
void mouseMove(int x, int y) {
    if (mousedown) {
        yrot = x - xdiff;
        xrot = y + ydiff;

        glutPostRedisplay();
    }
}

void mouseButton(int button, int state, int x, int y) {
    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
        mousedown = true;
        xdiff = x - yrot;
        ydiff = -y + xrot;
    }
    else {
        mousedown = false;
    }
    glutPostRedisplay();
}

void init(void)
{
    glClearColor(1.0, 1.0, 1.0, 0.0);
    glEnable(GL_DEPTH_TEST);
    glMatrixMode(GL_MODELVIEW);
    glPointSize(9.0);
    glLineWidth(6.0f);

}

void silinderMeja(float red, float green, float blue, float x, float y, float z, float jari_jari, float tinggi) {
    //selimut
    glPushMatrix();
    glColor3f(red, green, blue);
    glRotatef(-90, 1.f, 0.f, 0.f);
    glTranslatef(x, y, z / 2.0f);
    gluCylinder(p, jari_jari, jari_jari, tinggi, 360, 1);
    glPopMatrix();

    //bawah
    glPushMatrix();
    glColor3f(0.5, 0.5, 0.5);
    glRotatef(-90, 1.f, 0.f, 0.f);
    glTranslatef(x, y, z / 2.0f);
    gluDisk(p, 0, jari_jari, 360, 1);
    glPopMatrix();

    //atas
    glPushMatrix();
    glColor3f(0.396f, 0.337f, 0.243f);
    glRotatef(-90, 1.f, 0.f, 0.f);
    glTranslatef(x, y, z / 2.0f + tinggi);
    gluDisk(p, 0, jari_jari, 360, 1);
    glPopMatrix();

}

void silinder(float red, float green, float blue, float x, float y, float z, float jari_jari, float tinggi) {
    //selimut
    glPushMatrix();
    glColor3f(red, green, blue);
    glRotatef(-90, 1.f, 0.f, 0.f);
    glTranslatef(x, y, z / 2.0f);
    gluCylinder(p, jari_jari, jari_jari, tinggi, 360, 1);
    glPopMatrix();

    //bawah
    glPushMatrix();
    glColor3f(0.5, 0.5, 0.5);
    glRotatef(-90, 1.f, 0.f, 0.f);
    glTranslatef(x, y, z / 2.0f);
    gluDisk(p, 0, jari_jari, 360, 1);
    glPopMatrix();

    //atas
    glPushMatrix();
    glColor3f(0.5, 0.5, 0.5);
    glRotatef(-90, 1.f, 0.f, 0.f);
    glTranslatef(x, y, z / 2.0f + tinggi);
    gluDisk(p, 0, jari_jari, 360, 1);
    glPopMatrix();

}

void kubus(float red, float green, float blue, float x, float y, float z, float panjang, float lebar, float tinggi, float rotation_z) {
    glPushMatrix();
    glColor3f(red, green, blue);
    glTranslatef(x, y + tinggi / 2, z);
    glRotatef(rotation_z, 0.0, 1.0, 0.0f);
    glScalef(panjang, tinggi, lebar);
    glutSolidCube(1);
    glPopMatrix();
}

void meja_bundar(float x, float y, float z) {
    //atas meja
    silinderMeja(0.813f, 0.694f, 0.494f, x, -z, y + (4 * 2), 5, 0.2);
    //tiang meja
    kubus(0.813f, 0.694f, 0.494f, x, y / 2, z, 1, 1, 4, 0);
    //alas meja
    silinderMeja(0.813f, 0.694f, 0.494f, x, -z, y, 3, 0.2);
}



void display(void)
{
    GLfloat theta;


    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glClear(GL_COLOR_BUFFER_BIT);
    glPushMatrix();
    glRotatef(xrot, 1, 0, 0);
    glRotatef(yrot, 0, 1, 0);

    glBegin(GL_QUADS);//Luas Mall
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex3f(-500.0, -3.0, -500.0);
    glColor3f(0.4f, 0.4f, 0.4f);
    glVertex3f(-500.0, -3.0, 500.0);
    glColor3f(0.6f, 0.6f, 0.6f);
    glVertex3f(500.0, -3.0, 500.0);
    glColor3f(0.8f, 0.8f, 0.8f);
    glVertex3f(500.0, -3.0, -500.0);
    glEnd();
    glBegin(GL_LINE_LOOP);//Garis Halaman Mall
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex3f(-500.0, -3.0, -500.0);
    glVertex3f(-500.0, -3.0, 500.0);
    glVertex3f(500.0, -3.0, 500.0);
    glVertex3f(500.0, -3.0, -500.0);
    glEnd();

    //lantai 1 - 4
    silinder(0.3, 0.3, 0.3, 0, 0, 0, 50, 100);
    silinder(0.741f, 0.741f, 0.713f, 0, 0, 50, 70, 5);
    silinder(0.741f, 0.741f, 0.713f, 0, 0, 100, 70, 5);
    silinder(0.741f, 0.741f, 0.713f, 0, 0, 150, 70, 5);
    silinder(0.741f, 0.741f, 0.713f, 0, 0, 200, 70, 5);

    //lantai 1 - 4
    kubus(0.1, 0.3, 0.5, -90, 24.8, 20, 100, 50, 4.90, -10);
    kubus(0.4, 0.2, 0.5, -90, 49.8, 20, 100, 50, 4.90, -10);
    kubus(0.6, 0.1, 0.5, -90, 74.8, 20, 100, 50, 4.90, -10);
    kubus(0.2, 0.7, 0.5, -80, 99.8, 10, 100, 50, 4.90, -20);

    //belakang mall
    kubus(0.2, 0.4, 0.3, -80, 0, -80, 100, 160, 99.9, 0);

    //pilar-pilar
    silinder(0.413f, 0.413f, 0.4f, -20, -60, 0, 5, 100);
    silinder(0.413f, 0.413f, 0.4f, -50, -35, 0, 5, 100);
    silinder(0.413f, 0.413f, 0.4f, 20, -60, 0, 5, 100);

    //Gedung kanan dalam 
    kubus(0.4, 0.4, 0.4, 90, 25.1, 10, 100, 100, 74.9, 0);

    //Gedung kanan dalam (bawah)
    kubus(0.4, 0.4, 0.4, 100, 0, 17, 100, 100, 25, 0);

    //Gedung kanan luar
    kubus(0.4, 0.4, 0.4, 150, 24.9, 60, 150, 100, 75.1, 0);

    //Gedung kanan luar bawah
    kubus(0.3, 0.3, 0.3, 149, 0, 40, 152.1, 100, 99.9, 0);

    //gedung silinder besar
    silinder(0.4, 0.4, 0.4, 70, -70, 50, 40, 75.1);

    //gedung silinder lobby
    silinder(0.3, 0.3, 0.3, 70, -70, 0, 20, 25);

    //pilar kanan 
    silinder(0.413f, 0.413f, 0.4f, 40, -60, 0, 5, 25);
    silinder(0.413f, 0.413f, 0.4f, 43, -86, 0, 5, 25);
    silinder(0.413f, 0.413f, 0.4f, 65, -100, 0, 5, 25);
    silinder(0.413f, 0.413f, 0.4f, 95, -100, 0, 5, 25);
    silinder(0.413f, 0.413f, 0.4f, 125, -100, 0, 5, 25);
    silinder(0.413f, 0.413f, 0.4f, 155, -100, 0, 5, 25);
    silinder(0.413f, 0.413f, 0.4f, 185, -100, 0, 5, 25);
    silinder(0.413f, 0.413f, 0.4f, 215, -100, 0, 5, 25);

    //tembok atas gedung kanan (panjang)
    kubus(0.2, 0.2, 0.2, 145, 100, 75, 140, 5, 30, 0);

    //tembok kecil atas(kecil)
    kubus(0.35, 0.35, 0.35, 72, 100, 70, 15, 5, 29, -45);



    //////////////////////////////////////////
    //tembok kiri atas bagian depan
    glColor3f(0.2, 0.2, 0.2);
    glBegin(GL_QUADS);
    glVertex3f(64, 100, 66);
    glVertex3f(69, 100, 66);
    glVertex3f(69, 130, 66);
    glVertex3f(64, 130, 66);
    glEnd();

    //miring atas
    glColor3f(0.2, 0.2, 0.2);
    glBegin(GL_QUADS);
    glVertex3f(64, 130, 66);
    glVertex3f(69, 130, 66);
    glVertex3f(69, 110, 0);
    glVertex3f(64, 110, 0);
    glEnd();

    //kiri
    glColor3f(0.2, 0.2, 0.2);
    glBegin(GL_QUADS);
    glVertex3f(64, 100, 66);
    glVertex3f(64, 130, 66);
    glVertex3f(64, 110, 0);
    glVertex3f(64, 100, 0);
    glEnd();

    //kanan
    glColor3f(0.2, 0.2, 0.2);
    glBegin(GL_QUADS);
    glVertex3f(69, 100, 66);
    glVertex3f(69, 130, 66);
    glVertex3f(69, 110, 0);
    glVertex3f(69, 100, 0);
    glEnd();

    //penutup belakang
    glColor3f(0.2, 0.2, 0.2);
    glBegin(GL_QUADS);
    glVertex3f(64, 100, 0);
    glVertex3f(69, 100, 0);
    glVertex3f(69, 110, 0);
    glVertex3f(64, 110, 0);
    glEnd();

    ////////////////////////////////////////////

    //Bagian Kiri
    //lantai 1 - 4
    kubus(0.4, 0.2, 0.6, -145, 24.9, 60, 50, 140, 4.95, -15);
    kubus(0.2, 0.2, 0.6, -138, 49.9, 35, 50, 140, 4.95, -15);
    kubus(0.0, 0.2, 0.6, -129, 74.9, 10, 50, 140, 4.95, -15);
    kubus(0.8, 0.2, 0.6, -120, 99.9, -15, 50, 140, 4.95, -15);

    //pilar-pilar
    silinder(0.413f, 0.413f, 0.4f, -145, -127, 0, 5, 25);
    silinder(0.413f, 0.413f, 0.4f, -138, -100, 0, 5, 50);
    silinder(0.413f, 0.413f, 0.4f, -120, -40, 0, 5, 100);

    //Gedung
    kubus(0.0, 1.0, 0.6, -130, 24.9, -100, 125, 350, 75, -30);

    //Apartement
    kubus(0.3, 0.3, 0.3, -230, 0, 5, 125, 250, 120, 0);
    kubus(0.413f, 0.413f, 0.4f, -230, 24.9, 150, 125, 50, 95.1, 0);
    kubus(0.3, 0.3, 0.3, -230, 0, 200, 125, 50, 120, 0);

    //gedung mall belakang
    kubus(0.3, 0.3, 0.3, -34, 0, -150, 518, 290, 100.1, 0);

    // x = 0
    meja_bundar(0, 60, 60);
    meja_bundar(0, 110, 60);
    meja_bundar(0, 160, 60);

    // x = -36
    meja_bundar(-36, 60, 48);
    meja_bundar(-36, 110, 48);
    meja_bundar(-36, 160, 48);

    glPopMatrix();


    glutSwapBuffers();
}

/*
tombol pada keyboard:
"a": ke kiri
"d": ke kanan
"w": ke depan
"s": ke belakang
"z" : ke atas
"x" : ke bawah
"i" : rotasi ke bawah terhadap sumbu X
"k" : rotasi ke atas terhadap sumbu X
"j" : rotasi ke kiri terhadap sumbu Y
"l" : rotasi ke kanan terhadap sumbu Y
"m" : rotasi ke kiri terhadap sumbu Z
"n" : rotasi ke kanan terhadap sumbu Z
"Q" : Melihat interior
*/
void keyboard(unsigned char key, int x, int y)
{
    switch (key)
    {
    case 'a':
    case 'A':
        glTranslatef(5.0, 0.0, 0.0);
        break;
    case 'd':
    case 'D':
        glTranslatef(-5.0, 0.0, 0.0);
        break;
    case 'z':
    case 'Z':
        glTranslatef(0.0, 5.0, 0.0);
        break;
    case 'x':
    case 'X':
        glTranslatef(0.0, -5.0, 0.0);
        break;
    case 'w':
    case 'W':
        glTranslatef(0.0, 0.0, 5.0);
        break;
    case 's':
    case 'S':
        glTranslatef(0.0, 0.0, -5.0);
        break;
    case 'i':
    case 'I':
        glRotatef(3.0, 1.0, 0.0, 0.0);
        break;
    case 'k':
    case 'K':
        glRotatef(-3.0, 1.0, 0.0, 0.0);
        break;
    case 'j':
    case 'J':
        glRotatef(3.0, 0.0, 1.0, 0.0);
        break;
    case 'l':
    case 'L':
        glRotatef(-3.0, 0.0, 1.0, 0.0);
        break;
    case 'm':
    case 'M':
        glRotatef(3.0, 0.0, 0.0, 1.0);
        break;
    case 'n':
    case 'N':
        glRotatef(-3.0, 0.0, 0.0, 1.0);
        break;
    case 'q':
    case 'Q':
        if (is_depth)
        {
            is_depth = 0;
            glDisable(GL_DEPTH_TEST);
        }
        else
        {
            is_depth = 1;
            glEnable(GL_DEPTH_TEST);
        }
    }
    display();
}
void resize(int width, int height)
{
    if (height == 0) height = 1;
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0, width / height, 5.0, 2000.0);
    glTranslatef(0.0, -50.0, -250.0);
    glMatrixMode(GL_MODELVIEW);
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(900, 900);
    glutInitWindowPosition(40, 40);
    glutCreateWindow("Robinsons Place Manilla");
    init();
    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);
    glutMouseFunc(mouseButton);
    glutMotionFunc(mouseMove);
    glutReshapeFunc(resize);
    glutMainLoop();
    return 0;
}
