#include <windows.h>
#include <stdlib.h>
#include <GL/glut.h>

void init (void);
void tampil (void);
void mouse (int button, int state, int x, int y);
void ukuran (int, int);
void mouseMotion (int x, int y);
void keyboard(unsigned char key, int , int);

float xrot = 0.0f;
float yrot = 0.0f;
float xdiff = 0.0f;
float ydiff = 0.0f;
bool mouseDown = false;
int is_depth;




void init (void)
{
	glClearColor (0.0, 0.0, 0.0, 1.0);
	glMatrixMode (GL_PROJECTION);
	glEnable (GL_LIGHTING);
	glEnable (GL_COLOR_MATERIAL);
	glEnable (GL_LIGHT0);
	glEnable (GL_DEPTH_TEST);
	is_depth = 1;
	glMatrixMode (GL_MODELVIEW);
	glPointSize (10.0f);
	glLineWidth (6.0f);
}

void tampil (void)
{
	glPushMatrix();
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	gluLookAt(0.0f, 0.0f, 3.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f);
	glRotatef(xrot, 1.0f, 0.0f, 0.0f);
	glRotatef(yrot, 1.0f, 1.0f, 0.0f);


//LAPANGAN
      //belakang
    //benderakanan
    glBegin(GL_TRIANGLES);
    glColor3f(1,1,0);
    glVertex3f(48.2, -17.0, -30.0);
    glVertex3f(52.0, -15.0, -30.0);
    glVertex3f(48.2, -13.0, -30.0);
    glEnd();
	//tiang bendera
    glBegin(GL_LINE_STRIP);
    glColor3f(0,0,0);
    glVertex3f(48.0, -20.0, -30.0);
    glVertex3f(48.0, -13.0, -30.0);
    glVertex3f(48.0, -13.0, -30.0);
    glVertex3f(48.0, -20.0, -30.0);
    glEnd();
     //benderakiri
    glBegin(GL_TRIANGLES);
    glColor3f(1,1,0);
    glVertex3f(-40.2, -17.0, -30.0);
    glVertex3f(-44.0, -15.0, -30.0);
    glVertex3f(-40.2, -13.0, -30.0);
    glEnd();
	//tiang bendera
    glBegin(GL_LINE_STRIP);
    glColor3f(0,0,0);
    glVertex3f(-40.0, -20.0, -30.0);
    glVertex3f(-40.0, -13.0, -30.0);
    glVertex3f(-40.0, -13.0, -30.0);
    glVertex3f(-40.0, -20.0, -30.0);
    glEnd();
    //depan
    //benderakanan
    glBegin(GL_TRIANGLES);
    glColor3f(1,1,0);
    glVertex3f(48.2, -17.0, 30.0);
    glVertex3f(52.0, -15.0, 30.0);
    glVertex3f(48.2, -13.0, 30.0);
    glEnd();
	//tiang bendera
    glBegin(GL_LINE_STRIP);
    glColor3f(0,0,0);
    glVertex3f(48.0, -20.0, 30.0);
    glVertex3f(48.0, -13.0, 30.0);
    glVertex3f(48.0, -13.0, 30.0);
    glVertex3f(48.0, -20.0, 30.0);
    glEnd();
     //benderakiri
    glBegin(GL_TRIANGLES);
    glColor3f(1,1,0);
    glVertex3f(-40.2, -17.0, 30.0);
    glVertex3f(-44.0, -15.0, 30.0);
    glVertex3f(-40.2, -13.0, 30.0);
    glEnd();
	//tiang bendera
    glBegin(GL_LINE_STRIP);
    glColor3f(0,0,0);
    glVertex3f(-40.0, -20.0, 30.0);
    glVertex3f(-40.0, -13.0, 30.0);
    glVertex3f(-40.0, -13.0, 30.0);
    glVertex3f(-40.0, -20.0, 30.0);
    glEnd();
	//lapangan1
	glBegin(GL_POLYGON);
	glColor3f (0.0,0.9,0.0);
	glVertex3f (-32.0, -20.0, 30.0);
	glVertex3f (-24.0, -20.0, 30.0);
	glVertex3f (-24.0, -20.0, -30.0);
	glVertex3f (-32.0, -20.0, -30.0);
	glEnd();
	glBegin(GL_POLYGON);//2
	glColor3f (0.0,0.9,0.0);
    glVertex3f (-16.0, -20.0, 30.0);
	glVertex3f (-8.0, -20.0, 30.0);
	glVertex3f (-8.0, -20.0, -30.0);
	glVertex3f (-16.0, -20.0, -30.0);
	glEnd();
	glBegin(GL_POLYGON);//3
	glColor3f (0.0,0.9,0.0);
    glVertex3f (0.0, -20.0, 30.0);
	glVertex3f (8.0, -20.0, 30.0);
	glVertex3f (8.0, -20.0, -30.0);
	glVertex3f (0.0, -20.0, -30.0);
	glEnd();
	glBegin(GL_POLYGON);//4
	glColor3f (0.0,0.9,0.0);
    glVertex3f (16.0, -20.0, 30.0);
	glVertex3f (24.0, -20.0, 30.0);
	glVertex3f (24.0, -20.0, -30.0);
	glVertex3f (16.0, -20.0, -30.0);
	glEnd();
    glBegin(GL_POLYGON);//4
	glColor3f (0.0,0.9,0.0);
    glVertex3f (32.0, -20.0, 30.0);
	glVertex3f (40.0, -20.0, 30.0);
	glVertex3f (40.0, -20.0, -30.0);
	glVertex3f (32.0, -20.0, -30.0);
	glEnd();

	//lapngan
	glBegin (GL_QUADS);
	glColor3f(0.0, 0.5, 0.0);
	glVertex3f (-40.0, -20.0, 30.0);
	glVertex3f (48.0, -20.0, 30.0);
	glVertex3f (48.0, -20.0, -30.0);
	glVertex3f (-40.0, -20.0, -30.0);
	glEnd();

//GAWANG

	//gawang kanan
	glBegin (GL_LINE_STRIP);
	glColor3f(1.0, 1.0, 1.0);
	glVertex3f (48.0, -20.0, 10.0);
	glVertex3f (48.0, -10.0, 10.0);
	glVertex3f (50.0, -10.0, 10.0);
	glVertex3f (56.0, -20.0, 10.0);
	glEnd();
	glBegin (GL_LINE_STRIP);
	glVertex3f (48.0, -20.0, -10.0);
	glVertex3f (48.0, -10.0, -10.0);
	glVertex3f (50.0, -10.0, -10.0);
	glVertex3f (56.0, -20.0, -10.0);
	glEnd();
	glBegin (GL_LINE_STRIP);
	glVertex3f (48.0, -10.0, 10.0);
	glVertex3f (48.0, -10.0, -10.0);
	glEnd();
	glBegin (GL_LINE_STRIP);
	glVertex3f (56.0, -20.0, 10.0);
	glVertex3f (56.0, -20.0, -10.0);
	glEnd();

	//gawang kiri
	glBegin (GL_LINE_STRIP);
	glColor3f(1.0, 1.0, 1.0);
	glVertex3f (-40.0, -20.0, 10.0);
	glVertex3f (-40.0, -10.0, 10.0);
	glVertex3f (-42.0, -10.0, 10.0);
	glVertex3f (-48.0, -20.0, 10.0);
	glEnd();
	glBegin (GL_LINE_STRIP);
	glVertex3f (-40.0, -20.0, -10.0);
	glVertex3f (-40.0, -10.0, -10.0);
	glVertex3f (-42.0, -10.0, -10.0);
	glVertex3f (-48.0, -20.0, -10.0);
	glEnd();
	glBegin (GL_LINE_STRIP);
	glVertex3f (-40.0, -10.0, 10.0);
	glVertex3f (-40.0, -10.0, -10.0);
	glEnd();
	glBegin (GL_LINE_STRIP);
	glVertex3f (-48.0, -20.0, 10.0);
	glVertex3f (-48.0, -20.0, -10.0);
	glEnd();

    //garis2
    glBegin (GL_LINE_STRIP);
	glColor3f(1.0, 1.0, 1.0);
	glVertex3f (4.0, -20.0, 30.0);
	glVertex3f (4.0, -20.0, -30.0);
	glEnd();
	//ijo tambahan depan
    glBegin(GL_QUADS);
    glColor3f(0.0, 0.5, 0.0);
	glVertex3f (-48.0, -20.0, 40.0);
	glVertex3f (-48.0, -20.0, 30.0);
	glVertex3f (56.0, -20.0, 30.0);
	glVertex3f (56.0, -20.0, 40.0);
	glEnd();
	//pinggir depan (diperlebar)
    glBegin(GL_QUADS);
    glColor3f(0.0, 1.0, 1.0);
	glVertex3f (-58.0, -20.0, 60.0);
	glVertex3f (-58.0, -20.0, 40.0);
	glVertex3f (68.0, -20.0, 40.0);
	glVertex3f (68.0, -20.0, 60.0);
	glEnd();
    //ijo tambahan belakang
    glBegin(GL_QUADS);
    glColor3f(0.0, 0.5, 0.0);
	glVertex3f (-48.0, -20.0, -40.0);
	glVertex3f (-48.0, -20.0, -30.0);
	glVertex3f (56.0, -20.0, -30.0);
	glVertex3f (56.0, -20.0, -40.0);
	glEnd();
	//pingigr belakang (diperlebar)
	glBegin(GL_QUADS);
    glColor3f(0.0, 1.0, 1.0);
	glVertex3f (-58.0, -20.0, -40.0);
	glVertex3f (-58.0, -20.0, -60.0);
	glVertex3f (68.0, -20.0, -60.0);
	glVertex3f (68.0, -20.0, -40.0);
	glEnd();
    //lapangan (diperlebar)
    //glBegin (GL_QUADS);
	//glColor3f(0.0, 0.5, 0.0);
	//glVertex3f (48.0, -20.0, 30.0);
	//glVertex3f (50.0, -20.0, 30.0);
	//glVertex3f (50.0, -20.0, -30.0);
	//glVertex3f (48.0, -20.0, -30.0);
	//glEnd();
	//pinggir kanan ijo
	glBegin (GL_QUADS);
	glColor3f(0.0, 0.5, 0.0);
	glVertex3f (48.0, -20.0, 30.0);
	glVertex3f (56.0, -20.0, 30.0);
	glVertex3f (56.0, -20.0, -30.0);
	glVertex3f (48.0, -20.0, -30.0);
	glEnd();
    //pinggir kanan diperlebar
    glBegin (GL_QUADS);
	glColor3f(0.0, 1.0, 1.0);
	glVertex3f (56.0, -20.0, 40.0);
	glVertex3f (68.0, -20.0, 40.0);
	glVertex3f (68.0, -20.0, -40.0);
	glVertex3f (56.0, -20.0, -40.0);
	glEnd();
	//pinggir kiri diperlebar
	glBegin (GL_QUADS);
	glColor3f(0.0, 1.0, 1.0);
	glVertex3f (-48.0, -20.0, 40.0);
	glVertex3f (-60.0, -20.0, 40.0);
	glVertex3f (-60.0, -20.0, -40.0);
	glVertex3f (-48.0, -20.0, -40.0);
	glEnd();
    //pinggir kiri(ijo)
	glBegin (GL_QUADS);
	glColor3f(0.0, 0.5, 0.0);
	glVertex3f (-40.0, -20.0, 30.0);
	glVertex3f (-48.0, -20.0, 30.0);
	glVertex3f (-48.0, -20.0, -30.0);
	glVertex3f (-40.0, -20.0, -30.0);
	glEnd();
	//pinggir dpn
    //glBegin(GL_QUADS);
    //glColor3f(0.0, 1.0, 1.0);
	//glVertex3f (-50.0, -20.0, -30.0);
	//glVertex3f (-50.0, -20.0, -40.0);
	//glVertex3f (60.0, -20.0, -40.0);
	//glVertex3f (60.0, -20.0, -30.0);
	//glEnd();

    //pinggir blkng
    glBegin(GL_QUADS);
    glColor3f(0.0, 1.0, 1.0);
	glVertex3f (-58.0, -20.0, 60.0);
	glVertex3f (-58.0, -20.0, 65.0);
	glVertex3f (68.0, -20.0, 65.0);
	glVertex3f (68.0, -20.0, 60.0);
	glEnd();

	//garis lapngan
	glBegin (GL_LINE_STRIP);
	glColor3f(1.0, 1.0, 1.0);
	glVertex3f (-40.0, -20.0, 30.0);
	glVertex3f (48.0, -20.0, 30.0);
	glVertex3f (48.0, -20.0, -30.0);
	glVertex3f (-40.0, -20.0, -30.0);
	glVertex3f (-40.0, -20.0, 30.0);
	glEnd();

//PAPAN IKLAN

    //papan iklan1
    glBegin(GL_POLYGON);
    glColor3f(0.0,0.0,0.6);
    glVertex3f (-35.0, -17.0, 40.0);
	glVertex3f (43.0, -17.0, 40.0);
	glVertex3f (43.0, -20.0, 40.0);
	glVertex3f (-35.0, -20.0, 40.0);
	glEnd();

    //papan iklan2
    glBegin(GL_POLYGON);
    glColor3f(0.0,0.0,0.6);
    glVertex3f (-35.0, -17.0, -40.0);
	glVertex3f (43.0, -17.0, -40.0);
	glVertex3f (43.0, -20.0, -40.0);
	glVertex3f (-35.0, -20.0, -40.0);
	glEnd();

    //papan iklan3
    glBegin(GL_POLYGON);
    glColor3f(0.0,0.0,0.6);
    glVertex3f (-50.0, -20.0, 25.0);
	glVertex3f (-50.0, -17.0, 25.0);
	glVertex3f (-50.0, -17.0, -25.0);
	glVertex3f (-50.0, -20.0, -25.0);
	glEnd();

    //papan iklan4
    glBegin(GL_POLYGON);
    glColor3f(0.0,0.0,0.6);
    glVertex3f (58.0, -20.0, 25.0);
	glVertex3f (58.0, -17.0, 25.0);
	glVertex3f (58.0, -17.0, -25.0);
	glVertex3f (58.0, -20.0, -25.0);
	glEnd();


//PONDASI PENONTON

 	//pinggir kiri
	glBegin (GL_QUADS);
	glColor3f(1.0, 0.0, 0.0);
	glVertex3f (-58.0, -20.0, 60.0);
	glVertex3f (-150.0, 10.0, 40.0);
	glVertex3f (-150.0, 10.0, -40.0);
	glVertex3f (-58.0, -20.0, -60.0);
	glEnd();

	//pinggir kanan
	glBegin (GL_QUADS);
	glColor3f(1.0, 0.0, 0.0);
	glVertex3f (68.0, -20.0, 60.0);
	glVertex3f (150.0, 10.0, 40.0);
	glVertex3f (150.0, 10.0, -40.0);
	glVertex3f (68.0, -20.0, -60.0);
	glEnd();

	//belakang
    glBegin(GL_QUADS);
    glColor3f(1.0,0.0,0.0);
    glVertex3f (-58.0, -20.0, -60.0);
	glVertex3f (68.0, -20.0, -60.0);
	glVertex3f (68.0, 10.0, -160.0);
	glVertex3f (-58.0, 10.0, -160.0);
	glEnd();

	//depan pintu
	//kiri
	glBegin(GL_QUADS);
    glColor3f(1.0,0.0,0.0);
    glVertex3f (-58.0, -20.0, 60.0); //a
    glVertex3f (-10.0, -20.0, 60.0); //e
    glVertex3f (-10.0, 5.0, 60.0); //f
	glVertex3f (-58.0, 10.0, 160.0);//d
	glEnd();

	//kanan
	glBegin(GL_QUADS);
    glColor3f(1.0,0.0,0.0);
    glVertex3f (68.0, -20.0, 60.0);//b
    glVertex3f (15.0, -20.0, 60.0); //h
    glVertex3f (15.0, 5.0, 60.0); //g
	glVertex3f (68.0, 10.0, 160.0);//c
	glEnd();

	//atas
	glBegin(GL_QUADS);
    glColor3f(1.0,0.0,0.0);
    glVertex3f (-58.0, 10.0, 160.0);//d //titik atas
	glVertex3f (-10.0, 5.0, 60.0); //f
	glVertex3f (15.0, 5.0, 60.0); //g
	glVertex3f (68.0, 10.0, 160.0);//c //titik atas
	glEnd();


//BANGKU PENONTON

	//BELAKANG
	// 1
	glBegin(GL_QUADS);
    glColor3f(0.0,0.0,1.0);
    glVertex3f (-40.0, -15.0, -60.0);//d
	glVertex3f (50.0, -15.0, -60.0); //f
	glVertex3f (50.0, -10.0, -60.0); //g
	glVertex3f (-40.0, -10.0, -60.0);//c
	glEnd();

	// 2
	glBegin(GL_QUADS);
    glColor3f(0.0,0.0,1.0);
    glVertex3f (-40.0, -10.0, -80.0);//d
	glVertex3f (50.0, -10.0, -80.0); //f
	glVertex3f (50.0, -5.0, -80.0); //g
	glVertex3f (-40.0, -5.0, -80.0);//c
	glEnd();

	// 3
	glBegin(GL_QUADS);
    glColor3f(0.0,0.0,1.0);
    glVertex3f (-40.0, 5.0, -90.0);//d
	glVertex3f (50.0, 5.0, -90.0); //f
	glVertex3f (50.0, 0.0, -90.0); //g
	glVertex3f (-40.0, 0.0, -90.0);//c
	glEnd();

	// 4
	glBegin(GL_QUADS);
    glColor3f(0.0,0.0,1.0);
    glVertex3f (-40.0, 10.0, -100.0);//d
	glVertex3f (50.0, 10.0, -100.0); //f
	glVertex3f (50.0, 5.0, -100.0); //g
	glVertex3f (-40.0, 5.0, -100.0);//c
	glEnd();

	// 5
	glBegin(GL_QUADS);
    glColor3f(0.0,0.0,1.0);
    glVertex3f (-40.0, 15.0, -110.0);//d
	glVertex3f (50.0, 15.0, -110.0); //f
	glVertex3f (50.0, 10.0, -110.0); //g
	glVertex3f (-40.0, 10.0, -110.0);//c
	glEnd();



	//KANAN
	// 1
	glBegin (GL_QUADS);
	glColor3f(0.0, 0.0, 1.0);
	glVertex3f (70.0, -15.0, 40.0);
	glVertex3f (70.0, -10.0, 40.0);
	glVertex3f (70.0, -10.0, -30.0);
	glVertex3f (70.0, -15.0, -30.0);
	glEnd();

	// 2
	glBegin (GL_QUADS);
	glColor3f(0.0, 0.0, 1.0);
	glVertex3f (80.0, -10.0, 40.0);
	glVertex3f (80.0, -5.0, 40.0);
	glVertex3f (80.0, -5.0, -30.0);
	glVertex3f (80.0, -10.0, -30.0);
	glEnd();

	// 3
	glBegin (GL_QUADS);
	glColor3f(0.0, 0.0, 1.0);
	glVertex3f (90.0, -5.0, 40.0);
	glVertex3f (90.0, 0.0, 40.0);
	glVertex3f (90.0, 0.0, -30.0);
	glVertex3f (90.0, -5.0, -30.0);
	glEnd();

	// 4
	glBegin (GL_QUADS);
	glColor3f(0.0, 0.0, 1.0);
	glVertex3f (100.0, 0.0, 40.0);
	glVertex3f (100.0, 5.0, 40.0);
	glVertex3f (100.0, 5.0, -30.0);
	glVertex3f (100.0, 0.0, -30.0);
	glEnd();

	// 5
	glBegin (GL_QUADS);
	glColor3f(0.0, 0.0, 1.0);
	glVertex3f (120.0, 5.0, 40.0);
	glVertex3f (120.0, 10.0, 40.0);
	glVertex3f (120.0, 10.0, -30.0);
	glVertex3f (120.0, 5.0, -30.0);
	glEnd();



	//KIRI
	// 1
	glBegin (GL_QUADS);
	glColor3f(0.0, 0.0, 1.0);
	glVertex3f (-60.0, -15.0, 40.0);
	glVertex3f (-60.0, -10.0, 40.0);
	glVertex3f (-60.0, -10.0, -30.0);
	glVertex3f (-60.0, -15.0, -30.0);
	glEnd();

	// 2
	glBegin (GL_QUADS);
	glColor3f(0.0, 0.0, 1.0);
	glVertex3f (-70.0, -10.0, 40.0);
	glVertex3f (-70.0, -5.0, 40.0);
	glVertex3f (-70.0, -5.0, -30.0);
	glVertex3f (-70.0, -10.0, -30.0);
	glEnd();

	// 3
	glBegin (GL_QUADS);
	glColor3f(0.0, 0.0, 1.0);
	glVertex3f (-80.0, -5.0, 40.0);
	glVertex3f (-80.0, 0.0, 40.0);
	glVertex3f (-80.0, 0.0, -30.0);
	glVertex3f (-80.0, -5.0, -30.0);
	glEnd();

	// 4
	glBegin (GL_QUADS);
	glColor3f(0.0, 0.0, 1.0);
	glVertex3f (-90.0, 0.0, 40.0);
	glVertex3f (-90.0, 5.0, 40.0);
	glVertex3f (-90.0, 5.0, -30.0);
	glVertex3f (-90.0, 0.0, -30.0);
	glEnd();

	// 5
	glBegin (GL_QUADS);
	glColor3f(0.0, 0.0, 1.0);
	glVertex3f (-100.0, 5.0, 40.0);
	glVertex3f (-100.0, 10.0, 40.0);
	glVertex3f (-100.0, 10.0, -30.0);
	glVertex3f (-100.0, 5.0, -30.0);
	glEnd();

	//DEPAN
	// 3
	glBegin(GL_QUADS);
    glColor3f(0.0,0.0,1.0);
    glVertex3f (-40.0, 15.0, 90.0);//d
	glVertex3f (50.0, 15.0, 90.0); //f
	glVertex3f (50.0, 10.0, 90.0); //g
	glVertex3f (-40.0, 10.0, 90.0);//c
	glEnd();

	// 4
	glBegin(GL_QUADS);
    glColor3f(0.0,0.0,1.0);
    glVertex3f (-40.0, 15.0, 100.0);//d
	glVertex3f (50.0, 15.0, 100.0); //f
	glVertex3f (50.0, 10.0, 100.0); //g
	glVertex3f (-40.0, 10.0, 100.0);//c
	glEnd();

	// 5
	glBegin(GL_QUADS);
    glColor3f(0.0,0.0,1.0);
    glVertex3f (-40.0, 15.0, 110.0);//d
	glVertex3f (50.0, 15.0, 110.0); //f
	glVertex3f (50.0, 10.0, 110.0); //g
	glVertex3f (-40.0, 10.0, 110.0);//c
	glEnd();



// PAPAN PERSEGI PONDASI

	//kanan
    glBegin(GL_QUADS);
    glColor3f(0.0,0.0,1.0);
    glVertex3f (150.0, 40.0, -40.0);
	glVertex3f (150.0, 10.0, -40.0);
	glVertex3f (150.0, 10.0, 40.0);
	glVertex3f (150.0, 40.0, 40.0);
	glEnd();

	//kiri
    glBegin(GL_QUADS);
    glColor3f(0.0,0.0,1.0);
    glVertex3f (-150.0, 40.0, -40.0);
	glVertex3f (-150.0, 10.0, -40.0);
	glVertex3f (-150.0, 10.0, 40.0);
	glVertex3f (-150.0, 40.0, 40.0);
	glEnd();

	//belakang
    glBegin(GL_QUADS);
    glColor3f(0.0,0.0,1.0);
    glVertex3f (-58.0, 10.0, -160.0);
	glVertex3f (68.0, 10.0, -160.0);
	glVertex3f (68.0, 40.0, -160.0);
	glVertex3f (-58.0, 40.0, -160.0);
	glEnd();

	//depan
    glBegin(GL_QUADS);
    glColor3f(0.0,0.0,1.0);
    glVertex3f (-58.0, 10.0, 160.0);
	glVertex3f (68.0, 10.0, 160.0);
	glVertex3f (68.0, 40.0, 160.0);
	glVertex3f (-58.0, 40.0, 160.0);
	glEnd();

//ATAP TRIBUN KOTAK

	//belakang
    glBegin(GL_QUADS);
    glColor3f(0.0,1.0,0.0);
    glVertex3f (-58.0, 40.0, -70.0);
	glVertex3f (68.0, 40.0, -70.0);
	glVertex3f (68.0, 40.0, -190.0);
	glVertex3f (-58.0, 40.0, -190.0);
	glEnd();

	//depan
    glBegin(GL_QUADS);
    glColor3f(0.0,1.0,0.0);
    glVertex3f (-58.0, 40.0, 70.0);
	glVertex3f (68.0, 40.0, 70.0);
	glVertex3f (68.0, 40.0, 190.0);
	glVertex3f (-58.0, 40.0, 190.0);
	glEnd();

	//kanan
    glBegin(GL_QUADS);
    glColor3f(0.0,1.0,0.0);
    glVertex3f (180.0, 40.0, -40.0);
	glVertex3f (70.0, 40.0, -40.0);
	glVertex3f (70.0, 40.0, 40.0);
	glVertex3f (180.0, 40.0, 40.0);
	glEnd();

	//kiri
    glBegin(GL_QUADS);
    glColor3f(0.0,1.0,0.0);
    glVertex3f (-180.0, 40.0, -40.0);
	glVertex3f (-70.0, 40.0, -40.0);
	glVertex3f (-70.0, 40.0, 40.0);
	glVertex3f (-180.0, 40.0, 40.0);
	glEnd();

//TRIBUN BAWAH KOTAK

	//depan
    glBegin(GL_QUADS);
    glColor3f(0.0,1.0,0.0);
    glVertex3f (-58.0, -20.0, 70.0);
	glVertex3f (68.0, -20.0, 70.0);
	glVertex3f (68.0, -40.0, 190.0);
	glVertex3f (-58.0, -40.0, 190.0);
	glEnd();

	//belakang
    glBegin(GL_QUADS);
    glColor3f(0.0,1.0,0.0);
    glVertex3f (-58.0, -20.0, -70.0);
	glVertex3f (68.0, -20.0, -70.0);
	glVertex3f (68.0, -40.0, -190.0);
	glVertex3f (-58.0, -40.0, -190.0);
	glEnd();

	//kanan
    glBegin(GL_QUADS);
    glColor3f(0.0,1.0,0.0);
    glVertex3f (180.0, -40.0, -40.0);
	glVertex3f (70.0, -20.0, -40.0);
	glVertex3f (70.0, -20.0, 40.0);
	glVertex3f (180.0, -40.0, 40.0);
	glEnd();

	//kiri
    glBegin(GL_QUADS);
    glColor3f(0.0,1.0,0.0);
    glVertex3f (-180.0, -40.0, -40.0);
	glVertex3f (-70.0, -20.0, -40.0);
	glVertex3f (-70.0, -20.0, 40.0);
	glVertex3f (-180.0, -40.0, 40.0);
	glEnd();




	//garis tv kiri (belakng)
    glBegin(GL_QUADS);
    glColor3f(0.0,0.0,0.3);
    glVertex3f (-8.0, 20.0, -75.0);
	glVertex3f (-8.6, 20.0, -75.0);
	glVertex3f (-8.6, 40.0, -75.0);
	glVertex3f (-8.0, 40.0, -75.0);
	glEnd();
	//garis tv kanan (belakng)
    glBegin(GL_QUADS);
    glColor3f(0.0,0.0,0.3);
    glVertex3f (14.3, 20.0, -75.0);
	glVertex3f (15.0, 20.0, -75.0);
	glVertex3f (15.0, 40.0, -75.0);
	glVertex3f (14.3, 40.0, -75.0);
	glEnd();
	//garis tv bawah (belakng)
    glBegin(GL_QUADS);
    glColor3f(0.0,0.0,0.3);
    glVertex3f (-8.0, 20.0, -75.0);
	glVertex3f (15.0, 20.0, -75.0);
	glVertex3f (15.0, 22.0, -75.0);
	glVertex3f (-8.0, 22.0, -75.0);
	glEnd();
	//garis tv atas (belakng)
    glBegin(GL_QUADS);
    glColor3f(0.0,0.0,0.3);
    glVertex3f (-8.0, 39.0, -75.0);
	glVertex3f (15.0, 39.0, -75.0);
	glVertex3f (15.0, 40.0, -75.0);
	glVertex3f (-8.0, 40.0, -75.0);
	glEnd();
    //TV belakang
    glBegin(GL_QUADS);
    glColor3f(1.5,1.0,0.3);
    glVertex3f (-8.0, 20.0, -75.0);
	glVertex3f (15.0, 20.0, -75.0);
	glVertex3f (15.0, 40.0, -75.0);
	glVertex3f (-8.0, 40.0, -75.0);
	glEnd();
	//belakang
    glBegin(GL_QUADS);
    glColor3f(0.0,1.0,0.0);
    glVertex3f (-58.0, 40.0, -70.0);
	glVertex3f (68.0, 40.0, -70.0);
	glVertex3f (68.0, 40.0, -160.0);
	glVertex3f (-58.0, 40.0, -160.0);
	glEnd();
    //garis tv depan (kiri)
    glBegin(GL_QUADS);
    glColor3f(0.0,0.0,0.3);
    glVertex3f (-8.0, 20.0, 74.9);
	glVertex3f (-8.6, 20.0, 74.9);
	glVertex3f (-8.6, 40.0, 74.9);
	glVertex3f (-8.0, 40.0, 74.9);
	glEnd();
	//garis tv dpan (kanan)
    glBegin(GL_QUADS);
    glColor3f(0.0,0.0,0.3);
    glVertex3f (14.3, 20.0, 75.0);
	glVertex3f (15.0, 20.0, 75.0);
	glVertex3f (15.0, 40.0, 75.0);
	glVertex3f (14.3, 40.0, 75.0);
	glEnd();
	//garis tv bawah (depan)
    glBegin(GL_QUADS);
    glColor3f(0.0,0.0,0.3);
    glVertex3f (-8.0, 20.0, 75.0);
	glVertex3f (15.0, 20.0, 75.0);
	glVertex3f (15.0, 22.0, 75.0);
	glVertex3f (-8.0, 22.0, 75.0);
	glEnd();
	//garis tv atas (belakng)
    glBegin(GL_QUADS);
    glColor3f(0.0,0.0,0.3);
    glVertex3f (-8.0, 39.0, 75.0);
	glVertex3f (15.0, 39.0, 75.0);
	glVertex3f (15.0, 40.0, 75.0);
	glVertex3f (-8.0, 40.0, 75.0);
	glEnd();
	//tv depan
     glBegin(GL_QUADS);
    glColor3f(1.5,1.0,0.3);
    glVertex3f (-8.0, 20.0, 75.0);
	glVertex3f (15.0, 20.0, 75.0);
	glVertex3f (15.0, 40.0, 75.0);
	glVertex3f (-8.0, 40.0, 75.0);
	glEnd();



//PERSEGI PENGHUBUNG
//garis belakang pojok kiri
    glBegin(GL_QUADS);
    glColor3f(1,1,0.5);
    glVertex3f(-70.0, 40.0, -90.0);
    glVertex3f(-73.0, 40.0, -90.0);
    glVertex3f(-73.0, 90.0, -90.0);
    glVertex3f(-70.0, 90.0, -90.0);
    glEnd();
    //tali
    glBegin(GL_LINE_STRIP);
    glColor3f(1,1,0.5);
    glVertex3f(-72.0, 75.0, -90.0);
    glVertex3f(-55.0, 40.0, -90.0);
    glVertex3f(-55.0, 40.0, -90.0);
    glVertex3f(-72.0, 75.0, -90.0);
    glEnd();
     //tali
    glBegin(GL_LINE_STRIP);
    glColor3f(1,1,0.5);
    glVertex3f(-72.2, 75.0, -90.0);
    glVertex3f(-87.0, 40.0, -90.0);
    glVertex3f(-87.0, 40.0, -90.0);
    glVertex3f(-72.2, 75.0, -90.0);
    glEnd();
//garis belakang samping kanan
    glBegin(GL_QUADS);
    glColor3f(1,1,0.5);
    glVertex3f(-105.0, 40.0, -20.0);
    glVertex3f(-108.0, 40.0, -20.0);
    glVertex3f(-108.0, 90.0, -20.0);
    glVertex3f(-105.0, 90.0, -20.0);
    glEnd();
    //tali
    glBegin(GL_LINE_STRIP);
    glColor3f(1,1,0.5);
    glVertex3f(-106.0, 75.0, -20.0);
    glVertex3f(-90.0, 40.0, -20.0);
    glVertex3f(-90.0, 40.0, -20.0);
    glVertex3f(-106.0, 75.0, -20.0);
    glEnd();
     //tali
    glBegin(GL_LINE_STRIP);
    glColor3f(1,1,0.5);
    glVertex3f(-107.0, 75.0, -20.0);
    glVertex3f(-120.0, 40.0, -20.0);
    glVertex3f(-120.0, 40.0, -20.0);
    glVertex3f(-107.0, 75.0, -20.0);
    glEnd();
 //garis 1 belakang samping kanan
    glBegin(GL_QUADS);
    glColor3f(1,1,0.5);
    glVertex3f(-105.0, 40.0, 30.0);
    glVertex3f(-108.0, 40.0, 30.0);
    glVertex3f(-108.0, 90.0, 30.0);
    glVertex3f(-105.0, 90.0, 30.0);
    glEnd();
    //tali
    glBegin(GL_LINE_STRIP);
    glColor3f(1,1,0.5);
    glVertex3f(-106.0, 75.0, 30.0);
    glVertex3f(-90.0, 40.0, 30.0);
    glVertex3f(-90.0, 40.0, 30.0);
    glVertex3f(-106.0, 75.0, 30.0);
    glEnd();
     //tali
    glBegin(GL_LINE_STRIP);
    glColor3f(1,1,0.5);
    glVertex3f(-107.0, 75.0, 30.0);
    glVertex3f(-120.0, 40.0, 30.0);
    glVertex3f(-120.0, 40.0, 30.0);
    glVertex3f(-107.0, 75.0, 30.0);
    glEnd();
//garis 2 depan
    glBegin(GL_QUADS);
    glColor3f(1,1,0.5);
    glVertex3f(-100.0, 40.0, 70.0);
    glVertex3f(-103.0, 40.0, 70.0);
    glVertex3f(-103.0, 90.0, 70.0);
    glVertex3f(-100.0, 90.0, 70.0);
    glEnd();
    //tali
    glBegin(GL_LINE_STRIP);
    glColor3f(1,1,0.5);
    glVertex3f(-102.0, 76.0, 70.0);
    glVertex3f(-85.0, 40.0, 70.0);
    glVertex3f(-85.0, 40.0, 70.0);
    glVertex3f(-102.0, 76.0, 70.0);
    glEnd();
     //tali
    glBegin(GL_LINE_STRIP);
    glColor3f(1,1,0.5);
    glVertex3f(-102.2, 75.0, 70.0);
    glVertex3f(-117.0, 40.0, 70.0);
    glVertex3f(-117.0, 40.0, 70.0);
    glVertex3f(-102.2, 75.0, 70.0);
    glEnd();
    //garis 3 depan
    glBegin(GL_QUADS);
    glColor3f(1,1,0.5);
    glVertex3f(-70.0, 40.0, 100.0);
    glVertex3f(-73.0, 40.0, 100.0);
    glVertex3f(-73.0, 90.0, 100.0);
    glVertex3f(-70.0, 90.0, 100.0);
    glEnd();
    //tali
    glBegin(GL_LINE_STRIP);
    glColor3f(1,1,0.5);
    glVertex3f(-72.0, 75.0, 100.0);
    glVertex3f(-55.0, 40.0, 100.0);
    glVertex3f(-55.0, 40.0, 100.0);
    glVertex3f(-72.0, 75.0, 100.0);
    glEnd();
     //tali
    glBegin(GL_LINE_STRIP);
    glColor3f(1,1,0.5);
    glVertex3f(-72.2, 75.0, 100.0);
    glVertex3f(-87.0, 40.0, 100.0);
    glVertex3f(-87.0, 40.0, 100.0);
    glVertex3f(-72.2, 75.0, 100.0);
    glEnd();
     //garis 4 depan
    glBegin(GL_QUADS);
    glColor3f(1,1,0.5);
    glVertex3f(-1.0, 40.0, 120.0);
    glVertex3f(2.0, 40.0, 120.0);
    glVertex3f(2.0, 90.0, 120.0);
    glVertex3f(-1.0, 90.0, 120.0);
    glEnd();
    //tali
    glBegin(GL_LINE_STRIP);
    glColor3f(1,1,0.5);
    glVertex3f(0.0, 76.0, 120.0);
    glVertex3f(-12.0, 40.0, 120.0);
    glVertex3f(-12.0, 40.0, 120.0);
    glVertex3f(0.0, 76.0, 120.0);
    glEnd();
     //tali
    glBegin(GL_LINE_STRIP);
    glColor3f(1,1,0.5);
    glVertex3f(0.0, 75.0, 120.0);
    glVertex3f(15.0, 40.0, 120.0);
    glVertex3f(15.0, 40.0, 120.0);
    glVertex3f(0.0, 75.0, 120.0);
    glEnd();
    //garis tiang belakang
    glBegin(GL_QUADS);
    glColor3f(1,1,0.5);
    glVertex3f(-1.0, 40.0, -120.0);
    glVertex3f(2.0, 40.0, -120.0);
    glVertex3f(2.0, 90.0, -120.0);
    glVertex3f(-1.0, 90.0, -120.0);
    glEnd();
    //tali
    glBegin(GL_LINE_STRIP);
    glColor3f(1,1,0.5);
    glVertex3f(0.0, 76.0, -120.0);
    glVertex3f(-12.0, 40.0, -120.0);
    glVertex3f(-12.0, 40.0, -120.0);
    glVertex3f(0.0, 76.0, -120.0);
    glEnd();
     //tali
    glBegin(GL_LINE_STRIP);
    glColor3f(1,1,0.5);
    glVertex3f(0.0, 75.0, -120.0);
    glVertex3f(15.0, 40.0, -120.0);
    glVertex3f(15.0, 40.0, -120.0);
    glVertex3f(0.0, 75.0, -120.0);
    glEnd();
	//kanan depan
    glBegin(GL_QUADS);
    glColor3f(0.0,0.0,1.0);
	glVertex3f (68.0, 10.0, 160.0);
	glVertex3f (68.0, 40.0, 160.0);
	glVertex3f (150.0, 40.0, 40.0);
	glVertex3f (150.0, 10.0, 40.0);
	glEnd();
	//garis kanan belakang
    glBegin(GL_QUADS);
    glColor3f(1,1,0.5);
    glVertex3f(80.0, 40.0, -90.0);
    glVertex3f(83.0, 40.0, -90.0);
    glVertex3f(83.0, 90.0, -90.0);
    glVertex3f(80.0, 90.0, -90.0);
    glEnd();
    //tali
    glBegin(GL_LINE_STRIP);
    glColor3f(1,1,0.5);
    glVertex3f(82.0, 76.0, -90.0);
    glVertex3f(65.0, 40.0, -90.0);
    glVertex3f(65.0, 40.0, -90.0);
    glVertex3f(82.0, 76.0, -90.0);
    glEnd();
     //tali
    glBegin(GL_LINE_STRIP);
    glColor3f(1,1,0.5);
    glVertex3f(82.2, 75.0, -90.0);
    glVertex3f(97.0, 40.0, -90.0);
    glVertex3f(97.0, 40.0, -90.0);
    glVertex3f(82.2, 75.0, -90.0);
    glEnd();
	//garis kanan belakang
    glBegin(GL_QUADS);
    glColor3f(1,1,0.5);
    glVertex3f(110.0, 40.0, -20.0);
    glVertex3f(113.0, 40.0, -20.0);
    glVertex3f(113.0, 90.0, -20.0);
    glVertex3f(110.0, 90.0, -20.0);
    glEnd();
    //tali
    glBegin(GL_LINE_STRIP);
    glColor3f(1,1,0.5);
    glVertex3f(112.0, 76.0, -20.0);
    glVertex3f(95.0, 40.0, -20.0);
    glVertex3f(95.0, 40.0, -20.0);
    glVertex3f(112.0, 76.0, -20.0);
    glEnd();
     //tali
    glBegin(GL_LINE_STRIP);
    glColor3f(1,1,0.5);
    glVertex3f(112.2, 75.0, -20.0);
    glVertex3f(127.0, 40.0, -20.0);
    glVertex3f(127.0, 40.0, -20.0);
    glVertex3f(112.2, 75.0, -20.0);
    glEnd();
    //garis 1 belakang samping kanan
    glBegin(GL_QUADS);
    glColor3f(1,1,0.5);
    glVertex3f(105.0, 40.0, 30.0);
    glVertex3f(108.0, 40.0, 30.0);
    glVertex3f(108.0, 90.0, 30.0);
    glVertex3f(105.0, 90.0, 30.0);
    glEnd();
    //tali
    glBegin(GL_LINE_STRIP);
    glColor3f(1,1,0.5);
    glVertex3f(106.0, 75.0, 30.0);
    glVertex3f(90.0, 40.0, 30.0);
    glVertex3f(90.0, 40.0, 30.0);
    glVertex3f(106.0, 75.0, 30.0);
    glEnd();
     //tali
    glBegin(GL_LINE_STRIP);
    glColor3f(1,1,0.5);
    glVertex3f(107.0, 75.0, 30.0);
    glVertex3f(120.0, 40.0, 30.0);
    glVertex3f(120.0, 40.0, 30.0);
    glVertex3f(107.0, 75.0, 30.0);
    glEnd();
//garis 2 depan
    glBegin(GL_QUADS);
    glColor3f(1,1,0.5);
    glVertex3f(100.0, 40.0, 70.0);
    glVertex3f(103.0, 40.0, 70.0);
    glVertex3f(103.0, 90.0, 70.0);
    glVertex3f(100.0, 90.0, 70.0);
    glEnd();
    //tali
    glBegin(GL_LINE_STRIP);
    glColor3f(1,1,0.5);
    glVertex3f(102.0, 76.0, 70.0);
    glVertex3f(85.0, 40.0, 70.0);
    glVertex3f(85.0, 40.0, 70.0);
    glVertex3f(102.0, 76.0, 70.0);
    glEnd();
     //tali
    glBegin(GL_LINE_STRIP);
    glColor3f(1,1,0.5);
    glVertex3f(102.2, 75.0, 70.0);
    glVertex3f(117.0, 40.0, 70.0);
    glVertex3f(117.0, 40.0, 70.0);
    glVertex3f(102.2, 75.0, 70.0);
    glEnd();
	//kiri depan
    glBegin(GL_QUADS);
    glColor3f(0.0,0.0,1.0);
    glVertex3f (-58.0, 10.0, 160.0);
	glVertex3f (-58.0, 40.0, 160.0);
	glVertex3f (-150.0, 40.0, 40.0);
	glVertex3f (-150.0, 10.0, 40.0);
	glEnd();
    //garis 3 depan
    glBegin(GL_QUADS);
    glColor3f(1,1,0.5);
    glVertex3f(80.0, 40.0, 100.0);
    glVertex3f(83.0, 40.0, 100.0);
    glVertex3f(83.0, 90.0, 100.0);
    glVertex3f(80.0, 90.0, 100.0);
    glEnd();
    //tali
    glBegin(GL_LINE_STRIP);
    glColor3f(1,1,0.5);
    glVertex3f(82.0, 76.0, 100.0);
    glVertex3f(65.0, 40.0, 100.0);
    glVertex3f(65.0, 40.0, 100.0);
    glVertex3f(82.0, 76.0, 100.0);
    glEnd();
     //tali
    glBegin(GL_LINE_STRIP);
    glColor3f(1,1,0.5);
    glVertex3f(82.2, 75.0, 100.0);
    glVertex3f(97.0, 40.0, 100.0);
    glVertex3f(97.0, 40.0, 100.0);
    glVertex3f(82.2, 75.0, 100.0);
    glEnd();
	//kiri depan
    glBegin(GL_QUADS);
    glColor3f(0.0,0.0,1.0);
    glVertex3f (-58.0, 10.0, 160.0);
	glVertex3f (-58.0, 40.0, 160.0);
	glVertex3f (-150.0, 40.0, 40.0);
	glVertex3f (-150.0, 10.0, 40.0);
	glEnd();

	//kiri belakang
    glBegin(GL_QUADS);
    glColor3f(0.0,0.0,1.0);
    glVertex3f (-150.0, 40.0, -40.0);
	glVertex3f (-150.0, 10.0, -40.0);
    glVertex3f (-58.0, 10.0, -160.0);
	glVertex3f (-58.0, 40.0, -160.0);
	glEnd();

	//kanan belakang
    glBegin(GL_QUADS);
    glColor3f(0.0,0.0,1.0);
 	glVertex3f (68.0, 10.0, -160.0);
	glVertex3f (68.0, 40.0, -160.0);
	glVertex3f (150.0, 40.0, -40.0);
	glVertex3f (150.0, 10.0, -40.0);
	glEnd();

//SEGITIGA PINGGIR BAWAH PONDASI

	//SEGITIGA BELAKANG KANAN
   	glBegin(GL_TRIANGLES);
    glColor3f(1.0, 0.5, 0.0);
    glVertex3f (68.0, 10.0, -160.0);
    glVertex3f (150.0, 10.0, -40.0);
    glVertex3f (68.0, -20.0, -60.0);
	glEnd();

	//SEGITIGA BELAKANG KIRI
	glBegin(GL_TRIANGLES);
    glColor3f(1.0, 0.5, 0.0);
	glVertex3f (-58.0, -20.0, -60.0);
	glVertex3f (-150.0, 10.0, -40.0);
  	glVertex3f (-58.0, 10.0, -160.0);
	glEnd();

	//DEPAN KIRI
    glBegin(GL_TRIANGLES);
  	glColor3f(1.0, 0.5, 0.0);
    glVertex3f (-58.0, -20.0, 60.0);
    glVertex3f (-58.0, 10.0, 160.0);
    glVertex3f (-150.0, 10.0, 40.0);
    glEnd();

	//SEGITIGA DEPAN KANAN
	glBegin(GL_TRIANGLES);
    glColor3f(1.0, 0.5, 0.0);
    glVertex3f (150.0, 10.0, 40.0);
    glVertex3f (68.0, 10.0, 160.0);
	glVertex3f (68.0, -20.0, 60.0);
	glEnd();

//SEGITIGA PINGGIR ATAS TRIBUN

	// kiri belakang
    glBegin(GL_QUADS);
    glColor3f(1.0,0.0,0.0);
    glVertex3f (-58.0, 40.0, -70.0);
    glVertex3f (-58.0, 40.0, -190.0);
    glVertex3f (-180.0, 40.0, -40.0);
	glVertex3f (-70.0, 40.0, -40.0);
    glEnd();

    //kanan belakang
    glBegin(GL_QUADS);
    glColor3f(1.0,0.0,0.0);
    glVertex3f (68.0, 40.0, -70.0);
	glVertex3f (68.0, 40.0, -190.0);
	glVertex3f (180.0, 40.0, -40.0);
	glVertex3f (70.0, 40.0, -40.0);

	//kanan depan
	glBegin(GL_QUADS);
    glColor3f(1.0,0.0,0.0);
	glVertex3f (70.0, 40.0, 40.0);
	glVertex3f (180.0, 40.0, 40.0);
	glVertex3f (68.0, 40.0, 70.0);
	glVertex3f (68.0, 40.0, 190.0);
    glEnd();

    //kiri depan
    glBegin(GL_QUADS);
    glColor3f(1.0,0.0,0.0);
    glVertex3f (-58.0, 40.0, 70.0);
    glVertex3f (-58.0, 40.0, 190.0);
    glVertex3f (-70.0, 40.0, 40.0);
	glVertex3f (-180.0, 40.0, 40.0);
    glEnd();
    
//SEGITIGA PINGGIR BAWAH TRIBUN

	// kiri belakang
    glBegin(GL_QUADS);
    glColor3f(1.0,0.0,0.0);
    glVertex3f (-58.0, -40.0, -70.0);
    glVertex3f (-58.0, -40.0, -190.0);
    glVertex3f (-180.0,-40.0, -40.0);
	glVertex3f (-0.0, -40.0, -40.0);
    glEnd();

    //kanan belakang
    glBegin(GL_QUADS);
    glColor3f(1.0,0.0,0.0);
    glVertex3f (68.0, -40.0, -70.0);
	glVertex3f (68.0, -40.0, -190.0);
	glVertex3f (180.0, -40.0, -40.0);
	glVertex3f (0.0, -40.0, -40.0);

	//kanan depan
	glBegin(GL_QUADS);
    glColor3f(1.0,0.0,0.0);
	glVertex3f (0.0, -40.0, 40.0);
	glVertex3f (180.0, -40.0, 40.0);
	glVertex3f (68.0, -40.0, 70.0);
	glVertex3f (68.0, -40.0, 190.0);
    glEnd();

    //kiri depan
    glBegin(GL_QUADS);
    glColor3f(1.0,0.0,0.0);
    glVertex3f (-58.0, -40.0, 70.0);
    glVertex3f (-58.0, -40.0, 190.0);
    glVertex3f (-0.0, -40.0, 40.0);
	glVertex3f (-180.0, -40.0, 40.0);
    glEnd();
    

// LAMPU STADION

	//kanan
	glBegin(GL_POINTS);
	glColor3f(0.5,1,1 );
	glVertex3f (70.0, 40.0, -40.0);
	glVertex3f (70.0, 40.0, 40.0);
	glEnd();

	//kiri
	glBegin(GL_POINTS);
	glColor3f(0.5,1,1 );
	glVertex3f (-70.0, 40.0, -40.0);
	glVertex3f (-70.0, 40.0, 40.0);
	glEnd();

	//depan
	glBegin(GL_POINTS);
	glColor3f(0.5,1,1 );
  	glVertex3f (-58.0, 40.0, 70.0);
	glVertex3f (68.0, 40.0, 70.0);
	glEnd();

	//belakang
	glBegin(GL_POINTS);
	glColor3f(0.5,1,1 );
    glVertex3f (-58.0, 40.0, -70.0);
	glVertex3f (68.0, 40.0, -70.0);
	glEnd();

// TIANG PENYANGGA LUAR STADION

		//depan kiri
    glBegin(GL_QUADS);
    glColor3f(1.0,0.0,0.0);
    glVertex3f (-58.0, 10.0, 160.0);
	glVertex3f (-58.0, 40.0, 160.0);
	glVertex3f (-58.0, -40.0, 190.0);
	glVertex3f (-58.0, 10.0, 160.0);
	
	glEnd();
	
		//depan kanan
    glBegin(GL_QUADS);
    glColor3f(1.0,0.0,0.0);
	glVertex3f (68.0, 10.0, 160.0);
	glVertex3f (68.0, 40.0, 160.0);
	glVertex3f (68.0, -40.0, 190.0);
	glVertex3f (68.0, 10.0, 160.0);
	glEnd();
	
		//samping kanan (kiri)
    glBegin(GL_QUADS);
    glColor3f(1.0,0.0,0.0);
    glVertex3f (150.0, 10.0, 40.0);
	glVertex3f (150.0, 40.0, 40.0);
	glVertex3f (180.0, -40.0, 40.0);
	glVertex3f (150.0, 10.0, 40.0);
	glEnd();
	
		//samping kanan (kanan)
    glBegin(GL_QUADS);
    glColor3f(1.0,0.0,0.0);
    glVertex3f (150.0, 40.0, -40.0);
	glVertex3f (150.0, 10.0, -40.0);
    glVertex3f (180.0, -40.0, -40.0);
 	glVertex3f (150.0, 40.0, -40.0);
	glEnd();
	
		//belakang kiri
    glBegin(GL_QUADS);
    glColor3f(1.0,0.0,0.0);
    glVertex3f (68.0, 10.0, -160.0);
	glVertex3f (68.0, 40.0, -160.0); 
	glVertex3f (68.0, -40.0, -190.0);
	glVertex3f (68.0, 10.0, -160.0);
	glEnd();
	
		//belakang kanan
    glBegin(GL_QUADS);
    glColor3f(1.0,0.0,0.0);
    glVertex3f (-58.0, 10.0, -160.0);
	glVertex3f (-58.0, 40.0, -160.0); 
    glVertex3f (-58.0, -40.0, -190.0);
    glVertex3f (-58.0, 10.0, -160.0);
	glEnd();
	
		//samping kiri (kiri)
    glBegin(GL_QUADS);
    glColor3f(1.0,0.0,0.0);
    glVertex3f (-150.0, 40.0, -40.0);
	glVertex3f (-150.0, 10.0, -40.0);
    glVertex3f (-180.0, -40.0, -40.0);
	glVertex3f (-150.0, 40.0, -40.0);
	glEnd();
	
		//samping kiri (kanan)
    glBegin(GL_QUADS);
    glColor3f(1.0,0.0,0.0);
    glVertex3f (-150.0, 10.0, 40.0);
	glVertex3f (-150.0, 40.0, 40.0);
 	glVertex3f (-180.0, -40.0, 40.0);
 	glVertex3f (-150.0, 10.0, 40.0);
	glEnd();
	
// PENUTUP BAWAH
	
		//depan belakang
    glBegin(GL_QUADS);
    glColor3f(0.0,0.0,1.0);
	glVertex3f (68.0, -40.0, 190.0);
	glVertex3f (-58.0, -40.0, 190.0);
	glVertex3f (-58.0, -40.0, -190.0);
	glVertex3f (68.0, -40.0, -190.0);
	glEnd();
	
		//kanan kiri
		
    glBegin(GL_QUADS);
    glColor3f(0.0,0.0,1.0);
    glVertex3f (180.0, -40.0, -40.0);
	glVertex3f (180.0, -40.0, 40.0);
	glVertex3f (-180.0, -40.0, -40.0);
	glVertex3f (-180.0, -40.0, 40.0);
	glEnd();
	
	glPopMatrix();
	glutSwapBuffers();


}

