#include <GL/glut.h>
#include <stdlib.h>
#include <time.h>

#define ARRIBA 0
#define ABAJO 1
#define IZDA 2
#define DCHA 3
 
class Cuerpo {
public:
    float x,y;
};

class Snake {
public:
   Cuerpo serpiente[20*20], comida, frente; 
   int longitud, milisegundos, direccion;
   bool colision;
   
   void Iniciar() {
      longitud = 3;
      milisegundos = 100;
      direccion = ARRIBA;
      colision = 0;
      
      serpiente[0].x = serpiente[0].y = serpiente[1].y = serpiente[2].y = 0.0f;
      serpiente[1].x = -1.0f;
      serpiente[2].x = -2.0f;
      
      do {
         comida.x = (float) (rand()%(40)) - 20.0f;
         comida.y = (float) (rand()%(40)) - 20.0f;
      } while ( comida.y == 0.0f || comida.x == -2.0f || comida.x == -1.0f || comida.x == 0.0f );
   }
   
   void Pintar() {
      glColor3f(1.0f,1.0f,1.0f);
      glRectf(-20.0f,-20.0f,20.0f,20.0f); //Fondo
      
      for (int i=0; i<longitud; i++) {
         glColor3f(0.5f,0.5f,0.5f);
         glRectf(serpiente[i].x,serpiente[i].y,serpiente[i].x+1.0f,serpiente[i].y+1.0f);
         glColor3f(0.0f,0.0f,0.0f);
         glRectf(serpiente[i].x+0.2f,serpiente[i].y+0.2f,serpiente[i].x+0.8f,serpiente[i].y+0.8f);
      }
      
      glColor3f(1.0f,0.0f,0.0f);
      glRectf(comida.x,comida.y,comida.x+1.0f,comida.y+1.0f);
      glColor3f(0.5f,0.0f,0.0f);
      glRectf(comida.x+0.2f,comida.y+0.2f,comida.x+0.8f,comida.y+0.8f);
   }
   
   void colocarNuevaComida() {
      int esp_libre, libre, m;
      libre = 0;
      esp_libre = 0;
      while(!esp_libre) {
         libre = 0;
         esp_libre = 0;
         comida.x = (float) (rand()%(40)) - 20.0f;
         comida.y = (float) (rand()%(40)) - 20.0f;
         
         for (m=0; m<longitud; m++) {
            if (serpiente[m].x != comida.x && serpiente[m].y != comida.y) libre++;
         }
         if (libre == longitud) esp_libre = 1;
      }
    }
   
   bool Avanzar() {
      switch (direccion) {
         case ARRIBA: frente.y = frente.y + 1.0f; break;
         case ABAJO: frente.y = frente.y - 1.0f; break;
         case IZDA: frente.x = frente.x - 1.0f; break;
         case DCHA: frente.x = frente.x + 1.0f; break;
      }
      
      for (int p=1; p<longitud; p++) if (serpiente[0].x == serpiente[p].x && serpiente[0].y == serpiente[p].y) colision = 1;
      if (frente.y > 19.0f || frente.y < -20.0f || frente.x > 19.0f || frente.x < -20.0f ) colision = 1;
      else {      
         if (frente.x == comida.x && frente.y == comida.y) {
            longitud++;
            colocarNuevaComida();
         }
         for (int p=longitud-1; p>=0; p--) {
            serpiente[p+1].x = serpiente[p].x;
            serpiente[p+1].y = serpiente[p].y;
         }
         serpiente[0].x = frente.x;
         serpiente[0].y = frente.y;
      }
      if (!colision) return 1;
      else return 0;
   }   
} snake;

void PintarEscena() {
    glMatrixMode(GL_MODELVIEW);
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();
   
   snake.Pintar();
       
    glutSwapBuffers();
}
 
void ReProyectar(int w, int h) {
    GLfloat formato;
 
    if(h == 0) h = 1;
       
    glViewport(0, 0, w, h);
 
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
 
    formato = (GLfloat)w / (GLfloat)h;
    if (w <= h) glOrtho (-20.0f, 20.0f, -20.0f / formato, 20.0f / formato, 1.0f, -1.0f);
    else glOrtho (-20.0f * formato, 20.0f * formato, -20.0f, 20.0f, 1.0f, -1.0f);
}
 
void ControlFlechas(int key, int x, int y) {
    if (key==GLUT_KEY_UP) if (snake.direccion!=ABAJO) snake.direccion = ARRIBA;
    if (key==GLUT_KEY_DOWN) if (snake.direccion!=ARRIBA) snake.direccion = ABAJO;
    if (key==GLUT_KEY_LEFT) if (snake.direccion!=DCHA) snake.direccion = IZDA;
    if (key==GLUT_KEY_RIGHT) if (snake.direccion!=IZDA) snake.direccion = DCHA;
}
 
void Mover(int value) {
   if (snake.Avanzar()) glutTimerFunc(snake.milisegundos,Mover,1);
}
 
int main(int argc, char **argv)
{
   glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
   glutInitWindowSize(600,600);
   glutInitWindowPosition(100,100);
   glutCreateWindow("SNAKE by HarZe");
   glutInit(&argc,argv);
   
    srand(time(0));
   
    snake.Iniciar();
   
   glutReshapeFunc(ReProyectar);
   glutDisplayFunc(PintarEscena);
   glutTimerFunc(snake.milisegundos,Mover,1);
   glutSpecialFunc(ControlFlechas);
   glutIdleFunc(PintarEscena);
   
   glutMainLoop();
    return 0;
}