/* Programa Cuadrado de la semana 2 */
#include <GL/glut.h>
#include <math.h>

/* Inicialización de la pantalla. */
void initGL(){
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f); // Establecer el color de fondo en negro y opaco
	glMatrixMode(GL_MODELVIEW);
}
void display() {
	
	glClear(GL_COLOR_BUFFER_BIT); // Limpiar el búfer de color
	
	glLoadIdentity();
	// Dibujar un Cuadrado rojo 1x1 centrado en el origen
	
	glBegin (GL_QUADS); // Cada conjunto de 4 vértices forma un quad
		
		glColor3f (1.0f, 1.0f, 0.0f); // Rojo
		glVertex2f (-0.2f, -0.2f); // x, y
		glVertex2f (0.2f, -0.2f);
		glVertex2f (0.2f, 0.2f);
		glVertex2f (-0.2f, 0.2f);
	glEnd ();
	glPushMatrix();
		glRotatef (45.0f, 0.0f, 0.0f, 0.5f);
		glTranslatef (0.7f, 0.0f, 0.0f);
		glBegin (GL_QUADS); // Cada conjunto de 4 vértices forma un quad
			glColor3f (1.0f, 0.0f, 0.0f); // Rojo
			glVertex2f (-0.2f, -0.2f); // x, y
			glVertex2f (0.2f, -0.2f);
			glVertex2f (0.2f, 0.2f);
			glVertex2f (-0.2f, 0.2f);
		glEnd ();
	glPopMatrix();

	glPushMatrix();
		glTranslatef (0.0f, -0.5f, 0.0f);
		glBegin (GL_QUADS); // Cada conjunto de 4 vértices forma un quad
			glColor3f (1.0f, 0.0f, 1.0f); // Rojo
			glVertex2f (-0.2f, -0.2f); // x, y
			glVertex2f (0.2f, -0.2f);
			glVertex2f (0.2f, 0.2f);
			glVertex2f (-0.2f, 0.2f);
		glEnd ();
	glPopMatrix();
	//trasladar
	
	glFlush (); // Renderizar ahora
}
float radio = 100, calx,caly;
int ortho = 20;
void drawStartPolygon(){
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT); // Limpiar el búfer de color
	// Dibujar un circulo rojo 1x1 centrado en el origen


	
	glBegin(GL_POLYGON);
	glColor3f(1.0f, 0.0f, 0.0f); // Rojo
	for(float i = 0; i < 10; i+=0.01){
		calx = radio * cos(i);
		caly = radio * sin(i);
		glVertex2f(calx-ortho, caly);
	}
	glEnd ();
	glFlush (); // Renderizar ahora
	
	
	

	


}
/* Función principal: GLUT se ejecuta como una aplicación de consola comenzando en main () */
int main (int argc, char ** argv) {
	glutInit (& argc, argv); // Inicializar GLUT
<<<<<<< HEAD
	glutInitDisplayMode (GLUT_SINGLE | GLUT_RGBA); // Inicializar el modo de visualización
	glutInitWindowSize (900, 900); // Establecer el ancho y alto inicial de la ventana
	
	glutCreateWindow ("Prueba"); // Crea una ventana con el título dado
	gluOrtho2D (-900/2, 900/2, -900/2, 900/2); // Establecer el origen de coordenadas en el centro de la ventana
	glClearColor(1, 1, 1, 1);
	glutInitWindowPosition (100, 100); // Coloca la esquina superior izquierda inicial de la ventana
	glutDisplayFunc (drawStartPolygon); // Registrar el controlador de devolución de llamada de visualización para la pintura de la ventana
=======
	glutCreateWindow ("Prueba de configuración de OpenGL"); // Crea una ventana con el título dado
	glutInitWindowSize (320, 320); // Establecer el ancho y alto inicial de la ventana
	glutInitWindowPosition (50, 50); // Coloca la esquina superior izquierda inicial de la ventana
	glutDisplayFunc (display); // Registrar el controlador de devolución de llamada de visualización para la pintura de la ventana
	initGL();
>>>>>>> a06b7f351ca773e3d1a0b37dfcc0c80175ab1ad0
	glutMainLoop (); // Ingrese el ciclo de procesamiento de eventos infinito
	return 0;
}