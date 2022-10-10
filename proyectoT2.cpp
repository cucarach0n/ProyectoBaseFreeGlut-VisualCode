#include<iostream>
#include <stdio.h>
#include <math.h>
#include <GL/freeglut.h>
using namespace std;


// Variables globales

GLUquadricObj *cilindro;

float pos_camY = 0;
int eye_camX = 0, eye_camY = 0, eye_camZ = 0;
float posX = 10, posY = 0, posZ = 10;


float posXPericote = 6.0;
float posYPericote = -1;
float RED1=0.0, GREEN1=0.0, BLUE1=0.0,RED2=0.0,GREEN2=0.0,BLUE2=0.0,RED3=0.0,GREEN3=0.0,BLUE3=0.0,RED4=0.0,GREEN4=0.0,BLUE4=0.0;
int random = 0;
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
void SillaGamer() {
	glPushMatrix();
	
	glScalef(1.8, 1.8, 1.8);
	
		///////////////////////////////////////////////////// RUEDAS SILLA ////////////////////////////////////////////////////////////////////////////////
		ruedaSilla(-3.01, -4.93, 2.1);
		ruedaSilla(-3.3, -4.93, 1.7);
		ruedaSilla(-3.01, -4.93, 1.3);
		ruedaSilla(-2.65, -4.93, 1.49);
		ruedaSilla(-2.65, -4.93, 1.91);
		
		//////////////////////////////////////////////////// EJE DE LA SILLA  //////////////////////////////////////////////////////////////////////////////////
		ejeSilla();
		
		///////////////////////////////////////////////////// PATAS SILLA ///////////////////////////////////////////////////////////////////////////////////
		pataSilla(-3, -4.81, 2, -8);
		pataSilla(-3.2, -4.81, 1.7, 90);
		pataSilla(-3, -4.81, 1.4, 8);
		pataSilla(-2.75, -4.81, 1.53, -60);
		pataSilla(-2.75, -4.81, 1.87, 60);
		
		///////////////////////////////////////////////////// PALO SILLA /////////////////////////////////////////////////////////////////////////////
		paloSilla();
		
		/////////////////////////////////////////////////////// ASIENTO SILLA //////////////////////////////////////////////////////////////////////////
		asiento();
		
		/////////////////////////////////////////////////////// RESPALDAR SILLA ////////////////////////////////////////////////////////////////////////
		respaldar(); 
		
		/////////////////////////////////////////////////////// POSA BRAZOS ///////////////////////////////////////////////////////////////////////////
		posaBrazos(-2.75, -3.5, 1.95);
		posaBrazos(-3.2, -3.5, 1.4);
		paloPosaBrazos(-2.75, -3.75, 1.95);
		paloPosaBrazos(-3.2, -3.75, 1.4);	
		
	glPopMatrix();
}
void Escritorio(){
	glPushMatrix();
	glScalef(0.8, 1.0, 0.7);
	
	///////////////////////////////////////////// MESA ESCRITORIO ////////////////////////////////////////////////////////
	glPushMatrix();
		glColor3f(0.39f, 0.32f, 0.27f);
		glTranslatef(-3.95, -2.75, -2.0);
		glScalef(0.2, 0.01, 0.6);
		glutSolidCube(10);
		glColor3f(0.0f, 0.0f, 0.0f);
		LineaCubo(1.5);		
		glEnd();
	glPopMatrix();	
	
	///////////////////////////////////////////// CAJON 1 ////////////////////////////////////////////////////////
	glPushMatrix();
		glColor3f(1.0f, 1.0f, 1.0f);
		glTranslatef(-3.8, -3.2, 0.15);
		glScalef(0.18, 0.05, 0.13);
		glutSolidCube(10);
		glColor3f(0.0f, 0.0f, 0.0f);
		LineaCubo(1.5);		
		glEnd();
	glPopMatrix();
		
	///////////////////////////////////////////// CAJON 2 ////////////////////////////////////////////////////////
	glPushMatrix();
		glColor3f(1.0f, 1.0f, 1.0f);
		glTranslatef(-3.8, -3.8, 0.15);
		glScalef(0.18, 0.05, 0.13);
		glutSolidCube(10);
		glColor3f(0.0f, 0.0f, 0.0f);
		LineaCubo(1.5);		
		glEnd();
	glPopMatrix();
			
	///////////////////////////////////////////// CAJON 3 ////////////////////////////////////////////////////////
	glPushMatrix();
		glColor3f(1.0f, 1.0f, 1.0f);
		glTranslatef(-3.8, -4.4, 0.15);
		glScalef(0.18, 0.05, 0.13);
		glutSolidCube(10);
		glColor3f(0.0f, 0.0f, 0.0f);
		LineaCubo(1.5);		
		glEnd();
	glPopMatrix();
	
	///////////////////////////////////////////// CAJONES GENERAL ESCRITORIO ////////////////////////////////////////////////////////
	glPushMatrix();
		glColor3f(1.0f, 1.0f, 1.0f);
		glTranslatef(-3.95, -3.8, 0.15);
		glScalef(0.2, 0.195, 0.15);
		glutSolidCube(10);
		glColor3f(0.0f, 0.0f, 0.0f);
		LineaCubo(1.5);		
		glEnd();
	glPopMatrix();	
	
	///////////////////////////////////////////// PATA ESCRITORIO ////////////////////////////////////////////////////////
	glPushMatrix();
		glColor3f(1.0f, 1.0f, 1.0f);
		glTranslatef(-3.95, -3.8, -4.88);
		glScalef(0.2, 0.195, 0.01);
		glutSolidCube(10);
		glColor3f(0.0f, 0.0f, 0.0f);
		LineaCubo(1.5);		
		glEnd();
	glPopMatrix();
	glPushMatrix();
	glTranslatef(-2.3, 1.0, -6.15);
	glScalef(0.5, 1.1, 1.8);

		//////////////////////////////////////////////////////////////// MONITOR 1 MARCO /////////////////////////////////////////////////////////////////////////////////////
		glPushMatrix();
		
		glColor3f(0.0, 0.0, 0.0);
		glTranslatef(-4.81, -2.7, 1.4);
		glScalef(0.01, 0.11, 0.11);
		glutSolidCube(10);
		glColor3f(0.0f, 0.0f, 0.0f);
		LineaCubo(1);	
		glEnd ();	
		
		glPopMatrix();
	
		//////////////////////////////////////////////////////////////// MONITOR 1 /////////////////////////////////////////////////////////////////////////////////////
		glPushMatrix();
		
		glColor3f( 0.529 , 0.807 , 0.921 );
		glTranslatef(-4.8, -2.7, 1.4);
		glScalef(0.01, 0.1, 0.1);
		glutSolidCube(10);
		glColor3f(135, 206, 235);
		LineaCubo(1);	
		glEnd ();	
		
		glPopMatrix();

		//////////////////////////////////////////////////////////////// MONITOR 2 MARCO /////////////////////////////////////////////////////////////////////////////////////
		
		glPushMatrix();
		
		glColor3f(0.0, 0.0, 0.0);
		glTranslatef(-4.57, -2.7, 2.5);
		glRotatef(40, 0.0, 1.0, 0.0);
		glScalef(0.009, 0.11, 0.11);
		glutSolidCube(10);
		glColor3f(0.0f, 0.0f, 0.0f);
		LineaCubo(1);		
		glEnd();
		
		glPopMatrix();
		
		//////////////////////////////////////////////////////////////// MONITOR 2 /////////////////////////////////////////////////////////////////////////////////////
		
		glPushMatrix();
		
		glColor3f( 0.529 , 0.807 , 0.921 );
		glTranslatef(-4.56, -2.7, 2.5);
		glRotatef(40, 0.0, 1.0, 0.0);
		glScalef(0.01, 0.1, 0.1);
		glutSolidCube(10);
		glColor3f(0.0f, 0.0f, 0.0f);
		LineaCubo(1);		
		glEnd ();
		glPopMatrix();
		
		//////////////////////////////////////////////////////////////// RACK 1 /////////////////////////////////////////////////////////////////////////////////////
				
		glPushMatrix();
		
		glColor3f(0.0, 0.0, 0.0);
		glTranslatef(-5.1, -2.9, 1.4);
		glRotatef(90.0, 1.0, 0.0, 0.0);
		glScalef(0.2, 0.05, 0.05);
		cilindro = gluNewQuadric();
		gluQuadricDrawStyle(cilindro,GLU_FILL);
		gluCylinder(cilindro,1,1,10,20,20);
		
		glPopMatrix();						
		
		//////////////////////////////////////////////////////////////// RACK 2 /////////////////////////////////////////////////////////////////////////////////////
				
		glPushMatrix();
		
		glColor3f(0.0, 0.0, 0.0);
		glTranslatef(-4.8, -2.9, 2.5);
		glRotatef(90.0, 1.0, 0.0, 0.0);
		glScalef(0.2, 0.05, 0.05);
		cilindro = gluNewQuadric();
		gluQuadricDrawStyle(cilindro,GLU_FILL);
		gluCylinder(cilindro,1,1,10,20,20);	
		
		glPopMatrix();
		
		
		glPopMatrix();
			////////////////////////////////////////////////////////////////////////////// TECLADO //////////////////////////////////////////////////////////////////////////////////////
	
	glPushMatrix();
	
	glColor3f(0.59f, 0.6f, 0.6f);
	glTranslatef(-4.0, -2.63, -3.75);
	glRotatef(90, 0.0, 1.0, 0.0);
	glScalef(0.13, 0.006, 0.05);
	glutSolidCube(10);
	glColor3f(0.0f, 0.0f, 0.0f);
	LineaCubo(1.5);	
	
	glPopMatrix();

		glPushMatrix();
		
		glColor3f(0.08, 0.08, 0.08);
		glTranslatef(-4.98, -1.8, -2.5);
		glScalef(0.002, 0.15, 0.435);
		glutSolidCube(10);
		glColor3f(0.0f, 0.0f, 0.0f);
		LineaCubo(1.5);
		
		glPopMatrix();
	
	////////////////////////////////////////////////////////////////////////////// MOUSE PAD ///////////////////////////////////////////////////////////////////////////////////////
	
	glPushMatrix();
	
	glColor3f(0.5f, 0.49f, 0.48f);
	glTranslatef(-4.0, -2.67, -3.5);
	glRotatef(90, 0.0, 1.0, 0.0);
	glScalef(0.2, 0.001, 0.1);
	glutSolidCube(10);
	glColor3f(0.0f, 0.0f, 0.0f);
	LineaCubo(1.5);	
	
	glPopMatrix();	
	glPopMatrix();
}

