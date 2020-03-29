#ifndef OPENGLITEM_H
#define OPENGLITEM_H

#include <QQuickItem>
#include <QBasicTimer>
#include <QQuickWindow>

#include "render.h"

class MyRender: public Render {

public:
    MyRender() {
    }

    void RenderGL() override{
        glClearColor(0.4, 0.3, 0.3, 1.0);
        glClear(GL_COLOR_BUFFER_BIT);
        glBegin(GL_TRIANGLES);
            glVertex3d(0.0f, 1.0f, 0.0f);
            glVertex3d(-1.0f, -1.0f, 0.0f);
            glVertex3d(1.0f, -1.0f, 0.0f);
        glEnd();
    }

};


class OpenGLItem : public QQuickItem
{
    Q_OBJECT

public:
    OpenGLItem();

public slots:
    void sync();
    void cleanup();

protected:
    void timerEvent(QTimerEvent *event);

private:
    QBasicTimer m_timer;
    Render *m_render;
};


#endif // OPENGLITEM_H
