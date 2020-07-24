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

