#include <stdio.h>
#include <math.h>
#include <GL/freeglut.h>
#include <iostream>

using namespace std;

void specialKeys();
// Variables globales

double rotate_y=0;
double rotate_x=0;

float x=30,y=30,z=50;

GLUquadricObj *obj;

float posclax1, posclay1;

float radio=5,calx,caly;

void prender_luz(){

const GLfloat light_ambient[]  = { 0.0f, 0.0f, 0.0f, 1.0f };
        const GLfloat light_diffuse[]  = { 0.5, 0.5, 0.5, 1.0 };
        const GLfloat light_specular[] = { 1, 1, 1, 1 };
        const GLfloat light_position[] = { x, y, z, 1 };

        const GLfloat mat_ambient[]    = { 0.7f, 0.7f, 0.7f, 1.0f };
        const GLfloat mat_diffuse[]    = { 0.8f, 0.8f, 0.8f, 1.0f };
        const GLfloat mat_specular[]   = { 1.0f, 1.0f, 1.0f, 1.0f };
        const GLfloat high_shininess[] = { 100.0f };

        glEnable(GL_LIGHT1);
        glEnable(GL_NORMALIZE);
        glEnable(GL_COLOR_MATERIAL);
        glEnable(GL_LIGHTING);

        glLightfv(GL_LIGHT1, GL_AMBIENT,  light_ambient);
        glLightfv(GL_LIGHT1, GL_DIFFUSE,  light_diffuse);
        glLightfv(GL_LIGHT1, GL_SPECULAR, light_specular);
        glLightfv(GL_LIGHT1, GL_POSITION, light_position);

        glMaterialfv(GL_FRONT, GL_AMBIENT,   mat_ambient);
        glMaterialfv(GL_FRONT, GL_DIFFUSE,   mat_diffuse);
        glMaterialfv(GL_FRONT, GL_SPECULAR,  mat_specular);
        glMaterialfv(GL_FRONT, GL_SHININESS, high_shininess);
}













void mapa(){
	
	//PISO
	glPushMatrix ();
    glTranslatef(0.0,-30,3.0);  
	glScalef(55.0,3.0,58.0);
    glColor3f(0.498f, 0.451f,0.549f);
	glutSolidCube (2);
    glPopMatrix ();
    
    //PARED DERECHA
    glPushMatrix ();
    glTranslatef(58.0,18.0,3.0);  
	glScalef(3.0,51.0,58.0);
    glColor3f(0.6588f, 0.5608f,0.5412f);
	glutSolidCube (2);
    glPopMatrix ();
    
    
    //PARED IZQUIERDA
    glPushMatrix ();
    glTranslatef(3.0,18.0,-58.0);  
	glScalef(58.0,51.0,3.0);
	//glRotatef(45.0,0.0,1.0,0.0 );
    glColor3f(0.5922f, 0.498f,0.5922f);
	glutSolidCube (2);
    glPopMatrix ();
    
}

void caja(){
	
	//LADO FRONTAL CELESTE
	glBegin(GL_POLYGON);
	glColor3f(0.1804,0.1961,0.6941); // color de la cara o tapa
	glVertex3f( 2.5, -2.5, 2.5 );
	glVertex3f( 2.5, 2.5, 2.5 );
	glVertex3f( -2.5, 2.5, 2.5 );
	glVertex3f( -2.5, -2.5, 2.5 );
	glEnd();	
	// LADO TRASERO AMARILLO
	glBegin(GL_POLYGON);
	glColor3f(0.1804,0.1961,0.6941);
	glVertex3f( 2.5, -2.5, -2.5 ); 
	glVertex3f( 2.5, 2.5, -2.5 ); 
	glVertex3f( -2.5, 2.5, -2.5 ); 
	glVertex3f( -2.5, -2.5, -2.5 ); 
	glEnd();
	// LADO DERECHO NARANJA
	glBegin(GL_POLYGON);
	glColor3f(0.149,0.1765,0.6353); // color de la cara o tapa
	glVertex3f( 2.5, -2.5, -2.5 );
	glVertex3f( 2.5, 2.5, -2.5 );
	glVertex3f( 2.5, 2.5, 2.5 );
	glVertex3f( 2.5, -2.5, 2.5 );
	glEnd();	
	// LADO IZQUIERDO PLOMO
	glBegin(GL_POLYGON);
	glColor3f(0.149,0.1765,0.6353); // color de la cara o tapa
	glVertex3f( -2.5, -2.5, 2.5 );
	glVertex3f( -2.5, 2.5, 2.5 );
	glVertex3f( -2.5, 2.5, -2.5 );
	glVertex3f( -2.5, -2.5, -2.5 );
	glEnd();	
	// LADO SUPERIOR VERDE LIMON
	glBegin(GL_POLYGON);
	glColor3f(0.1804,0.1373,0.5922); // color de la cara o tapa
	glVertex3f( 2.5, 2.5, 2.5 );
	glVertex3f( 2.5, 2.5, -2.5 );
	glVertex3f( -2.5, 2.5, -2.5 );
	glVertex3f( -2.5, 2.5, 2.5 );
	glEnd();		
	// LADO INFERIOR ROJO
	glBegin(GL_POLYGON);
	glColor3f(0.1804,0.1961,0.6941); // color de la cara o tapa
	glVertex3f( 2.5, -2.5, -2.5 );
	glVertex3f( 2.5, -2.5, 2.5 );
	glVertex3f( -2.5, -2.5, 2.5 );
	glVertex3f( -2.5, -2.5, -2.5 );
	glEnd();	
	//TAPA 1
	glBegin(GL_POLYGON);
	glColor3f( 0.5765,0.4157,0.7765); 
	glVertex3f( 2.5, 2.5, 2.5 );
	glVertex3f( -2.5, 2.5, 2.5 );
	glVertex3f( -2.5, 4.0, 1.0 );
	glVertex3f( 2.5, 4.0, 1.0 );
	glEnd();	
	//TAPA 2
	glBegin(GL_POLYGON);
	glColor3f( 0.5176,0.4784,0.7961);  // color de la cara o tapa
	glVertex3f( -4.0, 0.5, 2.5 );
	glVertex3f( -2.5, 2.5, 2.5 );
	glVertex3f( -2.5, 2.5, -2.5 );
	glVertex3f( -4.0, 0.5, -2.5 );
	glEnd();	
	//TAPA 3
	glBegin(GL_POLYGON);
	glColor3f( 0.2392,0.2078,0.6471);  // color de la cara o tapa
	glVertex3f( 2.5, 2.5, -2.5 );
	glVertex3f( -2.5, 2.5, -2.5 );
	glVertex3f( -2.5, 4.5, 0.0 );
	glVertex3f( 2.5, 4.5, 0.0 );
	glEnd();	
	//TAPA 4
	glBegin(GL_POLYGON);
	glColor3f( 0.3255,0.2706,0.5843);  // color de la cara o tapa
	glVertex3f( 4.0, 0.5, -2.5 );
	glVertex3f( 2.5, 2.5, -2.5 );
	glVertex3f( 2.5, 2.5, 2.5 );
	glVertex3f( 4.0, 0.5, 2.5 );
	glEnd();	
}