void TV(){
	
	///////////////////////////////////////////// TV //////////////////////////////////////////////////////////////////////
	glPushMatrix();
	
		glColor3f(0.0, 0.0, 0.0);
		glTranslatef(-4.95, -0.9, 2.4);
		glScalef(0.0078, 0.25, 0.41);
		glutSolidCube(10);
		glColor3f(0.0f, 0.0f, 0.0f);
		LineaCubo(1.5);

	glPopMatrix();
		
	///////////////////////////////////////////// TV DISPLAY //////////////////////////////////////////////////////////////////////
	glPushMatrix();
	
		glColor3f( RED1, GREEN1, BLUE1 );
		glTranslatef(-4.95, -0.9, 1.0);//(-4.95, -0.9, 2.4)
		glScalef(0.008, 0.23, 0.095);//glScalef(0.008, 0.23, 0.39)
		glutSolidCube(10);
		glColor3f(0.0f, 0.0f, 0.0f);
		LineaCubo(1.5);

	glPopMatrix();

    glPushMatrix();
	
		glColor3f( RED2, GREEN2, BLUE2 );
		glTranslatef(-4.95, -0.9, 1.95);
		glScalef(0.008, 0.23, 0.095);//glScalef(0.008, 0.23, 0.39)
		glutSolidCube(10);
		glColor3f(0.0f, 0.0f, 0.0f);
		LineaCubo(1.5);

	glPopMatrix();

    glPushMatrix();
	
		glColor3f( RED3, GREEN3, BLUE3 );
		glTranslatef(-4.95, -0.9, 2.9);
		glScalef(0.008, 0.23, 0.095);//glScalef(0.008, 0.23, 0.39)
		glutSolidCube(10);
		glColor3f(0.0f, 0.0f, 0.0f);
		LineaCubo(1.5);

	glPopMatrix();
    glPushMatrix();
	
		glColor3f( RED4, GREEN4, BLUE4 );
		glTranslatef(-4.95, -0.9, 3.85);
		glScalef(0.008, 0.23, 0.095);//glScalef(0.008, 0.23, 0.39)
		glutSolidCube(10);
		glColor3f(0.0f, 0.0f, 0.0f);
		LineaCubo(1.5);

	glPopMatrix();
	//ImagenTV();		
	
	///////////////////////////////////////////// TV //////////////////////////////////////////////////////////////////////
	glPushMatrix();
		
		glColor3f(0.0, 0.0, 0.0);
		glTranslatef(-4.96, -2.5, 2.4);
		glRotatef(90, 1.0, 0.0, 0.0);
		glScalef(0.01, 0.3, 0.01);//glScalef(0.01, 0.3, 0.01)
		glutSolidCube(10);
		glColor3f(0.0f, 0.0f, 0.0f);
		LineaCubo(1.5);
	glPopMatrix();
	
}


