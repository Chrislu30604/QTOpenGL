#include "render.h"

Render::Render()
{

}

void Render::InitializeGL() {
    initializeOpenGLFunctions();
    InitializeShader();
}

void Render::InitializeShader() {

}

void Render::ResizeGL(int w, int h) {
    glViewport(0, 0, w, h);
}

void Render::RenderGL() {

}
