#include <GL/glut.h>

void display() {
  glClear(GL_COLOR_BUFFER_BIT);
  //drawing the hut's wall borders
	
  // Left wall
  glBegin(GL_POINTS);
  glColor3f(1.0f, 0.0f, 0.0f); // Red

  for (float y = -50.0f; y <= 25.0f; y += 0.25f) {
    glVertex2f(-75.0f, y);
  }

  glEnd();

  //Bottom wall
  glBegin(GL_POINTS);
  glColor3f(0.0f, 1.0f, 0.0f); // Green

  for (float x = -75.0f; x <= 75.0f; x += 0.25f) {
    glVertex2f(x, -50.0f);
  }

  glEnd();

  //Right wall
  glBegin(GL_POINTS);
  glColor3f(0.0f, 0.0f, 1.0f); // Blue

  for (float y = -50.0f; y <= 25.0f; y += 0.25f) {
    glVertex2f(75.0f, y);
  }

  glEnd();

  //Roof
  glBegin(GL_TRIANGLES);
   glColor3f(0.0f, 0.0f, 1.0f);     //blue
  glVertex3f(0.0f, 75.0f,0.0f);
        glColor3f(1.0f, 0.0f, 0.0f);     //red

  glVertex3f(-100.0f, 25.0f,0.0f);
        glColor3f(0.0f, 1.0f, 0.0f);     // green

  glVertex3f(100.0f, 25.0f,0.0f);
  glEnd();

 //Colored walls
  glBegin(GL_POLYGON);
  //bottom left
    glColor3f(1.0f, 0.0f, 0.0f);

  glVertex2f(-74.0f, -49.0f);
  //top left
    glColor3f(0.0f, 0.0f, 1.0f);
  glVertex2f(-74.0f, 25.0f);
  //top right
    glColor3f(0.0f, 0.0f, 1.0f);
  glVertex2f(74.4f, 25.0f);
  //bottom right
    glColor3f(0.0f, 1.0f, 0.0f);

  glVertex2f(74.4f, -49.0f);
  glEnd();

  glutSwapBuffers();
}

void reshape(int width, int height) {
  glViewport(0, 0, width, height);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluOrtho2D(-150.0f, 150.0f, -100.0f, 100.0f);
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
}

int main(int argc, char** argv) {
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
  glutInitWindowSize(500, 500);
  glutInitWindowPosition(100, 100);
  glutCreateWindow("MY HUT");
  glutDisplayFunc(display);
  glutReshapeFunc(reshape);
  glutMainLoop();
  return 0;
}
