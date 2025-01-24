
#include <windows.h>
#include <GL/glut.h>
#include <math.h>
#include<cstdio>
# define PI           3.14159265358979323846


GLfloat boatPosition = 0.0f;  // Boat position
GLfloat planePosition = -1.0f;
GLfloat speed = 0.01f;  // Speed of movement
bool moving = true;
GLfloat cloudPosition1 = -1.5f;  // Cloud 1 initial position

GLfloat cloudPosition2 = -1.0f;  // Cloud 2 initial position

GLfloat cloudPosition3 = -0.5f;  // Cloud 3 initial position

GLfloat cloudPosition4 = 0.0f;   // Cloud 4 initial position

GLfloat cloudSpeed = 0.0005f;      // Speed for all clouds

GLfloat planeposition = 0.0f;
GLfloat planespeed = 0.2f;
int  back1=151,back2=247,back3=255,  star1=151,star2=247,star3=255;


//int sky1=31,sky2=63,sky3=96 ;


void River() {

    glColor3ub(61,191,255);  // River color
    glBegin(GL_QUADS);
    glVertex2f(-1.0f, -0.6f);
    glVertex2f(1.0f, -0.6f);
    glVertex2f(1.0f, -1.0f);
    glVertex2f(-1.0f, -1.0f);
    glEnd();

        glColor3ub(255,255,255);  // River
            glLineWidth(1.0);
    glBegin(GL_LINES);
    glVertex2f(-0.7f, -0.7f);
    glVertex2f(-0.6f, -0.7f);
    glEnd();
          glColor3ub(255,255,255);  // River
    glBegin(GL_LINES);
    glVertex2f(-0.98f, -0.88f);
    glVertex2f(-0.9f, -0.88f);
    glEnd();

         glColor3ub(255,255,255);  // River
    glBegin(GL_LINES);
    glVertex2f(-0.86f, -0.97f);
    glVertex2f(-0.7f, -0.97f);
    glEnd();


         glColor3ub(255,255,255);  // River
    glBegin(GL_LINES);
    glVertex2f(-0.55f, -0.85f);
    glVertex2f(-0.5f, -0.85f);
    glEnd();

         glColor3ub(255,255,255);  // River
    glBegin(GL_LINES);
    glVertex2f(-0.47f, -0.85f);
    glVertex2f(-0.46f, -0.85f);
    glEnd();

       glColor3ub(255,255,255);  // River
    glBegin(GL_LINES);
    glVertex2f(-0.2f, -0.7f);
    glVertex2f(-0.1f, -0.7f);
    glEnd();
        glColor3ub(255,255,255);  // River
    glBegin(GL_LINES);
    glVertex2f(-0.08f, -0.7f);
    glVertex2f(-0.06f, -0.7f);
    glEnd();
           glColor3ub(255,255,255);  // River
    glBegin(GL_LINES);
    glVertex2f(-0.05f, -0.9f);
    glVertex2f(0.05f, -0.9f);
    glEnd();
              glColor3ub(255,255,255);  // River
    glBegin(GL_LINES);
    glVertex2f(0.1f, -0.85f);
    glVertex2f(0.15f, -0.85f);
    glEnd();
              glColor3ub(255,255,255);  // River
    glBegin(GL_LINES);
    glVertex2f(-0.3f, -0.85f);
    glVertex2f(-0.15f, -0.85f);
    glEnd();
               glColor3ub(255,255,255);  // River
    glBegin(GL_LINES);
    glVertex2f(-0.1f, -0.9f);
    glVertex2f(-0.08f, -0.9f);
    glEnd();
              glColor3ub(255,255,255);  // River
    glBegin(GL_LINES);
    glVertex2f(0.55f, -0.95f);
    glVertex2f(0.65f, -0.95f);
    glEnd();
             glColor3ub(255,255,255);  // River
    glBegin(GL_LINES);
    glVertex2f(0.52f, -0.95f);
    glVertex2f(0.55f, -0.95f);
    glEnd();
             glColor3ub(255,255,255);  // River
    glBegin(GL_LINES);
    glVertex2f(0.76f, -0.8f);
    glVertex2f(0.84f, -0.8f);
    glEnd();
             glColor3ub(255,255,255);  // River color
    glBegin(GL_LINES);
    glVertex2f(0.9f, -0.9f);
    glVertex2f(1.0f, -0.9f);
    glEnd();
             glColor3ub(255,255,255);  // River color
    glBegin(GL_LINES);
    glVertex2f(0.84f, -0.68f);
    glVertex2f(0.92f, -0.68f);
    glEnd();
         glColor3ub(255,255,255);  // River color
    glBegin(GL_LINES);
    glVertex2f(0.5f, -0.65f);
    glVertex2f(0.6f, -0.65f);
    glEnd();
        glColor3ub(255,255,255);  // River color
    glBegin(GL_LINES);
    glVertex2f(0.2f, -0.75f);
    glVertex2f(0.35f, -0.75f);
    glEnd();
      glColor3ub(255,255,255);  // River color
    glBegin(GL_LINES);
    glVertex2f(0.37f, -0.75f);
    glVertex2f(0.4f, -0.75f);
    glEnd();


}


void updateBoat(int value) {
    if (moving) {
        boatPosition += speed;
        if (boatPosition > 1.0f) {
            boatPosition = -1.0f;
        } else if (boatPosition < -1.0f) {
            boatPosition = 1.0f;
        }
        glutPostRedisplay();
    }
    glutTimerFunc(100, updateBoat, 0);
}

void init() {
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
}

void handleSpecialKeys(int key, int x, int y) {
    switch (key) {
        case GLUT_KEY_UP:
            speed = 0.1f;

            break;
        case GLUT_KEY_DOWN:
            speed = -0.1f;
            moving = true;
            break;
        case GLUT_KEY_LEFT:
            speed = 0.0f;

            break;
        case GLUT_KEY_RIGHT:
            speed = 0.1f;

            break;

    }
    glutPostRedisplay();
}


void Boat(){
       // Draw the boat
     glPushMatrix();
    glTranslatef(boatPosition, 0.0f, 0.0f);
     glColor3ub(51,62,124);//31, 63, 96
	glBegin(GL_QUADS);//..........................................boats lowre
	glVertex2f(0.3f,-0.8f);
    glVertex2f(0.6f,-0.8f);
    glVertex2f(0.55f,-0.87f);
	glVertex2f(0.36f,-0.87f);
	glEnd();

	glColor3ub(242,255,255);//31, 63, 96
	glBegin(GL_TRIANGLES);//..........................................boats upper
	glVertex2f(0.33f,-0.79f);
    glVertex2f(0.45f,-0.79f);
    glVertex2f(0.45f,-0.58f);
	glEnd();
	glColor3ub(242,255,255);//31, 63, 96
	glBegin(GL_TRIANGLES);//..........................................boats upper
	glVertex2f(0.46f,-0.58f);
	glVertex2f(0.46f,-0.79f);
    glVertex2f(0.574f,-0.79f);
	glEnd();

	glLineWidth(1.0);
	glColor3ub(0,0,0);
	glBegin(GL_LINE_STRIP);//..........................................boats lowre
	glVertex2f(0.33f,-0.79f);
    glVertex2f(0.574,-0.79f);
	glEnd();

	glLineWidth(1.5);
	glColor3ub(0,0,0);
	glBegin(GL_LINE_STRIP);//..........................................boats lowre
	glVertex2f(0.455f,-0.8f);
    glVertex2f(0.455,-0.58f);
	glEnd();
//////////////////////////////////////////////////////////////////////////////////////

  	 glColor3ub(3,25,97);//31, 63, 96
	glBegin(GL_QUADS);//..........................................boats lower
	glVertex2f(-0.4f,-0.7f);
    glVertex2f(-0.7f,-0.7f);
    glVertex2f(-0.66f,-0.76f);
	glVertex2f(-0.44f,-0.76f);
	glEnd();

     glColor3ub(163,219,220);
	glBegin(GL_QUADS);//..........................................boats upper
	glVertex2f(-0.45f,-0.7f);
    glVertex2f(-0.5f,-0.65f);
    glVertex2f(-0.6f,-0.65f);
	glVertex2f(-0.65f,-0.7f);
	glEnd();
///////////////////
    glColor3ub(3,25,97);
	glBegin(GL_QUADS);//..........................................boats lower triangle
	glVertex2f(0.7f,-0.9f);
    glVertex2f(0.99f,-0.9f);
    glVertex2f(0.9f,-0.99f);
	glVertex2f(0.8f,-0.99f);
	glEnd();


	glColor3ub(242,255,255);
	glBegin(GL_TRIANGLES);//..........................................boats upper triangle
	glVertex2f(0.75f,-0.9f);
    glVertex2f(0.75f,-0.65f);
    glVertex2f(0.9f,-0.9f);
	glEnd();

    glColor3ub(70,38,6); //----------------------------boat line
    glLineWidth(5);
	glBegin(GL_LINES);
   glVertex2f(0.75f,-0.9f);
    glVertex2f(0.75f,-0.65f);
	glEnd();

/////////////////////////////////////////////////////////////////////////////////
	glColor3ub(255,249,240);
	glBegin(GL_POLYGON);//..........................................boats lower
	glVertex2f(-0.72f,-0.88f);
    glVertex2f(-0.82f,-0.88f);
     glVertex2f(-0.84f,-0.92f);
     glVertex2f(-0.84f,-0.96f);
	glVertex2f(-0.76f,-0.96f);
	glEnd();


	glColor3ub(255,249,240);
	glBegin(GL_POLYGON);//..........................................boats lower
	glVertex2f(-0.84f,-0.92f);
    glVertex2f(-0.98f,-0.92f);
     glVertex2f(-0.94f,-0.96f);
     glVertex2f(-0.84f,-0.96f);
	glEnd();


	glColor3ub(67,60,131);
	glBegin(GL_QUADS);//..........................................boats lower
	glVertex2f(-0.925f, -0.82f);
	glVertex2f(-0.925f, -0.8f);
     glVertex2f(-0.794f,-0.8f);
      glVertex2f(-0.794f,-0.82f);
	glEnd();

    glColor3ub(160,160,160);
	glBegin(GL_POLYGON);//..........................................boats lower
	glVertex2f(-0.96f,-0.908f);
	glVertex2f(-0.92f,-0.82f);
     glVertex2f(-0.8f,-0.82f);
     glVertex2f(-0.78f,-0.8675f);
     glVertex2f(-0.82, -0.8675f);
     glVertex2f(-0.84f, -0.908f);
	glEnd();

		glColor3ub(51,62,124);
	glBegin(GL_QUADS);//..........................................boats lower
	glVertex2f(-0.98f,-0.92f);
	glVertex2f(-0.98f,-0.908f);
     glVertex2f(-0.84f,-0.908f);
      glVertex2f(-0.84f,-0.92f);
	glEnd();

		glColor3ub(255,249,240);
	glBegin(GL_POLYGON);//..........................................boats lower
	glVertex2f(-0.82f, -0.8675f);
	glVertex2f(-0.72f, -0.8675f);
     glVertex2f(-0.72f, -0.88f);
      glVertex2f(-0.82f,-0.88f);
	glEnd();

		glColor3ub(51,62,124);
	glBegin(GL_POLYGON);//..........................................boats lower
	glVertex2f(-0.84f, -0.92f);
	glVertex2f(-0.84f, -0.905f);
     glVertex2f(-0.82f,-0.8675f);
      glVertex2f(-0.82f,-0.88f);
	glEnd();


	glColor3ub(204,229,255);
	glBegin(GL_POLYGON);//..........................................boats window
	glVertex2f(-0.9115966259538f, -0.8279106398519f);
	glVertex2f(-0.9318967898129f, -0.8680276303354f);
     glVertex2f(-0.8883964386862f, -0.8685109675701f);
     glVertex2f(-0.8883964386862f, -0.8283939770867f);
     glEnd();

    glColor3ub(204,229,255);
    glBegin(GL_POLYGON);
	glVertex2f(-0.88f, -0.828f);
	glVertex2f(-0.88f, -0.8675f);
     glVertex2f(-0.85f, -0.8675f);
     glVertex2f(-0.85f, -0.828f);
	glEnd();

	glColor3ub(204,229,255);
    glBegin(GL_POLYGON);
	glVertex2f(-0.84f, -0.828f);
	glVertex2f(-0.84f, -0.8675f);
     glVertex2f(-0.78f, -0.8675f);
     glVertex2f(-0.796f, -0.828f);
	glEnd();

		glColor3ub(51,62,124);
	glBegin(GL_POLYGON);//..........................................boats lower
	glVertex2f(-0.82f, -0.88f);
	glVertex2f(-0.82f, -0.8675f);
     glVertex2f(-0.697f, -0.8675);
      glVertex2f(-0.72f, -0.88f);
	glEnd();

		glColor3ub(51,62,124);
	glBegin(GL_POLYGON);//..........................................boats lower
	glVertex2f(-0.72f, -0.88f);
	glVertex2f(-0.697f, -0.8675f);
     glVertex2f(-0.74f, -0.96f);
      glVertex2f(-0.76f, -0.96f);
	glEnd();

}


