#include <GL/glut.h>
#include <math.h>

//============================================
// Definicje kolorow:

#define CZARN 0.0, 0.0, 0.0
#define CZERW 1.0, 0.0, 0.0
#define ZIELO 0.0, 1.0, 0.0
#define ZOLTY 1.0, 1.0, 0.0
#define NIEBI 0.0, 0.0, 1.0
#define MAGEN 1.0, 0.0, 1.0
#define CYJAN 0.0, 1.0, 1.0
#define BIALY 1.0, 1.0, 1.0
  
void geom(int w, int h) {
  // Granice przedstawionego fragmentu przestrzeni:
  //   glOrtho(lewa, prawa, dolna, gorna, przednia, tylna);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  glOrtho(-20, 20, -15, 15, -4, 4);
  glMatrixMode(GL_MODELVIEW);
}

#define M_PI 3.14159265358979323846
#define n 6
#define prom 5
double przyrost = M_PI/20;

void wyswietl(void) {
  glClear(GL_COLOR_BUFFER_BIT);
  glLoadIdentity();

  glColor3d(CZERW);            // kolor

  glPushMatrix();              // pamietanie wspolrzednych oraz:

  glBegin(GL_POLYGON);         // wypelniony wielokat
      for (double kat=0; kat<=2*M_PI; kat+=(M_PI * 2) / n)
    glVertex3d(prom*cos(kat), prom*sin(kat), 0);
  glEnd();

  glPopMatrix();   

  glFlush();
}

int main(int ile_arg, char* arg[]) {
  glutInit(&ile_arg, arg);
  glutInitWindowSize(400, 300);
  glutInitWindowPosition(20, 10);
  glutCreateWindow(arg[0]);
  glClearColor(CYJAN, 0.0);
  glutReshapeFunc(geom);
  glutDisplayFunc(wyswietl);
  glutMainLoop();
  return 0;
}
