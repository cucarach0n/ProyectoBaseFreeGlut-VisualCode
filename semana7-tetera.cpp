#include <GL/freeglut.h>
void init(void)
{
// Ubicamos la fuente de luz en el punto
GLfloat light_position[] = { 0.0, 1.0, 1.0, 0.0 }; // VALIDAREMOS CAMBIOS AQUÍ
GLfloat luz_ambiental[] = { -5.0, -5.0, -5.0, 1.0 };
// Activamos la fuente de luz
glEnable(GL_LIGHTING);
glEnable(GL_LIGHT0);
glDepthFunc(GL_LESS);
glEnable(GL_DEPTH_TEST);
glLightfv(GL_LIGHT0,GL_POSITION,luz_ambiental);
// Queremos que se dibujen las caras frontales y con un color solido de relleno.
glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
}
void reshape(int w, int h)
{
//glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
glViewport(0, 0, (GLsizei) w, (GLsizei) h);
// Activamos la matriz de proyeccion.
glMatrixMode(GL_PROJECTION);
// "limpiamos" esta con la matriz identidad.
glLoadIdentity();
// Usamos proyeccion ortogonal
glOrtho(-300, 300, -300, 300, -300, 300);
// Activamos la matriz de modelado/visionado.
glMatrixMode(GL_MODELVIEW);
// "Limpiamos" la matriz
glLoadIdentity();
}
// Aqui ponemos lo que queremos dibujar.

void display(void)
{
// Propiedades del material

GLfloat mat_ambient[] = { 0.329412f, 0.223529f, 0.027451f,1.0f };
GLfloat mat_diffuse[] = { 0.780392f, 0.568627f, 0.113725f, 1.0f };
GLfloat mat_specular[] = { 0.992157f, 0.941176f, 0.807843f, 1.0f };
GLfloat shine[] = {27.8974f}; 
// "Limpiamos" el frame buffer con el color de "Clear", en este color negro
glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // Aquí va, verificarlo en el repintado
// Rotacion de 20 grados en torno al eje x
glRotated(20.0, 1.0, 0.0, 0.0);
// Rotacion de -30 grados en torno al eje y
glRotated(-30.0, 0.0, 1.0, 0.0);
// Dibujamos una "Tetera" y le aplico el material
glPushMatrix();
//Aplicando el setMaterial

glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient);
glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
glMaterialfv(GL_FRONT, GL_SHININESS, shine); 
glColor3f(1.0,1.0,0.0);
glutSolidTeapot(125.0);
glFlush();
}
// Termina la ejecucion del programa cuando se presiona ESC
void keyboard(unsigned char key, int x, int y)
{
switch (key)
{
case 27:
exit(0);
break;
}
}
// Main del programa.
int main(int argc, char **argv)

{
glutInit(&argc, argv);
glutInitDisplayMode (GLUT_RGB | GLUT_DEPTH);
glutInitWindowSize (800, 600);
glutInitWindowPosition (0, 0);
glutCreateWindow ("Teapot");
init();
glutDisplayFunc(display);
glutReshapeFunc(reshape);
glutKeyboardFunc(keyboard);
glutMainLoop();
return 0;
}