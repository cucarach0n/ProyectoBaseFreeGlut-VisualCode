/* Programa Cuadrado de la semana 2 */
#include <GL/freeglut.h>
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
/* Función principal: GLUT se ejecuta como una aplicación de consola comenzando en main () */
int main (int argc, char ** argv) {
	glutInit (& argc, argv); // Inicializar GLUT
	glutCreateWindow ("Prueba de configuración de OpenGL"); // Crea una ventana con el título dado
	glutInitWindowSize (320, 320); // Establecer el ancho y alto inicial de la ventana
	glutInitWindowPosition (50, 50); // Coloca la esquina superior izquierda inicial de la ventana
	glutDisplayFunc (display); // Registrar el controlador de devolución de llamada de visualización para la pintura de la ventana
	initGL();
	glutMainLoop (); // Ingrese el ciclo de procesamiento de eventos infinito
	return 0;
}