///////Silla/////////////////////
void silla(){

    //espaldar	
    glPushMatrix();
        
        glScalef(35.0,35.0,3.0);
        glColor3f(0.8078f,0.2157f,0.2235f);
        glutSolidCube(1);
    glPopMatrix();

    //palo espaldar
    glPushMatrix();
        glTranslatef(0.0,-20.0,0.0);
        glScalef(5.0,20.0,3.0);
        glColor3f(0.8941f,0.8471f,0.8314f);
        glutSolidCube(1);
    glPopMatrix();

    //base
    glPushMatrix();
        glTranslatef(0.0,-30.0,-15.0);
        glScalef(35.0,5.0,30.0);
        glColor3f(0.8078f,0.2157f,0.2235f);
        glutSolidCube(1);
    glPopMatrix();


    //palo central de base
    glPushMatrix();
        glTranslatef(0.0,-45.0,-15.0);
        glScalef(3.0,30.0,3.0);
        glColor3f(0.8941f,0.8471f,0.8314f);
        glutSolidCube(1);
    glPopMatrix();

    //base rueda 1
    glPushMatrix();
        glTranslatef(0.0,-60.0,-15.0);
        glScalef(3.0,3.0,30.0);
        glColor3f(0.3176f,0.3176f,0.3176f);
        glutSolidCube(1);
    glPopMatrix();

    //base rueda 2 
    glPushMatrix();
        glTranslatef(0.0,-60.0,-15.0);
        glScalef(30.0,3.0,3.0);
        glColor3f(0.3176f,0.3176f,0.3176f);
        glutSolidCube(1);
    glPopMatrix();

    //ruedas
    glPushMatrix();
        glTranslatef(12.0,-63.0,-15.0);
        glColor3f(0.1490f,0.1490f,0.1490f);
        glutSolidSphere(3.0,5,5);
    glPopMatrix();

    glPushMatrix();
        glTranslatef(-12.0,-63.0,-15.0);
        glColor3f(0.1490f,0.1490f,0.1490f);
        glutSolidSphere(3.0,5,5);
    glPopMatrix();

    glPushMatrix();
        glTranslatef(0.0,-63.0,-3.0);
        glColor3f(0.1490f,0.1490f,0.1490f);
        glutSolidSphere(3.0,5,5);
    glPopMatrix();

    glPushMatrix();
        glTranslatef(0.0,-63.0,-27.0);
        glColor3f(0.1490f,0.1490f,0.1490f);
        glutSolidSphere(3.0,5,5);
    glPopMatrix();

}

