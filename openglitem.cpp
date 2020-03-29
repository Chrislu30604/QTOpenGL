#include "openglitem.h"
#include "objloader.h"

OpenGLItem::OpenGLItem()
    : m_render(0)
{

    ObjLoader *obj_loader = new ObjLoader();
    QVector<QVector3D> vPoints;
    QVector<QVector3D> tPoints;
    QVector<Face> faces;
    obj_loader->Load("D:\\NTURobotLibrary\\OpenGLTest\\cube.obj", vPoints, tPoints, faces);
    m_timer.start(12, this);
    connect(this, &QQuickItem::windowChanged, this, [this](QQuickWindow *window)
    {
        if (window)
        {
            connect(window, &QQuickWindow::beforeSynchronizing, this, &OpenGLItem::sync,
                    Qt::DirectConnection);
            connect(window, &QQuickWindow::sceneGraphInvalidated, this, &OpenGLItem::cleanup,
                    Qt::DirectConnection);

            window->setClearBeforeRendering(false);
        }
        else return;
    });
}


void OpenGLItem::sync()
{
    if (!m_render)
    {
        m_render = new MyRender();
        m_render->InitializeGL();   //可以放在Render的构造函数中
        m_render->ResizeGL(window()->width(), window()->height());
        connect(window(), &QQuickWindow::beforeRendering, this, [this]()
        {
            //window()->resetOpenGLState();
            m_render->RenderGL();
        }, Qt::DirectConnection);
        connect(window(), &QQuickWindow::afterRendering, this, [this]()
        {
            //渲染后调用，计算fps
        }, Qt::DirectConnection);
        connect(window(), &QQuickWindow::widthChanged, this, [this]()
        {
            m_render->ResizeGL(window()->width(), window()->height());
        });
        connect(window(), &QQuickWindow::heightChanged, this, [this]()
        {
            m_render->ResizeGL(window()->width(), window()->height());
        });
    }
}

void OpenGLItem::cleanup()
{
    if (m_render)
    {
        delete m_render;
        m_render = nullptr;
    }
}


void OpenGLItem::timerEvent(QTimerEvent *event)
{
    Q_UNUSED(event);
    window()->update();
}
