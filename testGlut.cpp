/* Programa Cuadrado de la semana 2 */
#include <GL/freeglut.h>
/* Inicialización de la pantalla. */
void display() {
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f); // Establecer el color de fondo en negro y opaco
	glClear(GL_COLOR_BUFFER_BIT); // Limpiar el búfer de color
	// Dibujar un Cuadrado rojo 1x1 centrado en el origen
	glBegin (GL_QUADS); // Cada conjunto de 4 vértices forma un quad
	glColor3f (1.0f, 0.0f, 0.0f); // Rojo
	glVertex2f (-0.5f, -0.5f); // x, y
	glVertex2f (0.5f, -0.5f);
	glVertex2f (0.5f, 0.5f);
	glVertex2f (-0.5f, 0.5f);
	glEnd ();
	glFlush (); // Renderizar ahora
}
/* Función principal: GLUT se ejecuta como una aplicación de consola comenzando en main () */
int main (int argc, char ** argv) {
	glutInit (& argc, argv); // Inicializar GLUT
	glutCreateWindow ("Prueba de configuración de OpenGL"); // Crea una ventana con el título dado
	glutInitWindowSize (320, 320); // Establecer el ancho y alto inicial de la ventana
	glutInitWindowPosition (50, 50); // Coloca la esquina superior izquierda inicial de la ventana
	glutDisplayFunc (display); // Registrar el controlador de devolución de llamada de visualización para la pintura de la ventana
	glutMainLoop (); // Ingrese el ciclo de procesamiento de eventos infinito
	return 0;
}