#include <stdlib.h>
#include <windows.h>
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include <math.h>
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
void kubus(float x, float y, float z, float panjang, float lebar, float tinggi);

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

void silinder(float red, float green, float blue, float x, float y, float z, float jari_jari,  float tinggi) {
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

void kubus(float x, float y, float z, float panjang, float lebar, float tinggi) {
    glPushMatrix();
    glColor3f(0.9, 0.4, 0.3);
    glTranslatef(x, y + tinggi / 2, z);
    glScalef(panjang, tinggi, lebar);
    glutSolidCube(1);
    glPopMatrix();
}



void display(void)
{
    GLfloat theta;
   
    
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glClear(GL_COLOR_BUFFER_BIT);
    glPushMatrix();
    glRotatef(xrot, 1, 0, 0);
    glRotatef(yrot, 0, 1, 0);

    glBegin(GL_QUADS);//Jalan halaman Rumah
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex3f(-500.0, -3.0, -500.0);
    glColor3f(0.4f, 0.4f, 0.4f);
    glVertex3f(-500.0, -3.0, 500.0);
    glColor3f(0.6f, 0.6f, 0.6f);
    glVertex3f(500.0, -3.0, 500.0);
    glColor3f(0.8f, 0.8f, 0.8f);
    glVertex3f(500.0, -3.0, -500.0);
    glEnd();
    glBegin(GL_LINE_LOOP);//Garis Halaman rumah
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex3f(-500.0, -3.0, -500.0);
    glVertex3f(-500.0, -3.0, 500.0);
    glVertex3f(500.0, -3.0, 500.0);
    glVertex3f(500.0, -3.0, -500.0);
    glEnd();
   
    
    silinder(0.1, 0.5, 0.8, 0, 0, 0, 50, 50);
    silinder(0.2, 0.4, 0.7, 60, 0, 50, 50, 50);
    silinder(0.3, 0.7, 0.6, -60, 0, 50, 50, 50);
    kubus(70, 0, 0, 50, 50, 50);
    
   


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
    gluPerspective(45.0, width / height, 5.0, 400.0);
    glTranslatef(0.0, -20.0, -250.0);
    glMatrixMode(GL_MODELVIEW);
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(900, 900);
    glutInitWindowPosition(40, 40);
    glutCreateWindow("Fungsi Mouse dan Keyboardss");
    init();
    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);
    glutMouseFunc(mouseButton);
    glutMotionFunc(mouseMove);
    glutReshapeFunc(resize);
    glutMainLoop();
    return 0;
}