void cajones(){
//	glDisable (GL_LIGHTING);
	//proyeccion del frente
	glPushMatrix(); 
	glTranslatef(97,0,-131);	
	//mesa del frente
	glPushMatrix(); 
		glTranslatef(13.5,8.0,-20.5);	
		glRotatef(-55,0,-30,00);		
        glScalef(53,3,125);
	    glColor3f(1.0f, 1.0f, 1.0f);
        glutSolidCube(1);
	glPopMatrix();
	
	//cajon del frente
	glPushMatrix(); 
		glTranslatef(13.5,-18.0,-20.5);		
		glRotatef(-55,0,-30,00);		
        glScalef(47.5,50,120);
	    glColor3f(0.549,0.549,0.549);
        glutSolidCube(1);
	glPopMatrix();
	
	//cajones del frente
	glPushMatrix();
	glTranslatef(-3,0,-1);
		glPushMatrix(); 
			glTranslatef(5.5,-18.0,4.5);		
			glRotatef(-55,0,-30,00);		
	        glScalef(3,50,30);        
		    glColor3f(1, 0.902, 0.902);
	        glutSolidCube(1);
	glPopMatrix();
	
	glPushMatrix(); 
			glTranslatef(32,-18.0,23);		
			glRotatef(-55,0,-30,00);		
	        glScalef(3,50,30);        
		    glColor3f(1, 0.902, 0.902);
	        glutSolidCube(1);
	glPopMatrix();
	
	glPushMatrix(); 
			//manija1
			glPushMatrix(); 
				glTranslatef(22,4,19);	
				glRotatef(-55,0,-30,00);		        
				glColor3f(0.902, 0.902,0.902);
				glutSolidSphere(2,20,10);
			glPopMatrix();
			//manija2
			glPushMatrix(); 
				glTranslatef(14,4,13);		
				glRotatef(-55,0,-30,00);		        
				glColor3f(0.902, 0.902,0.902);
				glutSolidSphere(2,20,10);
			glPopMatrix();
		glPopMatrix();
	glPopMatrix();
	glPopMatrix();
	//mitad
	//mesa del medio
	glPushMatrix(); 
		glTranslatef(43.5,8.0,-129.5);	
		glRotatef(-55,0,-30,00);		
        glScalef(164,3,50);        
	    glColor3f(1.0f, 1.0f, 1.0f);
        glutSolidCube(1);
	glPopMatrix();
	//cajones-segundo par
	glPushMatrix();
	glTranslatef(32,0,-46);	
	glPushMatrix(); 
		glTranslatef(24.0,-18.0,-61.73);	
		glRotatef(-55,0,-30,00);		
        glScalef(25,50,3);
	    glColor3f(1, 0.902, 0.902);
        glutSolidCube(1);
	glPopMatrix();
	//manija1
	glPushMatrix(); 
		glTranslatef(37.5,3,-75.4);	
		glRotatef(-55,0,-30,00);		        
		glColor3f(0.902, 0.902,0.902);
		glutSolidSphere(2,20,10);
	glPopMatrix();
	//manija2
	glPushMatrix(); 
		glTranslatef(31.0,3,-67.4);	
		glRotatef(-55,0,-30,00);		        
		glColor3f(0.902, 0.902,0.902);
		glutSolidSphere(2,20,10);
	glPopMatrix();
	glPushMatrix(); 
		glTranslatef(40.0,-18.0,-83.73);	
		glRotatef(-55,0,-30,00);		
        glScalef(25,50,3);
	    glColor3f(1, 0.902, 0.902);
        glutSolidCube(1);
	glPopMatrix();
	glPopMatrix();
	//cajones-primer par
	glPushMatrix(); 
		glTranslatef(24.0,-18.0,-61.73);	
		glRotatef(-55,0,-30,00);		
        glScalef(25,50,3);
	    glColor3f(1, 0.902, 0.902);
        glutSolidCube(1);
	glPopMatrix();
	
	//manija1
	glPushMatrix(); 
		glTranslatef(37.5,3,-75.4);	
		glRotatef(-55,0,-30,00);		        
		glColor3f(0.902, 0.902,0.902);
		glutSolidSphere(2,20,10);
	glPopMatrix();
	
	//manija2
	glPushMatrix(); 
		glTranslatef(31.0,3,-67.4);	
		glRotatef(-55,0,-30,00);		        
		glColor3f(0.902, 0.902,0.902);
		glutSolidSphere(2,20,10);
	glPopMatrix();
	
	glPushMatrix(); 
		glTranslatef(40.0,-18.0,-83.73);	
		glRotatef(-55,0,-30,00);		
        glScalef(25,50,3);
	    glColor3f(1, 0.902, 0.902);
        glutSolidCube(1);
	glPopMatrix();
	//Caja izquierda
	glPushMatrix(); 
		glTranslatef(18.2,-18.0,-89);	
		glRotatef(-55,0,-30,00);		
        glScalef(160,50,40);
	    glColor3f(0.549,0.549,0.549);
        glutSolidCube(1);
	glPopMatrix();
	//Mesa derecha
	glPushMatrix(); 
		glTranslatef(13.5,8.0,-20.5);	
		glRotatef(-55,0,-30,00);		
        glScalef(50,3,125);
	    glColor3f(1.0f, 1.0f, 1.0f);
        glutSolidCube(1);
	glPopMatrix();
	//Mesa derecha abajo
	glPushMatrix(); 
		glTranslatef(30,4.0,-6.5);	
		glRotatef(-55,0,-30,00);		
        glScalef(41.8,10,73);
	    glColor3f(1, 0.902, 0.902);
        glutSolidCube(1);
	glPopMatrix();
	//Patas mesa derecha abajo
	glPushMatrix(); 
		glTranslatef(54.5,-18.0,-9.5);	
		glRotatef(-55,0,-30,00);		
        glScalef(8.5,50,8.5);
	    glColor3f(1, 0.902, 0.902);
        glutSolidCube(1);
	glPopMatrix();
	
	glPushMatrix(); 
		glTranslatef(35.3,-18.0,17.5);	
		glRotatef(-55,0,-30,00);		
        glScalef(8.5,50,8.5);
	    glColor3f(1, 0.902, 0.902);
        glutSolidCube(1);
	glPopMatrix();
	
	glPushMatrix(); 
		glTranslatef(45.3,-25.0,4.5);	
		glRotatef(-55,0,-30,00);		
        glScalef(40,5,5);
	    glColor3f(1, 0.902, 0.902);
        glutSolidCube(1);
	glPopMatrix();
	

}

void cuadro(){
			
	//LADO FRONTAL 
	glBegin(GL_POLYGON);
	glColor3f(0.851,0.7608,0.7294); // color de la cara o tapa
	glVertex3f( 4.8, -2.35, 0.45 );
	glVertex3f( 4.8, 2.35, 0.45);
	glVertex3f( -4.8, 2.35, 0.45 );
	glVertex3f( -4.8, -2.35, 0.45 );
	glEnd();
	
	// LADO TRASERO 
	glBegin(GL_POLYGON);
	glColor3f(0.7647,0.5255,0.3804);
	glVertex3f( 5.0, -2.5, 0.3 ); 
	glVertex3f( 5.0, 2.5, -0.3 ); 
	glVertex3f( -5.0, 2.5, -0.3 ); 
	glVertex3f( -5.0, -2.5, -0.3 ); 
	glEnd();
		
	// LADO DERECHO 
	glBegin(GL_POLYGON);
	glColor3f(0.7647,0.5255,0.3804); // color de la cara o tapa
	glVertex3f( 5.0, -2.5, -0.3 );
	glVertex3f( 5.0, 2.5, -0.3 );
	glVertex3f( 5.0, 2.5, 0.3 );
	glVertex3f( 5.0, -2.5, 0.3 );
	glEnd();
	
	// LADO IZQUIERDO
	glBegin(GL_POLYGON);
	glColor3f(0.898,0.8078,0.7608); // color de la cara o tapa
	glVertex3f( -5.0, -2.5, 0.3 );
	glVertex3f( -5.0, 2.5, 0.3 );
	glVertex3f( -5.0, 2.5, -0.3 );
	glVertex3f( -5.0, -2.5, -0.3 );
	glEnd();
	
	// LADO SUPERIOR MORADO
	glBegin(GL_POLYGON);
	glColor3f(0.4078,0.2431,0.4196); // color de la cara o tapa
	glVertex3f( 5.0, 2.5, 0.3 );
	glVertex3f( 5.0, 2.5, -0.3 );
	glVertex3f( -5.0, 2.5, -0.3 );
	glVertex3f( -5.0, 2.5, 0.3 );
	glEnd();
		
	// LADO INFERIOR 
	glBegin(GL_POLYGON);
	glColor3f(0.7647,0.5255,0.3804); // color de la cara o tapa
	glVertex3f( 5.0, -2.5, -0.3 );
	glVertex3f( 5.0, -2.5, 0.3 );
	glVertex3f( -5.0, -2.5, 0.3 );
	glVertex3f( -5.0, -2.5, -0.3 );
	glEnd();	
}

void borde(){
			
	//LADO FRONTAL 
	glBegin(GL_POLYGON);
	glColor3f(0.898,0.8078,0.7608); // color de la cara o tapa
	glVertex3f( 5.0, -2.5, 0.4 );
	glVertex3f( 5.0, 2.5, 0.4 );
	glVertex3f( -5.0, 2.5, 0.4 );
	glVertex3f( -5.0, -2.5, 0.4 );
	glEnd();
	
}

void papeles_cuadro(){
	
	//PAPEL 1
	glBegin(GL_POLYGON);
	glColor3f(0.9137,0.8706,0.831 ); // color de la cara o tapa
	glVertex3f( 0.5, -1.0, 0.6 );
	glVertex3f( 0.5, 1.0, 0.6 );
	glVertex3f( -1.0, 1.0, 0.6 );
	glVertex3f( -1.0, -1.0, 0.6 );
	glEnd();
	
	//PAPEL 2
	glBegin(GL_POLYGON);
	glColor3f(0.9137,0.8706,0.831 ); // color de la cara o tapa
	glVertex3f( -2.0, -0.5, 0.6 );
	glVertex3f( -2.0, 1.5, 0.6 );
	glVertex3f( -3.5, 1.5, 0.6 );
	glVertex3f( -3.5, -0.5, 0.6 );
	glEnd();
	
	//PAPEL 3
	glBegin(GL_POLYGON);
	glColor3f(0.9137,0.8706,0.831 ); // color de la cara o tapa
	glVertex3f( 2.5, -1.0, 0.6 );
	glVertex3f( 2.5, 1.0, 0.6 );
	glVertex3f( 4.0, 1.0, 0.6 );
	glVertex3f( 4.0, -1.0, 0.6 );
	glEnd();
	
	//PAPEL 4
	glBegin(GL_POLYGON);
	glColor3f(0.9137,0.8706,0.831 ); // color de la cara o tapa
	glVertex3f( -2.9,1.0, 0.65);
	glVertex3f( -2.9, 2.0, 0.65);
	glVertex3f( -3.8, 2.0, 0.65);
	glVertex3f( -3.8, 1.0, 0.65);
	glEnd();
	
	//PAPEL 5
	glBegin(GL_POLYGON);
	glColor3f(0.9137,0.8706,0.831 ); // color de la cara o tapa
	glVertex3f( 2.0, -1.0, 0.7);
	glVertex3f( 2.0, 0.0, 0.7);
	glVertex3f( 2.8, 0.0, 0.7);
	glVertex3f( 2.8, -1.0, 0.7);
	glEnd();
	
	//PAPEL 6
	glBegin(GL_POLYGON);
	glColor3f(0.9137,0.8706,0.831 ); // color de la cara o tapa
	glVertex3f( 3.8, 1.2, 0.7);
	glVertex3f( 3.8, 2.3, 0.7);
	glVertex3f( 4.6, 2.3, 0.7);
	glVertex3f( 4.6, 1.2, 0.7);
	glEnd();
	
	//PAPEL 7
	glBegin(GL_POLYGON);
	glColor3f(0.9137,0.8706,0.831 ); // color de la cara o tapa
	glVertex3f( 1.8, 0.8, 0.65);
	glVertex3f( 1.8, 2.3, 0.65);
	glVertex3f( 3.3, 2.3, 0.65);
	glVertex3f( 3.3, 0.8, 0.65);
	glEnd();
	
	//PAPEL 8
	glBegin(GL_POLYGON);
	glColor3f(0.9137,0.8706,0.831 ); // color de la cara o tapa
	glVertex3f( 0.6, 1.3, 0.6 );
	glVertex3f( 0.6, 2.3, 0.6 );
	glVertex3f( -0.8, 2.3, 0.6 );
	glVertex3f( -0.8, 1.3, 0.6 );
	glEnd();
}

void bola(){

	glPushMatrix();
		glBegin(GL_POLYGON);
		glColor4f(1.0,0.0,0.0,0.0f);
		for(double i=0;i<10;i+=0.01){
			calx= radio+cos(i);
			caly= radio+sin(i);
			glVertex2f(calx,caly);
		}
		glEnd();
	glPopMatrix();
}

