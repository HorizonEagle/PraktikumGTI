#include <GL/glut.h>
#include <cstdlib>

static int shoulder=0, elbow=0, wrist=0, finger=0, thumb=0;

void init(void){
    glClearColor(0.0,0.0,0.0,0.0);
    glShadeModel(GL_FLAT);
}

void drawSegment(float sx, float sy, float sz){
    glPushMatrix();
    glScalef(sx,sy,sz);
    glutWireCube(1.0);
    glPopMatrix();
}

void display(void){
    glClear(GL_COLOR_BUFFER_BIT);
    glPushMatrix();

    // ===== UPPER ARM =====
    glTranslatef(-1.0,0.0,0.0);
    glRotatef((GLfloat)shoulder,0.0,0.0,1.0);
    glTranslatef(1.0,0.0,0.0);
    drawSegment(2.0,0.4,1.0);

    // ===== FOREARM =====
    glTranslatef(1.0,0.0,0.0);
    glRotatef((GLfloat)elbow,0.0,0.0,1.0);
    glTranslatef(1.0,0.0,0.0);
    drawSegment(2.0,0.4,1.0);

    // ===== PERGELANGAN (WRIST) =====
    glTranslatef(1.0,0.0,0.0);
    glRotatef((GLfloat)wrist,0.0,0.0,1.0);
    glTranslatef(0.3,0.0,0.0);

    // ===== TELAPAK TANGAN =====
    drawSegment(0.6,0.8,0.3);

    // ===== 4 JARI =====
    float fingerY[4] = {0.3f,0.1f,-0.1f,-0.3f};
    for(int i=0;i<4;i++){
        glPushMatrix();
        glTranslatef(0.35f,fingerY[i],0.0f);
        glRotatef((GLfloat)finger,0.0f,0.0f,1.0f);
        glTranslatef(0.2f,0.0f,0.0f);
        drawSegment(0.4,0.1,0.25);

        // Ruas tengah jari (mengikuti rotasi finger)
        glTranslatef(0.2f,0.0f,0.0f);
        glRotatef((GLfloat)finger*0.6f,0.0f,0.0f,1.0f);
        glTranslatef(0.15f,0.0f,0.0f);
        drawSegment(0.3,0.09,0.22);
        glPopMatrix();
    }

    // ===== IBU JARI =====
    glPushMatrix();
    glTranslatef(0.2f,-0.45f,0.0f);
    glRotatef(30.0f+thumb,0.0f,0.0f,1.0f);
    glTranslatef(0.18f,0.0f,0.0f);
    drawSegment(0.36,0.12,0.25);

    glTranslatef(0.18f,0.0f,0.0f);
    glRotatef((GLfloat)thumb*0.5f,0.0f,0.0f,1.0f);
    glTranslatef(0.14f,0.0f,0.0f);
    drawSegment(0.28,0.11,0.22);
    glPopMatrix();

    glPopMatrix();
    glutSwapBuffers();
}

void reshape(int w,int h){
    glViewport(0,0,(GLsizei)w,(GLsizei)h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(65.0,(GLfloat)w/(GLfloat)h,1.0,20.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glTranslatef(0.0,0.0,-7.0);
}

void keyboard(unsigned char key,int x,int y){
    switch(key){
        case 's': shoulder=(shoulder+5)%360; break;
        case 'S': shoulder=(shoulder-5+360)%360; break;
        case 'e': elbow=(elbow+5)%360; break;
        case 'E': elbow=(elbow-5+360)%360; break;
        case 'w': wrist=(wrist+5)%360; break;
        case 'W': wrist=(wrist-5+360)%360; break;
        case 'f': finger=(finger+5>80)?80:finger+5; break;
        case 'F': finger=(finger-5<0)?0:finger-5; break;
        case 't': thumb=(thumb+5>60)?60:thumb+5; break;
        case 'T': thumb=(thumb-5<-20)?-20:thumb-5; break;
        case 'r': shoulder=elbow=wrist=finger=thumb=0; break;
        case 27: exit(0); break;
    }
    glutPostRedisplay();
}

int main(int argc,char** argv){
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGB);
    glutInitWindowSize(700,600);
    glutInitWindowPosition(100,100);
    glutCreateWindow(argv[0]);
    init();
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutKeyboardFunc(keyboard);
    glutMainLoop();
    return 0;
}
