#ifndef GENERICRENDER_H
#define GENERICRENDER_H

#include <QOpenGLShaderProgram>
#include <QOpenGLExtraFunctions>
#include <QOpenGLTexture>
#include <QOpenGLBuffer>


class GenericRender
{
    GenericRender();

    void initsize(QString filename,QImage &textureImg);
    void render(QOpenGLExtraFunctions *f,QMatrix4x4 &pMatrix,QMatrix4x4 &vMatrix,QMatrix4x4 &mMatrix,QVector3D &cameraLocation,QVector3D &lightCation);

private:
    QOpenGLTexture *texture_{nullptr};
    QOpenGLBuffer vbo_;
    QOpenGLShaderProgram program_;
    QVector<float> vertPoints_,texturePoints_,normalPoints_;
};

#endif // GENERICRENDER_H
