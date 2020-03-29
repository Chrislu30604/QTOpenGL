#ifndef OBJLOADER_H
#define OBJLOADER_H

#include <QString>
#include <QVector>
#include <QOpenGLFunctions>
#include <QVector3D>
#include <QVector2D>

using namespace std;

class Face {
public:
    Face(){
        v.resize(3);
        vn.resize(3);
        t.resize(3);
    }
    QVector<QVector3D> v;
    QVector<QVector3D> vn;
    QVector<QVector2D> t;
};


class ObjLoader
{
public:
    ObjLoader();
    bool ObjLoader::Load(QString fileName,
                         QVector<QVector3D> &vPoints,
                         QVector<QVector3D> &tPoints,
                         QVector<Face> &Faces);

};

#endif // OBJLOADER_H
