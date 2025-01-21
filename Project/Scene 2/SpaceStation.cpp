#include <cstdio>
#include <GL/gl.h>
#include <GL/glut.h>
#include <cmath>
#include <ctime>
#include <mmsystem.h>
GLfloat position = 0.0f;
GLfloat speed = 0.005f;
GLboolean moving = true;

#define PI 3.14159265358979323846
#define STAR_COUNT 100
struct Star {
    GLfloat x, y, brightness;
};

Star stars[STAR_COUNT];

// Initialize stars with random positions and brightness
void initStars() {
    for (int i = 0; i < STAR_COUNT; ++i) {
        stars[i].x = static_cast<GLfloat>(rand() % 200 - 100) / 100.0f; // X: [-1, 1]
        stars[i].y = static_cast<GLfloat>(rand() % 200 - 100) / 100.0f; // Y: [-1, 1]
        stars[i].brightness = static_cast<GLfloat>(rand() % 100) / 100.0f; // Brightness: [0, 1]
    }
}

// Draw a star at the specified position with the specified brightness
void drawStar(GLfloat x, GLfloat y, GLfloat brightness) {
    glColor3f(brightness, brightness, brightness); // Set star color based on brightness
    glBegin(GL_POLYGON);
    GLfloat radius = 0.01f; // Star size
    for (int i = 0; i < 5; ++i) {
        GLfloat angle = i * 2.0f * PI / 5;
        glVertex2f(x + radius * cos(angle), y + radius * sin(angle));
    }
    glEnd();
}

// Function to draw a half-circle using GL_TRIANGLE_FAN
void drawHalfCircle(GLfloat radius, GLfloat x, GLfloat y, GLint num_segments) {
    GLfloat twicePi = 2.0f * PI;
    glColor3f(0.17f, 0.50f, 0.81f); // Blue color for the world

    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y); // center of circle
    for (int i = 0; i <= num_segments; i++) {
        GLfloat angle = PI * i / num_segments; // Angle from 0 to PI (half circle)
        GLfloat dx = radius * cos(angle);
        GLfloat dy = radius * sin(angle);
        glVertex2f(x + dx, y + dy);
    }
    glEnd();
}

// Function to draw green grass under the half-circle
void drawGrass(GLfloat x_start, GLfloat x_end, GLfloat y_position, GLfloat blade_width, GLfloat blade_height) {
    glColor3f(0.13f, 0.55f, 0.13f); // Green color for grass
    for (GLfloat x = x_start; x < x_end; x += blade_width) {
        glBegin(GL_TRIANGLES);
        glVertex2f(x, y_position);                         // Base of the blade
        glVertex2f(x + blade_width / 2.0f, y_position + blade_height); // Tip of the blade
        glVertex2f(x + blade_width, y_position);          // Base of the blade
        glEnd();
    }
}
void drawSmallCircle(GLfloat radius, GLfloat x, GLfloat y, GLint num_segments) {
    GLfloat twicePi = 2.0f * PI;

    glColor3f(1.0f,1.0f,1.0f);

    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y); // center of the circle
    for (int i = 0; i <= num_segments; i++) {
        GLfloat angle = twicePi * i / num_segments; // Full circle
        GLfloat dx = radius * cos(angle);
        GLfloat dy = radius * sin(angle);
        glVertex2f(x + dx, y + dy);
    }
    glEnd();
}

GLfloat circleRadius = 0.10f;    // Initial radius of the small circle
GLfloat circleRadiusSpeed = 0.002f; // Increment/Decrement step for the circle's size
GLfloat maxCircleRadius = 0.10f;   // Maximum radius limit
GLfloat minCircleRadius = 0.05f;   // Minimum radius limit

// Function to handle keyboard inputs
void handleSpecialKeypress(int key, int x, int y) {
    switch (key) {
        case GLUT_KEY_LEFT: // Move left
            speed = -0.005f;
            moving = true;
            break;

        case GLUT_KEY_RIGHT: // Move right
            speed = 0.005f;
            moving = true;
            break;

        case GLUT_KEY_UP: // Stop
            moving = false;
            break;
    }
    glutPostRedisplay();
}



void update(int value) {
    if (moving) {
        position += speed;
        if (position > 1.0f) position = -1.0f;
        if (position < -1.0f) position = 1.0f;
    }
    glutPostRedisplay();
    glutTimerFunc(100, update, 0);

}


