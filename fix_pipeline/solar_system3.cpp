#include <GLUT/glut.h>
 
 
#include<math.h>
#include<iostream>
using namespace std;
 
 
#define PI 3.14159
void Rotate() ;
//水星、金星、地球、火星、木星、土星、天王星、和海王星 
//adam,hesper,earth,mars,jupiter,saturn,uranus,neptune 
static float year = 0, day = 0,adamYear=0,hesperYear=0,marsYear=0,jupiterYear=0,saturnYear=0,uranusYear=0,neptuneYear=0,sunYear=0,month=0;
static float mar_satellite_1,mar_satellite_2 ;
float light_angle=0; 
float light_radius=8.0; 
double x=0,y=0;
 
 
 
 
double aix_x=0.0,aix_y=0.0,aix_z=0.5;
 
 
GLdouble angle = 100.0;
 
 
/*float theta=-90.0; //圆环旋转角
float angle=10; //左右场景每次旋转角
float sightangle=-90;
float s=10; //前后直走步长
float R=100; 
int inner=10,outer=80;
*/
 
 
/*float eyex=0,eyey=0,eyez=outer+4*inner+50;  
float atx=0,aty=0,atz=0;     
float atx1,atz1,eyex1,eyez1;*/
 
 
void lPosition()                                       
{ 
     float y,z; 
     y=light_radius*cos(light_angle); 
     z=light_radius*sin(light_angle);
     float light_position[] = { 3.0,y,z, 0.0 }; 
     glLightfv(GL_LIGHT0, GL_POSITION, light_position);   
} 
 
 
 
 
void init(void) 
{ 
    glClearColor (0.0, 0.0, 0.0, 0.0);
    // 设置光源位置
    lPosition(); 
    glShadeModel(GL_SMOOTH);            
    glEnable(GL_LIGHTING);               
    glEnable(GL_LIGHT0); 
    glEnable(GL_DEPTH_TEST); 
    glEnable(GL_COLOR_MATERIAL); 
}
 
 
 
 
void material_sun()                               //设置太阳材质，以下同
{ 
    GLfloat mat_specular[] = { 1.0, 0.0, 0.0, 1.0 };       
    GLfloat mat_shininess[] = { 10.0 };                  
    GLfloat lmodel_ambient[]={1.0,0.0,0.0,1.0};        //太阳颜色为红色      
    GLfloat white_light[]={1.0, 1.0,1.0, 1.0};             
  
    // glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);     
    // glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess); 
    glMaterialfv(GL_FRONT, GL_DIFFUSE, lmodel_ambient); 
    // glLightModelfv(GL_LIGHT_MODEL_AMBIENT, lmodel_ambient); 
    GLfloat mat_emission[] = { 0.2,0.0,0.0,0.2};//sun微微发红光  
    glMaterialfv(GL_FRONT, GL_EMISSION, mat_emission);
} 
 
void material_earth() 
{ 
    GLfloat mat_specular[] = { 1.0, 0.0, 0.0, 1.0 }; 
    GLfloat mat_shininess[] = { 50.0 }; 
    GLfloat lmodel_ambient[]={0.1,0.2,0.6,1.0}; 
    GLfloat white_light[]={1.0, 1.0,1.0, 1.0}; 
 
    glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular); 
    glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess); 
    glMaterialfv(GL_FRONT, GL_DIFFUSE, lmodel_ambient); 
    glLightModelfv(GL_LIGHT_MODEL_AMBIENT, lmodel_ambient); 
} 
 

void material_moon()
{
  GLfloat mat_specular[] = { 1.0, 1.0, 1.0, 1.0 }; 
    GLfloat mat_shininess[] = { 50.0 }; 
    GLfloat lmodel_ambient[]={1.0,1.0,0.0,1.0}; 
    GLfloat white_light[]={1.0, 1.0,1.0, 1.0}; 
 
 
    glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular); 
    glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess); 
    glMaterialfv(GL_FRONT, GL_DIFFUSE, lmodel_ambient); 
    glLightModelfv(GL_LIGHT_MODEL_AMBIENT, lmodel_ambient); 
}
 
 
void sun()                  //绘制太阳
{ 
    glPushMatrix(); 
    glColor4f(1.0,1.0,1.0,1.0);	
    glTranslatef (-15,0,0);
    
    material_sun();  
    glRotatef ((GLfloat) day, 0.0, 1.0, 0.0);   //太阳自转
    glutSolidSphere(10, 200, 200);                //画球体 
    glPopMatrix(); 
} 
 