void shadowBuilding()
{
     glColor3ub(14,147,195); //-----
	glBegin(GL_QUADS);
    glVertex2f(0.63f,-0.56f);
    glVertex2f(0.63f,0.38f);
    glVertex2f(0.845f,0.14f);
    glVertex2f(0.845f,-0.56f);
glEnd();
     glColor3ub(235,255,245);  //--------window
     glBegin(GL_QUADS);
    glVertex2f(0.65f,0.21f);
    glVertex2f(0.65f,0.25f);
    glVertex2f(0.66f,0.25f);
    glVertex2f(0.66f,0.21f);

     glColor3ub(235,255,245);  //--------window
     glBegin(GL_QUADS);
    glVertex2f(0.67f,0.21f);
    glVertex2f(0.67f,0.25f);
    glVertex2f(0.68f,0.25f);
    glVertex2f(0.68f,0.21f);

      glColor3ub(235,255,245);  //--------window
     glBegin(GL_QUADS);
    glVertex2f(0.69f,0.21f);
    glVertex2f(0.69f,0.25f);
    glVertex2f(0.7f,0.25f);
    glVertex2f(0.7f,0.21f);
    ////
        glColor3ub(235,255,245);  //--------window
     glBegin(GL_QUADS);
    glVertex2f(0.65f,0.15f);
    glVertex2f(0.65f,0.19f);
    glVertex2f(0.66f,0.19f);
    glVertex2f(0.66f,0.15f);

     glColor3ub(235,255,245);  //--------window
     glBegin(GL_QUADS);
    glVertex2f(0.67f,0.15f);
    glVertex2f(0.67f,0.19f);
    glVertex2f(0.68f,0.19f);
    glVertex2f(0.68f,0.15f);

      glColor3ub(235,255,245);  //--------window
     glBegin(GL_QUADS);
    glVertex2f(0.69f,0.15f);
    glVertex2f(0.69f,0.19f);
    glVertex2f(0.7f,0.19f);
    glVertex2f(0.7f,0.15f);

      glColor3ub(235,255,245);  //--------window
     glBegin(GL_QUADS);
    glVertex2f(0.71f,0.15f);
    glVertex2f(0.71f,0.19f);
    glVertex2f(0.72f,0.19f);
    glVertex2f(0.72f,0.15f);

        glColor3ub(235,255,245);  //--------window
     glBegin(GL_QUADS);
    glVertex2f(0.73f,0.15f);
    glVertex2f(0.73f,0.19f);
    glVertex2f(0.74f,0.19f);
    glVertex2f(0.74f,0.15f);
        glColor3ub(235,255,245);  //--------window
     glBegin(GL_QUADS);
    glVertex2f(0.75f,0.15f);
    glVertex2f(0.75f,0.19f);
    glVertex2f(0.76f,0.19f);
    glVertex2f(0.76f,0.15f);
    ///////
          glColor3ub(235,255,245);  //--------window
     glBegin(GL_QUADS);
    glVertex2f(0.65f,0.09f);
    glVertex2f(0.65f,0.13f);
    glVertex2f(0.66f,0.13f);
    glVertex2f(0.66f,0.09f);
     glColor3ub(235,255,245);  //--------window
     glBegin(GL_QUADS);
    glVertex2f(0.67f,0.09f);
    glVertex2f(0.67f,0.13f);
    glVertex2f(0.68f,0.13f);
    glVertex2f(0.68f,0.09f);
      glColor3ub(235,255,245);  //--------window
     glBegin(GL_QUADS);
    glVertex2f(0.69f,0.09f);
    glVertex2f(0.69f,0.13f);
    glVertex2f(0.7f,0.13f);
    glVertex2f(0.7f,0.09f);
      glColor3ub(235,255,245);  //--------window
     glBegin(GL_QUADS);
    glVertex2f(0.71f,0.09f);
    glVertex2f(0.71f,0.13f);
    glVertex2f(0.72f,0.13f);
    glVertex2f(0.72f,0.09f);
        glColor3ub(235,255,245);  //--------window
     glBegin(GL_QUADS);
    glVertex2f(0.73f,0.09f);
    glVertex2f(0.73f,0.13f);
    glVertex2f(0.74f,0.13f);
    glVertex2f(0.74f,0.09f);
        glColor3ub(235,255,245);  //--------window
     glBegin(GL_QUADS);
    glVertex2f(0.75f,0.09f);
    glVertex2f(0.75f,0.13f);
    glVertex2f(0.76f,0.13f);
    glVertex2f(0.76f,0.09f);
        glColor3ub(235,255,245);  //--------window
     glBegin(GL_QUADS);
    glVertex2f(0.77f,0.09f);
    glVertex2f(0.77f,0.13f);
    glVertex2f(0.78f,0.13f);
    glVertex2f(0.78f,0.09f);
           glColor3ub(235,255,245);  //--------window
     glBegin(GL_QUADS);
    glVertex2f(0.79f,0.09f);
    glVertex2f(0.79f,0.13f);
    glVertex2f(0.80f,0.13f);
    glVertex2f(0.80f,0.09f);
          glColor3ub(235,255,245);  //--------window
     glBegin(GL_QUADS);
    glVertex2f(0.81f,0.09f);
    glVertex2f(0.81f,0.13f);
    glVertex2f(0.82f,0.13f);
    glVertex2f(0.82f,0.09f);
///////
 glColor3ub(235,255,245);  //--------window
     glBegin(GL_QUADS);
    glVertex2f(0.65f,0.03f);
    glVertex2f(0.65f,0.07f);
    glVertex2f(0.66f,0.07f);
    glVertex2f(0.66f,0.03f);
     glColor3ub(235,255,245);  //--------window
     glBegin(GL_QUADS);
    glVertex2f(0.67f,0.03f);
    glVertex2f(0.67f,0.07f);
    glVertex2f(0.68f,0.07f);
    glVertex2f(0.68f,0.03f);
      glColor3ub(235,255,245);  //--------window
     glBegin(GL_QUADS);
    glVertex2f(0.69f,0.03f);
    glVertex2f(0.69f,0.07f);
    glVertex2f(0.7f,0.07f);
    glVertex2f(0.7f,0.03f);
      glColor3ub(235,255,245);  //--------window
     glBegin(GL_QUADS);
    glVertex2f(0.71f,0.03f);
    glVertex2f(0.71f,0.07f);
    glVertex2f(0.72f,0.07f);
    glVertex2f(0.72f,0.03f);
        glColor3ub(235,255,245);  //--------window
     glBegin(GL_QUADS);
    glVertex2f(0.73f,0.03f);
    glVertex2f(0.73f,0.07f);
    glVertex2f(0.74f,0.07f);
    glVertex2f(0.74f,0.03f);
        glColor3ub(235,255,245);  //--------window
     glBegin(GL_QUADS);
    glVertex2f(0.75f,0.03f);
    glVertex2f(0.75f,0.07f);
    glVertex2f(0.76f,0.07f);
    glVertex2f(0.76f,0.03f);
        glColor3ub(235,255,245);  //--------window
     glBegin(GL_QUADS);
    glVertex2f(0.77f,0.03f);
    glVertex2f(0.77f,0.07f);
    glVertex2f(0.78f,0.07f);
    glVertex2f(0.78f,0.03f);
           glColor3ub(235,255,245);  //--------window
     glBegin(GL_QUADS);
    glVertex2f(0.79f,0.03f);
    glVertex2f(0.79f,0.07f);
    glVertex2f(0.80f,0.07f);
    glVertex2f(0.80f,0.03f);
          glColor3ub(235,255,245);  //--------window
     glBegin(GL_QUADS);
    glVertex2f(0.81f,0.03f);
    glVertex2f(0.81f,0.07f);
    glVertex2f(0.82f,0.07f);
    glVertex2f(0.82f,0.03f);
    /////
     glColor3ub(235,255,245);  //--------window
     glBegin(GL_QUADS);
    glVertex2f(0.65f,-0.03f);
    glVertex2f(0.65f,0.01f);
    glVertex2f(0.66f,0.01f);
    glVertex2f(0.66f,-0.03f);
     glColor3ub(235,255,245);  //--------window
     glBegin(GL_QUADS);
    glVertex2f(0.67f,-0.03f);
    glVertex2f(0.67f,0.01f);
    glVertex2f(0.68f,0.01f);
    glVertex2f(0.68f,-0.03f);
      glColor3ub(235,255,245);  //--------window
     glBegin(GL_QUADS);
    glVertex2f(0.69f,-0.03f);
    glVertex2f(0.69f,0.01f);
    glVertex2f(0.7f,0.01f);
    glVertex2f(0.7f,-0.03f);
      glColor3ub(235,255,245);  //--------window
     glBegin(GL_QUADS);
    glVertex2f(0.71f,-0.03f);
    glVertex2f(0.71f,0.01f);
    glVertex2f(0.72f,0.01f);
    glVertex2f(0.72f,-0.03f);
        glColor3ub(235,255,245);  //--------window
     glBegin(GL_QUADS);
    glVertex2f(0.73f,-0.03f);
    glVertex2f(0.73f,0.01f);
    glVertex2f(0.74f,0.01f);
    glVertex2f(0.74f,-0.03f);
        glColor3ub(235,255,245);  //--------window
     glBegin(GL_QUADS);
    glVertex2f(0.75f,-0.03f);
    glVertex2f(0.75f,0.01f);
    glVertex2f(0.76f,0.01f);
    glVertex2f(0.76f,-0.03f);
        glColor3ub(235,255,245);  //--------window
     glBegin(GL_QUADS);
    glVertex2f(0.77f,-0.03f);
    glVertex2f(0.77f,0.01f);
    glVertex2f(0.78f,0.01f);
    glVertex2f(0.78f,-0.03f);
           glColor3ub(235,255,245);  //--------window
     glBegin(GL_QUADS);
    glVertex2f(0.79f,-0.03f);
    glVertex2f(0.79f,0.01f);
    glVertex2f(0.80f,0.01f);
    glVertex2f(0.80f,-0.03f);
          glColor3ub(235,255,245);  //--------window
     glBegin(GL_QUADS);
    glVertex2f(0.81f,-0.03f);
    glVertex2f(0.81f,0.01f);
    glVertex2f(0.82f,0.01f);
    glVertex2f(0.82f,-0.03f);
    //////
        glColor3ub(235,255,245);  //--------window
     glBegin(GL_QUADS);
    glVertex2f(0.65f,-0.09f);
    glVertex2f(0.65f,-0.05f);
    glVertex2f(0.66f,-0.05f);
    glVertex2f(0.66f,-0.09f);
     glColor3ub(235,255,245);  //--------window
     glBegin(GL_QUADS);
    glVertex2f(0.67f,-0.09f);
    glVertex2f(0.67f,-0.05f);
    glVertex2f(0.68f,-0.05f);
    glVertex2f(0.68f,-0.09f);
      glColor3ub(235,255,245);  //--------window
     glBegin(GL_QUADS);
    glVertex2f(0.69f,-0.09f);
    glVertex2f(0.69f,-0.05f);
    glVertex2f(0.7f,-0.05f);
    glVertex2f(0.7f,-0.09f);
      glColor3ub(235,255,245);  //--------window
     glBegin(GL_QUADS);
    glVertex2f(0.71f,-0.09f);
    glVertex2f(0.71f,-0.05f);
    glVertex2f(0.72f,-0.05f);
    glVertex2f(0.72f,-0.09f);
        glColor3ub(235,255,245);  //--------window
     glBegin(GL_QUADS);
    glVertex2f(0.73f,-0.09f);
    glVertex2f(0.73f,-0.05f);
    glVertex2f(0.74f,-0.05f);
    glVertex2f(0.74f,-0.09f);
        glColor3ub(235,255,245);  //--------window
     glBegin(GL_QUADS);
    glVertex2f(0.75f,-0.09f);
    glVertex2f(0.75f,-0.05f);
    glVertex2f(0.76f,-0.05f);
    glVertex2f(0.76f,-0.09f);
        glColor3ub(235,255,245);  //--------window
     glBegin(GL_QUADS);
    glVertex2f(0.77f,-0.09f);
    glVertex2f(0.77f,-0.05f);
    glVertex2f(0.78f,-0.05f);
    glVertex2f(0.78f,-0.09f);
           glColor3ub(235,255,245);  //--------window
     glBegin(GL_QUADS);
    glVertex2f(0.79f,-0.09f);
    glVertex2f(0.79f,-0.05f);
    glVertex2f(0.80f,-0.05f);
    glVertex2f(0.80f,-0.09f);
          glColor3ub(235,255,245);  //--------window
     glBegin(GL_QUADS);
    glVertex2f(0.81f,-0.09f);
    glVertex2f(0.81f,-0.05f);
    glVertex2f(0.82f,-0.05f);
    glVertex2f(0.82f,-0.09f);
    //////
            glColor3ub(235,255,245);  //--------window
     glBegin(GL_QUADS);
    glVertex2f(0.65f,-0.15f);
    glVertex2f(0.65f,-0.11f);
    glVertex2f(0.66f,-0.11f);
    glVertex2f(0.66f,-0.15f);
     glColor3ub(235,255,245);  //--------window
     glBegin(GL_QUADS);
    glVertex2f(0.67f,-0.15f);
    glVertex2f(0.67f,-0.11f);
    glVertex2f(0.68f,-0.11f);
    glVertex2f(0.68f,-0.15f);
      glColor3ub(235,255,245);  //--------window
     glBegin(GL_QUADS);
    glVertex2f(0.69f,-0.15f);
    glVertex2f(0.69f,-0.11f);
    glVertex2f(0.7f,-0.11f);
    glVertex2f(0.7f,-0.15f);
      glColor3ub(235,255,245);  //--------window
     glBegin(GL_QUADS);
    glVertex2f(0.71f,-0.15f);
    glVertex2f(0.71f,-0.11f);
    glVertex2f(0.72f,-0.11f);
    glVertex2f(0.72f,-0.15f);
        glColor3ub(235,255,245);  //--------window
     glBegin(GL_QUADS);
    glVertex2f(0.73f,-0.15f);
    glVertex2f(0.73f,-0.11f);
    glVertex2f(0.74f,-0.11f);
    glVertex2f(0.74f,-0.15f);
        glColor3ub(235,255,245);  //--------window
     glBegin(GL_QUADS);
    glVertex2f(0.75f,-0.15f);
    glVertex2f(0.75f,-0.11f);
    glVertex2f(0.76f,-0.11f);
    glVertex2f(0.76f,-0.15f);
        glColor3ub(235,255,245);  //--------window
     glBegin(GL_QUADS);
    glVertex2f(0.77f,-0.15f);
    glVertex2f(0.77f,-0.11f);
    glVertex2f(0.78f,-0.11f);
    glVertex2f(0.78f,-0.15f);
           glColor3ub(235,255,245);  //--------window
     glBegin(GL_QUADS);
    glVertex2f(0.79f,-0.15f);
    glVertex2f(0.79f,-0.11f);
    glVertex2f(0.80f,-0.11f);
    glVertex2f(0.80f,-0.15f);
          glColor3ub(235,255,245);  //--------window
     glBegin(GL_QUADS);
    glVertex2f(0.81f,-0.15f);
    glVertex2f(0.81f,-0.11f);
    glVertex2f(0.82f,-0.11f);
    glVertex2f(0.82f,-0.15f);
    /////

                glColor3ub(235,255,245);  //--------window
     glBegin(GL_QUADS);
    glVertex2f(0.65f,-0.21f);
    glVertex2f(0.65f,-0.17f);
    glVertex2f(0.66f,-0.17f);
    glVertex2f(0.66f,-0.21f);
     glColor3ub(235,255,245);  //--------window
     glBegin(GL_QUADS);
    glVertex2f(0.67f,-0.21f);
    glVertex2f(0.67f,-0.17f);
    glVertex2f(0.68f,-0.17f);
    glVertex2f(0.68f,-0.21f);
      glColor3ub(235,255,245);  //--------window
     glBegin(GL_QUADS);
    glVertex2f(0.69f,-0.21f);
    glVertex2f(0.69f,-0.17f);
    glVertex2f(0.7f,-0.17f);
    glVertex2f(0.7f,-0.21f);
      glColor3ub(235,255,245);  //--------window
     glBegin(GL_QUADS);
    glVertex2f(0.71f,-0.21f);
    glVertex2f(0.71f,-0.17f);
    glVertex2f(0.72f,-0.17f);
    glVertex2f(0.72f,-0.21f);
        glColor3ub(235,255,245);  //--------window
     glBegin(GL_QUADS);
    glVertex2f(0.73f,-0.21f);
    glVertex2f(0.73f,-0.17f);
    glVertex2f(0.74f,-0.17f);
    glVertex2f(0.74f,-0.21f);
        glColor3ub(235,255,245);  //--------window
     glBegin(GL_QUADS);
    glVertex2f(0.75f,-0.21f);
    glVertex2f(0.75f,-0.17f);
    glVertex2f(0.76f,-0.17f);
    glVertex2f(0.76f,-0.21f);
        glColor3ub(235,255,245);  //--------window
     glBegin(GL_QUADS);
    glVertex2f(0.77f,-0.21f);
    glVertex2f(0.77f,-0.17f);
    glVertex2f(0.78f,-0.17f);
    glVertex2f(0.78f,-0.21f);
           glColor3ub(235,255,245);  //--------window
     glBegin(GL_QUADS);
    glVertex2f(0.79f,-0.21f);
    glVertex2f(0.79f,-0.17f);
    glVertex2f(0.80f,-0.17f);
    glVertex2f(0.80f,-0.21f);
          glColor3ub(235,255,245);  //--------window
     glBegin(GL_QUADS);
    glVertex2f(0.81f,-0.21f);
    glVertex2f(0.81f,-0.17f);
    glVertex2f(0.82f,-0.17f);
    glVertex2f(0.82f,-0.21f);

    /////
                glColor3ub(235,255,245);  //--------window
     glBegin(GL_QUADS);
    glVertex2f(0.65f,-0.23f);
    glVertex2f(0.65f,-0.19f);
    glVertex2f(0.66f,-0.19f);
    glVertex2f(0.66f,-0.23f);
     glColor3ub(235,255,245);  //--------window
     glBegin(GL_QUADS);
    glVertex2f(0.67f,-0.23f);
    glVertex2f(0.67f,-0.19f);
    glVertex2f(0.68f,-0.19f);
    glVertex2f(0.68f,-0.23f);
      glColor3ub(235,255,245);  //--------window
     glBegin(GL_QUADS);
    glVertex2f(0.69f,-0.23f);
    glVertex2f(0.69f,-0.19f);
    glVertex2f(0.7f,-0.19f);
    glVertex2f(0.7f,-0.23f);
      glColor3ub(235,255,245);  //--------window
     glBegin(GL_QUADS);
    glVertex2f(0.71f,-0.23f);
    glVertex2f(0.71f,-0.19f);
    glVertex2f(0.72f,-0.19f);
    glVertex2f(0.72f,-0.23f);
        glColor3ub(235,255,245);  //--------window
     glBegin(GL_QUADS);
    glVertex2f(0.73f,-0.23f);
    glVertex2f(0.73f,-0.19f);
    glVertex2f(0.74f,-0.19f);
    glVertex2f(0.74f,-0.23f);
        glColor3ub(235,255,245);  //--------window
     glBegin(GL_QUADS);
    glVertex2f(0.75f,-0.23f);
    glVertex2f(0.75f,-0.19f);
    glVertex2f(0.76f,-0.19f);
    glVertex2f(0.76f,-0.23f);
        glColor3ub(235,255,245);  //--------window
     glBegin(GL_QUADS);
    glVertex2f(0.77f,-0.23f);
    glVertex2f(0.77f,-0.19f);
    glVertex2f(0.78f,-0.19f);
    glVertex2f(0.78f,-0.23f);
           glColor3ub(235,255,245);  //--------window
     glBegin(GL_QUADS);
    glVertex2f(0.79f,-0.23f);
    glVertex2f(0.79f,-0.19f);
    glVertex2f(0.80f,-0.19f);
    glVertex2f(0.80f,-0.23f);
          glColor3ub(235,255,245);  //--------window
     glBegin(GL_QUADS);
    glVertex2f(0.81f,-0.23f);
    glVertex2f(0.81f,-0.19f);
    glVertex2f(0.82f,-0.19f);
    glVertex2f(0.82f,-0.23f);

//////
             glColor3ub(235,255,245);  //--------window
     glBegin(GL_QUADS);
    glVertex2f(0.65f,-0.29f);
    glVertex2f(0.65f,-0.25f);
    glVertex2f(0.66f,-0.25f);
    glVertex2f(0.66f,-0.29f);
     glColor3ub(235,255,245);  //--------window
     glBegin(GL_QUADS);
    glVertex2f(0.67f,-0.29f);
    glVertex2f(0.67f,-0.25f);
    glVertex2f(0.68f,-0.25f);
    glVertex2f(0.68f,-0.29f);
      glColor3ub(235,255,245);  //--------window
     glBegin(GL_QUADS);
    glVertex2f(0.69f,-0.29f);
    glVertex2f(0.69f,-0.25f);
    glVertex2f(0.7f,-0.25f);
    glVertex2f(0.7f,-0.29f);
      glColor3ub(235,255,245);  //--------window
     glBegin(GL_QUADS);
    glVertex2f(0.71f,-0.29f);
    glVertex2f(0.71f,-0.25f);
    glVertex2f(0.72f,-0.25f);
    glVertex2f(0.72f,-0.29f);
        glColor3ub(235,255,245);  //--------window
     glBegin(GL_QUADS);
    glVertex2f(0.73f,-0.29f);
    glVertex2f(0.73f,-0.25f);
    glVertex2f(0.74f,-0.25f);
    glVertex2f(0.74f,-0.29f);


glEnd();




}