/////fin silla////////////////////

/////dibujar pericote/////////////////////
void DibujarPericote(){

    //cuerpo
    glPushMatrix();
        glTranslatef(0.0,-4.83,0.0);
        glColor3f (0.501 , 0.501 , 0.501 );
        glutSolidSphere(0.3,40,40);
    glPopMatrix();
    //cabeza
    glPushMatrix();
        glTranslatef(-0.3,-4.83,0.0);
        glColor3f (0.501 , 0.501 , 0.501 );
        glutSolidSphere(0.2,40,40);
    glPopMatrix();
    //ojo
    glPushMatrix();
        glTranslatef(-0.4,-4.7,0.04);
        glColor3f (0.411 , 0.047 , 0.047);
        glutSolidSphere(0.05,40,40);
    glPopMatrix();
    //ojo
    glPushMatrix();
        glTranslatef(-0.4,-4.7,-0.04);
        glColor3f (0.411 , 0.047 , 0.047);
        glutSolidSphere(0.05,40,40);
    glPopMatrix();
    //oreja
    glPushMatrix();
        glRotatef(90,0,1,0);
        glTranslatef(0.2,-4.64,-0.3);
        glColor3f (0.501 , 0.6 , 0.501 );
        glutSolidTorus(0.05, 0.05, 20, 20);
    glPopMatrix();
    //oreja
    glPushMatrix();
        glRotatef(90,0,1,0);
        glTranslatef(-0.2,-4.64,-0.3);
        glColor3f (0.501 , 0.6 , 0.501 );
        glutSolidTorus(0.05, 0.05, 20, 20);
    glPopMatrix();
    //nariz
    glPushMatrix();
        glTranslatef(-0.5,-4.8,-0.01);
        glColor3f (0 , 0 , 0);
        glutSolidSphere(0.05,40,40);
    glPopMatrix();
    
  
}
//////fin dibujar pericote////////////////

//////////////BANO///////////////
void PISO_BANIO(){
	//PISO DEL BA?O
	glPushMatrix();
		glColor3f( 0.847 , 0.823 , 0.788 );
		glTranslatef(-7.5,-15.0,6.15);//glTranslatef(-7.5,-16.905,6.15);
		glScalef(4.9,3.0,0.20);//glScalef(4.9,4.9,0.20);
		glutSolidCube(2.0);
	glPopMatrix();
}

