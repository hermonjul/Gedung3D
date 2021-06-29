#include <stdlib.h>
#include <windows.h>
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
using namespace std;
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
    glClearColor(0.0, 1.0, 0.906, 0.0);
    glEnable(GL_DEPTH_TEST);
    glMatrixMode(GL_MODELVIEW);
    glPointSize(9.0);
    glLineWidth(6.0f);

}
void display(void)
{

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glClear(GL_COLOR_BUFFER_BIT);
    glPushMatrix();
    glRotatef(xrot, 1, 0, 0);
    glRotatef(yrot, 0, 1, 0);

    glBegin(GL_QUADS);//Jalan halaman Rumah
    glColor3f(0.2f, 0.2f, 0.2f);
    glVertex3f(-200.0, -3.0, -200.0);
    glColor3f(0.4f, 0.4f, 0.4f);
    glVertex3f(-200.0, -3.0, 200.0);
    glColor3f(0.6f, 0.6f, 0.6f);
    glVertex3f(200.0, -3.0, 200.0);
    glColor3f(0.8f, 0.8f, 0.8f);
    glVertex3f(200.0, -3.0, -200.0);
    glEnd();
    glBegin(GL_LINE_LOOP);//Garis Halaman rumah
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex3f(-200.0, -3.0, -200.0);
    glVertex3f(-200.0, -3.0, 200.0);
    glVertex3f(200.0, -3.0, 200.0);
    glVertex3f(200.0, -3.0, -200.0);
    glEnd();
    glBegin(GL_QUADS);//garis depan rumah`
    glColor3f(1.0f, 0.408f, 0.0f);
    glVertex3f(-50.0, 0.0, 100.1);
    glVertex3f(-50.0, 50.0, 100.1);
    glVertex3f(50.0, 50.0, 100.1);
    glVertex3f(50.0, 0.0, 100.1);
    glEnd();
    glBegin(GL_QUADS);// pintu rumah
    glColor3f(0.671f, 0.322f, 0.0f);
    glVertex3f(-15.1, 0.0, 100.5);
    glVertex3f(-15.1, 40.0, 100.5);
    glVertex3f(15.1, 40.0, 100.5);
    glVertex3f(15.1, 0.0, 100.5);
    glEnd();
    glBegin(GL_LINE_LOOP);//garis pintu rumah
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex3f(-15.1, 0.0, 100.6);
    glVertex3f(-15.1, 40.0, 100.6);
    glVertex3f(15.1, 40.0, 100.6);
    glVertex3f(15.1, 0.0, 100.6);
    glEnd();
    glBegin(GL_TRIANGLES);//atap depan rumah
    glColor3f(0.165f, 0.09f, 0.004f);
    glVertex3f(0.0, 100.0, 100.0);
    glVertex3f(50.0, 50.0, 100.0);
    glVertex3f(-50.0, 50.0, 100.0);
    glEnd();
    glBegin(GL_LINE_LOOP);//garis atap depan rumah
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex3f(0.0, 100.0, 100.0);
    glVertex3f(50.0, 50.0, 100.0);
    glVertex3f(-50.0, 50.0, 100.0);
    glEnd();
    glBegin(GL_QUADS);//kiri
    glColor3f(1.0f, 0.408f, 0.0f);
    glVertex3f(-50.0, 0.0, 100.0);
    glVertex3f(-50.0, 50.0, 100.0);
    glVertex3f(-50.0, 50.0, -100.0);
    glVertex3f(-50.0, 0.0, -100.0);
    glEnd();
    glBegin(GL_LINE_LOOP);//garis kiri
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex3f(-50.0, 0.0, 100.0);
    glVertex3f(-50.0, 50.0, 100.0);
    glVertex3f(-50.0, 50.0, -100.0);
    glVertex3f(-50.0, 0.0, -100.0);
    glEnd();
    glBegin(GL_QUADS);//atap  kiri
    glColor3f(0.165f, 0.09f, 0.004f);
    glVertex3f(-50.0, 50.0, -100.0);
    glVertex3f(0.0, 100.0, -100.0);
    glVertex3f(0.0, 100.0, 100.0);
    glVertex3f(-50.0, 50.0, 100.0);
    glEnd();
    glBegin(GL_LINE_LOOP);//garis atap kiri
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex3f(-50.0, 50.0, -100.0);
    glVertex3f(0.0, 100.0, -100.0);
    glVertex3f(0.0, 100.0, 100.0);
    glVertex3f(-50.0, 50.0, 100.0);
    glEnd();
    glBegin(GL_QUADS);//samping kanan
    glColor3f(1.0f, 0.408f, 0.0f);
    glVertex3f(50.0, 0.0, 100.0);
    glVertex3f(50.0, 50.0, 100.0);
    glVertex3f(50.0, 50.0, -100.0);
    glVertex3f(50.0, 0.0, -100.0);
    glEnd();
    glBegin(GL_LINE_LOOP);//garis samping kanan
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex3f(50.0, 0.0, 100.0);
    glVertex3f(50.0, 50.0, 100.0);
    glVertex3f(50.0, 50.0, -100.0);
    glVertex3f(50.0, 0.0, -100.0);
    glEnd();
    glBegin(GL_QUADS);//jendela  kiri
    glColor3f(0.345f, 0.333f, 0.333f);
    glVertex3f(51.1, 30.0, 40.0);
    glVertex3f(51.1, -2.0, 40.0);
    glVertex3f(51.1, -2.0, 70.0);
    glVertex3f(51.1, 30.0, 70.0);
    glEnd();
    glBegin(GL_LINE_LOOP);//garis jendela kiri
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex3f(51.1, 30.0, 40.0);
    glVertex3f(51.1, -2.0, 40.0);
    glVertex3f(51.1, -2.0, 70.0);
    glVertex3f(51.1, 30.0, 70.0);
    glEnd();
    glBegin(GL_QUADS);//jendela  kanan
    glColor3f(0.345f, 0.333f, 0.333f);
    glVertex3f(51.1, 30.0, -50.0);
    glVertex3f(51.1, -1.0, -50.0);
    glVertex3f(51.1, -1.0, -70.0);
    glVertex3f(51.1, 30.0, -70.0);
    glEnd();
    glBegin(GL_LINE_LOOP);//garis jendela kanan
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex3f(51.1, 30.0, -50.0);
    glVertex3f(51.1, -1.0, -50.0);
    glVertex3f(51.1, -1.0, -70.0);
    glVertex3f(51.1, 30.0, -70.0);
    glEnd();
    glBegin(GL_QUADS);//pintu samping
    glColor3f(0.671f, 0.322f, 0.0f);
    glVertex3f(51.1, 30.0, 20.0);
    glVertex3f(51.1, -2.0, 20.0);
    glVertex3f(51.1, -2.0, 0.0);
    glVertex3f(51.1, 30.0, 0.0);
    glEnd();
    glBegin(GL_LINE_LOOP);//garis pintu samping
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex3f(51.1, 30.0, 20.0);
    glVertex3f(51.1, -2.0, 20.0);
    glVertex3f(51.1, -2.0, 0.0);
    glVertex3f(51.1, 30.0, 0.0);
    glEnd();
    glBegin(GL_QUADS);//atap samping kanan
    glColor3f(0.165f, 0.09f, 0.004f);
    glVertex3f(50.0, 50.0, 100.0);
    glVertex3f(0.0, 100.0, 100.0);
    glVertex3f(0.0, 100.0, -100.0);
    glVertex3f(50.0, 50.0, -100.0);
    glEnd();
    glBegin(GL_LINE_LOOP);//garis atap samping kanan
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex3f(50.0, 50.0, 100.0);
    glVertex3f(0.0, 100.0, 100.0);
    glVertex3f(0.0, 100.0, -100.0);
    glVertex3f(50.0, 50.0, -100.0);
    glEnd();

    glBegin(GL_QUADS);//belakang
    glColor3f(1.0f, 0.408f, 0.0f);
    glVertex3f(-50.0, 0.0, -100.0);
    glVertex3f(-50.0, 50.0, -100.0);
    glVertex3f(50.0, 50.0, -100.0);
    glVertex3f(50.0, 0.0, -100.0);
    glEnd();
    glBegin(GL_LINE_LOOP);//garis belakang
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex3f(-50.0, 0.0, -100.0);
    glVertex3f(-50.0, 50.0, -100.0);
    glVertex3f(50.0, 50.0, -100.0);
    glVertex3f(50.0, 0.0, -100.0);
    glEnd();
    glBegin(GL_TRIANGLES);//atap belakang
    glColor3f(0.165f, 0.09f, 0.004f);
    glVertex3f(0.0, 100.0, -100.0);
    glVertex3f(-50.0, 50.0, -100.0);
    glVertex3f(50.0, 50.0, -100.0);
    glEnd();
    glBegin(GL_LINE_LOOP);//garis atap belakang
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex3f(0.0, 100.0, -100.0);
    glVertex3f(-50.0, 50.0, -100.0);
    glVertex3f(50.0, 50.0, -100.0);
    glEnd();
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
    gluPerspective(45.0, width / height, 1.0, 400.0);
    glTranslatef(0.0, -5.0, -150.0);
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