#include <GL/freeglut.h>
#include <cmath>

void display()
{
glClear(GL_COLOR_BUFFER_BIT);

/////////////////////////////// FONDO ///////////////////////////////
glPushMatrix ();
/*PISO*/
glColor3f (0.4f, 0.6f, 0.7f);
glBegin (GL_POLYGON);
glVertex2f (-1.0f,-0.6f);//A
glVertex2f (-0.75f, 0.1f);//B
glVertex2f (0.1f, 0.1f);//C
glVertex2f (1.0f,-0.6f);//D
glVertex2f (1.0f,-1.0f);//E
glVertex2f (-1.0f,-1.0f);//F
glEnd ();
//LINEAS Piso
glColor3f (0.1f, 0.5f, 0.7f);
glLineWidth(9);
glBegin (GL_LINES);//0.1 - -0.75
glVertex2f (-0.6f, 0.1f);//A
glVertex2f (-0.7f,-1.0f);//B
glVertex2f (-0.4f, 0.1f);//A
glVertex2f (-0.3f,-1.0f);//B
glVertex2f (-0.2f, 0.1f);//A
glVertex2f (0.15f,-1.0f);//B
glVertex2f (-0.03f, 0.1f);//A
glVertex2f (0.7f,-1.0f);//B
glVertex2f (-1.0f, -0.1f);//A
glVertex2f (1.0f,-0.1f);//B
glVertex2f (-1.0f, -0.35f);//A
glVertex2f (1.0f,-0.35f);//B
glVertex2f (-1.0f, -0.65f);//A
glVertex2f (1.0f,-0.65f);//B
glVertex2f (-1.0f, -1.0f);//A
glVertex2f (1.0f,-1.0f);//B
glEnd ();
/*TECHO*/
glColor3f (0.8f, 0.8f, 0.8f);
glBegin (GL_POLYGON);
glVertex2f (-1.0f, 1.0f);//A
glVertex2f (0.75f, 1.0f);//B
glVertex2f (0.1f, 0.8f);//C
glVertex2f (-0.75f, 0.8f);//D
glEnd ();
//LINEAS TECHO
glColor3f (0.0f, 0.0f, 0.0f);
glLineWidth(3);
glBegin (GL_LINES);//
glVertex2f (-0.68f, 1.0f);//A
glVertex2f (-0.5f,0.7f);//B
glVertex2f (-0.41f, 1.0f);//A
glVertex2f (-0.35f,0.7f);//B
glVertex2f (-0.13f, 1.0f);//A
glVertex2f (-0.2f,0.7f);//B
glVertex2f (0.2f, 1.0f);//A
glVertex2f (-0.1f,0.7f);//B
glVertex2f (-1.0f, 0.9f);//C
glVertex2f (1.0f, 0.9f);//D
glEnd ();
/*PARED PRINCIPAL*/
glColor3f (0.8f, 0.7f, 0.5f);
glBegin (GL_POLYGON);
glVertex2f (-0.75f, 0.8f);//A
glVertex2f (0.1f, 0.8f);//B
glVertex2f (0.1f,0.25f);//C
glVertex2f (-0.75f, 0.25f);//D
glEnd ();
glColor3f (0.7f, 0.5f, 0.5f);
glBegin (GL_POLYGON);
glVertex2f (-0.75f, 0.25f);//A
glVertex2f (0.1f,0.25f);//B
glVertex2f (0.1f, 0.1f);//C
glVertex2f (-0.75f, 0.1f);//D
glEnd ();
/*PARED IZQUIERDA*/
glColor3f (0.7f, 0.5f, 0.5f);
glBegin (GL_POLYGON);
glPopMatrix ();
glVertex2f (-1.0f, 1.0f);//A
glVertex2f (-0.75f, 0.8f);//B
glVertex2f (-0.75f, 0.75f);//C
glVertex2f (-1.0f,0.9f);//D
glEnd ();
glColor3f (0.8f, 0.7f, 0.5f);
glBegin (GL_POLYGON);
glVertex2f (-1.0f,0.9f);//A
glVertex2f (-0.75f,0.75f);//B
glVertex2f (-0.75f, 0.25f);//C
glVertex2f (-1.0f,-0.2f);//D
glEnd ();
glColor3f (0.7f, 0.5f, 0.5f);
glBegin (GL_POLYGON);
glVertex2f (-1.0f,-0.2f);//A
glVertex2f (-0.75f, 0.25f);//B
glVertex2f (-0.75f, 0.1f);//C
glVertex2f (-1.0f,-0.6f);//D
glEnd ();
/*PARED DERECHA*/
glColor3f (0.7f, 0.5f, 0.5f);
glBegin (GL_POLYGON);
glPopMatrix ();
glVertex2f (0.1f, 0.8f);//A
glVertex2f (0.75f, 1.0f);//B
glVertex2f (1.0f, 1.0f);//C
glVertex2f (1.0f,0.9f);//D
glVertex2f (0.1f, 0.75f);//E
glEnd ();
glColor3f (0.8f, 0.7f, 0.5f);
glBegin (GL_POLYGON);
glVertex2f (0.1f, 0.75f);//A
glVertex2f (0.75f, 0.9f);//B
glVertex2f (1.0f, 1.0f);//C
glVertex2f (1.0f,-0.3f);//D
glVertex2f (0.1f, 0.25f);//E
glEnd ();
glColor3f (0.7f, 0.5f, 0.5f);
glBegin (GL_POLYGON);
glVertex2f (0.1f,0.25f);//A
glVertex2f (1.0f,-0.3f);//B
glVertex2f (1.0f,-0.6f);//C
glVertex2f (0.1f, 0.1f);//D
glEnd ();
/*PIZARRA 2*/
glColor3f (0.15f, 0.5f, 0.15f);
glBegin (GL_POLYGON);
glVertex2f (-0.6f,0.5f);//A
glVertex2f (-0.493f, 0.51f);//B
glVertex2f (-0.475f, 0.3f);//C
glVertex2f (-0.575f, 0.3f);//D
glEnd ();
glColor3f (1.0f, 1.0f, 1.0f);
glLineWidth(3);
glBegin (GL_LINE_LOOP);
glVertex2f (-0.6f,0.5f);//A
glVertex2f (-0.493f, 0.51f);//B
glVertex2f (-0.475f, 0.3f);//C
glVertex2f (-0.575f, 0.3f);//D
glEnd ();
/*PIZARRA 3*/
glColor3f (0.15f, 0.5f, 0.15f);
glBegin (GL_POLYGON);
glVertex2f (-0.2101f, 0.51f);//A
glVertex2f (-0.1f, 0.5f);//B
glVertex2f (-0.125f, 0.3f);//C
glVertex2f (-0.225f, 0.3f);//D
glEnd ();
glColor3f (1.0f, 1.0f, 1.0f);
glLineWidth(3);
glBegin (GL_LINE_LOOP);
glVertex2f (-0.2101f, 0.51f);//A
glVertex2f (-0.1f, 0.5f);//B
glVertex2f (-0.125f, 0.3f);//C
glVertex2f (-0.225f, 0.3f);//D
glEnd ();
/*PIZARRA 1*/
glColor3f (0.15f, 0.5f, 0.15f);
glBegin (GL_POLYGON);
glVertex2f (-0.5f,0.6f);//A
glVertex2f (-0.2f, 0.6f);//B
glVertex2f (-0.225f, 0.3f);//C
glVertex2f (-0.475f, 0.3f);//D
glEnd ();
glColor3f (1.0f, 1.0f, 1.0f);
glLineWidth(3);
glBegin (GL_LINE_LOOP);
glVertex2f (-0.5f,0.6f);//A
glVertex2f (-0.2f, 0.6f);//B
glVertex2f (-0.225f, 0.3f);//C
glVertex2f (-0.475f, 0.3f);//D
glEnd ();
//soporte pizarra
glColor3f (0.6f, 0.3f, 0.2f);
glLineWidth(8);
glBegin (GL_LINES);
glVertex2f (-0.579f, 0.3f);//A
glVertex2f (-0.121f, 0.3f);//B
glEnd ();
/*PUERTA*/
glColor3f (0.6f, 0.4f, 0.3f);
glBegin (GL_POLYGON);
glVertex2f (0.1f,0.6f);//A
glVertex2f (0.25f, 0.6f);//B
glVertex2f (0.225f, 0.0f);//C
glVertex2f (0.1f, 0.1f);//D
glEnd ();
glColor3f (1.0f, 1.0f, 1.0f);
glLineWidth(5);
glBegin (GL_LINE_STRIP);
glVertex2f (0.1f, 0.1f);//D
glVertex2f (0.1f,0.6f);//A
glVertex2f (0.25f, 0.6f);//B
glVertex2f (0.225f, 0.0f);//C
glEnd ();
/*PUERTA ventana*/
glColor3f (0.1f, 0.7f, 0.7f);
glBegin (GL_POLYGON);
glPopMatrix ();
glVertex2f (0.125f,0.55f);//A
glVertex2f (0.217f, 0.55f);//B
glVertex2f (0.21f, 0.32f);//C
glVertex2f (0.125f, 0.35f);//D
glEnd ();
glColor3f (0.0f, 0.0f, 0.0f);
glLineWidth(3.5);
glBegin (GL_LINE_STRIP);
glVertex2f (0.125f,0.55f);//A
glVertex2f (0.125f, 0.35f);//D
glVertex2f (0.21f, 0.32f);//C
glEnd ();
//
/*PUERTA MANIJA*/
glColor3f (0.7f, 0.2f, 0.5f);
glPointSize(7);
glBegin (GL_POINTS);
glVertex2f (0.115f,0.3f);//A
glEnd ();
/*VENTANA*/
glColor3f (0.1f, 0.7f, 0.7f);
glBegin (GL_POLYGON);
glPopMatrix ();
glVertex2f (0.325f,0.7f);//A
glVertex2f (1.0f, 0.75f);//B
glVertex2f (1.0f, 0.15f);//C
glVertex2f (0.325f, 0.3f);//D
glEnd ();
glColor3f (1.0f, 1.0f, 1.0f);
glLineWidth(9);
glBegin (GL_LINE_LOOP);
glVertex2f (0.325f,0.7f);//A
glVertex2f (1.0f, 0.75f);//B
glVertex2f (1.0f, 0.15f);//C
glVertex2f (0.325f, 0.3f);//D
glEnd ();
glColor3f (0.0f, 0.0f, 0.0f);
glLineWidth(5);
glBegin (GL_LINES);
glVertex2f (0.475f,0.71f);//A
glVertex2f (0.475f,0.27f);//B
glVertex2f (0.65f, 0.72f);//A
glVertex2f (0.65f, 0.23f);//B
glVertex2f (0.825f,0.73f);//A
glVertex2f (0.825f,0.19f);//B
glEnd ();
glColor3f (0.0f, 0.0f, 0.0f);
glLineWidth(3);
//
glBegin (GL_LINE_LOOP);
glVertex2f (0.325f,0.7f);//A
glVertex2f (1.0f, 0.75f);//B
glVertex2f (1.0f, 0.15f);//C
glVertex2f (0.325f, 0.3f);//D
glEnd ();
glColor3f (0.6f, 0.4f, 0.3f);
glLineWidth(5);
glBegin (GL_LINES);
glVertex2f (0.325f,0.75f);//A
glVertex2f (0.99f, 0.83f);//B
glEnd ();
/*PINTURA*/
glColor3f (0.6f, 0.5f, 0.15f);
glBegin (GL_POLYGON);
glVertex2f (-0.95f,0.7f);//A
glVertex2f (-0.8f, 0.65f);//B
glVertex2f (-0.805f, 0.3f);//C
glVertex2f (-0.95f,0.15f);//D
glEnd ();
glColor3f (0.0f, 0.0f, 0.0f);
glLineWidth(4);
glBegin (GL_LINE_LOOP);
glVertex2f (-0.95f,0.7f);//A
glVertex2f (-0.8f, 0.65f);//B
glVertex2f (-0.805f, 0.3f);//C
glVertex2f (-0.95f,0.15f);//D
glEnd ();
//LINEAS PARED
glColor3f (0.0f, 0.0f, 0.0f);
glLineWidth(1);
glBegin (GL_LINES);
glVertex2f (-0.75f, 0.8f);//A
glVertex2f (-0.75f, 0.1f);//B
glVertex2f (0.1f, 0.8f);//A
//
glVertex2f (0.1f,0.6f);//B
glVertex2f (-0.75f, 0.1f);//A
glVertex2f (-1.0f,-0.6f);//B
glVertex2f (1.0f,-0.6f);//A
glVertex2f (0.1f, 0.1f);//B
glVertex2f (-0.75f, 0.8f);//A
glVertex2f (0.1f, 0.8f);//B
glVertex2f (0.1f, 0.1f);//A
glVertex2f (-0.75f, 0.1f);//B
glVertex2f (-1.0f, 1.0f);//A
glVertex2f (-0.75f, 0.8f);//D
glVertex2f (0.75f, 1.0f);//B
glVertex2f (0.1f, 0.8f);//C
glEnd ();
//escritorio
glColor3f (0.4f, 0.1f, 0.2f);
glBegin (GL_POLYGON);
glVertex2f (-0.65f, 0.27f);//A
glVertex2f (-0.58f, 0.27f);//B
glVertex2f (-0.58f, 0.21f);//C
glVertex2f (-0.65f,0.21f);//D
glEnd ();
glColor3f (0.6f, 0.4f, 0.3f);
glBegin (GL_POLYGON);
glVertex2f (-0.73f, 0.21f);//A
glVertex2f (-0.5f,0.21f);//B
glVertex2f (-0.5f, 0.05f);//C
glVertex2f (-0.73f, 0.05f);//d
glEnd ();
glColor3f (0.7f, 0.4f, 0.3f);
glLineWidth(8);
glBegin (GL_LINES);
glVertex2f (-0.74f, 0.21f);//A
glVertex2f (-0.49f,0.21f);//B
glEnd ();
//ESTANTE
//
glColor3f (0.6f, 0.4f, 0.3f);
glBegin (GL_POLYGON);
glVertex2f (-0.05f, 0.4f);//A
glVertex2f (0.075f,0.4f);//B
glVertex2f (0.075f,0.08f);//C
glVertex2f (-0.05f,0.08f);//d
glEnd ();
glColor3f (0.6f, 0.3f, 0.2f);
glLineWidth(5);
glBegin (GL_LINES);
glVertex2f (-0.05f, 0.3f);//A
glVertex2f (0.075f,0.3f);//B
glVertex2f (0.075f,0.23f);//A
glVertex2f (-0.05f,0.23f);//B
glVertex2f (0.075f,0.15f);//A
glVertex2f (-0.05f,0.15f);//B
glEnd ();
glColor3f (0.6f, 0.3f, 0.2f);
glLineWidth(5);
glBegin (GL_LINE_LOOP);
glVertex2f (-0.05f, 0.4f);//A
glVertex2f (0.075f,0.4f);//B
glVertex2f (0.075f,0.08f);//C
glVertex2f (-0.05f,0.08f);//d
glEnd ();
glPopMatrix ();
////////////////////// 1
//////////////////////////////////////////////////////////////////////////////////
glPushMatrix();
/*MESA*/
glTranslated(-0.15f,0.3f,0.0f);
glScaled(0.7f,0.7f,0.0f);
glColor3f (0.15f, 0.15f, 0.15f);
glLineWidth(5);
glBegin (GL_LINE_STRIP);
glVertex2f (-0.942f,-0.9f);//A
glVertex2f (-0.942f,-0.7f);//B
glVertex2f (-0.58f,-0.7f);//C
//
glVertex2f (-0.58f,-0.9f);//D
glEnd ();
glColor3f (0.15f, 0.15f, 0.15f);
glBegin (GL_LINES);
glVertex2f (-0.9f,-0.80f);//A
glVertex2f (-0.9f,-0.7f);//B
glVertex2f (-0.6f,-0.7f);//C
glVertex2f (-0.6f,-0.80f);//D
glEnd ();
glColor3f (0.6f, 0.3f, 0.2f);
glBegin (GL_POLYGON);
glVertex2f (-0.95f,-0.7f);//A
glVertex2f (-0.9f,-0.55f);//B
glVertex2f (-0.57f,-0.55f);//C
glVertex2f (-0.575f,-0.7f);//D
glEnd ();
/*SILLA*/
glColor3f (0.15f, 0.15f, 0.15f);
glBegin (GL_LINES);
glVertex2f (-0.86f,-0.85f);//A
glVertex2f (-0.86f,-0.91f);//B
glVertex2f (-0.79f,-0.85f);//C
glVertex2f (-0.79f,-0.91f);//D
glEnd ();
glColor3f (0.6f, 0.4f, 0.4f);
glBegin (GL_POLYGON);
glVertex2f (-0.88f,-0.76);//A
glVertex2f (-0.76f,-0.74f);//B
glVertex2f (-0.77f,-0.87f);//C
glVertex2f (-0.9f,-0.87f);//D
glEnd ();
glLineWidth(5);
glColor3f (0.15f, 0.15f, 0.15f);
glBegin (GL_LINES);
glVertex2f (-0.77f,-0.86f);//C
glVertex2f (-0.9f,-0.86f);//D
glEnd ();
glColor3f (0.2f, 0.2f, 0.2f);
glLineWidth(3);
//
glBegin (GL_LINE_STRIP);
glVertex2f (-0.775f,-0.605f);//B
glVertex2f (-0.775f,-0.755f);//C
glVertex2f (-0.9f,-0.755f);//D
glEnd ();
glColor3f (0.6f, 0.5f, 0.2f);
glBegin (GL_POLYGON);
glVertex2f (-0.9f,-0.6f);//A
glVertex2f (-0.775f,-0.6f);//B
glVertex2f (-0.775f,-0.75f);//C
glVertex2f (-0.9f,-0.75f);//D
glEnd ();
glLineWidth(5);
glColor3f (0.15f, 0.15f, 0.15f);
glBegin (GL_LINES);
glVertex2f (-0.87f,-0.7f);//A
glVertex2f (-0.87f,-0.95f);//B
glVertex2f (-0.81f,-0.7f);//C
glVertex2f (-0.81f,-0.95f);//D
glEnd ();
/*MONITOR*/
glColor3f (0.3f, 0.3f, 0.3f);
glBegin (GL_POLYGON);
glVertex2f (-0.85f,-0.35f);//A
glVertex2f (-0.65f,-0.35f);//B
glVertex2f (-0.65f,-0.53f);//C
glVertex2f (-0.85f,-0.53f);//D
glEnd ();
glColor3f (0.0f, 0.0f, 0.0f);
glLineWidth(4);
glBegin (GL_LINE_LOOP);
glVertex2f (-0.85f,-0.35f);//A
glVertex2f (-0.65f,-0.35f);//B
glVertex2f (-0.65f,-0.53f);//C
glVertex2f (-0.85f,-0.53f);//D
glEnd ();
glColor3f (0.0f, 0.0f, 0.0f);
//
glBegin (GL_POLYGON);
glVertex2f (-0.775f,-0.53f);//A
glVertex2f (-0.725f,-0.53f);//B
glVertex2f (-0.74f,-0.57f);//C
glVertex2f (-0.76f,-0.57f);//D
glEnd ();
glLineWidth(7);
glColor3f (0.0f, 0.0f, 0.0f);
glBegin (GL_LINES);
glVertex2f (-0.78f,-0.57f);//A
glVertex2f (-0.72f,-0.57f);//B
glEnd ();
glPopMatrix ();
///////////////////////// 2
///////////////////////////////////////////////////////////////////////////////////////////////
glPushMatrix();
/*MESA*/
glTranslated(-0.12f,0.15f,0.0f);
glScaled(0.8f,0.8f,0.0f);
glColor3f (0.15f, 0.15f, 0.15f);
glLineWidth(5);
glBegin (GL_LINE_STRIP);
glVertex2f (-0.942f,-0.9f);//A
glVertex2f (-0.942f,-0.7f);//B
glVertex2f (-0.58f,-0.7f);//C
glVertex2f (-0.58f,-0.9f);//D
glEnd ();
glColor3f (0.15f, 0.15f, 0.15f);
glBegin (GL_LINES);
glVertex2f (-0.9f,-0.80f);//A
glVertex2f (-0.9f,-0.7f);//B
glVertex2f (-0.6f,-0.7f);//C
glVertex2f (-0.6f,-0.80f);//D
glEnd ();
glColor3f (0.6f, 0.3f, 0.2f);
glBegin (GL_POLYGON);
glVertex2f (-0.95f,-0.7f);//A
//
glVertex2f (-0.9f,-0.55f);//B
glVertex2f (-0.57f,-0.55f);//C
glVertex2f (-0.575f,-0.7f);//D
glEnd ();
/*SILLA*/
glColor3f (0.15f, 0.15f, 0.15f);
glBegin (GL_LINES);
glVertex2f (-0.86f,-0.85f);//A
glVertex2f (-0.86f,-0.91f);//B
glVertex2f (-0.79f,-0.85f);//C
glVertex2f (-0.79f,-0.91f);//D
glEnd ();
glColor3f (0.6f, 0.4f, 0.4f);
glBegin (GL_POLYGON);
glVertex2f (-0.88f,-0.76);//A
glVertex2f (-0.76f,-0.74f);//B
glVertex2f (-0.77f,-0.87f);//C
glVertex2f (-0.9f,-0.87f);//D
glEnd ();
glLineWidth(5);
glColor3f (0.15f, 0.15f, 0.15f);
glBegin (GL_LINES);
glVertex2f (-0.77f,-0.86f);//C
glVertex2f (-0.9f,-0.86f);//D
glEnd ();
glColor3f (0.2f, 0.2f, 0.2f);
glLineWidth(3);
glBegin (GL_LINE_STRIP);
glVertex2f (-0.775f,-0.605f);//B
glVertex2f (-0.775f,-0.755f);//C
glVertex2f (-0.9f,-0.755f);//D
glEnd ();
glColor3f (0.6f, 0.5f, 0.2f);
glBegin (GL_POLYGON);
glVertex2f (-0.9f,-0.6f);//A
glVertex2f (-0.775f,-0.6f);//B
glVertex2f (-0.775f,-0.75f);//C
glVertex2f (-0.9f,-0.75f);//D
glEnd ();
//
glLineWidth(5);
glColor3f (0.15f, 0.15f, 0.15f);
glBegin (GL_LINES);
glVertex2f (-0.87f,-0.7f);//A
glVertex2f (-0.87f,-0.95f);//B
glVertex2f (-0.81f,-0.7f);//C
glVertex2f (-0.81f,-0.95f);//D
glEnd ();
/*MONITOR*/
glColor3f (0.3f, 0.3f, 0.3f);
glBegin (GL_POLYGON);
glVertex2f (-0.85f,-0.35f);//A
glVertex2f (-0.65f,-0.35f);//B
glVertex2f (-0.65f,-0.53f);//C
glVertex2f (-0.85f,-0.53f);//D
glEnd ();
glColor3f (0.0f, 0.0f, 0.0f);
glLineWidth(4);
glBegin (GL_LINE_LOOP);
glVertex2f (-0.85f,-0.35f);//A
glVertex2f (-0.65f,-0.35f);//B
glVertex2f (-0.65f,-0.53f);//C
glVertex2f (-0.85f,-0.53f);//D
glEnd ();
glColor3f (0.0f, 0.0f, 0.0f);
glBegin (GL_POLYGON);
glVertex2f (-0.775f,-0.53f);//A
glVertex2f (-0.725f,-0.53f);//B
glVertex2f (-0.74f,-0.57f);//C
glVertex2f (-0.76f,-0.57f);//D
glEnd ();
glLineWidth(7);
glColor3f (0.0f, 0.0f, 0.0f);
glBegin (GL_LINES);
glVertex2f (-0.78f,-0.57f);//A
glVertex2f (-0.72f,-0.57f);//B
//
glEnd ();
glPopMatrix ();
/////////////////////// 3
/////////////////////////////////////////////////////////////////////////////////////////////////
glPushMatrix();
/*MESA*/
glColor3f (0.15f, 0.15f, 0.15f);
glLineWidth(5);
glBegin (GL_LINE_STRIP);
glVertex2f (-0.942f,-0.9f);//A
glVertex2f (-0.942f,-0.7f);//B
glVertex2f (-0.58f,-0.7f);//C
glVertex2f (-0.58f,-0.9f);//D
glEnd ();
glColor3f (0.15f, 0.15f, 0.15f);
glBegin (GL_LINES);
glVertex2f (-0.9f,-0.80f);//A
glVertex2f (-0.9f,-0.7f);//B
glVertex2f (-0.6f,-0.7f);//C
glVertex2f (-0.6f,-0.80f);//D
glEnd ();
glColor3f (0.6f, 0.3f, 0.2f);
glBegin (GL_POLYGON);
glVertex2f (-0.95f,-0.7f);//A
glVertex2f (-0.9f,-0.55f);//B
glVertex2f (-0.57f,-0.55f);//C
glVertex2f (-0.575f,-0.7f);//D
glEnd ();
/*SILLA*/
glColor3f (0.15f, 0.15f, 0.15f);
glBegin (GL_LINES);
glVertex2f (-0.86f,-0.85f);//A
glVertex2f (-0.86f,-0.91f);//B
glVertex2f (-0.79f,-0.85f);//C
glVertex2f (-0.79f,-0.91f);//D
glEnd ();
glColor3f (0.6f, 0.4f, 0.4f);
glBegin (GL_POLYGON);
//
glVertex2f (-0.88f,-0.76);//A
glVertex2f (-0.76f,-0.74f);//B
glVertex2f (-0.77f,-0.87f);//C
glVertex2f (-0.9f,-0.87f);//D
glEnd ();
glLineWidth(5);
glColor3f (0.15f, 0.15f, 0.15f);
glBegin (GL_LINES);
glVertex2f (-0.77f,-0.86f);//C
glVertex2f (-0.9f,-0.86f);//D
glEnd ();
glColor3f (0.2f, 0.2f, 0.2f);
glLineWidth(3);
glBegin (GL_LINE_STRIP);
glVertex2f (-0.775f,-0.605f);//B
glVertex2f (-0.775f,-0.755f);//C
glVertex2f (-0.9f,-0.755f);//D
glEnd ();
glColor3f (0.6f, 0.5f, 0.2f);
glBegin (GL_POLYGON);
glVertex2f (-0.9f,-0.6f);//A
glVertex2f (-0.775f,-0.6f);//B
glVertex2f (-0.775f,-0.75f);//C
glVertex2f (-0.9f,-0.75f);//D
glEnd ();
glLineWidth(5);
glColor3f (0.15f, 0.15f, 0.15f);
glBegin (GL_LINES);
glVertex2f (-0.87f,-0.7f);//A
glVertex2f (-0.87f,-0.95f);//B
glVertex2f (-0.81f,-0.7f);//C
glVertex2f (-0.81f,-0.95f);//D
glEnd ();
/*MONITOR*/
glColor3f (0.3f, 0.3f, 0.3f);
glBegin (GL_POLYGON);
glVertex2f (-0.85f,-0.35f);//A
glVertex2f (-0.65f,-0.35f);//B
glVertex2f (-0.65f,-0.53f);//C
//
glVertex2f (-0.85f,-0.53f);//D
glEnd ();
glColor3f (0.0f, 0.0f, 0.0f);
glLineWidth(4);
glBegin (GL_LINE_LOOP);
glVertex2f (-0.85f,-0.35f);//A
glVertex2f (-0.65f,-0.35f);//B
glVertex2f (-0.65f,-0.53f);//C
glVertex2f (-0.85f,-0.53f);//D
glEnd ();
glColor3f (0.0f, 0.0f, 0.0f);
glBegin (GL_POLYGON);
glVertex2f (-0.775f,-0.53f);//A
glVertex2f (-0.725f,-0.53f);//B
glVertex2f (-0.74f,-0.57f);//C
glVertex2f (-0.76f,-0.57f);//D
glEnd ();
glLineWidth(7);
glColor3f (0.0f, 0.0f, 0.0f);
glBegin (GL_LINES);
glVertex2f (-0.78f,-0.57f);//A
glVertex2f (-0.72f,-0.57f);//B
glEnd ();
glPopMatrix ();
//////////////////// 4
//////////////////////////////////////////////////////////////////////////////
glPushMatrix();
glTranslated(0.34f,0.3f,0.0f);
glScaled(0.7f,0.7f,0.0f);
//MESA
glColor3f (0.15f, 0.15f, 0.15f);
glLineWidth(5);
glBegin (GL_LINE_STRIP);
glVertex2f (-0.942f,-0.9f);//A
glVertex2f (-0.942f,-0.7f);//B
glVertex2f (-0.58f,-0.7f);//C
//
glVertex2f (-0.58f,-0.9f);//D
glEnd ();
glColor3f (0.15f, 0.15f, 0.15f);
glBegin (GL_LINES);
glVertex2f (-0.955f,-0.55f);//A
glVertex2f (-0.955f,-0.8f);//B
glVertex2f (-0.64f,-0.7f);//C
glVertex2f (-0.64f,-0.80f);//D
glEnd ();
glColor3f (0.6f, 0.3f, 0.2f);
glBegin (GL_POLYGON);
glVertex2f (-0.95f,-0.7f);//A
glVertex2f (-0.96f,-0.55f);//B
glVertex2f (-0.62f,-0.55f);//C
glVertex2f (-0.575f,-0.7f);//D
glEnd ();
glTranslated(0.03f,0.0f,0.0f);
//SILLA
glColor3f (0.15f, 0.15f, 0.15f);
glBegin (GL_LINES);
glVertex2f (-0.89f,-0.79f);//A
glVertex2f (-0.89f,-0.91f);//B
glVertex2f (-0.795f,-0.85f);//C
glVertex2f (-0.795f,-0.91f);//D
glEnd ();
glColor3f (0.6f, 0.4f, 0.4f);
glBegin (GL_POLYGON);
glVertex2f (-0.91f,-0.76);//A
glVertex2f (-0.79f,-0.74f);//B
glVertex2f (-0.77f,-0.87f);//C
glVertex2f (-0.9f,-0.87f);//D
glEnd ();
glLineWidth(2);
glColor3f (0.15f, 0.15f, 0.15f);
glBegin (GL_LINES);
glVertex2f (-0.91f,-0.76);//A
glVertex2f (-0.905f,-0.86f);//D
glEnd ();
glLineWidth(5);
//
glBegin (GL_LINES);
glVertex2f (-0.905f,-0.86f);//
glVertex2f (-0.77f,-0.86f);//C
glEnd ();
glColor3f (0.2f, 0.2f, 0.2f);
glLineWidth(3);
glBegin (GL_LINE_STRIP);
glVertex2f (-0.775f,-0.605f);//B
glVertex2f (-0.775f,-0.755f);//C
glVertex2f (-0.9f,-0.755f);//D
glEnd ();
glColor3f (0.6f, 0.5f, 0.2f);
glBegin (GL_POLYGON);
glVertex2f (-0.9f,-0.6f);//A
glVertex2f (-0.775f,-0.6f);//B
glVertex2f (-0.775f,-0.75f);//C
glVertex2f (-0.9f,-0.75f);//D
glEnd ();
glLineWidth(5);
glColor3f (0.15f, 0.15f, 0.15f);
glBegin (GL_LINES);
glVertex2f (-0.87f,-0.7f);//A
glVertex2f (-0.87f,-0.95f);//B
glVertex2f (-0.81f,-0.7f);//C
glVertex2f (-0.81f,-0.95f);//D
glEnd ();
glTranslated(-0.03f,0.0f,0.0f);
//MONITOR
glColor3f (0.3f, 0.3f, 0.3f);
glBegin (GL_POLYGON);
glVertex2f (-0.85f,-0.35f);//A
glVertex2f (-0.65f,-0.35f);//B
glVertex2f (-0.65f,-0.53f);//C
glVertex2f (-0.85f,-0.53f);//D
glEnd ();
glColor3f (0.0f, 0.0f, 0.0f);
glLineWidth(4);
glBegin (GL_LINE_LOOP);
//
glVertex2f (-0.85f,-0.35f);//A
glVertex2f (-0.65f,-0.35f);//B
glVertex2f (-0.65f,-0.53f);//C
glVertex2f (-0.85f,-0.53f);//D
glEnd ();
glColor3f (0.0f, 0.0f, 0.0f);
glBegin (GL_POLYGON);
glVertex2f (-0.775f,-0.53f);//A
glVertex2f (-0.725f,-0.53f);//B
glVertex2f (-0.74f,-0.57f);//C
glVertex2f (-0.76f,-0.57f);//D
glEnd ();
glLineWidth(7);
glColor3f (0.0f, 0.0f, 0.0f);
glBegin (GL_LINES);
glVertex2f (-0.78f,-0.57f);//A
glVertex2f (-0.72f,-0.57f);//B
glEnd ();
glPopMatrix ();
//////////////////// 5
//////////////////////////////////////////////////////////////////////////////
glPushMatrix();
glTranslated(0.47f,0.15f,0.0f);
glScaled(0.8f,0.8f,0.8f);
//MESA
glColor3f (0.15f, 0.15f, 0.15f);
glLineWidth(5);
glBegin (GL_LINE_STRIP);
glVertex2f (-0.942f,-0.9f);//A
glVertex2f (-0.942f,-0.7f);//B
glVertex2f (-0.58f,-0.7f);//C
glVertex2f (-0.58f,-0.9f);//D
glEnd ();
glColor3f (0.15f, 0.15f, 0.15f);
glBegin (GL_LINES);
glVertex2f (-0.955f,-0.55f);//A
glVertex2f (-0.955f,-0.8f);//B
//
glVertex2f (-0.64f,-0.7f);//C
glVertex2f (-0.64f,-0.80f);//D
glEnd ();
glColor3f (0.6f, 0.3f, 0.2f);
glBegin (GL_POLYGON);
glVertex2f (-0.95f,-0.7f);//A
glVertex2f (-0.96f,-0.55f);//B
glVertex2f (-0.62f,-0.55f);//C
glVertex2f (-0.575f,-0.7f);//D
glEnd ();
glTranslated(0.03f,0.0f,0.0f);
//SILLA
glColor3f (0.15f, 0.15f, 0.15f);
glBegin (GL_LINES);
glVertex2f (-0.89f,-0.79f);//A
glVertex2f (-0.89f,-0.91f);//B
glVertex2f (-0.795f,-0.85f);//C
glVertex2f (-0.795f,-0.91f);//D
glEnd ();
glColor3f (0.6f, 0.4f, 0.4f);
glBegin (GL_POLYGON);
glVertex2f (-0.91f,-0.76);//A
glVertex2f (-0.79f,-0.74f);//B
glVertex2f (-0.77f,-0.87f);//C
glVertex2f (-0.9f,-0.87f);//D
glEnd ();
glLineWidth(2);
glColor3f (0.15f, 0.15f, 0.15f);
glBegin (GL_LINES);
glVertex2f (-0.91f,-0.76);//A
glVertex2f (-0.905f,-0.86f);//D
glEnd ();
glLineWidth(5);
glBegin (GL_LINES);
glVertex2f (-0.905f,-0.86f);//
glVertex2f (-0.77f,-0.86f);//C
glEnd ();
glColor3f (0.2f, 0.2f, 0.2f);
glLineWidth(3);
//
glBegin (GL_LINE_STRIP);
glVertex2f (-0.775f,-0.605f);//B
glVertex2f (-0.775f,-0.755f);//C
glVertex2f (-0.9f,-0.755f);//D
glEnd ();
glColor3f (0.6f, 0.5f, 0.2f);
glBegin (GL_POLYGON);
glVertex2f (-0.9f,-0.6f);//A
glVertex2f (-0.775f,-0.6f);//B
glVertex2f (-0.775f,-0.75f);//C
glVertex2f (-0.9f,-0.75f);//D
glEnd ();
glLineWidth(5);
glColor3f (0.15f, 0.15f, 0.15f);
glBegin (GL_LINES);
glVertex2f (-0.87f,-0.7f);//A
glVertex2f (-0.87f,-0.95f);//B
glVertex2f (-0.81f,-0.7f);//C
glVertex2f (-0.81f,-0.95f);//D
glEnd ();
glTranslated(-0.03f,0.0f,0.0f);
//MONITOR
glColor3f (0.3f, 0.3f, 0.3f);
glBegin (GL_POLYGON);
glVertex2f (-0.85f,-0.35f);//A
glVertex2f (-0.65f,-0.35f);//B
glVertex2f (-0.65f,-0.53f);//C
glVertex2f (-0.85f,-0.53f);//D
glEnd ();
glColor3f (0.0f, 0.0f, 0.0f);
glLineWidth(4);
glBegin (GL_LINE_LOOP);
glVertex2f (-0.85f,-0.35f);//A
glVertex2f (-0.65f,-0.35f);//B
glVertex2f (-0.65f,-0.53f);//C
glVertex2f (-0.85f,-0.53f);//D
glEnd ();
//
glColor3f (0.0f, 0.0f, 0.0f);
glBegin (GL_POLYGON);
glVertex2f (-0.775f,-0.53f);//A
glVertex2f (-0.725f,-0.53f);//B
glVertex2f (-0.74f,-0.57f);//C
glVertex2f (-0.76f,-0.57f);//D
glEnd ();
glLineWidth(7);
glColor3f (0.0f, 0.0f, 0.0f);
glBegin (GL_LINES);
glVertex2f (-0.78f,-0.57f);//A
glVertex2f (-0.72f,-0.57f);//B
glEnd ();
glPopMatrix ();
////////////////// 6
//////////////////////////////////////////////////////////////////////////////////////////////////////
glPushMatrix();
glTranslated(0.7f,0.0f,0.0f);
//MESA
glColor3f (0.15f, 0.15f, 0.15f);
glLineWidth(5);
glBegin (GL_LINE_STRIP);
glVertex2f (-0.942f,-0.9f);//A
glVertex2f (-0.942f,-0.7f);//B
glVertex2f (-0.58f,-0.7f);//C
glVertex2f (-0.58f,-0.9f);//D
glEnd ();
glColor3f (0.15f, 0.15f, 0.15f);
glBegin (GL_LINES);
glVertex2f (-0.955f,-0.55f);//A
glVertex2f (-0.955f,-0.8f);//B
glVertex2f (-0.64f,-0.7f);//C
glVertex2f (-0.64f,-0.80f);//D
glEnd ();
glColor3f (0.6f, 0.3f, 0.2f);
glBegin (GL_POLYGON);
glVertex2f (-0.95f,-0.7f);//A
glVertex2f (-0.96f,-0.55f);//B
//
glVertex2f (-0.62f,-0.55f);//C
glVertex2f (-0.575f,-0.7f);//D
glEnd ();
glTranslated(0.03f,0.0f,0.0f);
//SILLA
glColor3f (0.15f, 0.15f, 0.15f);
glBegin (GL_LINES);
glVertex2f (-0.89f,-0.79f);//A
glVertex2f (-0.89f,-0.91f);//B
glVertex2f (-0.795f,-0.85f);//C
glVertex2f (-0.795f,-0.91f);//D
glEnd ();
glColor3f (0.6f, 0.4f, 0.4f);
glBegin (GL_POLYGON);
glVertex2f (-0.91f,-0.76);//A
glVertex2f (-0.79f,-0.74f);//B
glVertex2f (-0.77f,-0.87f);//C
glVertex2f (-0.9f,-0.87f);//D
glEnd ();
glLineWidth(2);
glColor3f (0.15f, 0.15f, 0.15f);
glBegin (GL_LINES);
glVertex2f (-0.91f,-0.76);//A
glVertex2f (-0.905f,-0.86f);//D
glEnd ();
glLineWidth(5);
glBegin (GL_LINES);
glVertex2f (-0.905f,-0.86f);//
glVertex2f (-0.77f,-0.86f);//C
glEnd ();
glColor3f (0.2f, 0.2f, 0.2f);
glLineWidth(3);
glBegin (GL_LINE_STRIP);
glVertex2f (-0.775f,-0.605f);//B
glVertex2f (-0.775f,-0.755f);//C
glVertex2f (-0.9f,-0.755f);//D
glEnd ();
glColor3f (0.6f, 0.5f, 0.2f);
glBegin (GL_POLYGON);
//
glVertex2f (-0.9f,-0.6f);//A
glVertex2f (-0.775f,-0.6f);//B
glVertex2f (-0.775f,-0.75f);//C
glVertex2f (-0.9f,-0.75f);//D
glEnd ();
glLineWidth(5);
glColor3f (0.15f, 0.15f, 0.15f);
glBegin (GL_LINES);
glVertex2f (-0.87f,-0.7f);//A
glVertex2f (-0.87f,-0.95f);//B
glVertex2f (-0.81f,-0.7f);//C
glVertex2f (-0.81f,-0.95f);//D
glEnd ();
glTranslated(-0.03f,0.0f,0.0f);
//MONITOR
glColor3f (0.3f, 0.3f, 0.3f);
glBegin (GL_POLYGON);
glVertex2f (-0.85f,-0.35f);//A
glVertex2f (-0.65f,-0.35f);//B
glVertex2f (-0.65f,-0.53f);//C
glVertex2f (-0.85f,-0.53f);//D
glEnd ();
glColor3f (0.0f, 0.0f, 0.0f);
glLineWidth(4);
glBegin (GL_LINE_LOOP);
glVertex2f (-0.85f,-0.35f);//A
glVertex2f (-0.65f,-0.35f);//B
glVertex2f (-0.65f,-0.53f);//C
glVertex2f (-0.85f,-0.53f);//D
glEnd ();
glColor3f (0.0f, 0.0f, 0.0f);
glBegin (GL_POLYGON);
glVertex2f (-0.775f,-0.53f);//A
glVertex2f (-0.725f,-0.53f);//B
glVertex2f (-0.74f,-0.57f);//C
glVertex2f (-0.76f,-0.57f);//D
glEnd ();
//
glLineWidth(7);
glColor3f (0.0f, 0.0f, 0.0f);
glBegin (GL_LINES);
glVertex2f (-0.78f,-0.57f);//A
glVertex2f (-0.72f,-0.57f);//B
glEnd ();
glPopMatrix ();
////////////////// 7
//////////////////////////////////////////////////////////////////////////////////////////////////////
glPushMatrix();
glTranslated(0.78f,0.3f,0.0f);
glScaled(0.7f,0.7f,0.0f);
//MESA
glColor3f (0.15f, 0.15f, 0.15f);
glLineWidth(5);
glBegin (GL_LINE_STRIP);
glVertex2f (-0.942f,-0.9f);//A
glVertex2f (-0.942f,-0.7f);//B
glVertex2f (-0.58f,-0.7f);//C
glVertex2f (-0.58f,-0.9f);//D
glEnd ();
glColor3f (0.15f, 0.15f, 0.15f);
glBegin (GL_LINES);
glVertex2f (-1.01f,-0.55f);//A
glVertex2f (-1.01f,-0.8f);//B
glVertex2f (-0.705f,-0.7f);//C
glVertex2f (-0.705f,-0.80f);//D
glEnd ();
glColor3f (0.6f, 0.3f, 0.2f);
glBegin (GL_POLYGON);
glVertex2f (-0.95f,-0.7f);//A
glVertex2f (-1.02f,-0.55f);//B
glVertex2f (-0.7f,-0.55f);//C
glVertex2f (-0.575f,-0.7f);//D
glEnd ();
glTranslated(0.05f,0.0f,0.0f);
//SILLA
//
glColor3f (0.15f, 0.15f, 0.15f);
glBegin (GL_LINES);
glVertex2f (-0.89f,-0.79f);//A
glVertex2f (-0.89f,-0.91f);//B
glVertex2f (-0.795f,-0.85f);//C
glVertex2f (-0.795f,-0.91f);//D
glEnd ();
glColor3f (0.6f, 0.4f, 0.4f);
glBegin (GL_POLYGON);
glVertex2f (-0.91f,-0.76);//A
glVertex2f (-0.79f,-0.74f);//B
glVertex2f (-0.77f,-0.87f);//C
glVertex2f (-0.9f,-0.87f);//D
glEnd ();
glLineWidth(2);
glColor3f (0.15f, 0.15f, 0.15f);
glBegin (GL_LINES);
glVertex2f (-0.91f,-0.76);//A
glVertex2f (-0.905f,-0.86f);//D
glEnd ();
glLineWidth(5);
glBegin (GL_LINES);
glVertex2f (-0.905f,-0.86f);//
glVertex2f (-0.77f,-0.86f);//C
glEnd ();
glColor3f (0.2f, 0.2f, 0.2f);
glLineWidth(3);
glBegin (GL_LINE_STRIP);
glVertex2f (-0.775f,-0.605f);//B
glVertex2f (-0.775f,-0.755f);//C
glVertex2f (-0.9f,-0.755f);//D
glEnd ();
glColor3f (0.6f, 0.5f, 0.2f);
glBegin (GL_POLYGON);
glVertex2f (-0.9f,-0.6f);//A
glVertex2f (-0.775f,-0.6f);//B
glVertex2f (-0.775f,-0.75f);//C
glVertex2f (-0.9f,-0.75f);//D
glEnd ();
glLineWidth(5);
//
glColor3f (0.15f, 0.15f, 0.15f);
glBegin (GL_LINES);
glVertex2f (-0.87f,-0.7f);//A
glVertex2f (-0.87f,-0.95f);//B
glVertex2f (-0.81f,-0.7f);//C
glVertex2f (-0.81f,-0.95f);//D
glEnd ();
glTranslated(-0.11f,0.0f,0.0f);
//MONITOR
glColor3f (0.3f, 0.3f, 0.3f);
glBegin (GL_POLYGON);
glVertex2f (-0.85f,-0.35f);//A
glVertex2f (-0.65f,-0.35f);//B
glVertex2f (-0.65f,-0.53f);//C
glVertex2f (-0.85f,-0.53f);//D
glEnd ();
glColor3f (0.0f, 0.0f, 0.0f);
glLineWidth(4);
glBegin (GL_LINE_LOOP);
glVertex2f (-0.85f,-0.35f);//A
glVertex2f (-0.65f,-0.35f);//B
glVertex2f (-0.65f,-0.53f);//C
glVertex2f (-0.85f,-0.53f);//D
glEnd ();
glColor3f (0.0f, 0.0f, 0.0f);
glBegin (GL_POLYGON);
glVertex2f (-0.775f,-0.53f);//A
glVertex2f (-0.725f,-0.53f);//B
glVertex2f (-0.74f,-0.57f);//C
glVertex2f (-0.76f,-0.57f);//D
glEnd ();
glLineWidth(7);
glColor3f (0.0f, 0.0f, 0.0f);
glBegin (GL_LINES);
glVertex2f (-0.78f,-0.57f);//A
glVertex2f (-0.72f,-0.57f);//B
//
glEnd ();
glPopMatrix ();
////////////////// 8
//////////////////////////////////////////////////////////////////////////////////////////////////////
glPushMatrix();
glTranslated(1.0f,0.15f,0.0f);
glScaled(0.8f,0.8f,0.8f);
//MESA
glColor3f (0.15f, 0.15f, 0.15f);
glLineWidth(5);
glBegin (GL_LINE_STRIP);
glVertex2f (-0.942f,-0.9f);//A
glVertex2f (-0.942f,-0.7f);//B
glVertex2f (-0.58f,-0.7f);//C
glVertex2f (-0.58f,-0.9f);//D
glEnd ();
glColor3f (0.15f, 0.15f, 0.15f);
glBegin (GL_LINES);
glVertex2f (-1.01f,-0.55f);//A
glVertex2f (-1.01f,-0.8f);//B
glVertex2f (-0.705f,-0.7f);//C
glVertex2f (-0.705f,-0.80f);//D
glEnd ();
glColor3f (0.6f, 0.3f, 0.2f);
glBegin (GL_POLYGON);
glVertex2f (-0.95f,-0.7f);//A
glVertex2f (-1.02f,-0.55f);//B
glVertex2f (-0.7f,-0.55f);//C
glVertex2f (-0.575f,-0.7f);//D
glEnd ();
glTranslated(0.05f,0.0f,0.0f);
//SILLA
glColor3f (0.15f, 0.15f, 0.15f);
glBegin (GL_LINES);
glVertex2f (-0.89f,-0.79f);//A
glVertex2f (-0.89f,-0.91f);//B
glVertex2f (-0.795f,-0.85f);//C
glVertex2f (-0.795f,-0.91f);//D
//
glEnd ();
glColor3f (0.6f, 0.4f, 0.4f);
glBegin (GL_POLYGON);
glVertex2f (-0.91f,-0.76);//A
glVertex2f (-0.79f,-0.74f);//B
glVertex2f (-0.77f,-0.87f);//C
glVertex2f (-0.9f,-0.87f);//D
glEnd ();
glLineWidth(2);
glColor3f (0.15f, 0.15f, 0.15f);
glBegin (GL_LINES);
glVertex2f (-0.91f,-0.76);//A
glVertex2f (-0.905f,-0.86f);//D
glEnd ();
glLineWidth(5);
glBegin (GL_LINES);
glVertex2f (-0.905f,-0.86f);//
glVertex2f (-0.77f,-0.86f);//C
glEnd ();
glColor3f (0.2f, 0.2f, 0.2f);
glLineWidth(3);
glBegin (GL_LINE_STRIP);
glVertex2f (-0.775f,-0.605f);//B
glVertex2f (-0.775f,-0.755f);//C
glVertex2f (-0.9f,-0.755f);//D
glEnd ();
glColor3f (0.6f, 0.5f, 0.2f);
glBegin (GL_POLYGON);
glVertex2f (-0.9f,-0.6f);//A
glVertex2f (-0.775f,-0.6f);//B
glVertex2f (-0.775f,-0.75f);//C
glVertex2f (-0.9f,-0.75f);//D
glEnd ();
glLineWidth(5);
glColor3f (0.15f, 0.15f, 0.15f);
glBegin (GL_LINES);
glVertex2f (-0.87f,-0.7f);//A
glVertex2f (-0.87f,-0.95f);//B
glVertex2f (-0.81f,-0.7f);//C
glVertex2f (-0.81f,-0.95f);//D
//
glEnd ();
glTranslated(-0.11f,0.0f,0.0f);
//MONITOR
glColor3f (0.3f, 0.3f, 0.3f);
glBegin (GL_POLYGON);
glVertex2f (-0.85f,-0.35f);//A
glVertex2f (-0.65f,-0.35f);//B
glVertex2f (-0.65f,-0.53f);//C
glVertex2f (-0.85f,-0.53f);//D
glEnd ();
glColor3f (0.0f, 0.0f, 0.0f);
glLineWidth(4);
glBegin (GL_LINE_LOOP);
glVertex2f (-0.85f,-0.35f);//A
glVertex2f (-0.65f,-0.35f);//B
glVertex2f (-0.65f,-0.53f);//C
glVertex2f (-0.85f,-0.53f);//D
glEnd ();
glColor3f (0.0f, 0.0f, 0.0f);
glBegin (GL_POLYGON);
glVertex2f (-0.775f,-0.53f);//A
glVertex2f (-0.725f,-0.53f);//B
glVertex2f (-0.74f,-0.57f);//C
glVertex2f (-0.76f,-0.57f);//D
glEnd ();
glLineWidth(7);
glColor3f (0.0f, 0.0f, 0.0f);
glBegin (GL_LINES);
glVertex2f (-0.78f,-0.57f);//A
glVertex2f (-0.72f,-0.57f);//B
glEnd ();
glPopMatrix ();
////////////////// 9
//////////////////////////////////////////////////////////////////////////////////////////////////////
glPushMatrix();
//
glTranslated(1.4f,0.0f,0.0f);
//MESA
glColor3f (0.15f, 0.15f, 0.15f);
glLineWidth(5);
glBegin (GL_LINE_STRIP);
glVertex2f (-0.942f,-0.9f);//A
glVertex2f (-0.942f,-0.7f);//B
glVertex2f (-0.58f,-0.7f);//C
glVertex2f (-0.58f,-0.9f);//D
glEnd ();
glColor3f (0.15f, 0.15f, 0.15f);
glBegin (GL_LINES);
glVertex2f (-1.01f,-0.55f);//A
glVertex2f (-1.01f,-0.8f);//B
glVertex2f (-0.705f,-0.7f);//C
glVertex2f (-0.705f,-0.80f);//D
glEnd ();
glColor3f (0.6f, 0.3f, 0.2f);
glBegin (GL_POLYGON);
glVertex2f (-0.95f,-0.7f);//A
glVertex2f (-1.02f,-0.55f);//B
glVertex2f (-0.7f,-0.55f);//C
glVertex2f (-0.575f,-0.7f);//D
glEnd ();
glTranslated(0.05f,0.0f,0.0f);
//SILLA
glColor3f (0.15f, 0.15f, 0.15f);
glBegin (GL_LINES);
glVertex2f (-0.89f,-0.79f);//A
glVertex2f (-0.89f,-0.91f);//B
glVertex2f (-0.795f,-0.85f);//C
glVertex2f (-0.795f,-0.91f);//D
glEnd ();
glColor3f (0.6f, 0.4f, 0.4f);
glBegin (GL_POLYGON);
glVertex2f (-0.91f,-0.76);//A
glVertex2f (-0.79f,-0.74f);//B
glVertex2f (-0.77f,-0.87f);//C
glVertex2f (-0.9f,-0.87f);//D
//
glEnd ();
glLineWidth(2);
glColor3f (0.15f, 0.15f, 0.15f);
glBegin (GL_LINES);
glVertex2f (-0.91f,-0.76);//A
glVertex2f (-0.905f,-0.86f);//D
glEnd ();
glLineWidth(5);
glBegin (GL_LINES);
glVertex2f (-0.905f,-0.86f);//
glVertex2f (-0.77f,-0.86f);//C
glEnd ();
glColor3f (0.2f, 0.2f, 0.2f);
glLineWidth(3);
glBegin (GL_LINE_STRIP);
glVertex2f (-0.775f,-0.605f);//B
glVertex2f (-0.775f,-0.755f);//C
glVertex2f (-0.9f,-0.755f);//D
glEnd ();
glColor3f (0.6f, 0.5f, 0.2f);
glBegin (GL_POLYGON);
glVertex2f (-0.9f,-0.6f);//A
glVertex2f (-0.775f,-0.6f);//B
glVertex2f (-0.775f,-0.75f);//C
glVertex2f (-0.9f,-0.75f);//D
glEnd ();
glLineWidth(5);
glColor3f (0.15f, 0.15f, 0.15f);
glBegin (GL_LINES);
glVertex2f (-0.87f,-0.7f);//A
glVertex2f (-0.87f,-0.95f);//B
glVertex2f (-0.81f,-0.7f);//C
glVertex2f (-0.81f,-0.95f);//D
glEnd ();
glTranslated(-0.11f,0.0f,0.0f);
//MONITOR
glColor3f (0.3f, 0.3f, 0.3f);
glBegin (GL_POLYGON);
glVertex2f (-0.85f,-0.35f);//A
//
glVertex2f (-0.65f,-0.35f);//B
glVertex2f (-0.65f,-0.53f);//C
glVertex2f (-0.85f,-0.53f);//D
glEnd ();
glColor3f (0.0f, 0.0f, 0.0f);
glLineWidth(4);
glBegin (GL_LINE_LOOP);
glVertex2f (-0.85f,-0.35f);//A
glVertex2f (-0.65f,-0.35f);//B
glVertex2f (-0.65f,-0.53f);//C
glVertex2f (-0.85f,-0.53f);//D
glEnd ();
glColor3f (0.0f, 0.0f, 0.0f);
glBegin (GL_POLYGON);
glVertex2f (-0.775f,-0.53f);//A
glVertex2f (-0.725f,-0.53f);//B
glVertex2f (-0.74f,-0.57f);//C
glVertex2f (-0.76f,-0.57f);//D
glEnd ();
glLineWidth(7);
glColor3f (0.0f, 0.0f, 0.0f);
glBegin (GL_LINES);
glVertex2f (-0.78f,-0.57f);//A
glVertex2f (-0.72f,-0.57f);//B
glEnd ();
glPopMatrix ();
//cuadros pared
glPushMatrix ();
glColor3f (0.5f, 0.6f, 0.5f);
glBegin (GL_POLYGON);
glVertex2f (-0.525f,0.75f);//A
glVertex2f (-0.475f,0.75f);//B
glVertex2f (-0.48f,0.65f);//C
glVertex2f (-0.52f,0.65f);//D
glEnd ();
glColor3f (0.0f, 0.0f, 0.0f);
//
glLineWidth(2);
glBegin (GL_LINE_LOOP);
glVertex2f (-0.525f,0.75f);//A
glVertex2f (-0.475f,0.75f);//B
glVertex2f (-0.48f,0.65f);//C
glVertex2f (-0.52f,0.65f);//D
glEnd ();
glPopMatrix ();
glPushMatrix ();
glTranslated(-0.11f,0.0f,0.0f);
glColor3f (0.7f, 0.2f, 0.5f);
glBegin (GL_POLYGON);
glVertex2f (-0.525f,0.75f);//A
glVertex2f (-0.475f,0.75f);//B
glVertex2f (-0.48f,0.65f);//C
glVertex2f (-0.52f,0.65f);//D
glEnd ();
glColor3f (0.0f, 0.0f, 0.0f);
glLineWidth(2);
glBegin (GL_LINE_LOOP);
glVertex2f (-0.525f,0.75f);//A
glVertex2f (-0.475f,0.75f);//B
glVertex2f (-0.48f,0.65f);//C
glVertex2f (-0.52f,0.65f);//D
glEnd ();
glPopMatrix ();
glPushMatrix ();
glTranslated(0.5f,0.0f,0.0f);
glColor3f (0.4f, 0.6f, 0.9f);
glBegin (GL_POLYGON);
glVertex2f (-0.525f,0.75f);//A
glVertex2f (-0.475f,0.75f);//B
glVertex2f (-0.48f,0.65f);//C
glVertex2f (-0.52f,0.65f);//D
glEnd ();
glColor3f (0.0f, 0.0f, 0.0f);
glLineWidth(2);
glBegin (GL_LINE_LOOP);
//
glVertex2f (-0.525f,0.75f);//A
glVertex2f (-0.475f,0.75f);//B
glVertex2f (-0.48f,0.65f);//C
glVertex2f (-0.52f,0.65f);//D
glEnd ();
glPopMatrix ();
glFlush();
glutSwapBuffers();
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitWindowSize(1200, 700);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutCreateWindow("The glut hello world program");
    glutDisplayFunc(display);
    glClearColor(0.0, 0.0, 0.0, 1.0);
    glutMainLoop(); // Infinite event loop
    return 0;
}