void display() {
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

   // Draw all stars
    for (int i = 0; i < STAR_COUNT; ++i) {
        drawStar(stars[i].x, stars[i].y, stars[i].brightness);
    }


    // Draw the half-circle world background at the bottom
    drawHalfCircle(1.0f, 0.0f, -1.0f, 100);

    // Draw the green grass texture under the half-circle
    drawGrass(-1.0f, 1.0f, -1.0f, 0.02f, 0.1f);
    drawGrass(-1.0f, 1.0f, -1.0f, 0.02f, 0.1f);

    drawSmallCircle(0.10f, -0.85f, 0.85f, 30);

    glPushMatrix();
    glTranslatef(position, 0.0f, 0.0f);

//1
    glBegin(GL_POLYGON);
    glColor3f(0.67f, 0.76f, 0.74f); // brown
    glVertex2f(-0.25f, 0.025f);
    glVertex2f(0.25f, 0.025f);
    glVertex2f(0.25f, -0.025f);
    glVertex2f(-0.25f, -0.025f);
    glEnd();
//2
    glBegin(GL_POLYGON);
    glColor3f(.62f, .73f, .9f); // light blue
    glVertex2f(-0.225f, 0.025f);
    glVertex2f(-0.225f, 0.05f);
    glVertex2f(-0.175f, 0.05f);
    glVertex2f(-0.175f, 0.025f);
    glEnd();

//3
    glBegin(GL_POLYGON);
    glColor3f(0.41f, 0.50f, 0.56f); // pakha
    glVertex2f(-0.25f, 0.05f);
    glVertex2f(-0.25f, 0.25f);
    glVertex2f(-0.21f, 0.25f);
    glVertex2f(-0.21f, 0.05f);
    glEnd();

//4
    glBegin(GL_POLYGON);
    glColor3f(0.41f, 0.50f, 0.56f); // pakha
    glVertex2f(-0.19f, 0.05f);
    glVertex2f(-0.19f, 0.25f);
    glVertex2f(-0.15f, 0.25f);
    glVertex2f(-0.15f, 0.05f);
    glEnd();
//5
    glBegin(GL_POLYGON);
    glColor3f(.62f, .73f, .9f); // light blue
    glVertex2f(-0.115f, 0.025f);
    glVertex2f(-0.115f, 0.05f);
    glVertex2f(-0.065f, 0.05f);
    glVertex2f(-0.065f, 0.025f);
    glEnd();

//6
    glBegin(GL_POLYGON);
    glColor3f(0.41f, 0.50f, 0.56f); // pakha
    glVertex2f(-0.14f, 0.05f);
    glVertex2f(-0.14f, 0.2f);
    glVertex2f(-0.1f, 0.2f);
    glVertex2f(-0.1f, 0.05f);
    glEnd();

//7
    glBegin(GL_POLYGON);
    glColor3f(0.41f, 0.50f, 0.56f); // pakha
    glVertex2f(-0.08f, 0.05f);
    glVertex2f(-0.08f, 0.2f);
    glVertex2f(-0.04f, 0.2f);
    glVertex2f(-0.04f, 0.05f);
    glEnd();
//8
    glBegin (GL_POLYGON);
    glColor3f(.62f , .73f , .9f);//light blue
    glVertex2f (-0.225f, -0.025f);
    glVertex2f (-0.225f, -0.05f);
    glVertex2f (-0.175f, -0.05f);
    glVertex2f (-0.175f, -0.025f);
    glEnd();
//9
    glBegin (GL_POLYGON);
    glColor3f(0.41f, 0.50f, 0.56f); // pakha
    glVertex2f (-0.25f, -0.05f);
    glVertex2f (-0.25f, -0.25f);
    glVertex2f (-0.21f, -0.25f);
    glVertex2f (-0.21f, -0.05f);
    glEnd();
//10
    glBegin (GL_POLYGON);
    glColor3f(0.41f, 0.50f, 0.56f); // pakha
    glVertex2f (-0.19f, -0.05f);
    glVertex2f (-0.19f, -0.25f);
    glVertex2f (-0.15f, -0.25f);
    glVertex2f (-0.15f, -0.05f);
    glEnd();

//11
    glBegin (GL_POLYGON);
    glColor3f(.62f , .73f , .9f);//light blue
    glVertex2f (-0.115f, -0.025f);
    glVertex2f (-0.115f, -0.05f);
    glVertex2f (-0.065f, -0.05f);
    glVertex2f (-0.065f, -0.025f);
    glEnd();

//12
    glBegin (GL_POLYGON);
    glColor3f(0.41f, 0.50f, 0.56f); // pakha
    glVertex2f (-0.14f, -0.05f);
    glVertex2f (-0.14f, -0.2f);
    glVertex2f (-0.1f, -0.2f);
    glVertex2f (-0.1f, -0.05f);
    glEnd();

//13
    glBegin (GL_POLYGON);
    glColor3f(0.41f, 0.50f, 0.56f); // pakha
    glVertex2f (-0.08f, -0.05f);
    glVertex2f (-0.08f, -0.2f);
    glVertex2f (-0.04f, -0.2f);
    glVertex2f (-0.04f, -0.05f);
    glEnd();
//14
    glBegin (GL_POLYGON);
    glColor3f(.62f , .73f , .9f);//light blue
    glVertex2f (0.225f, -0.025f);
    glVertex2f (0.225f, -0.05f);
    glVertex2f (0.175f, -0.05f);
    glVertex2f (0.175f, -0.025f);
    glEnd();

//15
    glBegin (GL_POLYGON);
    glColor3f(0.41f, 0.50f, 0.56f); // pakha
    glVertex2f (0.25f, -0.05f);
    glVertex2f (0.25f, -0.25f);
    glVertex2f (0.21f, -0.25f);
    glVertex2f (0.21f, -0.05f);
    glEnd();

//16
    glBegin (GL_POLYGON);
    glColor3f(0.41f, 0.50f, 0.56f); // pakha
    glVertex2f (0.19f, -0.05f);
    glVertex2f (0.19f, -0.25f);
    glVertex2f (0.15f, -0.25f);
    glVertex2f (0.15f, -0.05f);
    glEnd();

//17
    glBegin (GL_POLYGON);
    glColor3f(.62f , .73f , .9f);//light blue
    glVertex2f (0.115f, -0.025f);
    glVertex2f (0.115f, -0.05f);
    glVertex2f (0.065f, -0.05f);
    glVertex2f (0.065f, -0.025f);
    glEnd();

//18
    glBegin (GL_POLYGON);
    glColor3f(0.41f, 0.50f, 0.56f); // pakha
    glVertex2f (0.14f, -0.05f);
    glVertex2f (0.14f, -0.2f);
    glVertex2f (0.1f, -0.2f);
    glVertex2f (0.1f, -0.05f);
    glEnd();

//19
    glBegin (GL_POLYGON);
    glColor3f(0.41f, 0.50f, 0.56f); // pakha
    glVertex2f (0.08f, -0.05f);
    glVertex2f (0.08f, -0.2f);
    glVertex2f (0.04f, -0.2f);
    glVertex2f (0.04f, -0.05f);
    glEnd();


//20
    glBegin (GL_POLYGON);
    glColor3f(.62f , .73f , .9f);//light blue
    glVertex2f (0.225f, 0.025f);
    glVertex2f (0.225f, 0.05f);
    glVertex2f (0.175f, 0.05f);
    glVertex2f (0.175f, 0.025f);
    glEnd();

//21
    glBegin (GL_POLYGON);
    glColor3f(0.41f, 0.50f, 0.56f); // pakha
    glVertex2f (0.25f, 0.05f);
    glVertex2f (0.25f, 0.25f);
    glVertex2f (0.21f, 0.25f);
    glVertex2f (0.21f, 0.05f);
    glEnd();

//22
    glBegin (GL_POLYGON);
    glColor3f(0.41f, 0.50f, 0.56f); // pakha
    glVertex2f (0.19f, 0.05f);
    glVertex2f (0.19f, 0.25f);
    glVertex2f (0.15f, 0.25f);
    glVertex2f (0.15f, 0.05f);
    glEnd();

//23
    glBegin (GL_POLYGON);
    glColor3f(.62f , .73f , .9f);//light blue
    glVertex2f (0.115f, 0.025f);
    glVertex2f (0.115f, 0.05f);
    glVertex2f (0.065f, 0.05f);
    glVertex2f (0.065f, 0.025f);
    glEnd();

//24
    glBegin (GL_POLYGON);
    glColor3f(0.41f, 0.50f, 0.56f); // pakha
    glVertex2f (0.14f, 0.05f);
    glVertex2f (0.14f, 0.2f);
    glVertex2f (0.1f, 0.2f);
    glVertex2f (0.1f, 0.05f);
    glEnd();

//25
    glBegin (GL_POLYGON);
    glColor3f(0.41f, 0.50f, 0.56f); // pakha
    glVertex2f (0.08f, 0.05f);
    glVertex2f (0.08f, 0.2f);
    glVertex2f (0.04f, 0.2f);
    glVertex2f (0.04f, 0.05f);
    glEnd();

//26
    glBegin (GL_POLYGON);
    glColor3f(0.67f, 0.76f, 0.74f); // brown
    glVertex2f (-0.025f, 0.0f);
    glVertex2f (-0.025f, -0.3f);
    glVertex2f (0.025f, -0.3f);
    glVertex2f (0.025f, 0.0f);
    glEnd();

//27
    glBegin (GL_POLYGON);
    glColor3f(0.67f, 0.76f, 0.74f); // brown
    glVertex2f (-0.05f, -0.25f);
    glVertex2f (0.05f, -0.25f);
    glVertex2f (0.05f, -0.285f);
    glVertex2f (-0.05f, -0.285f);
    glEnd();

    glPopMatrix();

    glFlush();
}

void sound()
{
   PlaySound(TEXT("Background.wav"), NULL, SND_ASYNC | SND_LOOP);
}
void reshape(int w, int h) {
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-1.0, 1.0, -1.0, 1.0);
    glMatrixMode(GL_MODELVIEW);
}

int main(int argc, char** argv) {
    srand(static_cast<unsigned>(time(0))); // Seed for random number generation
    initStars();

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(800, 600);
    glutCreateWindow("Space Station");

    glutDisplayFunc(display);
    glutSpecialFunc(handleSpecialKeypress);
    glutTimerFunc(100, update, 0);

    sound();
    glutMainLoop();
    return 0;
}