void PAREDES_BANIO(){
	
	//PARED DERECHA
	glPushMatrix();
		glColor3f( 0.760 , 0.741 , 0.709 );
		glTranslatef(-7.425,-11.86,9.65);
		glScalef(4.675,0.15,3.5);
		glutSolidCube(2.0);
	glPopMatrix();
	
	//PARED FRENTE
	glPushMatrix();
		glColor3f( 0.760 , 0.741 , 0.709 );
		glTranslatef(-2.75,-19.13,9.725);
		glScalef(0.15,2.675,3.425);
		glutSolidCube(2.0);
	glPopMatrix();
	
	glPushMatrix();
		glColor3f( 0.760 , 0.741 , 0.709 );
		glTranslatef(-2.75,-14.705,12.74);
		glScalef(0.15,1.75,0.41);
		glutSolidCube(2.0);
	glPopMatrix();
	
	glPushMatrix();
		glColor3f( 0.760 , 0.741 , 0.709 );
		glTranslatef(-2.75,-12.482,9.725);
		glScalef(0.15,0.472,3.425);
		glutSolidCube(2.0);
	glPopMatrix();
	
	//PARED FRENTE 2
	glPushMatrix();
		glColor3f(0.63, 0.63, 0.63);
		glTranslatef(-2.74,-19.13,9.715);
		glScalef(0.15,2.675,3.425);
		glutSolidCube(2.0);
	glPopMatrix();
	
	glPushMatrix();
		glColor3f(0.63, 0.63, 0.63);
		glTranslatef(-2.74,-14.695,12.73);
		glScalef(0.15,1.75,0.41);
		glutSolidCube(2.0);
	glPopMatrix();
	
	glPushMatrix();
		glColor3f(0.63, 0.63, 0.63);
		glTranslatef(-2.74,-12.472,9.715);
		glScalef(0.15,0.472,3.425);
		glutSolidCube(2.0);
	glPopMatrix();
	
	//PUERTA
		//Madera
    
    glPushMatrix();
        glRotatef(-30,0,0,1);
        glTranslatef(6.7,0.4,0.0);
        glPushMatrix();
            glColor3f( 0.545 , 0.454 , 0.337 );
            glTranslatef(-2.0805,-14.628,9.3341);
            glRotatef(285.0,0.0,0.0,1.0);
            glScalef(1.75,0.052,3.0);
            glutSolidCube(2.0);
        glPopMatrix();
            //Detalle 1
        glPushMatrix();
            glColor3f( 0.364 , 0.223 , 0.082 );
            glTranslatef(-2.0134,-14.628,9.3341);
            glRotatef(285.0,0.0,0.0,1.0);
            glScalef(1.5,0.0,2.8);
            glutSolidCube(2.0);
        glPopMatrix();
            //Detalle 2
        glPushMatrix();
            glColor3f( 0.545 , 0.454 , 0.337 );
            glTranslatef(-2.0108,-14.622,10.884);
            glRotatef(285.0,0.0,0.0,1.0);
            glScalef(1.15,0.0,1.0);
            glutSolidCube(2.0);
        glPopMatrix();
            //Detalle 3
        glPushMatrix();
            glColor3f( 0.545 , 0.454 , 0.337 );
            glTranslatef(-2.0108,-14.622,7.8341);
            glRotatef(285.0,0.0,0.0,1.0);
            glScalef(1.150,0.0,1.0);
            glutSolidCube(2.0);
        glPopMatrix();
        //MANIJA
            //DETALLE 1
        glPushMatrix();
            glColor3f( 0.898 , 0.862 , 0.796 );
            glTranslatef(-1.7344,-15.637,9.3341);
            glRotatef(285.0,0.0,0.0,1.0);
            glScalef(0.150,0.0,0.15);
            glutSolidCube(2.0);
        glPopMatrix();
            //DETALLE 2
        glPushMatrix();
            glColor3f( 0.388 , 0.298 , 0.160 );
            glTranslatef(-1.6348,-15.629,9.3341);
            glRotatef(285.0,0.0,0.0,1.0);
            glScalef(0.05,0.1,0.05);
            glutSolidCube(2.0);
        glPopMatrix();
            //DETALLE 3
        glPushMatrix();
            glColor3f( 0.388 , 0.298 , 0.160 );
            glTranslatef(-1.585,-15.624,9.1841);
            glRotatef(285.0,0.0,0.0,1.0);
            glScalef(0.05,0.05,0.1);
            glutSolidCube(2.0);
        glPopMatrix();
    glPopMatrix();
}

void WATER_BANIO(){
	//TAPA
	glPushMatrix();
		glColor3f( 0.823 , 0.792 , 0.666 );
		glTranslatef(-11.47,-15.52,7.9);
		glScalef(0.1,0.6,0.6);
		glutSolidCube(2.0);
	glPopMatrix();
	
	//ASIENTO
	glPushMatrix();
		glColor3f( 0.839 , 0.811 , 0.686 );
		glTranslatef(-10.92,-15.52,7.05);
		glScalef(0.65,0.65,0.25);
		glutSolidCube(2.0);
	glPopMatrix();
	
	//ASIENTO
	glPushMatrix();
		glColor3f( 0.874 , 0.858 , 0.827 );
		glTranslatef(-10.92,-15.52,7.05);
		glScalef(0.65,0.65,0.25);
		glutSolidCube(2.0);
	glPopMatrix();
	
	glPushMatrix();
		glColor3f( 0.823 , 0.792 , 0.666 );
		glTranslatef(-10.921,-15.52,6.6);
		glScalef(0.4,0.3,0.2);
		glutSolidCube(2.0);
	glPopMatrix();
	
	glPushMatrix();
		glColor3f( 0.874 , 0.858 , 0.827 );
		glTranslatef(-10.921,-15.52,6.35);
		glScalef(0.65,0.65,0.05);
		glutSolidCube(2.0);
	glPopMatrix();
}

void BASURERO_BANIO(){
	//TAPA 1
	glPushMatrix();
		glColor3f( 0.439 , 0.423 , 0.454 );
		glTranslatef(-10.65,-13.86,6.65);
		glScalef(0.0,0.35,0.35);
		glutSolidCube(2.0);
	glPopMatrix();
	
	//TAPA 2
	glPushMatrix();
		glColor3f( 0.439 , 0.423 , 0.454 );
		glTranslatef(-11.35,-13.86,6.65);
		glScalef(0.0,0.35,0.35);
		glutSolidCube(2.0);
	glPopMatrix();
	
	//TAPA 3
	glPushMatrix();
		glColor3f( 0.439 , 0.423 , 0.454 );
		glTranslatef(-11,-13.51,6.65);
		glScalef(0.35,0.0,0.35);
		glutSolidCube(2.0);
	glPopMatrix();
	
	//TAPA 4
	glPushMatrix();
		glColor3f( 0.439 , 0.423 , 0.454 );
		glTranslatef(-11,-14.21,6.65);
		glScalef(0.35,0.0,0.35);
		glutSolidCube(2.0);
	glPopMatrix();
}