void Building()
{

	 glColor3ub(14,147,195); //-----light tower lower floor
	glBegin(GL_QUADS);
    glVertex2f(-0.75f,-0.59f);
    glVertex2f(-0.5f,-0.59f);
    glVertex2f(-0.51f,-0.4f);
    glVertex2f(-0.74f,-0.4f);
// text

   glColor3ub(14,147,195);  //--------light tower top floor
    glVertex2f(-0.72f,0.3f);
    glVertex2f(-0.52f,0.3f);
    glVertex2f(-0.52f,0.4f);
    glVertex2f(-0.72f,0.4f);

    glColor3ub(14,147,195); //----------light tower
    glVertex2f(-0.74f,-0.4f);
    glVertex2f(-0.51f,-0.4f);
    glVertex2f(-0.52f,0.3f);
    glVertex2f(-0.72f,0.3f);

	glEnd();

glPushMatrix();
    glTranslatef(-0.62,0.45,0);
    glScalef(0.08,0.08,1);
   //------light tower matha
glPopMatrix();

    glColor3ub(0,172,235); //----- light tower triangle
    glBegin(GL_TRIANGLES);
    glVertex2f(-0.6f,0.55f);
    glVertex2f(-0.64f,0.55f);
    glVertex2f(-0.62f,0.7f);
	glEnd();

	glColor3ub(183, 237, 255); //------- light tower er mathar janala
    glBegin(GL_QUADS);
  glVertex2f(-0.7f,0.4f);
    glVertex2f(-0.53f,0.4f);
    glVertex2f(-0.53f,0.55f);
    glVertex2f(-0.7f,0.55f);

     glColor3ub(14,147,195); //------- trangle er nicher square
    glVertex2f(-0.66f,0.55f);
    glVertex2f(-0.58f,0.55f);
    glVertex2f(-0.58f,0.5f);
    glVertex2f(-0.66f,0.5f);

   glColor3ub(183, 237, 255); //------- light tower er sob light ------------ (183, 237, 255);-------------------------------------


    glVertex2f(-0.55f,0.44f);
    glVertex2f(-0.68f,0.44f);
    glVertex2f(-0.68f,0.47f);
    glVertex2f(-0.55f,0.47f);



    glVertex2f(-0.6f,0.31f);
    glVertex2f(-0.63f,0.31f);
    glVertex2f(-0.63f,0.34f);
    glVertex2f(-0.6f,0.34f);

    glVertex2f(-0.65f,0.31f);
    glVertex2f(-0.68f,0.31f);
    glVertex2f(-0.68f,0.34f);
    glVertex2f(-0.65f,0.34f);

    glVertex2f(-0.7f,0.31f);
    glVertex2f(-0.72f,0.31f);
    glVertex2f(-0.72f,0.34f);
    glVertex2f(-0.7f,0.34f);

    glVertex2f(-0.55f,0.31f);
    glVertex2f(-0.58f,0.31f);
    glVertex2f(-0.58f,0.34f);
    glVertex2f(-0.55f,0.34f);

    glVertex2f(-0.52f,0.31f);
    glVertex2f(-0.53f,0.31f);
    glVertex2f(-0.53f,0.34f);
    glVertex2f(-0.52f,0.34f);

    glVertex2f(-0.6f,0.21f);
    glVertex2f(-0.63f,0.21f);
    glVertex2f(-0.63f,0.24f);
    glVertex2f(-0.6f,0.24f);

    glVertex2f(-0.6f,0.11f);
    glVertex2f(-0.63f,0.11f);
    glVertex2f(-0.63f,0.14f);
    glVertex2f(-0.6f,0.14f);

    glVertex2f(-0.6f,0.01f);
    glVertex2f(-0.63f,0.01f);
    glVertex2f(-0.63f,0.04f);
    glVertex2f(-0.6f,0.04f);

    glVertex2f(-0.6f,-0.05f);
    glVertex2f(-0.63f,-0.05f);
    glVertex2f(-0.63f,-0.08f);
    glVertex2f(-0.6f,-0.08f);

    glVertex2f(-0.6f,-0.15f);
    glVertex2f(-0.63f,-0.15f);
    glVertex2f(-0.63f,-0.18f);
    glVertex2f(-0.6f,-0.18f);

    glVertex2f(-0.6f,-0.25f);
    glVertex2f(-0.63f,-0.25f);
    glVertex2f(-0.63f,-0.28f);
    glVertex2f(-0.6f,-0.28f);

    glVertex2f(-0.6f,-0.35f);
    glVertex2f(-0.63f,-0.35f);
    glVertex2f(-0.63f,-0.38f);
    glVertex2f(-0.6f,-0.38f);

 glColor3ub(11, 84, 111); //------ light tower ground floor
    glVertex2f(-0.51f,-0.45f);
    glVertex2f(-0.6f,-0.45f);
    glVertex2f(-0.6f,-0.59f);
    glVertex2f(-0.51f,-0.59f);

	glEnd();

glPushMatrix();
    glTranslatef(-0.95,-0.59,0);
    glBegin(GL_POLYGON);
	for(int i=0;i<200;i++)
        {
            glColor3ub(30,78,95); //---------bam pasher dim building
            float pi=3.1416/2;
            float A=(i*2*pi)/200;
            float r=0.4;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x,y);
        }

	glEnd();
	glBegin(GL_POLYGON);
	for(int i=0;i<200;i++)
        {
            glColor3ub(141,225,255);      //---------bam pasher dim building
            float pi=3.1416/4;
            float A=(i*2*pi)/200;
            float r=0.4;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x,y);
        }

	glEnd();
