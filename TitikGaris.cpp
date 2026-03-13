#include <GL/glut.h>

void TitikGaris(void){
	glClear(GL_COLOR_BUFFER_BIT);
	glPointSize(10.0f);
	glBegin(GL_POINTS);
		glColor3f(1.0f,0.0f,0.0f);
		glVertex3f(0.0f,0.0f,0.0f);
		
	glEnd();
	
	glLineWidth(5.0f);
	glBegin(GL_LINES);
		glVertex3f(-0.5f, 0.6f, 0.0f);
        glVertex3f( 0.5f, 0.6f, 0.0f);
	
	glEnd();
	
	glFlush();
	
}

int main(int argc,char*argv[]){
	glutInit(&argc,argv);
	glutInitWindowSize(720,720);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGBA);
	glutCreateWindow("garisTitik");
	glClearColor(1.0f,1.0f,1.0f,0.0f);
	glutDisplayFunc(TitikGaris);
	glutMainLoop();
	return 0;
}

