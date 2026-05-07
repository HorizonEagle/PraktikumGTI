#include <GL/glut.h>
#include <math.h>

float carX = -3.5f;
const float carSpeed = 0.2f;
float wheelAngle = 0.0f;

void drawBox(float w, float h, float d) {
    float hw = w / 2, hh = h / 2, hd = d / 2;
    glBegin(GL_QUADS);
        glNormal3f(0, 0, 1);
        glVertex3f(-hw, -hh, hd); glVertex3f(hw, -hh, hd);
        glVertex3f(hw, hh, hd); glVertex3f(-hw, hh, hd);

        glNormal3f(0, 0, -1);
        glVertex3f(hw, -hh, -hd); glVertex3f(-hw, -hh, -hd);
        glVertex3f(-hw, hh, -hd); glVertex3f(hw, hh, -hd);

        glNormal3f(-1, 0, 0);
        glVertex3f(-hw, -hh, -hd); glVertex3f(-hw, -hh, hd);
        glVertex3f(-hw, hh, hd); glVertex3f(-hw, hh, -hd);

        glNormal3f(1, 0, 0);
        glVertex3f(hw, -hh, hd); glVertex3f(hw, -hh, -hd);
        glVertex3f(hw, hh, -hd); glVertex3f(hw, hh, hd);

        glNormal3f(0, 1, 0);
        glVertex3f(-hw, hh, hd); glVertex3f(hw, hh, hd);
        glVertex3f(hw, hh, -hd); glVertex3f(-hw, hh, -hd);

        glNormal3f(0, -1, 0);
        glVertex3f(-hw, -hh, -hd); glVertex3f(hw, -hh, -hd);
        glVertex3f(hw, -hh, hd); glVertex3f(-hw, -hh, hd);
    glEnd();
}

void drawWheel(void) {
    int slices = 24;
    float r = 0.28f;
    float thick = 0.18f;
    int i;

    glColor3f(0.12f, 0.12f, 0.12f);
    glBegin(GL_QUAD_STRIP);
    for (i = 0; i <= slices; i++) {
        float a = (float)i / slices * 2.0f * (float)M_PI;
        float c = cosf(a), s = sinf(a);
        glNormal3f(c, s, 0);
        glVertex3f(c * r, s * r, thick / 2);
        glVertex3f(c * r, s * r, -thick / 2);
    }
    glEnd();

    glBegin(GL_TRIANGLE_FAN);
    glNormal3f(0, 0, 1);
    glVertex3f(0, 0, thick / 2);
    for (i = 0; i <= slices; i++) {
        float a = (float)i / slices * 2.0f * (float)M_PI;
        glVertex3f(cosf(a) * r, sinf(a) * r, thick / 2);
    }
    glEnd();

    glBegin(GL_TRIANGLE_FAN);
    glNormal3f(0, 0, -1);
    glVertex3f(0, 0, -thick / 2);
    for (i = slices; i >= 0; i--) {
        float a = (float)i / slices * 2.0f * (float)M_PI;
        glVertex3f(cosf(a) * r, sinf(a) * r, -thick / 2);
    }
    glEnd();

    glColor3f(0.75f, 0.75f, 0.80f);
    int spokes = 5;
    for (i = 0; i < spokes; i++) {
        float a = (float)i / spokes * 2.0f * (float)M_PI + wheelAngle * (float)M_PI / 180.0f;
        float cx = cosf(a) * r * 0.55f;
        float cy = sinf(a) * r * 0.55f;
        glPushMatrix();
            glTranslatef(cx, cy, 0);
            drawBox(0.06f, 0.06f, thick * 1.02f);
        glPopMatrix();
    }

    glColor3f(0.60f, 0.60f, 0.65f);
    glBegin(GL_TRIANGLE_FAN);
    glVertex3f(0, 0, thick / 2 + 0.001f);
    for (i = 0; i <= slices; i++) {
        float a = (float)i / slices * 2.0f * (float)M_PI;
        glVertex3f(cosf(a) * 0.07f, sinf(a) * 0.07f, thick / 2 + 0.001f);
    }
    glEnd();
}

void drawAllWheels(void) {
    float wx[2] = {-0.75f, 0.75f};
    float wz[2] = {0.50f, -0.50f};
    float wy = -0.20f;
    int i, j;

    for (i = 0; i < 2; i++) {
        for (j = 0; j < 2; j++) {
            glPushMatrix();
                glTranslatef(wx[i], wy, wz[j]);
                glRotatef(wheelAngle, 0, 0, 1);
                drawWheel();
            glPopMatrix();
        }
    }
}

