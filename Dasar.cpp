<<<<<<< HEAD
#include <windows.h>
#include <stdlib.h>
#include <GL/glut.h>

void init (void);
void tampil (void);
void mouse (int button, int state, int x, int y);
void ukuran (int, int);
void mouseMotion (int x, int y);
void keyboard (unsigned char, int , int);

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
	glPointSize (5.0f);
	glLineWidth (6.0f);
}

void tampil (void)
{
	if (is_depth)
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	else
		glClear (GL_COLOR_BUFFER_BIT);

	glLoadIdentity();
	gluLookAt (0.0f, 0.0f, 3.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f);
	glRotatef (xrot, 1.0f, 0.0f, 0.0f);
	glRotatef (yrot, 1.0f, 1.0f, 0.0f);
	glPushMatrix();

	/*//depan
	glBegin (GL_QUADS);
	glColor3f(1.0, 1.0, 0.7);
	glVertex3f (-10.0, -10.0, 10.0);
	glVertex3f (-10.0, 10.0, 10.0);
	glVertex3f (10.0, 10.0, 10.0);
	glVertex3f (10.0, -10.0, 10.0);
	glEnd();

	//belaknag
	glBegin (GL_QUADS);
	glColor3f(1.0, 1.0, 0.7);
	glVertex3f (-10.0, -10.0, -10.0);
	glVertex3f (-10.0, 10.0, -10.0);
	glVertex3f (10.0, 10.0, -10.0);
	glVertex3f (10.0, -10.0, -10.0);
	glEnd();
	*/
	//lapngan
	glBegin (GL_QUADS);
	glColor3f(0.0, 1.0, 0.0);
	glVertex3f (-40.0, -20.0, 30.0);
	glVertex3f (40.0, -20.0, 30.0);
	glVertex3f (40.0, -20.0, -30.0);
	glVertex3f (-40.0, -20.0, -30.0);
	glEnd();
	//gawang kanan
	glBegin (GL_LINE_STRIP);
	glColor3f(1.0, 1.0, 1.0);
	glVertex3f (30.0, -20.0, 10.0);
	glVertex3f (30.0, -10.0, 10.0);
	glVertex3f (32.0, -10.0, 10.0);
	glVertex3f (40.0, -20.0, 10.0);
	glEnd();
	glBegin (GL_LINE_STRIP);
	glVertex3f (30.0, -20.0, -10.0);
	glVertex3f (30.0, -10.0, -10.0);
	glVertex3f (32.0, -10.0, -10.0);
	glVertex3f (40.0, -20.0, -10.0);
	glEnd();
	glBegin (GL_LINE_STRIP);
	glVertex3f (30.0, -10.0, 10.0);
	glVertex3f (30.0, -10.0, -10.0);
	glEnd();
	glBegin (GL_LINE_STRIP);
	glVertex3f (40.0, -20.0, 10.0);
	glVertex3f (40.0, -20.0, -10.0);
	glEnd();
	
	//gawang kiri
	glBegin (GL_LINE_STRIP);
	glColor3f(1.0, 1.0, 1.0);
	glVertex3f (-30.0, -20.0, 10.0);
	glVertex3f (-30.0, -10.0, 10.0);
	glVertex3f (-32.0, -10.0, 10.0);
	glVertex3f (-40.0, -20.0, 10.0);
	glEnd();
	glBegin (GL_LINE_STRIP);
	glVertex3f (-30.0, -20.0, -10.0);
	glVertex3f (-30.0, -10.0, -10.0);
	glVertex3f (-32.0, -10.0, -10.0);
	glVertex3f (-40.0, -20.0, -10.0);
	glEnd();
	glBegin (GL_LINE_STRIP);
	glVertex3f (-30.0, -10.0, 10.0);
	glVertex3f (-30.0, -10.0, -10.0);
	glEnd();
	glBegin (GL_LINE_STRIP);
	glVertex3f (-40.0, -20.0, 10.0);
	glVertex3f (-40.0, -20.0, -10.0);
	glEnd();

	//pinggir kanan
	glBegin (GL_QUADS);
	glColor3f(1.0, 0.5, 0.0);
	glVertex3f (40.0, -20.0, 30.0);
	glVertex3f (55.0, -20.0, 30.0);
	glVertex3f (55.0, -20.0, -30.0);
	glVertex3f (40.0, -20.0, -30.0);
	glEnd();
	//pinggir kiri
	glBegin (GL_QUADS);
	glColor3f(1.0, 0.5, 0.0);
	glVertex3f (-40.0, -20.0, 30.0);
	glVertex3f (-55.0, -20.0, 30.0);
	glVertex3f (-55.0, -20.0, -30.0);
	glVertex3f (-40.0, -20.0, -30.0);
	glEnd();
	//pinggir depan
    glBegin(GL_QUADS);
    glColor3f(1.0, 0.5, 0.0);
	glVertex3f (-55.0, -20.0, -30.0);
	glVertex3f (-55.0, -20.0, -40.0);
	glVertex3f (55.0, -20.0, -40.0);
	glVertex3f (55.0, -20.0, -30.0);
	glEnd();
    //pinggir bekalang
    glBegin(GL_QUADS);
    glColor3f(1.0, 0.5, 0.0);
	glVertex3f (-55.0, -20.0, 40.0);
	glVertex3f (-55.0, -20.0, 30.0);
	glVertex3f (55.0, -20.0, 30.0);
	glVertex3f (55.0, -20.0, 40.0);
	glEnd();
	//lampu kanan belaknag T
	glBegin (GL_LINE_STRIP);
	glColor3f(1.0, 0.0, 1.0);
	glVertex3f (50.0, -20.0, -30.0);
	glVertex3f (50.0, 15.0, -30.0);
	glVertex3f (45.0, 15.0, -30.0);
	glVertex3f (55.0, 15.0, -30.0);
	glEnd();
	//lampu kiri belakang T
	glBegin (GL_LINE_STRIP);
	glColor3f(1.0, 0.0, 1.0);
	glVertex3f (-50.0, -20.0, -30.0);
	glVertex3f (-50.0, 15.0, -30.0);
	glVertex3f (-45.0, 15.0, -30.0);
	glVertex3f (-55.0, 15.0, -30.0);
	glEnd();
	//lampu kanan depan T
	glBegin (GL_LINE_STRIP);
	glColor3f(1.0, 0.0, 1.0);
	glVertex3f (50.0, -20.0, 30.0);
	glVertex3f (50.0, 15.0, 30.0);
	glVertex3f (45.0, 15.0, 30.0);
	glVertex3f (55.0, 15.0, 30.0);
	glEnd();
	//lampu kiri depan T
	glBegin (GL_LINE_STRIP);
	glColor3f(1.0, 0.0, 1.0);
	glVertex3f (-50.0, -20.0, 30.0);
	glVertex3f (-50.0, 15.0, 30.0);
	glVertex3f (-45.0, 15.0, 30.0);
	glVertex3f (-55.0, 15.0, 30.0);
	glEnd();

	//kepala kanan depan (kiri)
	glBegin (GL_QUADS);
	glColor3f(1.0, 0.0, 1.0);
	glVertex3f (53.0, 17.0, 30.0);
	glVertex3f (53.0, 13.0, 30.0);
	glVertex3f (57.0, 13.0, 30.0);
	glVertex3f (57.0, 17.0, 30.0);
	glEnd();
	//kepala kanan depan (kanan)
	glBegin (GL_QUADS);
	glColor3f (1.0, 0.0, 1.0);
	glVertex3f (43.0, 17.0, 30.0);
	glVertex3f (43.0, 13.0, 30.0);
	glVertex3f (47.0, 13.0, 30.0);
	glVertex3f (47.0, 17.0, 30.0);
	glEnd();
	//kepala kiri depan (kanan)
	glBegin (GL_QUADS);
	glColor3f (1.0, 0.0, 1.0);
	glVertex3f (-43.0, 17.0, 30.0);
	glVertex3f (-43.0, 13.0, 30.0);
	glVertex3f (-47.0, 13.0, 30.0);
	glVertex3f (-47.0, 17.0, 30.0);
	glEnd();
	//kepala kiri depan (kiri)
	glBegin (GL_QUADS);
	glColor3f(1.0, 0.0, 1.0);
	glVertex3f (-53.0, 17.0, 30.0);
	glVertex3f (-53.0, 13.0, 30.0);
	glVertex3f (-57.0, 13.0, 30.0);
	glVertex3f (-57.0, 17.0, 30.0);
	glEnd();
	//kepala kiri belakang (kiri)
	glBegin (GL_QUADS);
	glColor3f(1.0, 0.0, 1.0);
	glVertex3f (-53.0, 17.0, -30.0);
	glVertex3f (-53.0, 13.0, -30.0);
	glVertex3f (-57.0, 13.0, -30.0);
	glVertex3f (-57.0, 17.0, -30.0);
	glEnd();
	//kepala kiri depan (kanan)
	glBegin (GL_QUADS);
	glColor3f (1.0, 0.0, 1.0);
	glVertex3f (-43.0, 17.0, -30.0);
	glVertex3f (-43.0, 13.0, -30.0);
	glVertex3f (-47.0, 13.0, -30.0);
	glVertex3f (-47.0, 17.0, -30.0);
	glEnd();
	//kepala kanan depan (kiri)
	glBegin (GL_QUADS);
	glColor3f(1.0, 0.0, 1.0);
	glVertex3f (53.0, 17.0, -30.0);
	glVertex3f (53.0, 13.0, -30.0);
	glVertex3f (57.0, 13.0, -30.0);
	glVertex3f (57.0, 17.0, -30.0);
	glEnd();
	//kepala kanan depan (kanan)
	glBegin (GL_QUADS);
	glColor3f (1.0, 0.0, 1.0);
	glVertex3f (43.0, 17.0, -30.0);
	glVertex3f (43.0, 13.0, -30.0);
	glVertex3f (47.0, 13.0, -30.0);
	glVertex3f (47.0, 17.0, -30.0);
	glEnd();

	//garis lapngan
	glBegin (GL_LINE_STRIP);
	glColor3f(1.0, 1.0, 1.0);
	glVertex3f (-40.0, -20.0, 30.0);
	glVertex3f (40.0, -20.0, 30.0);
	glVertex3f (40.0, -20.0, -30.0);
	glVertex3f (-40.0, -20.0, -30.0);
	glVertex3f (-40.0, -20.0, 30.0);
	glEnd();

    //papan iklan2
    glBegin(GL_POLYGON);
    glColor3f(0.2,1.5,1.5);
    glVertex3f (-35.0, -15.0, -31.0);
	glVertex3f (35.0, -15.0, -31.0);
	glVertex3f (35.0, -20.0, -31.0);
	glVertex3f (-35.0, -20.0, -31.0);
	glEnd();
    //papan iklan3
    glBegin(GL_POLYGON);
    glColor3f(0.2,1.5,1.5);
    glVertex3f (-41.0, -20.0, 25.0);
	glVertex3f (-41.0, -15.0, 25.0);
	glVertex3f (-41.0, -15.0, -25.0);
	glVertex3f (-41.0, -20.0, -25.0);
	glEnd();
    //papan iklan4
    glBegin(GL_POLYGON);
    glColor3f(0.2,1.5,1.5);
    glVertex3f (41.0, -20.0, 25.0);
	glVertex3f (41.0, -15.0, 25.0);
	glVertex3f (41.0, -15.0, -25.0);
	glVertex3f (41.0, -20.0, -25.0);
	glEnd();
	 
	//tv
	//glBegin(GL_QUADS);
	//glVertex3f (95.0, -10.0, 10.0);
	//glVertex3f (90.0, 10.0, 10.0);
	//glVertex3f (90.0, 10.0, -10.0);
	//glVertex3f (95.0, -10.0, -10.0);
	//glEnd();
	
	//tempat pnonnton
	
	//pinggir kiri
	glBegin (GL_QUADS);
	glColor3f(1.0, 0.0, 0.0);
	glVertex3f (-55.0, -20.0, 40.0);
	glVertex3f (-100.0, 30.0, 40.0);
	glVertex3f (-100.0, 30.0, -40.0);
	glVertex3f (-55.0, -20.0, -40.0);
	glEnd();
	
	//pinggir kanan
	glBegin (GL_QUADS);
	glColor3f(1.0, 0.0, 0.0);
	glVertex3f (55.0, -20.0, 40.0);
	glVertex3f (100.0, 30.0, 40.0);
	glVertex3f (100.0, 30.0, -40.0);
	glVertex3f (55.0, -20.0, -40.0);
	glEnd();
	
	//pinggir atas
  //  glBegin(GL_QUADS);
  //  glColor3f(0.0, 0.0, 1.0);
//	glVertex3f (-55.0, -20.0, -40.0);
//	glVertex3f (55.0, -20.0, -40.0);
//	glVertex3f (55.0, 20.0, -120.0);
//	glVertex3f (-55.0, 20.0, -120.0);
//	glEnd();
		//pinggir atas
    glBegin(GL_QUADS);
    glColor3f(0.0, 0.0, 1.0);
	glVertex3f (-55.0, 50.0, -80.0);
	glVertex3f (55.0, 50.0, -80.0);
	glVertex3f (55.0, -20.0, -40.0);
	glVertex3f (-55.0, -20.0, -40.0);
	glEnd();
	
	//pinggir bawah 
//	glBegin(GL_QUADS);
  //  glColor3f(0.0, 0.0, 1.0);
	//glVertex3f (-55.0, -20.0, 40.0);
	//glVertex3f (55.0, -20.0, 40.0);
	//glVertex3f (55.0, 20.0, 120.0);
	//glVertex3f (-55.0, 20.0, 120.0);
	//glEnd();
	
	glPopMatrix();
	glPopMatrix();
	glutSwapBuffers();


}

