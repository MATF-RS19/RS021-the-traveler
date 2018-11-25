#include <iostream>
#include <vector>
#include "../headers/camera.hpp"
#include "../headers/keyboard.hpp"

/* Dimenzije grada */
#define xRange (150.0)
#define yRange (150.0)
#define zRange (150.0)

Camera *camera;

/* Dimenzije prozora */
GLint WIN_WIDTH;
GLint WIN_HEIGHT;

void init();
void reshape(GLint width, GLint height);
void drawScene();

int main(int argc, char ** argv) {

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DEPTH | GLUT_DOUBLE | GLUT_ACCUM);

    /* Inicijalizacija GLFW */
    if (!glfwInit()) {
        return EXIT_FAILURE;
    }

    /* Kreira se prozor dimenzija koje odgovaraju monitoru na kom se program pokrece */
    const GLFWvidmode *mode = glfwGetVideoMode(glfwGetPrimaryMonitor());
    WIN_WIDTH = mode->width;
    WIN_HEIGHT = mode->height;

    glutInitWindowPosition(50, 50);
	glutInitWindowSize(WIN_WIDTH, WIN_HEIGHT);

	glutCreateWindow("The traveler");
	init();
	glutReshapeFunc(reshape);
	glutDisplayFunc(drawScene);
	glutKeyboardFunc(keyboardFunc);
	glutSpecialFunc(specialFunc);

	glutMainLoop();

    return EXIT_SUCCESS;
}

void init()
{
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	glClearAccum(0.0f, 0.0f, 0.0f, 1.0f);

	glEnable(GL_DEPTH_TEST);
	glEnable(GL_NORMALIZE);
	glEnable(GL_LINE_SMOOTH);
    glEnable(GL_COLOR_MATERIAL);
	glHint(GL_LINE_SMOOTH_HINT, GL_NICEST);
	glHint(GL_POLYGON_SMOOTH_HINT, GL_NICEST);

    camera = Camera::getInstance();
    camera->setPosition({0.0, yRange/2, zRange-2});
    camera->setLookAt({0.0, yRange/2, 0.0});
    camera->setUpVector({0.0, 1.0, 0.0});
}


void reshape(GLint width, GLint height){

	if (height == 0)
		height = 1;

	glViewport(0, 0, width, height);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(70.0f, (GLfloat)width / height, 1.0f, 1000.0f);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	gluLookAt(camera->getPosition()[0], camera->getPosition()[1], camera->getPosition()[2],
              camera->getLookAt()[0], camera->getLookAt()[1], camera->getLookAt()[2],
              camera->getCameraUp()[0], camera->getCameraUp()[1], camera->getCameraUp()[2]);
}

void drawScene(){

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glBegin(GL_QUADS);
        //glNormal3f(0.0f, normal, 0.0f);
        glVertex3f(xRange, 0, zRange);
        glVertex3f(-xRange, 0, zRange);
        glVertex3f(-xRange, 0, -zRange);
        glVertex3f(xRange, 0, -zRange);
    glEnd();

    glFlush();
	glutSwapBuffers();
}
