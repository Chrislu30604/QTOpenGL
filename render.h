#ifndef RENDER_H
#define RENDER_H

#include <QOpenGLFunctions>


class Render: protected QOpenGLFunctions
{
public:
    Render();

    virtual void InitializeGL();
    virtual void InitializeShader();

    virtual void ResizeGL(int w, int h);
    virtual void RenderGL();

};

#endif // RENDER_H