glPopMatrix();



glColor3ub(7,1196,165); //------ dim buidling er bam glass
    glBegin(GL_QUADS);

    glVertex2f(-1.0f,-0.55f);
    glVertex2f(-0.95f,-0.55f);
    glVertex2f(-0.95f,-0.5f);
    glVertex2f(-1.0f,-0.5f);

  glColor3ub(7,1196,165); //-------dim building er pasher glass
    glVertex2f(-0.8f,-0.55f);
    glVertex2f(-0.65f,-0.55f);
    glVertex2f(-0.65f,-0.5f);
    glVertex2f(-0.8f,-0.5f);

	glEnd();

//-------- dan pasher building start



	glPushMatrix();
    glTranslatef(0.95,-0.59,0);
    glBegin(GL_POLYGON);
	for(int i=0;i<200;i++)
        {
            glColor3ub(90,101,102); //---------bam pasher dim building
            float pi=3.1416/2;
            float A=(i*2*pi)/200;
            float r=0.4;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x,y);
        }

	glEnd();
	glBegin(GL_POLYGON);
	for(int i=0;i<200;i++)
        {
            glColor3ub(172,184,186);      //---------bam pasher dim building
            float pi=3.1416/4;
            float A=(i*2*pi)/200;
            float r=0.4;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x,y);
        }

	glEnd();
