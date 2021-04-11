
#include <iostream>
#include <GLUT/glut.h>

#define WINDOW_HEIGHT 300
#define WINDOW_WIDTH 500


GLfloat G_fDistance = 3.6f;
GLfloat G_fAngle_horizon = 0.0f;
GLfloat G_fAngle_vertical = 0.0f;

void myReshape(GLsizei w, GLsizei h)
{
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
	gluPerspective(60.0, 1.0*(GLfloat)w/(GLfloat)h, 1.0, 30.0);
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

void display(void)
{
    glClearColor(0.0f,0.0f,0.0f,0.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glMatrixMode(GL_MODELVIEW);

    glLoadIdentity();

    glTranslatef(0.0, 0.0, -G_fDistance);
	glRotatef(G_fAngle_horizon, 0.0f, 1.0f, 0.0f);
	glRotatef(G_fAngle_vertical, 1.0f, 0.0f, 0.0f);

	glColor4f(1.0f, 0.0f, 0.0f, 0.0f);
	glBegin(GL_QUADS);
		glVertex3f (-1.0, -1.0f, 0.0f);
		glVertex3f (1.0, -1.0f, 0.0f);
		glVertex3f (1.0, 1.0f, 0.0f);
		glVertex3f (-1.0, 1.0f, 0.0f);
	glEnd();

	glColor4f(0.0f, 1.0f, 0.0f, 1.0f);
	// glutWireTeapot(1.0);
    glutSolidSphere(1, 100, 100);
//	glutSolidTeapot(1.0);

	glutSwapBuffers();
//	glFlush();
}

int main(int argc, char* argv[]) {
    // 对GLUT进行初始化，并处理所有对命令行参数
    glutInit(&argc, argv);
    // 指定使用RGBA颜色模式和双缓存窗口
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
    // 指定窗口创建时对宽高
    glutInitWindowSize(WINDOW_WIDTH, WINDOW_HEIGHT);
    // 创建一个窗口并指定标题
    glutCreateWindow("Solar System");

	glutReshapeFunc(myReshape);

	glutSpecialFunc(processSpecialKeys);
	glutKeyboardFunc(processNormalKeys);
	
	glutDisplayFunc(display); 

	glutIdleFunc(display);

	glutMainLoop();
    return 0;
}