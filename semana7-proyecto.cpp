#include <stdio.h>
#include <math.h>
#include <GL/freeglut.h>

GLfloat girax = 0, giray = 0;
float a;
// Variables globales
double rotate_y=0;
double rotate_x=0;
GLUquadricObj *cilindro;

GLfloat Diffuse[] = {1.0, 1.0, 0.5, 1.0};
GLfloat Specular[] = {1.0 ,1.0, 1.0, 1.0};
GLfloat Position[] = {0.0, 10.0, 0.0, 1.0};
GLfloat Position2[] = {0.0, 0.0, 5.0, 1.0};

float pos_camX = 0, pos_camY = 0, pos_camZ = 0;
int eye_camX = 0, eye_camY = 0, eye_camZ = 0;
float posX = 10, posY = 0, posZ = 10;

float x=30,y=30,z=50;
///////////////////////////////////////////////////////////////////


void LineaCubo(int x){
	glPushMatrix();
	glScalef(10.0, 10.0, 10.0);

	//linea
	glLineWidth(x);    // grosor de la l�nea
	glBegin (GL_LINE_STRIP); 
	glVertex3f( 0.5, -0.5, -0.5 );
	glVertex3f( 0.5, 0.5, -0.5 );
	glVertex3f( -0.5, 0.5, -0.5 );
	glVertex3f( -0.5, -0.5, -0.5 );
	glVertex3f( 0.5, -0.5, -0.5 );
	glEnd ();	

	//linea
	glLineWidth(x);    // grosor de la l�nea
	glBegin (GL_LINE_STRIP);
	glVertex3f( 0.5, -0.5, 0.5 );
	glVertex3f( 0.5, 0.5, 0.5 );
	glVertex3f( -0.5, 0.5, 0.5 );
	glVertex3f( -0.5, -0.5, 0.5 );
	glVertex3f( 0.5, -0.5, 0.5 );
	glEnd ();

	//linea
	glLineWidth(x);    // grosor de la l�nea
	glBegin (GL_LINE_STRIP); 
	glVertex3f( 0.5, -0.5, -0.5 );
	glVertex3f( 0.5, 0.5, -0.5 );
	glVertex3f( 0.5, 0.5, 0.5 );
	glVertex3f( 0.5, -0.5, 0.5 );
	glVertex3f( 0.5, -0.5, -0.5 );
	glEnd ();

	//linea
	glLineWidth(x);    // grosor de la l�nea
	glBegin (GL_LINE_STRIP); 
	glVertex3f( -0.5, -0.5, 0.5 );
	glVertex3f( -0.5, 0.5, 0.5 );
	glVertex3f( -0.5, 0.5, -0.5 );
	glVertex3f( -0.5, -0.5, -0.5 );
	glVertex3f( -0.5, -0.5, 0.5 );
	glEnd ();

	//linea
	glLineWidth(x);    // grosor de la l�nea
	glBegin (GL_LINE_STRIP); 
	glVertex3f( 0.5, 0.5, 0.5 );
	glVertex3f( 0.5, 0.5, -0.5 );
	glVertex3f( -0.5, 0.5, -0.5 );
	glVertex3f( -0.5, 0.5, 0.5 );
	glVertex3f( 0.5, 0.5, 0.5 );
	glEnd ();

	//linea
	glLineWidth(x);    // grosor de la l�nea
	glBegin (GL_LINE_STRIP); 
	glVertex3f( 0.5, -0.5, -0.5 );
	glVertex3f( 0.5, -0.5, 0.5 );
	glVertex3f( -0.5, -0.5, 0.5 );
	glVertex3f( -0.5, -0.5, -0.5 );
	glVertex3f( 0.5, -0.5, -0.5 );
	glEnd ();
		
	glPopMatrix();		
}

void paredDerechaFondo() {
	glPushMatrix();
	
	glColor3f(0.63, 0.63, 0.63);
	glTranslatef(-5.21, -1.95, 0.0);
	glScalef(0.04, 0.65, 1.0);
	glutSolidCube(10);
	glColor3f(0.0f, 0.0f, 0.0f);
	LineaCubo(1.5);

	glPopMatrix();
}

void paredIzquierdaFondo() {
	glPushMatrix();
	
	glColor3f(0.63, 0.63, 0.63);
	glTranslatef(0.0, -1.95, -5.21);
	glScalef(1.0, 0.65, 0.04);
	glutSolidCube(10);
	glColor3f(0.0f, 0.0f, 0.0f);
	LineaCubo(1.5);

	glPopMatrix();
}

