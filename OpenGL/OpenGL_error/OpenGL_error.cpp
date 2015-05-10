
#include <GL/glew.h>
#include <stdio.h>

bool openGL_error()
{
	GLenum error;
	bool return_value = false;
	while ( (error = glGetError( )) != GL_NO_ERROR )
	{
		return_value = true;
		switch ( error )
		{
			case GL_INVALID_ENUM:
				printf( "OpenGL ERROR: GL_INVALID_ENUM \n" );
				break;
			case GL_INVALID_VALUE:
				printf( "OpenGL ERROR: GL_INVALID_VALUE \n" );
				break;
			case GL_INVALID_OPERATION:
				printf( "OpenGL ERROR: GL_INVALID_OPERATION \n" );
				break;
			case GL_INVALID_FRAMEBUFFER_OPERATION:
				printf( "OpenGL ERROR: GL_INVALID_FRAMEBUFFER_OPERATION \n" );
				break;
			case GL_OUT_OF_MEMORY:
				printf( "OpenGL ERROR: GL_OUT_OF_MEMORY \n" );
				break;
			case GL_STACK_UNDERFLOW:
				printf( "OpenGL ERROR: GL_STACK_UNDERFLOW \n" );
				break;
			case GL_STACK_OVERFLOW:
				printf( "OpenGL ERROR: GL_STACK_OVERFLOW \n" );
				break;
			default:
				printf( "OpenGL ERROR: Nieznany b³¹d \n" );
		}
	}
	return return_value;
}