void LAVADERO_BANIO(){
	//CANIO
	glPushMatrix();
		glColor3f( 0.686 , 0.647 , 0.580 );
		glTranslatef(-6.99,-12.76,9.05);
		glScalef(0.1,0.25,0.05);
		glutSolidCube(2.0);
	glPopMatrix();
	
	glPushMatrix();
		glColor3f( 0.686 , 0.647 , 0.580 );
		glTranslatef(-6.99,-12.61,8.9);
		glScalef(0.1,0.1,0.1);
		glutSolidCube(2.0);
	glPopMatrix();
	
	//DETALLE CANIO
	glPushMatrix();
		glColor3f( 0.686 , 0.647 , 0.580 );
		glTranslatef(-6.99,-12.58,8.6);
		glScalef(0.15,0.15,0.2);
		glutSolidCube(2.0);
	glPopMatrix();
	
	//MANIJA 1
	glPushMatrix();
		glColor3f( 0.686 , 0.647 , 0.580 );
		glTranslatef(-6.56,-12.58,8.5);
		glScalef(0.1,0.1,0.1);
		glutSolidCube(2.0);
	glPopMatrix();
	
	//MANIJA 2
	glPushMatrix();
		glColor3f( 0.686 , 0.647 , 0.580 );
		glTranslatef(-7.41,-12.58,8.5);
		glScalef(0.1,0.1,0.1);
		glutSolidCube(2.0);
	glPopMatrix();
	
	//LAVAVO
	glPushMatrix();
		glColor3f( 0.890 , 0.874 , 0.831 );
		glTranslatef(-6.98,-13.13,8.3);
		glScalef(0.7,0.7,0.1);
		glutSolidCube(2.0);
	glPopMatrix();
	
	glPushMatrix();
		glColor3f( 0.890 , 0.874 , 0.831 );
		glTranslatef(-7.02,-12.58,7.3);
		glScalef(0.15,0.15,0.9);
		glutSolidCube(2.0);
	glPopMatrix();
	
	glPushMatrix();
		glColor3f( 0.890 , 0.874 , 0.831 );
		glTranslatef(-7.02,-12.62,6.35);
		glScalef(0.4,0.4,0.05);
		glutSolidCube(2.0);
	glPopMatrix();
	
}

void DUCHA_BANIO(){
	//REGADERA
	glPushMatrix();
		glColor3f(0.6, 0.2, 0.2);
		glTranslatef(-11.15,-19.6,11.7);
		glScalef(0.1,0.1,0.1);
		glutSolidCube(2.0);
	glPopMatrix();
	
	glPushMatrix();
		glColor3f(0.6, 0.2, 0.2);
		glTranslatef(-11.357,-19.6,11.85);
		glScalef(0.3,0.1,0.05);
		glutSolidCube(2.0);
	glPopMatrix();
	
	glPushMatrix();
		glColor3f(0.6, 0.2, 0.2);
		glTranslatef(-11.55,-19.6,9.05);
		glScalef(0.1,0.1,2.750);
		glutSolidCube(2.0);
	glPopMatrix();
	
	//MANIJA DERECHA
	glPushMatrix();
		glColor3f(0.2, 0.2, 0.2);
		glTranslatef(-11.6,-19.35,9.13);
		glScalef(0.05,0.05,0.05);
		glutSolidCube(2.0);
	glPopMatrix();
	
	//MANIJA CENTRAL
	glPushMatrix();
		glColor3f(0.2, 0.2, 0.2);
		glTranslatef(-11.7,-19.6,9.13);
		glScalef(0.05,0.05,0.05);
		glutSolidCube(2.0);
	glPopMatrix();
	
	//MANIJA IZQUIERDA
	glPushMatrix();
		glColor3f(0.2, 0.2, 0.2);
		glTranslatef(-11.6,-19.85,9.13);
		glScalef(0.05,0.05,0.05);
		glutSolidCube(2.0);
	glPopMatrix();
	
	//DUCHA
	glPushMatrix();
		glColor3f(0.2, 0.1, 0.1);
		glTranslatef(-8.65,-21.12,7.9);
		glScalef(2.8,0.05,1.6);
		glutSolidCube(2.0);
	glPopMatrix();
	
	glPushMatrix();
		glColor3f(0.2, 0.1, 0.1);
		glTranslatef(-5.8,-19.47,7.9);
		glScalef(0.05,1.7,1.6);
		glutSolidCube(2.0);
	glPopMatrix();
	
	glPushMatrix();
		glColor3f(0.2, 0.1, 0.1);
		glTranslatef(-9.5,-17.82,7.9);
		glScalef(1.95,0.05,1.6);
		glutSolidCube(2.0);
	glPopMatrix();
	
	glPushMatrix();
		glColor3f(0.2, 0.1, 0.1);
		glTranslatef(-8.65,-19.47,6.35);
		glScalef(2.8,1.6,0.05);
		glutSolidCube(2.0);
	glPopMatrix();
	
	//PUERTA CORREDIZA
	glPushMatrix();
		glColor3f(0.2, 0.13, 0.13);
		glTranslatef(-9.25,-17.72,7.9);
		glScalef(1.95,0.05,1.6);
		glutSolidCube(2.0);
	glPopMatrix();

}

