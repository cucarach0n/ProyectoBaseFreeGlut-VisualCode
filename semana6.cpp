#include <GL/freeglut.h>
float aspect = 1.0f;
void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
    //para el perspective
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(20.0f, aspect, 1.0f, 10.0f);
    //
    //para las transformaciones geometricas
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(0.0f, 0.0f, 5.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f);
    //
    glutWireTeapot(0.5);
     
    glFlush();
    glutSwapBuffers();
}
void onSize(int sx, int sy)
{
    glViewport(0, 0, sx, sy); 
    aspect = (float) sx / (float) sy;
}
int main(int argc, char **argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(400, 400);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Viewport tetera alambre");
    glutDisplayFunc(display);
    glutReshapeFunc(onSize);
    glutMainLoop();
}