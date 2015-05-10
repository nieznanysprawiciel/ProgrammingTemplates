#pragma once

#include <glew.h>
#include <glfw3.h>


class OpenGL_template
{
private:
	GLFWwindow*		window;
	float			window_sizeX;
	float			window_sizeY;

	virtual void init();
	virtual void loop( double time );
protected:

public:
	OpenGL_template();
	virtual ~OpenGL_template();

	void main_loop();
	int initialize( float screenX, float screenY, const char* window_title );

	inline GLFWwindow* get_window() const { return window; }
	inline float get_window_sizeX() const { return window_sizeX; }
	inline float get_window_sizeY() const  { return window_sizeY; }
};