void ceramico(float x,float z){
	glPushMatrix();  ///inicio
	glBegin(GL_POLYGON);
        
	glColor3f( 1.0, 1.0, 1.0 );             

    glVertex3f( x, 0.00001,z);
    glVertex3f( x+0.0754,0.00001,z);
    glVertex3f( x+0.0754, 0.00001,z-0.0754);
    glVertex3f( x, 0.00001,z-0.0754);

	glEnd();

	glBegin(GL_LINE_STRIP);

	glLineWidth(100.0);
	glColor3f( 0.0, 0.0, 0.0 );             

    glVertex3f( x, 0.0001,z);
	glVertex3f( x+0.0754,0.0001,z);
	glVertex3f( x+0.0754, 0.0001,z-0.0754);
	glVertex3f( x, 0.0001,z-0.0754);
	glVertex3f( x, 0.0001,z);
	glEnd();

	glPopMatrix ();
}

void CuadrosPiso(){
	glPushMatrix();
		glColor3f(0.87f, 0.87f, 0.87f);
		glTranslatef(-5.0, -4.8, 5.0);
		glScalef(22.1, 22.1, 22.1);

		float Xc=0.0;
		float Zc=-0.0;

		for(int i=0;i<36;i++){
	
			if(i%6==0 && i!=0){
	    	    Xc = 0.0;
	    	    Zc = Zc-0.0754;   
			}
			ceramico(Xc,Zc);
			Xc = Xc+0.0754;
		}
	glPopMatrix ();
}

void PisoCuarto(){
	CuadrosPiso();
	glPushMatrix();
		glColor3f(0.87f, 0.87f, 0.87f);
		glTranslatef(0.0, -5.0, 0.0);
		glScalef(1.0, 0.04, 1.0);
		glutSolidCube(10);
		glColor3f(0.0f, 0.0f, 0.0f);
		LineaCubo(1.5);
		glEnd();
	glPopMatrix();	
}

void Alfombra() {
	glPushMatrix();
		glColor3f(0.13f, 0.13f, 0.13f);
		glTranslatef(2.4, -4.75, -1.9);
		glScalef(0.9, 0.01, 1.1);
		glutSolidCube(5);
		glScalef(0.5, 0.5, 0.5);
		glColor3f(0.0f, 0.0f, 0.0f);
		LineaCubo(1.5);		
		glEnd();
	glPopMatrix();
}


