#include <GL/glut.h>

void Garis() {
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.0f,0.0f,0.0f);

    // GL_LINE_STRIP
    glBegin(GL_LINE_STRIP);
        glVertex2f(-0.9, 0.7);
        glVertex2f(-0.7, 0.9);
        glVertex2f(-0.5, 0.7);
        glVertex2f(-0.3, 0.9);
    glEnd();

    // GL_LINE_LOOP
    glBegin(GL_LINE_LOOP);
        glVertex2f(-0.2, 0.9);
        glVertex2f(0.0, 0.9);
        glVertex2f(0.0, 0.7);
        glVertex2f(-0.2, 0.7);
    glEnd();

    // GL_TRIANGLE_FAN
    glBegin(GL_TRIANGLE_FAN);
        glVertex2f(0.5, 0.8);   // pusat
        glVertex2f(0.4, 0.7);
        glVertex2f(0.6, 0.7);
        glVertex2f(0.7, 0.8);
        glVertex2f(0.6, 0.9);
        glVertex2f(0.4, 0.9);
    glEnd();

    // GL_TRIANGLE_STRIP
    glBegin(GL_TRIANGLE_STRIP);
        glVertex2f(-0.9, 0.2);
        glVertex2f(-0.8, 0.4);
        glVertex2f(-0.7, 0.2);
        glVertex2f(-0.6, 0.4);
        glVertex2f(-0.5, 0.2);
    glEnd();

    // GL_QUADS
    glBegin(GL_QUADS);
        glVertex2f(-0.2, 0.4);
        glVertex2f(0.0, 0.4);
        glVertex2f(0.0, 0.2);
        glVertex2f(-0.2, 0.2);
    glEnd();

    // GL_QUAD_STRIP
    glBegin(GL_QUAD_STRIP);
        glVertex2f(0.3, 0.4);
        glVertex2f(0.3, 0.2);

        glVertex2f(0.4, 0.4);
        glVertex2f(0.4, 0.2);

        glVertex2f(0.5, 0.4);
        glVertex2f(0.5, 0.2);

        glVertex2f(0.6, 0.4);
        glVertex2f(0.6, 0.2);
    glEnd();

    glFlush();
}



int main(int argc,char*argv[]){
	glutInit(&argc,argv);
	glutInitWindowSize(840,840);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGBA);
	glutCreateWindow("Garis2");
	glutDisplayFunc(Garis);
	glClearColor(1.0f,1.0f,1.0f,1.0f);
	glutMainLoop();
	return 0;
}