glPopMatrix();

   glColor3ub(75, 147, 158); //------ dim buidling er part dhaka pore
    glBegin(GL_QUADS);
    glVertex2f(0.65f,-0.33f);
    glVertex2f(1.0f,-0.33f);
    glVertex2f(1.0f,-0.38f);
    glVertex2f(0.6f,-0.38f);


  glColor3ub(98, 183, 196); //------ dim buidling er sada glass
    glBegin(GL_QUADS);
    glVertex2f(-0.65f,-0.33f);
    glVertex2f(-1.0f,-0.33f);
    glVertex2f(-1.0f,-0.38f);
    glVertex2f(-0.6f,-0.38f);

    glColor3ub(98, 183, 196); //------ dim buidling er bam glass
    glBegin(GL_QUADS);

    glVertex2f(1.0f,-0.55f);
    glVertex2f(0.95f,-0.55f);
    glVertex2f(0.95f,-0.5f);
    glVertex2f(1.0f,-0.5f);
 glColor3ub(98, 183, 196);//-------dim building er pasher glass
    glVertex2f(0.8f,-0.55f);
    glVertex2f(0.65f,-0.55f);
    glVertex2f(0.65f,-0.5f);
    glVertex2f(0.8f,-0.5f);

	glEnd();


	glColor3ub(0,111 ,145); //------ ground block
    glBegin(GL_QUADS);
    glVertex2f(-0.5f,0.4f);
    glVertex2f(-0.07f,0.4f);
    glVertex2f(-0.07f,-0.6f);
    glVertex2f(-0.5f,-0.6f);




 glColor3ub(92, 92, 92);    //---matha
    glVertex2f(-0.5f,0.4f);
    glVertex2f(-0.07f,0.4f);
    glVertex2f(-0.07f,0.33f);
    glVertex2f(-0.5f,0.33f);


 glColor3ub(22, 198, 223);    //---matha
    glVertex2f(-0.5f,0.3f);
    glVertex2f(-0.07f,0.3f);
    glVertex2f(-0.07f,0.25f);
    glVertex2f(-0.5f,0.25f);



    glVertex2f(-0.5f,0.2f);
    glVertex2f(-0.07f,0.2f);
    glVertex2f(-0.07f,0.15f);
    glVertex2f(-0.5f,0.15f);



    glVertex2f(-0.5f,0.1f);
    glVertex2f(-0.07f,0.1f);
    glVertex2f(-0.07f,0.05);
    glVertex2f(-0.5f,0.05f);

  glVertex2f(-0.5f,0.0f);
    glVertex2f(-0.07f,0.0f);
    glVertex2f(-0.07f,-0.05);
    glVertex2f(-0.5f,-0.05f);

  glVertex2f(-0.5f,-0.1f);
    glVertex2f(-0.07f,-0.1f);
    glVertex2f(-0.07f,-0.15);
    glVertex2f(-0.5f,-0.15f);


     glVertex2f(-0.5f,-0.2f);
    glVertex2f(-0.07f,-0.2f);
    glVertex2f(-0.07f,-0.25);
    glVertex2f(-0.5f,-0.25f);


     glVertex2f(-0.5f,-0.3f);
    glVertex2f(-0.07f,-0.3f);
    glVertex2f(-0.07f,-0.35);
    glVertex2f(-0.5f,-0.35f);



      glVertex2f(-0.5f,-0.4f);
    glVertex2f(-0.07f,-0.4f);
    glVertex2f(-0.07f,-0.45);
    glVertex2f(-0.5f,-0.45f);


      glVertex2f(-0.5f,-0.5f);
    glVertex2f(-0.07f,-0.5f);
    glVertex2f(-0.07f,-0.55);
    glVertex2f(-0.5f,-0.55f);


	glEnd();





	//---------  building no 2 end







glPushMatrix();
    glTranslatef(0.105,0.51,0);
    glBegin(GL_POLYGON);
	for(int i=0;i<200;i++)
        {
            glColor3ub(0,128,166); //----------pasher dim er matha
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=0.21;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x,y);
        }

	glEnd();
	glBegin(GL_POLYGON);
	for(int i=0;i<200;i++)
        {
            glColor3ub(148,234,255); //----------vitor er colour
            float pi=3.1416/2;
            float A=(i*2*pi)/200;
            float r=0.17;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x,y);
        }

	glEnd();
