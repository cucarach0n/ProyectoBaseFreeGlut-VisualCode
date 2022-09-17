/* Programa Cuadrado de la semana 2 */
#include <stdio.h>
#include <math.h>
#include <GL/freeglut.h>
/* Inicialización de la pantalla. */
void initGL(){
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f); // Establecer el color de fondo en negro y opaco
	glMatrixMode(GL_MODELVIEW);
    
}

float a;
GLUquadricObj *cilindro;
void DibujarEsferas(){
    glPushMatrix();
    glTranslatef(0,8,0);
    glPushMatrix();
    glTranslatef(-8.7,0,0);
    glRotated(-a,0,1,0);
    glColor3f (0.6235, 0.3725, 0.6235);
    glutWireSphere(2.0,40,40);
    glPopMatrix();
    glPushMatrix();
    glTranslatef(-4.0,0,0);
    glRotated(a,0,1,0);
    glColor3f (0.6235, 0.3725, 0.6235);
    glutWireSphere(2.0,40,40);
    glPopMatrix();
    glPopMatrix();
}
void DibujarCubos(){
    glPushMatrix();
    glTranslatef(0,8,0);
    glPushMatrix();
    glTranslatef(3,0,0);
    glRotated(-a,0,0,1);
    glColor3f (0, 0, 1);
    glutWireCube(3.0);
    glPopMatrix();
    glPushMatrix();
    glTranslatef(8,0,0);
    glRotated(a,0,0,1);
    glColor3f (0, 0, 1);
    glutWireCube(3.0);
    glPopMatrix();
    glPopMatrix();
}
void DibujarToroides(){
    glPushMatrix();
    glTranslatef(0,0,0);
    glPushMatrix();
    glTranslatef(-8.7,0,0);
    glRotated(a,0,0,1);
    glColor3f (0, 1, 0);
    glutWireTorus(1.0, 1.7, 20, 20);
    glPopMatrix();
    glPushMatrix();
    glTranslatef(-2.7,0,0);
    glRotated(-a,0,0,1);
    glColor3f (0, 1, 0);
    glutWireTorus(1.0, 1.7, 20, 20);
    glPopMatrix();
    glPopMatrix();
}
void DibujarCilindros(){
    glPushMatrix();
    glTranslatef(0,-2.5,0);
    glPushMatrix();
    glRotated(-90, 1,0,0);
    glTranslatef(4,0,0);
    glRotated(a,0,0,1);
    cilindro = gluNewQuadric();
    glColor3f(1, 0, 0);
    gluQuadricDrawStyle(cilindro,GLU_LINE);
    gluCylinder(cilindro,1,1,5,20,20);
    glPopMatrix();
    glPushMatrix();
    glRotated(-90, 1,0,0);
    glTranslatef(8,0,0);
    glRotated(-a,0,0,1);
    cilindro = gluNewQuadric();
    glColor3f(1, 0, 0);
    gluQuadricDrawStyle(cilindro,GLU_LINE);
    gluCylinder(cilindro,1,1,5,20,20);
    glPopMatrix();
    glPopMatrix();
}
void DibujarTeteras(){
    glPushMatrix();
    glTranslatef(0,-7,0);
    glPushMatrix();
    glTranslatef(-7.7,0,0);
    glRotated(a,0,1,0);
    glColor3f (0, 1, 1);
    glutWireTeapot(2.0);
    glPopMatrix();
    glPushMatrix();
    glTranslatef(-2.5,0,0);
    glRotated(-a,0,1,0);
    glColor3f (0, 1, 1);
    glutSolidTeapot(2);
    glPopMatrix();
    glPopMatrix();
}
void DibujarIso(){
    glPushMatrix();
    glTranslatef(0,-7,0);
    glPushMatrix();
    glTranslatef(3,0,0);
    glRotated(-a,1,0,0);
    glColor3f (0, 0, 0);
    glScalef(2.0,2.0,2.0);
    glutWireIcosahedron();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(8,0,0);
    glRotated(a,1,0,0);
    glColor3f (0, 0, 0);
    glScalef(2.0,2.0,2.0);
    glutWireIcosahedron();
    glPopMatrix();
    glPopMatrix();
}
void display(void)
{
    glClear( GL_COLOR_BUFFER_BIT );
    glMatrixMode(GL_MODELVIEW);
    DibujarEsferas();
    DibujarCubos();
    DibujarToroides();
    DibujarCilindros();
    DibujarTeteras();
    DibujarIso();
    a=a+0.5;
    glutSwapBuffers();
}


void myReshape(int w, int h)
{
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective( 60.0, (GLdouble)w/(GLdouble)h, 0.5,30.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(0.0, 0.0, 20.0, /* cam-pos (0,0,20) */
    0.0, 0.0, 0.0, /* ver a */
    0.0, 1.0, 0.0);
}
void myIdleFunc(void) {
    glutPostRedisplay();
}


int main (int argc, char ** argv) {
	glutInit (& argc, argv); // Inicializar GLUT
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowPosition(100,40);
    glutInitWindowSize(700,650);
	glutCreateWindow ("T 3D"); // Crea una ventana con el título dado
	//glutInitWindowSize (320, 320); // Establecer el ancho y alto inicial de la ventana
	//glutInitWindowPosition (50, 50); // Coloca la esquina superior izquierda inicial de la ventana
    
    glutReshapeFunc(myReshape);
	glutDisplayFunc (display); // Registrar el controlador de devolución de llamada de visualización para la pintura de la ventana
	glutIdleFunc(myIdleFunc);
    glClearColor(1.0,1.0,1.0,1.0);
    glColor3f(0.0,0.0,0.0);
    glLightf(1,1,1);
    
	glutMainLoop (); // Ingrese el ciclo de procesamiento de eventos infinito
	return 0;
}