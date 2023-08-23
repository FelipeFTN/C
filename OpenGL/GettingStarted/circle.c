#include <GL/gl.h>
#include <GL/glext.h>
#include<stdio.h>
#include<GL/glut.h>
#include<math.h>

#define pi 3.142857
#define window_width 300 
#define window_height 300

void init (void) {
    // Black Background color
    glClearColor(0.0, 0.0, 0.0, 1.0);

    // Green stroke color
    glColor3f(0.0, 1.0, 0.0);

    // stroke width to 1px
    glPointSize(1.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    // Set window
    gluOrtho2D(-window_width, window_width, -window_height, window_height);
}

void display (void) {
    glClear(GL_COLOR_BUFFER_BIT);
    glBegin(GL_POINTS);
    float x, y, i;
    
    // Iterates Y up to 2*pi -> 360 degrees
    // Increments angles
    // Draws it
    for (i = 0; i < (2 * pi); i += 0.001) {
        // circle radius is 200
        // circle formula is (x = r * cos(i); y = r * sin(i))
        x = 200 * cos(i);
        y = 200 * sin(i);

        glVertex2i(x, y);
    }
    glEnd();
    glFlush();
}

int main (int argc, char** argv) {
    // Initialize Window
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);

    // Window size & position
    glutInitWindowSize(window_width, window_height);
    glutInitWindowPosition(window_width/2, window_height/2);
    
    // Create Window
    glutCreateWindow("Circle Drawing");
    init();
    
    glutDisplayFunc(display);
    glutMainLoop();
}
