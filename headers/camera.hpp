#include <vector>
#include <GL/glu.h>
#include <GL/glut.h>
#include <GLFW/glfw3.h>

/* Kamera je singleton zbog toga sto nam je potrebna samo jedna instanca te klase tokom citavog programa */
class Camera {
    
public:
    static Camera* getInstance();

    Camera(std::vector<GLfloat> position, std::vector<GLfloat> lookAt, std::vector<GLfloat> cameraUp)
      :_position(position),_lookAt(lookAt),_cameraUp(cameraUp)
    {
        _xRotation = 0.0f;
        _yRotation = 0.0f;

        _moveRightward = 0.0f;
        _moveForward = 0.0f;
        _moveUpward = 0.0f;
    }

    void setPosition(std::vector<GLfloat> v) {_position = v;}
    void setLookAt(std::vector<GLfloat> v) {_lookAt = v;}
    void setUpVector(std::vector<GLfloat> v) {_cameraUp = v;}
    std::vector<GLfloat> getPosition() {return _position;}
    std::vector<GLfloat> getLookAt() {return _lookAt;}
    std::vector<GLfloat> getCameraUp() {return _cameraUp;}

    void updateCamera();

    GLfloat _xRotation;
    GLfloat _yRotation;

    GLfloat _moveRightward;
    GLfloat _moveForward;
    GLfloat _moveUpward;

private:
    static Camera* _instance;
    std::vector<GLfloat> _position;
    std::vector<GLfloat> _lookAt;
    std::vector<GLfloat> _cameraUp;

    Camera(){} // private constructor
    Camera(const Camera&);
    Camera& operator=(const Camera&);
};
