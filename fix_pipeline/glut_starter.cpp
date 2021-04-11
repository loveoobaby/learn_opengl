//
//  main.cpp
//  pro2
//
//  Created by yingyingzhu on 2019/8/20.
//  Copyright © 2019 yingyingzhu. All rights reserved.
//
 
#include <iostream>
#include <GLUT/GLUT.h>
 
#define WINDOW_HEIGHT 300
#define WINDOW_WIDTH 500

GLfloat G_fDistance = 3.6f;
GLfloat G_fAngle_horizon = 0.0f;
GLfloat G_fAngle_vertical = 0.0f;

////////////////////////////////////////////////
void myinit(void);
void myReshape(GLsizei w, GLsizei h);
void display(void);


void processSpecialKeys(int key, int x, int y);
void processNormalKeys(unsigned char key,int x,int y);



int main(int argc, char* argv[])
{
	glutInit(&argc, argv);


	glutInitDisplayMode (GLUT_DOUBLE | GLUT_RGBA);

	glutInitWindowSize (500, 500); 
	glutInitWindowPosition (100, 100);

	glutCreateWindow ("OpenGL");

    myinit();

	glutReshapeFunc(myReshape);

	glutSpecialFunc(processSpecialKeys);
	glutKeyboardFunc(processNormalKeys);
	

	glutDisplayFunc(display); 

	glutIdleFunc(display);

	glutMainLoop();

	return 0;
}


void myinit(void)
{
    //your initialization code
	glEnable(GL_DEPTH_TEST);

//	glEnable(GL_ALPHA_TEST);
//	glAlphaFunc( GL_GREATER, 0.5f );
//	GLfloat a = 0.0f;
}


void myReshape(GLsizei w, GLsizei h)
{

    glViewport(0, 0, w, h);
	
    glMatrixMode(GL_PROJECTION);
   glLoadIdentity();
	gluPerspective(60.0, 1.0*(GLfloat)w/(GLfloat)h, 1.0, 30.0);
//	gluPerspective(60.0, 1.0, 1.0, 30.0);	//�������ڱ���ʱ��������
//  glFrustum (-1.0, 1.0, -1.0, 1.0, 1.0, 30.0);
}

void display(void)
{
    glClearColor(0.0f,0.0f,0.0f,0.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

//	glEnable(GL_ALPHA_TEST);
//	glAlphaFunc(GL_LESS, 0.5f);

    glMatrixMode(GL_MODELVIEW);

    glLoadIdentity();

    glTranslatef(0.0, 0.0, -G_fDistance);
	glRotatef(G_fAngle_horizon, 0.0f, 1.0f, 0.0f);
	glRotatef(G_fAngle_vertical, 1.0f, 0.0f, 0.0f);


	glColor4f(1.0f, 0.0f, 0.0f, 0.0f);
//	glColor3ub(255, 0, 255);
	glBegin(GL_QUADS);
		glVertex3f (-1.0, -1.0f, 0.0f);
		glVertex3f (1.0, -1.0f, 0.0f);
		glVertex3f (1.0, 1.0f, 0.0f);
		glVertex3f (-1.0, 1.0f, 0.0f);
	glEnd();

	glColor4f(0.0f, 1.0f, 0.0f, 1.0f);
	glutWireTeapot(1.0);
//	glutSolidTeapot(1.0);


	glutSwapBuffers();
//	glFlush();
}


void processSpecialKeys(int key, int x, int y)
{
	switch(key) {
		case GLUT_KEY_LEFT:
			G_fAngle_horizon -= 5.0f;
			break;
		case GLUT_KEY_RIGHT:
			G_fAngle_horizon += 5.0f;
			break;
		case GLUT_KEY_UP:
			G_fAngle_vertical -= 5.0f;
			break;
		case GLUT_KEY_DOWN:
			G_fAngle_vertical += 5.0f;
			break;
	}
//	glutPostRedisplay();
}

void processNormalKeys(unsigned char key,int x,int y)
{
	switch(key) {
		case 97:	//"a"
			G_fDistance -= 0.3f;
			break;
		case 65:		//"A"
			G_fDistance += 0.3f;
			break;
		case 27:	//"esc"
			exit(0);
	}
//	glutPostRedisplay();
}


