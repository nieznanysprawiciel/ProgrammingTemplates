#include "OpenGL_template.h"
#include <stdio.h>

OpenGL_template::OpenGL_template()
{
	window = nullptr;
}


OpenGL_template::~OpenGL_template()
{
}


void OpenGL_template::init( ){}
void OpenGL_template::loop( double time ){}

void OpenGL_template::main_loop( )
{

	do{
		// Clear the screen
		glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );

		double time = glfwGetTime();

		loop( time );

		// Swap buffers
		glfwSwapBuffers( window );
		glfwPollEvents( );

	} // Check if the ESC key was pressed or the window was closed
	while ( glfwGetKey( window, GLFW_KEY_ESCAPE ) != GLFW_PRESS &&
	glfwWindowShouldClose( window ) == 0 );


	// Konczymy aplikacjê
	glfwTerminate( );
}


int OpenGL_template::initialize( float screenX, float screenY, const char* window_title )
{
	window_sizeX = screenX;
	window_sizeY = screenY;

	if ( !glfwInit( ) )
	{
		fprintf( stderr, "Failed to initialize GLFW\n" );
		return -1;
	}

	glfwWindowHint( GLFW_SAMPLES, 4 );
	glfwWindowHint( GLFW_CONTEXT_VERSION_MAJOR, 3 );
	glfwWindowHint( GLFW_CONTEXT_VERSION_MINOR, 3 );
	glfwWindowHint( GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE );


	// Open a window and create its OpenGL context
	window = glfwCreateWindow( window_sizeX, window_sizeY, window_title, NULL, NULL );
	if ( window == NULL ){
		fprintf( stderr, "Failed to open GLFW window. If you have an Intel GPU, they are not 3.3 compatible. Try the 2.1 version of the tutorials.\n" );
		glfwTerminate( );
		return -1;
	}
	glfwMakeContextCurrent( window );

	// Initialize GLEW
	glewExperimental = true; // Needed for core profile
	if ( glewInit( ) != GLEW_OK ) {
		fprintf( stderr, "Failed to initialize GLEW\n" );
		return -1;
	}

	// Ensure we can capture the escape key being pressed below
	glfwSetInputMode( window, GLFW_STICKY_KEYS, GL_TRUE );

	// Dark blue background
	glClearColor( 0.0f, 0.0f, 0.0f, 0.0f );

	// Enable depth test
	glEnable( GL_DEPTH_TEST );
	// Accept fragment if it closer to the camera than the former one
	glDepthFunc( GL_LESS );

	init();

	return 0;
}