void keyboard(unsigned char key, int bx, int by){
    switch (key)
    {
		//maju
		case 'w':
		case 'W':
			glTranslatef(0, 0, 5);
			break;

		//kanan
		case 'd':
		case 'D':
			glTranslatef(5, 0, 0);
			break;

		//mundur
		case 's':
		case 'S':
			glTranslatef(0, 0, -5);
			break;

		//kiri
		case 'a':
		case 'A':
			glTranslatef(-5, 0, 0);
			break;

		//atas
		case '9':
			glTranslatef(0, 5, 0);
			break;

		//bawah
		case '0':
			glTranslatef(0, -5, 0);
			break;

		//rotasi bawah
		case 'k':
		case 'K':
			glRotatef(3, 1, 0, 0);
			break;

		//rotas atas
		case 'i':
		case 'I':
			glRotatef(-3, 1, 0, 0);
			break;

		//rotasi kanan
		case 'l':
		case 'L':
			glRotatef(3, 0, 1, 0);
			break;

		//rotasi kiri
		case 'j':
		case 'J':
			glRotatef(-3, 0, 1, 0);
			break;

		//rotasi miring kiri
		case '7':
			glRotatef(3, 0, 0, 1);
			break;

		//rotasi miring kanan
		case '8':
			glRotatef(-3, 0, 0, 1);
			break;

		//buka objek
    	case '5':
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
		tampil();
}

//fungsi mouse 1
void idle ()
{
	if (!mouseDown)
	{
		xrot += 0.3f;
		yrot += 0.4f;
	}
	glutPostRedisplay();
}

//fungsi mouse 2
void mouse (int button, int state, int x, int y)
{
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		mouseDown = true;
		xdiff = x - yrot;
		ydiff = -y + xrot;
	}
	else
	mouseDown = false;
}

//fungsi mouse 3
void mouseMotion (int x, int y)
{
	if (mouseDown)
	{
		xrot = x - ydiff;
		yrot = y + xdiff;

		glutPostRedisplay();
	}
}

void ukuran (int lebar, int tinggi)
{
	if (tinggi == 0) tinggi = 1;

	glMatrixMode (GL_PROJECTION);
	glLoadIdentity ();
	gluPerspective (120.0, lebar/tinggi,5.0, 500.0);
	glTranslatef (0.0, -5.0, -150.0);
	glMatrixMode (GL_MODELVIEW);
}


int main (int argc, char **argv)
{
	glutInit (&argc, argv);
	glutInitDisplayMode (GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize (900, 600);
	glutInitWindowPosition (250, 80);
	glutCreateWindow ("stadion dajal");
	init();
	glutDisplayFunc (tampil);
	glutReshapeFunc (ukuran);

	glutKeyboardFunc (keyboard);

	glutMouseFunc (mouse);
	glutMotionFunc (mouseMotion);

	glutIdleFunc (tampil);
	glutMainLoop ();
	return 0;
}