void Puerta(){
	glPushMatrix();
	glTranslatef(-0.5, 1.0, -6.05);
	glScalef(0.5, 1.1, 1.7);
	
	 	//////////////////////////////////////////////////////////////// puerta/////////////////////////////////////////////////////////////////////////////////////
		glPushMatrix();
		
		glColor3f(1.0, 1.0, 1.0);
		glTranslatef(0.90, -3.0, 0.5);
		glScalef(0.5, 0.48, 0.028);
		glutSolidCube(10);
		glColor3f(0.0f, 0.0f, 0.0f);
		LineaCubo(1);	
		glEnd ();	
		
		glPopMatrix();
		
		//////////////////////////////////////////////////////////////// *puerta/////////////////////////////////////////////////////////////////////////////////////
		glPushMatrix();
		
		glColor3f(1.0, 1.0, 1.0);
		glTranslatef(0.1, -1.5, 0.5);//moviemiento
		glScalef(0.1, 0.06, 0.028);
		glutSolidCube(10);
		glColor3f(0.0f, 0.0f, 0.0f);
		LineaCubo(8);	
		glEnd ();	
		
		glPopMatrix();
		
		//////////////////////////////////////////////////////////////// *puerta/////////////////////////////////////////////////////////////////////////////////////
		glPushMatrix();
		
		glColor3f(1.0, 1.0, 1.0);
		glTranslatef(0.1, -3.0, 0.5);//moviemiento
		glScalef(0.1, 0.09, 0.028);//figura
		glutSolidCube(10);
		glColor3f(0.0f, 0.0f, 0.0f);
		LineaCubo(8);	
		glEnd ();	
		
		glPopMatrix();		
		
		//////////////////////////////////////////////////////////////// *puerta/////////////////////////////////////////////////////////////////////////////////////
		glPushMatrix();
		
		glColor3f(1.0, 1.0, 1.0);
		glTranslatef(0.1, -4.5, 0.5);//moviemiento
		glScalef(0.1, 0.09, 0.028);//figura
		glutSolidCube(10);
		glColor3f(0.0f, 0.0f, 0.0f);
		LineaCubo(8);	
		glEnd ();	
		
		glPopMatrix();
		
		//////////////////////////////////////////////////////////////// *puerta/////////////////////////////////////////////////////////////////////////////////////
		glPushMatrix();
		
		glColor3f(1.0, 1.0, 1.0);
		glTranslatef(1.9, -1.5, 0.5);//moviemiento
		glScalef(0.1, 0.06, 0.028);
		glutSolidCube(10);
		glColor3f(0.0f, 0.0f, 0.0f);
		LineaCubo(8);	
		glEnd ();	
		
		glPopMatrix();
		
		//////////////////////////////////////////////////////////////// *puerta/////////////////////////////////////////////////////////////////////////////////////
		glPushMatrix();
		
		glColor3f(1.0, 1.0, 1.0);
		glTranslatef(1.9, -3.0, 0.5);//moviemiento
		glScalef(0.1, 0.09, 0.028);//figura
		glutSolidCube(10);
		glColor3f(0.0f, 0.0f, 0.0f);
		LineaCubo(8);	
		glEnd ();	
		
		glPopMatrix();
		
		//////////////////////////////////////////////////////////////// *puerta/////////////////////////////////////////////////////////////////////////////////////
		glPushMatrix();
		
		glColor3f(1.0, 1.0, 1.0);
		glTranslatef(1.9, -4.5, 0.5);//moviemiento
		glScalef(0.1, 0.09, 0.028);//figura
		glutSolidCube(10);
		glColor3f(0.0f, 0.0f, 0.0f);
		LineaCubo(8);	
		glEnd ();	
		
		glPopMatrix();
	
	glPopMatrix();
}





void ruedaSilla(float x, float y, float z) {
	glPushMatrix();
		glColor3f(0.0, 0.0, 0.0);
		glTranslatef(x, y, z);
		glutSolidSphere(0.07, 100, 5);
	glPopMatrix();
}

void pataSilla(float x, float y, float z, float ang) {
	glPushMatrix();
		glColor3f(0.0, 0.0, 0.0);
		glTranslatef(x, y, z);
		glRotatef(ang, 0.0, 1.0, 0.0);
		glScalef(1.0, 1.0, -3.1);
		glutSolidCube(0.11);
		glScalef(0.011, 0.011, 0.011);
		glColor3f(0.0f, 0.0f, 0.0f);
		LineaCubo(1.5);			
	glPopMatrix();
}

void ejeSilla() {
	glPushMatrix();
		glColor3f(0.0, 0.0, 0.0);
		glTranslatef(-2.975, -4.81, 1.7);
		glutSolidSphere(0.12, 10, 10);
	glPopMatrix();
}

void paloSilla() {
	glPushMatrix();
		glColor3f(0.0, 0.0, 0.0);
		glTranslatef(-2.975, -4.35, 1.7);
		glScalef(0.1, 0.65, 0.1);
		glutSolidCube(1);
		glScalef(0.1, 0.1, 0.1);
		glColor3f(0.0f, 0.0f, 0.0f);
		LineaCubo(1.5);			
	glPopMatrix();
}

void asiento() {
	glPushMatrix();
		glColor3f(0.84, 0.84, 0.84);
		glTranslatef(-2.975, -4, 1.7);
		glRotatef(40, 0.0, 1.0, 0.0);
		glScalef(3.5, 1.0, 3.5);
		glutSolidCube(0.2);
		glScalef(0.02, 0.02, 0.02);
		glColor3f(0.0f, 0.0f, 0.0f);
		LineaCubo(1.5);			
	glPopMatrix();
}

void respaldar() {
	glPushMatrix();
		glColor3f(0.84, 0.84, 0.84);
		glTranslatef(-2.7, -3.4, 1.45);
		glRotatef(130, 0.0, 1.0, 0.0);
		glScalef(3.5, 6.9, 1.0);
		glutSolidCube(0.2);
		glScalef(0.02, 0.02, 0.02);
		glColor3f(0.0f, 0.0f, 0.0f);
		LineaCubo(1.5);			
	glPopMatrix();
}