void keyboard (unsigned char key, int x, int y)
{
	switch (key)
	{
		case 'w':
			case 'W':
				glTranslatef (0.0, 0.0, 10.0);
				break;
		case 'd':
			case 'D':
				glTranslatef (10.0, 0.0, 0.0);
				break;
		case 's':
			case 'S':
				glTranslatef (0.0, 0.0, -10.0);
				break;
		case 'a':
			case 'A':
				glTranslatef (-10.0, 0.0, 0.0);
				break;
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
	gluPerspective (90.0, lebar/tinggi,5.0, 500.0);
	glTranslatef (0.0, -5.0, -150.0);
	glMatrixMode (GL_MODELVIEW);
}


int main (int argc, char **argv)
{
	glutInit (&argc, argv);
	glutInitDisplayMode (GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize (800, 600);
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
=======
#include <windows.h>
#include <gl/glut.h>

void mouse(int button, int state, int x, int y);
void mouseMotion(int x, int y);
float xrot = 0.0f;
float yrot = 0.0f;
float xdiff = 0.0f;
float ydiff = 0.0f;
bool mouseDown = false;
void init(void);
void tampil(void);
void keyboard(unsigned char, int, int);//bisa qwerty kecuali F1 dll (fungsi spesial)
void ukuran(int,int);

int is_depth;//agar bisa menekan pada keyboard (view tembus pandang)

void idle()
{
    if (!mouseDown)
    {
        xrot += 0.3f;
        yrot += 0.4f;
    }
glutPostRedisplay();
}
void mouse(int button, int state, int x, int y)
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
void mouseMotion(int x, int y)
{
    if(mouseDown)
    {
        yrot = x - xdiff;
        xrot = y + ydiff;
        glutPostRedisplay();
    }
}
int main (int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(800, 600);
    glutInitWindowPosition(180, 60);
    glutCreateWindow("TR Grafkom");
    init();
    glutDisplayFunc(tampil);
    glutKeyboardFunc(keyboard);
    glutReshapeFunc(ukuran);
    glutMainLoop();
    return 0;
}
void init(void)
{
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glMatrixMode(GL_PROJECTION);
    glEnable(GL_DEPTH_TEST); //fungsi spt is depth
    is_depth=1;
    glMatrixMode(GL_MODELVIEW);
    glPointSize(9.0);
    glLineWidth(6.0f);
}
void tampil(void)
{
    gluLookAt(0.0f, 0.0f, 3.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f);
    glLoadIdentity();
    glRotatef(xrot, 1.0f, 0.0f, 0.0f);
    glRotatef(yrot, 0.0f, 1.0f, 0.0f);
    if (is_depth)
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    else
    glClear(GL_COLOR_BUFFER_BIT);
    //lapangan
	//bawah
	glBegin (GL_QUADS);
	glColor3f(0,1.5,0);
	glVertex3f (-40.0, -20.0, 20.0); //A
	glVertex3f (40.0, -20.0, 20.0); //B
	glVertex3f (40.0, -20.0, -30.0); //C
	glVertex3f (-40.0, -20.0, -30.0); //D
	glEnd();
    //pinggir lapngan kanan
    glBegin (GL_QUADS);
	glColor3f(1.0, 0.0, 0.0);
    glVertex3f (40.0, -20.0, 20.0); //B
	glVertex3f (40.0, -20.0, -30.0); //C
	glVertex3f (55.0, -20.0, -30.0); //e
	glVertex3f (55.0, -20.0, 20.0); //f
    glEnd();
    //pinggir lapngan kiri
    glBegin (GL_QUADS);
	glColor3f(1.0, 0.0, 0.0);
    glVertex3f (-40.0, -20.0, 20.0); //A
	glVertex3f (-40.0, -20.0, -30.0); //D
	glVertex3f (-55.0, -20.0, -30.0); //g
	glVertex3f (-55.0, -20.0, 20.0); //h
    glEnd();
   
    /*//pinggir lapngan bawah
    glBegin (GL_POINTS);
	glColor3f(1.0, 0.0, 0.0);
    glVertex3f (-40.0, -20.0, 20.0); //A
	glVertex3f (40.0, -20.0, 20.0); //B
	glVertex3f (40.0, -35.0, 50.0); //j
	glVertex3f (-40.0, -35.0, 50.0); //i
    glEnd();
    */
    //pinggir lapngan atas
 	glBegin (GL_QUADS);
	glColor3f(1.0, 0.0, 0.0);
	glVertex3f (-40.0, 20.0, -30.0); //D
	glVertex3f (40.0, 20.0, -30.0); //C
	glVertex3f (40.0, -20.0, -40.0); //j
	glVertex3f (-40.0, -20.0, -40.0); //i
	
	glEnd();
    
    //lampu
    glBegin (GL_QUADS);
    glColor3f(0.0, 0.0, 1.0);
    glVertex3f (45.0, 0.0, -10.0); //p
	glVertex3f (50.0, 0.0, -10.0); //o
	glVertex3f (50.0, 0.0, -20.0); //n
	glVertex3f (45.0, 0.0, -20.0); //m
    glEnd();
	

    glutSwapBuffers();
}
void keyboard(unsigned char key, int x, int y)
{
    switch (key)
    {
    case 'w':
    case 'W':
        glTranslatef(0.0, 0.0, 3.0);
        break;
    case 'd':
    case 'D':
        glTranslatef(3.0,0.0,0.0);
        break;
    case 's':
    case 'S':
        glTranslatef(0.0,0.0,-3.0); //z nya - biar bisa mundur
        break;
    case 'a':
    case 'A':
        glTranslatef(-3.0,0.0,0.0);
        break;
    case '1':
        glTranslatef(0.0,3.0,0.0);
        break;
    case '2':
        glTranslatef(0.0,-3.0,0.0);
        break;
     case '3':
        glRotatef(2.0,2.0,0.0, 0.0);
        break;
    case '4':
        glRotatef(-2.0,1.0,0.0, 0.0);//atas bawah
        break;
    case '5':
        glRotatef(2.0,0.0,1.0, 0.0);
        break;
    case '6':
        glRotatef(-2.0,0.0,0.0, 1.0);
        break;
    case '7':
        glRotatef(2.0,0.0,0.0, 1.0);
        break;
     case '8':
        glRotatef(-2.0,0.0,0.0,1.0);
        break;
     case '9':
        if (is_depth)
        {
            is_depth=0;
            glDisable(GL_DEPTH_TEST);
        }
        else
        {
            is_depth = 1;
            glDisable(GL_DEPTH_TEST);
        }
    }
    tampil();
}
void ukuran(int lebar, int tinggi) //ukuran (awal)
{
    if (tinggi==0) tinggi =1;

    glMatrixMode(GL_PROJECTION); // a
    glLoadIdentity();//panggil
    gluPerspective(50.0, lebar / tinggi, 5.0,  500.0);//untuk melihat dari mana (sudur pandang) //fovy ibaratkan y aspect(bidang apa) znear zfar
    glTranslatef(0.0, -5.0, -150.0);
    glutMouseFunc(mouse);
    glutMotionFunc(mouseMotion);
    glMatrixMode(GL_MODELVIEW);
}

>>>>>>> 0c1fa4e5002ebe113b462af4a09bc5f57cd1499c
