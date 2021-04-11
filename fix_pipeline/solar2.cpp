
#include <stdlib.h>
#include <GLUT/GLUT.h>
#include <chrono>
#include <thread>

static int year0 = 0 ,year1 = 0,year2=0, year3=0,year4=0,day = 0;
 
void display(void)
{
	GLfloat mat_specular[] = { 1.0, 1.0, 1.0, 1.0 };//镜面光颜色白色
	GLfloat mat_shininess[] = { 200.0 };//粗糙程度
	GLfloat light_position[] = { 0.0, 0.0, 5.0, 0.0 };//光源位置，第四个参数为0，表示光源为无限远处，eg：太阳光
	GLfloat mat_emission[] = { 0.2,0.0,0.0,0.2};//sun微微发红光
	GLfloat white_light[] = { 1.0, 1.0, 1.0, 0.1 };
	GLfloat Light_Model_Ambient[] = { 0.2 , 0.2 , 0.2 , 1.0 }; //环境光
	glClearColor (0.0, 0.0, 0.0, 0.0);//窗口背景色为白色
	glShadeModel (GL_SMOOTH);//渐变色
	glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);//镜面
	glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);//粗糙
	glMaterialfv(GL_FRONT, GL_EMISSION, mat_emission);//使太阳微微发出红光。会照射在其他球体上
	//glLight 函数主要作用是设置光源，该函数有四种形式glLightf、glLighti、glLightfv、glLightiv
	glLightfv(GL_LIGHT0, GL_POSITION, light_position);//第一个参数表示设置哪个光源，第二个表示哪个光源的哪个属性，第三个表示把属性设置成多少
	glLightfv(GL_LIGHT0, GL_DIFFUSE, white_light);//漫
	glLightfv(GL_LIGHT0, GL_SPECULAR, white_light);//镜面
	glLightModelfv( GL_LIGHT_MODEL_AMBIENT , Light_Model_Ambient ); 
	glLightModeli( GL_FRONT, GL_AMBIENT_AND_DIFFUSE );
	glEnable( GL_COLOR_MATERIAL );
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glEnable(GL_DEPTH_TEST);//光照测试

	glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	//GL_DEPTH_BUFFER_BIT不会把原先绘制的图形删掉，近的的看见，远的被遮住
	glColor3f (1.0, 1.0, 1.0);

		glPushMatrix();		
		glColor4f(1.0,1.0,1.0,1.0);		
		glutSolidTorus(0.001,1.14,30,100);//木星轨道	
		glPopMatrix();

		glPushMatrix();		
		glColor4f(1.0,1.0,1.0,1.0);		
		glutSolidTorus(0.001,1.8,30,100);//地球轨道	
		glPopMatrix();

		glPushMatrix();		
		glColor4f(1.0,1.0,1.0,1.0);		
		glutSolidTorus(0.001,2.47,30,100);//火星轨道	
		glPopMatrix();


		glPushMatrix();		
		glColor4f(1.0,1.0,1.0,1.0);		
		glutSolidTorus(0.001,3.78,30,100);//木星轨道	
		glPopMatrix();

	glPushMatrix();
	day = (day + 5) % 360;
//	year0 = (year0 + 0) % 360;//太阳速度
	year1 = (year1 + 13) % 360;//水星速度
	year2 = (year2 + 6)% 360;//地球速度
	year3 = (year3 + 3)% 360;//火星速度
	year4 = (year4 + 1)% 360;//木星速度
	
//	glRotatef ((GLfloat) year0, 0.0, 0.0, 1.0);
	glColor3f(1.0,0.0,0.0);
	glutSolidSphere(0.95, 30, 30); //太阳
 
	
	glPopMatrix();
	glPushMatrix();
	glRotatef ((GLfloat) year1, 0.0, 0.0, 1.0);
	glTranslatef (0.0, 1.14, 0.0);
	glRotatef ((GLfloat) day, 0.0, 0.0, 1.0);
	glColor3f(1.00,0.89,0.4);//土黄色很淡
	glutSolidSphere(0.1, 30, 30); // 水星

 
	glPopMatrix();
	glPushMatrix();
	glRotatef ((GLfloat) year2, 0.0, 0.0, 1.0);
	glTranslatef (0.0, 1.8, 0.0);
	glRotatef ((GLfloat) day, 0.0, 0.0, 1.0);
	glColor3f(0.0,0.0,1.0);//蓝色
	glutSolidSphere(0.3, 30, 30); //地球


	glPopMatrix();
	glPushMatrix();
	glRotatef ((GLfloat) year3, 0.0, 0.0, 1.0);
	glTranslatef (0.0,-2.47, 0.0);
	glRotatef ((GLfloat) day, 0.0, 0.0, 1.0);
	glColor3f(0.95,0.4,0.0);//红黄色
	glutSolidSphere(0.15, 30, 30); //火星
 
		
	glPopMatrix();

    glFlush ();
 
	glutSwapBuffers();
	std::this_thread::sleep_for(std::chrono::milliseconds(60));
}
 

void reshape (int w, int h)
{
	glViewport (0, 0, (GLsizei) w, (GLsizei) h);
	glMatrixMode (GL_PROJECTION);
	glLoadIdentity ();//变为单位矩阵
	gluPerspective(60.0, (GLfloat) w/(GLfloat) h, 1.0, 20.0);//透视图
 
	if (w <= h)
		glOrtho(-1.5, 1.5, -1.5*(GLfloat)h/(GLfloat)w,1.5*(GLfloat)h/(GLfloat)w, 10.0, -10.0);
	else
		glOrtho(1.5*(GLfloat)w/(GLfloat)h,1.5*(GLfloat)w/(GLfloat)h, -1.5, 1.5, -10.0, 10.0);
	
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt (0.0, 6.0, 3.0, 0.0, 0.0, 0.0, 0.0, 0.0,1.0);
	//这里有9个参数，三个三个为一组，第一组表示眼睛的位置，第二组表示被观察物的位置，第三组代表观察者认为上的方向
}
 
int main(int argc, char** argv)
{
	glutInit(&argc, argv);//初始化opengl类库
	glutInitDisplayMode (GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);
	//若为GLUT_RGBA，则其中的A表示透明度
	//1.0为不透明，0.0为透明。Alpha测试在测试级别中最低。
	glutInitWindowSize (900, 800);
	glutInitWindowPosition (250, 50);
//	glutCreateWindow (argv[0]);//这一句显示的就是文件位置
	glutCreateWindow ("太阳系");
	//init ();
	glutDisplayFunc(display);
	glutIdleFunc(display);//全局回调函数，当没有窗口事件到达时，GLUT程序功
	//能可以执行后台处理任务或连续动画,启动，会被不断调用，直到有窗口事件发生
	glutReshapeFunc(reshape);
	//guidao();
	glutMainLoop();//让main函数里面的代码循环实现
	return 0;
}