void posaBrazos(float x, float y, float z) {
	glPushMatrix();
		glColor3f(0.1, 0.1, 0.1);
		glTranslatef(x, y, z);
		glRotatef(130, 0.0, 1.0, 0.0);
		glScalef(0.2, 0.1, 1.0);
		glutSolidCube(0.5);
		glScalef(0.05, 0.05, 0.05);
		glColor3f(0.0f, 0.0f, 0.0f);
		LineaCubo(1.5);			
	glPopMatrix();
}

void paloPosaBrazos(float x, float y, float z) {
	glPushMatrix();
		glColor3f(0.1, 0.1, 0.1);
		glTranslatef(x, y, z);
		glRotatef(130, 0.0, 1.0, 0.0);
		glRotatef(90, 1.0, 0.0, 0.0);
		glScalef(0.2, 0.1, 1.0);
		glutSolidCube(0.5);
		glScalef(0.05, 0.05, 0.05);
		glColor3f(0.0f, 0.0f, 0.0f);
		LineaCubo(1.5);			
	glPopMatrix();
}

 

void caLateral()
{
	
	// Propiedades del material

// "Limpiamos" el frame buffer con el color de "Clear", en este color negro
// Aqu� va, verificarlo en el repintado
// Rotacion de 20 grados en torno al eje x

GLfloat mat_ambient[]={0.0,0.0,0.0,1.0};
//GLfloat mat_ambient[] = { 0.329412f, 0.223529f, 0.027451f,1.0f };
GLfloat mat_marron[] = { 0.094f, 0.023f, 0.0f, 1.0f };
GLfloat mat_plomo[] = { 0.250f, 0.250f, 0.250f, 1.0f };
//GLfloat mat_specular[] = { 0.992157f, 0.941176f, 0.807843f, 1.0f };
GLfloat shine[] = {27.8974f}; 

glPushMatrix();
glScalef(0.3,0.3,0.3);
glTranslatef(0.0,-6.3,-0.4);
glRotated(90.0, 0.0, 1.0, 0.0);
// Rotacion de -30 grados en torno al eje y
//glRotated(-30.0, 0.0, 1.0, 0.0);
//glTranslatef(-5,0.1,0);
// ESPALDAR/////////////////////////////////////////////////////////////////////////////////
//Aplicando el setMaterial


glPushMatrix();
glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient);
glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_marron);
//glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
glMaterialfv(GL_FRONT, GL_SHININESS, shine); 
glScalef(1.5,0.7,0.03);
glColor4f(0.094f, 0.023f, 0.0f, 1.0f);
glutSolidCube(10);
glPopMatrix();

///////////////////////////////////////////////////////////////////////////////////////////
glPushMatrix();
// BASE //////////////////////////////////////////////////////////////////////////////////
//glScalef(1.5,0.7,0.05);
glColor4f(0.094f, 0.023f, 0.0f, 1.0f);//red
glTranslatef(0,-2.8,-10);
glScalef(1.5,0.15,2);
//glTranslatef();
glutSolidCube(10);
glPopMatrix();
/////////////////////////////////////////////////////////////////////////////////////////////

glPushMatrix();
glColor4f(0.250f, 0.250f, 0.250f,  1.0f);//red
// COLCHON /////////////////////////////////////////////////////////////////////////////////
//glScalef(1.5,0.7,0.05);
glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient);
glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_plomo);

glTranslatef(0,-0.5,-10);
glScalef(1.47,0.3,2);
//glTranslatef();
glutSolidCube(10);
glPopMatrix();
////////////////////////////////////////////////////////////////////////////////////////////

glPushMatrix();
glColor4f(0.501f, 0.501f, 0.501f,  1.0f);//red
// CABECERA DERECHA ////////////////////////////////////////////////////////////////////////
glTranslatef(0.5,1,-2.3);
//glTranslatef(0,-0.5,-10);
glScalef(1.3,0.1,0.9);
//glTranslatef();
//glutSolidCube(10);
glRotated(90, 0,1,0);
cilindro = gluNewQuadric();
gluQuadricDrawStyle(cilindro,GLU_FILL);
gluCylinder(cilindro,2,2,5,50,50);
//glTranslatef();
//glutSolidCube(10);
glPopMatrix();
/////////////////////////////////////////////////////////////////////////////////////////////