glPopMatrix();

    glBegin(GL_QUADS);

	glColor3ub(11, 84, 111);    //----bottom
    glVertex2f(-0.05f,-0.59f);
    glVertex2f(0.26f,-0.59f);
    glVertex2f(0.26f,-0.38f);
    glVertex2f(-0.05f,-0.38f);

    glColor3ub(0,128,166); //--------main body
    glVertex2f(-0.05f,-0.38f);
    glVertex2f(0.26f,-0.38f);
    glVertex2f(0.26f,0.38f);
    glVertex2f(-0.05f,0.38f);


        glColor3ub(148,234,255); //--------main body block
    glVertex2f(0.05f,-0.2f);
    glVertex2f(0.15f,-0.2f);
    glVertex2f(0.15f,0.2f);
    glVertex2f(0.05f,0.2f);


    glColor3ub(252,252,252);    //---matha
    glVertex2f(-0.15f,0.4f);
    glVertex2f(0.36f,0.4f);
    glVertex2f(0.36f,0.33f);
    glVertex2f(-0.15f,0.33f);

	glEnd();

    glBegin(GL_LINES);

	glColor3ub(0, 123, 161);
    glVertex2f(-0.05f,0.59f);
    glVertex2f(0.26f,0.59f);

    glVertex2f(0.0f,0.5f);
    glVertex2f(0.07f,0.68f);

    glVertex2f(0.2f,0.5f);
    glVertex2f(0.13f,0.68f);

	glEnd();

    glBegin(GL_QUADS);

	glColor3ub(181,237,255);        //--------lights
    glVertex2f(-0.15f,0.39f);
    glVertex2f(-0.1f,0.39f);
    glVertex2f(-0.1f,0.34f);
    glVertex2f(-0.15f,0.34f);

    glVertex2f(-0.05f,0.39f);
    glVertex2f(-0.0f,0.39f);
    glVertex2f(-0.0f,0.34f);
    glVertex2f(-0.05f,0.34f);

    glVertex2f(0.05f,0.39f);
    glVertex2f(0.1f,0.39f);
    glVertex2f(0.1f,0.34f);
    glVertex2f(0.05f,0.34f);

    glVertex2f(0.15f,0.39f);
    glVertex2f(0.2f,0.39f);
    glVertex2f(0.2f,0.34f);
    glVertex2f(0.15f,0.34f);

    glVertex2f(0.25f,0.39f);
    glVertex2f(0.3f,0.39f);
    glVertex2f(0.3f,0.34f);
    glVertex2f(0.25f,0.34f);

    glVertex2f(0.35f,0.39f);
    glVertex2f(0.36f,0.39f);
    glVertex2f(0.36f,0.34f);
    glVertex2f(0.35f,0.34f);

    glVertex2f(-0.0f,0.28f);
    glVertex2f(-0.05f,0.28f);
    glVertex2f(-0.05f,0.2f);
    glVertex2f(-0.0f,0.2f);

    glVertex2f(0.21f,0.28f);
    glVertex2f(0.26f,0.28f);
    glVertex2f(0.26f,0.2f);
    glVertex2f(0.21f,0.2f);

    glVertex2f(-0.0f,0.18f);
    glVertex2f(-0.05f,0.18f);
    glVertex2f(-0.05f,0.1f);
    glVertex2f(-0.0f,0.1f);

    glVertex2f(0.21f,0.18f);
    glVertex2f(0.26f,0.18f);
    glVertex2f(0.26f,0.1f);
    glVertex2f(0.21f,0.1f);

    glVertex2f(-0.0f,0.08f);
    glVertex2f(-0.05f,0.08f);
    glVertex2f(-0.05f,0.0f);
    glVertex2f(-0.0f,0.0f);

    glVertex2f(0.21f,0.08f);
    glVertex2f(0.26f,0.08f);
    glVertex2f(0.26f,0.0f);
    glVertex2f(0.21f,0.0f);

    glVertex2f(-0.0f,-0.02f);
    glVertex2f(-0.05f,-0.02f);
    glVertex2f(-0.05f,-0.1f);
    glVertex2f(-0.0f,-0.1f);

    glVertex2f(0.21f,-0.02f);
    glVertex2f(0.26f,-0.02f);
    glVertex2f(0.26f,-0.1f);
    glVertex2f(0.21f,-0.1f);

    glVertex2f(-0.0f,-0.12f);
    glVertex2f(-0.05f,-0.12f);
    glVertex2f(-0.05f,-0.2f);
    glVertex2f(-0.0f,-0.2f);

    glVertex2f(0.21f,-0.12f);
    glVertex2f(0.26f,-0.12f);
    glVertex2f(0.26f,-0.2f);
    glVertex2f(0.21f,-0.2f);

    glVertex2f(-0.0f,-0.22f);
    glVertex2f(-0.05f,-0.22f);
    glVertex2f(-0.05f,-0.3f);
    glVertex2f(-0.0f,-0.3f);

    glVertex2f(0.21f,-0.22f);
    glVertex2f(0.26f,-0.22f);
    glVertex2f(0.26f,-0.3f);
    glVertex2f(0.21f,-0.3f);

	glEnd();

    glBegin(GL_QUADS);

	glColor3ub(71, 142, 178); //-------pasher building block
    glVertex2f(0.3f,-0.59f);
    glVertex2f(0.4f,-0.59f);
    glVertex2f(0.4f,0.28f);
    glVertex2f(0.3f,0.28f);


    glColor3ub(50, 102, 128); //-------pasher building tan
    glVertex2f(0.32f,-0.59f);
    glVertex2f(0.335f,-0.59f);
    glVertex2f(0.335f,0.28f);
    glVertex2f(0.32f,0.28f);

     glColor3ub(50, 102, 128); //-------pasher building tan
    glVertex2f(0.34f,-0.59f);
    glVertex2f(0.345f,-0.59f);
    glVertex2f(0.345f,0.28f);
    glVertex2f(0.34f,0.28f);



     glColor3ub(50, 102, 128); //-------pasher building tan
    glVertex2f(0.35f,-0.59f);
    glVertex2f(0.365f,-0.59f);
    glVertex2f(0.365f,0.28f);
    glVertex2f(0.35f,0.28f);

     glColor3ub(50, 102, 128); //-------pasher building tan
    glVertex2f(0.38f,-0.59f);
    glVertex2f(0.375f,-0.59f);
    glVertex2f(0.375f,0.28f);
    glVertex2f(0.38f,0.28f);



    glColor3ub(80,208,240); //------- bulding colour
    glVertex2f(0.4f,-0.59f);
    glVertex2f(0.56f,-0.59f);
    glVertex2f(0.56f,0.28f);
    glVertex2f(0.4f,0.28f);


    glColor3ub(161,237,255);       //------ colour
    glVertex2f(0.43f,0.25f);
    glVertex2f(0.47f,0.25f);
    glVertex2f(0.47f,0.15f);
    glVertex2f(0.43f,0.15f);

    glColor3ub(195,236,255); // janla
    glVertex2f(0.48f,0.25f);
    glVertex2f(0.52f,0.25f);
    glVertex2f(0.52f,0.15f);
    glVertex2f(0.48f,0.15f);

    glColor3ub(161,237,255);      //----janla
    glVertex2f(0.53f,0.25f);
    glVertex2f(0.56f,0.25f);
    glVertex2f(0.56f,0.15f);
    glVertex2f(0.53f,0.15f);

    glVertex2f(0.43f,0.14f);
    glVertex2f(0.47f,0.14f);
    glVertex2f(0.47f,0.04f);
    glVertex2f(0.43f,0.04f);

    glVertex2f(0.48f,0.14f);
    glVertex2f(0.52f,0.14f);
    glVertex2f(0.52f,0.04f);
    glVertex2f(0.48f,0.04f);

    glColor3ub(161,237,255);
    glVertex2f(0.53f,0.14f);
    glVertex2f(0.56f,0.14f);
    glVertex2f(0.56f,0.04f);
    glVertex2f(0.53f,0.04f);

    glColor3ub(195,236,255);
    glVertex2f(0.43f,0.03f);
    glVertex2f(0.47f,0.03f);
    glVertex2f(0.47f,-0.07f);
    glVertex2f(0.43f,-0.07f);

    glColor3ub(161,237,255);
    glVertex2f(0.48f,0.03f);
    glVertex2f(0.52f,0.03f);
    glVertex2f(0.52f,-0.07f);
    glVertex2f(0.48f,-0.07f);

    glColor3ub(161,237,255);
    glVertex2f(0.53f,0.03f);
    glVertex2f(0.56f,0.03f);
    glVertex2f(0.56f,-0.07f);
    glVertex2f(0.53f,-0.07f);

    glVertex2f(0.43f,-0.08f);
    glVertex2f(0.47f,-0.08f);
    glVertex2f(0.47f,-0.18f);
    glVertex2f(0.43f,-0.18f);

    glVertex2f(0.48f,-0.08f);
    glVertex2f(0.52f,-0.08f);
    glVertex2f(0.52f,-0.18f);
    glVertex2f(0.48f,-0.18f);

    glColor3ub(195,236,255);
    glVertex2f(0.53f,-0.08f);
    glVertex2f(0.56f,-0.08f);
    glVertex2f(0.56f,-0.18f);
    glVertex2f(0.53f,-0.18f);

    glVertex2f(0.43f,-0.19f);
    glVertex2f(0.47f,-0.19f);
    glVertex2f(0.47f,-0.29f);
    glVertex2f(0.43f,-0.29f);

    glColor3ub(161,237,255);
    glVertex2f(0.48f,-0.19f);
    glVertex2f(0.52f,-0.19f);
    glVertex2f(0.52f,-0.29f);
    glVertex2f(0.48f,-0.29f);

    glColor3ub(161,237,255);
    glVertex2f(0.53f,-0.19f);
    glVertex2f(0.56f,-0.19f);
    glVertex2f(0.56f,-0.29f);
    glVertex2f(0.53f,-0.29f);

    glVertex2f(0.43f,-0.3f);
    glVertex2f(0.47f,-0.3f);
    glVertex2f(0.47f,-0.4f);
    glVertex2f(0.43f,-0.4f);

    glColor3ub(195,236,255);
    glVertex2f(0.48f,-0.3f);
    glVertex2f(0.52f,-0.3f);
    glVertex2f(0.52f,-0.4f);
    glVertex2f(0.48f,-0.4f);

    glVertex2f(0.53f,-0.3f);
    glVertex2f(0.56f,-0.3f);
    glVertex2f(0.56f,-0.4f);
    glVertex2f(0.53f,-0.4f);

    glVertex2f(0.43f,-0.41f);
    glVertex2f(0.47f,-0.41f);
    glVertex2f(0.47f,-0.51f);
    glVertex2f(0.43f,-0.51f);

    glColor3ub(161,237,255);
    glVertex2f(0.48f,-0.41f);
    glVertex2f(0.52f,-0.41f);
    glVertex2f(0.52f,-0.51f);
    glVertex2f(0.48f,-0.51f);

    glColor3ub(195,236,255);
    glVertex2f(0.53f,-0.41f);
    glVertex2f(0.56f,-0.41f);
    glVertex2f(0.56f,-0.51f);
    glVertex2f(0.53f,-0.51f);

	glEnd();


	glColor3f(1.0f, 1.0f, 1.0f); // Text color (white)
glRasterPos2f(-0.67f, 0.35f); // Position for the text

const char* text = "Light Tower";
for (const char* c = text; *c != '\0'; c++)
{
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, *c); // Larger font for bolder effect
}



// Add  text on the roof of the hospital
glColor3f(1.0f, 1.0f, 1.0f); // Text color (white)

// Slight offsets for bold effect
float offset = 0.001f;

// Draw the text multiple times with slight offsets
for (float dx = -offset; dx <= offset; dx += offset)
{
    for (float dy = -offset; dy <= offset; dy += offset)
    {
        glRasterPos2f(-0.47f + dx, 0.35f + dy); // Adjust position for each pass
        const char* text1 = "Ibn-Sina Hospital";
        for (const char* c = text1; *c != '\0'; c++)
        {
            glutBitmapCharacter(GLUT_BITMAP_9_BY_15, *c); // Use smaller font
        }
    }
}

//add text on taj hotel

	glColor3f(1.0f, 1.0f, 1.0f); // Text color (white)
glRasterPos2f(0.02f, 0.42f); // Position for the text

const char* text3 = "Grand Taj Hotel";
for (const char* c = text3; *c != '\0'; c++)
{
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, *c); // Larger font for bolder effect
}

// Add vertical text on residential
glColor3f(1.0f, 1.0f, 1.0f); // Text color (white)

// Position for the first character
float x = 0.4f;
float y = 0.17f;

const char* text4 = "CITY COUNCILL";
for (const char* c = text4; *c != '\0'; c++) {
    glRasterPos2f(x, y); // Set position for each character
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, *c); // Larger font for vertical text
    y -= 0.05f; // Move the position down for the next character
}


}




//===============================================================================================================================================


void updatePlane(int value) {

    if(planeposition <- 2.50)
        planeposition = 2.50f;

    planeposition -= planespeed;

    glutPostRedisplay();


    glutTimerFunc(200, updatePlane, 0);
}

void handleMouse(int button, int state, int x, int y) {
	if (button == GLUT_LEFT_BUTTON)
	{
		planespeed=1.0f;
	}
	if (button == GLUT_RIGHT_BUTTON)
	{

		planespeed=0.04f;
	}
	glutPostRedisplay();
}


