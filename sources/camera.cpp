#include "../headers/camera.hpp"
#include <cmath>

#define DEG2RAD(a)    (M_PI / 180 * (a))

Camera* Camera::_instance = nullptr;

Camera* Camera::getInstance() {
   if (_instance == nullptr) {
      _instance = new Camera();
   }
   return(_instance);
}

void Camera::updateCamera(){

    /* Kamera oko x ose moze da rotira samo u intervalu [-90, 90]  */
	if (_xRotation > 90.0f)
		_xRotation = 90.0f;
	else if (_xRotation < -90.0f)
		_xRotation = -90.0f;
    /* Kamera oko y ose moze da napravi pun krug */
	if (_yRotation > 360.0f)
		_yRotation -= 360.0f;
	else if (_yRotation < 0.0f)
		_yRotation += 360.0f;

	_position[0] += sin(DEG2RAD(_yRotation)) * _moveForward;
	_position[2] -= cos(DEG2RAD(_yRotation)) * _moveForward;
	_position[0] += sin(DEG2RAD(_yRotation + 90)) * (_moveRightward * 2);
	_position[2] += -cos(DEG2RAD(_yRotation + 90)) * (_moveRightward * 2);
	_position[1] += _moveUpward;
	_lookAt[0] = _position[0] + sin(DEG2RAD(_yRotation));
	_lookAt[2] = _position[2] - cos(DEG2RAD(_yRotation));
	_lookAt[1] = _position[1] + sin(DEG2RAD(_xRotation));
	_moveRightward = 0;
	_moveUpward = 0;
	_moveForward = 0;

	glLoadIdentity();
    gluLookAt(_position[0], _position[1], _position[2],
              _lookAt[0], _lookAt[1], _lookAt[2],
              _cameraUp[0], _cameraUp[1], _cameraUp[2]);

	glutPostRedisplay();
}
