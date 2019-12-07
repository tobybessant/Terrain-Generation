#include <iostream>
#include <vector>
#include <GL/glew.h>
#include "glm/glm.hpp"
#include "GL/glew.h"
#include "GL/freeglut.h"
#include "GLFW/glfw3.h"

#include "Terrain.h"
#include "LoadShaders.h"

using namespace std;

#define SCREEN_X 1920
#define SCREEN_Y 1080

#define TILE_SIZE 0.2

#define ROWS 10
#define COLS 10

int main() {

	glfwInit();

	GLFWwindow* window = glfwCreateWindow(SCREEN_X, SCREEN_Y, "Terrain Generator", NULL, NULL);

	glfwMakeContextCurrent(window);
	glewInit();

	ShaderInfo  shaders[] = {
		{ GL_VERTEX_SHADER, "shaders/triangles.vert" },
		{ GL_FRAGMENT_SHADER, "shaders/triangles.frag" },
		{ GL_NONE, NULL }
	};

	GLuint program = LoadShaders(shaders);
	glUseProgram(program);
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);

	glFrontFace(GL_CCW);
	glCullFace(GL_BACK);
	glEnable(GL_CULL_FACE);

	glEnable(GL_DEPTH_TEST);

	glEnable(GL_POLYGON_OFFSET_LINE);
	glPolygonOffset(-1.0, -1.0);

	Terrain t = Terrain(COLS, ROWS, TILE_SIZE);

	while (true) {
		glClear(GL_COLOR_BUFFER_BIT);
		glClear(GL_DEPTH_BUFFER_BIT);
		
		glUniform1i(1, 1);
		glPolygonMode(GL_FRONT, GL_FILL);
		t.render(program);
		

		glUniform1i(1, 0);
		glPolygonMode(GL_FRONT, GL_LINE);
		t.render(program);


		glfwSwapBuffers(window);
		glfwPollEvents();
	}

}