void lineas(){
	
	// BOLA 1 - BOLA 6
	glPushMatrix();
		glBegin(GL_LINE_STRIP);
		glColor3f(0.0f, 0.0f, 0.0f);
		glVertex3f(-0.5,0.5,0.7);
		glVertex3f(3.3,0.2,0.65);
		glEnd();
	glPopMatrix();
	
	// BOLA 2 - BOLA 3
	glPushMatrix();
		glBegin(GL_LINE_STRIP);
		glColor3f(0.0f, 0.0f, 0.0f);
		glVertex3f(0.0,1.8,0.7);
		glVertex3f(1.9,1.4,0.7);
		glEnd();
	glPopMatrix();
	
	// BOLA 3 - BOLA 6
	glPushMatrix();
		glBegin(GL_LINE_STRIP);
		glColor3f(0.0f, 0.0f, 0.0f);
		glVertex3f(2.2,1.3,0.7);
		glVertex3f(3.4,0.3,0.65);
		glEnd();
	glPopMatrix();
	
	// BOLA 4 - BOLA 6
	glPushMatrix();
		glBegin(GL_LINE_STRIP);
		glColor3f(0.0f, 0.0f, 0.0f);
		glVertex3f(2.9,1.82,0.75);
		glVertex3f(3.5,0.35,0.65);
		glEnd();
	glPopMatrix();
	
	// BOLA 5 - BOLA 6
	glPushMatrix();
		glBegin(GL_LINE_STRIP);
		glColor3f(0.0f, 0.0f, 0.0f);
		glVertex3f(4.25,1.7,0.75);
		glVertex3f(3.6,0.35,0.65);
		glEnd();
	glPopMatrix();
	
	// BOLA 6 - BOLA 7
	glPushMatrix();
		glBegin(GL_LINE_STRIP);
		glColor3f(0.0f, 0.0f, 0.0f);
		glVertex3f(3.45,0.0,0.75);
		glVertex3f(2.5,-0.45,0.75);
		glEnd();
	glPopMatrix();	
}

void bolitas(){
	
	//BOLA 1
	glPushMatrix();
	glTranslatef(-1.65,-0.5,0.7);
	glScalef(0.2,0.2,0.2);
	bola();
	glPopMatrix();
	
	//BOLA 2
	glPushMatrix();
	glTranslatef(-1.15,0.8,0.7);
	glScalef(0.2,0.2,0.2);
	bola();
	glPopMatrix();
	
	//BOLA 3
	glPushMatrix();
	glTranslatef(1.1,0.4,0.7);
	glScalef(0.2,0.2,0.2);
	bola();
	glPopMatrix();
	
	//BOLA 4
	glPushMatrix();
	glTranslatef(1.8,1.0,0.7);
	glScalef(0.2,0.2,0.2);
	bola();
	glPopMatrix();
	
	//BOLA 5
	glPushMatrix();
	glTranslatef(3.3,0.9,0.75);
	glScalef(0.2,0.2,0.2);
	bola();
	glPopMatrix();
	
	//BOLA 6
	glPushMatrix();
	glTranslatef(2.5,-0.8,0.65);
	glScalef(0.2,0.2,0.2);
	bola();
	glPopMatrix();
	
	//BOLA 7
	glPushMatrix();
	glTranslatef(1.4,-1.5,0.75);
	glScalef(0.2,0.2,0.2);
	bola();
	glPopMatrix();
	
	//LINEAS
	glPushMatrix();
	lineas();
	glPopMatrix();
	
	borde();
}

void  caja1(){

	//Radio
    glPushMatrix ();
       glTranslatef(-2.0,1.0,4.7);
       glScalef(3,0.5,1);
       glColor3f(0.7176f, 0.7725f, 0.749f);
	   glutSolidCube (1);
    glPopMatrix ();	 
    
    glPushMatrix ();
       glTranslatef(-2.8,0.0,5.1);
       glScalef(1.5,1,0);
       glColor3f(0.7176f, 0.7725f, 0.749f);
	   glutSolidCube (1);
    glPopMatrix ();	
    
    glPushMatrix ();
       glTranslatef(0,2.1,0);
       glScalef(8.5,0.3,10.5);
       glColor3f(0.4902f,0.5961f, 0.5176f);
	   glutSolidCube (1);
    glPopMatrix ();	
    
    glPushMatrix ();
       glTranslatef(2.8,0.5,5.05);
       glScalef(1,1,1);
       glRotatef (180.0f, 180.0f, 180.0f, 0.0f);
       glColor3f(0.7176f, 0.7725f, 0.749f);
	   glutSolidCone (1,2,20,1);
    glPopMatrix ();
    
	 glPushMatrix ();
       glTranslatef(0.0,0.0,0.0);
       glScalef(8,4,10);
       glColor3f(0.5647f, 0.6157f, 0.5961f);
	   glutSolidCube (1);
    glPopMatrix ();	
}

void cajon2(){
	
    //Radio 2
    glPushMatrix ();
       glTranslatef(0.0,0.0,0.0);
       glScalef(10,6,10);
       glColor3f(0.9059f, 0.7529f, 0.5843f);
	   glutSolidCube (1);
    glPopMatrix ();
    
     glPushMatrix ();
       glTranslatef(1.5,0.,5.1);
       glScalef(1,1,1);
       glRotatef (180.0f, 180.0f, 180.0f, 0.0f);
       glColor3f(0.4588f, 0.3882f, 0.302f);;
	   glutSolidCone (1.5,2,20,1);
    glPopMatrix ();
 	
 	 glPushMatrix ();
       glTranslatef(-3.25,-2.3,4.52);
       glScalef(3.48,0.5,1);
       glColor3f(0.7725f, 0.5451f, 0.4196f);
	   glutSolidCube (1);
    glPopMatrix ();
	
	 glPushMatrix ();
       glTranslatef(0,3,0);
       glScalef(10.5,0.3,10.5);
       glColor3f(0.7176f, 0.9176f, 0.7255f);
	   glutSolidCube (1);
    glPopMatrix ();	   
}

void cajon(){
	//estante 1
    
	glPushMatrix ();
       glTranslatef(0.0,-0.25,0.0);
       glScalef(8,8.5,10);
       glColor3f(0.5804f, 0.5647f, 0.5882f);
	   glutSolidCube (1);
    glPopMatrix ();
    //Cajon 1
    glPushMatrix ();
       glTranslatef(0,3.7,4.55);
       glScalef(2,0.4,1);
       glColor3f(0, 0, 0);;
	   glutSolidCube (1);
    glPopMatrix ();
    
    glPushMatrix ();
       glTranslatef(0,2.9,0.1499);
       glScalef(7.5,2,9.8);
       glColor3f(0.7804f, 0.7686f, 0.7882f);
	   glutSolidCube (1);
    glPopMatrix ();
    
    //Cajon 2
    glPushMatrix ();
       glTranslatef(0,1.6,4.55);
       glScalef(2,0.4,1);
       glColor3f(0, 0, 0);
	   glutSolidCube (1);
    glPopMatrix ();
    
    glPushMatrix ();
       glTranslatef(0,0.8,0.1499);
       glScalef(7.5,2,9.8);
       glColor3f(0.7804f, 0.7686f, 0.7882f);
	   glutSolidCube (1);
    glPopMatrix ();
    
    
    //Cajon 3
    glPushMatrix ();
       glTranslatef(0,-0.5,4.55);
       glScalef(2,0.4,1);
       glColor3f(0, 0, 0);
	   glutSolidCube (1);
    glPopMatrix ();
    
    glPushMatrix ();
       glTranslatef(0,-1.3,0.1499);
       glScalef(7.5,2,9.8);
       glColor3f(0.7804f, 0.7686f, 0.7882f);
	   glutSolidCube (1);
    glPopMatrix ();
      
    //Cajon 4
    glPushMatrix ();
    glPushMatrix ();
       glTranslatef(0,-2.6,4.55);
       glScalef(2,0.4,1);
       glColor3f(0, 0, 0);
	   glutSolidCube (1);
    glPopMatrix ();
    
       glTranslatef(0,-3.4,0.149);
       glScalef(7.5,2,9.8);
       glColor3f(0.7804f, 0.7686f, 0.7882f);
	  glutSolidCube (1);
    glPopMatrix ();

}

void cajonx1(){

   	glPushMatrix ();
       glTranslatef(0.0,-0.5,0.0);
       glScalef(7.8,2.5,5);
       glColor3f(0.6863f, 0.7686f, 0.6941f);
       glutSolidCube (1);
	  // glutSolidCube (1);
    glPopMatrix ();
}

void cajonx2(){
	
	//estante 
    glPushMatrix ();
       glTranslatef(-3,0.3,2.6);
       glScalef(0.6,0.6,1);
       glRotatef (180.0f, 180.0f, 180.0f, 0.0f);
       glColor3f(0.851f, 0.8902f, 0.8471f);
	   glutSolidCone (0.3,2,10,1);
    glPopMatrix ();
    
    glPushMatrix ();
       glTranslatef(-3,0.3,1.53);
       glScalef(1.8,1,2);
       glColor3f(0.7843f, 0.7922f, 0.7451f);
       glutSolidCube (1);
    glPopMatrix ();
      
}

void cajaSup(){
	   glPushMatrix ();
       glTranslatef(-2.3,1.455,0.9);
       glRotatef (-15.0f, 0.0f, 1.0f, 0.0f);
       glScalef(1.8,1,2);
       glColor3f(1.0f, 1.0f, 0.9961f);
       glutSolidCube (1);
    glPopMatrix ();
}

void BolaSup(){
	glPushMatrix ();
    glTranslatef(2.8,1.255,1.5);
	glColor3f(1.0f, 0.0f, 0.0f);
	glutSolidSphere(0.3,20,6);
	glPopMatrix ();
}

void CajaTodo(){
	
	glPushMatrix();
	glTranslatef(-0.15,0.2,0);
	cajonx1();
	glPopMatrix();
	
	cajonx2();
	
	glPushMatrix();
	glTranslatef(0,-1.2,0);
	cajonx2();
	glPopMatrix();
		
	glPushMatrix();
	glTranslatef(1.9,0,0);
	cajonx2();
	glPopMatrix();
	
	glPushMatrix();
	glTranslatef(1.9,-1.2,0);
	cajonx2();
	glPopMatrix();
	
	glPushMatrix();
	glTranslatef(3.8,0,0);
	cajonx2();
	glPopMatrix();
	
	glPushMatrix();
	glTranslatef(3.8,-1.2,0);
	cajonx2();
	glPopMatrix();
	
	glPushMatrix();
	glTranslatef(5.7,0,0);
	cajonx2();
	glPopMatrix();
	
	glPushMatrix();
	glTranslatef(5.7,-1.2,0);
	cajonx2();
	glPopMatrix();
	
	cajaSup();
	BolaSup();
	
}