void COSAS_BANIO(){
	//CUADRO
	/*glPushMatrix();
		glColor3f(0.1, 0.1, 0.1);
		glTranslatef(-12.05,-19.6,11.7);
		glScalef(0.05,1.2,0.65);
		glutSolidCube(2.0);
	glPopMatrix();*/
	
	//TOALLERO
	glPushMatrix();
		glColor3f( 0.611 , 0.607 , 0.6 );
		glTranslatef(-9.8,-12.26,8.81);
		glScalef(0.4,0.05,0.05);
		glutSolidCube(2.0);
	glPopMatrix();
	
	glPushMatrix();
		glColor3f( 0.611 , 0.607 , 0.6 );
		glTranslatef(-9.35,-12.16,8.81);
		glScalef(0.05,0.150,0.05);
		glutSolidCube(2.0);
	glPopMatrix();
	
	glPushMatrix();
		glColor3f( 0.611 , 0.607 , 0.6);
		glTranslatef(-10.25,-12.16,8.81);
		glScalef(0.05,0.150,0.05);
		glutSolidCube(2.0);
	glPopMatrix();
	
	//ESPEJO
		//MARCO
	glPushMatrix();
		glColor3f( 0.611 , 0.607 , 0.6);
		glTranslatef(-6.97,-12.11,9.84);
		glScalef(0.850,0.1,0.8);
		glutSolidCube(2.0);
	glPopMatrix();
	
	glPushMatrix();
		glColor3f( 0.498 , 0.823 , 0.823 );
		glTranslatef(-6.97,-12.26,9.84);
		glScalef(0.7,0.05,0.65);
		glutSolidCube(2.0);
	glPopMatrix();
	
	//TAPETE
	glPushMatrix();
		glColor3f( 0.701 , 0.627 , 0.509 );
		glTranslatef(-4.1145,-14.808,6.35);
		glScalef(1.1,1.35,0.05);
		glutSolidCube(2.0);
	glPopMatrix();
}

void CuartoBanio(){
    glRotatef(270,1,0,0);
    glPushMatrix();
        PISO_BANIO();
        PAREDES_BANIO();
        WATER_BANIO();
        BASURERO_BANIO();
        LAVADERO_BANIO();
        //DUCHA_BANIO();
        COSAS_BANIO();
    glPopMatrix();
}

void cuarto(){
    glPushMatrix();
        glTranslatef(-1,-2.5,0);
        glScalef(-0.03,-0.03,-0.03);
        glRotatef(180,1,0,0);
        glRotatef(-90,0,1,0);
        silla();
    glPopMatrix();
}