void earth() 
{ 
    glPushMatrix(); 
    material_earth(); 
glTranslatef (-15,0,0);
    glutSolidTorus(0.05,17,30,100);//地球轨道 
    glRotatef ((GLfloat) year, aix_x, aix_y, aix_z); 
glTranslatef (15,0,0);
    glTranslatef (2,0,0); 
    glRotatef ((GLfloat) day, 0.0, 1.0, 0.0);
glTranslatef (-2,0,0);
glTranslatef (2,0,0);
    glutSolidSphere(1.0, 20, 16);               
//  glColor3f(0.0, 1.0, 0.0);
 
 
material_moon();                          //绘制月球，以下以同样方法绘制各行星的卫星
     glRotatef(month/100, 0.0, 0.0, 1.0);
     glTranslatef(2, 0.0, 0.0);
     glutSolidSphere(0.3, 10, 10);
glPopMatrix(); 
} 


GLfloat G_fDistance = 36.f;
GLfloat G_fAngle_horizon = 0.0f;
GLfloat G_fAngle_vertical = 0.0f;

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
    lPosition(); 
    glClear (GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT); 

    glMatrixMode(GL_MODELVIEW);

    glLoadIdentity();

    glTranslatef(0.0, 0.0, -G_fDistance);
	glRotatef(G_fAngle_horizon, 0.0f, 1.0f, 0.0f);
	glRotatef(G_fAngle_vertical, 1.0f, 0.0f, 0.0f);
 
    sun(); 
    // adam(); 
    // hesper(); 
    earth(); 
    // mars(); 
    // jupiter(); 
    //saturn(); 
    //uranus(); 
    //neptune(); 
 
 
Rotate();
 
 
    glutSwapBuffers(); 
} 
 
 
void myidle()
{
day+=10.0;
if (day>=360)
day=day-360;
 
 
glutPostRedisplay();  
}
 
 
void Rotate()          //设置各行星的公转周期
{ 
   //adamYear=0,hesperYear=0,marsYear=0,jupiterYear=0,saturnYear=0,uranusYear=0,neptuneYear=0; 
 //  adamYear=(adamYear+1.2)%360; 
   adamYear+=0.12;
   if(adamYear>=360)
  adamYear-=360;
//   hesperYear=(hesperYear+2)%360; 
   hesperYear+=0.10;
   if(hesperYear>=360)
  hesperYear-=360;
 //  year=(year+0.8)%360;
   year+=0.08;
   if(year>=360)
  year-=360;
//   marsYear=(marsYear+0.6)%360;
   marsYear+=0.06;
   if(marsYear>=360)
  marsYear-=360;
 
 
//   jupiterYear=(jupiterYear+0.5)%360; 
    jupiterYear+=0.05;
   if(jupiterYear>=360)
  jupiterYear-=360;
//   saturnYear=(saturnYear+0.4)%360; 
    saturnYear+=0.04;
   if(saturnYear>=360)
  saturnYear-=360;
 //  uranusYear=(uranusYear+0.3)%360; 
   uranusYear+=0.03;
   if(uranusYear>=360)
  uranusYear-=360;
//   neptuneYear=(neptuneYear+0.1)%360; 
    neptuneYear+=0.01;
   if(neptuneYear>=360)
  neptuneYear-=360;
   glutPostRedisplay();                
   month+=0.03;
   if(month>=360)
  month-=360;
} 
 
 
void mykeyboard(unsigned char key, int x, int y)  
{
switch(key)
{
case 'A':
case 'a':
aix_y-=0.01;
aix_z+=0.01;
break;
case 'D':
case 'd':
aix_y+=0.01;
aix_z-=0.01;
break;
 
 
case 'W':
case 'w':
angle-=10.0;
break;
case 'S':
case 's':
angle+=10.0;
break;
}
    glutPostRedisplay();  
     
}
 
 
 
 
void reshape (int w, int h)              
{ 
    glViewport (0, 0, (GLsizei) w, (GLsizei) h);                
    glMatrixMode (GL_PROJECTION);                               
    glLoadIdentity ();    
 
    gluPerspective(angle, (GLfloat) w/(GLfloat) h, 1.0, 200.0); 
 
    glMatrixMode(GL_MODELVIEW); 
glLoadIdentity();
glTranslatef(0.0,0.0,-50.0);                               
} 
 
 
 
 
 
 
 
 
int main(int argc, char** argv) 
{ 
   glutInit(&argc, argv);                                      
   glutInitDisplayMode (GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);   
   glutInitWindowSize(800, 600);                              
   glutInitWindowPosition(100, 100);                          
   glutCreateWindow ("solar system");                          
   init(); 
   glutDisplayFunc(display);          
   glutReshapeFunc(reshape);       
   glutIdleFunc(myidle);   
   
//    glutKeyboardFunc(mykeyboard);  
   	glutSpecialFunc(processSpecialKeys);
	glutKeyboardFunc(processNormalKeys); 
 
 
   glutMainLoop();                 
   return 0; 
} 