void Plane() {

          //PLANE CODE START

 glLoadIdentity();

glPushMatrix();
 glScalef(0.4,0.4,0);
 glTranslatef(0.0f,1.5f, 0.0f);
glTranslatef(planeposition, 0.0f, 0.0f);

    glBegin(GL_POLYGON); // airplane outer body
    glColor3ub   (234, 229, 229); // white    (234, 229, 229);
    glVertex2f(-0.3f, 0.2f);
    glVertex2f(0.3f, 0.2f);
    glVertex2f(0.4f, 0.3f);
    glVertex2f(0.45f, 0.4f);
    glVertex2f(0.3f, 0.4f);
    glVertex2f(0.0f, 0.4f);
    glVertex2f(-0.2f, 0.4f);
    glVertex2f(-0.3f, 0.4f);
    glVertex2f(-0.35f, 0.38f);
    glVertex2f(-0.4f, 0.3f);
    glVertex2f(-0.35f, 0.23f);
    glVertex2f(-0.3f, 0.2f);
    glEnd();
      glBegin(GL_POLYGON);  // Airplane wing
    glColor3ub(14,110, 205); // white    (234, 229, 229);
    glVertex2f(0.45f, 0.4f);
    glVertex2f(0.25f, 0.4f);
    glVertex2f(0.45f, 0.70f);
    glVertex2f(0.5f, 0.70f);
    glEnd();

        glBegin(GL_POLYGON); // airplane outer
    glColor3ub(14,110, 205); // white    (234, 229, 229);
    glVertex2f(0.4f, 0.35f);
    glVertex2f(0.3f, 0.35f);
    glVertex2f(0.34f, 0.14f);
    glVertex2f(0.4f, 0.14f);
    glEnd();

    glBegin(GL_POLYGON); // airplane front window
    glColor3ub(144,197,199); //
    glVertex2f(-0.37f, 0.35f);
    glVertex2f(-0.32f, 0.35f);
    glVertex2f(-0.3f, 0.36f);
    glVertex2f(-0.3f, 0.38f);
    glVertex2f(-0.35f, 0.38f);
    glEnd();


    glBegin(GL_QUADS); // Airplane front wing
 glColor3ub(14,110, 205);
    glVertex2f(0.02f, 0.15f);
    glVertex2f(0.05f, 0.15f);
    glVertex2f(-0.03f, 0.26f);
    glVertex2f(-0.1f, 0.26f);
    glEnd();
    glBegin(GL_QUADS); // Airplane back wing
    glColor3ub(14,110, 205);
    glVertex2f(-0.08f, 0.4f);
    glVertex2f(0.0f, 0.4f);
    glVertex2f(0.07f, 0.49f);
    glVertex2f(0.04f, 0.49f);
    glEnd();
    // Airplane  window
    glColor3ub(0,0,0); // purple one
    GLfloat x2=-0.09f;
    GLfloat y2=0.35f;
    GLfloat  radius1 =.02f;
     int triangleAmount1 = 100;
    GLfloat twicePi1 = 2.0f * PI;
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x2, y2); // center of circle
    for(int i = 0; i <= triangleAmount1; i++)
    {
        glVertex2f(
            x2 + (radius1 * cos(i *  twicePi1 / triangleAmount1)),
            y2 + (radius1 * sin(i * twicePi1 / triangleAmount1))
        );
    }
    glEnd();
    // Airplane  window
    glColor3ub(64,64,64); // purple one
    GLfloat x3=-0.02f;
    GLfloat y3=0.35f;
     radius1 =.02f;
       twicePi1 = 2.0f * PI;
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x3, y3); // center of circle
    for(int i = 0; i <= triangleAmount1; i++)
    {
        glVertex2f(
            x3 + (radius1 * cos(i *  twicePi1 / triangleAmount1)),
            y3 + (radius1 * sin(i * twicePi1 / triangleAmount1))
        );
    }
    glEnd();
    // Airplane  window
    glColor3ub(64,64,64);
    GLfloat x4=0.06f;
    GLfloat y4=0.35f;
    radius1 =.02f;
    twicePi1 = 2.0f * PI;
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x4, y4); // center of circle
    for(int i = 0; i <= triangleAmount1; i++)
    {
        glVertex2f(
            x4 + (radius1 * cos(i *  twicePi1 / triangleAmount1)),
            y4 + (radius1 * sin(i * twicePi1 / triangleAmount1))
        );
    }
    glEnd();

    glColor3ub(64,64,64);
    GLfloat x5=0.13f;
    GLfloat y5=0.35f;
    radius1 =.02f;
    twicePi1 = 2.0f * PI;
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x5, y5); // center of circle
    for(int i = 0; i <= triangleAmount1; i++)
    {
        glVertex2f(
            x5 + (radius1 * cos(i *  twicePi1 / triangleAmount1)),
            y5 + (radius1 * sin(i * twicePi1 / triangleAmount1))
        );
    }
    glEnd();


glPopMatrix();

   //PLANE CODE END


}




//---- update function
 void updateClouds(int value) {
    // Move Cloud 1 and Cloud 4 from right to left
    cloudPosition1 -= cloudSpeed;
    cloudPosition4 -= cloudSpeed;

    // Move Cloud 2 and Cloud 3 from left to right
    cloudPosition2 += cloudSpeed;
    cloudPosition3 += cloudSpeed;

    // Reset position when the cloud moves off the screen
    if (cloudPosition1 < -1.5f) cloudPosition1 = 1.5f;
    if (cloudPosition4 < -1.5f) cloudPosition4 = 1.5f;
    if (cloudPosition2 > 1.5f) cloudPosition2 = -1.5f;
    if (cloudPosition3 > 1.5f) cloudPosition3 = -1.5f;

    glutPostRedisplay();          // Request redisplay
    glutTimerFunc(16, updateClouds, 0); // Schedule the next update (approx 60 FPS)
}

void Cloud() {
    // Cloud 1
    glPushMatrix();
    glTranslatef(cloudPosition1, 1.1f, 0);  // Position for cloud 1        -0.5
    glScalef(0.4f, 0.4f, 1.0f);   // Scale for cloud 1

    glPushMatrix();
    glTranslatef(0.75f, -0.5f, 0); // Circle 1
    glBegin(GL_POLYGON);
    for (int i = 0; i < 400; i++) {
      glColor3ub(250, 250, 240);
        float pi = 3.1416f / 2;
        float A = (i * 2 * pi) / 200;
        float r = 0.17f;
        float x = r * cos(A);
        float y = r * sin(A);
        glVertex2f(x, y);
    }
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glPushMatrix();
    glTranslatef(0.85f, -0.65f, 0); // Circle 2
    glBegin(GL_POLYGON);
    for (int i = 0; i < 400; i++) {
        glColor3ub(255, 255, 245);
        float pi = 3.1416f / 2;
        float A = (i * 2 * pi) / 200;
        float r = 0.17f;
        float x = r * cos(A);
        float y = r * sin(A);
        glVertex2f(x, y);
    }
    glEnd();
    glPopMatrix();
glPopMatrix();
    glPushMatrix();
    glTranslatef(0.8f, -0.71f, 0); // Circle 3
    glBegin(GL_POLYGON);
    for (int i = 0; i < 200; i++) {
        glColor3ub(245, 245, 235);
        float pi = 3.1416f / 2;
        float A = (i * 2 * pi) / 200;
        float r = 0.17f;
        float x = r * cos(A);
        float y = r * sin(A);
        glVertex2f(x, y);
    }
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.55f, -0.55f, 0); // Circle 4
    glBegin(GL_POLYGON);
    for (int i = 0; i < 400; i++) {
        glColor3ub(248, 248, 238);
        float pi = 3.1416f / 2;
        float A = (i * 2 * pi) / 200;
        float r = 0.17f;
        float x = r * cos(A);
        float y = r * sin(A);
        glVertex2f(x, y);
    }
    glEnd();
    glPopMatrix();
    glPopMatrix();

