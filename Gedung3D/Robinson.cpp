#include <stdlib.h>
#include <windows.h>
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include <math.h>
#include "loadImageBMP.h"

using namespace std;

GLuint _textureID;
GLuint _textureID1;
GLuint _textureID2;

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
void kursi(float x, float y, float z);



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

    _textureID = loadBMP_custom("robinson.bmp");
    _textureID1 = loadBMP_custom("robinson.bmp");
    _textureID2 = loadBMP_custom("tembok.bmp");


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

void kursi(float x, float y, float z) {
    kubus(0.396f, 0.337f, 0.243f, x, y, z, 0.5, 0.5, 2, 0);
    kubus(0.396f, 0.337f, 0.243f, x, y, z + 2, 0.5, 0.5, 2, 0);
    kubus(0.396f, 0.337f, 0.243f, x + 2, y, z, 0.5, 0.5, 2, 0);
    kubus(0.396f, 0.337f, 0.243f, x + 2, y, z + 2, 0.5, 0.5, 2, 0);
    //alas kursi
    kubus(0.396f, 0.337f, 0.243f, x + 1, y + 2, z + 1, 4, 4, 0.5, 0);
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

void silinder_tempat_sampah(float red, float green, float blue, float x, float y, float z, float jari_jari, float tinggi) {
    //selimut
    glPushMatrix();
    glColor3f(red, green, blue);
    glRotatef(-90, 1.0f, 0.0f, 0.0f);
    glTranslatef(x, y, z / 2.0f);
    gluCylinder(p, jari_jari, jari_jari, tinggi, 360, 1);
    glPopMatrix();

    //bawah
    glPushMatrix();
    glColor3f(0.5, 0.5, 0.5);
    glRotatef(-90, 1.0f, 0.0f, 0.0f);
    glTranslatef(x, y, z / 2.0f);
    gluDisk(p, 0, jari_jari, 360, 1);
    glPopMatrix();

    //atas
    glPushMatrix();
    glColor3f(0.2, 0.2, 0.2);
    glRotatef(-90, 1.0f, 0.0f, 0.0f);
    glTranslatef(x, y, z / 2.0f + tinggi);
    gluDisk(p, 0, jari_jari, 360, 1);
    glPopMatrix();

}


void silinder_ban(float red, float green, float blue, float x, float y, float z, float jari_jari, float tinggi) {
    //selimut
    glPushMatrix();
    glColor3f(red, green, blue);
    glRotatef(0, 1.f, 0.f, 0.f);
    glTranslatef(x, y, z / 2.0f);
    gluCylinder(p, jari_jari, jari_jari, tinggi, 360, 1);
    glPopMatrix();

    //bawah
    glPushMatrix();
    glColor3f(0.8, 0.8, 0.8);
    glRotatef(0, 1.f, 0.f, 0.f);
    glTranslatef(x, y, z / 2.0f);
    gluDisk(p, 0, jari_jari, 360, 1);
    glPopMatrix();

    //atas
    glPushMatrix();
    glColor3f(0.8, 0.8, 0.8);
    glRotatef(0, 1.f, 0.f, 0.f);
    glTranslatef(x, y, z / 2.0f + tinggi);
    gluDisk(p, 0, jari_jari, 360, 1);
    glPopMatrix();

}

void mobil(float red, float green, float blue, float x, float y, float z) {
    silinder_ban(0, 0, 0, x, y, z, 3, 5);
    silinder_ban(0, 0, 0, x, y, z + 25, 3, 5);
    silinder_ban(0, 0, 0, x - 20, y, z, 3, 5);
    silinder_ban(0, 0, 0, x - 20, y, z + 25, 3, 5);
    kubus(red, green, blue, x - 10, y, (z / 2) + 9, 35, 12, 5, 0);
    kubus(red, green, blue, x - 10, y, (z / 2) + 9, 20, 12, 10, 0);
}


void meja_bundar(float x, float y, float z) {
    //atas meja
    silinderMeja(0.813f, 0.694f, 0.494f, x, -z, y + (4 * 2), 5, 0.2);
    //tiang meja
    kubus(0.813f, 0.694f, 0.494f, x, y / 2, z, 1, 1, 4, 0);
    //alas meja
    silinderMeja(0.813f, 0.694f, 0.494f, x, -z, y, 3, 0.2);
}

void patung(float x, float y, float z) {
    //Kepala
    kubus(0.813f, 0.694f, 0.494f, x, y + 15, z, 4, 4, 4, 0);
    //badan
    kubus(0.0, 0.0, 1.0, x, y + 6, z, 4, 4, 9, 0);
    //tangankiri
    kubus(0.813f, 0.694f, 0.494f, x + (-3), y + 8, z, 2, 4, 7, 0);
    //tangankanan
    kubus(0.813f, 0.694f, 0.494f, x + 3, y + 8, z, 2, 4, 7, 0);
    //Kaki
    kubus(0.396f, 0.337f, 0.243f, x, y, z, 4, 4, 9, 0);
}

void tempat_sampah(float x, float y, float z) {
    silinder_tempat_sampah(0.5f, 0.5f, 0.5f, x, -z, y + 2, 1, 3);
    silinder_tempat_sampah(0.6f, 0.6f, 0.6f, x, -z, y + 8, 1.5, 1.5);
    silinder_tempat_sampah(0.4f, 0.4f, 0.4f, x, -z, y, 0.6, 2);
}



void display(void)
{
    GLfloat theta;
    glEnable(GL_TEXTURE_2D);


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
    silinder(0.2706, 0.482, 0.6157, 0, 0, 0, 50, 100);
    silinder(0.741f, 0.741f, 0.713f, 0, 0, 50, 70, 5);
    silinder(0.741f, 0.741f, 0.713f, 0, 0, 100, 70, 5);
    silinder(0.741f, 0.741f, 0.713f, 0, 0, 150, 70, 5);
    silinder(0.741f, 0.741f, 0.713f, 0, 0, 200, 70, 5);

    //lantai 1 - 4
    kubus(0.741f, 0.741f, 0.713f, -90, 24.8, 20, 100, 50, 4.90, -10);
    kubus(0.741f, 0.741f, 0.713f, -90, 49.8, 20, 100, 50, 4.90, -10);
    kubus(0.741f, 0.741f, 0.713f, -90, 74.8, 20, 100, 50, 4.90, -10);
    kubus(0.741f, 0.741f, 0.713f, -80, 99.8, 10, 100, 50, 4.90, -20);

    //belakang mall
    kubus(0.413f, 0.413f, 0.4f, -80, 0, -80, 100, 160, 99.9, 0);

    //pilar-pilar
    silinder(0.813f, 0.694f, 0.494f, -20, -60, 0, 5, 100);
    silinder(0.813f, 0.694f, 0.494f, -50, -35, 0, 5, 100);
    silinder(0.813f, 0.694f, 0.494f, 20, -60, 0, 5, 100);

    //Gedung kanan dalam 
    kubus(0.4, 0.4, 0.4, 90, 25.1, 10, 100, 100, 74.9, 0);

    //Gedung kanan dalam (bawah)
    kubus(0.4, 0.4, 0.4, 100, 0, 17, 100, 100, 25, 0);

    //Gedung kanan luar
    kubus(0.4, 0.4, 0.4, 150, 24.9, 60, 150, 100, 75.1, 0);

    //Gedung kanan luar bawah
    kubus(0.3, 0.3, 0.3, 149, 0, 40, 152.1, 100, 99.9, 0);

    //gedung silinder besar
    silinder(0.321, 0.564, 0.717, 70, -70, 50, 40, 75.1);

    //gedung silinder lobby
    silinder(0.101, 0.458, 0.623, 70, -70, 0, 20, 25);

    //pilar kanan 
    silinder(0.741f, 0.741f, 0.713f, 40, -60, 0, 5, 25);
    silinder(0.741f, 0.741f, 0.713f, 43, -86, 0, 5, 25);
    silinder(0.741f, 0.741f, 0.713f, 65, -100, 0, 5, 25);
    silinder(0.741f, 0.741f, 0.713f, 95, -100, 0, 5, 25);
    silinder(0.741f, 0.741f, 0.713f, 125, -100, 0, 5, 25);
    silinder(0.741f, 0.741f, 0.713f, 155, -100, 0, 5, 25);
    silinder(0.741f, 0.741f, 0.713f, 185, -100, 0, 5, 25);
    silinder(0.741f, 0.741f, 0.713f, 215, -100, 0, 5, 25);

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
    kubus(0.741f, 0.741f, 0.713f, -145, 24.9, 60, 50, 140, 4.95, -15);
    kubus(0.741f, 0.741f, 0.713f, -138, 49.9, 35, 50, 140, 4.95, -15);
    kubus(0.741f, 0.741f, 0.713f, -129, 74.9, 10, 50, 140, 4.95, -15);
    kubus(0.741f, 0.741f, 0.713f, -120, 99.9, -15, 50, 140, 4.95, -15);

    //pilar-pilar
    silinder(0.413f, 0.413f, 0.4f, -145, -127, 0, 5, 25);
    silinder(0.413f, 0.413f, 0.4f, -138, -100, 0, 5, 50);
    silinder(0.413f, 0.413f, 0.4f, -120, -40, 0, 5, 100);

    //Gedung
    kubus(0.3, 0.3, 0.3f, -130, 24.9, -100, 125, 350, 75, -30);

    //Apartement
    kubus(0.3, 0.3, 0.3, -230, 0, 5, 125, 250, 100, 0);
    kubus(0.413f, 0.413f, 0.4f, -230, 24.9, 150, 125, 50, 75.1, 0);
    kubus(0.3, 0.3, 0.3, -230, 0, 200, 125, 50, 100, 0);
    kubus(0.513f, 0.513f, 0.5f, -230, 100, 30, 125, 295, 240, 0);

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

    // x = -7
    kursi(-7, 30, 60);
    kursi(-7, 55, 60);
    kursi(-7, 80, 60);

    // x = 5
    kursi(5, 30, 60);
    kursi(5, 55, 60);
    kursi(5, 80, 60);

    //x = -30
    kursi(-30, 30, 48);
    kursi(-30, 55, 48);
    kursi(-30, 80, 48);

    //x = -44
    kursi(-44, 30, 48);
    kursi(-44, 55, 48);
    kursi(-44, 80, 48);

    //patung
    int y_patung = 0, z_patung = -150;
    for (int i = 0; i < 5; i++) {
        int x_patung = 0;
        for (int j = 0; j < 8; j++) {
            patung(x_patung, y_patung, z_patung);
            x_patung -= 20;
        }
        z_patung -= 25;
    }

    /*patung(-20, 0, -300);
    patung(-20, 0, -250);
    patung(-20, 0, -200);
    patung(0, 0, -300);
    patung(0, 0, -250);
    patung(0, 0, -200);*/

    //foodcourt
    int y_meja = 0, z_meja = -150;
    int y_kursi = 0, z_kursi = -150;
    int y_kursi2 = 0, z_kursi2 = -150;
    for (int i = 0; i < 4; i++) {
        int x_meja = 100;
        int x_kursi = 92;
        int x_kursi2 = 108;
        for (int j = 0; j < 3; j++)
        {
            meja_bundar(x_meja, y_meja, z_meja);
            kursi(x_kursi, y_kursi, z_kursi);
            kursi(x_kursi2, y_kursi2, z_kursi2);
            x_meja += 35;
            x_kursi += 35;
            x_kursi2 += 35;
        }
        z_meja -= 35;
        z_kursi -= 35;
        z_kursi2 -= 35;
    }

    //Tempat sampah (depan)
    tempat_sampah(13, 60, 60);
    tempat_sampah(13, 110, 60);
    tempat_sampah(13, 160, 60);
    //tempat sampah (dalam)
    tempat_sampah(60, 0, -210);

    //mobil pameran
    mobil(0, 0, 1, 50, 5, -400);
    //mobil diluar
    mobil(0, 1, 0, -180, 0, 285);

    //tekstur tembok
    glBindTexture(GL_TEXTURE_2D, _textureID2);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_QUADS);
    glTexCoord2f(0.0, 0.0);
    glVertex3f(70.0, 25, 110.1);
    glTexCoord2f(5.0, 0.0);
    glVertex3f(225.0, 25, 110.1);
    glTexCoord2f(5.0, 5.0);
    glVertex3f(225.0, 100, 110.1);
    glTexCoord2f(0.0, 5.0);
    glVertex3f(70.0, 100, 110.1);
    glEnd();

    //tembok belakang
    glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_QUADS);
    glTexCoord2f(0.0, 0.0);
    glVertex3f(-293.0, 0, -295.1);
    glTexCoord2f(5.0, 0.0);
    glVertex3f(225.0, 0, -295.1);
    glTexCoord2f(5.0, 5.0);
    glVertex3f(225.0, 100, -295.1);
    glTexCoord2f(0.0, 5.0);
    glVertex3f(-293.0, 100, -295.1);
    glEnd();

    //tembok kanan 
    glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_QUADS);
    glTexCoord2f(0.0, 0.0);
    glVertex3f(225.1, 0, 90);
    glTexCoord2f(4.0, 0.0);
    glVertex3f(225.1, 0, -295);
    glTexCoord2f(4.0, 4.0);
    glVertex3f(225.1, 100, -295);
    glTexCoord2f(0.0, 4.0);
    glVertex3f(225.1, 100, 90);
    glEnd();


    //tembok kanan tambal
    glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_QUADS);
    glTexCoord2f(0.0, 0.0);
    glVertex3f(225.1, 25, 90);
    glTexCoord2f(5.0, 0.0);
    glVertex3f(225.1, 25, 110);
    glTexCoord2f(5.0, 5.0);
    glVertex3f(225.1, 100, 110);
    glTexCoord2f(0.0, 5.0);
    glVertex3f(225.1, 100, 90);
    glEnd();

    //tembok apartment
    glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_QUADS);
    glTexCoord2f(0.0, 0.0);
    glVertex3f(-293.1, 0, 225.1);
    glTexCoord2f(5.0, 0.0);
    glVertex3f(-167.5, 0, 225.1);
    glTexCoord2f(5.0, 5.0);
    glVertex3f(-167.5, 120, 225.1);
    glTexCoord2f(0.0, 5.0);
    glVertex3f(-293.0, 120, 225.1);
    glEnd();

    //tembok kiri
    glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_QUADS);
    glTexCoord2f(0.0, 0.0);
    glVertex3f(-293.1, 0, 130);
    glTexCoord2f(4.0, 0.0);
    glVertex3f(-293.1, 0, -295);
    glTexCoord2f(4.0, 4.0);
    glVertex3f(-293.1, 100, -295);
    glTexCoord2f(0.0, 4.0);
    glVertex3f(-293.1, 100, 130);
    glEnd();


    glBindTexture(GL_TEXTURE_2D, _textureID);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    //Papan nama mall
    glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_QUADS);
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(-40.0, 105, 50);
    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(40.0, 105, 50);
    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(40.0, 130, 50);
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(-40.0, 130, 50);
    glEnd();

    //papan nama mall (belakang)
    glColor3f(0.2, 0.2, 0.2);
    glBegin(GL_QUADS);
    glVertex3f(-40.0, 105, 45);
    glVertex3f(40.0, 105, 45);
    glVertex3f(40.0, 130, 45);
    glVertex3f(-40.0, 130, 45);
    glEnd();

    //papan nama mall (sisi atas)
    glColor3f(0.35, 0.35, 0.35);
    glBegin(GL_QUADS);
    glVertex3f(-40.0, 130, 50);
    glVertex3f(40.0, 130, 50);
    glVertex3f(40.0, 130, 45);
    glVertex3f(-40.0, 130, 45);
    glEnd();

    //papan nama mall (sisi kiri)
    glColor3f(0.33, 0.33, 0.33);
    glBegin(GL_QUADS);
    glVertex3f(-40.0, 105, 50);
    glVertex3f(-40.0, 105, 45);
    glVertex3f(-40.0, 130, 45);
    glVertex3f(-40.0, 130, 50);
    glEnd();

    //papan nama mall (sisi kanan)
    glColor3f(0.33, 0.33, 0.33);
    glBegin(GL_QUADS);
    glVertex3f(40.0, 105, 50);
    glVertex3f(40.0, 105, 45);
    glVertex3f(40.0, 130, 45);
    glVertex3f(40.0, 130, 50);
    glEnd();

    //apartment
    
    

    glBindTexture(GL_TEXTURE_2D, _textureID1);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    //papan nama kanan
    glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_QUADS);
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(75.0, 100, 78.1);
    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(215.0, 100, 78.1);
    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(215.0, 130, 78.1);
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(75.0, 130, 78.1);
    glEnd();





    glPopMatrix();


    glutSwapBuffers();
    glDisable(GL_TEXTURE_2D);
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