glPushMatrix();
glColor4f(0.501f, 0.501f, 0.501f,  1.0f);//red
// CABECERA IZQUIERDA ////////////////////////////////////////////////////////////////////////
glTranslatef(-6.9,1,-2.3);
//glTranslatef(0,-0.5,-10);
glScalef(1.3,0.1,0.9);
//glTranslatef();
//glutSolidCube(10);
glRotated(90, 0,1,0);
cilindro = gluNewQuadric();
gluQuadricDrawStyle(cilindro,GLU_FILL);
gluCylinder(cilindro,2,2,5,50,50);
glPopMatrix();
///////////////////////////////////////////////////////////////////////////////////////////////
glPopMatrix();



}

void sofa()
{
	// Propiedades del material

	// "Limpiamos" el frame buffer con el color de "Clear", en este color negro
	//glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // Aqu� va, verificarlo en el repintado
	// Rotacion de 20 grados en torno al eje x
	
	glPushMatrix();
		GLfloat mat_ambient[] = { 0.0f, 0.0f, 0.0f,1.0f };
		GLfloat mat_plomo[] = { 0.376f, 0.376f, 0.376f, 1.0f };
		GLfloat mat_marron[] = { 0.2f, 0.098f, 0.0f, 1.0f };
		//GLfloat mat_specular[] = { 0.992157f, 0.941176f, 0.807843f, 1.0f };
		GLfloat shine[] = {27.8974f}; 

		//glTranslatef(-20,1,9);
		glScalef(0.17,0.16,0.15);

		//glRotated(10.0, 0.0, 0.0, 0.0);
		// Rotacion de -30 grados en torno al eje y
		//glRotated(15, 1.0, 1.0, 0.0);
		glTranslatef(-19.0, 2.6,6.0);
		// LATERAL ///////////////////////////////////////////////////////////////
		//Aplicando el setMaterial

		glPushMatrix();
			glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient);
			glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_plomo);
			//glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
			glMaterialfv(GL_FRONT, GL_SHININESS, shine); 
			glColor4f(0.376f, 0.376f, 0.376f, 1.0f);//red
			glScalef(1.9,1.3,0.2);
			glutSolidCube(10);
			glColor3f(0.0f, 0.0f, 0.0f);
			LineaCubo(1.5);
		glPopMatrix();
		///////////////////////////////////////////////////////////////////////

		glPushMatrix();
			glColor4f(0.25f, 0.25f, 0.25f, 1.0f);
			// BASE //////////////////////////////////////////////////////////////
			glTranslatef(0,-4.99,7.1);
			glScalef(1.9,0.3,1.2);
			glutSolidCube(10);
			glColor3f(0.0f, 0.0f, 0.0f);
			LineaCubo(1.5);
		glPopMatrix();
		/////////////////////////////////////////////////////////////////////

		//glPopMatrix();
		///////////////////////////////////////////////////////////////////////
		glPushMatrix();
			glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_marron);
			glColor4f(0.25f, 0.25f, 0.25f, 1.0f);
			// BRACERA DERECHA ///////////////////////////////////////////////////////
			glTranslatef(9.9,1,7);
			glScalef(0.09,0.05,1.6);
glutSolidCube(10);
glPopMatrix();
////////////////////////////////////////////////////////////////////////

glPushMatrix();
glColor4f(0.245f, 0.08f, 0.2f, 2.0f);//
// BRACERA IZQUIERDA /////////////////////////////////////////////////////////
glTranslatef(-9.9,1,7);
glScalef(0.09,0.05,1.6);
glutSolidCube(10);
glPopMatrix();
////////////////////////////////////////////////////////////////////////

glPushMatrix();
glColor4f(0.245f, 0.08f, 0.2f, 2.0f);//
// PATAS delantea IZQUIERDA /////////////////////////////////////////////////////////
glTranslatef(-9.9,-4.67,12.7);
glScalef(0.09,1.08,0.06);
glutSolidCube(10);
glPopMatrix();
////////////////////////////////////////////////////////////////////////

glPushMatrix();
glColor4f(0.245f, 0.08f, 0.2f, 2.0f);//
// PATAS delantera DERECHA /////////////////////////////////////////////////////////
glTranslatef(9.9,-4.67,12.7);
glScalef(0.09,1.08,0.06);
glutSolidCube(10);
glPopMatrix();
////////////////////////////////////////////////////////////////////////