void patasLavadora(){
	//parte superior
	glBegin(GL_POLYGON);
	glColor3f(0.9255f, 0.8235f, 0.7255f);
	glVertex3d(12.5,-15,12.5);
	glVertex3d(12.5,-15,10);
	glVertex3d(9,-15,10);
	glVertex3d(9,-15,12.5);
	glEnd();
	
	
	//parte inferior	
	glBegin(GL_POLYGON);
	glColor3f(0.9255f, 0.8235f, 0.7255f);
	glVertex3d(12.5,-18,10);
	glVertex3d(12.5,-18,12.5);
	glVertex3d(11,-18,12.5);
	glVertex3d(11,-18,10);
	glEnd();
		
	//cara 1
	glBegin(GL_POLYGON);
	glColor3f(0.9255f, 0.8235f, 0.7255f);
	glVertex3d(12.5,-15,12.5);
	glVertex3d(12.5,-15,10);
	glVertex3d(12.5,-18,10);
	glVertex3d(12.5,-18,12.5);
	glEnd();
		
	//cara 2
	glBegin(GL_POLYGON);
	glColor3f(0.9255f, 0.8235f, 0.7255f);
	glVertex3d(12.5,-15,12.5);
	glVertex3d(12.5,-18,12.5);
	glVertex3d(11,-18,12.5);
	glVertex3d(9,-15,12.5);
	glEnd();
	
	//cara 3
	glBegin(GL_POLYGON);
	glColor3f(0.9255f, 0.8235f, 0.7255f);
	glVertex3d(12.5,-15,10);
	glVertex3d(12.5,-18,10);
	glVertex3d(11,-18,10);
	glVertex3d(9,-15,10);
	glEnd();
	
	
	//cara 4
	glBegin(GL_POLYGON);
	glColor3f(0.9255f, 0.8235f, 0.7255f);
	glVertex3d(11,-18,12.5);
	glVertex3d(11,-18,10);
	glVertex3d(9,-15,10);
	glVertex3d(9,-15,12.5);
	glEnd();
}

void BotonCilindro(double radio, double altura){
	
	obj = gluNewQuadric();
    	gluQuadricDrawStyle(obj, GLU_FILL);
    	gluQuadricNormals(obj, GLU_SMOOTH);
    	glPushMatrix ();
     //  glTranslatef(0.0,-10.0,-25);
     
     	//glRotatef(90,0,0,1);
      //	glScalef(1,1,1);
     	// glColor3f(1.0f, 0.0f, 0.0f);
     	glColor3f(0.9255f, 0.8235f, 0.7255f);
	  //gluCylinder(obj,0.1f,0.1f,3.0f,32,32);
	  
	  	gluCylinder ( obj,radio, radio,altura , 50, 5);
   		glPopMatrix ();		
}

void circuloTapaBoton(double rad){
	
	glBegin(GL_POLYGON);
glColor3f(0.9255f, 0.8235f, 0.7255f);
	for(double i=0.0; i<10; i+=0.001){
		posclax1 = rad*cos(i);
		posclay1= rad*sin(i);
		
		glVertex3f(posclax1,0,posclay1);
	}
	
	glEnd();			
}

void lavadora(){
	
	//Cuerpo lavadora    glColor3f(0.9255f, 0.8235f, 0.7255f);
	glBegin(GL_POLYGON);
	glColor3f(0.9255f, 0.8235f, 0.7255f);
	glVertex3d(12.5,15,-12.5);
	glVertex3d(12.5,21,-12.5);
	glVertex3d(12.5,21,-11.5);
	glVertex3d(12.5,15,-5.5);
	glEnd();
	
	glBegin(GL_POLYGON);
	glColor3f(0.9255f, 0.8235f, 0.7255f);
	glVertex3d(-12.5,15,-12.5);
	glVertex3d(-12.5,21,-12.5);
	glVertex3d(-12.5,21,-11.5);
	glVertex3d(-12.5,15,-5.5);
	glEnd();
	
	glBegin(GL_POLYGON);
	glColor3f(0.9255f, 0.8235f, 0.7255f);
	glVertex3d(-12.5,15,-5.5);
	glVertex3d(-12.5,21,-11.5);
	glVertex3d(12.5,21,-11.5);
	glVertex3d(12.5,15,-5.5);
	glEnd();
	
	glPushMatrix();
	glColor3f(0.9255f, 0.8235f, 0.7255f);
	glTranslatef(0, 0, 0);
	glScalef(25,30,25);
	glutSolidCube(1);
	glPopMatrix();
	
	glPushMatrix();
	glColor3f(0.9255f, 0.8235f, 0.7255f);
	glTranslatef(0, 18, -12);
	glScalef(25,6,1);
	glutSolidCube(1);
	glPopMatrix();
		
	
	//Botones
	
	glPushMatrix();
	glColor3f(0.7804f, 0.6941f, 0.7098f);
	glTranslatef(5, 18.3, -9.3);
	glRotatef(-45,1,0,0);
	glScalef(1.7,1.7,2);
	glutSolidCube(1);
	glPopMatrix();
	
	glPushMatrix();
	glColor3f(0.7804f, 0.6941f, 0.7098f);
	glTranslatef(8, 18.3, -9.3);
	glRotatef(-45,1,0,0);
	glScalef(1.7,1.7,2);
	glutSolidCube(1);
	glPopMatrix();
	
	glPushMatrix();
	glColor3f(0.7804f, 0.6941f, 0.7098f);
	glTranslatef(5, 16.3, -7.3);
	glRotatef(-45,1,0,0);
	glScalef(1.7,1.7,2);
	glutSolidCube(1);
	glPopMatrix();
	
	glPushMatrix();
	glColor3f(0.7804f, 0.6941f, 0.7098f);
	glTranslatef(8, 16.3, -7.3);
	glRotatef(-45,1,0,0);
	glScalef(1.7,1.7,2);
	glutSolidCube(1);
	glPopMatrix();
	
	//tapa	
	glPushMatrix();
	glColor3f(0.7804f, 0.6941f, 0.7098f);
	glTranslatef(0, 14.4, 3);
	glScalef(21,2,15.5);
	glutSolidCube(1);
	glPopMatrix();
	
	//patas
	patasLavadora();
	
	glPushMatrix();
	glTranslatef(0, 0, -22.5);	
	patasLavadora();
	glPopMatrix();
	
	glPushMatrix();
	glTranslatef(0, 0, 0);
	glRotatef(180,0,1,0);
	patasLavadora();
	glPopMatrix();
	
	glPushMatrix();
	glTranslatef(0, 0, 22.5);
	glRotatef(180,0,1,0);
	patasLavadora();
	glPopMatrix();
	
	
	//boton cilindro
	glPushMatrix();
	glTranslatef(-5, 16, -10);
	glRotatef(-45,1,0,0);
		
	BotonCilindro(2.5,4);
	glPopMatrix();
	
	glPushMatrix();
	glTranslatef(-5, 18.8, -7.3);
	glRotatef(45,1,0,0);
	circuloTapaBoton(2.5);
	
	glPopMatrix();
		
}