glPopMatrix();

    // Cloud 2
    glPushMatrix();
    glTranslatef(cloudPosition2, 1.0f, 0);  // Position for cloud 2 -0.99
    glScalef(0.4f, 0.4f, 1.0f);   // Scale for the leftmost cloud

    glPushMatrix();
    glTranslatef(0.75f, -0.5f, 0); // Circle 1
    glBegin(GL_POLYGON);
    for (int i = 0; i < 400; i++) {
        glColor3ub(253, 253, 243);
        float pi = 3.1416f / 2;
        float A = (i * 2 * pi) / 200;
        float r = 0.17f;
        float x = r * cos(A);
        float y = r * sin(A);
        glVertex2f(x, y);
    }
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.85f, -0.65f, 0); // Circle 2
    glBegin(GL_POLYGON);
    for (int i = 0; i < 400; i++) {
        glColor3ub(253, 253, 243);
        float pi = 3.1416f / 2;
        float A = (i * 2 * pi) / 200;
        float r = 0.17f;
        float x = r * cos(A);
        float y = r * sin(A);
        glVertex2f(x, y);
    }
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.8f, -0.71f, 0); // Circle 3
    glBegin(GL_POLYGON);
    for (int i = 0; i < 200; i++) {
        glColor3ub(253, 253, 243);
        float pi = 3.1416f / 2;
        float A = (i * 2 * pi) / 200;
        float r = 0.17f;
        float x = r * cos(A);
        float y = r * sin(A);
        glVertex2f(x, y);
    }
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.55f, -0.55f, 0); // Circle 4
    glBegin(GL_POLYGON);
    for (int i = 0; i < 400; i++) {
        glColor3ub(253, 253, 243);
        float pi = 3.1416f / 2;
        float A = (i * 2 * pi) / 200;
        float r = 0.17f;
        float x = r * cos(A);
        float y = r * sin(A);
        glVertex2f(x, y);
    }
    glEnd();
    glPopMatrix();
    glPopMatrix();

    // Cloud 3
    glPushMatrix();
    glTranslatef(cloudPosition3, 1.2f, 0);  // Position for cloud 3 0.5
    glScalef(0.4f, 0.4f, 1.0f);

    glPushMatrix();
    glTranslatef(0.7f, -0.5f, 0); // Circle 1
    glBegin(GL_POLYGON);
    for (int i = 0; i < 400; i++) {
        glColor3ub(253, 253, 243);
        float pi = 3.1416f / 2;
        float A = (i * 2 * pi) / 200;
        float r = 0.17f;
        float x = r * cos(A);
        float y = r * sin(A);
        glVertex2f(x, y);
    }
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.85f, -0.65f, 0); // Circle 2
    glBegin(GL_POLYGON);
    for (int i = 0; i < 400; i++) {
        glColor3ub(253, 253, 243);
        float pi = 3.1416f / 2;
        float A = (i * 2 * pi) / 200;
        float r = 0.17f;
        float x = r * cos(A);
        float y = r * sin(A);
        glVertex2f(x, y);
    }
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.8f, -0.71f, 0); // Circle 3
    glBegin(GL_POLYGON);
    for (int i = 0; i < 200; i++) {
        glColor3ub(253, 253, 243);
        float pi = 3.1416f / 2;
        float A = (i * 2 * pi) / 200;
        float r = 0.17f;
        float x = r * cos(A);
        float y = r * sin(A);
        glVertex2f(x, y);
    }
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.55f, -0.55f, 0); // Circle 4
    glBegin(GL_POLYGON);
    for (int i = 0; i < 400; i++) {
        glColor3ub(253, 253, 243);
        float pi = 3.1416f / 2;
        float A = (i * 2 * pi) / 200;
        float r = 0.17f;
        float x = r * cos(A);
        float y = r * sin(A);
        glVertex2f(x, y);
    }
    glEnd();
    glPopMatrix();
    glPopMatrix();

    // Cloud 4
    glPushMatrix();
    glTranslatef(cloudPosition4, 1.0f, 0);  // Position for cloud 4     0.1
    glScalef(0.4f, 0.4f, 1.0f);

    glPushMatrix();
    glTranslatef(0.75f, -0.5f, 0); // Circle 1
    glBegin(GL_POLYGON);
    for (int i = 0; i < 400; i++) {
   glColor3ub(250, 250, 240);
        float pi = 3.1416f / 2;
        float A = (i * 2 * pi) / 200;
        float r = 0.17f;
        float x = r * cos(A);
        float y = r * sin(A);
        glVertex2f(x, y);
    }
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.85f, -0.65f, 0); // Circle 2
    glBegin(GL_POLYGON);
    for (int i = 0; i < 400; i++) {
       glColor3ub(255, 255, 245);
        float pi = 3.1416f / 2;
        float A = (i * 2 * pi) / 200;
        float r = 0.17f;
        float x = r * cos(A);
        float y = r * sin(A);
        glVertex2f(x, y);
    }
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.8f, -0.71f, 0); // Circle 3
    glBegin(GL_POLYGON);
    for (int i = 0; i < 200; i++) {
       glColor3ub(245, 245, 235);
        float pi = 3.1416f / 2;
        float A = (i * 2 * pi) / 200;
        float r = 0.17f;
        float x = r * cos(A);
        float y = r * sin(A);
        glVertex2f(x, y);
    }
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.55f, -0.55f, 0); // Circle 4
    glBegin(GL_POLYGON);
    for (int i = 0; i < 400; i++) {
        glColor3ub(248, 248, 238);
        float pi = 3.1416f / 2;
        float A = (i * 2 * pi) / 200;
        float r = 0.17f;
        float x = r * cos(A);
        float y = r * sin(A);
        glVertex2f(x, y);
    }
    glEnd();
    glPopMatrix();
    glPopMatrix();
}







//============================================================================================================================================

void Sun() {


//------------- sun

glPushMatrix();
    glTranslatef(0.8,0.8,0);
    glBegin(GL_POLYGON);
	for(int i=0;i<200;i++)
        {
            glColor3ub(255,247,8); //----------pasher dim er matha
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=0.12;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x,y);
        }


	glEnd();


glPopMatrix();



	//-------- sun end
}




void display() {
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f); // Set background color to black and opaque
	glClear(GL_COLOR_BUFFER_BIT);         // Clear the color buffer (background)102, 163, 255
	glLoadIdentity(); //Reset the drawing perspective
	glMatrixMode(GL_MODELVIEW);


	glColor3ub(back1,back2,back3); //glColor3ub(151,247,255);//..........sky
	glBegin(GL_QUADS);
    glVertex2f(-1.0f,1.0f);
	glVertex2f(-1.0f,-1.0f);
    glVertex2f(1.0f,-1.0f);
	glVertex2f(1.0f,1.0f);
	glEnd();







    glColor3ub(255,255,255);
    glLineWidth(8);
	glBegin(GL_LINES);
    glVertex2f(-1.0f,-0.6f);
	glVertex2f(1.0f,-0.6f);
	glEnd();

	glPointSize(2);
    glBegin(GL_POINTS);
	 glColor3ub(star1,star2,star3);//.................................star255,255,255

    glVertex2f(-0.0f,0.79f);
    glVertex2f(-0.0f,0.9f);
    glVertex2f(-0.07f,0.9f);
    glVertex2f(-0.07f,0.7f);
    glVertex2f(-0.03f,0.75f);
    glVertex2f(-0.03f,0.85f);
    glVertex2f(-0.03f,0.95f);
    glVertex2f(-0.13f,0.79f);
    glVertex2f(-0.13f,0.9f);
    glVertex2f(-0.23f,0.75f);
    glVertex2f(-0.23f,0.85f);
    glVertex2f(-0.33f,0.65f);
    glVertex2f(-0.33f,0.785f);
    glVertex2f(-0.33f,0.958f);
    glVertex2f(-0.43f,0.55f);
    glVertex2f(-0.43f,0.75f);
    glVertex2f(-0.43f,0.89f);
    glVertex2f(-0.55f,0.47f);
    glVertex2f(-0.55f,0.67f);
    glVertex2f(-0.55f,0.87f);
    glVertex2f(-0.5f,0.42f);
    glVertex2f(-0.58f,0.45f);
    glVertex2f(-0.58f,0.65f);
    glVertex2f(-0.58f,0.95f);
    glVertex2f(-0.49f,0.51f);
    glVertex2f(-0.63f,0.525f);
    glVertex2f(-0.63f,0.725f);
    glVertex2f(-0.63f,0.925f);
    glVertex2f(-0.73f,0.425f);
    glVertex2f(-0.73f,0.525f);
    glVertex2f(-0.73f,0.725f);
    glVertex2f(-0.83f,0.35f);
    glVertex2f(-0.83f,0.46f);
    glVertex2f(-0.83f,0.56f);
    glVertex2f(-0.83f,0.76f);
    glVertex2f(-0.83f,0.96f);
    glVertex2f(-0.93f,0.485f);
    glVertex2f(-0.93f,0.585f);
    glVertex2f(-0.93f,0.785f);
    glVertex2f(-0.98f,0.885f);
    glVertex2f(-0.98f,0.285f);
    glVertex2f(0.0f,0.79f);
    glVertex2f(0.0f,0.9f);
    glVertex2f(0.07f,0.9f);
    glVertex2f(0.07f,0.7f);
    glVertex2f(0.03f,0.75f);
    glVertex2f(0.03f,0.85f);
    glVertex2f(0.03f,0.95f);
    glVertex2f(0.13f,0.79f);
    glVertex2f(0.13f,0.9f);
    glVertex2f(0.23f,0.75f);
    glVertex2f(0.23f,0.85f);
    glVertex2f(0.33f,0.65f);
    glVertex2f(0.33f,0.785f);
    glVertex2f(0.33f,0.958f);
    glVertex2f(0.43f,0.55f);
    glVertex2f(0.43f,0.75f);
    glVertex2f(0.43f,0.89f);
    glVertex2f(0.55f,0.47f);
    glVertex2f(0.55f,0.67f);
    glVertex2f(0.55f,0.87f);
    glVertex2f(0.5f,0.42f);
    glVertex2f(0.58f,0.45f);
    glVertex2f(0.58f,0.65f);
    glVertex2f(0.58f,0.95f);
    glVertex2f(0.49f,0.51f);
    glVertex2f(0.63f,0.525f);
    glVertex2f(0.63f,0.725f);
    glVertex2f(0.63f,0.925f);
    glVertex2f(0.73f,0.425f);
    glVertex2f(0.73f,0.525f);
    glVertex2f(0.73f,0.725f);
    glVertex2f(0.83f,0.35f);
    glVertex2f(0.83f,0.46f);
    glVertex2f(0.83f,0.56f);
    glVertex2f(0.83f,0.76f);
    glVertex2f(0.83f,0.96f);
    glVertex2f(0.93f,0.485f);
    glVertex2f(0.93f,0.585f);
    glVertex2f(0.93f,0.785f);
    glVertex2f(0.98f,0.885f);
    glVertex2f(0.98f,0.285f);

    glEnd();





	Sun();
    Cloud();
    Plane();
    shadowBuilding();
	Building();
    River();
    Boat();


glFlush();  // Render now
 glutSwapBuffers();

}

void handleKeypress(unsigned char key, int x, int y) {
        switch (key) {

    case 'd':
star1=151;
        star2=247;
        star3=255;

        back1=151;
        back2=247;
        back3=255;

        break;

        /*   sky1=166;
        sky2=166;
        sky3=166; */

    case 'n':
star1=255;
        star2=255;
        star3=255;

        back1=38;
        back2=77;
        back3=115;
        break;
    glutPostRedisplay();
    //starc1=255,skyc2=255,skyc3=255,sky1=31,sky2=63,sky3=96,back1=38,back2=77,back3=115
   /* sky1=31;
        sky2=63;
        sky3=96; */
	}}


void myInit (void)
{
    glClearColor(0.0, 0.0, 0.0, 0.0);
    gluOrtho2D(-1.0, 1.0, -1.0, 1.0);
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode (GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize (900, 500);
    glutInitWindowPosition (100, 100);
    glutCreateWindow ("Colourfull Neon City");
    glutDisplayFunc(display);
    init();

    glutTimerFunc(100, updateBoat, 0);
    glutTimerFunc(16, updateClouds, 0); // Start the cloud movement animation
glutTimerFunc(200, updatePlane, 0);
 glutSpecialFunc(handleSpecialKeys);
 glutKeyboardFunc(handleKeypress);
glutMouseFunc(handleMouse);
    glutMainLoop();
    return 0;
}