glPushMatrix();
glColor4f(0.245f, 0.08f, 0.2f, 2.0f);//
// PATAS TRASERA IZQUIERDA /////////////////////////////////////////////////////////
glTranslatef(-9.9,-4.67,0.3);
glScalef(0.09,1.08,0.06);
glutSolidCube(10);
glPopMatrix();
////////////////////////////////////////////////////////////////////////

glPushMatrix();
glColor4f(0.245f, 0.08f, 0.2f, 2.0f);//
// PATAS TRASERA DERERCHA /////////////////////////////////////////////////////////
glTranslatef(9.9,-4.67,0.3);
glScalef(0.09,1.08,0.06);
glutSolidCube(10);
glPopMatrix();
glPopMatrix();
////////////////////////////////////////////////////////////////////////
//glPopMatrix();
//glFlush();
}

void Muebles(){
	glPushMatrix();
		glTranslatef(4.6, -1.85, 2.75);
		glRotatef(00, 0.0, 1.0, 0.0);
		//glScalef(0.7, 0.7, 0.7);
		caLateral();
	glPopMatrix();	
	
	glPushMatrix();
		glTranslatef(6.2, -3.52, -5.7);
		//glScalef(0.7, 0.7, 0.7);
		sofa();
	glPopMatrix();		
}

void specialKeys(int a_keys, int x, int y){ // Funcion para manejo de teclas especiales (arrow keys)
	switch (a_keys) {
		case GLUT_KEY_PAGE_UP:
			pos_camY -= 0.5;
			break;
		case GLUT_KEY_PAGE_DOWN:
			pos_camY += 0.5;
			break;
		case GLUT_KEY_UP: //Tecla arriba
			eye_camX = (eye_camX-5)%360;
			break;
		case GLUT_KEY_DOWN: //Tecla abajo
			eye_camX = (eye_camX+5)%360;
			break;
		case GLUT_KEY_LEFT: //Tecla izquierda
			eye_camY = (eye_camY-5)%360;
			break;
		case GLUT_KEY_RIGHT: //Tecla derecha
			eye_camY = (eye_camY+5)%360;
			break;
		default:
		break;
	}
	glutPostRedisplay(); //Indica a OpenGL Redibujar
}


void teclado(unsigned char key, int x, int y){
	switch (key){
		case '-':
			posZ += 0.5;
			break;break;
		case '+':
			posZ -= 0.5;
			break;
		case 'w': //Movimientos de camara
		case 'W':
			posY += 0.5;
			break;
		case 's':
		case 'S':
			posY -= 0.5;
			break;
		case 'a':
		case 'A':
			posX -= 0.5;
			break;
		case 'd':
		case 'D':
			posX += 0.5;
			break;
		 //////////////////////////////////////////	
		case 27:
			exit(0); // Salimos del programa
			break;
		default:
			break;	
	}
	glutPostRedisplay(); //Indica a OpenGL Redibujar
}

void manejarTeclado(unsigned char key, int x, int y){
    
    teclado(key,x,y);
    glutPostRedisplay();
    
}

void display() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
	glMatrixMode(GL_MODELVIEW);
	glTranslatef(posX, posY, posZ);
	//glTranslatef(pos_camX, pos_camY, pos_camZ);
	glRotatef(eye_camX, 1.0, 0.0, 0.0);
	glRotatef(eye_camY, 0.0, 1.0, 0.0);
	glRotatef(eye_camZ, 0.0, 0.0, 1.0);
	
	glPushMatrix();
	
		Alfombra();
		PisoCuarto();
		paredDerechaFondo();
		paredIzquierdaFondo();
		Puerta();
		Muebles();
	glPopMatrix();
	glFlush();
	glutSwapBuffers();	
}

void reshape(int w, int h) {
	glViewport(0, 0, (GLsizei) w, (GLsizei) h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(50.0, (GLfloat)w/ (GLfloat)h, 1.0, 100.0);
	glOrtho(-10, 10, -10, 10, -10, 10);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(0.0, 2.0, 5.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
}
 
int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GL_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(1450, 1000);
    glutInitWindowPosition (0, 0);
	glutCreateWindow("Habitacion");
		
	glEnable(GL_DEPTH_TEST);
	glutReshapeFunc(reshape);
	glutDisplayFunc(display);
	glutKeyboardFunc(manejarTeclado);
	glutSpecialFunc(specialKeys);
	
	glutMainLoop();
	return 0;
}

