void silla(){

//espaldar	
glPushMatrix();
//glTranslatef(-50.0,-50.0,50.0);
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

void ventana(){

	//marcos de la ventana 
	
    glPushMatrix(); //paloizquierda
	    glTranslatef(0.0,-9.5,-11);
        glScalef(3.5,130,3.5);
	    glColor4f(0.5137f, 0.3412f, 0.2039f, 0.9000f);
        glutSolidCube(0.5);
	glPopMatrix(); 
	
	glPushMatrix(); //paloderecha
	    glTranslatef(29,-9.5,-11);
        glScalef(3.5,130,3.5);
	    glColor4f(0.5137f, 0.3412f, 0.2039f, 0.9000f);
        glutSolidCube(0.5);
	glPopMatrix(); 
	
	glPushMatrix(); //paloarriba
	    glTranslatef(14.0,20.0,-10);
        glScalef(35,-8,1);
	    glColor4f(0.5137f, 0.3412f, 0.2039f, 0.9000f);
        glutSolidCube(0.8);
	glPopMatrix(); 
	
	//blanco de la ventana
	glPushMatrix(); //verde
	    glTranslatef(14.5,19.9,-9); 
        glScalef(30,4,2);
	    glColor3f(0.9176f, 0.8706f,0.7882f);
        glutSolidCube(0.9);
	glPopMatrix();
	
	//fondoventana
	glPushMatrix(); 
	    glTranslatef(14.0,1.0,-11); 
        glScalef(35,-40,1);
	    glColor3f(0.8353f, 0.8588f, 0.6745f);
        glutSolidCube(0.8);
	glPopMatrix();
    
    //rayas de la ventana
    glPushMatrix(); //verde
        
	    glTranslatef(14.5,14.8,-10); 
        glScalef(34,-0.4,0); 
	    glColor3f(0.6039f,0.6039f,0.3804f);
        glutSolidCube(0.8);
        
        
        for(int i=0;i<14;i++){
		  glTranslatef(0.0,5.0,0.0); 
		  glColor3f(0.6039f,0.6039f,0.3804f);
		  glutSolidCube(0.8);
	    }
	glPopMatrix();
}

void regla(){
	
	//LADO FRONTAL CELESTE
	glBegin(GL_POLYGON);
	glColor3f(0.6196,0.6,0.6902); // color de la cara o tapa
	glVertex3f( 2.5, -2.5, 2.5 );
	glVertex3f( 2.5, -1.5, 2.5 );
	glVertex3f( -3.5, -1.5, 2.5 );
	glVertex3f( -4.5, -2.5, 2.5 );
	glEnd();
		
	// LADO DERECHO NARANJA
	glBegin(GL_POLYGON);
	glColor3f(0.6196,0.6,0.6902); // color de la cara o tapa
	glVertex3f( 2.5, -2.5, 2.5 );
	glVertex3f( 2.5, 5.0, 2.5 );
	glVertex3f( 1.5, 4.0, 2.5 );
	glVertex3f( 1.5, -2.5, 2.5 );
	glEnd();
	
	// LADO IZQUIERDO PLOMO
	glBegin(GL_POLYGON);
	glColor3f(0.6196,0.6,0.6902);
	glVertex3f( -2.0, -1.5, 2.5 );
	glVertex3f( 1.5, 2.5, 2.5 );
	glVertex3f( 1.5, 4.0, 2.5 );
	glVertex3f( -3.5, -1.5, 2.5 );
	glEnd();
}

void mural(){
	
 glPushMatrix();
	
	glPushMatrix(); //paloizquiera
	    glTranslatef(-5.5,-4.0,-11);
        glScalef(2.8,80,2.8);
	    glColor3f(0.6275f, 0.6275f, 0.4078f);
        glutSolidCube(0.5);
	glPopMatrix(); 
	
	glPushMatrix(); //paloderecha
	    glTranslatef(34.5,-4.0,-11);
        glScalef(2.8,80,2.8);
	    glColor3f(0.6275f, 0.6275f, 0.4078f);
        glutSolidCube(0.5);
	glPopMatrix(); 
	
	//fondomural
	
    glPushMatrix(); 
	    glTranslatef(14.0,-3.5,-11); 
        glScalef(50,48,1);
        //glRotated(90,0,90,0);
	    glColor3f(0.9176f, 0.8706f,0.7882f);
        glutSolidCube(0.8);
	glPopMatrix();
	
	glPushMatrix(); //techomural
	    glRotated(-90,1,0,0);
	    glTranslatef(14.5,8.0,15.8); 
        glScalef(52,-12.0,-1);
	    glColor3f(0.6275f, 0.6275f, 0.4078f);
        glutSolidCube(0.8);
	glPopMatrix();
	
	glPushMatrix(); //palodeabajo
	    glRotated(-90,1,0,0);
	    glTranslatef(14.0,10.0,-23.0); 
        glScalef(80,3,2.8);
	    glColor3f(0.6275f, 0.6275f, 0.4078f);
        glutSolidCube(0.5);
	glPopMatrix();
	
	//hilos-----------------------------------------------
	
   glPushMatrix();
	     
	    glTranslatef(-3,16,-8); 
	    
	     //madeja1

	 glPushMatrix(); 
	     glRotated(-90,1,0,0);
		 glTranslatef(4,0,0);
		 glColor3f(0.9961f,0.2157f,0.2157f);
		 glutSolidCylinder(2.0,7.5,6,5);
	 glPopMatrix();
	
	 glPushMatrix();
	     glRotated(-90,1,0,0);
		 glTranslatef(4,0,0);
		 glColor3f(0.949f, 0.9098f,0.8f);
		 glutSolidCylinder(3.5,1,9,9);
     glPopMatrix();
    
     glPushMatrix();
	     glRotated(-90,1,0,0);
		 glTranslatef(4,0,7);
		 glColor3f(0.949f, 0.9098f,0.8f);
		 glutSolidCylinder(3.5,1,9,9);
     glPopMatrix();
	
	 glPushMatrix(); 
        glRotated(-90,1,0,-90);
	    glTranslatef(10,-4,0); 
        glScalef(5,-1.4,0); 
	    glColor3f(0.949f, 0.9098f,0.8f);
        glutSolidCube(0.8);
	 glPopMatrix();
	
	    //madeja2
	 glPushMatrix();
	     glRotated(-90,1,0,0);
		 glTranslatef(19,0,0);
		 glColor3f(0.949f, 0.9098f,0.8f);
		 glutSolidCylinder(3.5,1,9,9);
     glPopMatrix();
     
     glPushMatrix();
	     glRotated(-90,1,0,0);
		 glTranslatef(19,0,0);
		 glColor3f(0.9961f,0.2157f,0.2157f);
		 glutSolidCylinder(2.0,7.5,9,9);
	 glPopMatrix();
    
     glPushMatrix();
	     glRotated(-90,1,0,0);
		 glTranslatef(19,0,7);
		 glColor3f(0.949f, 0.9098f,0.8f);
		 glutSolidCylinder(3.5,1,9,9);
     glPopMatrix();
    
     glPushMatrix(); 
        glRotated(-90,1,0,-90);
	    glTranslatef(10,-19,0); 
        glScalef(5,-1.4,0); 
	    glColor3f(0.949f, 0.9098f,0.8f);
        glutSolidCube(0.8);
	 glPopMatrix();
	
	 
	    //madeja3
	 glPushMatrix();
	     glRotated(-90,1,0,0);
		 glTranslatef(35,0,0);
		 glColor3f(0.9961f,0.2157f,0.2157f);
		 glutSolidCylinder(1.6,10,40,50);
	 glPopMatrix();
	
	 glPushMatrix();
	     glRotated(-90,1,0,0);
		 glTranslatef(35,0,9.8);
		 glColor3f(0.949f, 0.9098f,0.8f);
		 glutSolidCylinder(1.9,0.5,6,5);
     glPopMatrix();
    
     glPushMatrix(); 
	    glRotated(-90,1,0,0);
	    glTranslatef(35,0,11); 
        glScalef(4,3,2.8);
	    glColor3f(0.949f, 0.9098f,0.8f);
        glutSolidCube(0.5);
	 glPopMatrix();
 
	glPopMatrix();	 
	//circulosgrandes--------------------------------
	glPushMatrix();
		 glTranslatef(2,3,-11);
		 glColor3f(0.6f, 0.698f, 0.549f);
		 glutSolidCylinder(3,1.5,20,10);
    glPopMatrix();
    
    glPushMatrix();
		 glTranslatef(15,3,-11);
		 glColor3f(0.6f, 0.698f, 0.549f);
		 glutSolidCylinder(6,1.5,20,10);
    glPopMatrix();
    
    glPushMatrix();
		 glTranslatef(28,7,-11);
		 glColor3f(0.6f, 0.698f, 0.549f);
		 glutSolidCylinder(4,1.5,20,10);
    glPopMatrix();
    
    glPushMatrix();
		 glTranslatef(2,3,-11);
		 glColor3f(0.6f, 0.698f, 0.549f);
		 glutSolidCylinder(3,1.5,20,10);
    glPopMatrix();
    
    glPushMatrix();
		 glTranslatef(0,-12,-11);
		 glColor3f(0.6f, 0.698f, 0.549f);
		 glutSolidCylinder(3.5,1.5,20,10);
    glPopMatrix();
    
    glPushMatrix();
		 glTranslatef(10,-12,-11);
		 glColor3f(0.6f, 0.698f, 0.549f);
		 glutSolidCylinder(3.5,1.5,20,10);
    glPopMatrix();
    
    glPushMatrix();
		 glTranslatef(27,-12,-11);
		 glColor3f(0.6f, 0.698f, 0.549f);
		 glutSolidCylinder(3.5,1.5,20,10);
    glPopMatrix();

 glPopMatrix();
 
 //circulospeque�os-------------------------------------
   
    glPushMatrix();
		 glTranslatef(2,3,-10);
		 glColor3f(0.2392f, 0.2941f, 0.2706f);
		 glutSolidCylinder(0.5,0.7,20,10);
    glPopMatrix();
    
    glPushMatrix();
		 glTranslatef(15,3,-10);
		 glColor3f(0.2392f, 0.2941f, 0.2706f);
		 glutSolidCylinder(0.5,0.7,20,10);
    glPopMatrix();
    
    glPushMatrix();
		 glTranslatef(28,7,-10);
		 glColor3f(0.2392f, 0.2941f, 0.2706f);
		 glutSolidCylinder(0.5,0.7,20,10);
    glPopMatrix();
    
    glPushMatrix();
		 glTranslatef(0,-12,-10);
		 glColor3f(0.2392f, 0.2941f, 0.2706f);
		 glutSolidCylinder(0.5,0.7,20,10);
    glPopMatrix();
    
    glPushMatrix();
		 glTranslatef(10,-12,-10);
		 glColor3f(0.2392f, 0.2941f, 0.2706f);
		 glutSolidCylinder(0.5,0.7,20,10);
    glPopMatrix();
    
    glPushMatrix();
		 glTranslatef(27,-12,-10);
		 glColor3f(0.2392f, 0.2941f, 0.2706f);
		 glutSolidCylinder(0.5,0.7,20,10);
    glPopMatrix();
    		  
}

void vaso(double radio, double altura,double radio2){
	
	obj = gluNewQuadric();
    	gluQuadricDrawStyle(obj, GLU_FILL);
    	gluQuadricNormals(obj, GLU_SMOOTH);
    	glPushMatrix ();
     //  glTranslatef(0.0,-10.0,-25);
     
     	//glRotatef(90,0,0,1);
      	glScalef(1,1,1);
       	glColor3f(1.0f, 0.0f,.0f);
	  //gluCylinder(obj,0.1f,0.1f,3.0f,32,32);
	  
	  	gluCylinder ( obj,radio, radio2,altura , 20, 5);
   		glPopMatrix ();	
}

void letras(){
	glPushMatrix();
	glColor3f(0.0f, 0.0f, 0.0f);
	glTranslatef(-7, -12, 0.9);
	glScalef(1,1,0);
	glutSolidCube(1);
	glPopMatrix();
	
	 
}

void semana(){
	
	letras();
	glPushMatrix();
	glTranslatef(2.3, 0, 0);
	letras();
	
	glTranslatef(2.3, 0, 0);
	letras();

	glTranslatef(2.3, 0, 0);
	letras();

	glTranslatef(2.3, 0, 0);
	letras();

	glTranslatef(2.3, 0, 0);
	letras();
	
	glTranslatef(2.3, 0, 0);
	letras();
	glPopMatrix();	
}

void almanaque(){
	
	glPushMatrix();
	glColor3f(0.8784f, 0.7804f,0.3608f);
	glScalef(20,15,1);
	glutSolidCube(1);
	glPopMatrix();
	
	glPushMatrix();
	glColor3f(0.949f, 0.8941f, 0.8667f);
	glTranslatef(0, -15, 0.3);
	glScalef(20,15,1);
	glutSolidCube(1);
	glPopMatrix();
	
	glPushMatrix();
	glTranslatef(0, 1.7, 0);
	semana();
	glPopMatrix();

	semana();
	glPushMatrix();
	glTranslatef(0, -1.7, 0);
	semana();
	glTranslatef(0, -1.7, 0);
	semana();
	glTranslatef(0, -1.7, 0);
	semana();
	glTranslatef(0, -1.7, 0);
	letras();
	glTranslatef(2.3, 0, 0);
	letras();
	glTranslatef(2.3, 0, 0);
	letras();
	glPopMatrix();
		
}

void pared(){
	   
	glPushMatrix ();
	   glTranslatef(-13.5,13.0,-53.0);
	   //glRotatef(90.0,0.0,1.0,0.0 );
       glScalef(27,15,0);
       glColor3f(1.0f, 1.0f, 1.0f);
       glutSolidCube (1);
    glPopMatrix ();
}

void desarmador(){
	   glPushMatrix ();
	   glTranslatef(0.0,0.0,-65.0);
       glScalef(10,10,50);
       glColor3f(1.0f, 0.0f, 0.0f);
       glutSolidCube (1);
    glPopMatrix ();
    
	glPushMatrix ();
	   glTranslatef(0.0,0.0,10.0);
       glScalef(5,5,100);
       glColor3f(0.6549f, 0.6353f, 0.6549f);
       glutSolidCube (1);
    glPopMatrix ();
    
	//estante 
    glPushMatrix ();
       glTranslatef(-0,0,60);
       glScalef(0.6,0.6,1);
       glRotatef (0.0f, 0.0f, 1.0f, 0.0f);
       glColor3f(0.6549f, 0.6353f, 0.6549f);;
	   glutSolidCone (4,4,20,20);
    glPopMatrix ();
}

void patasLavadero(){
	
	//cara 1
	glBegin(GL_POLYGON);
	glColor3f(0.4275f, 0.3451f, 0.3686f);
	glVertex3d(0,0,0);
	glVertex3d(0,-20,1);
	glVertex3d(0,-20,3);
	glVertex3d(0,0,3);
	glEnd();
	
	//cara 2
	glBegin(GL_POLYGON);
	glColor3f(0.4275f, 0.3451f, 0.3686f);
	glVertex3d(0,0,3);
	glVertex3d(0,-20,3);
	glVertex3d(-3,-20,3);
	glVertex3d(-4,0,3);
	glEnd();
	
	//cara 3
	glBegin(GL_POLYGON);
	glColor3f(0.4275f, 0.3451f, 0.3686f);
	glVertex3d(-4,0,3);
	glVertex3d(-3,-20,3);
	glVertex3d(-3,-20,1);	
	glVertex3d(-4,0,0);
	glEnd();
	
	
	//cara 4
	glBegin(GL_POLYGON);
	glColor3f(0.4275f, 0.3451f, 0.3686f);
	glVertex3d(-3,-20,1);
	glVertex3d(-4,0,0);
	glVertex3d(0,0,0);
	glVertex3d(0,-20,1);
	glEnd();	
}

void circuloTapa(double rad){
	
	glBegin(GL_POLYGON);
	glColor3f(0.8588f, 0.7725f, 0.8118f);
	for(double i=0.0; i<10; i+=0.001){
		posclax1 = rad*cos(i);
		posclay1= rad*sin(i);
		
		glVertex3f(posclax1,0,posclay1);
	}
	
	glEnd();			
}

void esquinaLavadero(double radio,double altura){
		obj = gluNewQuadric();
    	gluQuadricDrawStyle(obj, GLU_SILHOUETTE);
    	gluQuadricNormals(obj, GLU_SMOOTH);
    	glPushMatrix ();
     //  glTranslatef(0.0,-10.0,-25);
     
     	glRotatef(90,1,0,0);
      	glScalef(1,1,1);
       	glColor3f(0.8588f, 0.7725f, 0.8118f);
	  //gluCylinder(obj,0.1f,0.1f,3.0f,32,32);
	  
	  	gluCylinder ( obj,radio, radio,altura , 50, 5);
   		glPopMatrix ();	
}

void varilla(double radio, double altura){
	
	obj = gluNewQuadric();
    	gluQuadricDrawStyle(obj, GLU_SILHOUETTE);
    	gluQuadricNormals(obj, GLU_SMOOTH);
    	glPushMatrix ();
     //  glTranslatef(0.0,-10.0,-25);
     
     	//glRotatef(90,0,0,1);
      	glScalef(1,1,1);
       	glColor3f(0.4275f, 0.3451f, 0.3686f);
	  //gluCylinder(obj,0.1f,0.1f,3.0f,32,32);
	  
	  	gluCylinder ( obj,radio, radio,altura , 50, 5);
   		glPopMatrix ();		
}

void cano(){
	   glPushMatrix ();
       glRotatef (0.0f, 0.0f, 1.0f, 0.0f);
       glScalef(100,10,15);
       glColor3f(1.0f, 1.0f, 0.9961f);
       glutSolidCube (1);
    glPopMatrix ();
    
	glPushMatrix ();
	   glTranslatef(-63.0,-16,0.0);
       glRotatef (45.0f, 0.0f, 0.0f, 1.0f);
       glScalef(50,10,15);
       glColor3f(1.0f, 1.0f, 0.9961f);
       glutSolidCube (1);
    glPopMatrix ();
    
	//estante 
    glPushMatrix ();
       glTranslatef(40,0.3,0);
       glScalef(0.6,0.6,1);
       glRotatef (90.0f, 0.0f, 1.0f, 0.0f);
       glColor3f(0.851f, 0.8902f, 0.8471f);
	   glutSolidCone (50,20,20,20);
    glPopMatrix ();
}

void manijas(){
		
	glPushMatrix ();
		glTranslatef(20,0,0);
       glRotatef (0.0f, 0.0f, 1.0f, 0.0f);
       glScalef(40,10,15);
       glColor3f(1.0f, 1.0f, 0.9961f);
       glutSolidCube (1);
    glPopMatrix ();
	
	glPushMatrix ();
		glTranslatef(0,0,-20);
       glRotatef (0.0f, 0.0f, 1.0f, 0.0f);
       glScalef(15,10,60);
       glColor3f(1.0f, 1.0f, 0.9961f);
       glutSolidCube (1);
    glPopMatrix ();
	

	 glPushMatrix ();
       glTranslatef(40,0.3,0);
       glScalef(0.6,0.6,1);
       glRotatef (90.0f, 0.0f, 1.0f, 0.0f);
       glColor3f(0.851f, 0.8902f, 0.8471f);
	   glutSolidCone (50,20,20,20);
    glPopMatrix ();
	
}

void lavadero(){
		//base
		glPushMatrix ();
		glColor3f(0.8588f, 0.7725f, 0.8118f);
		glScalef(23,13,2);
		glutSolidCube(1);
		glPopMatrix ();	
		
		glPushMatrix ();
		glColor3f(0.8588f, 0.7725f, 0.8118f);
		glTranslatef(0, 0, -21);
		glScalef(23.5,13,2);
		glutSolidCube(1);
		glPopMatrix ();	
		
		glPushMatrix ();
		glColor3f(0.8588f, 0.7725f, 0.8118f);
		glTranslatef(12, 0, -11);
		glScalef(2,13,21);
		glutSolidCube(1);
		glPopMatrix ();	
		
		glPushMatrix ();
		glColor3f(0.8588f, 0.7725f, 0.8118f);
		glTranslatef(-12, 0, -11);
		glScalef(2,13,21);
		glutSolidCube(1);
		glPopMatrix ();	
		
	//esquina
		
		glPushMatrix ();
		glTranslatef(-12, 6.5, 0);
		esquinaLavadero(1,13);
		glTranslatef(24, 0, 0);
		esquinaLavadero(1,13);	
		glTranslatef(0, 0, -21.5);
		esquinaLavadero(1,13);	
		glTranslatef(-24, 0, 0);
		esquinaLavadero(1,13);
		glPopMatrix ();	
		
	//esquina tapa
		
		glPushMatrix ();
		glTranslatef(-12, 6.5, 0);	
		circuloTapa(1);
		glTranslatef(0, -13, 0);	
		circuloTapa(1);	
		glPopMatrix ();	
		
		glPushMatrix ();
		glTranslatef(24, 0, 0);
		glTranslatef(-12, 6.5, 0);	
		circuloTapa(1);
		glTranslatef(0, -13, 0);	
		circuloTapa(1);	
		glPopMatrix ();	
		
		//****
		
		glPushMatrix ();
		
		glTranslatef(0, 0, -21.5);
		glPushMatrix ();
		glTranslatef(-12, 6.5, 0);	
		circuloTapa(1);
		glTranslatef(0, -13, 0);	
		circuloTapa(1);	
		glPopMatrix ();	
		
		glPushMatrix ();		
		glTranslatef(24, 0, 0);
		glTranslatef(-12, 6.5, 0);	
		circuloTapa(1);
		glTranslatef(0, -13, 0);	
		circuloTapa(1);	
		glPopMatrix ();				
		
		glPopMatrix ();	
		
		
		//parte posterior
		
		glPushMatrix ();
		glColor3f(0.8588f, 0.7725f, 0.8118f);
		glTranslatef(15, 3.5, -11);
		glScalef(4,20,21);
		glutSolidCube(1);
		glPopMatrix ();
		//esquinas
		glPushMatrix ();
		glTranslatef(13,13.5 ,-2.5 );
		glRotatef(90,0,0,1);		
		esquinaLavadero(2,4);
		glPopMatrix ();
		
		glPushMatrix ();
		glTranslatef(0,0 ,-17 );
		
		glPushMatrix ();
		glTranslatef(13,13.5 ,-2.5 );
		glRotatef(90,0,0,1);		
		esquinaLavadero(2,4);
		glPopMatrix ();
			
		glPopMatrix ();
		//tapas
		glPushMatrix ();
		glTranslatef(13,13.5 ,-2.5 );
		glRotatef(90,0,0,1);		
		circuloTapa(2);
		glPopMatrix ();
		
		glPushMatrix ();
		glTranslatef(0,0 ,-17 );
		glPushMatrix ();
		glTranslatef(13,13.5 ,-2.5 );
		glRotatef(90,0,0,1);		
		circuloTapa(2);
		glPopMatrix ();
		glPopMatrix ();
		
		glPushMatrix ();
		glTranslatef(4,0 ,0 );
		glPushMatrix ();
		glTranslatef(13,13.5 ,-2.5 );
		glRotatef(90,0,0,1);		
		circuloTapa(2);
		glPopMatrix ();
		
		glPushMatrix ();
		glTranslatef(0,0 ,-17 );
		glPushMatrix ();
		glTranslatef(13,13.5 ,-2.5 );
		glRotatef(90,0,0,1);		
		circuloTapa(2);
		glPopMatrix ();
		glPopMatrix ();		
		glPopMatrix ();
		
		//topsuperior
		glPushMatrix ();
		glColor3f(0.8588f, 0.7725f, 0.8118f);
		glTranslatef(15, 14, -11);
		glScalef(4,4,18);
		glutSolidCube(1);
		glPopMatrix ();
		
		//patas 
		glPushMatrix ();
		glTranslatef(-5, -6.5, -4);
		patasLavadero();
		
		glTranslatef(17, 0, 0);
		patasLavadero();			
		glPopMatrix ();
		
		//******	
		glPushMatrix ();
		
		glTranslatef(3, 0, -21);
		glRotatef(180,0,1,0);
		glPushMatrix ();
		glTranslatef(-5, -6.5, -4);
		patasLavadero();
		
		glTranslatef(17, 0, 0);
		patasLavadero();			
		glPopMatrix ();
		
		glPopMatrix ();
	
		//contenido
		glPushMatrix ();
		glColor3f(0.0f, 0.0f, 0.8118f);
		glTranslatef(0, 0, -11);
		glScalef(22,4,20);
		glutSolidCube(1);
		glPopMatrix ();
		
		//varilla
		glPushMatrix ();
		glTranslatef(-7, -15, -19);
		varilla(1, 17);
		
		glTranslatef(17, 0, 0);
		varilla(1, 17);
			
		glPopMatrix ();
				
		//ca�o
				
		glPushMatrix ();
		glTranslatef(26, 2, -11);
		
		glRotatef(180,0,1,0);
		glPushMatrix ();
		glTranslatef(17, 10, 0);
		glRotatef(180,1,0,0);
		glScalef(-0.08,-0.08,-0.08);
		cano();
		glPopMatrix ();
		glPopMatrix ();
		
		
		glPushMatrix ();	
		glTranslatef(0, 24, -30);
		glRotatef(180,1,0,0);
		glPushMatrix ();
		glTranslatef(26, 2, -15);
		
		glRotatef(180,0,1,0);
		glPushMatrix ();
		glTranslatef(17, 10, 0);
		glRotatef(180,1,0,0);
		glScalef(-0.08,-0.08,-0.08);
		manijas();
		glPopMatrix ();
		glPopMatrix ();
		
		glPopMatrix ();
		
		
		glPushMatrix ();
		glTranslatef(26, 2, -7);
		
		glRotatef(180,0,1,0);
		glPushMatrix ();
		glTranslatef(17, 10, 0);
		glRotatef(180,1,0,0);
		glScalef(-0.08,-0.08,-0.08);
		manijas();
		glPopMatrix ();
		glPopMatrix ();
				
}

void arriba(){
	
	//LADO FRONTAL BLANCO
	glBegin(GL_POLYGON);
	glColor3f(0.4157f,0.5804f, 0.6235f);
	glVertex3f( 3.0, -1.5, 2.5 );
	glVertex3f( 2.5, 0.0, 2.5 );
	glVertex3f( -2.5, 0.0, 2.5 );
	glVertex3f( -3.0, -1.5, 2.5 );
	glEnd();
	
	// LADO TRASERO ROJO
	glBegin(GL_POLYGON);
	glColor3f(0.4157f,0.5804f, 0.6235f);
	glVertex3f( 3.0, -1.5, 0.0 ); 
	glVertex3f( 2.5, 0.0, 0.0 ); 
	glVertex3f( -2.5, 0.0, 0.0 ); 
	glVertex3f( -3.0, -1.5, 0.0 ); 
	glEnd();
		
	// LADO DERECHO TURQUESA
	glBegin(GL_POLYGON);
	glColor3f(0.4157f,0.5804f, 0.6235f);
	glVertex3f( 3.0, -1.5, 0.0 );
	glVertex3f( 2.5, 0.0, 0.0 );
	glVertex3f( 2.5, 0.0, 2.5 );
	glVertex3f( 3.0, -1.5, 2.5 );
	glEnd();
	
	// LADO IZQUIERDO VERDE LIMON
	glBegin(GL_POLYGON);
	glColor3f(0.4157f,0.5804f, 0.6235f);
	glVertex3f( -3.0, -1.5, 0.0 );
	glVertex3f( -2.5, 0.0, 0.0 );
	glVertex3f( -2.5, 0.0, 2.5 );
	glVertex3f( -3.0, -1.5, 2.5 );
	glEnd();
	
	// LADO SUPERIOR AMARILLO
	glBegin(GL_POLYGON);
	glColor3f(0.4157f,0.5804f, 0.6235f);
	glVertex3f( 2.5, 0.0, 2.5 );
	glVertex3f( 2.5, 0.0, 0.0 );
	glVertex3f( -2.5, 0.0, 0.0 );
	glVertex3f( -2.5, 0.0, 2.5 );
	glEnd();
}

void abajo(){
		
	//LADO FRONTAL BLANCO
	glBegin(GL_POLYGON);
	glColor3f(0.4157f,0.5804f, 0.6235f);
	glVertex3f( 5.0, -1.5, 4.5 );
	glVertex3f( 5.0, -2.0, 4.5 );
	glVertex3f( -5.0, -2.0, 4.5 );
	glVertex3f( -5.0, -1.5, 4.5 );
	glEnd();
	
	// LADO TRASERO ROJO
	glBegin(GL_POLYGON);
	glColor3f(0.4157f,0.5804f, 0.6235f);
	glVertex3f( 5.0, -2.0, 2.0 );
	glVertex3f( 5.0, -1.0, 2.5 );
	glVertex3f( -5.0, -1.0, 2.5 );
	glVertex3f( -5.0, -2.0, 2.0 );
	glEnd();
		
	// LADO DERECHO TURQUESA
	glBegin(GL_POLYGON);
	glColor3f(0.4157f,0.5804f, 0.6235f);
	glVertex3f( 5.0, -2.0, 2.0 );
	glVertex3f( 5.0, -1.0, 2.5 );
	glVertex3f( 5.0, -1.5, 4.5 );
	glVertex3f( 5.0, -2.0, 4.5 );
	glEnd();
	
	// LADO IZQUIERDO VERDE LIMON
	glBegin(GL_POLYGON);
	glColor3f(0.4157f,0.5804f, 0.6235f);
	glVertex3f( -5.0, -2.0, 2.0 );
	glVertex3f( -5.0, -1.0, 2.5 );
	glVertex3f( -5.0, -1.5, 4.5 );
	glVertex3f( -5.0, -2.0, 4.5 );
	glEnd();
	
	// LADO SUPERIOR AMARILLO
	glBegin(GL_POLYGON);
	glColor3f(0.4157f,0.5804f, 0.6235f);
	glVertex3f( 5.0, -1.5, 4.5 );
	glVertex3f( 5.0, -1.0, 2.5 );
	glVertex3f( -5.0, -1.0, 2.5 );
	glVertex3f( -5.0, -1.5, 4.5 );
	glEnd();
}

void cubitos(){
	
	glPushMatrix ();
    glTranslatef(-5.0,-2.8,3.8);  
	glRotatef(33.7,1.0,0.0,0.0);
	glScalef(0.25,0.2,0.3);
    glColor3f(0.4941f, 0.5882f, 0.5137f);
	glutSolidCube (2);
    glPopMatrix ();	
}

void lampara(){
	
	//PARTE DE ARRIBA
	glPushMatrix();
	glTranslatef(0.0,5.0,0.0);
	//glScalef(0.2,0.2,0.2);
	arriba();
	glPopMatrix();
	
	//PARTE DE ABAJO
	glPushMatrix();
	glTranslatef(-2.0,-1.5,-2.5);
	//glScalef(0.2,0.2,0.2);
	abajo();
	glPopMatrix();

	//CUBITO 1
	glPushMatrix ();
	glTranslatef(0.0,0.0,-2.5);
   	cubitos();
    glPopMatrix ();	
    
    //CUBITO 2
    glPushMatrix ();
    glTranslatef(-1.0,0.0,-2.5);
	cubitos();
	glPopMatrix ();
	
	
	glPushMatrix ();
    glTranslatef(0.0,1.0,0.0);  
	//glRotatef(33.7,1.0,0.0,0.0);
	glScalef(0.25,3.8,0.25);
    glColor3f(1.0f,1.0f,1.0f);
	glutSolidCube (2);
    glPopMatrix ();	

}

void reloj(double rad){
	
	obj = gluNewQuadric();
    gluQuadricDrawStyle(obj, GLU_FILL);
    gluQuadricNormals(obj, GLU_SMOOTH);
	
    	glPushMatrix ();
     //  glTranslatef(0.0,-10.0,-25);
       glScalef(1,1,1);
       glColor3f(0.8392f, 0.7373f, 0.4863f);
	  //gluCylinder(obj,0.1f,0.1f,3.0f,32,32);
	  
	  gluCylinder ( obj,rad--, rad--,5 , 13, 10);
    glPopMatrix ();	  
}

void circuloTapaReloj(double rad){
	
	glBegin(GL_POLYGON);
	glColor3f(0.9216f, 0.8549f, 0.7843f);
	for(double i=0.0; i<10; i+=0.001){
		posclax1 = rad*cos(i);
		posclay1= rad*sin(i);
		
		glVertex3f(posclax1,0,posclay1);
	}
	
	glEnd();			
}

void lineasReloj(){
	glPushMatrix ();
	glColor3f(0.0f, 0.0f, 0.0f);
	glTranslatef(0,10,0.1);
	glScalef(1,5,0);
	glutSolidCube (1);
	glPopMatrix ();	
	
}

void manecilla(){
	
	glPushMatrix ();
	glColor3f(0.698f,0.6471f, 0.6824f);
	glTranslatef(0,5,0.5);
	glScalef(1,12,0);
	glutSolidCube (1);
	glPopMatrix ();	
	
	glPushMatrix ();
	glColor3f(0.698f,0.6471f, 0.6824f);
	glTranslatef(4, -0.5, 0.5);
	glScalef(8,1,0);
	glutSolidCube (1);
	glPopMatrix ();	
	
	
}

void uno(double rad){
	
	for(double i=15; i<rad; i+=0.01){
		reloj(i);
	}
	glPushMatrix ();
	//glScalef(0,0,0);
	glRotatef (90.0f, 1.0f, 0.0f, 0.0f);
	circuloTapaReloj(17);
    glPopMatrix ();	
      
    
    lineasReloj();
    
    glPushMatrix ();
    glRotatef (30.0f, 0.0f, 0.0f, 1.0f);
    lineasReloj();
    
    glRotatef (30.0f, 0.0f, 0.0f, 1.0f);  
    lineasReloj();
    
    glRotatef (30.0f, 0.0f, 0.0f, 1.0f);
    lineasReloj();
    
    glRotatef (30.0f, 0.0f, 0.0f, 1.0f);
    lineasReloj();
    
    glRotatef (30.0f, 0.0f, 0.0f, 1.0f);
    lineasReloj();
    
    glRotatef (30.0f, 0.0f, 0.0f, 1.0f);
    lineasReloj();
    
    glRotatef (30.0f, 0.0f, 0.0f, 1.0f);
    lineasReloj();
    
    glRotatef (30.0f, 0.0f, 0.0f, 1.0f);
    lineasReloj();
    
    glRotatef (30.0f, 0.0f, 0.0f, 1.0f);
    lineasReloj();
    
    glRotatef (30.0f, 0.0f, 0.0f, 1.0f);
    lineasReloj();
    
    glRotatef (30.0f, 0.0f, 0.0f, 1.0f);
    lineasReloj();
    glPopMatrix ();	
    
    manecilla();
      
}

void display(){
	
	glClearColor(0.0549f,0.3765f, 0.6667f,0.0f);
	
	// Borrar pantalla y Z-buffer
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
	// Resetear transformaciones
	glMatrixMode( GL_MODELVIEW_MATRIX );
	glLoadIdentity();
	
	glRotatef( rotate_x, 10.0, 0.0, 0.0 );
	glRotatef( rotate_y, 0.0, 10.0, 0.0 );	
	
	//prender_luz();
	
	//MAPA
	
   	mapa();
   	//CAJA 1 EDSON
	glPushMatrix();
	glTranslatef(-39,-22.0,50.0);
	glRotatef(-30,0.0,1.0,0.0);
	glScalef(3.0,2.0,2.0);
	caja();
	glPopMatrix();
	
	//CAJA 2 EDSON
	glPushMatrix();
	glTranslatef(-45,-22.0,-20.0);
	glRotatef(120,0.0,1.0,0.0);
	glScalef(3.0,2.0,2.0);
	caja();
	glPopMatrix();
	
	//MESA EN U
	glPushMatrix();
	glTranslatef(-52.0,-6.0,-25.0);
	glRotatef(-55,0.0,1.0,0.0);
	glScalef(0.5,0.5,0.5);
	cajones();
	glPopMatrix();
		
	//EMPIEZA CUADRO	
	glPushMatrix();
	glTranslatef(55.0,30.0,-20);
	glRotatef(-90,0.0,1.0,0.0);
	glScalef(5.0,5.0,5.0);
	cuadro();
	glPopMatrix();
	
	//PAPELES CUADRO
	glPushMatrix();	
	glTranslatef(55.0,30.0,-20);
	glRotatef(-90,0.0,1.0,0.0);
	glScalef(5.0,5.0,5.0);
	papeles_cuadro();
	glPopMatrix();
	
	//BOLITAS
	glPushMatrix();	
	glTranslatef(55.0,30.0,-20);
	glRotatef(-90,0.0,1.0,0.0);
	glScalef(5.0,5.0,5.0);
	bolitas();
	glPopMatrix();
	//TERMINA CUADRO
	
	
	//RICARDO CAJA 1
	glPushMatrix();	
	glTranslatef(50.0,2.8,-30);
	glRotatef(-90,0.0,1.0,0.0);
	glScalef(2.3,2.3,1.0);
	caja1();
	glPopMatrix();
	
	//RICARDO CAJON 2
	glPushMatrix();	
	glTranslatef(40.0,2.8,-50);
	glRotatef(0.0,0.0,1.0,0.0);
	glScalef(1.7,1.7,1.7);
	cajon2();
	glPopMatrix();
	
	//RICARDO CAJON 3	
	glPushMatrix();	
	glTranslatef(10.0,6.8,-50.0);
	glRotatef(0.0,0.0,1.0,0.0);
	glScalef(2.0,1.8,2.0);
	cajon();
	glPopMatrix();
	
	//RICARDO CAJON 4	
	glPushMatrix();	
	glTranslatef(-13.5,4.8,-50.0);
	glRotatef(0.0,0.0,1.0,0.0);
	glScalef(4.0,4.0,2.5);
	CajaTodo();
	glPopMatrix();
	
	//LAVADORA CHELO
	glPushMatrix();
	
	glTranslatef(41.5,-9.0,47.0);
	glRotatef(-90,0.0,1.0,0.0);
	glScalef(1.0,1.0,1.0);
	lavadora();
	glPopMatrix();
	
	//LAVADERO CON CA�O CHELO
	glPushMatrix();	
	glTranslatef(41.0,0.0,32.0);
	glRotatef(0.0,0.0,0.0,0.0);
	glScalef(1.0,1.0,1.0);
	lavadero();
	glPopMatrix();
		
	//SILLA GUSTAVO
	glPushMatrix();	
	glTranslatef(0.0,2.0,18.0);
	glRotatef(45.0,0.0,1.0,0.0);
	glScalef(0.45,0.45,0.45);
	silla();
	glPopMatrix();
	
	//VENTANA KATHY
	glPushMatrix();	
	glTranslatef(-28.0,35.0,-43.0);
	glRotatef(0.0,0.0,1.0,0.0);
	glScalef(1.0,1.0,1.0);
	ventana();
	glPopMatrix();
		
	//REGLA ESCUADRA EDSON
	glPushMatrix();	
	glTranslatef(-31.0,-3.2,0.0);
	glRotatef(-90.0,1.0,0.0,0.0);
	glScalef(1.0,1.0,1.0);
	regla();
	glPopMatrix();
	
	//MURAL KATHY
	glPushMatrix();	
	glTranslatef(10.0,40.0,-42.3);
	glRotatef(0.0,0.0,0.0,0.0);
	glScalef(1.0,1.0,1.0);
	mural();
	glPopMatrix();
	
	//VASO RICARDO
	glPushMatrix();	
	glTranslatef(-33.0,3.0,-45.0);
	glRotatef(90.0,1.0,0.0,0.0);
	vaso(2,4,1);
	glPopMatrix();
	
	//ALMANAQUE MARCELO	
	glPushMatrix();	
	glTranslatef(53.75,40.0,40.0);
	glRotatef(-90.0,0.0,1.0,0.0);
	glScalef(0.7,0.7,0.7);
	almanaque();
	glPopMatrix();
	
	//DESARMADOR RICARDO
	glPushMatrix();	
	glTranslatef(-45.0,0.0,0.0);
	glRotatef(-120.0,0.0,1.0,0.0);
	glScalef(0.06,0.06,0.06);
	desarmador();
	glPopMatrix();
	
	//LAMPARA EDSON
	glPushMatrix();	
	glTranslatef(-41.0,5.0,-45.0);
	glRotatef(20.0,0.0,1.0,0.0);
	glScalef(1.8,1.8,1.8);
	lampara();
	glPopMatrix();
	
		
	glPushMatrix();	
	glTranslatef(53.0,55.0,20.0);
	glRotatef(-90.0,0.0,1.0,0.0);
	glScalef(0.45,0.45,0.45);
	uno(20);
	glPopMatrix();
	
	//FOCO VERDE
	glPushMatrix();
    glColor3f(0.6588f,0.8196f,0.6824f);
    glTranslatef(40.0,15.0,-47.0);
    glutSolidSphere(3.5,20,10);
    glPopMatrix();
    
    //FOCO ROSA
	glPushMatrix();
    glColor3f(0.9216f,0.7608f,0.8706f);
    glTranslatef(20.0,15.0,-40.0);
    glutSolidSphere(3.5,20,10);
    glPopMatrix();
	
	pared();
	
	prender_luz();
			
	glFlush();
	glutSwapBuffers();
	
}

void myReshape(int w, int h){
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION); //cada MATRIX MODE CON SU LOAD IDENTITY
	glLoadIdentity();
	glOrtho(-100,100,-100,100,-100,100);
	gluPerspective( 30.0, (GLdouble)w/(GLdouble)h, 50.0,50.0);     //perspectiva (angulo, aspecto, distancia del observador al plano cercano, distancia del observador al plano lejano)
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(0.0, 0.0, -10.0, /* cam-pos (0,0,20) */
	0.0, 0.0, 0.0, /* ver a */
	0.0, 1.0, 0.0);
}