//////////////FIN BANO///////////



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
		
		glColor3f( 0.545 , 0.454 , 0.337 );
		glTranslatef(0.90, -3.0, 0.5);
		glScalef(0.5, 0.48, 0.028);
		glutSolidCube(10);
		glColor3f(0.0f, 0.0f, 0.0f);
		LineaCubo(1);	
		glEnd ();	
		
		
		
		glPopMatrix();
		
		//////////////////////////////////////////////////////////////// *puerta/////////////////////////////////////////////////////////////////////////////////////
		glPushMatrix();
		
		glColor3f( 0.364 , 0.223 , 0.082 );
		glTranslatef(0.1, -1.5, 0.5);//moviemiento
		glScalef(0.1, 0.06, 0.028);
		glutSolidCube(10);
		glColor3f(0.0f, 0.0f, 0.0f);
		LineaCubo(8);	
		glEnd ();	
		
		glPopMatrix();
		
		//////////////////////////////////////////////////////////////// *puerta/////////////////////////////////////////////////////////////////////////////////////
		glPushMatrix();
		
		glColor3f( 0.364 , 0.223 , 0.082 );
		glTranslatef(0.1, -3.0, 0.5);//moviemiento
		glScalef(0.1, 0.09, 0.028);//figura
		glutSolidCube(10);
		glColor3f(0.0f, 0.0f, 0.0f);
		LineaCubo(8);	
		glEnd ();	
		
		glPopMatrix();		
		
		//////////////////////////////////////////////////////////////// *puerta/////////////////////////////////////////////////////////////////////////////////////
		glPushMatrix();
		
		glColor3f( 0.364 , 0.223 , 0.082 );
		glTranslatef(0.1, -4.5, 0.5);//moviemiento
		glScalef(0.1, 0.09, 0.028);//figura
		glutSolidCube(10);
		glColor3f(0.0f, 0.0f, 0.0f);
		LineaCubo(8);	
		glEnd ();	
		
		glPopMatrix();
		
		//////////////////////////////////////////////////////////////// *puerta/////////////////////////////////////////////////////////////////////////////////////
		glPushMatrix();
		
		glColor3f( 0.364 , 0.223 , 0.082 );
		glTranslatef(1.9, -1.5, 0.5);//moviemiento
		glScalef(0.1, 0.06, 0.028);
		glutSolidCube(10);
		glColor3f(0.0f, 0.0f, 0.0f);
		LineaCubo(8);	
		glEnd ();	
		
		glPopMatrix();
		
		//////////////////////////////////////////////////////////////// *puerta/////////////////////////////////////////////////////////////////////////////////////
		glPushMatrix();
		
		glColor3f( 0.364 , 0.223 , 0.082 );
		glTranslatef(1.9, -3.0, 0.5);//moviemiento
		glScalef(0.1, 0.09, 0.028);//figura
		glutSolidCube(10);
		glColor3f(0.0f, 0.0f, 0.0f);
		LineaCubo(8);	
		glEnd ();	
		
		glPopMatrix();
		
		//////////////////////////////////////////////////////////////// *puerta/////////////////////////////////////////////////////////////////////////////////////
		glPushMatrix();
		
		glColor3f( 0.364 , 0.223 , 0.082 );
		glTranslatef(1.9, -4.5, 0.5);//moviemiento
		glScalef(0.1, 0.09, 0.028);//figura
		glutSolidCube(10);
		glColor3f(0.0f, 0.0f, 0.0f);
		LineaCubo(8);	
		glEnd ();	
		
		glPopMatrix();
	
	glPopMatrix();
}














 

void caLateral()
{
	
	// Propiedades del material

// "Limpiamos" el frame buffer con el color de "Clear", en este color negro
// Aqu? va, verificarlo en el repintado
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
//(GL_FRONT, GL_AMBIENT, mat_ambient);
//(GL_FRONT, GL_DIFFUSE, mat_marron);
////(GL_FRONT, GL_SPECULAR, mat_specular);
//(GL_FRONT, GL_SHININESS, shine); 
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
//(GL_FRONT, GL_AMBIENT, mat_ambient);
//(GL_FRONT, GL_DIFFUSE, mat_plomo);

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
	//glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // Aqu? va, verificarlo en el repintado
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
			//(GL_FRONT, GL_AMBIENT, mat_ambient);
			//(GL_FRONT, GL_DIFFUSE, mat_plomo);
			////(GL_FRONT, GL_SPECULAR, mat_specular);
			//(GL_FRONT, GL_SHININESS, shine); 
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
			//(GL_FRONT, GL_DIFFUSE, mat_marron);
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
    glPushMatrix();
        glRotatef(90,0,1,0);
        glTranslatef(-2.2,-11.15,-17.1);
        CuartoBanio();
    glPopMatrix();

    glPushMatrix();
        glRotatef(-45,0,1,0);
        glTranslatef(posXPericote,0.0,0.0);
        DibujarPericote();
    glPopMatrix();
    glPushMatrix();
        glTranslatef(2.5, 4.0, -5.0);
        SillaGamer();
    glPopMatrix();
    glPushMatrix();
        glTranslatef(-1.0, 0.0, 0.03);
        Escritorio();
    glPopMatrix();
    glPushMatrix();
        TV();
    glPopMatrix();
	glFlush();
	glutSwapBuffers();	
}
 void moverPericote(){
    random = rand()%5;
    cout << random << endl;
    if(random == 2){
        RED1 = (double)rand() / (RAND_MAX + 1.0);
        GREEN1 = (double)rand() / (RAND_MAX + 1.0);
        BLUE1 = (double)rand() / (RAND_MAX + 1.0);
        RED2 = (double)rand() / (RAND_MAX + 1.0);
        GREEN2 = (double)rand() / (RAND_MAX + 1.0);
        BLUE2 = (double)rand() / (RAND_MAX + 1.0);
        RED3 = (double)rand() / (RAND_MAX + 1.0);
        GREEN3 = (double)rand() / (RAND_MAX + 1.0);
        BLUE3 = (double)rand() / (RAND_MAX + 1.0);
        RED4 = (double)rand() / (RAND_MAX + 1.0);
        GREEN4 = (double)rand() / (RAND_MAX + 1.0);
        BLUE4 = (double)rand() / (RAND_MAX + 1.0);
    }
    
    
    if(posXPericote > -7.0){

        posXPericote -= 0.02;
    }
    else{
        posXPericote = 6.0;
    }
    
    
 }
 void idleFunc(){
    moverPericote();
    glutPostRedisplay();
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
    glutIdleFunc(idleFunc);
	glutKeyboardFunc(manejarTeclado);
	glutSpecialFunc(specialKeys);
	
	glutMainLoop();
	return 0;
}