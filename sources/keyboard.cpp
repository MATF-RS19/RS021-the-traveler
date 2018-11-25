#include "../headers/keyboard.hpp"
#include "../headers/camera.hpp"

extern Camera* camera;
GLfloat movementSensitivity = 3;
GLfloat rotationSensitivity = 3;

void keyboardFunc(unsigned char key, GLint x, GLint y){
        /* Ovom funkcijom se realizuje rotacija kamere pomocu tastera 'w', 's', 'a', 'd' */

	switch (key){

		    case 'w':
            case 'W':       camera->_xRotation += rotationSensitivity;
					        break;

		    case 's':
            case 'S':       camera->_xRotation -= rotationSensitivity;
					        break;

		    case 'a':
            case 'A':       camera->_yRotation -= rotationSensitivity;
					        break;

		    case 'd':
            case 'D':       camera->_yRotation += rotationSensitivity;
					        break;

        }
	camera->updateCamera();
}


void specialFunc(GLint key, GLint x, GLint y){
        /* Ovom funkcijom je realizovano kretanje po prostoriji pomocu strelica */

	switch (key){

	case GLUT_KEY_UP: camera->_moveForward += movementSensitivity;
		break;

	case GLUT_KEY_DOWN: camera->_moveForward -= movementSensitivity;
		break;

	case GLUT_KEY_LEFT: camera->_moveRightward -= movementSensitivity;
		break;

	case GLUT_KEY_RIGHT: camera->_moveRightward += movementSensitivity;
		break;
	}

	camera->updateCamera();
}