void drawCar(void) {
    glColor3f(0.15f, 0.45f, 0.85f);
    glPushMatrix();
        glTranslatef(0, 0.05f, 0);
        drawBox(2.0f, 0.40f, 1.0f);
    glPopMatrix();

    glColor3f(0.20f, 0.55f, 0.95f);
    glPushMatrix();
        glTranslatef(-0.05f, 0.45f, 0);
        drawBox(1.10f, 0.38f, 0.88f);
    glPopMatrix();

    glColor3f(0.40f, 0.75f, 0.70f);
    glPushMatrix();
        glTranslatef(0.48f, 0.42f, 0);
        glRotatef(-20, 0, 0, 1);
        drawBox(0.05f, 0.32f, 0.84f);
    glPopMatrix();

    glColor3f(0.40f, 0.75f, 0.70f);
    glPushMatrix();
        glTranslatef(-0.58f, 0.42f, 0);
        glRotatef(20, 0, 0, 1);
        drawBox(0.05f, 0.28f, 0.84f);
    glPopMatrix();

    glColor3f(1.0f, 1.0f, 0.7f);
    glPushMatrix();
        glTranslatef(1.01f, 0.05f, 0.32f);
        drawBox(0.04f, 0.14f, 0.20f);
    glPopMatrix();

    glPushMatrix();
        glTranslatef(1.01f, 0.05f, -0.32f);
        drawBox(0.04f, 0.14f, 0.20f);
    glPopMatrix();

    glColor3f(0.9f, 0.1f, 0.1f);
    glPushMatrix();
        glTranslatef(-1.01f, 0.05f, 0.32f);
        drawBox(0.04f, 0.14f, 0.18f);
    glPopMatrix();

    glPushMatrix();
        glTranslatef(-1.01f, 0.05f, -0.32f);
        drawBox(0.04f, 0.14f, 0.18f);
    glPopMatrix();

    glColor3f(0.82f, 0.82f, 0.82f);
    glPushMatrix();
        glTranslatef(1.02f, -0.18f, 0);
        drawBox(0.06f, 0.10f, 0.90f);
    glPopMatrix();

    glPushMatrix();
        glTranslatef(-1.02f, -0.18f, 0);
        drawBox(0.06f, 0.10f, 0.90f);
    glPopMatrix();

    drawAllWheels();
}

void drawRoad(void) {
    glColor3f(0.25f, 0.25f, 0.25f);
    glBegin(GL_QUADS);
        glNormal3f(0, 1, 0);
        glVertex3f(-6.0f, -0.50f, -2.0f);
        glVertex3f(6.0f, -0.50f, -2.0f);
        glVertex3f(6.0f, -0.50f, 2.0f);
        glVertex3f(-6.0f, -0.50f, 2.0f);
    glEnd();

    glColor3f(0.95f, 0.95f, 0.95f);
    int k;
    for (k = -5; k <= 5; k++) {
        glBegin(GL_QUADS);
            glVertex3f(k * 1.0f, -0.499f, -0.07f);
            glVertex3f(k * 1.0f + 0.55f, -0.499f, -0.07f);
            glVertex3f(k * 1.0f + 0.55f, -0.499f, 0.07f);
            glVertex3f(k * 1.0f, -0.499f, 0.07f);
        glEnd();
    }
}

void display(void) {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();

    gluLookAt(0, 1.8, 5.0,
              0, 0, 0,
              0, 1, 0);

    drawRoad();

    glPushMatrix();
        glTranslatef(carX, 0, 0);
        drawCar();
    glPopMatrix();

    glutSwapBuffers();
}

void update(int value) {
    carX += carSpeed;
    wheelAngle -= carSpeed * 90.0f;
    if (wheelAngle < -360.0f) wheelAngle += 360.0f;

    if (carX > 5.5f) carX = -5.5f;

    glutPostRedisplay();
    glutTimerFunc(16, update, 0);
}

void reshape(int w, int h) {
    if (h == 0) h = 1;
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0, (double)w / h, 0.1, 100.0);
    glMatrixMode(GL_MODELVIEW);
}

int main(int argc, char **argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(900, 540);
    glutCreateWindow("Mobil 3D - OpenGL/GLUT");

    glEnable(GL_DEPTH_TEST);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glEnable(GL_COLOR_MATERIAL);
    glColorMaterial(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE);
    glShadeModel(GL_SMOOTH);

    GLfloat lightPos[] = {2.0f, 5.0f, 4.0f, 1.0f};
    GLfloat ambient[] = {0.30f, 0.30f, 0.30f, 1.0f};
    GLfloat diffuse[] = {0.90f, 0.90f, 0.90f, 1.0f};
    glLightfv(GL_LIGHT0, GL_POSITION, lightPos);
    glLightfv(GL_LIGHT0, GL_AMBIENT, ambient);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuse);

    glClearColor(0.53f, 0.81f, 0.98f, 1.0f);

    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutTimerFunc(16, update, 0);

    glutMainLoop();
    return 0;
}
