#include <gl/glut.h>
void neko(void){
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0.0f,0.0f,0.0f);

	//kuping
 
	glRectf(-0.25f, 0.3f,    0.25f, 0.275f); 

	glRectf(-0.3f,  0.275f, -0.1f,  0.35f);  // kuping kiri
	glRectf(-0.2833f, 0.35f, -0.1167f, 0.4f);
	glRectf(-0.2667f, 0.4f,  -0.1333f, 0.45f);
	glRectf(-0.25f,   0.45f, -0.15f,   0.5f);
	glRectf(-0.2333f, 0.5f,  -0.1667f, 0.55f);
	glRectf(-0.2167f, 0.55f, -0.1833f, 0.6f);

	
	glRectf( 0.1f,  0.275f,  0.3f,  0.35f);  // kuping kanan
	glRectf( 0.1167f, 0.35f,  0.2833f, 0.4f);
	glRectf( 0.1333f, 0.4f,   0.2667f, 0.45f);
	glRectf( 0.15f,   0.45f,  0.25f,   0.5f);
	glRectf( 0.1667f, 0.5f,   0.2333f, 0.55f);
	glRectf( 0.1833f, 0.55f,  0.2167f, 0.6f);

	//pala
	glRectf(-0.325f, 0.275f, 0.325f, 0.25f);
	glRectf(-0.35f,  0.25f,  0.35f,  0.225f);
	glRectf(-0.375f, 0.225f, 0.375f, 0.2f);
	glRectf(-0.4f,   0.05f,  0.4f,  -0.2f);
	glRectf(-0.375f, -0.2f,  0.375f, -0.225f);
	glRectf(-0.35f,  -0.225f, 0.35f, -0.25f);

	
	//pala daerah mata
	glRectf(-0.4f,   0.2f,  -0.25f,  0.05f); // kiri luar
	glRectf(-0.025f, 0.2f,   0.025f, 0.05f); // tengah
	glRectf( 0.25f,  0.2f,   0.4f,   0.05f); // kanan luar

	
	//Mata
	glColor3f(0.9098f, 0.78431f, 0.0588235f);
			//kanan
	glRectf( 0.025f,  0.2f,    0.25f,   0.19f); // atas pupil
	glRectf( 0.025f,  0.19f,   0.1125f, 0.06f); // kiri pupil
	glRectf( 0.15f,   0.19f,   0.25f,   0.06f); // kanan pupil
	glRectf( 0.025f,  0.06f,   0.25f,   0.05f); // bawah pupil
			//kiri
	glRectf(-0.025f,  0.2f,   -0.25f,   0.19f); // atas pupil
	glRectf(-0.025f,  0.19f,  -0.1125f, 0.06f); // kiri pupil
	glRectf(-0.15f,   0.19f,  -0.25f,   0.06f); // kanan pupil
	glRectf(-0.025f,  0.06f,  -0.25f,   0.05f); // bawah pupil

	//pupil
	glColor3f(0.0f, 0.0f, 0.0f);
	glRectf( 0.1125f, 0.19f,  0.15f,  0.06f); // pupil kanan
	glRectf(-0.1125f, 0.19f, -0.15f,  0.06f); // pupil kiri

	// kumis kanan
	glLineWidth(4.0f);
	glBegin(GL_LINES); glColor3f(1.0f,1.0f,1.0f);
	glVertex3f(0.2f,-0.08f,0.0f); glVertex3f(0.375f,-0.08f,0.0f); glEnd(); // tengah
	glBegin(GL_LINES); glColor3f(1.0f,1.0f,1.0f);
	glVertex3f(0.2f,-0.04f,0.0f); glVertex3f(0.375f,-0.01f,0.0f); glEnd(); // atas
	glBegin(GL_LINES); glColor3f(1.0f,1.0f,1.0f);
	glVertex3f(0.2f,-0.12f,0.0f); glVertex3f(0.375f,-0.15f,0.0f); glEnd(); // bawah

	//kumis kiri
	glBegin(GL_LINES); glColor3f(1.0f,1.0f,1.0f);
	glVertex3f(-0.2f,-0.08f,0.0f); glVertex3f(-0.375f,-0.08f,0.0f); glEnd(); // tengah
	glBegin(GL_LINES); glColor3f(1.0f,1.0f,1.0f);
	glVertex3f(-0.2f,-0.04f,0.0f); glVertex3f(-0.375f,-0.01f,0.0f); glEnd(); // atas
	glBegin(GL_LINES); glColor3f(1.0f,1.0f,1.0f);
	glVertex3f(-0.2f,-0.12f,0.0f); glVertex3f(-0.375f,-0.15f,0.0f); glEnd(); // bawah

	//mulut
	glLineWidth(3.0f);
	glBegin(GL_LINES); glColor3f(1.0f,1.0f,1.0f);
	glVertex3f(0.0f,0.0f,0.0f); glVertex3f(0.0f,-0.1f,0.0f); glEnd();    // tengah
	glBegin(GL_LINES); glColor3f(1.0f,1.0f,1.0f);
	glVertex3f(0.0f,-0.1f,0.0f); glVertex3f(0.06f,-0.13f,0.0f); glEnd(); // kanan
	glBegin(GL_LINES); glColor3f(1.0f,1.0f,1.0f);
	glVertex3f(0.0f,-0.1f,0.0f); glVertex3f(-0.06f,-0.13f,0.0f); glEnd();// kiri

	//hidung
	glBegin(GL_TRIANGLES); glColor3f(1.0f,0.2f,0.5f);
	glVertex3f(-0.06f,0.0f,0.0f);
	glVertex3f( 0.06f,0.0f,0.0f);
	glVertex3f( 0.0f,-0.06f,0.0f);
	glEnd();

	glFlush();
}
int main(int argc,char*argv[]){
	glutInit(&argc,argv);
	glutInitWindowSize(840,840);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGBA);
	glutCreateWindow("neko");
	glutDisplayFunc(neko);
	glClearColor(1.0f,1.0f,1.0f,1.0f);
	glutMainLoop();
	return 0;
}
