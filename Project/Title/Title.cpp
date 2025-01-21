#include <Windows.h>
#include <GL/freeglut.h>
#include <GL/glut.h>
#include <string>
#include <vector>

int selectedScene = 0;

struct Student {
    int serial;
    std::string name;
    std::string id;
};

std::vector<Student> students = {
    {5, "Ammar Bin Mahmud", "22-46524-1"},
    {29, "Humayra Tasnim Ajra", "22-48695-3"},
    {30, "Abul Bashar Saurov", "22-48823-3"},
    {31, "MD. Sajib Mondol", "22-48824-3"},
    {42, "MD. Ashfak Uzzaman Khan", "22-49976-3"}
};

void renderBitmapString(float x, float y, void* font, const char* string) {
    glRasterPos2f(x, y);
    for (const char* c = string; *c != '\0'; c++) {
        glutBitmapCharacter(font, *c);
    }
}

void displayMenu() {
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0, 1.0, 1.0);

    renderBitmapString(-0.9, 0.8, GLUT_BITMAP_HELVETICA_18, "Apocalyptic Spacecity");
    renderBitmapString(-0.9, 0.7, GLUT_BITMAP_HELVETICA_18, "Student List:");

    float y = 0.6f;
    for (const auto& student : students) {
        std::string line = std::to_string(student.serial) + "\t" + student.name + "\t" + student.id;
        renderBitmapString(-0.9, y, GLUT_BITMAP_HELVETICA_18, line.c_str());
        y -= 0.1f;
    }

    renderBitmapString(-0.9, -0.6, GLUT_BITMAP_HELVETICA_18, "Welcome");
    glFlush();
}

void keyboard(unsigned char key, int x, int y) {
    if (key >= '1' && key <= '3') {
        selectedScene = key - '0';
        switch (selectedScene) {
        }
    }
}

void init() {
    glClearColor(0.0, 0.0, 0.0, 1.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-1.0, 1.0, -1.0, 1.0);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(800, 600);
    glutCreateWindow("Menu");
    init();
    glutDisplayFunc(displayMenu);
    glutKeyboardFunc(keyboard);
    glutMainLoop();
    return 0;
}