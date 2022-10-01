/* Programa Cuadrado de la semana 2 */
#include <GL/freeglut.h>
/* Inicialización de la pantalla. */
void initGL(){
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f); // Establecer el color de fondo en negro y opaco
	glMatrixMode(GL_MODELVIEW);
    gluOrtho2D(-20,20,-20,20);
}
void display() {
	
	glClear(GL_COLOR_BUFFER_BIT); // Limpiar el búfer de color
	
	glLoadIdentity();
	// Dibujar un Cuadrado rojo 1x1 centrado en el origen
    
	glPushMatrix();
		glTranslatef (0.0f, -0.5f, 0.0f);
        glColor3f(0.0f,0.8f,1.0f);
		glutSolidTeapot(0.25);
	glPopMatrix();
	//trasladar
	
	glFlush (); // Renderizar ahora
    glutSwapBuffers ();
}
/* Función principal: GLUT se ejecuta como una aplicación de consola comenzando en main () */
int main (int argc, char ** argv) {
	glutInit (& argc, argv); // Inicializar GLUT
    glutInitWindowSize(1200,600);
    glutInitWindowPosition(100,80);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutCreateWindow ("Prueba de configuración de OpenGL"); // Crea una ventana con el título dado
	//glutInitWindowSize (320, 320); // Establecer el ancho y alto inicial de la ventana
	//glutInitWindowPosition (50, 50); // Coloca la esquina superior izquierda inicial de la ventana
    
	glutDisplayFunc (display); // Registrar el controlador de devolución de llamada de visualización para la pintura de la ventana
	initGL();
	glutMainLoop (); // Ingrese el ciclo de procesamiento de eventos infinito
	return 0;
}