void specialKeys( int key, int x, int y ){
	// La flecha derecha: incrementa su rotaci�n en 5 grados
	if (key == GLUT_KEY_RIGHT)
	rotate_y -= 10;
	// La flecha izquierda: disminuye su rotaci�n en 5 grados
	else if (key == GLUT_KEY_LEFT)
	rotate_y += 10;
	else if (key == GLUT_KEY_UP)
	rotate_x += 10;
	else if (key == GLUT_KEY_DOWN)
	rotate_x -= 10;
	// Solicitud para actualizar la pantalla
	glutPostRedisplay();
}

void onoff(unsigned char key, int x, int y){
	
    if(key=='P'){
        glEnable(GL_LIGHT0);
    }else if(key=='p'){
        glDisable(GL_LIGHT0);
    }
}

void onoff2(unsigned char key, int x, int y){
	
    if(key=='X'){
			x++; cout<<"X: "<<x;
    }else if(key=='x'){
			x--; cout<<"X: "<<x;
    }
    if(key=='Y'){
			y++; cout<<"Y: "<<y;
    }else if(key=='y'){
			y--; cout<<"Y: "<<y;
    }
    if(key=='Z'){
			z++; cout<<"Z: "<<z<<endl;
    }else if(key=='z'){
			z--; cout<<"Z: "<<z;
    }
}

void manejarTeclado(unsigned char key, int x, int y){
    onoff(key,x,y);
    onoff2(key,x,y);
    glutPostRedisplay();
    
}

int main(int argc, char* argv[]){
	glutInit(&argc,argv);
	glutInitWindowSize(800,800);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutCreateWindow("T2 3D");
	glEnable(GL_DEPTH_TEST);		
	glutDisplayFunc(display);
	glutReshapeFunc(myReshape);	
	glutKeyboardFunc(manejarTeclado);	
	glutSpecialFunc(specialKeys);
	glutMainLoop();
	
	return 0;	
}
